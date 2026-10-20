#include "common.h"
#include <cor.h>
#include <corprof.h>
#include "callback_base.h"
#include <array>
#include <cstring>
#include <new>

namespace {
constexpr GUID kMetadataImport =
    {0x7dac8207,0xd3ae,0x4c75,{0x9b,0x67,0x92,0x80,0x1a,0x49,0x7d,0x44}};

template<class T> class ComPtr {
    T* value_ = nullptr;
public:
    ~ComPtr() { if (value_) value_->Release(); }
    T* operator->() const { return value_; }
    T** Put() { return &value_; }
    explicit operator bool() const { return value_ != nullptr; }
};

// A bounds-checked ECMA-335 signature reader. Do not patch an unexpected overload.
class Signature {
    const BYTE* p_;
    const BYTE* end_;
public:
    Signature(PCCOR_SIGNATURE data, ULONG length) : p_(data), end_(data + length) {}
    bool Byte(BYTE value) { return p_ < end_ && *p_++ == value; }
    bool Number(ULONG& value) {
        if (p_ >= end_) return false;
        BYTE first = *p_++;
        if (!(first & 0x80)) { value = first; return true; }
        if ((first & 0xc0) == 0x80 && end_ - p_ >= 1) {
            value = ((first & 0x3f) << 8) | *p_++;
            return true;
        }
        if ((first & 0xe0) == 0xc0 && end_ - p_ >= 3) {
            value = ((first & 0x1f) << 24) | (p_[0] << 16) | (p_[1] << 8) | p_[2];
            p_ += 3;
            return true;
        }
        return false;
    }
    bool Type(BYTE kind, mdTypeDef type) {
        ULONG encoded;
        return Byte(kind) && Number(encoded) && (encoded & 3) == 0 && (encoded >> 2) == RidFromToken(type);
    }
    bool Done() const { return p_ == end_; }
};

struct Target {
    ModuleID module = 0;
    mdMethodDef evaluate = 0;
    std::array<BYTE,17> body{};
};

class Profiler final : public CallbackBase {
    std::atomic<ULONG> references_{1};
    ICorProfilerInfo10* info_ = nullptr;
    HANDLE changed_ = nullptr;
    HANDLE stopped_ = nullptr;
    SRWLOCK targetLock_ = SRWLOCK_INIT;
    Target target_;

    HRESULT Start(IUnknown* unknown) {
        HRESULT hr = unknown->QueryInterface(__uuidof(ICorProfilerInfo10), reinterpret_cast<void**>(&info_));
        if (FAILED(hr)) { Log(L"ICorProfilerInfo10 unavailable: 0x%08lx", hr); return hr; }
        hr = info_->SetEventMask(COR_PRF_MONITOR_MODULE_LOADS | COR_PRF_MONITOR_JIT_COMPILATION | COR_PRF_ENABLE_REJIT);
        if (FAILED(hr)) { Log(L"SetEventMask failed: 0x%08lx", hr); return hr; }
        changed_ = CreateEventW(nullptr, FALSE, FALSE, nullptr);
        stopped_ = CreateEventW(nullptr, TRUE, FALSE, nullptr);
        if (!changed_ || !stopped_) return HRESULT_FROM_WIN32(GetLastError());
        g_status = 1;
        Log(L"Profiler ready; OS region, language, time zone, and Lang properties are untouched.");
        return S_OK;
    }

    void StartDiscovery() {
        AddRef();
        HANDLE worker = CreateThread(nullptr, 0, [](void* self) -> DWORD {
            auto* profiler = static_cast<Profiler*>(self);
            profiler->Discover();
            profiler->Release();
            return 0;
        }, this, 0, nullptr);
        if (worker) CloseHandle(worker);
        else { Log(L"Cannot create metadata discovery thread."); Release(); g_status = -5; }
    }

    void Discover() {
        HRESULT hr = info_->InitializeCurrentThread();
        if (FAILED(hr)) Log(L"InitializeCurrentThread: 0x%08lx", hr);
        HANDLE events[] = {stopped_, changed_};
        for (;;) {
            ComPtr<ICorProfilerModuleEnum> modules;
            if (SUCCEEDED(info_->EnumModules(modules.Put()))) {
                ModuleID module;
                ULONG count;
                while (modules->Next(1, &module, &count) == S_OK && count) {
                    if (Inspect(module)) break;
                }
            }
            if (WaitForMultipleObjects(2, events, FALSE, INFINITE) != WAIT_OBJECT_0 + 1) break;
        }
    }

    bool Inspect(ModuleID module) {
        AcquireSRWLockShared(&targetLock_);
        bool exists = target_.module != 0;
        ReleaseSRWLockShared(&targetLock_);
        if (exists) return true;
        AssemblyID assembly = 0;
        if (FAILED(info_->GetModuleInfo(module, nullptr, 0, nullptr, nullptr, &assembly))) return false;
        wchar_t name[256];
        ULONG length = 0;
        if (FAILED(info_->GetAssemblyInfo(assembly, _countof(name), &length, name, nullptr, nullptr)) ||
            length > _countof(name) || wcscmp(name, L"PCL.Core") != 0) return false;

        ComPtr<IMetaDataImport> metadata;
        if (FAILED(info_->GetModuleMetaData(module, ofRead, kMetadataImport,
            reinterpret_cast<IUnknown**>(metadata.Put())))) return false;
        mdTypeDef policy, assessment, signals, classification;
        if (FAILED(metadata->FindTypeDefByName(L"PCL.Core.App.Region.RegionPolicy", 0, &policy)) ||
            FAILED(metadata->FindTypeDefByName(L"PCL.Core.App.Region.RegionAssessment", 0, &assessment)) ||
            FAILED(metadata->FindTypeDefByName(L"PCL.Core.App.Region.RegionSignals", 0, &signals)) ||
            FAILED(metadata->FindTypeDefByName(L"PCL.Core.App.Region.RegionClassification", 0, &classification))) {
            Log(L"PCL.Core lacks the expected region types; no replacement applied.");
            return false;
        }

        // Read Other's actual enum constant, rather than assuming its numeric value.
        mdFieldDef other;
        DWORD constantType = 0;
        UVCP_CONSTANT constant = nullptr;
        if (FAILED(metadata->FindField(classification, L"Other", nullptr, 0, &other)) ||
            FAILED(metadata->GetFieldProps(other, nullptr, nullptr, 0, nullptr, nullptr, nullptr,
                nullptr, &constantType, &constant, nullptr)) || constantType != ELEMENT_TYPE_I4 || !constant) {
            Log(L"RegionClassification.Other has an unsupported definition; leaving the app unchanged.");
            return false;
        }
        LONG otherValue;
        memcpy(&otherValue, constant, sizeof(otherValue));

        mdMethodDef evaluate = 0, constructor = 0;
        auto findMethod = [&](mdTypeDef type, LPCWSTR methodName, bool ctor) {
            HCORENUM enumeration = nullptr;
            mdMethodDef found = 0, candidate;
            ULONG count;
            while (metadata->EnumMethodsWithName(&enumeration, type, methodName, &candidate, 1, &count) == S_OK && count) {
                PCCOR_SIGNATURE signature = nullptr;
                ULONG size = 0;
                DWORD attributes = 0;
                if (FAILED(metadata->GetMethodProps(candidate, nullptr, nullptr, 0, nullptr, &attributes,
                    &signature, &size, nullptr, nullptr))) continue;
                Signature reader(signature, size);
                bool matches = ctor
                    ? reader.Byte(IMAGE_CEE_CS_CALLCONV_HASTHIS) && reader.Byte(2) && reader.Byte(ELEMENT_TYPE_VOID) &&
                      reader.Type(ELEMENT_TYPE_VALUETYPE, classification) && reader.Byte(ELEMENT_TYPE_STRING) && reader.Done()
                    : (attributes & mdStatic) && reader.Byte(IMAGE_CEE_CS_CALLCONV_DEFAULT) && reader.Byte(1) &&
                      reader.Type(ELEMENT_TYPE_CLASS, assessment) && reader.Type(ELEMENT_TYPE_CLASS, signals) && reader.Done();
                if (matches) { if (found) { found = 0; break; } found = candidate; }
            }
            if (enumeration) metadata->CloseEnum(enumeration);
            return found;
        };
        evaluate = findMethod(policy, L"Evaluate", false);
        constructor = findMethod(assessment, L".ctor", true);
        if (!evaluate || !constructor) {
            Log(L"Region method/constructor signature changed; no replacement applied.");
            return false;
        }

        // Reuse an existing string token; do not write to the assembly or its metadata.
        HCORENUM strings = nullptr;
        mdString reason = 0, candidate;
        ULONG count;
        while (metadata->EnumUserStrings(&strings, &candidate, 1, &count) == S_OK && count) {
            wchar_t text[64];
            ULONG size;
            if (SUCCEEDED(metadata->GetUserString(candidate, text, _countof(text), &size)) &&
                size == 9 && wmemcmp(text, L"geo-other", 9) == 0) { reason = candidate; break; }
        }
        if (strings) metadata->CloseEnum(strings);
        if (!reason) { Log(L"Expected geo-other string missing; no replacement applied."); return false; }

        Target target;
        target.module = module;
        target.evaluate = evaluate;
        // Tiny IL body: ldc.i4 Other; ldstr "geo-other"; newobj RegionAssessment::.ctor; ret.
        target.body = {0x42,0x20,0,0,0,0,0x72,0,0,0,0,0x73,0,0,0,0,0x2a};
        memcpy(target.body.data() + 2, &otherValue, 4);
        memcpy(target.body.data() + 7, &reason, 4);
        memcpy(target.body.data() + 12, &constructor, 4);
        AcquireSRWLockExclusive(&targetLock_);
        target_ = target;
        ReleaseSRWLockExclusive(&targetLock_);
        // ReJIT also covers ReadyToRun/already compiled code and existing inliners.
        g_status = 2;
        HRESULT hr = info_->RequestReJITWithInliners(COR_PRF_REJIT_BLOCK_INLINING,
            1, &target.module, &target.evaluate);
        if (FAILED(hr)) {
            Log(L"RequestReJIT failed: 0x%08lx", hr);
            g_status = -6;
            AcquireSRWLockExclusive(&targetLock_);
            target_ = {};
            ReleaseSRWLockExclusive(&targetLock_);
            return false;
        }
        Log(L"Requested replacement: PCL.Core RegionPolicy.Evaluate, token 0x%08lx; Other=%ld.", evaluate, otherValue);
        return true;
    }

public:
    ~Profiler() {
        if (info_) info_->Release();
        if (changed_) CloseHandle(changed_);
        if (stopped_) CloseHandle(stopped_);
    }
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void** result) override {
        if (!result) return E_POINTER;
        *result = nullptr;
        if (iid == IID_IUnknown || iid == __uuidof(ICorProfilerCallback) ||
            iid == __uuidof(ICorProfilerCallback2) || iid == __uuidof(ICorProfilerCallback3) ||
            iid == __uuidof(ICorProfilerCallback4)) {
            *result = static_cast<ICorProfilerCallback4*>(this);
            AddRef();
            return S_OK;
        }
        return E_NOINTERFACE;
    }
    ULONG STDMETHODCALLTYPE AddRef() override { return ++references_; }
    ULONG STDMETHODCALLTYPE Release() override {
        ULONG count = --references_;
        if (!count) delete this;
        return count;
    }
    HRESULT STDMETHODCALLTYPE Initialize(IUnknown* unknown) override {
        HRESULT hr = Start(unknown);
        if (SUCCEEDED(hr)) StartDiscovery();
        return hr;
    }
    HRESULT STDMETHODCALLTYPE InitializeForAttach(IUnknown* unknown, void*, UINT) override { return Start(unknown); }
    HRESULT STDMETHODCALLTYPE ProfilerAttachComplete() override { StartDiscovery(); return S_OK; }
    HRESULT STDMETHODCALLTYPE Shutdown() override { if (stopped_) SetEvent(stopped_); return S_OK; }
    HRESULT STDMETHODCALLTYPE ModuleLoadFinished(ModuleID, HRESULT result) override {
        if (SUCCEEDED(result) && changed_) SetEvent(changed_);
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE ModuleUnloadStarted(ModuleID module) override {
        AcquireSRWLockExclusive(&targetLock_);
        if (target_.module == module) { target_ = {}; g_status = 1; }
        ReleaseSRWLockExclusive(&targetLock_);
        if (changed_) SetEvent(changed_);
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE GetReJITParameters(ModuleID module, mdMethodDef method,
        ICorProfilerFunctionControl* control) override {
        AcquireSRWLockShared(&targetLock_);
        Target target = target_;
        ReleaseSRWLockShared(&targetLock_);
        if (target.module != module || target.evaluate != method) return S_OK;
        HRESULT hr = control->SetILFunctionBody(static_cast<ULONG>(target.body.size()), target.body.data());
        if (FAILED(hr)) { Log(L"SetILFunctionBody failed: 0x%08lx", hr); g_status = -7; }
        return hr;
    }
    HRESULT STDMETHODCALLTYPE JITCompilationStarted(FunctionID function, BOOL) override {
        ClassID type = 0;
        ModuleID module = 0;
        mdToken method = 0;
        if (FAILED(info_->GetFunctionInfo(function, &type, &module, &method))) return S_OK;
        AcquireSRWLockShared(&targetLock_);
        Target target = target_;
        ReleaseSRWLockShared(&targetLock_);
        if (target.module != module || target.evaluate != method) return S_OK;
        // RequestReJIT can skip methods that have never been JIT-compiled. Install
        // the same IL at the supported pre-JIT callback for that case.
        ComPtr<IMethodMalloc> allocator;
        HRESULT hr = info_->GetILFunctionBodyAllocator(module, allocator.Put());
        if (SUCCEEDED(hr)) {
            void* body = allocator->Alloc(static_cast<ULONG>(target.body.size()));
            if (!body) hr = E_OUTOFMEMORY;
            else {
                memcpy(body, target.body.data(), target.body.size());
                hr = info_->SetILFunctionBody(module, method, static_cast<LPCBYTE>(body));
            }
        }
        if (FAILED(hr)) { Log(L"Pre-JIT IL replacement failed: 0x%08lx.", hr); g_status = -10; }
        else Log(L"Installed replacement before first JIT compilation.");
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE JITCompilationFinished(FunctionID function, HRESULT result, BOOL safe) override {
        return ReJITCompilationFinished(function, 0, result, safe);
    }
    HRESULT STDMETHODCALLTYPE ReJITCompilationFinished(FunctionID function, ReJITID, HRESULT result, BOOL) override {
        ClassID type = 0;
        ModuleID module = 0;
        mdToken method = 0;
        if (SUCCEEDED(info_->GetFunctionInfo(function, &type, &module, &method))) {
            AcquireSRWLockShared(&targetLock_);
            bool matches = target_.module == module && target_.evaluate == method;
            ReleaseSRWLockShared(&targetLock_);
            if (matches) {
                g_status = SUCCEEDED(result) ? 3 : -8;
                Log(L"RegionPolicy.Evaluate replacement compiled: 0x%08lx.", result);
            }
        }
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE ReJITError(ModuleID, mdMethodDef method, FunctionID, HRESULT result) override {
        Log(L"ReJIT error for token 0x%08lx: 0x%08lx.", method, result);
        g_status = -9;
        return S_OK;
    }
};

class Factory final : public IClassFactory {
    std::atomic<ULONG> references_{1};
public:
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void** result) override {
        if (!result) return E_POINTER;
        *result = nullptr;
        if (iid != IID_IUnknown && iid != IID_IClassFactory) return E_NOINTERFACE;
        *result = static_cast<IClassFactory*>(this);
        AddRef();
        return S_OK;
    }
    ULONG STDMETHODCALLTYPE AddRef() override { return ++references_; }
    ULONG STDMETHODCALLTYPE Release() override {
        ULONG count = --references_;
        if (!count) delete this;
        return count;
    }
    HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown* outer, REFIID iid, void** result) override {
        if (!result) return E_POINTER;
        *result = nullptr;
        if (outer) return CLASS_E_NOAGGREGATION;
        auto* profiler = new (std::nothrow) Profiler();
        if (!profiler) return E_OUTOFMEMORY;
        HRESULT hr = profiler->QueryInterface(iid, result);
        profiler->Release();
        return hr;
    }
    HRESULT STDMETHODCALLTYPE LockServer(BOOL) override { return S_OK; }
};
}

extern "C" HRESULT WINAPI DllGetClassObject(REFCLSID clsid, REFIID iid, void** result) {
    if (!result) return E_POINTER;
    *result = nullptr;
    if (clsid != kProfilerClsid) return CLASS_E_CLASSNOTAVAILABLE;
    auto* factory = new (std::nothrow) Factory();
    if (!factory) return E_OUTOFMEMORY;
    HRESULT hr = factory->QueryInterface(iid, result);
    factory->Release();
    return hr;
}
extern "C" HRESULT WINAPI DllCanUnloadNow() { return S_FALSE; }

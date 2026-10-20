#include "common.h"
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

HMODULE g_self = nullptr;
std::atomic<LONG> g_status{0};

static std::wstring ModulePath(HMODULE module) {
    std::vector<wchar_t> path(32768);
    DWORD n = GetModuleFileNameW(module, path.data(), static_cast<DWORD>(path.size()));
    return n && n < path.size() ? std::wstring(path.data(), n) : std::wstring();
}

extern "C" LONG WINAPI PclCeRegionUnlockerStatus() { return g_status.load(); }

static bool Transfer(HANDLE pipe, void* buffer, DWORD size, bool write) {
    auto* bytes = static_cast<BYTE*>(buffer);
    while (size) {
        OVERLAPPED operation{};
        operation.hEvent = CreateEventW(nullptr, TRUE, FALSE, nullptr);
        if (!operation.hEvent) return false;
        DWORD transferred = 0;
        BOOL done = write ? WriteFile(pipe, bytes, size, &transferred, &operation)
                          : ReadFile(pipe, bytes, size, &transferred, &operation);
        if (!done && GetLastError() == ERROR_IO_PENDING) {
            if (WaitForSingleObject(operation.hEvent, 15000) != WAIT_OBJECT_0) {
                CancelIoEx(pipe, &operation);
                WaitForSingleObject(operation.hEvent, INFINITE);
                CloseHandle(operation.hEvent);
                return false;
            }
            done = GetOverlappedResult(pipe, &operation, &transferred, FALSE);
        }
        CloseHandle(operation.hEvent);
        if (!done || !transferred) return false;
        bytes += transferred;
        size -= transferred;
    }
    return true;
}

static DWORD WINAPI AttachWorker(void*) {
    // The runtime retains profiler callbacks for the rest of this process.
    HMODULE pinned;
    GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN,
        reinterpret_cast<LPCWSTR>(&AttachWorker), &pinned);
    Log(L"Loaded; waiting for this process's .NET diagnostic endpoint.");
    std::wstring path = ModulePath(g_self);
    if (path.empty()) { g_status = -1; return 0; }
    wchar_t pipeName[96];
    swprintf_s(pipeName, L"\\\\.\\pipe\\dotnet-diagnostic-%lu", GetCurrentProcessId());
    HANDLE pipe = INVALID_HANDLE_VALUE;
    ULONGLONG deadline = GetTickCount64() + 120000;
    DWORD lastError = 0;
    while (GetTickCount64() < deadline && g_status.load() == 0) {
        pipe = CreateFileW(pipeName, GENERIC_READ | GENERIC_WRITE, 0, nullptr,
            OPEN_EXISTING, FILE_FLAG_OVERLAPPED, nullptr);
        if (pipe != INVALID_HANDLE_VALUE) break;
        DWORD error = GetLastError();
        if (error != lastError) { Log(L"Diagnostic pipe %s: Win32 error %lu.", pipeName, error); lastError = error; }
        Sleep(200);
    }
    if (g_status.load() != 0) { if (pipe != INVALID_HANDLE_VALUE) CloseHandle(pipe); return 0; }
    if (pipe == INVALID_HANDLE_VALUE) {
        Log(L"No diagnostic endpoint after 120 s; no method was changed. Diagnostics may be disabled.");
        g_status = -2;
        return 0;
    }
    // .NET diagnostics IPC v1: 20-byte header, then timeout/GUID/UTF-16 path/client data.
    const DWORD chars = static_cast<DWORD>(path.size() + 1);
    const size_t size = 20 + 4 + sizeof(GUID) + 4 + chars * sizeof(wchar_t) + 4;
    if (size > 65535) { CloseHandle(pipe); g_status = -3; return 0; }
    std::vector<BYTE> packet(size, 0);
    memcpy(packet.data(), "DOTNET_IPC_V1", 13);
    const WORD wireSize = static_cast<WORD>(size);
    memcpy(packet.data() + 14, &wireSize, 2);
    packet[16] = 3; // Profiler command set.
    packet[17] = 1; // AttachProfiler.
    DWORD timeout = 10000;
    memcpy(packet.data() + 20, &timeout, 4);
    memcpy(packet.data() + 24, &kProfilerClsid, sizeof(GUID));
    memcpy(packet.data() + 40, &chars, 4);
    memcpy(packet.data() + 44, path.c_str(), chars * sizeof(wchar_t));
    BYTE header[20]{};
    bool ok = Transfer(pipe, packet.data(), static_cast<DWORD>(size), true) &&
              Transfer(pipe, header, sizeof(header), false);
    DWORD result = static_cast<DWORD>(E_FAIL);
    WORD responseSize = 0;
    memcpy(&responseSize, header + 14, 2);
    if (ok && memcmp(header, "DOTNET_IPC_V1", 14) == 0 && header[16] == 0xff && responseSize >= 24) {
        ok = Transfer(pipe, &result, sizeof(result), false);
        ok = ok && header[17] == 0 && SUCCEEDED(static_cast<HRESULT>(result));
    } else ok = false;
    CloseHandle(pipe);
    if (ok) Log(L"Profiler attached; only PCL.Core RegionPolicy.Evaluate is eligible for replacement.");
    else { Log(L"Profiler attach failed: 0x%08lx. No environment information was altered.", result); g_status = -4; }
    return 0;
}

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        g_self = instance;
        // No runtime, IPC, metadata, or forwarding work under the loader lock.
        HANDLE worker = CreateThread(nullptr, 0, AttachWorker, nullptr, 0, nullptr);
        if (worker) CloseHandle(worker);
    }
    return TRUE;
}

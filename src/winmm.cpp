#include "common.h"
#include <mmsystem.h>
#include <mmddk.h>
#include <string>

static HMODULE RealWinmm() {
    // Resolve outside DllMain, using the real system DLL's absolute path.
    static HMODULE module = [] {
        wchar_t directory[MAX_PATH];
        UINT length = GetSystemDirectoryW(directory, _countof(directory));
        if (!length || length >= _countof(directory)) return HMODULE(nullptr);
        std::wstring path(directory, length);
        path += L"\\winmm.dll";
        return LoadLibraryExW(path.c_str(), nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    }();
    return module;
}

template<class T> static T WinmmFunction(const char* name) {
    DWORD error = GetLastError();
    HMODULE module = RealWinmm();
    auto function = module ? reinterpret_cast<T>(GetProcAddress(module, name)) : nullptr;
    if (!function) {
        Log(L"Cannot forward a required System32 WinMM export: %hs.", name);
        RaiseFailFastException(nullptr, nullptr, 0);
    }
    SetLastError(error);
    return function;
}

#include "winmm_exports.inc"

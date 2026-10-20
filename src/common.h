#pragma once
#include <windows.h>
#include <atomic>

// A private profiler CLSID; no COM registration or registry writes are needed.
inline constexpr GUID kProfilerClsid =
    {0x8e25d71f, 0x9f87, 0x4d06, {0xa5, 0xe7, 0x0c, 0x5e, 0x91, 0x04, 0x23, 0x6b}};
extern HMODULE g_self;
// 0: loaded, 1: profiler ready, 2: replacement requested, 3: replacement compiled.
// Negative values indicate failure; they do not change application behavior.
extern std::atomic<LONG> g_status;
inline void Log(const wchar_t*, ...) {}

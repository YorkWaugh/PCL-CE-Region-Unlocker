// Typed WinMM export forwarding wrappers.
extern "C" BOOL WINAPI Proxy_mciExecute(LPCSTR command) {
    using Fn = BOOL (WINAPI*)(LPCSTR command);
    auto function = WinmmFunction<Fn>("mciExecute");
    return function(command);
}
extern "C" LRESULT WINAPI Proxy_CloseDriver(HDRVR hDriver, LPARAM lParam1, LPARAM lParam2) {
    using Fn = LRESULT (WINAPI*)(HDRVR hDriver, LPARAM lParam1, LPARAM lParam2);
    auto function = WinmmFunction<Fn>("CloseDriver");
    return function(hDriver, lParam1, lParam2);
}
extern "C" LRESULT WINAPI Proxy_DefDriverProc(DWORD_PTR dwDriverIdentifier, HDRVR hdrvr, UINT uMsg, LPARAM lParam1, LPARAM lParam2) {
    using Fn = LRESULT (WINAPI*)(DWORD_PTR dwDriverIdentifier, HDRVR hdrvr, UINT uMsg, LPARAM lParam1, LPARAM lParam2);
    auto function = WinmmFunction<Fn>("DefDriverProc");
    return function(dwDriverIdentifier, hdrvr, uMsg, lParam1, lParam2);
}
extern "C" BOOL WINAPI Proxy_DriverCallback(DWORD_PTR dwCallback, DWORD dwFlags, HDRVR hDevice, DWORD dwMsg, DWORD_PTR dwUser, DWORD_PTR dwParam1, DWORD_PTR dwParam2) {
    using Fn = BOOL (WINAPI*)(DWORD_PTR dwCallback, DWORD dwFlags, HDRVR hDevice, DWORD dwMsg, DWORD_PTR dwUser, DWORD_PTR dwParam1, DWORD_PTR dwParam2);
    auto function = WinmmFunction<Fn>("DriverCallback");
    return function(dwCallback, dwFlags, hDevice, dwMsg, dwUser, dwParam1, dwParam2);
}
extern "C" HMODULE WINAPI Proxy_DrvGetModuleHandle(HDRVR hDriver) {
    using Fn = HMODULE (WINAPI*)(HDRVR hDriver);
    auto function = WinmmFunction<Fn>("DrvGetModuleHandle");
    return function(hDriver);
}
extern "C" HMODULE WINAPI Proxy_GetDriverModuleHandle(HDRVR hDriver) {
    using Fn = HMODULE (WINAPI*)(HDRVR hDriver);
    auto function = WinmmFunction<Fn>("GetDriverModuleHandle");
    return function(hDriver);
}
extern "C" HDRVR WINAPI Proxy_OpenDriver(LPCWSTR szDriverName, LPCWSTR szSectionName, LPARAM lParam2) {
    using Fn = HDRVR (WINAPI*)(LPCWSTR szDriverName, LPCWSTR szSectionName, LPARAM lParam2);
    auto function = WinmmFunction<Fn>("OpenDriver");
    return function(szDriverName, szSectionName, lParam2);
}
extern "C" BOOL WINAPI Proxy_PlaySound(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound) {
    using Fn = BOOL (WINAPI*)(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound);
    auto function = WinmmFunction<Fn>("PlaySound");
    return function(pszSound, hmod, fdwSound);
}
extern "C" BOOL WINAPI Proxy_PlaySoundA(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound) {
    using Fn = BOOL (WINAPI*)(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound);
    auto function = WinmmFunction<Fn>("PlaySoundA");
    return function(pszSound, hmod, fdwSound);
}
extern "C" BOOL WINAPI Proxy_PlaySoundW(LPCWSTR pszSound, HMODULE hmod, DWORD fdwSound) {
    using Fn = BOOL (WINAPI*)(LPCWSTR pszSound, HMODULE hmod, DWORD fdwSound);
    auto function = WinmmFunction<Fn>("PlaySoundW");
    return function(pszSound, hmod, fdwSound);
}
extern "C" LRESULT WINAPI Proxy_SendDriverMessage(HDRVR hDriver, UINT message, LPARAM lParam1, LPARAM lParam2) {
    using Fn = LRESULT (WINAPI*)(HDRVR hDriver, UINT message, LPARAM lParam1, LPARAM lParam2);
    auto function = WinmmFunction<Fn>("SendDriverMessage");
    return function(hDriver, message, lParam1, lParam2);
}
extern "C" void WINAPI Proxy_WOWAppExit(DWORD task) {
    using Fn = void (WINAPI*)(DWORD task);
    auto function = WinmmFunction<Fn>("WOWAppExit");
    return function(task);
}
extern "C" MMRESULT WINAPI Proxy_auxGetDevCapsA(UINT_PTR uDeviceID, LPAUXCAPSA pac, UINT cbac) {
    using Fn = MMRESULT (WINAPI*)(UINT_PTR uDeviceID, LPAUXCAPSA pac, UINT cbac);
    auto function = WinmmFunction<Fn>("auxGetDevCapsA");
    return function(uDeviceID, pac, cbac);
}
extern "C" MMRESULT WINAPI Proxy_auxGetDevCapsW(UINT_PTR uDeviceID, LPAUXCAPSW pac, UINT cbac) {
    using Fn = MMRESULT (WINAPI*)(UINT_PTR uDeviceID, LPAUXCAPSW pac, UINT cbac);
    auto function = WinmmFunction<Fn>("auxGetDevCapsW");
    return function(uDeviceID, pac, cbac);
}
extern "C" UINT WINAPI Proxy_auxGetNumDevs(void) {
    using Fn = UINT (WINAPI*)(void);
    auto function = WinmmFunction<Fn>("auxGetNumDevs");
    return function();
}
extern "C" MMRESULT WINAPI Proxy_auxGetVolume(UINT uDeviceID, LPDWORD pdwVolume) {
    using Fn = MMRESULT (WINAPI*)(UINT uDeviceID, LPDWORD pdwVolume);
    auto function = WinmmFunction<Fn>("auxGetVolume");
    return function(uDeviceID, pdwVolume);
}
extern "C" MMRESULT WINAPI Proxy_auxOutMessage(UINT uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2) {
    using Fn = MMRESULT (WINAPI*)(UINT uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
    auto function = WinmmFunction<Fn>("auxOutMessage");
    return function(uDeviceID, uMsg, dw1, dw2);
}
extern "C" MMRESULT WINAPI Proxy_auxSetVolume(UINT uDeviceID, DWORD dwVolume) {
    using Fn = MMRESULT (WINAPI*)(UINT uDeviceID, DWORD dwVolume);
    auto function = WinmmFunction<Fn>("auxSetVolume");
    return function(uDeviceID, dwVolume);
}
extern "C" MMRESULT WINAPI Proxy_joyConfigChanged(DWORD dwFlags) {
    using Fn = MMRESULT (WINAPI*)(DWORD dwFlags);
    auto function = WinmmFunction<Fn>("joyConfigChanged");
    return function(dwFlags);
}
extern "C" MMRESULT WINAPI Proxy_joyGetDevCapsA(UINT_PTR uJoyID, LPJOYCAPSA pjc, UINT cbjc) {
    using Fn = MMRESULT (WINAPI*)(UINT_PTR uJoyID, LPJOYCAPSA pjc, UINT cbjc);
    auto function = WinmmFunction<Fn>("joyGetDevCapsA");
    return function(uJoyID, pjc, cbjc);
}
extern "C" MMRESULT WINAPI Proxy_joyGetDevCapsW(UINT_PTR uJoyID, LPJOYCAPSW pjc, UINT cbjc) {
    using Fn = MMRESULT (WINAPI*)(UINT_PTR uJoyID, LPJOYCAPSW pjc, UINT cbjc);
    auto function = WinmmFunction<Fn>("joyGetDevCapsW");
    return function(uJoyID, pjc, cbjc);
}
extern "C" UINT WINAPI Proxy_joyGetNumDevs(void) {
    using Fn = UINT (WINAPI*)(void);
    auto function = WinmmFunction<Fn>("joyGetNumDevs");
    return function();
}
extern "C" MMRESULT WINAPI Proxy_joyGetPos(UINT uJoyID, LPJOYINFO pji) {
    using Fn = MMRESULT (WINAPI*)(UINT uJoyID, LPJOYINFO pji);
    auto function = WinmmFunction<Fn>("joyGetPos");
    return function(uJoyID, pji);
}
extern "C" MMRESULT WINAPI Proxy_joyGetPosEx(UINT uJoyID, LPJOYINFOEX pji) {
    using Fn = MMRESULT (WINAPI*)(UINT uJoyID, LPJOYINFOEX pji);
    auto function = WinmmFunction<Fn>("joyGetPosEx");
    return function(uJoyID, pji);
}
extern "C" MMRESULT WINAPI Proxy_joyGetThreshold(UINT uJoyID, LPUINT puThreshold) {
    using Fn = MMRESULT (WINAPI*)(UINT uJoyID, LPUINT puThreshold);
    auto function = WinmmFunction<Fn>("joyGetThreshold");
    return function(uJoyID, puThreshold);
}
extern "C" MMRESULT WINAPI Proxy_joyReleaseCapture(UINT uJoyID) {
    using Fn = MMRESULT (WINAPI*)(UINT uJoyID);
    auto function = WinmmFunction<Fn>("joyReleaseCapture");
    return function(uJoyID);
}
extern "C" MMRESULT WINAPI Proxy_joySetCapture(HWND hwnd, UINT uJoyID, UINT uPeriod, BOOL fChanged) {
    using Fn = MMRESULT (WINAPI*)(HWND hwnd, UINT uJoyID, UINT uPeriod, BOOL fChanged);
    auto function = WinmmFunction<Fn>("joySetCapture");
    return function(hwnd, uJoyID, uPeriod, fChanged);
}
extern "C" MMRESULT WINAPI Proxy_joySetThreshold(UINT uJoyID, UINT uThreshold) {
    using Fn = MMRESULT (WINAPI*)(UINT uJoyID, UINT uThreshold);
    auto function = WinmmFunction<Fn>("joySetThreshold");
    return function(uJoyID, uThreshold);
}
extern "C" BOOL WINAPI Proxy_mciDriverNotify(HANDLE hwndCallback, MCIDEVICEID wDeviceID, UINT uStatus) {
    using Fn = BOOL (WINAPI*)(HANDLE hwndCallback, MCIDEVICEID wDeviceID, UINT uStatus);
    auto function = WinmmFunction<Fn>("mciDriverNotify");
    return function(hwndCallback, wDeviceID, uStatus);
}
extern "C" UINT WINAPI Proxy_mciDriverYield(MCIDEVICEID wDeviceID) {
    using Fn = UINT (WINAPI*)(MCIDEVICEID wDeviceID);
    auto function = WinmmFunction<Fn>("mciDriverYield");
    return function(wDeviceID);
}
extern "C" BOOL WINAPI Proxy_mciFreeCommandResource(UINT wTable) {
    using Fn = BOOL (WINAPI*)(UINT wTable);
    auto function = WinmmFunction<Fn>("mciFreeCommandResource");
    return function(wTable);
}
extern "C" HTASK WINAPI Proxy_mciGetCreatorTask(MCIDEVICEID mciId) {
    using Fn = HTASK (WINAPI*)(MCIDEVICEID mciId);
    auto function = WinmmFunction<Fn>("mciGetCreatorTask");
    return function(mciId);
}
extern "C" MCIDEVICEID WINAPI Proxy_mciGetDeviceIDA(LPCSTR pszDevice) {
    using Fn = MCIDEVICEID (WINAPI*)(LPCSTR pszDevice);
    auto function = WinmmFunction<Fn>("mciGetDeviceIDA");
    return function(pszDevice);
}
extern "C" MCIDEVICEID WINAPI Proxy_mciGetDeviceIDFromElementIDA(DWORD dwElementID, LPCSTR lpstrType) {
    using Fn = MCIDEVICEID (WINAPI*)(DWORD dwElementID, LPCSTR lpstrType);
    auto function = WinmmFunction<Fn>("mciGetDeviceIDFromElementIDA");
    return function(dwElementID, lpstrType);
}
extern "C" MCIDEVICEID WINAPI Proxy_mciGetDeviceIDFromElementIDW(DWORD dwElementID, LPCWSTR lpstrType) {
    using Fn = MCIDEVICEID (WINAPI*)(DWORD dwElementID, LPCWSTR lpstrType);
    auto function = WinmmFunction<Fn>("mciGetDeviceIDFromElementIDW");
    return function(dwElementID, lpstrType);
}
extern "C" MCIDEVICEID WINAPI Proxy_mciGetDeviceIDW(LPCWSTR pszDevice) {
    using Fn = MCIDEVICEID (WINAPI*)(LPCWSTR pszDevice);
    auto function = WinmmFunction<Fn>("mciGetDeviceIDW");
    return function(pszDevice);
}
extern "C" DWORD_PTR WINAPI Proxy_mciGetDriverData(MCIDEVICEID wDeviceID) {
    using Fn = DWORD_PTR (WINAPI*)(MCIDEVICEID wDeviceID);
    auto function = WinmmFunction<Fn>("mciGetDriverData");
    return function(wDeviceID);
}
extern "C" BOOL WINAPI Proxy_mciGetErrorStringA(MCIERROR mcierr, LPSTR pszText, UINT cchText) {
    using Fn = BOOL (WINAPI*)(MCIERROR mcierr, LPSTR pszText, UINT cchText);
    auto function = WinmmFunction<Fn>("mciGetErrorStringA");
    return function(mcierr, pszText, cchText);
}
extern "C" BOOL WINAPI Proxy_mciGetErrorStringW(MCIERROR mcierr, LPWSTR pszText, UINT cchText) {
    using Fn = BOOL (WINAPI*)(MCIERROR mcierr, LPWSTR pszText, UINT cchText);
    auto function = WinmmFunction<Fn>("mciGetErrorStringW");
    return function(mcierr, pszText, cchText);
}
extern "C" YIELDPROC WINAPI Proxy_mciGetYieldProc(MCIDEVICEID mciId, LPDWORD pdwYieldData) {
    using Fn = YIELDPROC (WINAPI*)(MCIDEVICEID mciId, LPDWORD pdwYieldData);
    auto function = WinmmFunction<Fn>("mciGetYieldProc");
    return function(mciId, pdwYieldData);
}
extern "C" UINT WINAPI Proxy_mciLoadCommandResource(HANDLE hInstance, LPCWSTR lpResName, UINT wType) {
    using Fn = UINT (WINAPI*)(HANDLE hInstance, LPCWSTR lpResName, UINT wType);
    auto function = WinmmFunction<Fn>("mciLoadCommandResource");
    return function(hInstance, lpResName, wType);
}
extern "C" MCIERROR WINAPI Proxy_mciSendCommandA(MCIDEVICEID mciId, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2) {
    using Fn = MCIERROR (WINAPI*)(MCIDEVICEID mciId, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2);
    auto function = WinmmFunction<Fn>("mciSendCommandA");
    return function(mciId, uMsg, dwParam1, dwParam2);
}
extern "C" MCIERROR WINAPI Proxy_mciSendCommandW(MCIDEVICEID mciId, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2) {
    using Fn = MCIERROR (WINAPI*)(MCIDEVICEID mciId, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2);
    auto function = WinmmFunction<Fn>("mciSendCommandW");
    return function(mciId, uMsg, dwParam1, dwParam2);
}
extern "C" MCIERROR WINAPI Proxy_mciSendStringA(LPCSTR lpstrCommand, LPSTR lpstrReturnString, UINT uReturnLength, HWND hwndCallback) {
    using Fn = MCIERROR (WINAPI*)(LPCSTR lpstrCommand, LPSTR lpstrReturnString, UINT uReturnLength, HWND hwndCallback);
    auto function = WinmmFunction<Fn>("mciSendStringA");
    return function(lpstrCommand, lpstrReturnString, uReturnLength, hwndCallback);
}
extern "C" MCIERROR WINAPI Proxy_mciSendStringW(LPCWSTR lpstrCommand, LPWSTR lpstrReturnString, UINT uReturnLength, HWND hwndCallback) {
    using Fn = MCIERROR (WINAPI*)(LPCWSTR lpstrCommand, LPWSTR lpstrReturnString, UINT uReturnLength, HWND hwndCallback);
    auto function = WinmmFunction<Fn>("mciSendStringW");
    return function(lpstrCommand, lpstrReturnString, uReturnLength, hwndCallback);
}
extern "C" BOOL WINAPI Proxy_mciSetDriverData(MCIDEVICEID wDeviceID, DWORD_PTR dwData) {
    using Fn = BOOL (WINAPI*)(MCIDEVICEID wDeviceID, DWORD_PTR dwData);
    auto function = WinmmFunction<Fn>("mciSetDriverData");
    return function(wDeviceID, dwData);
}
extern "C" BOOL WINAPI Proxy_mciSetYieldProc(MCIDEVICEID mciId, YIELDPROC fpYieldProc, DWORD dwYieldData) {
    using Fn = BOOL (WINAPI*)(MCIDEVICEID mciId, YIELDPROC fpYieldProc, DWORD dwYieldData);
    auto function = WinmmFunction<Fn>("mciSetYieldProc");
    return function(mciId, fpYieldProc, dwYieldData);
}
extern "C" MMRESULT WINAPI Proxy_midiConnect(HMIDI hmi, HMIDIOUT hmo, LPVOID pReserved) {
    using Fn = MMRESULT (WINAPI*)(HMIDI hmi, HMIDIOUT hmo, LPVOID pReserved);
    auto function = WinmmFunction<Fn>("midiConnect");
    return function(hmi, hmo, pReserved);
}
extern "C" MMRESULT WINAPI Proxy_midiDisconnect(HMIDI hmi, HMIDIOUT hmo, LPVOID pReserved) {
    using Fn = MMRESULT (WINAPI*)(HMIDI hmi, HMIDIOUT hmo, LPVOID pReserved);
    auto function = WinmmFunction<Fn>("midiDisconnect");
    return function(hmi, hmo, pReserved);
}
extern "C" MMRESULT WINAPI Proxy_midiInAddBuffer(HMIDIIN hmi, LPMIDIHDR pmh, UINT cbmh) {
    using Fn = MMRESULT (WINAPI*)(HMIDIIN hmi, LPMIDIHDR pmh, UINT cbmh);
    auto function = WinmmFunction<Fn>("midiInAddBuffer");
    return function(hmi, pmh, cbmh);
}
extern "C" MMRESULT WINAPI Proxy_midiInClose(HMIDIIN hmi) {
    using Fn = MMRESULT (WINAPI*)(HMIDIIN hmi);
    auto function = WinmmFunction<Fn>("midiInClose");
    return function(hmi);
}
extern "C" MMRESULT WINAPI Proxy_midiInGetDevCapsA(UINT_PTR uDeviceID, LPMIDIINCAPSA pmic, UINT cbmic) {
    using Fn = MMRESULT (WINAPI*)(UINT_PTR uDeviceID, LPMIDIINCAPSA pmic, UINT cbmic);
    auto function = WinmmFunction<Fn>("midiInGetDevCapsA");
    return function(uDeviceID, pmic, cbmic);
}
extern "C" MMRESULT WINAPI Proxy_midiInGetDevCapsW(UINT_PTR uDeviceID, LPMIDIINCAPSW pmic, UINT cbmic) {
    using Fn = MMRESULT (WINAPI*)(UINT_PTR uDeviceID, LPMIDIINCAPSW pmic, UINT cbmic);
    auto function = WinmmFunction<Fn>("midiInGetDevCapsW");
    return function(uDeviceID, pmic, cbmic);
}
extern "C" MMRESULT WINAPI Proxy_midiInGetErrorTextA(MMRESULT mmrError, LPSTR pszText, UINT cchText) {
    using Fn = MMRESULT (WINAPI*)(MMRESULT mmrError, LPSTR pszText, UINT cchText);
    auto function = WinmmFunction<Fn>("midiInGetErrorTextA");
    return function(mmrError, pszText, cchText);
}
extern "C" MMRESULT WINAPI Proxy_midiInGetErrorTextW(MMRESULT mmrError, LPWSTR pszText, UINT cchText) {
    using Fn = MMRESULT (WINAPI*)(MMRESULT mmrError, LPWSTR pszText, UINT cchText);
    auto function = WinmmFunction<Fn>("midiInGetErrorTextW");
    return function(mmrError, pszText, cchText);
}
extern "C" MMRESULT WINAPI Proxy_midiInGetID(HMIDIIN hmi, LPUINT puDeviceID) {
    using Fn = MMRESULT (WINAPI*)(HMIDIIN hmi, LPUINT puDeviceID);
    auto function = WinmmFunction<Fn>("midiInGetID");
    return function(hmi, puDeviceID);
}
extern "C" UINT WINAPI Proxy_midiInGetNumDevs(void) {
    using Fn = UINT (WINAPI*)(void);
    auto function = WinmmFunction<Fn>("midiInGetNumDevs");
    return function();
}
extern "C" MMRESULT WINAPI Proxy_midiInMessage(HMIDIIN hmi, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2) {
    using Fn = MMRESULT (WINAPI*)(HMIDIIN hmi, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
    auto function = WinmmFunction<Fn>("midiInMessage");
    return function(hmi, uMsg, dw1, dw2);
}
extern "C" MMRESULT WINAPI Proxy_midiInOpen(LPHMIDIIN phmi, UINT uDeviceID, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen) {
    using Fn = MMRESULT (WINAPI*)(LPHMIDIIN phmi, UINT uDeviceID, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
    auto function = WinmmFunction<Fn>("midiInOpen");
    return function(phmi, uDeviceID, dwCallback, dwInstance, fdwOpen);
}
extern "C" MMRESULT WINAPI Proxy_midiInPrepareHeader(HMIDIIN hmi, LPMIDIHDR pmh, UINT cbmh) {
    using Fn = MMRESULT (WINAPI*)(HMIDIIN hmi, LPMIDIHDR pmh, UINT cbmh);
    auto function = WinmmFunction<Fn>("midiInPrepareHeader");
    return function(hmi, pmh, cbmh);
}
extern "C" MMRESULT WINAPI Proxy_midiInReset(HMIDIIN hmi) {
    using Fn = MMRESULT (WINAPI*)(HMIDIIN hmi);
    auto function = WinmmFunction<Fn>("midiInReset");
    return function(hmi);
}
extern "C" MMRESULT WINAPI Proxy_midiInStart(HMIDIIN hmi) {
    using Fn = MMRESULT (WINAPI*)(HMIDIIN hmi);
    auto function = WinmmFunction<Fn>("midiInStart");
    return function(hmi);
}
extern "C" MMRESULT WINAPI Proxy_midiInStop(HMIDIIN hmi) {
    using Fn = MMRESULT (WINAPI*)(HMIDIIN hmi);
    auto function = WinmmFunction<Fn>("midiInStop");
    return function(hmi);
}
extern "C" MMRESULT WINAPI Proxy_midiInUnprepareHeader(HMIDIIN hmi, LPMIDIHDR pmh, UINT cbmh) {
    using Fn = MMRESULT (WINAPI*)(HMIDIIN hmi, LPMIDIHDR pmh, UINT cbmh);
    auto function = WinmmFunction<Fn>("midiInUnprepareHeader");
    return function(hmi, pmh, cbmh);
}
extern "C" MMRESULT WINAPI Proxy_midiOutCacheDrumPatches(HMIDIOUT hmo, UINT uPatch, LPWORD pwkya, UINT fuCache) {
    using Fn = MMRESULT (WINAPI*)(HMIDIOUT hmo, UINT uPatch, LPWORD pwkya, UINT fuCache);
    auto function = WinmmFunction<Fn>("midiOutCacheDrumPatches");
    return function(hmo, uPatch, pwkya, fuCache);
}
extern "C" MMRESULT WINAPI Proxy_midiOutCachePatches(HMIDIOUT hmo, UINT uBank, LPWORD pwpa, UINT fuCache) {
    using Fn = MMRESULT (WINAPI*)(HMIDIOUT hmo, UINT uBank, LPWORD pwpa, UINT fuCache);
    auto function = WinmmFunction<Fn>("midiOutCachePatches");
    return function(hmo, uBank, pwpa, fuCache);
}
extern "C" MMRESULT WINAPI Proxy_midiOutClose(HMIDIOUT hmo) {
    using Fn = MMRESULT (WINAPI*)(HMIDIOUT hmo);
    auto function = WinmmFunction<Fn>("midiOutClose");
    return function(hmo);
}
extern "C" MMRESULT WINAPI Proxy_midiOutGetDevCapsA(UINT_PTR uDeviceID, LPMIDIOUTCAPSA pmoc, UINT cbmoc) {
    using Fn = MMRESULT (WINAPI*)(UINT_PTR uDeviceID, LPMIDIOUTCAPSA pmoc, UINT cbmoc);
    auto function = WinmmFunction<Fn>("midiOutGetDevCapsA");
    return function(uDeviceID, pmoc, cbmoc);
}
extern "C" MMRESULT WINAPI Proxy_midiOutGetDevCapsW(UINT_PTR uDeviceID, LPMIDIOUTCAPSW pmoc, UINT cbmoc) {
    using Fn = MMRESULT (WINAPI*)(UINT_PTR uDeviceID, LPMIDIOUTCAPSW pmoc, UINT cbmoc);
    auto function = WinmmFunction<Fn>("midiOutGetDevCapsW");
    return function(uDeviceID, pmoc, cbmoc);
}
extern "C" MMRESULT WINAPI Proxy_midiOutGetErrorTextA(MMRESULT mmrError, LPSTR pszText, UINT cchText) {
    using Fn = MMRESULT (WINAPI*)(MMRESULT mmrError, LPSTR pszText, UINT cchText);
    auto function = WinmmFunction<Fn>("midiOutGetErrorTextA");
    return function(mmrError, pszText, cchText);
}
extern "C" MMRESULT WINAPI Proxy_midiOutGetErrorTextW(MMRESULT mmrError, LPWSTR pszText, UINT cchText) {
    using Fn = MMRESULT (WINAPI*)(MMRESULT mmrError, LPWSTR pszText, UINT cchText);
    auto function = WinmmFunction<Fn>("midiOutGetErrorTextW");
    return function(mmrError, pszText, cchText);
}
extern "C" MMRESULT WINAPI Proxy_midiOutGetID(HMIDIOUT hmo, LPUINT puDeviceID) {
    using Fn = MMRESULT (WINAPI*)(HMIDIOUT hmo, LPUINT puDeviceID);
    auto function = WinmmFunction<Fn>("midiOutGetID");
    return function(hmo, puDeviceID);
}
extern "C" UINT WINAPI Proxy_midiOutGetNumDevs(void) {
    using Fn = UINT (WINAPI*)(void);
    auto function = WinmmFunction<Fn>("midiOutGetNumDevs");
    return function();
}
extern "C" MMRESULT WINAPI Proxy_midiOutGetVolume(HMIDIOUT hmo, LPDWORD pdwVolume) {
    using Fn = MMRESULT (WINAPI*)(HMIDIOUT hmo, LPDWORD pdwVolume);
    auto function = WinmmFunction<Fn>("midiOutGetVolume");
    return function(hmo, pdwVolume);
}
extern "C" MMRESULT WINAPI Proxy_midiOutLongMsg(HMIDIOUT hmo, LPMIDIHDR pmh, UINT cbmh) {
    using Fn = MMRESULT (WINAPI*)(HMIDIOUT hmo, LPMIDIHDR pmh, UINT cbmh);
    auto function = WinmmFunction<Fn>("midiOutLongMsg");
    return function(hmo, pmh, cbmh);
}
extern "C" MMRESULT WINAPI Proxy_midiOutMessage(HMIDIOUT hmo, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2) {
    using Fn = MMRESULT (WINAPI*)(HMIDIOUT hmo, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
    auto function = WinmmFunction<Fn>("midiOutMessage");
    return function(hmo, uMsg, dw1, dw2);
}
extern "C" MMRESULT WINAPI Proxy_midiOutOpen(LPHMIDIOUT phmo, UINT uDeviceID, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen) {
    using Fn = MMRESULT (WINAPI*)(LPHMIDIOUT phmo, UINT uDeviceID, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
    auto function = WinmmFunction<Fn>("midiOutOpen");
    return function(phmo, uDeviceID, dwCallback, dwInstance, fdwOpen);
}
extern "C" MMRESULT WINAPI Proxy_midiOutPrepareHeader(HMIDIOUT hmo, LPMIDIHDR pmh, UINT cbmh) {
    using Fn = MMRESULT (WINAPI*)(HMIDIOUT hmo, LPMIDIHDR pmh, UINT cbmh);
    auto function = WinmmFunction<Fn>("midiOutPrepareHeader");
    return function(hmo, pmh, cbmh);
}
extern "C" MMRESULT WINAPI Proxy_midiOutReset(HMIDIOUT hmo) {
    using Fn = MMRESULT (WINAPI*)(HMIDIOUT hmo);
    auto function = WinmmFunction<Fn>("midiOutReset");
    return function(hmo);
}
extern "C" MMRESULT WINAPI Proxy_midiOutSetVolume(HMIDIOUT hmo, DWORD dwVolume) {
    using Fn = MMRESULT (WINAPI*)(HMIDIOUT hmo, DWORD dwVolume);
    auto function = WinmmFunction<Fn>("midiOutSetVolume");
    return function(hmo, dwVolume);
}
extern "C" MMRESULT WINAPI Proxy_midiOutShortMsg(HMIDIOUT hmo, DWORD dwMsg) {
    using Fn = MMRESULT (WINAPI*)(HMIDIOUT hmo, DWORD dwMsg);
    auto function = WinmmFunction<Fn>("midiOutShortMsg");
    return function(hmo, dwMsg);
}
extern "C" MMRESULT WINAPI Proxy_midiOutUnprepareHeader(HMIDIOUT hmo, LPMIDIHDR pmh, UINT cbmh) {
    using Fn = MMRESULT (WINAPI*)(HMIDIOUT hmo, LPMIDIHDR pmh, UINT cbmh);
    auto function = WinmmFunction<Fn>("midiOutUnprepareHeader");
    return function(hmo, pmh, cbmh);
}
extern "C" MMRESULT WINAPI Proxy_midiStreamClose(HMIDISTRM hms) {
    using Fn = MMRESULT (WINAPI*)(HMIDISTRM hms);
    auto function = WinmmFunction<Fn>("midiStreamClose");
    return function(hms);
}
extern "C" MMRESULT WINAPI Proxy_midiStreamOpen(LPHMIDISTRM phms, LPUINT puDeviceID, DWORD cMidi, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen) {
    using Fn = MMRESULT (WINAPI*)(LPHMIDISTRM phms, LPUINT puDeviceID, DWORD cMidi, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
    auto function = WinmmFunction<Fn>("midiStreamOpen");
    return function(phms, puDeviceID, cMidi, dwCallback, dwInstance, fdwOpen);
}
extern "C" MMRESULT WINAPI Proxy_midiStreamOut(HMIDISTRM hms, LPMIDIHDR pmh, UINT cbmh) {
    using Fn = MMRESULT (WINAPI*)(HMIDISTRM hms, LPMIDIHDR pmh, UINT cbmh);
    auto function = WinmmFunction<Fn>("midiStreamOut");
    return function(hms, pmh, cbmh);
}
extern "C" MMRESULT WINAPI Proxy_midiStreamPause(HMIDISTRM hms) {
    using Fn = MMRESULT (WINAPI*)(HMIDISTRM hms);
    auto function = WinmmFunction<Fn>("midiStreamPause");
    return function(hms);
}
extern "C" MMRESULT WINAPI Proxy_midiStreamPosition(HMIDISTRM hms, LPMMTIME lpmmt, UINT cbmmt) {
    using Fn = MMRESULT (WINAPI*)(HMIDISTRM hms, LPMMTIME lpmmt, UINT cbmmt);
    auto function = WinmmFunction<Fn>("midiStreamPosition");
    return function(hms, lpmmt, cbmmt);
}
extern "C" MMRESULT WINAPI Proxy_midiStreamProperty(HMIDISTRM hms, LPBYTE lppropdata, DWORD dwProperty) {
    using Fn = MMRESULT (WINAPI*)(HMIDISTRM hms, LPBYTE lppropdata, DWORD dwProperty);
    auto function = WinmmFunction<Fn>("midiStreamProperty");
    return function(hms, lppropdata, dwProperty);
}
extern "C" MMRESULT WINAPI Proxy_midiStreamRestart(HMIDISTRM hms) {
    using Fn = MMRESULT (WINAPI*)(HMIDISTRM hms);
    auto function = WinmmFunction<Fn>("midiStreamRestart");
    return function(hms);
}
extern "C" MMRESULT WINAPI Proxy_midiStreamStop(HMIDISTRM hms) {
    using Fn = MMRESULT (WINAPI*)(HMIDISTRM hms);
    auto function = WinmmFunction<Fn>("midiStreamStop");
    return function(hms);
}
extern "C" MMRESULT WINAPI Proxy_mixerClose(HMIXER hmx) {
    using Fn = MMRESULT (WINAPI*)(HMIXER hmx);
    auto function = WinmmFunction<Fn>("mixerClose");
    return function(hmx);
}
extern "C" MMRESULT WINAPI Proxy_mixerGetControlDetailsA(HMIXEROBJ hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fdwDetails) {
    using Fn = MMRESULT (WINAPI*)(HMIXEROBJ hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fdwDetails);
    auto function = WinmmFunction<Fn>("mixerGetControlDetailsA");
    return function(hmxobj, pmxcd, fdwDetails);
}
extern "C" MMRESULT WINAPI Proxy_mixerGetControlDetailsW(HMIXEROBJ hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fdwDetails) {
    using Fn = MMRESULT (WINAPI*)(HMIXEROBJ hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fdwDetails);
    auto function = WinmmFunction<Fn>("mixerGetControlDetailsW");
    return function(hmxobj, pmxcd, fdwDetails);
}
extern "C" MMRESULT WINAPI Proxy_mixerGetDevCapsA(UINT_PTR uMxId, LPMIXERCAPSA pmxcaps, UINT cbmxcaps) {
    using Fn = MMRESULT (WINAPI*)(UINT_PTR uMxId, LPMIXERCAPSA pmxcaps, UINT cbmxcaps);
    auto function = WinmmFunction<Fn>("mixerGetDevCapsA");
    return function(uMxId, pmxcaps, cbmxcaps);
}
extern "C" MMRESULT WINAPI Proxy_mixerGetDevCapsW(UINT_PTR uMxId, LPMIXERCAPSW pmxcaps, UINT cbmxcaps) {
    using Fn = MMRESULT (WINAPI*)(UINT_PTR uMxId, LPMIXERCAPSW pmxcaps, UINT cbmxcaps);
    auto function = WinmmFunction<Fn>("mixerGetDevCapsW");
    return function(uMxId, pmxcaps, cbmxcaps);
}
extern "C" MMRESULT WINAPI Proxy_mixerGetID(HMIXEROBJ hmxobj, UINT * puMxId, DWORD fdwId) {
    using Fn = MMRESULT (WINAPI*)(HMIXEROBJ hmxobj, UINT * puMxId, DWORD fdwId);
    auto function = WinmmFunction<Fn>("mixerGetID");
    return function(hmxobj, puMxId, fdwId);
}
extern "C" MMRESULT WINAPI Proxy_mixerGetLineControlsA(HMIXEROBJ hmxobj, LPMIXERLINECONTROLSA pmxlc, DWORD fdwControls) {
    using Fn = MMRESULT (WINAPI*)(HMIXEROBJ hmxobj, LPMIXERLINECONTROLSA pmxlc, DWORD fdwControls);
    auto function = WinmmFunction<Fn>("mixerGetLineControlsA");
    return function(hmxobj, pmxlc, fdwControls);
}
extern "C" MMRESULT WINAPI Proxy_mixerGetLineControlsW(HMIXEROBJ hmxobj, LPMIXERLINECONTROLSW pmxlc, DWORD fdwControls) {
    using Fn = MMRESULT (WINAPI*)(HMIXEROBJ hmxobj, LPMIXERLINECONTROLSW pmxlc, DWORD fdwControls);
    auto function = WinmmFunction<Fn>("mixerGetLineControlsW");
    return function(hmxobj, pmxlc, fdwControls);
}
extern "C" MMRESULT WINAPI Proxy_mixerGetLineInfoA(HMIXEROBJ hmxobj, LPMIXERLINEA pmxl, DWORD fdwInfo) {
    using Fn = MMRESULT (WINAPI*)(HMIXEROBJ hmxobj, LPMIXERLINEA pmxl, DWORD fdwInfo);
    auto function = WinmmFunction<Fn>("mixerGetLineInfoA");
    return function(hmxobj, pmxl, fdwInfo);
}
extern "C" MMRESULT WINAPI Proxy_mixerGetLineInfoW(HMIXEROBJ hmxobj, LPMIXERLINEW pmxl, DWORD fdwInfo) {
    using Fn = MMRESULT (WINAPI*)(HMIXEROBJ hmxobj, LPMIXERLINEW pmxl, DWORD fdwInfo);
    auto function = WinmmFunction<Fn>("mixerGetLineInfoW");
    return function(hmxobj, pmxl, fdwInfo);
}
extern "C" UINT WINAPI Proxy_mixerGetNumDevs(void) {
    using Fn = UINT (WINAPI*)(void);
    auto function = WinmmFunction<Fn>("mixerGetNumDevs");
    return function();
}
extern "C" DWORD WINAPI Proxy_mixerMessage(HMIXER hmx, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2) {
    using Fn = DWORD (WINAPI*)(HMIXER hmx, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2);
    auto function = WinmmFunction<Fn>("mixerMessage");
    return function(hmx, uMsg, dwParam1, dwParam2);
}
extern "C" MMRESULT WINAPI Proxy_mixerOpen(LPHMIXER phmx, UINT uMxId, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen) {
    using Fn = MMRESULT (WINAPI*)(LPHMIXER phmx, UINT uMxId, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
    auto function = WinmmFunction<Fn>("mixerOpen");
    return function(phmx, uMxId, dwCallback, dwInstance, fdwOpen);
}
extern "C" MMRESULT WINAPI Proxy_mixerSetControlDetails(HMIXEROBJ hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fdwDetails) {
    using Fn = MMRESULT (WINAPI*)(HMIXEROBJ hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fdwDetails);
    auto function = WinmmFunction<Fn>("mixerSetControlDetails");
    return function(hmxobj, pmxcd, fdwDetails);
}
extern "C" UINT WINAPI Proxy_mmDrvInstall(HDRVR hDriver, LPCWSTR wszDrvEntry, DRIVERMSGPROC drvMessage, UINT wFlags) {
    using Fn = UINT (WINAPI*)(HDRVR hDriver, LPCWSTR wszDrvEntry, DRIVERMSGPROC drvMessage, UINT wFlags);
    auto function = WinmmFunction<Fn>("mmDrvInstall");
    return function(hDriver, wszDrvEntry, drvMessage, wFlags);
}
extern "C" DWORD WINAPI Proxy_mmGetCurrentTask(void) {
    using Fn = DWORD (WINAPI*)(void);
    auto function = WinmmFunction<Fn>("mmGetCurrentTask");
    return function();
}
extern "C" void WINAPI Proxy_mmTaskBlock(DWORD h) {
    using Fn = void (WINAPI*)(DWORD h);
    auto function = WinmmFunction<Fn>("mmTaskBlock");
    return function(h);
}
extern "C" UINT WINAPI Proxy_mmTaskCreate(LPTASKCALLBACK lpfn, HANDLE * lph, DWORD_PTR dwInst) {
    using Fn = UINT (WINAPI*)(LPTASKCALLBACK lpfn, HANDLE * lph, DWORD_PTR dwInst);
    auto function = WinmmFunction<Fn>("mmTaskCreate");
    return function(lpfn, lph, dwInst);
}
extern "C" BOOL WINAPI Proxy_mmTaskSignal(DWORD h) {
    using Fn = BOOL (WINAPI*)(DWORD h);
    auto function = WinmmFunction<Fn>("mmTaskSignal");
    return function(h);
}
extern "C" void WINAPI Proxy_mmTaskYield(void) {
    using Fn = void (WINAPI*)(void);
    auto function = WinmmFunction<Fn>("mmTaskYield");
    return function();
}
extern "C" MMRESULT WINAPI Proxy_mmioAdvance(HMMIO hmmio, LPMMIOINFO pmmioinfo, UINT fuAdvance) {
    using Fn = MMRESULT (WINAPI*)(HMMIO hmmio, LPMMIOINFO pmmioinfo, UINT fuAdvance);
    auto function = WinmmFunction<Fn>("mmioAdvance");
    return function(hmmio, pmmioinfo, fuAdvance);
}
extern "C" MMRESULT WINAPI Proxy_mmioAscend(HMMIO hmmio, LPMMCKINFO pmmcki, UINT fuAscend) {
    using Fn = MMRESULT (WINAPI*)(HMMIO hmmio, LPMMCKINFO pmmcki, UINT fuAscend);
    auto function = WinmmFunction<Fn>("mmioAscend");
    return function(hmmio, pmmcki, fuAscend);
}
extern "C" MMRESULT WINAPI Proxy_mmioClose(HMMIO hmmio, UINT fuClose) {
    using Fn = MMRESULT (WINAPI*)(HMMIO hmmio, UINT fuClose);
    auto function = WinmmFunction<Fn>("mmioClose");
    return function(hmmio, fuClose);
}
extern "C" MMRESULT WINAPI Proxy_mmioCreateChunk(HMMIO hmmio, LPMMCKINFO pmmcki, UINT fuCreate) {
    using Fn = MMRESULT (WINAPI*)(HMMIO hmmio, LPMMCKINFO pmmcki, UINT fuCreate);
    auto function = WinmmFunction<Fn>("mmioCreateChunk");
    return function(hmmio, pmmcki, fuCreate);
}
extern "C" MMRESULT WINAPI Proxy_mmioDescend(HMMIO hmmio, LPMMCKINFO pmmcki, const MMCKINFO * pmmckiParent, UINT fuDescend) {
    using Fn = MMRESULT (WINAPI*)(HMMIO hmmio, LPMMCKINFO pmmcki, const MMCKINFO * pmmckiParent, UINT fuDescend);
    auto function = WinmmFunction<Fn>("mmioDescend");
    return function(hmmio, pmmcki, pmmckiParent, fuDescend);
}
extern "C" MMRESULT WINAPI Proxy_mmioFlush(HMMIO hmmio, UINT fuFlush) {
    using Fn = MMRESULT (WINAPI*)(HMMIO hmmio, UINT fuFlush);
    auto function = WinmmFunction<Fn>("mmioFlush");
    return function(hmmio, fuFlush);
}
extern "C" MMRESULT WINAPI Proxy_mmioGetInfo(HMMIO hmmio, LPMMIOINFO pmmioinfo, UINT fuInfo) {
    using Fn = MMRESULT (WINAPI*)(HMMIO hmmio, LPMMIOINFO pmmioinfo, UINT fuInfo);
    auto function = WinmmFunction<Fn>("mmioGetInfo");
    return function(hmmio, pmmioinfo, fuInfo);
}
extern "C" LPMMIOPROC WINAPI Proxy_mmioInstallIOProcA(FOURCC fccIOProc, LPMMIOPROC pIOProc, DWORD dwFlags) {
    using Fn = LPMMIOPROC (WINAPI*)(FOURCC fccIOProc, LPMMIOPROC pIOProc, DWORD dwFlags);
    auto function = WinmmFunction<Fn>("mmioInstallIOProcA");
    return function(fccIOProc, pIOProc, dwFlags);
}
extern "C" LPMMIOPROC WINAPI Proxy_mmioInstallIOProcW(FOURCC fccIOProc, LPMMIOPROC pIOProc, DWORD dwFlags) {
    using Fn = LPMMIOPROC (WINAPI*)(FOURCC fccIOProc, LPMMIOPROC pIOProc, DWORD dwFlags);
    auto function = WinmmFunction<Fn>("mmioInstallIOProcW");
    return function(fccIOProc, pIOProc, dwFlags);
}
extern "C" HMMIO WINAPI Proxy_mmioOpenA(LPSTR pszFileName, LPMMIOINFO pmmioinfo, DWORD fdwOpen) {
    using Fn = HMMIO (WINAPI*)(LPSTR pszFileName, LPMMIOINFO pmmioinfo, DWORD fdwOpen);
    auto function = WinmmFunction<Fn>("mmioOpenA");
    return function(pszFileName, pmmioinfo, fdwOpen);
}
extern "C" HMMIO WINAPI Proxy_mmioOpenW(LPWSTR pszFileName, LPMMIOINFO pmmioinfo, DWORD fdwOpen) {
    using Fn = HMMIO (WINAPI*)(LPWSTR pszFileName, LPMMIOINFO pmmioinfo, DWORD fdwOpen);
    auto function = WinmmFunction<Fn>("mmioOpenW");
    return function(pszFileName, pmmioinfo, fdwOpen);
}
extern "C" LONG WINAPI Proxy_mmioRead(HMMIO hmmio, HPSTR pch, LONG cch) {
    using Fn = LONG (WINAPI*)(HMMIO hmmio, HPSTR pch, LONG cch);
    auto function = WinmmFunction<Fn>("mmioRead");
    return function(hmmio, pch, cch);
}
extern "C" MMRESULT WINAPI Proxy_mmioRenameA(LPCSTR pszFileName, LPCSTR pszNewFileName, LPCMMIOINFO pmmioinfo, DWORD fdwRename) {
    using Fn = MMRESULT (WINAPI*)(LPCSTR pszFileName, LPCSTR pszNewFileName, LPCMMIOINFO pmmioinfo, DWORD fdwRename);
    auto function = WinmmFunction<Fn>("mmioRenameA");
    return function(pszFileName, pszNewFileName, pmmioinfo, fdwRename);
}
extern "C" MMRESULT WINAPI Proxy_mmioRenameW(LPCWSTR pszFileName, LPCWSTR pszNewFileName, LPCMMIOINFO pmmioinfo, DWORD fdwRename) {
    using Fn = MMRESULT (WINAPI*)(LPCWSTR pszFileName, LPCWSTR pszNewFileName, LPCMMIOINFO pmmioinfo, DWORD fdwRename);
    auto function = WinmmFunction<Fn>("mmioRenameW");
    return function(pszFileName, pszNewFileName, pmmioinfo, fdwRename);
}
extern "C" LONG WINAPI Proxy_mmioSeek(HMMIO hmmio, LONG lOffset, int iOrigin) {
    using Fn = LONG (WINAPI*)(HMMIO hmmio, LONG lOffset, int iOrigin);
    auto function = WinmmFunction<Fn>("mmioSeek");
    return function(hmmio, lOffset, iOrigin);
}
extern "C" LRESULT WINAPI Proxy_mmioSendMessage(HMMIO hmmio, UINT uMsg, LPARAM lParam1, LPARAM lParam2) {
    using Fn = LRESULT (WINAPI*)(HMMIO hmmio, UINT uMsg, LPARAM lParam1, LPARAM lParam2);
    auto function = WinmmFunction<Fn>("mmioSendMessage");
    return function(hmmio, uMsg, lParam1, lParam2);
}
extern "C" MMRESULT WINAPI Proxy_mmioSetBuffer(HMMIO hmmio, LPSTR pchBuffer, LONG cchBuffer, UINT fuBuffer) {
    using Fn = MMRESULT (WINAPI*)(HMMIO hmmio, LPSTR pchBuffer, LONG cchBuffer, UINT fuBuffer);
    auto function = WinmmFunction<Fn>("mmioSetBuffer");
    return function(hmmio, pchBuffer, cchBuffer, fuBuffer);
}
extern "C" MMRESULT WINAPI Proxy_mmioSetInfo(HMMIO hmmio, LPCMMIOINFO pmmioinfo, UINT fuInfo) {
    using Fn = MMRESULT (WINAPI*)(HMMIO hmmio, LPCMMIOINFO pmmioinfo, UINT fuInfo);
    auto function = WinmmFunction<Fn>("mmioSetInfo");
    return function(hmmio, pmmioinfo, fuInfo);
}
extern "C" FOURCC WINAPI Proxy_mmioStringToFOURCCA(LPCSTR sz, UINT uFlags) {
    using Fn = FOURCC (WINAPI*)(LPCSTR sz, UINT uFlags);
    auto function = WinmmFunction<Fn>("mmioStringToFOURCCA");
    return function(sz, uFlags);
}
extern "C" FOURCC WINAPI Proxy_mmioStringToFOURCCW(LPCWSTR sz, UINT uFlags) {
    using Fn = FOURCC (WINAPI*)(LPCWSTR sz, UINT uFlags);
    auto function = WinmmFunction<Fn>("mmioStringToFOURCCW");
    return function(sz, uFlags);
}
extern "C" LONG WINAPI Proxy_mmioWrite(HMMIO hmmio, const char * pch, LONG cch) {
    using Fn = LONG (WINAPI*)(HMMIO hmmio, const char * pch, LONG cch);
    auto function = WinmmFunction<Fn>("mmioWrite");
    return function(hmmio, pch, cch);
}
extern "C" UINT WINAPI Proxy_mmsystemGetVersion(void) {
    using Fn = UINT (WINAPI*)(void);
    auto function = WinmmFunction<Fn>("mmsystemGetVersion");
    return function();
}
extern "C" BOOL WINAPI Proxy_sndPlaySoundA(LPCSTR pszSound, UINT fuSound) {
    using Fn = BOOL (WINAPI*)(LPCSTR pszSound, UINT fuSound);
    auto function = WinmmFunction<Fn>("sndPlaySoundA");
    return function(pszSound, fuSound);
}
extern "C" BOOL WINAPI Proxy_sndPlaySoundW(LPCWSTR pszSound, UINT fuSound) {
    using Fn = BOOL (WINAPI*)(LPCWSTR pszSound, UINT fuSound);
    auto function = WinmmFunction<Fn>("sndPlaySoundW");
    return function(pszSound, fuSound);
}
extern "C" MMRESULT WINAPI Proxy_timeBeginPeriod(UINT uPeriod) {
    using Fn = MMRESULT (WINAPI*)(UINT uPeriod);
    auto function = WinmmFunction<Fn>("timeBeginPeriod");
    return function(uPeriod);
}
extern "C" MMRESULT WINAPI Proxy_timeEndPeriod(UINT uPeriod) {
    using Fn = MMRESULT (WINAPI*)(UINT uPeriod);
    auto function = WinmmFunction<Fn>("timeEndPeriod");
    return function(uPeriod);
}
extern "C" MMRESULT WINAPI Proxy_timeGetDevCaps(LPTIMECAPS ptc, UINT cbtc) {
    using Fn = MMRESULT (WINAPI*)(LPTIMECAPS ptc, UINT cbtc);
    auto function = WinmmFunction<Fn>("timeGetDevCaps");
    return function(ptc, cbtc);
}
extern "C" MMRESULT WINAPI Proxy_timeGetSystemTime(LPMMTIME pmmt, UINT cbmmt) {
    using Fn = MMRESULT (WINAPI*)(LPMMTIME pmmt, UINT cbmmt);
    auto function = WinmmFunction<Fn>("timeGetSystemTime");
    return function(pmmt, cbmmt);
}
extern "C" DWORD WINAPI Proxy_timeGetTime(void) {
    using Fn = DWORD (WINAPI*)(void);
    auto function = WinmmFunction<Fn>("timeGetTime");
    return function();
}
extern "C" MMRESULT WINAPI Proxy_timeKillEvent(UINT uTimerID) {
    using Fn = MMRESULT (WINAPI*)(UINT uTimerID);
    auto function = WinmmFunction<Fn>("timeKillEvent");
    return function(uTimerID);
}
extern "C" MMRESULT WINAPI Proxy_timeSetEvent(UINT uDelay, UINT uResolution, LPTIMECALLBACK fptc, DWORD_PTR dwUser, UINT fuEvent) {
    using Fn = MMRESULT (WINAPI*)(UINT uDelay, UINT uResolution, LPTIMECALLBACK fptc, DWORD_PTR dwUser, UINT fuEvent);
    auto function = WinmmFunction<Fn>("timeSetEvent");
    return function(uDelay, uResolution, fptc, dwUser, fuEvent);
}
extern "C" MMRESULT WINAPI Proxy_waveInAddBuffer(HWAVEIN hwi, LPWAVEHDR pwh, UINT cbwh) {
    using Fn = MMRESULT (WINAPI*)(HWAVEIN hwi, LPWAVEHDR pwh, UINT cbwh);
    auto function = WinmmFunction<Fn>("waveInAddBuffer");
    return function(hwi, pwh, cbwh);
}
extern "C" MMRESULT WINAPI Proxy_waveInClose(HWAVEIN hwi) {
    using Fn = MMRESULT (WINAPI*)(HWAVEIN hwi);
    auto function = WinmmFunction<Fn>("waveInClose");
    return function(hwi);
}
extern "C" MMRESULT WINAPI Proxy_waveInGetDevCapsA(UINT_PTR uDeviceID, LPWAVEINCAPSA pwic, UINT cbwic) {
    using Fn = MMRESULT (WINAPI*)(UINT_PTR uDeviceID, LPWAVEINCAPSA pwic, UINT cbwic);
    auto function = WinmmFunction<Fn>("waveInGetDevCapsA");
    return function(uDeviceID, pwic, cbwic);
}
extern "C" MMRESULT WINAPI Proxy_waveInGetDevCapsW(UINT_PTR uDeviceID, LPWAVEINCAPSW pwic, UINT cbwic) {
    using Fn = MMRESULT (WINAPI*)(UINT_PTR uDeviceID, LPWAVEINCAPSW pwic, UINT cbwic);
    auto function = WinmmFunction<Fn>("waveInGetDevCapsW");
    return function(uDeviceID, pwic, cbwic);
}
extern "C" MMRESULT WINAPI Proxy_waveInGetErrorTextA(MMRESULT mmrError, LPSTR pszText, UINT cchText) {
    using Fn = MMRESULT (WINAPI*)(MMRESULT mmrError, LPSTR pszText, UINT cchText);
    auto function = WinmmFunction<Fn>("waveInGetErrorTextA");
    return function(mmrError, pszText, cchText);
}
extern "C" MMRESULT WINAPI Proxy_waveInGetErrorTextW(MMRESULT mmrError, LPWSTR pszText, UINT cchText) {
    using Fn = MMRESULT (WINAPI*)(MMRESULT mmrError, LPWSTR pszText, UINT cchText);
    auto function = WinmmFunction<Fn>("waveInGetErrorTextW");
    return function(mmrError, pszText, cchText);
}
extern "C" MMRESULT WINAPI Proxy_waveInGetID(HWAVEIN hwi, LPUINT puDeviceID) {
    using Fn = MMRESULT (WINAPI*)(HWAVEIN hwi, LPUINT puDeviceID);
    auto function = WinmmFunction<Fn>("waveInGetID");
    return function(hwi, puDeviceID);
}
extern "C" UINT WINAPI Proxy_waveInGetNumDevs(void) {
    using Fn = UINT (WINAPI*)(void);
    auto function = WinmmFunction<Fn>("waveInGetNumDevs");
    return function();
}
extern "C" MMRESULT WINAPI Proxy_waveInGetPosition(HWAVEIN hwi, LPMMTIME pmmt, UINT cbmmt) {
    using Fn = MMRESULT (WINAPI*)(HWAVEIN hwi, LPMMTIME pmmt, UINT cbmmt);
    auto function = WinmmFunction<Fn>("waveInGetPosition");
    return function(hwi, pmmt, cbmmt);
}
extern "C" MMRESULT WINAPI Proxy_waveInMessage(HWAVEIN hwi, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2) {
    using Fn = MMRESULT (WINAPI*)(HWAVEIN hwi, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
    auto function = WinmmFunction<Fn>("waveInMessage");
    return function(hwi, uMsg, dw1, dw2);
}
extern "C" MMRESULT WINAPI Proxy_waveInOpen(LPHWAVEIN phwi, UINT uDeviceID, LPCWAVEFORMATEX pwfx, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen) {
    using Fn = MMRESULT (WINAPI*)(LPHWAVEIN phwi, UINT uDeviceID, LPCWAVEFORMATEX pwfx, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
    auto function = WinmmFunction<Fn>("waveInOpen");
    return function(phwi, uDeviceID, pwfx, dwCallback, dwInstance, fdwOpen);
}
extern "C" MMRESULT WINAPI Proxy_waveInPrepareHeader(HWAVEIN hwi, LPWAVEHDR pwh, UINT cbwh) {
    using Fn = MMRESULT (WINAPI*)(HWAVEIN hwi, LPWAVEHDR pwh, UINT cbwh);
    auto function = WinmmFunction<Fn>("waveInPrepareHeader");
    return function(hwi, pwh, cbwh);
}
extern "C" MMRESULT WINAPI Proxy_waveInReset(HWAVEIN hwi) {
    using Fn = MMRESULT (WINAPI*)(HWAVEIN hwi);
    auto function = WinmmFunction<Fn>("waveInReset");
    return function(hwi);
}
extern "C" MMRESULT WINAPI Proxy_waveInStart(HWAVEIN hwi) {
    using Fn = MMRESULT (WINAPI*)(HWAVEIN hwi);
    auto function = WinmmFunction<Fn>("waveInStart");
    return function(hwi);
}
extern "C" MMRESULT WINAPI Proxy_waveInStop(HWAVEIN hwi) {
    using Fn = MMRESULT (WINAPI*)(HWAVEIN hwi);
    auto function = WinmmFunction<Fn>("waveInStop");
    return function(hwi);
}
extern "C" MMRESULT WINAPI Proxy_waveInUnprepareHeader(HWAVEIN hwi, LPWAVEHDR pwh, UINT cbwh) {
    using Fn = MMRESULT (WINAPI*)(HWAVEIN hwi, LPWAVEHDR pwh, UINT cbwh);
    auto function = WinmmFunction<Fn>("waveInUnprepareHeader");
    return function(hwi, pwh, cbwh);
}
extern "C" MMRESULT WINAPI Proxy_waveOutBreakLoop(HWAVEOUT hwo) {
    using Fn = MMRESULT (WINAPI*)(HWAVEOUT hwo);
    auto function = WinmmFunction<Fn>("waveOutBreakLoop");
    return function(hwo);
}
extern "C" MMRESULT WINAPI Proxy_waveOutClose(HWAVEOUT hwo) {
    using Fn = MMRESULT (WINAPI*)(HWAVEOUT hwo);
    auto function = WinmmFunction<Fn>("waveOutClose");
    return function(hwo);
}
extern "C" MMRESULT WINAPI Proxy_waveOutGetDevCapsA(UINT_PTR uDeviceID, LPWAVEOUTCAPSA pwoc, UINT cbwoc) {
    using Fn = MMRESULT (WINAPI*)(UINT_PTR uDeviceID, LPWAVEOUTCAPSA pwoc, UINT cbwoc);
    auto function = WinmmFunction<Fn>("waveOutGetDevCapsA");
    return function(uDeviceID, pwoc, cbwoc);
}
extern "C" MMRESULT WINAPI Proxy_waveOutGetDevCapsW(UINT_PTR uDeviceID, LPWAVEOUTCAPSW pwoc, UINT cbwoc) {
    using Fn = MMRESULT (WINAPI*)(UINT_PTR uDeviceID, LPWAVEOUTCAPSW pwoc, UINT cbwoc);
    auto function = WinmmFunction<Fn>("waveOutGetDevCapsW");
    return function(uDeviceID, pwoc, cbwoc);
}
extern "C" MMRESULT WINAPI Proxy_waveOutGetErrorTextA(MMRESULT mmrError, LPSTR pszText, UINT cchText) {
    using Fn = MMRESULT (WINAPI*)(MMRESULT mmrError, LPSTR pszText, UINT cchText);
    auto function = WinmmFunction<Fn>("waveOutGetErrorTextA");
    return function(mmrError, pszText, cchText);
}
extern "C" MMRESULT WINAPI Proxy_waveOutGetErrorTextW(MMRESULT mmrError, LPWSTR pszText, UINT cchText) {
    using Fn = MMRESULT (WINAPI*)(MMRESULT mmrError, LPWSTR pszText, UINT cchText);
    auto function = WinmmFunction<Fn>("waveOutGetErrorTextW");
    return function(mmrError, pszText, cchText);
}
extern "C" MMRESULT WINAPI Proxy_waveOutGetID(HWAVEOUT hwo, LPUINT puDeviceID) {
    using Fn = MMRESULT (WINAPI*)(HWAVEOUT hwo, LPUINT puDeviceID);
    auto function = WinmmFunction<Fn>("waveOutGetID");
    return function(hwo, puDeviceID);
}
extern "C" UINT WINAPI Proxy_waveOutGetNumDevs(void) {
    using Fn = UINT (WINAPI*)(void);
    auto function = WinmmFunction<Fn>("waveOutGetNumDevs");
    return function();
}
extern "C" MMRESULT WINAPI Proxy_waveOutGetPitch(HWAVEOUT hwo, LPDWORD pdwPitch) {
    using Fn = MMRESULT (WINAPI*)(HWAVEOUT hwo, LPDWORD pdwPitch);
    auto function = WinmmFunction<Fn>("waveOutGetPitch");
    return function(hwo, pdwPitch);
}
extern "C" MMRESULT WINAPI Proxy_waveOutGetPlaybackRate(HWAVEOUT hwo, LPDWORD pdwRate) {
    using Fn = MMRESULT (WINAPI*)(HWAVEOUT hwo, LPDWORD pdwRate);
    auto function = WinmmFunction<Fn>("waveOutGetPlaybackRate");
    return function(hwo, pdwRate);
}
extern "C" MMRESULT WINAPI Proxy_waveOutGetPosition(HWAVEOUT hwo, LPMMTIME pmmt, UINT cbmmt) {
    using Fn = MMRESULT (WINAPI*)(HWAVEOUT hwo, LPMMTIME pmmt, UINT cbmmt);
    auto function = WinmmFunction<Fn>("waveOutGetPosition");
    return function(hwo, pmmt, cbmmt);
}
extern "C" MMRESULT WINAPI Proxy_waveOutGetVolume(HWAVEOUT hwo, LPDWORD pdwVolume) {
    using Fn = MMRESULT (WINAPI*)(HWAVEOUT hwo, LPDWORD pdwVolume);
    auto function = WinmmFunction<Fn>("waveOutGetVolume");
    return function(hwo, pdwVolume);
}
extern "C" MMRESULT WINAPI Proxy_waveOutMessage(HWAVEOUT hwo, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2) {
    using Fn = MMRESULT (WINAPI*)(HWAVEOUT hwo, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);
    auto function = WinmmFunction<Fn>("waveOutMessage");
    return function(hwo, uMsg, dw1, dw2);
}
extern "C" MMRESULT WINAPI Proxy_waveOutOpen(LPHWAVEOUT phwo, UINT uDeviceID, LPCWAVEFORMATEX pwfx, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen) {
    using Fn = MMRESULT (WINAPI*)(LPHWAVEOUT phwo, UINT uDeviceID, LPCWAVEFORMATEX pwfx, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);
    auto function = WinmmFunction<Fn>("waveOutOpen");
    return function(phwo, uDeviceID, pwfx, dwCallback, dwInstance, fdwOpen);
}
extern "C" MMRESULT WINAPI Proxy_waveOutPause(HWAVEOUT hwo) {
    using Fn = MMRESULT (WINAPI*)(HWAVEOUT hwo);
    auto function = WinmmFunction<Fn>("waveOutPause");
    return function(hwo);
}
extern "C" MMRESULT WINAPI Proxy_waveOutPrepareHeader(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh) {
    using Fn = MMRESULT (WINAPI*)(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh);
    auto function = WinmmFunction<Fn>("waveOutPrepareHeader");
    return function(hwo, pwh, cbwh);
}
extern "C" MMRESULT WINAPI Proxy_waveOutReset(HWAVEOUT hwo) {
    using Fn = MMRESULT (WINAPI*)(HWAVEOUT hwo);
    auto function = WinmmFunction<Fn>("waveOutReset");
    return function(hwo);
}
extern "C" MMRESULT WINAPI Proxy_waveOutRestart(HWAVEOUT hwo) {
    using Fn = MMRESULT (WINAPI*)(HWAVEOUT hwo);
    auto function = WinmmFunction<Fn>("waveOutRestart");
    return function(hwo);
}
extern "C" MMRESULT WINAPI Proxy_waveOutSetPitch(HWAVEOUT hwo, DWORD dwPitch) {
    using Fn = MMRESULT (WINAPI*)(HWAVEOUT hwo, DWORD dwPitch);
    auto function = WinmmFunction<Fn>("waveOutSetPitch");
    return function(hwo, dwPitch);
}
extern "C" MMRESULT WINAPI Proxy_waveOutSetPlaybackRate(HWAVEOUT hwo, DWORD dwRate) {
    using Fn = MMRESULT (WINAPI*)(HWAVEOUT hwo, DWORD dwRate);
    auto function = WinmmFunction<Fn>("waveOutSetPlaybackRate");
    return function(hwo, dwRate);
}
extern "C" MMRESULT WINAPI Proxy_waveOutSetVolume(HWAVEOUT hwo, DWORD dwVolume) {
    using Fn = MMRESULT (WINAPI*)(HWAVEOUT hwo, DWORD dwVolume);
    auto function = WinmmFunction<Fn>("waveOutSetVolume");
    return function(hwo, dwVolume);
}
extern "C" MMRESULT WINAPI Proxy_waveOutUnprepareHeader(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh) {
    using Fn = MMRESULT (WINAPI*)(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh);
    auto function = WinmmFunction<Fn>("waveOutUnprepareHeader");
    return function(hwo, pwh, cbwh);
}
extern "C" MMRESULT WINAPI Proxy_waveOutWrite(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh) {
    using Fn = MMRESULT (WINAPI*)(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh);
    auto function = WinmmFunction<Fn>("waveOutWrite");
    return function(hwo, pwh, cbwh);
}

#include <Windows.h>
#include <thread>
#include <iostream>

#include "../GolfSDK/SDK.hpp"
#include "TfdOverlay.h"
#include "../console/console.hpp"

//#define PRINT_DEBUG(a, ...) do {FILE *t = fopen("DEBUG_LOG.txt", "a"); fprintf(t, "%u " a, GetCurrentThreadId(), __VA_ARGS__); fclose(t); WSASetLastError(0);} while (0)


DWORD WINAPI MainThread(LPVOID lpReserved);

BOOL APIENTRY DllMain(const HMODULE hModule, const DWORD ul_reason_for_call) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, MainThread, hModule, 0, nullptr);
    }

    return TRUE;
}

DWORD WINAPI MainThread(const LPVOID lpReserved) {
    auto hModule = static_cast<HMODULE>(lpReserved);

    Console::Alloc();

    const auto Overlay = new TfdOverlay();
    OverlayBase::Instance = Overlay;
    Overlay->SetupOverlay();

    WaitForSingleObject(lpReserved, INFINITE);

    return TRUE;
}
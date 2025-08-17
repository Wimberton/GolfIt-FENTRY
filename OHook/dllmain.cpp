#include <Windows.h>
#include <thread>
#include <iostream>

#include <SDK.hpp>
#include "GolfOverlay.h"
#include "console.hpp"

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

    const auto Overlay = new GolfOverlay();
    OverlayBase::Instance = Overlay;
    Overlay->SetupOverlay();

    WaitForSingleObject(lpReserved, INFINITE);

    return TRUE;
}
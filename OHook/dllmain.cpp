#include <Windows.h>
#include <thread>
#include <iostream>

#include <SDK.hpp>
#include "GolfOverlay.h"
#include "console.hpp"
#include "DLLAuth.h"

std::string GenerateSessionKey();
bool AuthenticateWithServer();

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

    TUObjectArrayWrapper objectWrapper;
    objectWrapper.InitGObjects();

    Console::Alloc();

    // Authenticate with server before proceeding
    if (!AuthenticateWithServer()) {
        LOG("[!] Authentication failed. Exiting.\n");
        FreeLibraryAndExitThread(hModule, 0);
    }

    const auto Overlay = new GolfOverlay();
    OverlayBase::Instance = Overlay;
    Overlay->SetupOverlay();

    WaitForSingleObject(lpReserved, INFINITE);

    return TRUE;
}

std::string GenerateSessionKey() {
    SYSTEMTIME st;
    GetLocalTime(&st);

    std::stringstream ss;
    ss << "FREE_DLL_" << st.wYear << st.wMonth << st.wDay << "_" << st.wHour << st.wMinute << st.wSecond;

    return ss.str();
}

bool AuthenticateWithServer() {
    LOG("[+] Starting free DLL authentication (terms acceptance)...\n");

    std::string sessionKey = GenerateSessionKey();
    LOG("[+] Generated session key: %s\n", sessionKey.c_str());

    DLLAuth auth(sessionKey, "1.0.0");

    bool authResult = auth.Authenticate();

    if (authResult) {
        LOG("[+] Terms accepted! Free DLL authentication successful!\n");
        return true;
    }
    else {
        LOG("[!] Terms not accepted or authentication failed!\n");
        return false;
    }
}
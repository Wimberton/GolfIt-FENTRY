#include <Windows.h>
#include <chrono>
#include <thread>
#include <mutex>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <io.h>
#include <fcntl.h>

#include "SDKExt.h"
#include "Utils.h"
#include "Configuration.h"

#include "DetourManager.h"
#include <SDK/GolfIt_parameters.hpp>
#include "../GolfSDK/SDK.hpp"
#include "TfdOverlay.h"
#include "../console/console.hpp"
#include "ComponentLogger.h"
#include "Features/AimFeatures.h"
#include "Features/PlayerFeatures.h"

using namespace SDK;

// Helper variables
FVector2D ScreenMiddle = { 0, 0 };

// Initialize Golf Ball ESP colors from configuration
ImU32 GolfBallESPColor = Configuration::cfg_GolfBallESPColor;
ImU32 GolfBallESPColorTarget = Configuration::cfg_GolfBallESPColorTarget;
ImU32 GoalFlagESPColor = Configuration::cfg_GoalFlagESPColor;

// Health bar colors
ImU32 HealthBarColorGreen = IM_COL32(0, 255, 0, 255);
ImU32 HealthBarColorYellow = IM_COL32(255, 255, 0, 255);
ImU32 HealthBarColorRed = IM_COL32(255, 0, 0, 255);

// Detouring

void DetourManager::ProcessEventDetour(const UObject* Class, const UFunction* Function, void* Params) {
    const auto Overlay = dynamic_cast<TfdOverlay*>(OverlayBase::Instance);
    const auto fn = Function->GetFullName();
    invocations.insert(fn);
    
    // Debug: Log golf-related functions for teleport feature development
    // if (fn.find("Putter_BP") != std::string::npos) {
    //     LOG_DEBUG("PUTTER_FUNCTION: %s", fn.c_str());
    // }
    
    // if (fn.find("GolfBall") != std::string::npos) {
    //     LOG_DEBUG("GOLFBALL_FUNCTION: %s", fn.c_str());
    // }
    
    // Log any hit/shoot related functions
    // if (fn.find("Hit") != std::string::npos || fn.find("Shoot") != std::string::npos || 
    //     fn.find("Strike") != std::string::npos || fn.find("Impulse") != std::string::npos) {
    //     LOG_DEBUG("HIT_SHOOT_FUNCTION: %s", fn.c_str());
    // }

    // Initialize console for debugging output on first call
     //static bool consoleInitialized = false;
     //if (!consoleInitialized) {
     //    AllocConsole();
     //    freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
     //    freopen_s(reinterpret_cast<FILE**>(stderr), "CONOUT$", "w", stderr);
     //    freopen_s(reinterpret_cast<FILE**>(stdin), "CONIN$", "r", stdin);
     //    std::cout << "[OriginTFD2] Console initialized for debugging\n";
     //    consoleInitialized = true;
     //}

    // Initialize component logger on first call
     //static bool componentLoggerInitialized = false;
     //if (!componentLoggerInitialized) {
     //   ComponentLogger::Initialize();
     //   componentLoggerInitialized = true;
     //}
    
    // Initialize color manager on first call
    //static bool colorManagerInitialized = false;
    //if (!colorManagerInitialized) {
    //    ColorManager::Initialize();
    //    colorManagerInitialized = true;
    //}

    // Initialize cheat manager on first call
    //static bool cheatManagerInitialized = false;
    //if (!cheatManagerInitialized) {
    //    UWorld* GWorld = GetWorld();
    //    if (GWorld && GWorld->OwningGameInstance && GWorld->OwningGameInstance->LocalPlayers && GWorld->OwningGameInstance->LocalPlayers.Num() > 0) {
    //        const ULocalPlayer* LocalPlayer = GWorld->OwningGameInstance->LocalPlayers[0];
    //        if (LocalPlayer && LocalPlayer->PlayerController && LocalPlayer->PlayerController->IsA(APlayerController::StaticClass())) {
    //            APlayerController* LocalPlayerController = LocalPlayer->PlayerController;
    //            if (LocalPlayerController && !LocalPlayerController->CheatManager && LocalPlayerController->CheatClass) {
    //                LocalPlayerController->CheatManager = static_cast<UCheatManager*>(UGameplayStatics::SpawnObject(LocalPlayerController->CheatClass, LocalPlayerController));
    //                LocalPlayerController->EnableCheats();
    //                LOG_DEBUG("CHEAT_MANAGER: Spawned CheatManager and enabled cheats for LocalPlayerController");
    //            }
    //        }
    //    }
    //    cheatManagerInitialized = true;
    //}

    // Call ComponentLogger to process this event for logging
    // ComponentLogger::ProcessEvent(Class, Function, Params);

    // PlayerTick
    if (fn == "Function Engine.Actor.ReceiveTick") {
        if (Overlay) {
            static bool actorCacheInitialized = false;
            if (!actorCacheInitialized) {
                ActorCache::GetInstance().Initialize(Overlay);
                actorCacheInitialized = true;
            }
            ActorCache::GetInstance().Update();
        }
    }
    // HUD
    else if (fn == "Function Engine.HUD.ReceiveDrawHUD") {
        if (Overlay) {
            // add mods
            PlayerFeatures::Func_DoNoClip();
            // PlayerFeatures::Func_DoSpeedmod();
            PlayerFeatures::Func_DoMultiJump();
            PlayerFeatures::Func_DoTeleportToGoal();
            PlayerFeatures::Func_UnlitMode();

            // Targeting and aimbot features
            AimFeatures::Func_DoTargeting(Overlay, static_cast<const AHUD*>(Class));
            AimFeatures::Func_DoAimbot(Overlay, static_cast<const AHUD*>(Class));
            
            // Teleport features
            PlayerFeatures::Func_UnifiedTeleport(Overlay);

        }
    }

    if (OriginalProcessEvent) {
        OriginalProcessEvent(Class, Function, Params);
    }
}

// Essentials

void DetourManager::SetupDetour(void* Instance, void (*DetourFunc)(const UObject*, const UFunction*, void*)) {
    const void** Vtable = *static_cast<const void***>(Instance);

    DWORD OldProtection;
    VirtualProtect(Vtable, sizeof(DWORD) * 1024, PAGE_EXECUTE_READWRITE, &OldProtection);

    const int32_t Idx = Offsets::ProcessEventIdx;
    OriginalProcessEvent = reinterpret_cast<void(*)(const UObject*, const UFunction*, void*)>(reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr)) + Offsets::ProcessEvent);
    Vtable[Idx] = DetourFunc;

    HookedClient = Instance;
    VirtualProtect(Vtable, sizeof(DWORD) * 1024, OldProtection, &OldProtection);
}

void DetourManager::SetupDetour(void* Instance) {
    SetupDetour(Instance, &DetourManager::ProcessEventDetour);
}

void DetourManager::ProcessEventDetourCallback(const UObject* Class, const UFunction* Function, void* Params, const DetourManager* manager) {
    manager->ProcessEventDetour(Class, Function, Params);
}
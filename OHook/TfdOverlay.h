#pragma once

#include "SDKExt.h"
#include <OverlayBase.h>
#include <map>
#include <imgui.h>
#include <SDK.hpp>
#include <chrono>
#include <unordered_map>

using namespace SDK;

#define NO_HOTKEY -1
#define IsKeyPressed(key) GetAsyncKeyState(key) & 1 && GetAsyncKeyState(key) & 0x8000
#define IsKeyHeld(key) (GetAsyncKeyState(key) & 0x8000)

class TfdOverlay : public OverlayBase {
protected:
    void DrawHUD() override;
    void DrawOverlay() override;
    void DrawGuiFOVCircle() override;
    void DrawGuiESP() override;

public:
    // Cache for actor names
    std::unordered_map<int, std::string> ActorNameCache;
    std::unordered_map<int, std::string> ItemNameCache;
    bool UpdateCache = false;

    std::chrono::steady_clock::time_point LastPURetryTime;
    std::chrono::steady_clock::time_point LastDecomposeTime;

    SDK::AActor* Aimbot_Target;

    SDK::UWorld* GWorld;
    SDK::UEngine* GEngine;
    SDK::ULocalPlayer* LocalPlayer;
    SDK::APlayerController* PlayerController;

    SDK::AGolfItLobbyPlayerState* GolfItPlayerState;
    SDK::AGolfBall_C* LocalGolfBall;
    SDK::ACharacter* ActorCharacter;

    SDK::UGameViewportClient* LocalView;

    FName LockedBoneName;
    ULevel* CurrentLevel;
    std::string CurrentMap = "Unknown";

    bool bWaitingForKeyPress = false;
    bool AimbotInUse = false;
    // REMOVED: bScheduleNoCooldownNextFrame - was causing ability system crashes

    double SelectionThreshold = 50.0;
    double BestScore;
    AActor* BestTargetActor = nullptr;
    FVector BestTargetLocation;
    FRotator BestTargetRotation;

    // Silent aim globals (consolidated with main target variables)
    bool HasSilentAimTarget = false;
    FVector OriginalFireLoc = FVector();
    bool SilentAimActive = false;
    int SilentAimBoneIndex = -1;

    int screenWidth;
    int screenHeight;
};
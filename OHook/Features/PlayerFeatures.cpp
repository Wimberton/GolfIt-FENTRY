#include <cmath>
#include <algorithm>
#include <iostream>
#include "../Configuration.h"
#include "../Utils.h"
#include "../SDKExt.h"
#include "../TfdOverlay.h"
#include "PlayerFeatures.h"
#include "../../console/console.hpp"
#include <chrono>
#include <Windows.h>
#include <imgui.h>

using namespace SDK;

namespace PlayerFeatures {
    void Func_UnlitMode() {
        // Get World instance and verify it's valid
        UWorld* GWorld = GetWorld();
        if (!GWorld)
            return;

        // Check if OwningGameInstance is valid
        if (!GWorld->OwningGameInstance)
            return;

        // Get local golf ball and verify it's valid
        AGolfBall_C* LocalGolfBall = GetGolfBallC();
        if (!LocalGolfBall || !IsActorValid(LocalGolfBall))
            return;

        // Get player controller and verify it's valid
        APlayerController* PlayerController = GetAPC();
        if (!PlayerController || !IsActorValid(PlayerController))
            return;
            
        // Check if PlayerCameraManager is valid
        if (!PlayerController->PlayerCameraManager || !IsActorValid(PlayerController->PlayerCameraManager))
            return;

        // Get GameViewportClient through LocalPlayer
        UGameInstance* GameInstance = GWorld->OwningGameInstance;
        if (!GameInstance || !GameInstance->LocalPlayers || GameInstance->LocalPlayers.Num() <= 0) {
            LOG_DEBUG("UNLIT_MODE: GameInstance or LocalPlayers is null/empty");
            return;
        }

        const ULocalPlayer* LocalPlayer = GameInstance->LocalPlayers[0];
        if (!LocalPlayer || !LocalPlayer->PlayerController || !LocalPlayer->PlayerController->IsA(APlayerController::StaticClass())) {
            LOG_DEBUG("UNLIT_MODE: LocalPlayer or PlayerController is null/invalid");
            return;
        }

        UGameViewportClient* GameViewportClient = LocalPlayer->ViewportClient;
        if (!GameViewportClient) {
            LOG_DEBUG("UNLIT_MODE: GameViewportClient is null");
            return;
        }

        // Change viewmode at offset 0xB0
        // 0x1 = Unlit mode, 0x3 = Default lit mode
        uint8_t* ViewportClientPtr = reinterpret_cast<uint8_t*>(GameViewportClient);
        uint8_t* ViewModePtr = ViewportClientPtr + 0xB0;
        
        // Check current view mode and only set if it doesn't match what we want
        uint8_t currentViewMode = *ViewModePtr;
        uint8_t desiredViewMode = Configuration::cfg_EnableUnlitMode ? 0x1 : 0x3;
        
        if (currentViewMode != desiredViewMode) {
            *ViewModePtr = desiredViewMode;
            LOG_DEBUG("UNLIT_MODE: Changed viewmode from 0x%02X to 0x%02X (%s)", 
                      currentViewMode, desiredViewMode, 
                      Configuration::cfg_EnableUnlitMode ? "Unlit" : "Default");
        }
    }

    void Func_DoNoClip() {
        static bool wasNoClipEnabled = false;

        // Check if feature is enabled
        if (!Configuration::cfg_EnableNoClip)
            return;

        // Get World instance and verify it's valid
        UWorld* GWorld = GetWorld();
        if (!GWorld)
            return;

        // Get local golf ball and verify it's valid
        AGolfBall_C* LocalGolfBall = GetGolfBallC();
        if (!LocalGolfBall || !IsActorValid(LocalGolfBall))
            return;

        // Get player controller and verify it's valid
        APlayerController* PlayerController = GetAPC();
        if (!PlayerController || !IsActorValid(PlayerController))
            return;
            
        // Check if PlayerCameraManager is valid
        if (!PlayerController->PlayerCameraManager || !IsActorValid(PlayerController->PlayerCameraManager))
            return;

        // Get golf ball's primitive component for collision (golf balls use physics)
        UPrimitiveComponent* GolfBallPrimitive = static_cast<UPrimitiveComponent*>(LocalGolfBall->RootComponent);
        if (!GolfBallPrimitive || !IsComponentValid(GolfBallPrimitive))
            return;

        // Toggle noclip when key is pressed
        if (Configuration::cfg_EnableNoClip && (Configuration::cfg_NoClipKey == 0 || GetAsyncKeyState(Configuration::cfg_NoClipKey) & 0x8000)) {
            // Enable noclip if not already enabled
            if (!wasNoClipEnabled) {
                // Disable collision for golf ball
                GolfBallPrimitive->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
                
                // Disable physics simulation so we can control movement manually
                UStaticMeshComponent* GolfBallMesh = LocalGolfBall->GolfBall;
                if (GolfBallMesh && IsComponentValid(GolfBallMesh)) {
                    GolfBallMesh->SetSimulatePhysics(false);
                }
                
                wasNoClipEnabled = true;
            }

            const FRotator& CameraRot = PlayerController->PlayerCameraManager->GetCameraRotation();

            FVector CameraForward = UKismetMathLibrary::GetForwardVector(CameraRot);
            FVector CameraRight = UKismetMathLibrary::GetRightVector(CameraRot);
            constexpr FVector CameraUp = { 0.f, 0.f, 1.f };

            CameraForward.Normalize();
            CameraRight.Normalize();

            FVector MovementDirection = { 0.f, 0.f, 0.f };
            float FlySpeed = 1200.0f; // Faster for golf ball

            if (IsKeyHeld('W')) {
                MovementDirection += CameraForward * FlySpeed;
            }
            if (IsKeyHeld('S')) {
                MovementDirection -= CameraForward * FlySpeed;
            }
            if (IsKeyHeld('D')) {
                MovementDirection += CameraRight * FlySpeed;
            }
            if (IsKeyHeld('A')) {
                MovementDirection -= CameraRight * FlySpeed;
            }
            if (IsKeyHeld(VK_SPACE)) {
                MovementDirection += CameraUp * FlySpeed;
            }
            if (IsKeyHeld(VK_CONTROL)) {
                MovementDirection -= CameraUp * FlySpeed;
            }
            if (IsKeyHeld(VK_SHIFT)) {
                FlySpeed *= 2.0f;
            }

            // Normalize the total movement direction
            MovementDirection.Normalize();
            MovementDirection *= FlySpeed;

            constexpr float DeltaTime = 1.0f / 60.0f; // Assuming 60 FPS

            const FVector MovementDelta = MovementDirection * DeltaTime;

            FHitResult HitResult;
            LocalGolfBall->K2_SetActorLocation(LocalGolfBall->K2_GetActorLocation() + MovementDelta, false, &HitResult, false);
        }
        else if (wasNoClipEnabled) {
            // Disable noclip when key is not held
            GolfBallPrimitive->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
            
            // Re-enable physics simulation
            UStaticMeshComponent* GolfBallMesh = LocalGolfBall->GolfBall;
            if (GolfBallMesh && IsComponentValid(GolfBallMesh)) {
                GolfBallMesh->SetSimulatePhysics(true);
            }
            
            wasNoClipEnabled = false;
        }
    }

    void Func_DoSpeedmod() {
        static bool wasSpeedhackEnabled = false;

        // Check if feature is enabled
        if (!Configuration::cfg_EnableSpeedhack)
            return;

        // Get World instance and verify it's valid
        UWorld* GWorld = GetWorld();
        if (!GWorld)
            return;
            
        // Check if OwningGameInstance is valid
        if (!GWorld->OwningGameInstance)
            return;
            
        // Check if LocalPlayers array is valid and has at least one entry
        if (!GWorld->OwningGameInstance->LocalPlayers.IsValidIndex(0))
            return;

        // Get local golf ball and verify it's valid
        AGolfBall_C* LocalGolfBall = GetGolfBallC();
        if (!LocalGolfBall || !IsActorValid(LocalGolfBall))
            return;

        // Get player controller and verify it's valid
        APlayerController* PlayerController = GetAPC();
        if (!PlayerController || !IsActorValid(PlayerController))
            return;

        // Get golf it player state
        AGolfItLobbyPlayerState* GolfItPS = GetGolfItPS();
        if (!GolfItPS || !IsActorValid(GolfItPS))
            return;

        if (Configuration::cfg_EnableSpeedhack && (Configuration::cfg_SpeedKey == 0 || GetAsyncKeyState(Configuration::cfg_SpeedKey) & 0x8000)) {
            float SpeedMultiplier = Configuration::cfg_speedPlayerValue;
            LocalGolfBall->CustomTimeDilation = SpeedMultiplier;
            wasSpeedhackEnabled = true;
        }
        else if (wasSpeedhackEnabled) {
            LocalGolfBall->CustomTimeDilation = 1.0f;
            wasSpeedhackEnabled = false;
        }
    }

    void Func_DoMultiJump() {
        // Check if feature is enabled
        if (!Configuration::cfg_EnableMultiJump)
            return;

        // Get local golf ball and verify it's valid
        AGolfBall_C* LocalGolfBall = GetGolfBallC();
        if (!LocalGolfBall || !IsActorValid(LocalGolfBall))
            return;

        // Get player controller and verify it's valid
        APlayerController* PlayerController = GetAPC();
        if (!PlayerController || !IsActorValid(PlayerController))
            return;

        // Enable multi jump and set the amount
        LocalGolfBall->MultiJump = true;
        LocalGolfBall->MultiJumpAmount = Configuration::cfg_MultiJumpAmount;
    }

    void Func_DoTeleportToGoal() {
        // Check if feature is enabled
        if (!Configuration::cfg_EnableTeleportToGoal)
            return;

        // Check if teleport key is held
        if (Configuration::cfg_TeleportToGoalKey != 0 && !(GetAsyncKeyState(Configuration::cfg_TeleportToGoalKey) & 0x8000))
            return;

        // Get local golf ball and verify it's valid
        AGolfBall_C* LocalGolfBall = GetGolfBallC();
        if (!LocalGolfBall || !IsActorValid(LocalGolfBall))
            return;

        // Get the goal flag from ActorCache
        auto cachedGoalFlags = ActorCache::GetInstance().GetCachedGoalFlags();
        if (cachedGoalFlags.empty())
            return;

        // Find the closest goal flag
        FVector LocalGolfBallLocation = LocalGolfBall->K2_GetActorLocation();
        AGoalNumberRotation_C* ClosestGoal = nullptr;
        float ClosestDistance = FLT_MAX;

        for (const auto& goalInfo : cachedGoalFlags) {
            if (!goalInfo.Actor || !IsActorValid(goalInfo.Actor))
                continue;

            AGoalNumberRotation_C* Goal = static_cast<AGoalNumberRotation_C*>(goalInfo.Actor);
            if (!Goal || !IsActorValid(Goal))
                continue;

            FVector GoalLocation = Goal->K2_GetActorLocation();
            float Distance = GetDistance3D(LocalGolfBallLocation, GoalLocation);
            
            if (Distance < ClosestDistance) {
                ClosestDistance = Distance;
                ClosestGoal = Goal;
            }
        }

        if (!ClosestGoal)
            return;

        // Teleport to goal flag location (offset slightly above it)
        FVector GoalLocation = ClosestGoal->K2_GetActorLocation();
        GoalLocation.Z += 200.0f; // Offset above the goal to drop in

        FHitResult HitResult;
        LocalGolfBall->K2_SetActorLocation(GoalLocation, false, &HitResult, false);
        
        // Optional: Reset physics to make the ball drop naturally
        UStaticMeshComponent* GolfBallMesh = LocalGolfBall->GolfBall;
        if (GolfBallMesh && IsComponentValid(GolfBallMesh)) {
            GolfBallMesh->SetSimulatePhysics(true);
            // Give it a small downward velocity to ensure it drops
            // SetPhysicsLinearVelocity(NewVel, bAddToCurrent, BoneName)
            GolfBallMesh->SetPhysicsLinearVelocity(FVector(0.0f, 0.0f, -100.0f), false, UKismetStringLibrary::Conv_StringToName(L"None"));
        }
    }
}

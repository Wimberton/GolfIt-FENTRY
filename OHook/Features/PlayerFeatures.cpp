#include <cmath>
#include <algorithm>
#include <iostream>
#include "Configuration.h"
#include "Utils.h"
#include "SDKExt.h"
#include "GolfOverlay.h"
#include "PlayerFeatures.h"
#include "console.hpp"
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

        // Get local golf ball and verify it's valid (for position reference)
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

        if (Configuration::cfg_TeleportAllPlayers) {
            // CHAOS MODE: Teleport ALL golf balls to the goal! 😂
            auto cachedGolfBalls = ActorCache::GetInstance().GetCachedGolfBalls();
            
            LOG_DEBUG("TELEPORT_ALL: Starting chaos mode with %d cached golf balls", (int)cachedGolfBalls.size());
            
            // Add some random offset so players don't stack exactly on each other
            int playerCount = 0;
            int successfulTeleports = 0;
            
            for (const auto& ballInfo : cachedGolfBalls) {
                if (!ballInfo.Actor || !IsActorValid(ballInfo.Actor)) {
                    LOG_DEBUG("TELEPORT_ALL: Skipping invalid actor %d", playerCount);
                    continue;
                }
                    
                AGolfBall_C* GolfBall = static_cast<AGolfBall_C*>(ballInfo.Actor);
                if (!GolfBall || !IsActorValid(GolfBall)) {
                    LOG_DEBUG("TELEPORT_ALL: Skipping invalid golf ball %d", playerCount);
                    continue;
                }

                // Create a slight offset for each player so they don't stack
                FVector PlayerGoalLocation = GoalLocation;
                PlayerGoalLocation.X += (playerCount % 3 - 1) * 100.0f; // -100, 0, 100
                PlayerGoalLocation.Y += (playerCount / 3 - 1) * 100.0f; // Grid pattern
                
                LOG_DEBUG("TELEPORT_ALL: Teleporting player %d (%s) to (%.1f, %.1f, %.1f)", 
                          playerCount, ballInfo.DisplayName.c_str(), 
                          PlayerGoalLocation.X, PlayerGoalLocation.Y, PlayerGoalLocation.Z);
                
                FHitResult HitResult;
                GolfBall->K2_SetActorLocation(PlayerGoalLocation, false, &HitResult, false);
                
                // Reset physics for this golf ball
                UStaticMeshComponent* GolfBallMesh = GolfBall->GolfBall;
                if (GolfBallMesh && IsComponentValid(GolfBallMesh)) {
                    GolfBallMesh->SetSimulatePhysics(true);
                    // Give it a small downward velocity to ensure it settles properly
                    FVector downwardVelocity; 
                    downwardVelocity.X = 0.0f;
                    downwardVelocity.Y = 0.0f;
                    downwardVelocity.Z = -50.0f;
                    GolfBallMesh->SetPhysicsLinearVelocity(downwardVelocity, false, UKismetStringLibrary::Conv_StringToName(L"None"));
                    successfulTeleports++;
                }
                
                playerCount++;
            }
            
            LOG_DEBUG("TELEPORT_ALL: Successfully teleported %d out of %d players", successfulTeleports, playerCount);
            
            // Also teleport the local player with a slight offset
            FVector LocalPlayerGoalLocation = GoalLocation;
            LocalPlayerGoalLocation.X += 75.0f; // Offset so local player doesn't stack with others
            
            FHitResult LocalHitResult;
            LocalGolfBall->K2_SetActorLocation(LocalPlayerGoalLocation, false, &LocalHitResult, false);
            
            UStaticMeshComponent* LocalGolfBallMesh = LocalGolfBall->GolfBall;
            if (LocalGolfBallMesh && IsComponentValid(LocalGolfBallMesh)) {
                LocalGolfBallMesh->SetSimulatePhysics(true);
                FVector localDownwardVelocity;
                localDownwardVelocity.X = 0.0f;
                localDownwardVelocity.Y = 0.0f;
                localDownwardVelocity.Z = -50.0f;
                LocalGolfBallMesh->SetPhysicsLinearVelocity(localDownwardVelocity, false, UKismetStringLibrary::Conv_StringToName(L"None"));
            }
        }
        else {
            // Normal mode: Only teleport local player
            FHitResult HitResult;
            LocalGolfBall->K2_SetActorLocation(GoalLocation, false, &HitResult, false);
            
            // Reset physics to make the ball drop naturally
            UStaticMeshComponent* GolfBallMesh = LocalGolfBall->GolfBall;
            if (GolfBallMesh && IsComponentValid(GolfBallMesh)) {
                GolfBallMesh->SetSimulatePhysics(true);
                // Give it a small downward velocity to ensure it settles properly
                FVector normalDownwardVelocity;
                normalDownwardVelocity.X = 0.0f;
                normalDownwardVelocity.Y = 0.0f;
                normalDownwardVelocity.Z = -50.0f;
                GolfBallMesh->SetPhysicsLinearVelocity(normalDownwardVelocity, false, UKismetStringLibrary::Conv_StringToName(L"None"));
            }
        }
    }

    void Func_UnifiedTeleport(GolfOverlay* Overlay) {
        // Check if teleport feature is enabled and overlay is valid
        if (!Configuration::cfg_EnableTPTarget || !Overlay)
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
        
        // Check if teleport key is pressed
        if (!(GetAsyncKeyState(Configuration::cfg_TPTargetKey) & 0x8000))
            return;
        
        // First, try to use the aimbot target if available
        if (Overlay->BestTargetActor && IsActorValid(Overlay->BestTargetActor)) {
            LOG_DEBUG("UNIFIED_TELEPORT: Found target actor, checking TP conditions...");
            
            bool canTeleportToTarget = true;
            
            // If smaller TP targeting is enabled, check if target is within the smaller FOV radius
            if (Configuration::cfg_SmallerTPTargeting) {
                // Project target to screen and check if it's within the smaller TP radius
                FVector2D TargetScreenPosition;
                if (PlayerController->ProjectWorldLocationToScreen(Overlay->BestTargetLocation, &TargetScreenPosition, true)) {
                    // Calculate screen center
                    ImVec2 ScreenSize = ImGui::GetIO().DisplaySize;
                    FVector2D ScreenCenter = { ScreenSize.x * 0.5f, ScreenSize.y * 0.5f };
                    
                    // Calculate distance from center
                    float DistanceFromCenter = CustomMath::Sqrt(
                        CustomMath::Square(TargetScreenPosition.X - ScreenCenter.X) +
                        CustomMath::Square(TargetScreenPosition.Y - ScreenCenter.Y)
                    );
                    
                    // Check if target is within the smaller TP FOV radius
                    float TPRadius = Configuration::cfg_TPFOVRadius;
                    if (DistanceFromCenter > TPRadius) {
                        canTeleportToTarget = false;
                        LOG_DEBUG("UNIFIED_TELEPORT: Target outside TP FOV radius (%.1f > %.1f)", DistanceFromCenter, TPRadius);
                    } else {
                        LOG_DEBUG("UNIFIED_TELEPORT: Target within TP FOV radius (%.1f <= %.1f)", DistanceFromCenter, TPRadius);
                    }
                } else {
                    // If we can't project to screen, don't teleport
                    canTeleportToTarget = false;
                    LOG_DEBUG("UNIFIED_TELEPORT: Cannot project target to screen");
                }
            }
            
            if (canTeleportToTarget) {
                // Get target location from the best target location instead of actor location
                FVector TargetLocation = Overlay->BestTargetLocation;
                
                // Better offset calculation: offset based on target type
                if (Configuration::cfg_ActorTeleportOffset > 0) {
                    // For goal flags, teleport close to the goal with minimal offset
                    if (Overlay->BestTargetActor->IsA(AGoalNumberRotation_C::StaticClass())) {
                        TargetLocation.Z += 25.0f; // Minimal offset above the goal
                        // Small horizontal offset to avoid being exactly on the goal
                        TargetLocation.X += 50.0f; 
                        TargetLocation.Y += 25.0f;
                    }
                    // For golf balls, teleport to the side with specified offset
                    else if (Overlay->BestTargetActor->IsA(AGolfBall_C::StaticClass())) {
                        FVector LocalLocation = LocalGolfBall->K2_GetActorLocation();
                        FVector DirectionToTarget = (TargetLocation - LocalLocation).GetNormalized();
                        FVector SideOffset = FVector(-DirectionToTarget.Y, DirectionToTarget.X, 0.0f) * Configuration::cfg_ActorTeleportOffset;
                        TargetLocation = TargetLocation + SideOffset;
                        TargetLocation.Z += 50.0f; // Slightly above to avoid collision
                    }
                }
                
                LOG_DEBUG("UNIFIED_TELEPORT: Teleporting to target at (%.1f, %.1f, %.1f)", 
                          TargetLocation.X, TargetLocation.Y, TargetLocation.Z);
                
                // Teleport golf ball to target location
                FHitResult HitResult;
                LocalGolfBall->K2_SetActorLocation(TargetLocation, false, &HitResult, false);
                
                // Reset physics after teleport
                UStaticMeshComponent* GolfBallMesh = LocalGolfBall->GolfBall;
                if (GolfBallMesh && IsComponentValid(GolfBallMesh)) {
                    GolfBallMesh->SetSimulatePhysics(true);
                }
                
                return; // Exit early since we teleported to target
            }
        }
        // If no target, teleport in the direction player is looking
        LOG_DEBUG("UNIFIED_TELEPORT: No valid target found, teleporting forward");
        
        FVector LocalGolfBallLocation = LocalGolfBall->K2_GetActorLocation();
        
        // Check if PlayerCameraManager is valid
        if (!PlayerController->PlayerCameraManager || !IsActorValid(PlayerController->PlayerCameraManager))
            return;
            
        FRotator CameraRotation = PlayerController->PlayerCameraManager->GetCameraRotation();

        FVector ForwardDirection = UKismetMathLibrary::GetForwardVector(CameraRotation);
        ForwardDirection.Normalize();

        float TeleportDistance = Configuration::cfg_TPNoTargetDistance;
        FVector TeleportLocation = LocalGolfBallLocation + (ForwardDirection * TeleportDistance);

        LOG_DEBUG("UNIFIED_TELEPORT: Teleporting forward %.1f units to (%.1f, %.1f, %.1f)", 
                  TeleportDistance, TeleportLocation.X, TeleportLocation.Y, TeleportLocation.Z);

        // Teleport golf ball forward
        FHitResult HitResult;
        LocalGolfBall->K2_SetActorLocation(TeleportLocation, false, &HitResult, false);
        
        // Reset physics after teleport
        UStaticMeshComponent* GolfBallMesh = LocalGolfBall->GolfBall;
        if (GolfBallMesh && IsComponentValid(GolfBallMesh)) {
            GolfBallMesh->SetSimulatePhysics(true);
        }
    }

    // ======== PLAYER CONTROL FUNCTIONS ======== //
    
    void TeleportPlayerToGoal(AGolfBall_C* targetPlayer) {
        if (!targetPlayer || !IsActorValid(targetPlayer))
            return;

        // Get the goal flag from ActorCache (find closest goal to target player)
        auto cachedGoalFlags = ActorCache::GetInstance().GetCachedGoalFlags();
        if (cachedGoalFlags.empty()) {
            LOG_DEBUG("TELEPORT_TO_GOAL: No goal flags found in cache");
            return;
        }
        
        // Debug: Also check how many golf balls we can see in the world directly
        UWorld* GWorld = GetWorld();
        if (GWorld && GWorld->Levels.IsValid()) {
            int totalGolfBalls = 0;
            int validGolfBalls = 0;
            
            for (int i = 0; i < GWorld->Levels.Num(); ++i) {
                if (!GWorld->Levels.IsValidIndex(i))
                    continue;

                const auto Level = GWorld->Levels[i];
                if (!Level)
                    continue;

                for (int j = 0; j < Level->Actors.Num(); ++j) {
                    const auto Actor = Level->Actors[j];
                    if (!Actor || !IsActorValid(Actor))
                        continue;

                    if (Actor->IsA(AGolfBall_C::StaticClass())) {
                        totalGolfBalls++;
                        AGolfBall_C* GolfBall = static_cast<AGolfBall_C*>(Actor);
                        if (GolfBall && IsActorValid(GolfBall)) {
                            validGolfBalls++;
                        }
                    }
                }
            }
            
            LOG_DEBUG("TELEPORT_TO_GOAL: Found %d total golf balls in world, %d valid", totalGolfBalls, validGolfBalls);
        }

        // Find the closest goal flag to the target player
        FVector targetPlayerLocation = targetPlayer->K2_GetActorLocation();
        AGoalNumberRotation_C* ClosestGoal = nullptr;
        float ClosestDistance = FLT_MAX;

        for (const auto& goalInfo : cachedGoalFlags) {
            if (!goalInfo.Actor || !IsActorValid(goalInfo.Actor))
                continue;

            AGoalNumberRotation_C* Goal = static_cast<AGoalNumberRotation_C*>(goalInfo.Actor);
            if (!Goal || !IsActorValid(Goal))
                continue;

            FVector GoalLocation = Goal->K2_GetActorLocation();
            float Distance = GetDistance3D(targetPlayerLocation, GoalLocation);
            
            if (Distance < ClosestDistance) {
                ClosestDistance = Distance;
                ClosestGoal = Goal;
            }
        }

        if (!ClosestGoal)
            return;

        // Teleport target player to goal flag location (offset slightly above it)
        FVector GoalLocation = ClosestGoal->K2_GetActorLocation();
        GoalLocation.Z += 50.0f; // Small offset above the goal to avoid clipping

        FHitResult HitResult;
        targetPlayer->K2_SetActorLocation(GoalLocation, false, &HitResult, false);

        // Reset physics for the target player's golf ball
        UStaticMeshComponent* GolfBallMesh = targetPlayer->GolfBall;
        if (GolfBallMesh && IsComponentValid(GolfBallMesh)) {
            GolfBallMesh->SetSimulatePhysics(true);
            FVector downwardVelocity;
            downwardVelocity.X = 0.0f;
            downwardVelocity.Y = 0.0f;
            downwardVelocity.Z = -50.0f;
            GolfBallMesh->SetPhysicsLinearVelocity(downwardVelocity, false, UKismetStringLibrary::Conv_StringToName(L"None"));
        }
    }

    void TeleportPlayerToMe(AGolfBall_C* targetPlayer) {
        if (!targetPlayer || !IsActorValid(targetPlayer))
            return;

        // Get local golf ball location
        AGolfBall_C* LocalGolfBall = GetGolfBallC();
        if (!LocalGolfBall || !IsActorValid(LocalGolfBall))
            return;

        FVector LocalLocation = LocalGolfBall->K2_GetActorLocation();
        LocalLocation.X += 100.0f; // Offset slightly so players don't stack
        LocalLocation.Z += 50.0f;  // Slightly above to avoid collision

        FHitResult HitResult;
        targetPlayer->K2_SetActorLocation(LocalLocation, false, &HitResult, false);

        // Reset physics
        UStaticMeshComponent* GolfBallMesh = targetPlayer->GolfBall;
        if (GolfBallMesh && IsComponentValid(GolfBallMesh)) {
            GolfBallMesh->SetSimulatePhysics(true);
        }
    }

    void TeleportMeToPlayer(AGolfBall_C* targetPlayer) {
        if (!targetPlayer || !IsActorValid(targetPlayer))
            return;

        // Get local golf ball
        AGolfBall_C* LocalGolfBall = GetGolfBallC();
        if (!LocalGolfBall || !IsActorValid(LocalGolfBall))
            return;

        FVector TargetLocation = targetPlayer->K2_GetActorLocation();
        TargetLocation.X += 100.0f; // Offset slightly so balls don't stack
        TargetLocation.Z += 50.0f;  // Slightly above to avoid collision

        FHitResult HitResult;
        LocalGolfBall->K2_SetActorLocation(TargetLocation, false, &HitResult, false);

        // Reset physics
        UStaticMeshComponent* LocalGolfBallMesh = LocalGolfBall->GolfBall;
        if (LocalGolfBallMesh && IsComponentValid(LocalGolfBallMesh)) {
            LocalGolfBallMesh->SetSimulatePhysics(true);
        }
    }

    void FreezePlayer(AGolfBall_C* targetPlayer) {
        if (!targetPlayer || !IsActorValid(targetPlayer))
            return;

        // Disable physics simulation to freeze the golf ball
        UStaticMeshComponent* GolfBallMesh = targetPlayer->GolfBall;
        if (GolfBallMesh && IsComponentValid(GolfBallMesh)) {
            GolfBallMesh->SetSimulatePhysics(false);
            
            // Also set velocity to zero
            FVector zeroVelocity = {0.0f, 0.0f, 0.0f};
            GolfBallMesh->SetPhysicsLinearVelocity(zeroVelocity, false, UKismetStringLibrary::Conv_StringToName(L"None"));
            GolfBallMesh->SetPhysicsAngularVelocityInDegrees(zeroVelocity, false, UKismetStringLibrary::Conv_StringToName(L"None"));
        }
    }

    void UnfreezePlayer(AGolfBall_C* targetPlayer) {
        if (!targetPlayer || !IsActorValid(targetPlayer))
            return;

        // Re-enable physics simulation to unfreeze the golf ball
        UStaticMeshComponent* GolfBallMesh = targetPlayer->GolfBall;
        if (GolfBallMesh && IsComponentValid(GolfBallMesh)) {
            GolfBallMesh->SetSimulatePhysics(true);
        }
    }

    void LaunchPlayer(AGolfBall_C* targetPlayer) {
        if (!targetPlayer || !IsActorValid(targetPlayer))
            return;

        // Launch the golf ball into the air with upward velocity
        UStaticMeshComponent* GolfBallMesh = targetPlayer->GolfBall;
        if (GolfBallMesh && IsComponentValid(GolfBallMesh)) {
            GolfBallMesh->SetSimulatePhysics(true);
            
            // Apply strong upward force
            FVector launchVelocity = {0.0f, 0.0f, 1500.0f}; // Strong upward velocity
            GolfBallMesh->SetPhysicsLinearVelocity(launchVelocity, false, UKismetStringLibrary::Conv_StringToName(L"None"));
        }
    }

    void SpeedUpPlayer(AGolfBall_C* targetPlayer) {
        if (!targetPlayer || !IsActorValid(targetPlayer))
            return;

        // Increase time dilation for faster movement
        targetPlayer->CustomTimeDilation = 3.0f; // 3x speed
    }

    void SlowDownPlayer(AGolfBall_C* targetPlayer) {
        if (!targetPlayer || !IsActorValid(targetPlayer))
            return;

        // Decrease time dilation for slower movement
        targetPlayer->CustomTimeDilation = 0.5f; // Half speed
    }

    void ResetPlayer(AGolfBall_C* targetPlayer) {
        if (!targetPlayer || !IsActorValid(targetPlayer))
            return;

        // Reset all modifications to normal state
        targetPlayer->CustomTimeDilation = 1.0f; // Normal speed

        // Re-enable physics if disabled
        UStaticMeshComponent* GolfBallMesh = targetPlayer->GolfBall;
        if (GolfBallMesh && IsComponentValid(GolfBallMesh)) {
            GolfBallMesh->SetSimulatePhysics(true);
            
            // Reset velocities
            FVector zeroVelocity = {0.0f, 0.0f, 0.0f};
            GolfBallMesh->SetPhysicsLinearVelocity(zeroVelocity, false, UKismetStringLibrary::Conv_StringToName(L"None"));
            GolfBallMesh->SetPhysicsAngularVelocityInDegrees(zeroVelocity, false, UKismetStringLibrary::Conv_StringToName(L"None"));
        }

        // Reset any other golf ball properties to defaults
        targetPlayer->MultiJump = false;
        targetPlayer->MultiJumpAmount = 1;
    }
}

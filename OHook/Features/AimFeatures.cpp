#include "AimFeatures.h"
#include "../ActorCache.h"
#include "../Utils.h"
#include "../../console/console.hpp"
#include <SDK/GolfIt_parameters.hpp>
#include <chrono>
#include <algorithm>
#include <unordered_map>
#include <Windows.h>

using namespace SDK;

namespace AimFeatures {
    void Func_DoTargeting(TfdOverlay* Overlay, const SDK::AHUD* HUD)
    {        
        if (!Overlay || !HUD || !HUD->Canvas)
            return;

        const auto PlayerController = GetAPC();
        if (!PlayerController || !IsActorValid(PlayerController))
            return;

        const auto LocalGolfBall = GetGolfBallC();
        if (!LocalGolfBall || !IsActorValid(LocalGolfBall))
            return;

        FVector LocalGolfBallLocation = LocalGolfBall->K2_GetActorLocation();
        FVector ViewPoint = PlayerController->PlayerCameraManager->GetCameraLocation();

        float ScreenWidth = HUD->Canvas->SizeX;
        float ScreenHeight = HUD->Canvas->SizeY;
        FVector2D ScreenCenter = { ScreenWidth * 0.5f, ScreenHeight * 0.5f };

        double BestScore = DBL_MAX;
        bool HasValidTarget = false;
        AActor* CurrentBestTarget = nullptr;
        FVector BestTargetLocation;

        // Target Golf Balls if ESP is enabled
        if (Configuration::cfg_DrawGolfBallESP) {
            const auto& cachedGolfBalls = ActorCache::GetInstance().GetCachedGolfBalls();
            
            for (const auto& actorInfo : cachedGolfBalls)
            {
                if (!actorInfo.Actor || !IsActorValid(actorInfo.Actor))
                    continue;

                AGolfBall_C* GolfBall = static_cast<AGolfBall_C*>(actorInfo.Actor);
                if (!GolfBall || !IsActorValid(GolfBall))
                    continue;

                // Skip our own golf ball
                if (GolfBall == LocalGolfBall)
                    continue;

                FVector GolfBallLocation = GolfBall->K2_GetActorLocation();
                
                // Calculate distance
                float Distance = GetDistance3D(GolfBallLocation, LocalGolfBallLocation) / 100.0f; // Convert to meters
                if (Distance > Configuration::cfg_MaxGolfBallESPDistance / 100.0f)
                    continue;

                // Project to screen for FOV check
                FVector2D TargetScreenPosition;
                if (!PlayerController->ProjectWorldLocationToScreen(GolfBallLocation, &TargetScreenPosition, true))
                    continue;

                float ScreenDistance = CustomMath::Sqrt(
                    CustomMath::Square(TargetScreenPosition.X - ScreenCenter.X) +
                    CustomMath::Square(TargetScreenPosition.Y - ScreenCenter.Y)
                );

                // Simple scoring based on screen distance and 3D distance
                double Score = ScreenDistance + (Distance * 10.0f);

                if (Score < BestScore)
                {
                    BestScore = Score;
                    CurrentBestTarget = GolfBall;
                    BestTargetLocation = GolfBallLocation;
                    HasValidTarget = true;
                }
            }
        }
        
        // Target Goal Flags if ESP is enabled
        if (Configuration::cfg_DrawGoalFlagESP) {
            const auto& cachedGoalFlags = ActorCache::GetInstance().GetCachedGoalFlags();
            
            static int goalTargetingLogCounter = 0;
            goalTargetingLogCounter++;
            if (goalTargetingLogCounter % 300 == 0) { // Log every 300 frames (5 seconds at 60fps)
                LOG_DEBUG("TARGETING: Goal Flag ESP enabled, found %d cached goal flags", (int)cachedGoalFlags.size());
            }
            
            for (const auto& actorInfo : cachedGoalFlags)
            {
                if (!actorInfo.Actor || !IsActorValid(actorInfo.Actor))
                    continue;

                AGoalNumberRotation_C* GoalFlag = static_cast<AGoalNumberRotation_C*>(actorInfo.Actor);
                if (!GoalFlag || !IsActorValid(GoalFlag))
                    continue;

                FVector GoalFlagLocation = GoalFlag->K2_GetActorLocation();
                
                // Calculate distance
                float Distance = GetDistance3D(GoalFlagLocation, LocalGolfBallLocation) / 100.0f; // Convert to meters
                if (Distance > Configuration::cfg_MaxGoalFlagESPDistance / 100.0f)
                    continue;

                // Project to screen for FOV check
                FVector2D TargetScreenPosition;
                if (!PlayerController->ProjectWorldLocationToScreen(GoalFlagLocation, &TargetScreenPosition, true))
                    continue;

                float ScreenDistance = CustomMath::Sqrt(
                    CustomMath::Square(TargetScreenPosition.X - ScreenCenter.X) +
                    CustomMath::Square(TargetScreenPosition.Y - ScreenCenter.Y)
                );

                // Give goal flags priority by reducing their score (makes them more likely to be targeted)
                double Score = ScreenDistance + (Distance * 8.0f); // Lower multiplier = higher priority

                if (Score < BestScore)
                {
                    BestScore = Score;
                    CurrentBestTarget = GoalFlag;
                    BestTargetLocation = GoalFlagLocation;
                    HasValidTarget = true;
                }
            }
        }

        // Assign final results to the overlay for ESP highlighting
        if (HasValidTarget)
        {
            Overlay->BestTargetActor = CurrentBestTarget;
            Overlay->BestScore = BestScore;
            Overlay->BestTargetLocation = BestTargetLocation;
            Overlay->BestTargetRotation = UKismetMathLibrary::FindLookAtRotation(LocalGolfBallLocation, BestTargetLocation);
            
            // Debug logging
            std::string targetType = "Unknown";
            if (CurrentBestTarget->IsA(AGolfBall_C::StaticClass())) {
                targetType = "GolfBall";
            } else if (CurrentBestTarget->IsA(AGoalNumberRotation_C::StaticClass())) {
                targetType = "GoalFlag";
            }
            LOG_DEBUG("TARGETING: Found target %s at (%.1f, %.1f, %.1f), Score: %.2f", 
                      targetType.c_str(), BestTargetLocation.X, BestTargetLocation.Y, BestTargetLocation.Z, BestScore);
        }
        else
        {
            Overlay->BestTargetActor = nullptr;
            Overlay->BestScore = DBL_MAX;
            Overlay->BestTargetLocation = FVector{0.0f, 0.0f, 0.0f};
            Overlay->BestTargetRotation = FRotator{0.0f, 0.0f, 0.0f};
            LOG_DEBUG("TARGETING: No valid target found");
        }
    }
    
    void Func_DoAimbot(TfdOverlay* Overlay, const SDK::AHUD* HUD) {
        if (!Overlay || !HUD || !HUD->Canvas)
            return;

        if (Overlay->ShowOverlay() || !IsGameWindowActive())
            return;

        const auto PlayerController = GetAPC();
        if (!PlayerController || !IsActorValid(PlayerController))
            return;

        const auto LocalGolfBall = GetGolfBallC();
        if (!LocalGolfBall || !IsActorValid(LocalGolfBall))
            return;

        AActor* TargetActor = Overlay->BestTargetActor;
        if (!TargetActor || !IsActorValid(TargetActor))
            return;

        FVector BestTargetLocation = Overlay->BestTargetLocation;

        const auto CameraManager = PlayerController->PlayerCameraManager;
        if (!CameraManager || !IsActorValid(CameraManager))
            return;

        FVector CameraLocation = CameraManager->GetCameraLocation();
        FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(CameraLocation, BestTargetLocation);
        FRotator CurrentControlRotation = PlayerController->GetControlRotation();

        float SmoothingFactor = UKismetMathLibrary::Clamp(Configuration::cfg_AimbotSmoothing, 1.0f, 100.0f);
        bool bAimbotKeyHeld = (GetAsyncKeyState(Configuration::cfg_AimbotKey) & 0x8000) != 0;
        Overlay->AimbotInUse = bAimbotKeyHeld;

        // Handle targeting for any valid actor (golf balls, goal flags, etc.)
        if (IsActorValid(TargetActor)) {
            if (!bAimbotKeyHeld)
                return;

            if (SmoothingFactor == 1.0f) {
                PlayerController->SetControlRotation(TargetRotation);
            }
            else {
                float InterpSpeed = UKismetMathLibrary::MapRangeClamped(SmoothingFactor, 1.0f, 100.0f, 25.0f, 1.0f);
                float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(GetWorld());
                FRotator SmoothedRotation = UKismetMathLibrary::RInterpTo(CurrentControlRotation, TargetRotation, DeltaTime, InterpSpeed);

                PlayerController->SetControlRotation(SmoothedRotation);
            }
        }
    }
}
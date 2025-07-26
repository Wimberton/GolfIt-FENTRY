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

        // Get golf balls from actor cache
        const auto& cachedGolfBalls = ActorCache::GetInstance().GetCachedGolfBalls();

        // Loop over all cached golf balls
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

        // Assign final results to the overlay for ESP highlighting
        if (HasValidTarget)
        {
            Overlay->BestTargetActor = CurrentBestTarget;
            Overlay->BestScore = BestScore;
            Overlay->BestTargetLocation = BestTargetLocation;
            Overlay->BestTargetRotation = UKismetMathLibrary::FindLookAtRotation(LocalGolfBallLocation, BestTargetLocation);
        }
        else
        {
            Overlay->BestTargetActor = nullptr;
            Overlay->BestScore = DBL_MAX;
            Overlay->BestTargetLocation = FVector{0.0f, 0.0f, 0.0f};
            Overlay->BestTargetRotation = FRotator{0.0f, 0.0f, 0.0f};
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

        AGolfBall_C* TargetGolfBall = static_cast<AGolfBall_C*>(TargetActor);
        if (TargetGolfBall && IsActorValid(TargetGolfBall)) {
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
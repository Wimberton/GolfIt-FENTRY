#include "ESP.h"
#include "../Configuration.h"
#include "../ActorCache.h"
#include "../Utils.h"
#include "../SDKExt.h"
#include "../ImGuiExt.h"
#include "../TfdOverlay.h"
#include "../../RendererHook/OverlayBase.h"
#include <imgui_internal.h>
#include <Windows.h>
#include <algorithm>

using namespace SDK;

void ESP::DrawGuiFOVCircle() {
    TfdOverlay* Overlay = static_cast<TfdOverlay*>(OverlayBase::Instance);

    APlayerController* PlayerController = GetAPC();
    if (!PlayerController || !PlayerController->K2_GetPawn())
        return;

    FVector PawnLocation = PlayerController->K2_GetPawn()->K2_GetActorLocation();
    FVector2D PlayerScreenLocation;

    if (!PlayerController->ProjectWorldLocationToScreen(PawnLocation, &PlayerScreenLocation, true))
        return;

    FVector2D FOVCenter = { ImGui::GetIO().DisplaySize.x * 0.5f, ImGui::GetIO().DisplaySize.y * 0.5f };
    if (FOVCenter.X <= 0 || FOVCenter.Y <= 0)
        return;

    auto drawList = ImGui::GetBackgroundDrawList();
    if (!drawList)
        return;

    const ImU32 CircleColor = IM_COL32(0xFF, 0xFF, 0xFF, static_cast<int>(Configuration::cfg_CircleAlpha * 255));
    const float FOVRadius = Configuration::cfg_FOVRadius;

    // Draw FOV circle only if enabled
    if (Configuration::cfg_DrawFOVCircle) {
        drawList->AddCircle(ImVec2(FOVCenter.X, FOVCenter.Y), FOVRadius, CircleColor, 1200, 1.0f);
    }

    // Draw line to best target - always show this regardless of FOV circle visibility
    if (Overlay->BestTargetActor) {
        FVector2D TargetScreenPosition;
        if (PlayerController->ProjectWorldLocationToScreen(Overlay->BestTargetLocation, &TargetScreenPosition, true)) {
            float DistanceToCenter = CustomMath::Sqrt(
                CustomMath::Square(TargetScreenPosition.X - FOVCenter.X) +
                CustomMath::Square(TargetScreenPosition.Y - FOVCenter.Y)
            );

            if (DistanceToCenter <= FOVRadius) {
                // Use a simple golf ball target color
                ImU32 TargetColor = IM_COL32(0, 255, 0, 255); // Green for targeted golf ball

                drawList->AddLine(
                    ImVec2(FOVCenter.X, FOVCenter.Y),
                    ImVec2(TargetScreenPosition.X, TargetScreenPosition.Y),
                    TargetColor, Configuration::cfg_ESPThickness
                );
            }
        }
    }
}

void ESP::DrawGuiESP() {
    if (!Configuration::cfg_DrawGolfBallESP && !Configuration::cfg_ShowDebugClassNames)
        return;

    const auto DrawList = ImGui::GetBackgroundDrawList();
    if (!DrawList)
        return;

    if (!ImGui::GetCurrentContext())
        return;

    if (!OverlayBase::Instance->ESPFont)
        return;

    auto PlayerController = GetAPC();
    if (!PlayerController || !IsActorValid(PlayerController))
        return;

    auto PlayerPawn = PlayerController->K2_GetPawn();
    if (!PlayerPawn || !IsActorValid(PlayerPawn))
        return;
        
    // Get the local golf ball specifically for comparison
    auto LocalGolfBall = GetGolfBallC();

    TfdOverlay* Overlay = static_cast<TfdOverlay*>(OverlayBase::Instance);
    if (!Overlay)
        return;

    ImVec2 CanvasSize = ImGui::GetIO().DisplaySize;
    if (CanvasSize.x <= 0 || CanvasSize.y <= 0)
        return;

    auto IsValidScreenPosition = [&](ImVec2& Position) -> bool {
        return Position.x >= 0.0f && Position.y >= 0.0f && Position.x <= CanvasSize.x && Position.y <= CanvasSize.y;
    };

    FVector PlayerLocation = PlayerPawn->K2_GetActorLocation();
    
    // try-catch to prevent crashes
    try {
        // --- Golf Ball ESP ---
        if (Configuration::cfg_DrawGolfBallESP) {
            auto cachedGolfBalls = ActorCache::GetInstance().GetCachedGolfBalls();
            
            // Process golf ball actors
            for (const auto& actorInfo : cachedGolfBalls) {
                if (!actorInfo.Actor || !IsActorValid(actorInfo.Actor))
                    continue;
                    
                AGolfBall_C* GolfBall = static_cast<AGolfBall_C*>(actorInfo.Actor);
                if (!GolfBall || !IsActorValid(GolfBall))
                    continue;

                // Skip if it's the local player's golf ball
                if (GolfBall == LocalGolfBall || GolfBall == PlayerPawn)
                    continue;

                // Calculate distance
                FVector GolfBallLocation = GolfBall->K2_GetActorLocation();
                float Distance = GetDistance3D(GolfBallLocation, PlayerLocation) / 100.0f; // Convert to meters
                
                if (Distance > Configuration::cfg_MaxGolfBallESPDistance / 100.0f)
                    continue;

                // Get golf ball mesh component for bounding box
                UStaticMeshComponent* MeshComponent = GolfBall->GolfBall; // The actual golf ball mesh
                if (!MeshComponent || !MeshComponent->IsValidLowLevel())
                    continue;

                FVector Origin, BoxExtent;
                float SphereRadius;
                UKismetSystemLibrary::GetComponentBounds(MeshComponent, &Origin, &BoxExtent, &SphereRadius);

                // Golf balls are small, so we'll make the box a bit bigger for visibility
                BoxExtent.X = UKismetMathLibrary::Max(BoxExtent.X, 50.0f);
                BoxExtent.Y = UKismetMathLibrary::Max(BoxExtent.Y, 50.0f);
                BoxExtent.Z = UKismetMathLibrary::Max(BoxExtent.Z, 50.0f);

                FVector ActorTop = Origin;
                ActorTop.Z += BoxExtent.Z;
                FVector ActorBottom = Origin;
                ActorBottom.Z -= BoxExtent.Z;

                FVector2D ScreenPosTop, ScreenPosBottom;
                if (!PlayerController->ProjectWorldLocationToScreen(ActorTop, &ScreenPosTop, true) ||
                    !PlayerController->ProjectWorldLocationToScreen(ActorBottom, &ScreenPosBottom, true))
                    continue;

                float BoxHeight = ScreenPosBottom.Y - ScreenPosTop.Y;
                float BoxWidth = BoxHeight / 2.0f;

                if (BoxHeight <= 0 || BoxWidth <= 0)
                    continue;

                // Make sure box is at least a minimum size
                BoxWidth = UKismetMathLibrary::Max(BoxWidth, 20.0f);
                BoxHeight = UKismetMathLibrary::Max(BoxHeight, 30.0f);

                ImVec2 BoxTopLeft = { ScreenPosTop.X - BoxWidth / 2.0f, ScreenPosTop.Y };
                ImVec2 BoxBottomRight = { ScreenPosTop.X + BoxWidth / 2.0f, ScreenPosBottom.Y };

                if (!IsValidScreenPosition(BoxTopLeft) || !IsValidScreenPosition(BoxBottomRight))
                    continue;

                // Determine targeting status and color
                ImU32 BoxColor = (GolfBall == Overlay->BestTargetActor)
                    ? IM_COL32(0, 255, 0, 255)      // Green for targeted
                    : IM_COL32(255, 165, 0, 255);   // Orange for other golf balls

                // Draw box
                if (Configuration::cfg_DrawGolfBallBoxes) {
                    float boxThickness = Configuration::cfg_ESPThickness;

                    switch (Configuration::cfg_GolfBallBoxStyle) {
                    case 0: // Flat Box
                        FlatBox(BoxTopLeft, BoxBottomRight, BoxColor, DrawList, boxThickness);
                        break;
                    case 1: { // Cornered Box
                        float cornerSize = BoxWidth / 5.0f;
                        CorneredBox(BoxTopLeft, BoxBottomRight, BoxColor, DrawList, boxThickness, cornerSize);
                        break;
                    }
                    case 2: { // 3D Box
                        Box3D(PlayerController, Origin, BoxExtent, BoxColor, DrawList, boxThickness);
                        break;
                    }
                    default:
                        FlatBox(BoxTopLeft, BoxBottomRight, BoxColor, DrawList, boxThickness);
                        break;
                    }
                }

                // Draw golf ball player name with distance
                if (Configuration::cfg_DrawGolfBallNames) {
                    std::string DisplayName = actorInfo.DisplayName;
                    
                    // Add distance in brackets: "Player Name [50m]"
                    if (Configuration::cfg_DrawGolfBallDistance) {
                        DisplayName += " [" + std::to_string(static_cast<int>(Distance)) + "m]";
                    }

                    if (DrawList && OverlayBase::Instance->ESPFont) {
                        ImVec2 NameSize = ImGui::CalcTextSize(DisplayName.c_str(), nullptr, true);
                        ImVec2 NamePos = {
                            (BoxTopLeft.x + BoxBottomRight.x) / 2.0f - NameSize.x / 2.0f,
                            BoxBottomRight.y + 5.0f
                        };
                        drawTextOutlined(DrawList, NamePos, BoxColor, DisplayName.c_str(), OverlayBase::Instance->ESPFont);
                    }
                }
                // Only distance if name is disabled but distance is enabled
                else if (Configuration::cfg_DrawGolfBallDistance) {
                    char DistanceText[32];
                    snprintf(DistanceText, sizeof(DistanceText), "%.0fm", Distance);
                    
                    if (DrawList && OverlayBase::Instance->ESPFont) {
                        ImVec2 DistanceSize = ImGui::CalcTextSize(DistanceText, nullptr, true);
                        ImVec2 DistancePos = {
                            (BoxTopLeft.x + BoxBottomRight.x) / 2.0f - DistanceSize.x / 2.0f,
                            BoxBottomRight.y + 5.0f
                        };
                        drawTextOutlined(DrawList, DistancePos, BoxColor, DistanceText, OverlayBase::Instance->ESPFont);
                    }
                }

                // Draw lines
                if (Configuration::cfg_DrawGolfBallLines && DrawList) {
                    ImVec2 screenCenter = { CanvasSize.x / 2, Configuration::cfg_DrawGolfBallLinesTop ? 0 : CanvasSize.y };
                    ImVec2 lineEnd = Configuration::cfg_DrawGolfBallLinesTop
                        ? ImVec2(ScreenPosTop.X, ScreenPosTop.Y)
                        : ImVec2(ScreenPosBottom.X, ScreenPosBottom.Y);

                    DrawList->AddLine(screenCenter, lineEnd, BoxColor, Configuration::cfg_ESPThickness);
                }
            }
        }
        
        // --- Goal Flag ESP ---
        if (Configuration::cfg_DrawGoalFlagESP) {
            auto cachedGoalFlags = ActorCache::GetInstance().GetCachedGoalFlags();
            
            // Process goal flag actors
            for (const auto& actorInfo : cachedGoalFlags) {
                if (!actorInfo.Actor || !IsActorValid(actorInfo.Actor))
                    continue;
                    
                AGoalNumberRotation_C* GoalFlag = static_cast<AGoalNumberRotation_C*>(actorInfo.Actor);
                if (!GoalFlag || !IsActorValid(GoalFlag))
                    continue;

                // Calculate distance
                FVector GoalFlagLocation = GoalFlag->K2_GetActorLocation();
                float Distance = GetDistance3D(GoalFlagLocation, PlayerLocation) / 100.0f; // Convert to meters
                
                if (Distance > Configuration::cfg_MaxGoalFlagESPDistance / 100.0f)
                    continue;

                // Get goal flag bounds - use the DefaultSceneRoot component
                USceneComponent* RootComponent = GoalFlag->DefaultSceneRoot;
                if (!RootComponent || !RootComponent->IsValidLowLevel())
                    continue;

                FVector Origin, BoxExtent;
                float SphereRadius;
                UKismetSystemLibrary::GetComponentBounds(RootComponent, &Origin, &BoxExtent, &SphereRadius);

                // Goal flags might be small, so ensure minimum box size for visibility
                BoxExtent.X = UKismetMathLibrary::Max(BoxExtent.X, 100.0f);
                BoxExtent.Y = UKismetMathLibrary::Max(BoxExtent.Y, 100.0f);
                BoxExtent.Z = UKismetMathLibrary::Max(BoxExtent.Z, 150.0f);

                FVector ActorTop = Origin;
                ActorTop.Z += BoxExtent.Z;
                FVector ActorBottom = Origin;
                ActorBottom.Z -= BoxExtent.Z;

                FVector2D ScreenPosTop, ScreenPosBottom;
                if (!PlayerController->ProjectWorldLocationToScreen(ActorTop, &ScreenPosTop, true) ||
                    !PlayerController->ProjectWorldLocationToScreen(ActorBottom, &ScreenPosBottom, true))
                    continue;

                float BoxHeight = ScreenPosBottom.Y - ScreenPosTop.Y;
                float BoxWidth = BoxHeight / 2.0f;

                if (BoxHeight <= 0 || BoxWidth <= 0)
                    continue;

                // Make sure box is at least a minimum size
                BoxWidth = UKismetMathLibrary::Max(BoxWidth, 30.0f);
                BoxHeight = UKismetMathLibrary::Max(BoxHeight, 40.0f);

                ImVec2 BoxTopLeft = { ScreenPosTop.X - BoxWidth / 2.0f, ScreenPosTop.Y };
                ImVec2 BoxBottomRight = { ScreenPosTop.X + BoxWidth / 2.0f, ScreenPosBottom.Y };

                if (!IsValidScreenPosition(BoxTopLeft) || !IsValidScreenPosition(BoxBottomRight))
                    continue;

                // Use configured color for goal flags
                ImU32 BoxColor = Configuration::cfg_GoalFlagESPColor;

                // Draw box
                if (Configuration::cfg_DrawGoalFlagBoxes) {
                    float boxThickness = Configuration::cfg_ESPThickness;

                    switch (Configuration::cfg_GoalFlagBoxStyle) {
                    case 0: // Flat Box
                        FlatBox(BoxTopLeft, BoxBottomRight, BoxColor, DrawList, boxThickness);
                        break;
                    case 1: { // Cornered Box
                        float cornerSize = BoxWidth / 5.0f;
                        CorneredBox(BoxTopLeft, BoxBottomRight, BoxColor, DrawList, boxThickness, cornerSize);
                        break;
                    }
                    case 2: { // 3D Box
                        Box3D(PlayerController, Origin, BoxExtent, BoxColor, DrawList, boxThickness);
                        break;
                    }
                    default:
                        FlatBox(BoxTopLeft, BoxBottomRight, BoxColor, DrawList, boxThickness);
                        break;
                    }
                }

                // Draw goal flag name with distance
                if (Configuration::cfg_DrawGoalFlagNames) {
                    std::string DisplayName = actorInfo.DisplayName;
                    
                    // Add distance in brackets: "Goal Flag [50m]"
                    if (Configuration::cfg_DrawGoalFlagDistance) {
                        DisplayName += " [" + std::to_string(static_cast<int>(Distance)) + "m]";
                    }

                    if (DrawList && OverlayBase::Instance->ESPFont) {
                        ImVec2 NameSize = ImGui::CalcTextSize(DisplayName.c_str(), nullptr, true);
                        ImVec2 NamePos = {
                            (BoxTopLeft.x + BoxBottomRight.x) / 2.0f - NameSize.x / 2.0f,
                            BoxBottomRight.y + 5.0f
                        };
                        drawTextOutlined(DrawList, NamePos, BoxColor, DisplayName.c_str(), OverlayBase::Instance->ESPFont);
                    }
                }
                // Only distance if name is disabled but distance is enabled
                else if (Configuration::cfg_DrawGoalFlagDistance) {
                    char DistanceText[32];
                    snprintf(DistanceText, sizeof(DistanceText), "%.0fm", Distance);
                    
                    if (DrawList && OverlayBase::Instance->ESPFont) {
                        ImVec2 DistanceSize = ImGui::CalcTextSize(DistanceText, nullptr, true);
                        ImVec2 DistancePos = {
                            (BoxTopLeft.x + BoxBottomRight.x) / 2.0f - DistanceSize.x / 2.0f,
                            BoxBottomRight.y + 5.0f
                        };
                        drawTextOutlined(DrawList, DistancePos, BoxColor, DistanceText, OverlayBase::Instance->ESPFont);
                    }
                }

                // Draw lines
                if (Configuration::cfg_DrawGoalFlagLines && DrawList) {
                    ImVec2 screenCenter = { CanvasSize.x / 2, Configuration::cfg_DrawGoalFlagLinesTop ? 0 : CanvasSize.y };
                    ImVec2 lineEnd = Configuration::cfg_DrawGoalFlagLinesTop
                        ? ImVec2(ScreenPosTop.X, ScreenPosTop.Y)
                        : ImVec2(ScreenPosBottom.X, ScreenPosBottom.Y);

                    DrawList->AddLine(screenCenter, lineEnd, BoxColor, Configuration::cfg_ESPThickness);
                }
            }
        }
        
        // --- DEBUG CLASS NAMES ---
        if (Configuration::cfg_ShowDebugClassNames) {
            // Get all levels to iterate through all actors
            UWorld* GWorld = GetWorld();
            if (GWorld && GWorld->Levels.IsValid()) {
                for (int i = 0; i < GWorld->Levels.Num(); ++i) {
                    if (!GWorld->Levels.IsValidIndex(i))
                        continue;

                    const auto Level = GWorld->Levels[i];
                    if (!Level)
                        continue;

                    // Loop through all actors in the level
                    for (int j = 0; j < Level->Actors.Num(); ++j) {
                        const auto Actor = Level->Actors[j];
                        if (!Actor || !IsActorValid(Actor))
                            continue;
                            
                        // Skip the player's own character
                        if (Actor == PlayerPawn)
                            continue;
                            
                        // Calculate distance
                        FVector ActorLocation = Actor->K2_GetActorLocation();
                        float Distance = GetDistance3D(ActorLocation, PlayerLocation) / 100.0f; // Convert to meters
                        
                        if (Distance > Configuration::cfg_DebugMaxDistance / 100.0f)
                            continue;

                        FVector2D ScreenPos;
                        if (!PlayerController->ProjectWorldLocationToScreen(ActorLocation, &ScreenPos, true))
                            continue;

                        // Get class name
                        std::string className = Actor->Class ? Actor->Class->GetName() : "Unknown";
                        
                        // Prepare display text
                        std::string displayText = className;
                        if (Configuration::cfg_ShowDebugDistance) {
                            displayText += " [" + std::to_string(static_cast<int>(Distance)) + "m]";
                        }
                        
                        // Use different color for debug text
                        ImU32 debugColor = IM_COL32(255, 255, 0, 180); // Yellow with some transparency
                        
                        // Draw debug class name
                        if (DrawList && OverlayBase::Instance->ESPFont) {
                            ImVec2 NameSize = ImGui::CalcTextSize(displayText.c_str(), nullptr, true);
                            ImVec2 NamePos = {
                                ScreenPos.X - NameSize.x / 2.0f,
                                ScreenPos.Y + 10.0f // Offset below normal ESP text
                            };

                            if (NamePos.x >= 0 && NamePos.y >= 0 && 
                                NamePos.x < CanvasSize.x && NamePos.y < CanvasSize.y) {
                                drawTextOutlined(DrawList, NamePos, debugColor, displayText.c_str(), OverlayBase::Instance->ESPFont);
                            }
                        }
                    }
                }
            }
        }
    }
    catch (...) {
        // Ignore any exceptions to prevent crashes
    }
}

bool ESP::IsValidScreenPosition(const ImVec2& position, const ImVec2& canvasSize) {
    return position.x >= 0.0f && position.y >= 0.0f && position.x <= canvasSize.x && position.y <= canvasSize.y;
}

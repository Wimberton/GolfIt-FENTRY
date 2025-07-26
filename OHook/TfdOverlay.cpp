#include "TfdOverlay.h"
#include "DetourManager.h"
#include <SDK/GolfIt_parameters.hpp>

#include "../console/console.hpp"
#include "ImGuiExt.h"
#include "SDKExt.h"
#include "Utils.h"
#include "Configuration.h"
#include "ActorCache.h"
#include "Overlays/ESP.h"
#include "Features/PlayerFeatures.h"

#include <Windows.h>
#include <algorithm>
#include <thread>
#include <fstream>
#include <TlHelp32.h>
#include <imgui_internal.h>
#include <Fonts.h>
#include <unordered_set>

using namespace SDK;

std::vector<std::string> debugger;
DetourManager gDetourManager;

// aim globals
bool waitingForKey = false;
bool waitingForTeleportKey = false;
bool waitingForSpeedKey = false;
bool waitingForNoClipKey = false;
bool waitingForVacuumKey = false;
bool waitingForTPTargetKey = false;
bool waitingForDropInventoryKey = false;
bool waitingForConsoleKey = false;

// helper funcs
const char* GetKeyName(int key) {
    if (key == 0) {
        return "No key set";
    }

    switch (key) {
    case VK_LBUTTON: return "Left Mouse Button";
    case VK_RBUTTON: return "Right Mouse Button";
    case VK_MBUTTON: return "Middle Mouse Button";
    case VK_XBUTTON1: return "Side Mouse Button 1";
    case VK_XBUTTON2: return "Side Mouse Button 2";

    default: {
        static char keyName[64] = {};
        if (GetKeyNameTextA(MapVirtualKeyA(key, MAPVK_VK_TO_VSC) << 16, keyName, 64) > 0) {
            return keyName;
        }
        return "Unknown Key";
        }
    }
}
void HandleKeySetting(int& keyToSet, bool& waitingForKey) {
    if (waitingForKey) {
        for (int key = 0x01; key <= 0xFE; key++) {
            if (GetAsyncKeyState(key) & 0x8000) {
                if (key == VK_ESCAPE) {
                    keyToSet = 0; // Set to 0 when ESC is pressed
                    Configuration::Save();
                    waitingForKey = false;
                }
                else {
                    keyToSet = key;
                    Configuration::Save();
                    waitingForKey = false;
                }
                break;
            }
        }
    }
}

// ======== DRAWING STUFF ======== //

void TfdOverlay::DrawGuiFOVCircle() {
    ESP::DrawGuiFOVCircle();
}

void TfdOverlay::DrawGuiESP() {
    ESP::DrawGuiESP();
}

void TfdOverlay::DrawHUD() {
    // load config
    static bool bConfigLoaded = false;
    if (!bConfigLoaded) {
        Configuration::Load(static_cast<TfdOverlay*>(OverlayBase::Instance));
        bConfigLoaded = true;
    }

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui::SetNextWindowBgAlpha(0.50f);
    ImGuiStyle& style = ImGui::GetStyle();
    float prevRounding = style.WindowRounding;
    style.WindowRounding = 5.0f;

    // Watermark
    if (Configuration::bShowWatermark) {
        const char* watermarkText = "GolfIt Cheat";
        float textW = ImGui::CalcTextSize(watermarkText).x;
        ImGui::SetNextWindowPos({ (io.DisplaySize.x - textW) * 0.5f, 10.0f });
        ImGui::Begin("Watermark", nullptr,
            ImGuiWindowFlags_NoDecoration |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_AlwaysAutoResize |
            ImGuiWindowFlags_NoSavedSettings |
            ImGuiWindowFlags_NoFocusOnAppearing |
            ImGuiWindowFlags_NoNav);
        ImGui::Text("%s", watermarkText);
        ImGui::End();
    }
    
    // Mission Info Window
    // MissionControl::DrawMissionInfoWindow();
    
    style.WindowRounding = prevRounding;

    APlayerController* PlayerController = GetAPC();
    AGolfItLobbyPlayerController* GolfItLobbyPC = GetGolfItLobbyPC();

    // Static caches
    static APlayerController* s_HookedPC = nullptr;
    static AGolfItLobbyPlayerState* s_HookedPS = nullptr;
    static AGolfBall_C* s_HookedGolfBall = nullptr;
    static UCharacterMovementComponent* s_HookedMovement = nullptr;
    static ACharacter* s_HookedCharacter = nullptr;
    static AHUD* s_HookedHUD = nullptr;

    if (PlayerController && PlayerController != nullptr) {
        // PlayerController
        if (PlayerController != s_HookedPC) {
            gDetourManager.SetupDetour(PlayerController);
            s_HookedPC = PlayerController;
        }

        // Golf Ball (Character replacement)
        AGolfBall_C* GolfBall = GetGolfBallC();
        if (GolfBall && GolfBall != nullptr && GolfBall != s_HookedGolfBall) {
            gDetourManager.SetupDetour(GolfBall);
            s_HookedGolfBall = GolfBall;
        }
    }

    // Hook HUD once
    if (PlayerController && PlayerController->MyHUD && PlayerController->MyHUD != s_HookedHUD) {
        gDetourManager.SetupDetour(PlayerController->MyHUD);
        s_HookedHUD = PlayerController->MyHUD;
    }
}

void TfdOverlay::DrawOverlay() {
    bool show = true;
    const ImGuiIO& io = ImGui::GetIO();
    constexpr ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoCollapse;

    const auto center_pos = ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f);
    const auto window_size = ImVec2(Configuration::windowSizeX, Configuration::windowSizeY);
    const auto window_pos = ImVec2(center_pos.x - window_size.x * 0.5f, center_pos.y - window_size.y * 0.5f);

    ImGui::SetNextWindowPos(window_pos, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(window_size, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowBgAlpha(0.98f);

    const auto WindowTitle = std::string("GolfIt Cheat");
    TfdOverlay* Overlay = static_cast<TfdOverlay*>(OverlayBase::Instance);

    if (ImGui::Begin(WindowTitle.data(), &show, window_flags)) {
        static int OpenTab = 0;

        if (ImGui::IsMouseDragging(0) &&
            (Configuration::windowSizeX != ImGui::GetWindowSize().x || Configuration::windowSizeY != ImGui::GetWindowSize().y)) {
            Configuration::windowSizeX = static_cast<float>(ImGui::GetWindowSize().x);
            Configuration::windowSizeY = static_cast<float>(ImGui::GetWindowSize().y);
            Configuration::Save();
        }

        if (ImGui::BeginTabBar("OverlayTabs")) {
            if (ImGui::BeginTabItem(ICON_FA_EYE " Visuals")) {
                OpenTab = 0;
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem(ICON_FA_PERSON " Player Mods")) {
                OpenTab = 1;
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }

        // =========================== VISUALS TAB
        if (OpenTab == 0) {
            ImGui::Columns(2, nullptr, false);
            float tempMonsterColor[4];
            float tempPlayerColor[4];
            float tempItemColor[4];

            if (ImGui::CollapsingHeader("General Visual Settings##GeneralVisualSettingsHeader", ImGuiTreeNodeFlags_DefaultOpen)) {
                if (ImGui::Checkbox("Show Watermark", &Configuration::bShowWatermark)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Display the watermark at the top of the screen");
                
                if (ImGui::Checkbox("Enable Unlit Mode", &Configuration::cfg_EnableUnlitMode)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Remove lighting effects for better visibility through walls and objects");

                if (ImGui::Checkbox("Visibility Check", &Configuration::cfg_AimVisCheck)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Only show ESP/aim at targets that are visible (not behind walls)");
                
                if (ImGui::Checkbox("Show FOV Circle", &Configuration::cfg_DrawFOVCircle)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Display a circle showing your aimbot field of view radius");
                
                ImGui::SetNextItemWidth(200.0f);
                if (ImGui::SliderFloat("FOV Radius", &Configuration::cfg_FOVRadius, 3.0f, 280.0f, "%1.0f")) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Modify the circle radius in which the aimbot will lock");
                    
                ImGui::SetNextItemWidth(200.0f);
                if (ImGui::SliderFloat("Change FOV Opacity", &Configuration::cfg_CircleAlpha, 0.1f, 1.0f)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Adjust the transparency of the FOV circle");
            }

            ImGui::NextColumn();
            
            if (ImGui::CollapsingHeader("Debug ESP Options##DebugESPSettingsHeader")) {
                if (ImGui::Checkbox("Show Class Names", &Configuration::cfg_ShowDebugClassNames)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Display the actual class names of all objects for debugging");
                
                if (ImGui::Checkbox("Show Debug Distance", &Configuration::cfg_ShowDebugDistance)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Display distance in the debug class name display");
                
                float debugDistanceInMeters = Configuration::cfg_DebugMaxDistance / 100.0f;
                ImGui::SetNextItemWidth(200.0f);
                if (ImGui::SliderFloat("Debug Max Distance", &debugDistanceInMeters, 10.0f, 500.0f)) {
                    Configuration::cfg_DebugMaxDistance = debugDistanceInMeters * 100.0f;
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Maximum distance to show debug class names (in meters)");
            }

            if (ImGui::CollapsingHeader("Golf Ball ESP Settings##GolfBallESPSettingsHeader")) {
                if (ImGui::Checkbox("Enable Golf Ball ESP", &Configuration::cfg_DrawGolfBallESP)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Show ESP for other players' golf balls");

                if (ImGui::Checkbox("Show Golf Ball Boxes", &Configuration::cfg_DrawGolfBallBoxes)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Draw 3D boxes around golf balls");

                const char* golfBallBoxStyles[] = { "Flat Box", "Cornered Box", "3D Box" };
                static int selectedGolfBallBoxStyle = Configuration::cfg_GolfBallBoxStyle;
                ImGui::SetNextItemWidth(200.0f);
                if (ImGui::Combo("Golf Ball Box Style", &selectedGolfBallBoxStyle, golfBallBoxStyles, IM_ARRAYSIZE(golfBallBoxStyles))) {
                    Configuration::cfg_GolfBallBoxStyle = selectedGolfBallBoxStyle;
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Choose the visual style for golf ball ESP boxes");

                if (ImGui::Checkbox("Show Golf Ball Names", &Configuration::cfg_DrawGolfBallNames)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Display player names above their golf balls");

                if (ImGui::Checkbox("Show Golf Ball Distance", &Configuration::cfg_DrawGolfBallDistance)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Display distance to golf balls");

                if (ImGui::Checkbox("Show Golf Ball Lines", &Configuration::cfg_DrawGolfBallLines)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Draw lines from screen center to golf balls");

                if (ImGui::Checkbox("Show Top Golf Ball Lines", &Configuration::cfg_DrawGolfBallLinesTop)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Draw lines from top of screen to golf balls");

                float golfBallDistanceInMeters = Configuration::cfg_MaxGolfBallESPDistance / 100.0f;
                ImGui::SetNextItemWidth(200.0f);
                if (ImGui::SliderFloat("Max Golf Ball ESP Distance", &golfBallDistanceInMeters, 10.0f, 1000.0f)) {
                    Configuration::cfg_MaxGolfBallESPDistance = golfBallDistanceInMeters * 100.0f;
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Maximum distance to show golf ball ESP (in meters)");

                ImGui::SetNextItemWidth(200.0f);
                if (ImGui::SliderFloat("ESP Line Thickness", &Configuration::cfg_ESPThickness, 0.5f, 5.0f)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Thickness of ESP lines and boxes");

                ImGui::Text("Golf Ball ESP Colors:");

                float tempGolfBallColor[4];

                // Convert and edit Golf Ball ESP Color
                ImU32ToFloat4(Configuration::cfg_GolfBallESPColor, tempGolfBallColor);
                if (ImGui::ColorEdit4("Normal Golf Ball Color", tempGolfBallColor)) {
                    Configuration::cfg_GolfBallESPColor = Float4ToImU32(tempGolfBallColor);
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Color for other players' golf balls");

                // Convert and edit Golf Ball Target ESP Color
                ImU32ToFloat4(Configuration::cfg_GolfBallESPColorTarget, tempGolfBallColor);
                if (ImGui::ColorEdit4("Targeted Golf Ball Color", tempGolfBallColor)) {
                    Configuration::cfg_GolfBallESPColorTarget = Float4ToImU32(tempGolfBallColor);
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Color for golf balls when they are being targeted");
            }

            if (ImGui::CollapsingHeader("Goal Flag ESP Settings##GoalFlagESPSettingsHeader")) {
                if (ImGui::Checkbox("Enable Goal Flag ESP", &Configuration::cfg_DrawGoalFlagESP)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Show ESP for goal flags/holes");

                if (ImGui::Checkbox("Show Goal Flag Boxes", &Configuration::cfg_DrawGoalFlagBoxes)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Draw 3D boxes around goal flags");

                const char* goalFlagBoxStyles[] = { "Flat Box", "Cornered Box", "3D Box" };
                static int selectedGoalFlagBoxStyle = Configuration::cfg_GoalFlagBoxStyle;
                ImGui::SetNextItemWidth(200.0f);
                if (ImGui::Combo("Goal Flag Box Style", &selectedGoalFlagBoxStyle, goalFlagBoxStyles, IM_ARRAYSIZE(goalFlagBoxStyles))) {
                    Configuration::cfg_GoalFlagBoxStyle = selectedGoalFlagBoxStyle;
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Choose the visual style for goal flag ESP boxes");

                if (ImGui::Checkbox("Show Goal Flag Names", &Configuration::cfg_DrawGoalFlagNames)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Display names above goal flags");

                if (ImGui::Checkbox("Show Goal Flag Distance", &Configuration::cfg_DrawGoalFlagDistance)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Display distance to goal flags");

                if (ImGui::Checkbox("Show Goal Flag Lines", &Configuration::cfg_DrawGoalFlagLines)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Draw lines from screen center to goal flags");

                if (ImGui::Checkbox("Show Top Goal Flag Lines", &Configuration::cfg_DrawGoalFlagLinesTop)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Draw lines from top of screen to goal flags");

                float goalFlagDistanceInMeters = Configuration::cfg_MaxGoalFlagESPDistance / 100.0f;
                ImGui::SetNextItemWidth(200.0f);
                if (ImGui::SliderFloat("Max Goal Flag ESP Distance", &goalFlagDistanceInMeters, 10.0f, 2000.0f)) {
                    Configuration::cfg_MaxGoalFlagESPDistance = goalFlagDistanceInMeters * 100.0f;
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Maximum distance to show goal flag ESP (in meters)");

                ImGui::Text("Goal Flag ESP Color:");

                float tempGoalFlagColor[4];

                // Convert and edit Goal Flag ESP Color
                ImU32ToFloat4(Configuration::cfg_GoalFlagESPColor, tempGoalFlagColor);
                if (ImGui::ColorEdit4("Goal Flag Color", tempGoalFlagColor)) {
                    Configuration::cfg_GoalFlagESPColor = Float4ToImU32(tempGoalFlagColor);
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Color for goal flag ESP");
            }
        }
        // =========================== PLAYER MODS TAB
        else if (OpenTab == 1) {
            ImGui::Columns(2, nullptr, false);
            if (ImGui::CollapsingHeader("Player Movement##PlayerMovementHeader", ImGuiTreeNodeFlags_DefaultOpen)) {
                if (ImGui::Checkbox("Enable NoClip", &Configuration::cfg_EnableNoClip)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Walk through walls and objects");

                // if (ImGui::Checkbox("Enable Speedhack", &Configuration::cfg_EnableSpeedhack)) {
                //     Configuration::Save();
                // }
                // if (ImGui::IsItemHovered())
                //     ImGui::SetTooltip("Increase movement speed multiplier");

                // ImGui::SetNextItemWidth(200.0f);
                // if (ImGui::SliderFloat("Speed Multiplier", &Configuration::cfg_speedPlayerValue, 0.5f, 10.0f)) {
                //     Configuration::Save();
                // }
                // if (ImGui::IsItemHovered())
                //     ImGui::SetTooltip("Speed multiplier when speedhack is enabled");
                
                // if (ImGui::Checkbox("Enable Multi Jump", &Configuration::cfg_EnableMultiJump)) {
                //     Configuration::Save();
                // }
                // if (ImGui::IsItemHovered())
                //     ImGui::SetTooltip("Allow golf ball to jump multiple times in air");
                
                // ImGui::SetNextItemWidth(200.0f);
                // if (ImGui::SliderInt("Multi Jump Amount", &Configuration::cfg_MultiJumpAmount, 1, 20)) {
                //     Configuration::Save();
                // }
                // if (ImGui::IsItemHovered())
                //     ImGui::SetTooltip("Number of times the golf ball can jump in air");
                
                if (ImGui::Checkbox("Enable Teleport to Goal", &Configuration::cfg_EnableTeleportToGoal)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Teleport golf ball to the goal flag with hotkey");
                
                if (ImGui::Checkbox("Teleport ALL Players", &Configuration::cfg_TeleportAllPlayers)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Teleport ALL golf balls to the goal (chaos mode! 😂)");
                
                if (ImGui::Checkbox("Enable Teleport to Target", &Configuration::cfg_EnableTPTarget)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Teleport to targeted objects (golf balls, goal flags)");
                
                if (ImGui::Checkbox("Smaller TP Targeting", &Configuration::cfg_SmallerTPTargeting)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Use a smaller FOV radius for teleport targeting");
                
                ImGui::SetNextItemWidth(200.0f);
                if (ImGui::SliderFloat("TP FOV Radius", &Configuration::cfg_TPFOVRadius, 50.0f, 400.0f)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("FOV radius for teleport targeting (pixels)");
                
                ImGui::SetNextItemWidth(200.0f);
                if (ImGui::SliderFloat("Actor Teleport Offset", &Configuration::cfg_ActorTeleportOffset, 0.0f, 500.0f)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Distance offset from target to avoid clipping (units)");
                
                ImGui::SetNextItemWidth(200.0f);
                if (ImGui::SliderFloat("No Target Distance", &Configuration::cfg_TPNoTargetDistance, 500.0f, 5000.0f)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Forward teleport distance when no target is selected (units)");
            }

            if (ImGui::CollapsingHeader("Aimbot Settings##AimbotHeader")) {
                ImGui::SetNextItemWidth(200.0f);
                if (ImGui::SliderFloat("Aimbot Smoothing", &Configuration::cfg_AimbotSmoothing, 1.0f, 100.0f)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Smoothing factor for aimbot movement (higher = smoother)");
            }

            if (ImGui::CollapsingHeader("Console##ConsoleHeader")) {
                if (ImGui::Checkbox("Enable Console", &Configuration::cfg_EnableConsole)) {
                    Configuration::Save();
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Enable console access with hotkey");
            }

            ImGui::NextColumn();

            if (ImGui::CollapsingHeader("Movement HotKeys##MovementHotKeysHeader", ImGuiTreeNodeFlags_DefaultOpen)) {                
                // Speedhack Key
                ImGui::Text("Speedhack Key: %s", GetKeyName(Configuration::cfg_SpeedKey));
                ImGui::SameLine();
                if (ImGui::Button("Set##SpeedKey")) {
                    waitingForSpeedKey = true;
                }
                if (waitingForSpeedKey) {
                    ImGui::SameLine();
                    ImGui::Text("Press any key... (ESC to clear)");
                }
                HandleKeySetting(Configuration::cfg_SpeedKey, waitingForSpeedKey);

                // NoClip Key
                ImGui::Text("NoClip Key: %s", GetKeyName(Configuration::cfg_NoClipKey));
                ImGui::SameLine();
                if (ImGui::Button("Set##NoClipKey")) {
                    waitingForNoClipKey = true;
                }
                if (waitingForNoClipKey) {
                    ImGui::SameLine();
                    ImGui::Text("Press any key... (ESC to clear)");
                }
                HandleKeySetting(Configuration::cfg_NoClipKey, waitingForNoClipKey);

                // Aimbot Key
                ImGui::Text("Aimbot Key: %s", GetKeyName(Configuration::cfg_AimbotKey));
                ImGui::SameLine();
                if (ImGui::Button("Set##AimbotKey")) {
                    waitingForKey = true;
                }
                if (waitingForKey) {
                    ImGui::SameLine();
                    ImGui::Text("Press any key... (ESC to clear)");
                }
                HandleKeySetting(Configuration::cfg_AimbotKey, waitingForKey);

                // Console Key
                ImGui::Text("Console Key: %s", GetKeyName(Configuration::cfg_ConsoleKey));
                ImGui::SameLine();
                if (ImGui::Button("Set##ConsoleKey")) {
                    waitingForConsoleKey = true;
                }
                if (waitingForConsoleKey) {
                    ImGui::SameLine();
                    ImGui::Text("Press any key... (ESC to clear)");
                }
                HandleKeySetting(Configuration::cfg_ConsoleKey, waitingForConsoleKey);

                // Teleport to Goal Key
                ImGui::Text("Teleport to Goal Key: %s", GetKeyName(Configuration::cfg_TeleportToGoalKey));
                ImGui::SameLine();
                if (ImGui::Button("Set##TeleportToGoalKey")) {
                    waitingForTeleportKey = true;
                }
                if (waitingForTeleportKey) {
                    ImGui::SameLine();
                    ImGui::Text("Press any key... (ESC to clear)");
                }
                HandleKeySetting(Configuration::cfg_TeleportToGoalKey, waitingForTeleportKey);

                // Teleport to Target Key
                static bool waitingForTPTargetKey = false;
                ImGui::Text("Teleport to Target Key: %s", GetKeyName(Configuration::cfg_TPTargetKey));
                ImGui::SameLine();
                if (ImGui::Button("Set##TPTargetKey")) {
                    waitingForTPTargetKey = true;
                }
                if (waitingForTPTargetKey) {
                    ImGui::SameLine();
                    ImGui::Text("Press any key... (ESC to clear)");
                }
                HandleKeySetting(Configuration::cfg_TPTargetKey, waitingForTPTargetKey);
            }

            // Player Control Section
            if (ImGui::CollapsingHeader("Player Control##PlayerControlHeader")) {
                // Get golf ball players for the listbox
                static int selectedPlayerIndex = -1;
                static std::vector<std::string> playerNames;
                static std::vector<AGolfBall_C*> playerGolfBalls;
                
                // Update player list every frame
                playerNames.clear();
                playerGolfBalls.clear();
                
                auto cachedGolfBalls = ActorCache::GetInstance().GetCachedGolfBalls();
                for (const auto& ballInfo : cachedGolfBalls) {
                    if (!ballInfo.Actor || !IsActorValid(ballInfo.Actor))
                        continue;
                        
                    AGolfBall_C* golfBall = static_cast<AGolfBall_C*>(ballInfo.Actor);
                    if (!golfBall || !IsActorValid(golfBall))
                        continue;
                    
                    // Skip our own golf ball
                    auto LocalGolfBall = GetGolfBallC();
                    if (golfBall == LocalGolfBall)
                        continue;
                    
                    playerNames.push_back(ballInfo.DisplayName);
                    playerGolfBalls.push_back(golfBall);
                }
                
                // Validate selected index
                if (selectedPlayerIndex >= static_cast<int>(playerNames.size())) {
                    selectedPlayerIndex = -1;
                }
                
                ImGui::Text("Lobby Players:");
                
                // Player listbox
                ImGui::SetNextItemWidth(300.0f);
                if (ImGui::ListBox("##PlayerList", &selectedPlayerIndex, 
                    [](void* data, int idx, const char** out_text) -> bool {
                        auto* names = static_cast<std::vector<std::string>*>(data);
                        if (idx < 0 || idx >= static_cast<int>(names->size())) return false;
                        *out_text = (*names)[idx].c_str();
                        return true;
                    }, &playerNames, static_cast<int>(playerNames.size()), 6)) {
                    // Selection changed
                }
                
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Select a player to perform actions on");
                
                ImGui::Spacing();
                
                // Action buttons
                bool hasSelectedPlayer = selectedPlayerIndex >= 0 && selectedPlayerIndex < static_cast<int>(playerGolfBalls.size());
                
                if (!hasSelectedPlayer) {
                    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.5f);
                }
                
                // Teleport actions
                ImGui::Text("Teleport Actions:");
                
                if (ImGui::Button("Teleport Player to Goal", ImVec2(200, 0))) {
                    if (hasSelectedPlayer) {
                        PlayerFeatures::TeleportPlayerToGoal(playerGolfBalls[selectedPlayerIndex]);
                    }
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Teleport the selected player to the nearest goal flag");
                
                ImGui::SameLine();
                if (ImGui::Button("Teleport Player to Me", ImVec2(200, 0))) {
                    if (hasSelectedPlayer) {
                        PlayerFeatures::TeleportPlayerToMe(playerGolfBalls[selectedPlayerIndex]);
                    }
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Teleport the selected player to your location");
                
                if (ImGui::Button("Teleport Me to Player", ImVec2(200, 0))) {
                    if (hasSelectedPlayer) {
                        PlayerFeatures::TeleportMeToPlayer(playerGolfBalls[selectedPlayerIndex]);
                    }
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Teleport yourself to the selected player's location");
                
                ImGui::Spacing();
                
                // Player modification actions
                ImGui::Text("Player Modifications:");
                
                if (ImGui::Button("Freeze Player", ImVec2(150, 0))) {
                    if (hasSelectedPlayer) {
                        PlayerFeatures::FreezePlayer(playerGolfBalls[selectedPlayerIndex]);
                    }
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Freeze the selected player's golf ball");
                
                ImGui::SameLine();
                if (ImGui::Button("Unfreeze Player", ImVec2(150, 0))) {
                    if (hasSelectedPlayer) {
                        PlayerFeatures::UnfreezePlayer(playerGolfBalls[selectedPlayerIndex]);
                    }
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Unfreeze the selected player's golf ball");
                
                ImGui::SameLine();
                if (ImGui::Button("Launch Player", ImVec2(150, 0))) {
                    if (hasSelectedPlayer) {
                        PlayerFeatures::LaunchPlayer(playerGolfBalls[selectedPlayerIndex]);
                    }
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Launch the selected player's golf ball into the air");
                
                if (ImGui::Button("Speed Up Player", ImVec2(150, 0))) {
                    if (hasSelectedPlayer) {
                        PlayerFeatures::SpeedUpPlayer(playerGolfBalls[selectedPlayerIndex]);
                    }
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Increase the selected player's movement speed");
                
                ImGui::SameLine();
                if (ImGui::Button("Slow Down Player", ImVec2(150, 0))) {
                    if (hasSelectedPlayer) {
                        PlayerFeatures::SlowDownPlayer(playerGolfBalls[selectedPlayerIndex]);
                    }
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Decrease the selected player's movement speed");
                
                ImGui::SameLine();
                if (ImGui::Button("Reset Player", ImVec2(150, 0))) {
                    if (hasSelectedPlayer) {
                        PlayerFeatures::ResetPlayer(playerGolfBalls[selectedPlayerIndex]);
                    }
                }
                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Reset the selected player's golf ball to normal state");
                
                if (!hasSelectedPlayer) {
                    ImGui::PopStyleVar();
                }
                
                ImGui::Spacing();
                
                // Info about selected player
                if (hasSelectedPlayer && selectedPlayerIndex < static_cast<int>(playerNames.size())) {
                    ImGui::Text("Selected Player: %s", playerNames[selectedPlayerIndex].c_str());
                    
                    // Show some info about the selected player
                    AGolfBall_C* selectedBall = playerGolfBalls[selectedPlayerIndex];
                    if (selectedBall && IsActorValid(selectedBall)) {
                        FVector playerLocation = selectedBall->K2_GetActorLocation();
                        ImGui::Text("Location: (%.1f, %.1f, %.1f)", playerLocation.X, playerLocation.Y, playerLocation.Z);
                        
                        auto LocalGolfBall = GetGolfBallC();
                        if (LocalGolfBall && IsActorValid(LocalGolfBall)) {
                            FVector localLocation = LocalGolfBall->K2_GetActorLocation();
                            float distance = GetDistance3D(playerLocation, localLocation) / 100.0f; // Convert to meters
                            ImGui::Text("Distance: %.1fm", distance);
                        }
                    }
                } else if (playerNames.empty()) {
                    ImGui::Text("No other players found in lobby");
                } else {
                    ImGui::Text("Select a player from the list above");
                }
            }
        }
    }

    ImGui::End();

    if (!show)
        ShowOverlay(false);
}
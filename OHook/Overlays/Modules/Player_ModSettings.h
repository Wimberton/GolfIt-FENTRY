#pragma once

#include "Configuration.h"
#include "Utils.h"
#include "GolfOverlay.h"
#include <imgui.h>
#include <imgui_internal.h>

namespace Player_ModSettings {
    inline void Show() {
        ImGui::Columns(2, nullptr, false);
        if (ImGui::CollapsingHeader("Player Movement##PlayerMovementHeader", ImGuiTreeNodeFlags_DefaultOpen)) {
            if (ImGui::Checkbox("Enable NoClip", &Configuration::cfg_EnableNoClip)) {
                Configuration::Save();
            }
            if (ImGui::IsItemHovered())
                ImGui::SetTooltip("Walk through walls and objects");

            if (ImGui::Checkbox("Enable Teleport to Goal", &Configuration::cfg_EnableTeleportToGoal)) {
                Configuration::Save();
            }
            if (ImGui::IsItemHovered())
                ImGui::SetTooltip("Teleport golf ball to the goal flag with hotkey");

            if (ImGui::Checkbox("Teleport ALL Players", &Configuration::cfg_TeleportAllPlayers)) {
                Configuration::Save();
            }
            if (ImGui::IsItemHovered())
                ImGui::SetTooltip("Teleport ALL golf balls to the goal");

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

        ImGui::NextColumn();

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
            }
            else if (playerNames.empty()) {
                ImGui::Text("No other players found in lobby");
            }
            else {
                ImGui::Text("Select a player from the list above");
            }
        }
    }
}
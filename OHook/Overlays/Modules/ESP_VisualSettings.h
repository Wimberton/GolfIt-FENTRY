#pragma once

#include "Configuration.h"
#include "Utils.h"
#include "GolfOverlay.h"
#include <imgui.h>
#include <imgui_internal.h>

namespace ESP_VisualSettings {
    inline void Show() {
        ImGui::Columns(2, nullptr, false);

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

            ImGui::SetNextItemWidth(200.0f);
            if (ImGui::Combo("Golf Ball Box Style", &selectedGolfBallBoxStyle, golfBallBoxStyles, GOLFBALL_BOX_STYLES_COUNT)) {
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

            ImGui::SetNextItemWidth(200.0f);
            if (ImGui::Combo("Goal Flag Box Style", &selectedGoalFlagBoxStyle, goalFlagBoxStyles, FLAG_BOX_STYLES_COUNT)) {
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
}
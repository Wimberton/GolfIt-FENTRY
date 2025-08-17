#pragma once

#include "Configuration.h"
#include "Utils.h"
#include "GolfOverlay.h"
#include <imgui.h>
#include <imgui_internal.h>

namespace Fentry_Settings {
    inline void Show() {

        ImGui::Columns(2, nullptr, false);

        if (ImGui::CollapsingHeader("UI Settings##FentrySettingsHeader", ImGuiTreeNodeFlags_DefaultOpen)) {
            ImGui::SetNextItemWidth(200.0f);
            if (ImGui::Combo("##ThemesCombo", &Configuration::selectedTheme, GolfOverlay::themes, IM_ARRAYSIZE(GolfOverlay::themes))) {
                switch (Configuration::selectedTheme) {
                case 0: // Origin
                    ImGui::StyleColorsDark();
                    Configuration::Save();
                    break;
                case 1: // Spectrum Light
                    ImGui::Spectrum::StyleColorsSpectrum();
                    Configuration::Save();
                    break;
                case 2: // Magma
                    ImGui::Magma::StyleColorsMagma();
                    Configuration::Save();
                    break;
                case 3: // Custom theme
                    Configuration::ApplyCustomTheme();
                    Configuration::Save();
                    break;
                default:
                    break;
                }
            }
            ImGui::SameLine();
            ImGui::Text("Select Theme");

            ImGuiStyle* style = &ImGui::GetStyle();
            auto guiColor = style->Colors;

            static int selectedColor = -1;
            static std::string currentColorName = "Select a widget";

            static bool openCustomThemePopup = false;

            if (Configuration::selectedTheme != 3) {
                ImGui::PushItemFlag(ImGuiItemFlags_Disabled, (Configuration::selectedTheme == 3));
                ImGui::PushStyleVar(ImGuiStyleVar_Alpha, style->Alpha * 0.25f);
                ImGui::Button("Edit Custom Theme");
                ImGui::PopItemFlag();
                ImGui::PopStyleVar();

                if (ImGui::IsItemHovered())
                    ImGui::SetTooltip("Select 'Custom Theme' to begin editing.");
            }
            else {
                if (ImGui::Button("Edit Custom Theme")) {
                    openCustomThemePopup = true;

                    previousColors.clear(); // Ensuring previousColors is fresh.

                    for (int i = 0; i < ImGuiCol_COUNT; ++i) {
                        ImVec4 col = style->Colors[i];
                        previousColors[i] = col;
                    }
                }
            }

            if (ImGui::BeginPopupModal("Custom Theme Editor##CustomThemeEditor", nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize)) {
                if (ImGui::BeginCombo("Widgets", currentColorName.c_str())) {
                    for (const auto& colorPair : GuiColors) {
                        int colorEnum = colorPair.first;
                        const std::string& colorName = colorPair.second;

                        bool isSelected = (selectedColor == colorEnum);
                        if (ImGui::Selectable(colorName.c_str(), isSelected)) {
                            selectedColor = colorEnum;
                            currentColorName = colorName;
                        }
                        if (isSelected)
                            ImGui::SetItemDefaultFocus();
                    }
                    ImGui::EndCombo();
                }

                if (selectedColor != -1) {
                    ImVec4& color = style->Colors[selectedColor];

                    ImGui::Text("%s color", currentColorName.c_str());
                    ImGui::SameLine();
                    if (ImGui::ColorEdit4("##GuiColorPicker", reinterpret_cast<float*>(&color), ImGuiColorEditFlags_NoInputs)) {
                        auto colorIt = Configuration::customColors.find(selectedColor);
                        if (colorIt != Configuration::customColors.end()) { // Check if color already exists in customColors & replace instead of inserting.
                            if (colorIt->second != color) {
                                colorIt->second = color;
                            }
                        }
                        else {
                            Configuration::customColors.insert(std::make_pair(selectedColor, color));
                        }
                        style->Colors[selectedColor] = color;
                    }
                    ImGui::SameLine();
                    if (ImGui::Button("Undo##UndoGuiColor")) {
                        // Undo colour function
                        auto it = previousColors.find(selectedColor);
                        auto colorIt = Configuration::customColors.find(selectedColor);
                        if (it != previousColors.end()) {
                            style->Colors[selectedColor] = it->second;
                            colorIt->second = it->second;
                        }
                    }
                    if (ImGui::IsItemHovered())
                        ImGui::SetTooltip("Undo Changes.");

                    ImGui::BeginGroupPanel("Widget Preview");
                    {
                        ImGui::Spacing();

                        // Widget preview
                        GetWidgetForPreview(selectedColor);

                        ImGui::Spacing();
                    }
                    ImGui::EndGroupPanel();
                }

                ImGui::Separator();
                // Calculate the center position buttons
                float windowWidth = ImGui::GetWindowSize().x;
                float buttonWidth = 160.0f * 2 + ImGui::GetStyle().ItemSpacing.x;
                ImGui::SetCursorPosX((windowWidth - buttonWidth) * 0.5f);

                // Save button
                if (ImGui::Button("Save", ImVec2(160, 0))) {
                    // Save to config.
                    Configuration::Save();
                    openCustomThemePopup = false;
                    ImGui::CloseCurrentPopup();
                }
                ImGui::SetItemDefaultFocus();
                ImGui::SameLine();

                // Cancel button
                if (ImGui::Button("Close Without Saving", ImVec2(160, 0))) {
                    // Restore old colors.
                    auto colorIt = Configuration::customColors.find(selectedColor);
                    for (auto& it : previousColors) {
                        int idx = it.first;
                        ImVec4 col = it.second;
                        style->Colors[idx] = col;
                        colorIt->second = col;
                    }

                    previousColors.clear();
                    openCustomThemePopup = false;
                    ImGui::CloseCurrentPopup();
                }

                ImGui::EndPopup();
            }

            if (openCustomThemePopup) {
                ImGui::OpenPopup("Custom Theme Editor##CustomThemeEditor");
            }
        }

        ImGui::NextColumn();

        if (ImGui::CollapsingHeader("HotKey Settings##PlayerHotKeySettingsHeader", ImGuiTreeNodeFlags_DefaultOpen)) {
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
    }
}
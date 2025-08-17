#include "GolfOverlay.h"
#include "DetourManager.h"
#include <SDK/GolfIt_parameters.hpp>

#include "console.hpp"
#include "ImGuiExt.h"
#include "SDKExt.h"
#include "Utils.h"
#include "Configuration.h"
#include "ActorCache.h"
#include "Overlays/ESP.h"
#include "Features/PlayerFeatures.h"

#include "Modules/ESP_VisualSettings.h"
#include "Modules/Player_ModSettings.h"
#include "Modules/Fentry_Settings.h"

#include <Windows.h>
#include <algorithm>
#include <thread>
#include <fstream>
#include <TlHelp32.h>
#include <imgui_internal.h>
#include <Fonts.h>
#include <unordered_set>

using namespace SDK;

// ======== GLOBALS ======== //

std::vector<std::string> debugger;
DetourManager gDetourManager;

const char* golfBallBoxStyles[] = { "Flat Box", "Cornered Box", "3D Box" };
const char* goalFlagBoxStyles[] = { "Flat Box", "Cornered Box", "3D Box" };
static int selectedGolfBallBoxStyle = Configuration::cfg_GolfBallBoxStyle;
static int selectedGoalFlagBoxStyle = Configuration::cfg_GoalFlagBoxStyle;

bool waitingForKey = false;
bool waitingForTeleportKey = false;
bool waitingForSpeedKey = false;
bool waitingForNoClipKey = false;
bool waitingForVacuumKey = false;
bool waitingForTPTargetKey = false;
bool waitingForDropInventoryKey = false;
bool waitingForConsoleKey = false;

float tempGolfBallColor[4];
float tempGoalFlagColor[4];

const char* GolfOverlay::themes[4] = { "Main", "Spectrum Light", "Magma", "Custom Theme" };

// ======== DRAWING ======== //

void GolfOverlay::DrawGuiFOVCircle() {
    ESP::DrawGuiFOVCircle();
}

void GolfOverlay::DrawGuiESP() {
    ESP::DrawGuiESP();
}

void GolfOverlay::DrawHUD() {
    // load config
    static bool bConfigLoaded = false;
    if (!bConfigLoaded) {
        Configuration::Load(static_cast<GolfOverlay*>(OverlayBase::Instance));
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
        const char* watermarkText = "GolfIt Fentry";
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
    
    style.WindowRounding = prevRounding;

    /*
    * Theme loading
    */
    if (getTheme) {
        switch (Configuration::selectedTheme) {
        case 0:
            ImGui::StyleColorsDark();
            break;
        case 1:
            ImGui::Spectrum::StyleColorsSpectrum();
            break;
        case 2:
            ImGui::Magma::StyleColorsMagma();
            break;
        case 3:
            Configuration::ApplyCustomTheme();
            break;
        default:
            ImGui::StyleColorsDark();
            break;
        }
        getTheme = false;
    }

    /*
     * Notification rendering
     */
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
    ImVec4 windowBg = ImGui::ColorConvertU32ToFloat4(ImGui::GetColorU32(ImGuiCol_WindowBg));
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(windowBg.x, windowBg.y, windowBg.z, 1.00f));
    ImGui::RenderNotifications();
    ImGui::PopStyleVar(2);
    ImGui::PopStyleColor(1);

    /*
     * Notification(s) for first use-case scenario
     */
    static bool displayedFirstUseNotif, displayedCorruptConfigNotif = false;
    if (Configuration::bFirstUse && !displayedFirstUseNotif) {
        ImGui::InsertNotification({ ImGuiToastType::Info, 8000, "Thank you for using our GolfIt Fentry. To get started, open the menu with the 'INSERT' key." });
        displayedFirstUseNotif = true;
    }

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

void GolfOverlay::DrawOverlay() {
    bool show = true;
    const ImGuiIO& io = ImGui::GetIO();
    constexpr ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoCollapse;

    const auto center_pos = ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f);
    const auto window_size = ImVec2(Configuration::windowSizeX, Configuration::windowSizeY);
    const auto window_pos = ImVec2(center_pos.x - window_size.x * 0.5f, center_pos.y - window_size.y * 0.5f);

    ImGui::SetNextWindowPos(window_pos, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(window_size, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowBgAlpha(0.98f);

    const auto WindowTitle = std::string("www.Fentry.org");
    GolfOverlay* Overlay = static_cast<GolfOverlay*>(OverlayBase::Instance);

    if (ImGui::Begin(WindowTitle.data(), &show, window_flags)) {
        
        /*
         * First use case-scenario bool
         */
        if (Configuration::bFirstUse) {
            Configuration::bFirstUse = false;
            Configuration::Save();
        }

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
            if (ImGui::BeginTabItem(ICON_FA_GEAR " Settings & Hotkeys")) {
                OpenTab = 2;
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }

        if (OpenTab == 0) {
            ESP_VisualSettings::Show();
        }
        else if (OpenTab == 1) {
            Player_ModSettings::Show();
        }
        else if (OpenTab == 2) {
            Fentry_Settings::Show();
        }
    }

    ImGui::End();

    if (!show)
        ShowOverlay(false);
}
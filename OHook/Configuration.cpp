#include "Configuration.h"
#include "TfdOverlay.h"
#include "Utils.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <type_traits>

namespace fs = std::filesystem;

#pragma region VarsInit

std::string Configuration::JsonConfigFile = "";
bool Configuration::ConfigLoaded = false;

// Config Version
int Configuration::Version = 1;

// GUI Options
bool Configuration::bShowWatermark = true;
float Configuration::windowSizeX = 1150.0f;
float Configuration::windowSizeY = 500.0f;

// Visual Settings
float Configuration::cfg_CircleAlpha = 0.5f;
bool Configuration::cfg_DrawFOVCircle = false;
float Configuration::cfg_FOVRadius = 200.0f;
bool Configuration::cfg_EnableUnlitMode = false;
bool Configuration::cfg_AimVisCheck = true;

// Golf Ball ESP Settings
bool Configuration::cfg_DrawGolfBallESP = false;
bool Configuration::cfg_DrawGolfBallBoxes = false;
bool Configuration::cfg_DrawGolfBallNames = false;
bool Configuration::cfg_DrawGolfBallDistance = false;
bool Configuration::cfg_DrawGolfBallLines = false;
bool Configuration::cfg_DrawGolfBallLinesTop = false;
float Configuration::cfg_MaxGolfBallESPDistance = 50000.0f;
float Configuration::cfg_ESPThickness = 1.0f;
int Configuration::cfg_GolfBallBoxStyle = 0;

// Golf Ball ESP Colors
int Configuration::cfg_GolfBallESPColor = IM_COL32(255, 165, 0, 255);  // Orange
int Configuration::cfg_GolfBallESPColorTarget = IM_COL32(0, 255, 0, 255);  // Green for targeted ball

// Goal Flag ESP Settings
bool Configuration::cfg_DrawGoalFlagESP = false;
bool Configuration::cfg_DrawGoalFlagBoxes = false;
bool Configuration::cfg_DrawGoalFlagNames = false;
bool Configuration::cfg_DrawGoalFlagDistance = false;
bool Configuration::cfg_DrawGoalFlagLines = false;
bool Configuration::cfg_DrawGoalFlagLinesTop = false;
float Configuration::cfg_MaxGoalFlagESPDistance = 100000.0f;
int Configuration::cfg_GoalFlagBoxStyle = 0;
int Configuration::cfg_GoalFlagESPColor = IM_COL32(255, 255, 0, 255);  // Yellow

// Debug ESP options
bool Configuration::cfg_ShowDebugClassNames = false;
bool Configuration::cfg_ShowDebugDistance = false;
int Configuration::cfg_DebugMaxDistance = 10000;

// Aimbot Settings
float Configuration::cfg_AimbotSmoothing = 10.0f;
int Configuration::cfg_AimbotKey = VK_RBUTTON;

// Player Movement (simplified)
bool Configuration::cfg_EnableNoClip = false;
bool Configuration::cfg_EnableSpeedhack = false;
float Configuration::cfg_speedPlayerValue = 1.0f;
int Configuration::cfg_SpeedKey = VK_SUBTRACT;
int Configuration::cfg_NoClipKey = VK_RSHIFT;

// Multi Jump Settings
bool Configuration::cfg_EnableMultiJump = false;
int Configuration::cfg_MultiJumpAmount = 5;

// Teleport to Goal Settings
bool Configuration::cfg_EnableTeleportToGoal = false;
bool Configuration::cfg_TeleportAllPlayers = false;
int Configuration::cfg_TeleportToGoalKey = VK_F2;

// Teleport to Target Settings
bool Configuration::cfg_EnableTPTarget = false;
bool Configuration::cfg_SmallerTPTargeting = false;
float Configuration::cfg_TPFOVRadius = 150.0f;
float Configuration::cfg_ActorTeleportOffset = 300.0f;
float Configuration::cfg_TPNoTargetDistance = 1000.0f;
int Configuration::cfg_TPTargetKey = VK_F3;

// Console settings
bool Configuration::cfg_EnableConsole = false;
int Configuration::cfg_ConsoleKey = VK_F1;

#pragma endregion

// Path for the configuration file
static const std::string configDirectory = "C:\\ProgramData\\OriginGOLFIT\\config";
static const std::string configFileName = "golfit_config.json";
static const std::string configFilePath = configDirectory + "\\" + configFileName;

// Functions for saving and loading config data
static void EnsureDirectoryExists(const std::string& path) {
    fs::path dir(path);
    if (!fs::exists(dir)) {
        fs::create_directories(dir);
    }
}

void Configuration::ParseBool(std::string Key, bool& Var) {
    if (JsonConfigFile.empty()) return;

    if (JsonConfigFile.find(Key) == std::string::npos) return;

    Var = (JsonConfigFile.find("\"" + Key + "\": true") != std::string::npos);
}

void Configuration::ParseBool(std::string Key, bool& Var, bool DefaultValue) {
    Var = DefaultValue;
    ParseBool(Key, Var);
}

template<typename T>
void Configuration::ParseNumber(std::string Key, T& Var) {
    static_assert(std::is_arithmetic<T>::value, "Template parameter must be a numeric type");

    if (JsonConfigFile.empty()) return;

    auto pos = JsonConfigFile.find("\"" + Key + "\":");
    if (pos == std::string::npos) return;

    std::size_t start = JsonConfigFile.find_first_of("0123456789.", pos);
    std::size_t end = JsonConfigFile.find_first_not_of("0123456789.", start);
    Var = std::stof(JsonConfigFile.substr(start, end - start));
}

bool Configuration::ReadJsonFile() {
    if (!fs::exists(configFilePath)) {
        return false; // No config file to load
    }

    std::ifstream configFile(configFilePath);
    std::string line;
    if (configFile.is_open()) {
        while (getline(configFile, line)) {
            JsonConfigFile += line;
        }
        configFile.close();
        return true;
    }

    return false;
}

void Configuration::Load(TfdOverlay* Overlay) {
    if (ConfigLoaded) return;

    if (!ReadJsonFile()) return;

    // Window settings
    ParseNumber("Menu Size X", windowSizeX);
    ParseNumber("Menu Size Y", windowSizeY);

    // Visual settings
    ParseBool("Watermark", bShowWatermark);
    ParseNumber("Circle Alpha", cfg_CircleAlpha);
    ParseBool("Enable FOV Circle", cfg_DrawFOVCircle);
    ParseNumber("FOV Radius", cfg_FOVRadius);
    ParseBool("Enable Unlit Mode", cfg_EnableUnlitMode);
    ParseBool("Enable Visibility Check", cfg_AimVisCheck);

    // Golf Ball ESP Settings
    ParseBool("Enable Golf Ball ESP", cfg_DrawGolfBallESP);
    ParseBool("Enable Golf Ball Boxes", cfg_DrawGolfBallBoxes);
    ParseBool("Enable Golf Ball Names", cfg_DrawGolfBallNames);
    ParseBool("Enable Golf Ball Distance", cfg_DrawGolfBallDistance);
    ParseBool("Enable Golf Ball Lines", cfg_DrawGolfBallLines);
    ParseBool("Enable Top Golf Ball Lines", cfg_DrawGolfBallLinesTop);
    ParseNumber("Max Golf Ball ESP Distance", cfg_MaxGolfBallESPDistance);
    ParseNumber("ESP Thickness", cfg_ESPThickness);
    ParseNumber("Golf Ball Box Style", cfg_GolfBallBoxStyle);
    
    // Goal Flag ESP Settings
    ParseBool("Enable Goal Flag ESP", cfg_DrawGoalFlagESP);
    ParseBool("Enable Goal Flag Boxes", cfg_DrawGoalFlagBoxes);
    ParseBool("Enable Goal Flag Names", cfg_DrawGoalFlagNames);
    ParseBool("Enable Goal Flag Distance", cfg_DrawGoalFlagDistance);
    ParseBool("Enable Goal Flag Lines", cfg_DrawGoalFlagLines);
    ParseBool("Enable Top Goal Flag Lines", cfg_DrawGoalFlagLinesTop);
    ParseNumber("Max Goal Flag ESP Distance", cfg_MaxGoalFlagESPDistance);
    ParseNumber("Goal Flag Box Style", cfg_GoalFlagBoxStyle);

    // Debug ESP options
    ParseBool("Show Debug Class Names", cfg_ShowDebugClassNames);
    ParseBool("Show Debug Distance", cfg_ShowDebugDistance);
    ParseNumber("Debug Max Distance", cfg_DebugMaxDistance);

    // Aimbot Settings
    ParseNumber("Aimbot Smoothing", cfg_AimbotSmoothing);
    ParseNumber("Aimbot Key", cfg_AimbotKey);

    // Movement settings
    ParseBool("Enable NoClip", cfg_EnableNoClip);
    ParseBool("Enable Speedhack", cfg_EnableSpeedhack);
    ParseNumber("Speedhack Amount", cfg_speedPlayerValue);
    ParseNumber("Speedhack Key", cfg_SpeedKey);
    ParseNumber("NoClip Key", cfg_NoClipKey);
    
    // Multi Jump settings
    ParseBool("Enable Multi Jump", cfg_EnableMultiJump);
    ParseNumber("Multi Jump Amount", cfg_MultiJumpAmount);
    
    // Teleport to Goal settings
    ParseBool("Enable Teleport to Goal", cfg_EnableTeleportToGoal);
    ParseBool("Teleport All Players", cfg_TeleportAllPlayers);
    ParseNumber("Teleport to Goal Key", cfg_TeleportToGoalKey);
    
    // Teleport to Target settings
    ParseBool("Enable Teleport to Target", cfg_EnableTPTarget);
    ParseBool("Smaller TP Targeting", cfg_SmallerTPTargeting);
    ParseNumber("TP FOV Radius", cfg_TPFOVRadius);
    ParseNumber("Actor Teleport Offset", cfg_ActorTeleportOffset);
    ParseNumber("TP No Target Distance", cfg_TPNoTargetDistance);
    ParseNumber("TP Target Key", cfg_TPTargetKey);

    // Console settings
    ParseBool("Enable Console", cfg_EnableConsole);
    ParseNumber("Console Key", cfg_ConsoleKey);

    ConfigLoaded = true;
}

void Configuration::Save() {
    EnsureDirectoryExists(configDirectory);

    std::ofstream configFile(configFilePath);
    if (configFile.is_open()) {
        configFile << "{\n";
        
        // Window settings
        configFile << "    \"Version\": " << Version << ",\n";
        configFile << "    \"Menu Size X\": " << windowSizeX << ",\n";
        configFile << "    \"Menu Size Y\": " << windowSizeY << ",\n";

        // Visual settings
        configFile << "    \"Watermark\": " << (bShowWatermark ? "true" : "false") << ",\n";
        configFile << "    \"Circle Alpha\": " << cfg_CircleAlpha << ",\n";
        configFile << "    \"Enable FOV Circle\": " << (cfg_DrawFOVCircle ? "true" : "false") << ",\n";
        configFile << "    \"FOV Radius\": " << cfg_FOVRadius << ",\n";
        configFile << "    \"Enable Unlit Mode\": " << (cfg_EnableUnlitMode ? "true" : "false") << ",\n";
        configFile << "    \"Enable Visibility Check\": " << (cfg_AimVisCheck ? "true" : "false") << ",\n";

        // Golf Ball ESP Settings
        configFile << "    \"Enable Golf Ball ESP\": " << (cfg_DrawGolfBallESP ? "true" : "false") << ",\n";
        configFile << "    \"Enable Golf Ball Boxes\": " << (cfg_DrawGolfBallBoxes ? "true" : "false") << ",\n";
        configFile << "    \"Enable Golf Ball Names\": " << (cfg_DrawGolfBallNames ? "true" : "false") << ",\n";
        configFile << "    \"Enable Golf Ball Distance\": " << (cfg_DrawGolfBallDistance ? "true" : "false") << ",\n";
        configFile << "    \"Enable Golf Ball Lines\": " << (cfg_DrawGolfBallLines ? "true" : "false") << ",\n";
        configFile << "    \"Enable Top Golf Ball Lines\": " << (cfg_DrawGolfBallLinesTop ? "true" : "false") << ",\n";
        configFile << "    \"Max Golf Ball ESP Distance\": " << cfg_MaxGolfBallESPDistance << ",\n";
        configFile << "    \"ESP Thickness\": " << cfg_ESPThickness << ",\n";
        configFile << "    \"Golf Ball Box Style\": " << cfg_GolfBallBoxStyle << ",\n";
        
        // Goal Flag ESP Settings
        configFile << "    \"Enable Goal Flag ESP\": " << (cfg_DrawGoalFlagESP ? "true" : "false") << ",\n";
        configFile << "    \"Enable Goal Flag Boxes\": " << (cfg_DrawGoalFlagBoxes ? "true" : "false") << ",\n";
        configFile << "    \"Enable Goal Flag Names\": " << (cfg_DrawGoalFlagNames ? "true" : "false") << ",\n";
        configFile << "    \"Enable Goal Flag Distance\": " << (cfg_DrawGoalFlagDistance ? "true" : "false") << ",\n";
        configFile << "    \"Enable Goal Flag Lines\": " << (cfg_DrawGoalFlagLines ? "true" : "false") << ",\n";
        configFile << "    \"Enable Top Goal Flag Lines\": " << (cfg_DrawGoalFlagLinesTop ? "true" : "false") << ",\n";
        configFile << "    \"Max Goal Flag ESP Distance\": " << cfg_MaxGoalFlagESPDistance << ",\n";
        configFile << "    \"Goal Flag Box Style\": " << cfg_GoalFlagBoxStyle << ",\n";

        // Debug ESP options
        configFile << "    \"Show Debug Class Names\": " << (cfg_ShowDebugClassNames ? "true" : "false") << ",\n";
        configFile << "    \"Show Debug Distance\": " << (cfg_ShowDebugDistance ? "true" : "false") << ",\n";
        configFile << "    \"Debug Max Distance\": " << cfg_DebugMaxDistance << ",\n";

        // Aimbot Settings
        configFile << "    \"Aimbot Smoothing\": " << cfg_AimbotSmoothing << ",\n";
        configFile << "    \"Aimbot Key\": " << cfg_AimbotKey << ",\n";

        // Movement settings
        configFile << "    \"Enable NoClip\": " << (cfg_EnableNoClip ? "true" : "false") << ",\n";
        configFile << "    \"Enable Speedhack\": " << (cfg_EnableSpeedhack ? "true" : "false") << ",\n";
        configFile << "    \"Speedhack Amount\": " << cfg_speedPlayerValue << ",\n";
        configFile << "    \"Speedhack Key\": " << cfg_SpeedKey << ",\n";
        configFile << "    \"NoClip Key\": " << cfg_NoClipKey << ",\n";
        
        // Multi Jump settings
        configFile << "    \"Enable Multi Jump\": " << (cfg_EnableMultiJump ? "true" : "false") << ",\n";
        configFile << "    \"Multi Jump Amount\": " << cfg_MultiJumpAmount << ",\n";
        
        // Teleport to Goal settings
        configFile << "    \"Enable Teleport to Goal\": " << (cfg_EnableTeleportToGoal ? "true" : "false") << ",\n";
        configFile << "    \"Teleport All Players\": " << (cfg_TeleportAllPlayers ? "true" : "false") << ",\n";
        configFile << "    \"Teleport to Goal Key\": " << cfg_TeleportToGoalKey << ",\n";
        
        // Teleport to Target settings
        configFile << "    \"Enable Teleport to Target\": " << (cfg_EnableTPTarget ? "true" : "false") << ",\n";
        configFile << "    \"Smaller TP Targeting\": " << (cfg_SmallerTPTargeting ? "true" : "false") << ",\n";
        configFile << "    \"TP FOV Radius\": " << cfg_TPFOVRadius << ",\n";
        configFile << "    \"Actor Teleport Offset\": " << cfg_ActorTeleportOffset << ",\n";
        configFile << "    \"TP No Target Distance\": " << cfg_TPNoTargetDistance << ",\n";
        configFile << "    \"TP Target Key\": " << cfg_TPTargetKey << ",\n";

        // Console settings
        configFile << "    \"Enable Console\": " << (cfg_EnableConsole ? "true" : "false") << ",\n";
        configFile << "    \"Console Key\": " << cfg_ConsoleKey << "\n";

        configFile << "}";
        configFile.close();
    }
}
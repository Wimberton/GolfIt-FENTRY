#pragma once
#include <string>
#include <type_traits>
#include <fstream>
#include <imgui.h>
#include <filesystem>
#include <iostream>
#include <map>

class GolfOverlay;

class Configuration final {
private:
    static bool ReadJsonFile();
    static void ParseBool(std::string Key, bool& Var);
    static void ParseBool(std::string Key, bool& Var, bool DefaultValue);

    template<typename T>
    static void ParseNumber(std::string Key, T& Var);

    static std::string JsonConfigFile;
    static bool ConfigLoaded;

public:
    static void Load(GolfOverlay* Overlay);
    static void Save();
    static void ApplyCustomTheme();

#pragma region ConfigVars

    // Config Version
    static int Version;
    
    static bool bFirstUse;
    static int selectedTheme;
    static std::map<int, ImVec4> customColors;

    // GUI Settings
    static bool bShowWatermark;
    static float windowSizeX;
    static float windowSizeY;

    // Visual Settings
    static float cfg_CircleAlpha;
    static bool cfg_DrawFOVCircle;
    static float cfg_FOVRadius;
    static bool cfg_EnableUnlitMode;
    static bool cfg_AimVisCheck;

    // Golf Ball ESP Settings
    static bool cfg_DrawGolfBallESP;
    static bool cfg_DrawGolfBallBoxes;
    static bool cfg_DrawGolfBallNames;
    static bool cfg_DrawGolfBallDistance;
    static bool cfg_DrawGolfBallLines;
    static bool cfg_DrawGolfBallLinesTop;
    static float cfg_MaxGolfBallESPDistance;
    static float cfg_ESPThickness;
    static int cfg_GolfBallBoxStyle;

    // Golf Ball ESP Colors
    static int cfg_GolfBallESPColor;
    static int cfg_GolfBallESPColorTarget;
    
    // Goal Flag ESP Settings
    static bool cfg_DrawGoalFlagESP;
    static bool cfg_DrawGoalFlagBoxes;
    static bool cfg_DrawGoalFlagNames;
    static bool cfg_DrawGoalFlagDistance;
    static bool cfg_DrawGoalFlagLines;
    static bool cfg_DrawGoalFlagLinesTop;
    static float cfg_MaxGoalFlagESPDistance;
    static int cfg_GoalFlagBoxStyle;
    static int cfg_GoalFlagESPColor;

    // Debug ESP Options
    static bool cfg_ShowDebugClassNames;
    static bool cfg_ShowDebugDistance;
    static int cfg_DebugMaxDistance;

    // Aimbot Settings
    static float cfg_AimbotSmoothing;
    static int cfg_AimbotKey;

    // Player Movement (simplified)
    static bool cfg_EnableNoClip;
    static bool cfg_EnableSpeedhack;
    static float cfg_speedPlayerValue;
    static int cfg_SpeedKey;
    static int cfg_NoClipKey;
    
    // Multi Jump Settings
    static bool cfg_EnableMultiJump;
    static int cfg_MultiJumpAmount;
    
    // Teleport to Goal Settings
    static bool cfg_EnableTeleportToGoal;
    static bool cfg_TeleportAllPlayers;
    static int cfg_TeleportToGoalKey;
    
    // Teleport to Target Settings
    static bool cfg_EnableTPTarget;
    static bool cfg_SmallerTPTargeting;
    static float cfg_TPFOVRadius;
    static float cfg_ActorTeleportOffset;
    static float cfg_TPNoTargetDistance;
    static int cfg_TPTargetKey;

    // Console Settings
    static bool cfg_EnableConsole;
    static int cfg_ConsoleKey;

#pragma endregion
};
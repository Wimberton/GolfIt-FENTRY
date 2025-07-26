#pragma once
#include "../ImGui/imgui.h"

namespace ColorManager {
    // Golf Ball ESP colors
    extern ImU32 GolfBallESPColor;
    extern ImU32 GolfBallESPColorTarget;
    
    // Goal Flag ESP colors
    extern ImU32 GoalFlagESPColor;
    
    // Health bar colors
    extern ImU32 HealthBarColorGreen;
    extern ImU32 HealthBarColorYellow;
    extern ImU32 HealthBarColorRed;
    
    // Initialize all colors from configuration
    void Initialize();
} 
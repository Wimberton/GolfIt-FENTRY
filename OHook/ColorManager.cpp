#include "ColorManager.h"
#include "Configuration.h"

namespace ColorManager {
    // Initialize Golf Ball ESP colors from configuration
    ImU32 GolfBallESPColor = Configuration::cfg_GolfBallESPColor;
    ImU32 GolfBallESPColorTarget = Configuration::cfg_GolfBallESPColorTarget;
    
    // Initialize Goal Flag ESP colors from configuration
    ImU32 GoalFlagESPColor = Configuration::cfg_GoalFlagESPColor;
    
    // Health bar colors
    ImU32 HealthBarColorGreen = IM_COL32(0, 255, 0, 255);
    ImU32 HealthBarColorYellow = IM_COL32(255, 255, 0, 255);
    ImU32 HealthBarColorRed = IM_COL32(255, 0, 0, 255);
    
    // Initialize all colors from configuration
    void Initialize() {
        // Golf Ball ESP colors
        GolfBallESPColor = Configuration::cfg_GolfBallESPColor;
        GolfBallESPColorTarget = Configuration::cfg_GolfBallESPColorTarget;
        
        // Goal Flag ESP colors
        GoalFlagESPColor = Configuration::cfg_GoalFlagESPColor;
        
        // Health bar colors (these are static)
        HealthBarColorGreen = IM_COL32(0, 255, 0, 255);
        HealthBarColorYellow = IM_COL32(255, 255, 0, 255);
        HealthBarColorRed = IM_COL32(255, 0, 0, 255);
    }
} 
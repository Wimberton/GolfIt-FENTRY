#pragma once

#include <imgui.h>

class ESP {
public:
    static void DrawGuiFOVCircle();
    static void DrawGuiESP();
    
private:
    // Helper functions if needed in the future
    static bool IsValidScreenPosition(const ImVec2& position, const ImVec2& canvasSize);
};

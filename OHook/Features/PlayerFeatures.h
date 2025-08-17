#pragma once
#include "SDKExt.h"
#include "GolfOverlay.h"
#include "Configuration.h"
#include <SDK.hpp>

using namespace SDK;

namespace PlayerFeatures {
    void Func_DoNoClip();
    void Func_DoSpeedmod();
    void Func_DoMultiJump();
    void Func_UnlitMode();
    void Func_DoTeleportToGoal();
    void Func_UnifiedTeleport(GolfOverlay* Overlay);
    
    // Player Control Functions
    void TeleportPlayerToGoal(AGolfBall_C* targetPlayer);
    void TeleportPlayerToMe(AGolfBall_C* targetPlayer);
    void TeleportMeToPlayer(AGolfBall_C* targetPlayer);
    void FreezePlayer(AGolfBall_C* targetPlayer);
    void UnfreezePlayer(AGolfBall_C* targetPlayer);
    void LaunchPlayer(AGolfBall_C* targetPlayer);
    void SpeedUpPlayer(AGolfBall_C* targetPlayer);
    void SlowDownPlayer(AGolfBall_C* targetPlayer);
    void ResetPlayer(AGolfBall_C* targetPlayer);
}

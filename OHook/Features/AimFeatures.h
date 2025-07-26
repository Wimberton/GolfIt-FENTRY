#pragma once
#include "../SDKExt.h"
#include "../TfdOverlay.h"
#include "../Configuration.h"
#include "../../GolfSDK/SDK.hpp"

using namespace SDK;

namespace AimFeatures {
    void Func_DoTargeting(TfdOverlay* Overlay, const AHUD* HUD);
    void Func_DoAimbot(TfdOverlay* Overlay, const AHUD* HUD);
}

#pragma once
#include "SDKExt.h"
#include "GolfOverlay.h"
#include "Configuration.h"
#include <SDK.hpp>

using namespace SDK;

namespace AimFeatures {
    void Func_DoTargeting(GolfOverlay* Overlay, const AHUD* HUD);
    void Func_DoAimbot(GolfOverlay* Overlay, const AHUD* HUD);
}

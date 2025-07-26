#pragma once
#include "SDKExt.h"
#include "Configuration.h"
#include "../GolfSDK/SDK.hpp"
#include "../console/console.hpp"
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <Windows.h>

using namespace SDK;

namespace ComponentLogger {
    // Initialize the component logger
    void Initialize();
    
    // Process a function event for logging (called from DetourManager)
    void ProcessEvent(const UObject* Object, const UFunction* Function, void* Params);
    
    // Check if component logging is enabled
    bool IsEnabled();
    
    // Check if an object should be monitored
    bool ShouldMonitor(const UObject* Object);
} 
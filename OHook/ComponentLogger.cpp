#include "ComponentLogger.h"
#include "Utils.h"

namespace ComponentLogger {
    // List of component class names to monitor - easily configurable
    static const std::unordered_set<std::string> MONITORED_CLASSES = {
        // Player Controllers
        "APlayerController",
        // Player State
        // "APlayerState",
        
        // Characters (Descendants)
        // "AM1Character",
        // "Bunny_C",
        // "UltimateBunny_C", 
        // "Viessa_C",
        // "Ines_C",
        
        // Weapons
        "AWeapon",
        // "SMG_1004_C",
        // "SMG_1005_C",
        // "AR_1006_C",
        // "AR_1007_C",
        // "MG_1003_C",
        // "MG_1007_C",
        // "HC_1011_C",
        // "LNC_1001_C",
        
        // Movement Components
        // "UCharacterMovementComponent",
        // "M1PlayerMovementComponent",
        
        // Weapon Components
        // "UM1WeaponRoundsComponent",
        // "M1WeaponRoundsComponent",
        // "UM1WeaponReloadComponent", 
        "UM1WeaponAttackComponent",
        "UM1WeaponInstantHitComponent",  // Add this to monitor silent aim functions
        // "UM1WeaponFireLoopComponent",

    };
    
    // Blacklist of noisy functions that aren't useful for debugging
    static const std::unordered_set<std::string> BLACKLISTED_FUNCTIONS = {
        // Engine functions
        "Function Engine.Actor.IsActorBeingDestroyed",
        "Function Engine.Actor.K2_GetActorLocation",
        "Function Engine.Controller.K2_GetPawn",
        "Function Engine.Actor.ReceiveTick",
        "Function Engine.PlayerController.ProjectWorldLocationToScreen",
        "Function Engine.Actor.OnRep_ReplicatedMovement",
        "Function Engine.PlayerController.ServerUpdateCamera",
        "Function Engine.Character.ClientMoveResponsePacked",
        "Function Engine.Character.ServerMovePacked",
        "Function Engine.Actor.GetActorLocation",
        "Function Engine.Actor.GetActorRotation",
        "Function Engine.Actor.GetActorTransform",
        "Function Engine.Pawn.GetPawnViewLocation",
        "Function Engine.Controller.GetControlRotation",
        "Function Engine.Actor.GetActorBounds",
        "Function Engine.SceneComponent.GetComponentLocation",
        "Function Engine.SceneComponent.GetComponentRotation",
        "Function Engine.SceneComponent.GetComponentTransform",
        // M1 functions that are too noisy
        "Function M1.M1PlayerControllerInGame.GetMultiSupplierObtainComponent",
        "Function M1.M1Character.IsDead",
        "Function M1.M1Weapon.IsZoomedOrOwnWay",
        // Network replication functions (very frequent)
        "Function M1.M1Weapon.NetMulticastSetWeaponActionState",
        "Function M1.M1Player.OnRepInAir",
        "Function M1.M1Character.OnRep_SpawnParams",
        "Function M1.M1Actor.OnRepDataKey",
        "Function M1.M1Weapon.OnRepWeaponLevel",
        "Function M1.M1WeaponRoundsComponent.OnRepCurrentRoundsRep",
        "Function M1.M1Player.OnRep_FinishedSetupOnServer",
        "Function M1.M1Player.OnRep_FellowInfo",
        "Function M1.M1Player.Cosmetic_UpdateCustomizingSkinVisibilities",
        // Ability functions (very frequent - cooldown/availability checks)
        "Function M1.M1SkillAbility.CheckCoolTimeInAbility",
        "Function M1.M1SkillAbility.CanActivateAbility",
        "Function Default_Fist.Default_Fist_C.CheckCoolTimeInAbility",
        // Ability tick functions (run every frame)
        "Function Skill_Bunny_Passive.Skill_Bunny_Passive_C.OnTick"
    };
    
    // **CUSTOMIZATION-SPECIFIC FUNCTIONS TO ALWAYS LOG** (never filter these)
    static const std::unordered_set<std::string> CUSTOMIZATION_FUNCTIONS = {
        "Function M1.M1PrivateOnlineServiceComponent.ClientReceiveOwnedCustomizings",
        "Function M1.M1PrivateOnlineServiceComponent.ServerRequestCustomizingCharacterSkin",
        "Function M1.M1PrivateOnlineServiceComponent.ClientReceiveCustomizingCharacterSkin",
        "Function M1.M1PrivateOnlineServiceComponent.ServerEquipCustomizeCharacterSkin",
        "Function M1.M1PrivateOnlineServiceComponent.ClientEquipCustomizeCharacterSkin",
        "Function M1.M1AccountInventory.AddOrUpdateCustomizingItems",
        "Function M1.M1AccountInventory.SetCustomizingItemList",
        "Function M1.M1Account.GetInventory",
        "Function M1.M1PrivateOnlineServiceCustomize.ClientReceiveCustomizingCharacterSkin",
        "Function M1.M1PrivateOnlineServiceCustomize.ReceiveCustomizingCharacterSkinImpl"
    };
    
    // Debug: Track unique class names we've seen
    static std::unordered_set<std::string> seenClasses;
    static int processEventCallCount = 0;
    static int filteredCallCount = 0;
    
    // Configuration flags
    static bool bFilterAllEngineFunctions = true;  // Filter out ALL Engine.* functions
    static bool bFilterEngineNoise = true;         // Filter out specific blacklisted functions (both Engine and M1)
    static bool bShowRPCs = true;                  // Show RPC calls
    static bool bShowM1Functions = true;           // Show M1/game-specific functions

    #ifndef DISABLE_LOGGING_CONSOLE
        bool IsEnabled() {
            return true; 
        }
    #else
        bool IsEnabled() {
            return false;
        }
    #endif
    
    // Check if a function should be filtered out
    bool ShouldFilterFunction(const std::string& functionName) {
        // NEVER filter weapon-related functions (for debugging silent aim)
        if (functionName.find("M1WeaponInstantHitComponent") != std::string::npos ||
            functionName.find("HitScan") != std::string::npos ||
            functionName.find("BP_Fire") != std::string::npos ||
            functionName.find("InstantHit") != std::string::npos ||
            functionName.find("Server_InstantHit") != std::string::npos) {
            return false; // Never filter weapon functions we care about
        }
        
        // NEVER filter customization functions - these are critical for debugging
        // if (CUSTOMIZATION_FUNCTIONS.find(functionName) != CUSTOMIZATION_FUNCTIONS.end()) {
        //     return false; // Never filter customization functions
        // }
        
        // NEVER filter any function containing "Customiz" (might be related to customization)
        // if (functionName.find("Customiz") != std::string::npos || functionName.find("customiz") != std::string::npos) {
        //     return false; // Never filter potential customization functions
        // }
        
        // First check: Filter out specifically blacklisted functions (both Engine and M1)
        if (bFilterEngineNoise) {
            if (BLACKLISTED_FUNCTIONS.find(functionName) != BLACKLISTED_FUNCTIONS.end()) {
                return true; // Filter blacklisted functions
            }
        }
        
        // Second check: Filter out ALL Engine functions if enabled
        if (bFilterAllEngineFunctions) {
            if (functionName.find("Function Engine.") != std::string::npos) {
                return true; // Filter ALL Engine functions
            }
        }
        
        // Don't filter other functions (including non-blacklisted M1 functions)
        return false;
    }
    
    // Check if an object should be monitored based on its class
    bool ShouldMonitor(const UObject* Object) {
        if (!Object || !Object->Class) return false;
        
        std::string className = Object->Class->GetName().c_str();
        
        // Debug: Track unique class names we've seen
        // if (seenClasses.find(className) == seenClasses.end()) {
        //     seenClasses.insert(className);
        //     // Only log milestone counts to avoid spam
        //     if (seenClasses.size() % 100 == 0) {
        //         LOG_DEBUG("ComponentLogger: Saw %zu unique classes so far", seenClasses.size());
        //     }
        // }
        
        // First check exact class name match (for performance)
        bool shouldMonitor = MONITORED_CLASSES.find(className) != MONITORED_CLASSES.end();
        
        // If no exact match, check inheritance hierarchy
        if (!shouldMonitor) {
            // Check if this object is a subclass of any monitored class
            try {
                // Player Controllers
                if (Object->IsA(APlayerController::StaticClass()) && 
                    (className.find("PlayerController") != std::string::npos)) {
                    shouldMonitor = true;
                }
                // Characters
                // else if (Object->IsA(AM1Character::StaticClass())) {
                //     shouldMonitor = true;
                // }
                
                // Note: inheritance logging removed to reduce spam
            } catch (...) {
                // Ignore IsA() exceptions
            }
        }
        
        return shouldMonitor;
    }
    
    // Process a function event for logging (called from DetourManager)
    void ProcessEvent(const UObject* Object, const UFunction* Function, void* Params) {
        processEventCallCount++;
        
        // Debug: Log stats every 100000 calls to reduce spam
        if (processEventCallCount % 1000000 == 0) {
            LOG_DEBUG("ComponentLogger: Processed %d calls, filtered %d (%.1f%% filtered)", 
                     processEventCallCount, filteredCallCount, 
                     (float)filteredCallCount / processEventCallCount * 100.0f);
        }
        
        if (!IsEnabled() || !Object || !Function) return;
        
        // Only log if this object should be monitored
        if (!ShouldMonitor(Object)) return;
        
        // Get function name early for filtering
        const std::string functionName = Function->GetFullName();
        
        // Filter out noisy functions
        if (ShouldFilterFunction(functionName)) {
            filteredCallCount++;
            return;
        }
        
        // Log the function call
        const std::string objectName = Object->GetFullName();
        const std::string className = Object->Class ? Object->Class->GetName().c_str() : "Unknown";
        
        // Check if this is an RPC call
        bool isRPC = functionName.find("RPC") != std::string::npos || 
                    functionName.find("Server") != std::string::npos || 
                    functionName.find("Client") != std::string::npos ||
                    functionName.find("Multicast") != std::string::npos;
        
        // Check if this is a customization function (highest priority)
        bool isCustomizationFunction = CUSTOMIZATION_FUNCTIONS.find(functionName) != CUSTOMIZATION_FUNCTIONS.end();
        
        // Also catch any function with "Customiz" in the name (case-insensitive)
        bool isAnyCustomizationFunction = (functionName.find("Customiz") != std::string::npos) || 
                                         (functionName.find("customiz") != std::string::npos);
        
        if (isCustomizationFunction) {
            LOG_RPC("========================================");
            LOG_RPC("*** CUSTOMIZATION FUNCTION DETECTED ***");
            LOG_RPC("Function: %s", functionName.c_str());
            LOG_RPC("Object: %s", objectName.c_str());
            LOG_RPC("Class: %s", className.c_str());
            LOG_RPC("*** THIS IS WHAT WE'RE LOOKING FOR ***");
            LOG_RPC("========================================");
        } else if (isAnyCustomizationFunction) {
            LOG_RPC("========================================");
            LOG_RPC("*** UNKNOWN CUSTOMIZATION FUNCTION ***");
            LOG_RPC("Function: %s", functionName.c_str());
            LOG_RPC("Object: %s", objectName.c_str());
            LOG_RPC("Class: %s", className.c_str());
            LOG_RPC("*** MIGHT BE RELATED TO CUSTOMIZATION ***");
            LOG_RPC("========================================");
        } else if (isRPC) {
            LOG_RPC("=== RPC CALL ===");
            LOG_RPC("Function: %s", functionName.c_str());
            LOG_RPC("Object: %s", objectName.c_str());
            LOG_RPC("Class: %s", className.c_str());
            LOG_RPC("================");
        } else {
            LOG_FUNCTION("=== FUNCTION CALL ===");
            LOG_FUNCTION("Function: %s", functionName.c_str());
            LOG_FUNCTION("Object: %s", objectName.c_str());
            LOG_FUNCTION("Class: %s", className.c_str());
            LOG_FUNCTION("====================");
        }
    }
    
    // Initialize the component logger
    void Initialize() {
        LOG_EVENT("=== Component Logger Initialized ===");
        LOG_EVENT("Monitoring classes:");
        for (const auto& className : MONITORED_CLASSES) {
            LOG_EVENT("  - %s", className.c_str());
        }
        LOG_EVENT("Note: Also monitoring subclasses via inheritance");
        LOG_EVENT("Filtering: All Engine functions=%s, Blacklisted functions=%s, Show M1=%s", 
                  bFilterAllEngineFunctions ? "Yes" : "No",
                  bFilterEngineNoise ? "Yes" : "No", 
                  bShowM1Functions ? "Yes" : "No");
        LOG_EVENT("*** SPECIAL: Monitoring %zu specific customization functions ***", CUSTOMIZATION_FUNCTIONS.size());
        LOG_EVENT("*** SPECIAL: Never filtering any function containing 'Customiz' ***");
        LOG_EVENT("====================================");
    }
} 
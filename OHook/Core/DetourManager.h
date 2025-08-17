#ifndef DETOUR_MANAGER_H
#define DETOUR_MANAGER_H

#pragma once

#include <unordered_set>
#include <SDK.hpp>
#include <Imgui.h>
#include "GolfOverlay.h"

class GolfOverlay;

using namespace SDK;

inline static void (__fastcall *OriginalProcessEvent)(const UObject*, const UFunction*, void*);
inline static std::unordered_set<std::string> invocations;
inline static void* HookedClient;
inline static UFont* Roboto;

// ESP color globals - these are used across multiple files
extern ImU32 PlayerESPColorVisible;
extern ImU32 PlayerESPColorAimed;
extern ImU32 PlayerESPColorNonVisible;

extern ImU32 MonsterESPColorVisible;
extern ImU32 MonsterESPColorAimed;
extern ImU32 MonsterESPColorNonVisible;

extern ImU32 ItemESPColor;

// Item type specific colors
extern ImU32 EquipmentColor;
extern ImU32 ResourceColor;
extern ImU32 ModuleColor;
extern ImU32 AmmoColor;
extern ImU32 HealthColor;
extern ImU32 ManaColor;
extern ImU32 BuffColor;
extern ImU32 EmberColor;
extern ImU32 CurrencyColor;

// NPC type specific colors
extern ImU32 JournalColor;
extern ImU32 ArcheEchoColor;
extern ImU32 MissionBeaconColor;
extern ImU32 SupportDroneColor;

// Task type specific colors
extern ImU32 SurveillanceTowerColor;
extern ImU32 MissionTaskColor;

class DetourManager final {

public:
    DetourManager() = default;

    static inline void ProcessEventDetourCallback(const UObject* Class, const UFunction* Function, void* Params, const DetourManager* manager);
    static inline void ProcessEventDetour(const UObject* Class, const UFunction* Function, void* Params);
    static void SetupDetour(void* Instance, void (*DetourFunc)(const UObject*, const UFunction*, void*));
    static void SetupDetour(void* Instance);
};

#endif
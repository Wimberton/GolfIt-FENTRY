#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: LobbySettings_0

#include "Basic.hpp"

#include "CustomSettings_structs.hpp"


namespace SDK
{

// UserDefinedStruct LobbySettings.LobbySettings
// 0x0048 (0x0048 - 0x0000)
struct FLobbySettings final
{
public:
	class FString                                 SettingsName_27_CC4777DD43E50A55F5CC068C5E2973C9;  // 0x0000(0x0010)(Edit, BlueprintVisible, ZeroConstructor, HasGetValueTypeHash)
	int32                                         StrokeIndex_6_99380B4D443B4125D6A00CB901E2CF54;    // 0x0010(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         TimeIndex_5_A4FA09FA4C82F98D35D7D9BD9CBAD69D;      // 0x0014(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FString                                 GameMode_9_7CCB672B49B1A264B2EA828018743822;       // 0x0018(0x0010)(Edit, BlueprintVisible, ZeroConstructor, HasGetValueTypeHash)
	int32                                         PracticeHole_12_7A3B444448D4BE5681B01C984F7962CB;  // 0x0028(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         TickIndex_14_086EDA524F5BF4B0973DA0BD3EC31C1D;     // 0x002C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Collision_17_BAA2FDF54F0DBF2C5EC8E9B3E165819B;     // 0x0030(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Scoreboard_19_804E13FA446F977DA790CCA98EFEC793;    // 0x0031(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	struct FCustomSettings                        CustomSettings_24_71F229D446728D7BEC34C28E59163A5C; // 0x0032(0x000A)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         NewStrokes_30_BEB8EAF94C71DD46550D7AB89BC07B4E;    // 0x003C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         NewTimes_32_203434FE451F04BE4565449EDE548263;      // 0x0040(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}


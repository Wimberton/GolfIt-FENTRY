#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: PlayerNameGolfBall_VR

#include "Basic.hpp"

#include "SlateCore_structs.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function PlayerNameGolfBall_VR.PlayerNameGolfBall_VR_C.SetName
// 0x0020 (0x0020 - 0x0000)
struct PlayerNameGolfBall_VR_C_SetName final
{
public:
	class FString                                 Param_Name;                                        // 0x0000(0x0010)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
	struct FLinearColor                           Param_Color;                                       // 0x0010(0x0010)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function PlayerNameGolfBall_VR.PlayerNameGolfBall_VR_C.ExecuteUbergraph_PlayerNameGolfBall_VR
// 0x0068 (0x0068 - 0x0000)
struct PlayerNameGolfBall_VR_C_ExecuteUbergraph_PlayerNameGolfBall_VR final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 K2Node_CustomEvent_Name;                           // 0x0008(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	struct FLinearColor                           K2Node_CustomEvent_Color;                          // 0x0018(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FSlateColor                            K2Node_MakeStruct_SlateColor;                      // 0x0028(0x0028)()
	class FText                                   CallFunc_Conv_StringToText_ReturnValue;            // 0x0050(0x0018)()
};

}


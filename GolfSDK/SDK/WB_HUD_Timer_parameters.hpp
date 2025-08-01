#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_HUD_Timer

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "SlateCore_structs.hpp"
#include "Engine_structs.hpp"
#include "GolfIt_structs.hpp"


namespace SDK::Params
{

// Function WB_HUD_Timer.WB_HUD_Timer_C.Tick
// 0x003C (0x003C - 0x0000)
struct WB_HUD_Timer_C_Tick final
{
public:
	struct FGeometry                              MyGeometry;                                        // 0x0000(0x0038)(BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
	float                                         InDeltaTime;                                       // 0x0038(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function WB_HUD_Timer.WB_HUD_Timer_C.OnCurrentHoleChanged
// 0x0008 (0x0008 - 0x0000)
struct WB_HUD_Timer_C_OnCurrentHoleChanged final
{
public:
	int32                                         LastHole;                                          // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         NextHole;                                          // 0x0004(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function WB_HUD_Timer.WB_HUD_Timer_C.SetHole
// 0x0004 (0x0004 - 0x0000)
struct WB_HUD_Timer_C_SetHole final
{
public:
	int32                                         Hole;                                              // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function WB_HUD_Timer.WB_HUD_Timer_C.ExecuteUbergraph_WB_HUD_Timer
// 0x0248 (0x0248 - 0x0000)
struct WB_HUD_Timer_C_ExecuteUbergraph_WB_HUD_Timer final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AGameStateBase*                         CallFunc_GetGameState_ReturnValue;                 // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AGolfItLobbyGameState*                  K2Node_DynamicCast_AsGolf_It_Lobby_Game_State;     // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0019(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1A[0x6];                                       // 0x001A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class AGameStateBase*                         CallFunc_GetGameState_ReturnValue_1;               // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void(int32 LastHole, int32 NextHole)> K2Node_CreateDelegate_OutputDelegate;              // 0x0028(0x0010)(ZeroConstructor, NoDestructor)
	class AGolfItLobbyGameState*                  K2Node_DynamicCast_AsGolf_It_Lobby_Game_State_1;   // 0x0038(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess_1;                     // 0x0040(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValid_ReturnValue_1;                    // 0x0041(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_42[0x2];                                       // 0x0042(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	struct FGeometry                              K2Node_Event_MyGeometry;                           // 0x0044(0x0038)(IsPlainOldData, NoDestructor)
	float                                         K2Node_Event_InDeltaTime;                          // 0x007C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Temp_bool_Variable;                                // 0x0080(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_81[0x3];                                       // 0x0081(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_GetTimeSinceMatchStarted_ReturnValue;     // 0x0084(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EGolfItPlayMode                               CallFunc_GetPlayMode_ReturnValue;                  // 0x0088(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EGolfItGameType                               CallFunc_GetGameType_ReturnValue;                  // 0x0089(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_NotEqual_ByteByte_ReturnValue;            // 0x008A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_SwitchEnum_CmpSuccess;                      // 0x008B(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	float                                         CallFunc_GetTimeLeftForHole_ReturnValue;           // 0x008C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           CallFunc_GetTimerColor_Color;                      // 0x0090(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FSlateColor                            K2Node_MakeStruct_SlateColor;                      // 0x00A0(0x0028)()
	int32                                         CallFunc_GetPracticeHole_ReturnValue;              // 0x00C8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EGolfItPlayMode                               CallFunc_GetPlayMode_ReturnValue_1;                // 0x00CC(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue_2;                    // 0x00CD(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_EqualEqual_ByteByte_ReturnValue;          // 0x00CE(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BooleanAND_ReturnValue;                   // 0x00CF(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	int32                                         K2Node_CustomEvent_LastHole;                       // 0x00D0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         K2Node_CustomEvent_NextHole;                       // 0x00D4(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         K2Node_CustomEvent_Hole;                           // 0x00D8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         K2Node_Select_Default;                             // 0x00DC(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData;              // 0x00E0(0x0040)(HasGetValueTypeHash)
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData_1;            // 0x0120(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array;                            // 0x0160(0x0010)(ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue;                       // 0x0170(0x0018)()
	float                                         CallFunc_GetTimeSinceMatchStarted_ReturnValue_1;   // 0x0188(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_18C[0x4];                                      // 0x018C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 CallFunc_TimeSecondsToString_ReturnValue;          // 0x0190(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class FText                                   CallFunc_Conv_StringToText_ReturnValue;            // 0x01A0(0x0018)()
	EGolfItPlayMode                               CallFunc_GetPlayMode_ReturnValue_2;                // 0x01B8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_1B9[0x7];                                      // 0x01B9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_MakeLiteralText_ReturnValue;              // 0x01C0(0x0018)()
	bool                                          CallFunc_EqualEqual_ByteByte_ReturnValue_1;        // 0x01D8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1D9[0x7];                                      // 0x01D9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData_2;            // 0x01E0(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array_1;                          // 0x0220(0x0010)(ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue_1;                     // 0x0230(0x0018)()
};

}


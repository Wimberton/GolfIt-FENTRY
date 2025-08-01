#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_Options_LiveSplit

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "SlateCore_structs.hpp"
#include "GolfItSteam_structs.hpp"


namespace SDK::Params
{

// Function WB_Options_LiveSplit.WB_Options_LiveSplit_C.BndEvt__WB_Options_LiveSplit_Checkbox_MapSplitting_K2Node_ComponentBoundEvent_8_OnValueChanged__DelegateSignature
// 0x0001 (0x0001 - 0x0000)
struct WB_Options_LiveSplit_C_BndEvt__WB_Options_LiveSplit_Checkbox_MapSplitting_K2Node_ComponentBoundEvent_8_OnValueChanged__DelegateSignature final
{
public:
	bool                                          Value;                                             // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function WB_Options_LiveSplit.WB_Options_LiveSplit_C.BndEvt__WB_Options_LiveSplit_Checkbox_ResetOnMapChange_K2Node_ComponentBoundEvent_9_OnValueChanged__DelegateSignature
// 0x0001 (0x0001 - 0x0000)
struct WB_Options_LiveSplit_C_BndEvt__WB_Options_LiveSplit_Checkbox_ResetOnMapChange_K2Node_ComponentBoundEvent_9_OnValueChanged__DelegateSignature final
{
public:
	bool                                          Value;                                             // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function WB_Options_LiveSplit.WB_Options_LiveSplit_C.BndEvt__WB_Options_LiveSplit_Text_Port_K2Node_ComponentBoundEvent_10_OnTextChanged__DelegateSignature
// 0x0020 (0x0020 - 0x0000)
struct WB_Options_LiveSplit_C_BndEvt__WB_Options_LiveSplit_Text_Port_K2Node_ComponentBoundEvent_10_OnTextChanged__DelegateSignature final
{
public:
	class FText                                   Value;                                             // 0x0000(0x0018)(BlueprintVisible, BlueprintReadOnly, Parm)
	ETextCommit                                   Commit_Method;                                     // 0x0018(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function WB_Options_LiveSplit.WB_Options_LiveSplit_C.BndEvt__WB_Options_LiveSplit_Checkbox_WaitForSplit_K2Node_ComponentBoundEvent_0_OnValueChanged__DelegateSignature
// 0x0001 (0x0001 - 0x0000)
struct WB_Options_LiveSplit_C_BndEvt__WB_Options_LiveSplit_Checkbox_WaitForSplit_K2Node_ComponentBoundEvent_0_OnValueChanged__DelegateSignature final
{
public:
	bool                                          Value;                                             // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function WB_Options_LiveSplit.WB_Options_LiveSplit_C.ExecuteUbergraph_WB_Options_LiveSplit
// 0x0170 (0x0170 - 0x0000)
struct WB_Options_LiveSplit_C_ExecuteUbergraph_WB_Options_LiveSplit final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ECheckBoxState                                Temp_byte_Variable;                                // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ECheckBoxState                                Temp_byte_Variable_1;                              // 0x0005(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ECheckBoxState                                Temp_byte_Variable_2;                              // 0x0006(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_7[0x1];                                        // 0x0007(0x0001)(Fixing Size After Last Property [ Dumper-7 ])
	class UGolfItCommonGameInstanceSubsystem*     CallFunc_GetGameInstanceSubsystem_ReturnValue;     // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsLiveSplitConnectionActive_ReturnValue;  // 0x0010(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Temp_bool_Variable;                                // 0x0011(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_12[0x6];                                       // 0x0012(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   Temp_text_Variable;                                // 0x0018(0x0018)()
	class FText                                   Temp_text_Variable_1;                              // 0x0030(0x0018)()
	bool                                          Temp_bool_Variable_1;                              // 0x0048(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_49[0x7];                                       // 0x0049(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   K2Node_Select_Default;                             // 0x0050(0x0018)()
	ESteamInventoryItemRarity                     Temp_byte_Variable_3;                              // 0x0068(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ESteamInventoryItemRarity                     Temp_byte_Variable_4;                              // 0x0069(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Temp_bool_Variable_2;                              // 0x006A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	ESteamInventoryItemRarity                     K2Node_Select_Default_1;                           // 0x006B(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ECheckBoxState                                Temp_byte_Variable_5;                              // 0x006C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_6D[0x3];                                       // 0x006D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FLinearColor                           CallFunc_GetRarityColor_Color;                     // 0x0070(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FSlateColor                            K2Node_MakeStruct_SlateColor;                      // 0x0080(0x0028)()
	ECheckBoxState                                Temp_byte_Variable_6;                              // 0x00A8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Temp_bool_Variable_3;                              // 0x00A9(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_AA[0x6];                                       // 0x00AA(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class UGolfItUserSettings*                    CallFunc_GetGolfItUserSettings_ReturnValue;        // 0x00B0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsLiveSplitResetOnMapChangeEnabled_ReturnValue; // 0x00B8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_B9[0x7];                                       // 0x00B9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UGolfItUserSettings*                    CallFunc_GetGolfItUserSettings_ReturnValue_1;      // 0x00C0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_GetLiveSplitPort_ReturnValue;             // 0x00C8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ECheckBoxState                                K2Node_Select_Default_2;                           // 0x00CC(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_CD[0x3];                                       // 0x00CD(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_Conv_IntToText_ReturnValue;               // 0x00D0(0x0018)()
	ECheckBoxState                                Temp_byte_Variable_7;                              // 0x00E8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_ComponentBoundEvent_Value_3;                // 0x00E9(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_ComponentBoundEvent_Value_2;                // 0x00EA(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_EB[0x5];                                       // 0x00EB(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   K2Node_ComponentBoundEvent_Value_1;                // 0x00F0(0x0018)()
	ETextCommit                                   K2Node_ComponentBoundEvent_Commit_Method;          // 0x0108(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_109[0x7];                                      // 0x0109(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UGolfItUserSettings*                    CallFunc_GetGolfItUserSettings_ReturnValue_2;      // 0x0110(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FString                                 CallFunc_Conv_TextToString_ReturnValue;            // 0x0118(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	int32                                         CallFunc_Conv_StringToInt_ReturnValue;             // 0x0128(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_12C[0x4];                                      // 0x012C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UGolfItUserSettings*                    CallFunc_GetGolfItUserSettings_ReturnValue_3;      // 0x0130(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Temp_bool_Variable_4;                              // 0x0138(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_139[0x7];                                      // 0x0139(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UGolfItUserSettings*                    CallFunc_GetGolfItUserSettings_ReturnValue_4;      // 0x0140(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UGolfItUserSettings*                    CallFunc_GetGolfItUserSettings_ReturnValue_5;      // 0x0148(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsLiveSplitMapTracking_ReturnValue;       // 0x0150(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	ECheckBoxState                                K2Node_Select_Default_3;                           // 0x0151(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_ComponentBoundEvent_Value;                  // 0x0152(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_153[0x5];                                      // 0x0153(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	class UGolfItUserSettings*                    CallFunc_GetGolfItUserSettings_ReturnValue_6;      // 0x0158(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UGolfItUserSettings*                    CallFunc_GetGolfItUserSettings_ReturnValue_7;      // 0x0160(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsLiveSplitPauseWaitForAllPlayersEnabled_ReturnValue; // 0x0168(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	ECheckBoxState                                K2Node_Select_Default_4;                           // 0x0169(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}


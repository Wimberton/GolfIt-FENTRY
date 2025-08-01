#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_Options_BallSettings_Coins

#include "Basic.hpp"

#include "SlateCore_structs.hpp"
#include "GolfItSteam_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function WB_Options_BallSettings_Coins.WB_Options_BallSettings_Coins_C.OnDragOver
// 0x00E0 (0x00E0 - 0x0000)
struct WB_Options_BallSettings_Coins_C_OnDragOver final
{
public:
	struct FGeometry                              MyGeometry;                                        // 0x0000(0x0038)(BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
	struct FPointerEvent                          PointerEvent;                                      // 0x0038(0x0070)(BlueprintVisible, BlueprintReadOnly, Parm)
	class UDragDropOperation*                     Operation;                                         // 0x00A8(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ReturnValue;                                       // 0x00B0(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)
	uint8                                         Pad_B1[0x7];                                       // 0x00B1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UWB_Tile_Item_C*                        K2Node_DynamicCast_AsWB_Tile_Item;                 // 0x00B8(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x00C0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_C1[0x7];                                       // 0x00C1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UObject*                                CallFunc_GetObjectFromPrimaryAssetId_ReturnValue;  // 0x00C8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UGolfItInventoryItemDataAsset*          K2Node_DynamicCast_AsGolf_It_Inventory_Item_Data_Asset; // 0x00D0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess_1;                     // 0x00D8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	ESteamInventoryItemRarity                     CallFunc_GetRarity_ReturnValue;                    // 0x00D9(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_DA[0x2];                                       // 0x00DA(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_GetRewardByRarity_Reward;                 // 0x00DC(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function WB_Options_BallSettings_Coins.WB_Options_BallSettings_Coins_C.OnDrop
// 0x00C8 (0x00C8 - 0x0000)
struct WB_Options_BallSettings_Coins_C_OnDrop final
{
public:
	struct FGeometry                              MyGeometry;                                        // 0x0000(0x0038)(BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
	struct FPointerEvent                          PointerEvent;                                      // 0x0038(0x0070)(BlueprintVisible, BlueprintReadOnly, Parm)
	class UDragDropOperation*                     Operation;                                         // 0x00A8(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ReturnValue;                                       // 0x00B0(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)
	uint8                                         Pad_B1[0x7];                                       // 0x00B1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UWB_Tile_Item_C*                        K2Node_DynamicCast_AsWB_Tile_Item;                 // 0x00B8(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x00C0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function WB_Options_BallSettings_Coins.WB_Options_BallSettings_Coins_C.SetValue
// 0x0004 (0x0004 - 0x0000)
struct WB_Options_BallSettings_Coins_C_SetValue final
{
public:
	int32                                         NewValue;                                          // 0x0000(0x0004)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function WB_Options_BallSettings_Coins.WB_Options_BallSettings_Coins_C.ShowPrice
// 0x0004 (0x0004 - 0x0000)
struct WB_Options_BallSettings_Coins_C_ShowPrice final
{
public:
	int32                                         Price;                                             // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function WB_Options_BallSettings_Coins.WB_Options_BallSettings_Coins_C.OnDragLeave
// 0x0078 (0x0078 - 0x0000)
struct WB_Options_BallSettings_Coins_C_OnDragLeave final
{
public:
	struct FPointerEvent                          PointerEvent;                                      // 0x0000(0x0070)(BlueprintVisible, BlueprintReadOnly, Parm)
	class UDragDropOperation*                     Operation;                                         // 0x0070(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function WB_Options_BallSettings_Coins.WB_Options_BallSettings_Coins_C.ExecuteUbergraph_WB_Options_BallSettings_Coins
// 0x00F8 (0x00F8 - 0x0000)
struct WB_Options_BallSettings_Coins_C_ExecuteUbergraph_WB_Options_BallSettings_Coins final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         K2Node_CustomEvent_NewValue;                       // 0x0004(0x0004)(ConstParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         K2Node_CustomEvent_Price;                          // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_C[0x4];                                        // 0x000C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData;              // 0x0010(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array;                            // 0x0050(0x0010)(ReferenceParm)
	float                                         CallFunc_Conv_IntToFloat_ReturnValue;              // 0x0060(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_64[0x4];                                       // 0x0064(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_Format_ReturnValue;                       // 0x0068(0x0018)()
	struct FPointerEvent                          K2Node_Event_PointerEvent;                         // 0x0080(0x0070)()
	class UDragDropOperation*                     K2Node_Event_Operation;                            // 0x00F0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function WB_Options_BallSettings_Coins.WB_Options_BallSettings_Coins_C.OnItemDropped__DelegateSignature
// 0x0008 (0x0008 - 0x0000)
struct WB_Options_BallSettings_Coins_C_OnItemDropped__DelegateSignature final
{
public:
	class UWB_Tile_Item_C*                        Tile;                                              // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}


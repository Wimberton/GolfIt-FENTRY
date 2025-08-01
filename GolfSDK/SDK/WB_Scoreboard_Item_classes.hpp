#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_Scoreboard_Item

#include "Basic.hpp"

#include "UMG_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "SlateCore_structs.hpp"
#include "Engine_structs.hpp"
#include "CommonUI_structs.hpp"
#include "CommonUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WB_Scoreboard_Item.WB_Scoreboard_Item_C
// 0x0050 (0x02D8 - 0x0288)
class UWB_Scoreboard_Item_C final : public UCommonUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0288(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UBorder*                                Border_Background;                                 // 0x0290(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       NotFinishedDot;                                    // 0x0298(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonNumericTextBlock*                Numeric_Value;                                     // 0x02A0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	float                                         Value;                                             // 0x02A8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	bool                                          IsAlternate;                                       // 0x02AC(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn)
	uint8                                         Pad_2AD[0x3];                                      // 0x02AD(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FLinearColor                           Color;                                             // 0x02B0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	struct FMargin                                ValuePadding;                                      // 0x02C0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn)
	ESlateVisibility                              ValueVisibility;                                   // 0x02D0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	bool                                          NotFinished;                                       // 0x02D1(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn)

public:
	void SetValueVisibility(ESlateVisibility InVisibility);
	void SetColor(const struct FLinearColor& Param_Color);
	void SetType(ECommonNumericType NumericType);
	void GetValue(float* Current_Numeric_Value);
	void SetValue(const float NewValue);
	void BP_OnEntryReleased();
	void BP_OnItemExpansionChanged(bool bIsExpanded);
	void BP_OnItemSelectionChanged(bool bIsSelected);
	void OnListItemObjectSet(class UObject* ListItemObject);
	void ExecuteUbergraph_WB_Scoreboard_Item(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WB_Scoreboard_Item_C">();
	}
	static class UWB_Scoreboard_Item_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWB_Scoreboard_Item_C>();
	}
};

}


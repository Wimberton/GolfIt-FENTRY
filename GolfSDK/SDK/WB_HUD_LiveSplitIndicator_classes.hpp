#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_HUD_LiveSplitIndicator

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GolfIt_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WB_HUD_LiveSplitIndicator.WB_HUD_LiveSplitIndicator_C
// 0x0020 (0x0358 - 0x0338)
class UWB_HUD_LiveSplitIndicator_C final : public UGolfItActivatableWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0338(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       LiveSplitAnimation;                                // 0x0340(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class USizeBox*                               LiveSplit_Sizebox;                                 // 0x0348(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 LiveSplitIndicator;                                // 0x0350(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void StartIndicatorFlashing();
	void ExecuteUbergraph_WB_HUD_LiveSplitIndicator(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WB_HUD_LiveSplitIndicator_C">();
	}
	static class UWB_HUD_LiveSplitIndicator_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWB_HUD_LiveSplitIndicator_C>();
	}
};

}


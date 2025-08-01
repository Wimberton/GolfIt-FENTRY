#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_SettingsEntry_Base

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CommonUI_structs.hpp"
#include "GolfIt_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WB_SettingsEntry_Base.WB_SettingsEntry_Base_C
// 0x0010 (0x0318 - 0x0308)
class UWB_SettingsEntry_Base_C : public UGolfItSettingsWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0308(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	EInputActionState                             InputActionState;                                  // 0x0310(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)

public:
	void PreConstruct(bool IsDesignTime);
	void ExecuteUbergraph_WB_SettingsEntry_Base(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WB_SettingsEntry_Base_C">();
	}
	static class UWB_SettingsEntry_Base_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWB_SettingsEntry_Base_C>();
	}
};

}


#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_HUD_Lobby

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GolfIt_structs.hpp"
#include "GolfIt_classes.hpp"
#include "CommonInput_structs.hpp"
#include "UMG_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WB_HUD_Lobby.WB_HUD_Lobby_C
// 0x0020 (0x0358 - 0x0338)
class UWB_HUD_Lobby_C final : public UGolfItActivatableWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0338(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWB_BoundActionBar_Menu_C*              ActionBar;                                         // 0x0340(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWB_Button_Icon_C*                      Button_Options;                                    // 0x0348(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWB_Chat_C*                             WB_Chat;                                           // 0x0350(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void BP_OnActivated();
	void BndEvt__WB_HUD_Lobby_Button_Options_K2Node_ComponentBoundEvent_0_CommonButtonBaseClicked__DelegateSignature(class UCommonButtonBase* Button);
	void OnOptionsDeactivated();
	void OnInputTypeChanged(ECommonInputType NewInputType);
	void ExecuteUbergraph_WB_HUD_Lobby(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WB_HUD_Lobby_C">();
	}
	static class UWB_HUD_Lobby_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWB_HUD_Lobby_C>();
	}
};

}


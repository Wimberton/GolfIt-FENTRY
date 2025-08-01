#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_Lobby_Friends

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GolfIt_structs.hpp"
#include "GolfIt_classes.hpp"
#include "GolfItSteam_structs.hpp"
#include "UMG_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WB_Lobby_Friends.WB_Lobby_Friends_C
// 0x0038 (0x0370 - 0x0338)
class UWB_Lobby_Friends_C final : public UGolfItActivatableWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0338(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UVerticalBox*                           Box_Error;                                         // 0x0340(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWB_Button_Default_C*                   Button_Back;                                       // 0x0348(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UGolfItListView*                        List_Friends;                                      // 0x0350(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	TArray<struct FSteamFriend>                   CachedFriends;                                     // 0x0358(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGolfItActionBindingHandle             InputActionInviteHandle;                           // 0x0368(0x0004)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)

public:
	void ExecuteUbergraph_WB_Lobby_Friends(int32 EntryPoint);
	void OnInputActionInvite(class FName ActionName);
	void BndEvt__WB_Lobby_Friends_List_Friends_K2Node_ComponentBoundEvent_3_OnListItemSelectionChangedDynamic__DelegateSignature(class UObject* Item, bool bIsSelected);
	void BP_OnDeactivated();
	void BndEvt__WB_Lobby_Friends_WB_Button_Default_K2Node_ComponentBoundEvent_0_CommonButtonBaseClicked__DelegateSignature(class UCommonButtonBase* Button);
	void BP_OnActivated();
	void Construct();
	void MOnReadFriendListDoneDelegate_398D41F04B305CF819250A9F72D75507(const TArray<struct FSteamFriend>& Friends, bool Success);
	bool BP_OnHandleBackAction();

	class UWidget* BP_GetDesiredFocusTarget() const;

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WB_Lobby_Friends_C">();
	}
	static class UWB_Lobby_Friends_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWB_Lobby_Friends_C>();
	}
};

}


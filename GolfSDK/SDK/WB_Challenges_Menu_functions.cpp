#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_Challenges_Menu

#include "Basic.hpp"

#include "WB_Challenges_Menu_classes.hpp"
#include "WB_Challenges_Menu_parameters.hpp"


namespace SDK
{

// Function WB_Challenges_Menu.WB_Challenges_Menu_C.DisplayErrors
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    HasErrors                                              (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWB_Challenges_Menu_C::DisplayErrors(bool* HasErrors)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Challenges_Menu_C", "DisplayErrors");

	Params::WB_Challenges_Menu_C_DisplayErrors Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (HasErrors != nullptr)
		*HasErrors = Parms.HasErrors;
}


// Function WB_Challenges_Menu.WB_Challenges_Menu_C.ChangeChallengeVisibility
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// ESlateVisibility                        Param_Visibility                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Challenges_Menu_C::ChangeChallengeVisibility(ESlateVisibility Param_Visibility)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Challenges_Menu_C", "ChangeChallengeVisibility");

	Params::WB_Challenges_Menu_C_ChangeChallengeVisibility Parms{};

	Parms.Param_Visibility = Param_Visibility;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Challenges_Menu.WB_Challenges_Menu_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UWB_Challenges_Menu_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Challenges_Menu_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Challenges_Menu.WB_Challenges_Menu_C.BndEvt__WB_Challenges_Menu_ExpandableArea_103_K2Node_ComponentBoundEvent_0_OnExpandableAreaExpansionChanged__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UExpandableArea*                  Area                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    bIsExpanded                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWB_Challenges_Menu_C::BndEvt__WB_Challenges_Menu_ExpandableArea_103_K2Node_ComponentBoundEvent_0_OnExpandableAreaExpansionChanged__DelegateSignature(class UExpandableArea* Area, bool bIsExpanded)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Challenges_Menu_C", "BndEvt__WB_Challenges_Menu_ExpandableArea_103_K2Node_ComponentBoundEvent_0_OnExpandableAreaExpansionChanged__DelegateSignature");

	Params::WB_Challenges_Menu_C_BndEvt__WB_Challenges_Menu_ExpandableArea_103_K2Node_ComponentBoundEvent_0_OnExpandableAreaExpansionChanged__DelegateSignature Parms{};

	Parms.Area = Area;
	Parms.bIsExpanded = bIsExpanded;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Challenges_Menu.WB_Challenges_Menu_C.CreateChallenges
// (BlueprintCallable, BlueprintEvent)

void UWB_Challenges_Menu_C::CreateChallenges()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Challenges_Menu_C", "CreateChallenges");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Challenges_Menu.WB_Challenges_Menu_C.OnFailedToGetSteamToken
// (BlueprintCallable, BlueprintEvent)

void UWB_Challenges_Menu_C::OnFailedToGetSteamToken()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Challenges_Menu_C", "OnFailedToGetSteamToken");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Challenges_Menu.WB_Challenges_Menu_C.OnReceivedAPIState
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// EChallengesAPIState                     APIState                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Challenges_Menu_C::OnReceivedAPIState(EChallengesAPIState APIState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Challenges_Menu_C", "OnReceivedAPIState");

	Params::WB_Challenges_Menu_C_OnReceivedAPIState Parms{};

	Parms.APIState = APIState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Challenges_Menu.WB_Challenges_Menu_C.ExecuteUbergraph_WB_Challenges_Menu
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Challenges_Menu_C::ExecuteUbergraph_WB_Challenges_Menu(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Challenges_Menu_C", "ExecuteUbergraph_WB_Challenges_Menu");

	Params::WB_Challenges_Menu_C_ExecuteUbergraph_WB_Challenges_Menu Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}

}


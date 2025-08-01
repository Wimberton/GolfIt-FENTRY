#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_HUD_Endgame

#include "Basic.hpp"

#include "WB_HUD_Endgame_classes.hpp"
#include "WB_HUD_Endgame_parameters.hpp"


namespace SDK
{

// Function WB_HUD_Endgame.WB_HUD_Endgame_C.BP_OnActivated
// (Event, Protected, BlueprintEvent)

void UWB_HUD_Endgame_C::BP_OnActivated()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_HUD_Endgame_C", "BP_OnActivated");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_HUD_Endgame.WB_HUD_Endgame_C.OnInputTypeChanged
// (Event, Protected, BlueprintEvent)
// Parameters:
// ECommonInputType                        NewInputType                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_HUD_Endgame_C::OnInputTypeChanged(ECommonInputType NewInputType)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_HUD_Endgame_C", "OnInputTypeChanged");

	Params::WB_HUD_Endgame_C_OnInputTypeChanged Parms{};

	Parms.NewInputType = NewInputType;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_HUD_Endgame.WB_HUD_Endgame_C.ExecuteUbergraph_WB_HUD_Endgame
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_HUD_Endgame_C::ExecuteUbergraph_WB_HUD_Endgame(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_HUD_Endgame_C", "ExecuteUbergraph_WB_HUD_Endgame");

	Params::WB_HUD_Endgame_C_ExecuteUbergraph_WB_HUD_Endgame Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_HUD_Endgame.WB_HUD_Endgame_C.BP_GetDesiredFocusTarget
// (Event, Protected, HasOutParams, BlueprintCallable, BlueprintEvent, Const)
// Parameters:
// class UWidget*                          ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

class UWidget* UWB_HUD_Endgame_C::BP_GetDesiredFocusTarget() const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_HUD_Endgame_C", "BP_GetDesiredFocusTarget");

	Params::WB_HUD_Endgame_C_BP_GetDesiredFocusTarget Parms{};

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}

}


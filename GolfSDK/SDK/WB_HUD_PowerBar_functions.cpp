#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_HUD_PowerBar

#include "Basic.hpp"

#include "WB_HUD_PowerBar_classes.hpp"
#include "WB_HUD_PowerBar_parameters.hpp"


namespace SDK
{

// Function WB_HUD_PowerBar.WB_HUD_PowerBar_C.SetPower
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Percentage                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_HUD_PowerBar_C::SetPower(float Percentage)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_HUD_PowerBar_C", "SetPower");

	Params::WB_HUD_PowerBar_C_SetPower Parms{};

	Parms.Percentage = Percentage;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_HUD_PowerBar.WB_HUD_PowerBar_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWB_HUD_PowerBar_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_HUD_PowerBar_C", "PreConstruct");

	Params::WB_HUD_PowerBar_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_HUD_PowerBar.WB_HUD_PowerBar_C.ExecuteUbergraph_WB_HUD_PowerBar
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_HUD_PowerBar_C::ExecuteUbergraph_WB_HUD_PowerBar(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_HUD_PowerBar_C", "ExecuteUbergraph_WB_HUD_PowerBar");

	Params::WB_HUD_PowerBar_C_ExecuteUbergraph_WB_HUD_PowerBar Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}

}


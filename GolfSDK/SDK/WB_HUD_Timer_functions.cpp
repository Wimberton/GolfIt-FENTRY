#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_HUD_Timer

#include "Basic.hpp"

#include "WB_HUD_Timer_classes.hpp"
#include "WB_HUD_Timer_parameters.hpp"


namespace SDK
{

// Function WB_HUD_Timer.WB_HUD_Timer_C.BP_OnActivated
// (Event, Protected, BlueprintEvent)

void UWB_HUD_Timer_C::BP_OnActivated()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_HUD_Timer_C", "BP_OnActivated");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_HUD_Timer.WB_HUD_Timer_C.Tick
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// float                                   InDeltaTime                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_HUD_Timer_C::Tick(const struct FGeometry& MyGeometry, float InDeltaTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_HUD_Timer_C", "Tick");

	Params::WB_HUD_Timer_C_Tick Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.InDeltaTime = InDeltaTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_HUD_Timer.WB_HUD_Timer_C.OnCurrentHoleChanged
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   LastHole                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   NextHole                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_HUD_Timer_C::OnCurrentHoleChanged(int32 LastHole, int32 NextHole)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_HUD_Timer_C", "OnCurrentHoleChanged");

	Params::WB_HUD_Timer_C_OnCurrentHoleChanged Parms{};

	Parms.LastHole = LastHole;
	Parms.NextHole = NextHole;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_HUD_Timer.WB_HUD_Timer_C.SetHole
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   Hole                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_HUD_Timer_C::SetHole(int32 Hole)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_HUD_Timer_C", "SetHole");

	Params::WB_HUD_Timer_C_SetHole Parms{};

	Parms.Hole = Hole;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_HUD_Timer.WB_HUD_Timer_C.ExecuteUbergraph_WB_HUD_Timer
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_HUD_Timer_C::ExecuteUbergraph_WB_HUD_Timer(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_HUD_Timer_C", "ExecuteUbergraph_WB_HUD_Timer");

	Params::WB_HUD_Timer_C_ExecuteUbergraph_WB_HUD_Timer Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}

}


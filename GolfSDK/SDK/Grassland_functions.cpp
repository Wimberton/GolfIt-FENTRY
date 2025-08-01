#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: Grassland

#include "Basic.hpp"

#include "Grassland_classes.hpp"
#include "Grassland_parameters.hpp"


namespace SDK
{

// Function Grassland.Grassland_C.ExecuteUbergraph_Grassland
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AGrassland_C::ExecuteUbergraph_Grassland(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Grassland_C", "ExecuteUbergraph_Grassland");

	Params::Grassland_C_ExecuteUbergraph_Grassland Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Grassland.Grassland_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void AGrassland_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Grassland_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Grassland.Grassland_C.SetRandomColorButterfly
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void AGrassland_C::SetRandomColorButterfly()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Grassland_C", "SetRandomColorButterfly");

	UObject::ProcessEvent(Func, nullptr);
}

}


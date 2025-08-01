#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_LoadingCustomMap

#include "Basic.hpp"

#include "WB_LoadingCustomMap_classes.hpp"
#include "WB_LoadingCustomMap_parameters.hpp"


namespace SDK
{

// Function WB_LoadingCustomMap.WB_LoadingCustomMap_C.ChangeLoadingTextAndProgressBar
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class FText                             NewText                                                (BlueprintVisible, BlueprintReadOnly, Parm)
// float                                   NewProgressValue                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_LoadingCustomMap_C::ChangeLoadingTextAndProgressBar(const class FText& NewText, float NewProgressValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_LoadingCustomMap_C", "ChangeLoadingTextAndProgressBar");

	Params::WB_LoadingCustomMap_C_ChangeLoadingTextAndProgressBar Parms{};

	Parms.NewText = std::move(NewText);
	Parms.NewProgressValue = NewProgressValue;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_LoadingCustomMap.WB_LoadingCustomMap_C.ExecuteUbergraph_WB_LoadingCustomMap
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_LoadingCustomMap_C::ExecuteUbergraph_WB_LoadingCustomMap(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_LoadingCustomMap_C", "ExecuteUbergraph_WB_LoadingCustomMap");

	Params::WB_LoadingCustomMap_C_ExecuteUbergraph_WB_LoadingCustomMap Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}

}


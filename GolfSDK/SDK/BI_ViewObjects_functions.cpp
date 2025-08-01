#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: BI_ViewObjects

#include "Basic.hpp"

#include "BI_ViewObjects_classes.hpp"
#include "BI_ViewObjects_parameters.hpp"


namespace SDK
{

// Function BI_ViewObjects.BI_ViewObjects_C.HideActor
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           ActorRef                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void IBI_ViewObjects_C::HideActor(class AActor* ActorRef)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BI_ViewObjects_C", "HideActor");

	Params::BI_ViewObjects_C_HideActor Parms{};

	Parms.ActorRef = ActorRef;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BI_ViewObjects.BI_ViewObjects_C.StopSceneRender
// (Public, BlueprintCallable, BlueprintEvent)

void IBI_ViewObjects_C::StopSceneRender()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BI_ViewObjects_C", "StopSceneRender");

	UObject::ProcessEvent(Func, nullptr);
}

}


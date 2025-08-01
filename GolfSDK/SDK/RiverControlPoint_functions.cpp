#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: RiverControlPoint

#include "Basic.hpp"

#include "RiverControlPoint_classes.hpp"
#include "RiverControlPoint_parameters.hpp"


namespace SDK
{

// Function RiverControlPoint.RiverControlPoint_C.ExecuteUbergraph_RiverControlPoint
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ARiverControlPoint_C::ExecuteUbergraph_RiverControlPoint(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RiverControlPoint_C", "ExecuteUbergraph_RiverControlPoint");

	Params::RiverControlPoint_C_ExecuteUbergraph_RiverControlPoint Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function RiverControlPoint.RiverControlPoint_C.MulticastSetRiverReference
// (Net, NetReliable, NetMulticast, BlueprintCallable, BlueprintEvent)
// Parameters:
// class ARiverEditor_C*                   RiverRef                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ARiverControlPoint_C::MulticastSetRiverReference(class ARiverEditor_C* RiverRef)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RiverControlPoint_C", "MulticastSetRiverReference");

	Params::RiverControlPoint_C_MulticastSetRiverReference Parms{};

	Parms.RiverRef = RiverRef;

	UObject::ProcessEvent(Func, &Parms);
}


// Function RiverControlPoint.RiverControlPoint_C.ServerRebuildSpline
// (Net, NetReliable, NetServer, BlueprintCallable, BlueprintEvent)

void ARiverControlPoint_C::ServerRebuildSpline()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RiverControlPoint_C", "ServerRebuildSpline");

	UObject::ProcessEvent(Func, nullptr);
}


// Function RiverControlPoint.RiverControlPoint_C.ReceiveDestroyed
// (Event, Public, BlueprintEvent)

void ARiverControlPoint_C::ReceiveDestroyed()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RiverControlPoint_C", "ReceiveDestroyed");

	UObject::ProcessEvent(Func, nullptr);
}


// Function RiverControlPoint.RiverControlPoint_C.AddNewSplinePoint
// (Public, BlueprintCallable, BlueprintEvent)

void ARiverControlPoint_C::AddNewSplinePoint()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RiverControlPoint_C", "AddNewSplinePoint");

	UObject::ProcessEvent(Func, nullptr);
}


// Function RiverControlPoint.RiverControlPoint_C.LostControl
// (Public, BlueprintCallable, BlueprintEvent)

void ARiverControlPoint_C::LostControl()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RiverControlPoint_C", "LostControl");

	UObject::ProcessEvent(Func, nullptr);
}


// Function RiverControlPoint.RiverControlPoint_C.InpAxisKeyEvt_MouseWheelAxis_K2Node_InputAxisKeyEvent_0
// (BlueprintEvent)
// Parameters:
// float                                   AxisValue                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ARiverControlPoint_C::InpAxisKeyEvt_MouseWheelAxis_K2Node_InputAxisKeyEvent_0(float AxisValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RiverControlPoint_C", "InpAxisKeyEvt_MouseWheelAxis_K2Node_InputAxisKeyEvent_0");

	Params::RiverControlPoint_C_InpAxisKeyEvt_MouseWheelAxis_K2Node_InputAxisKeyEvent_0 Parms{};

	Parms.AxisValue = AxisValue;

	UObject::ProcessEvent(Func, &Parms);
}


// Function RiverControlPoint.RiverControlPoint_C.ReceiveTick
// (Event, Public, BlueprintEvent)
// Parameters:
// float                                   DeltaSeconds                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ARiverControlPoint_C::ReceiveTick(float DeltaSeconds)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RiverControlPoint_C", "ReceiveTick");

	Params::RiverControlPoint_C_ReceiveTick Parms{};

	Parms.DeltaSeconds = DeltaSeconds;

	UObject::ProcessEvent(Func, &Parms);
}


// Function RiverControlPoint.RiverControlPoint_C.ControlPointMoved
// (Public, BlueprintCallable, BlueprintEvent)

void ARiverControlPoint_C::ControlPointMoved()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RiverControlPoint_C", "ControlPointMoved");

	UObject::ProcessEvent(Func, nullptr);
}


// Function RiverControlPoint.RiverControlPoint_C.CheckIfRiverControlPoint
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class ARiverControlPoint_C*             Ref                                                    (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ARiverControlPoint_C::CheckIfRiverControlPoint(class ARiverControlPoint_C** Ref)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RiverControlPoint_C", "CheckIfRiverControlPoint");

	Params::RiverControlPoint_C_CheckIfRiverControlPoint Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Ref != nullptr)
		*Ref = Parms.Ref;
}

}


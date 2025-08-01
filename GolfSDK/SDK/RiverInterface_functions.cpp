#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: RiverInterface

#include "Basic.hpp"

#include "RiverInterface_classes.hpp"
#include "RiverInterface_parameters.hpp"


namespace SDK
{

// Function RiverInterface.RiverInterface_C.CheckIfRiverControlPoint
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class ARiverControlPoint_C*             Ref                                                    (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void IRiverInterface_C::CheckIfRiverControlPoint(class ARiverControlPoint_C** Ref)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RiverInterface_C", "CheckIfRiverControlPoint");

	Params::RiverInterface_C_CheckIfRiverControlPoint Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Ref != nullptr)
		*Ref = Parms.Ref;
}


// Function RiverInterface.RiverInterface_C.AddNewSplinePoint
// (Public, BlueprintCallable, BlueprintEvent)

void IRiverInterface_C::AddNewSplinePoint()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RiverInterface_C", "AddNewSplinePoint");

	UObject::ProcessEvent(Func, nullptr);
}


// Function RiverInterface.RiverInterface_C.ControlPointMoved
// (Public, BlueprintCallable, BlueprintEvent)

void IRiverInterface_C::ControlPointMoved()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RiverInterface_C", "ControlPointMoved");

	UObject::ProcessEvent(Func, nullptr);
}


// Function RiverInterface.RiverInterface_C.LostControl
// (Public, BlueprintCallable, BlueprintEvent)

void IRiverInterface_C::LostControl()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("RiverInterface_C", "LostControl");

	UObject::ProcessEvent(Func, nullptr);
}

}


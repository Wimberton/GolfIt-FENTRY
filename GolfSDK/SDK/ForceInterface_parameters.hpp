#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: ForceInterface

#include "Basic.hpp"


namespace SDK::Params
{

// Function ForceInterface.ForceInterface_C.NewVisibility
// 0x0001 (0x0001 - 0x0000)
struct ForceInterface_C_NewVisibility final
{
public:
	bool                                          Visibility;                                        // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function ForceInterface.ForceInterface_C.ActivateForce
// 0x0001 (0x0001 - 0x0000)
struct ForceInterface_C_ActivateForce final
{
public:
	bool                                          NewActivation;                                     // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function ForceInterface.ForceInterface_C.GetForce
// 0x0004 (0x0004 - 0x0000)
struct ForceInterface_C_GetForce final
{
public:
	float                                         Value;                                             // 0x0000(0x0004)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function ForceInterface.ForceInterface_C.NewForce
// 0x0004 (0x0004 - 0x0000)
struct ForceInterface_C_NewForce final
{
public:
	float                                         Value;                                             // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}


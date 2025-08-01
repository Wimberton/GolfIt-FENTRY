#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: SteamVR

#include "Basic.hpp"

#include "SteamVR_classes.hpp"
#include "SteamVR_parameters.hpp"


namespace SDK
{

// DelegateFunction SteamVR.SteamVRChaperoneComponent.SteamVRChaperoneEvent__DelegateSignature
// (MulticastDelegate, Public, Delegate)

void USteamVRChaperoneComponent::SteamVRChaperoneEvent__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SteamVRChaperoneComponent", "SteamVRChaperoneEvent__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function SteamVR.SteamVRChaperoneComponent.GetBounds
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// TArray<struct FVector>                  ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, NativeAccessSpecifierPublic)

TArray<struct FVector> USteamVRChaperoneComponent::GetBounds() const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SteamVRChaperoneComponent", "GetBounds");

	Params::SteamVRChaperoneComponent_GetBounds Parms{};

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function SteamVR.SteamVRFunctionLibrary.GetHandPositionAndOrientation
// (Final, Native, Static, Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintPure)
// Parameters:
// int32                                   ControllerIndex                                        (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// EControllerHand                         Hand                                                   (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// struct FVector                          OutPosition                                            (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// struct FRotator                         OutOrientation                                         (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool USteamVRFunctionLibrary::GetHandPositionAndOrientation(int32 ControllerIndex, EControllerHand Hand, struct FVector* OutPosition, struct FRotator* OutOrientation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("SteamVRFunctionLibrary", "GetHandPositionAndOrientation");

	Params::SteamVRFunctionLibrary_GetHandPositionAndOrientation Parms{};

	Parms.ControllerIndex = ControllerIndex;
	Parms.Hand = Hand;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	if (OutPosition != nullptr)
		*OutPosition = std::move(Parms.OutPosition);

	if (OutOrientation != nullptr)
		*OutOrientation = std::move(Parms.OutOrientation);

	return Parms.ReturnValue;
}


// Function SteamVR.SteamVRFunctionLibrary.GetTrackedDevicePositionAndOrientation
// (Final, Native, Static, Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintPure)
// Parameters:
// int32                                   DeviceID                                               (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// struct FVector                          OutPosition                                            (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// struct FRotator                         OutOrientation                                         (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool USteamVRFunctionLibrary::GetTrackedDevicePositionAndOrientation(int32 DeviceID, struct FVector* OutPosition, struct FRotator* OutOrientation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("SteamVRFunctionLibrary", "GetTrackedDevicePositionAndOrientation");

	Params::SteamVRFunctionLibrary_GetTrackedDevicePositionAndOrientation Parms{};

	Parms.DeviceID = DeviceID;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	if (OutPosition != nullptr)
		*OutPosition = std::move(Parms.OutPosition);

	if (OutOrientation != nullptr)
		*OutOrientation = std::move(Parms.OutOrientation);

	return Parms.ReturnValue;
}


// Function SteamVR.SteamVRFunctionLibrary.GetValidTrackedDeviceIds
// (Final, Native, Static, Public, HasOutParams, BlueprintCallable, BlueprintPure)
// Parameters:
// ESteamVRTrackedDeviceType               DeviceType                                             (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// TArray<int32>                           OutTrackedDeviceIds                                    (Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)

void USteamVRFunctionLibrary::GetValidTrackedDeviceIds(ESteamVRTrackedDeviceType DeviceType, TArray<int32>* OutTrackedDeviceIds)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("SteamVRFunctionLibrary", "GetValidTrackedDeviceIds");

	Params::SteamVRFunctionLibrary_GetValidTrackedDeviceIds Parms{};

	Parms.DeviceType = DeviceType;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	if (OutTrackedDeviceIds != nullptr)
		*OutTrackedDeviceIds = std::move(Parms.OutTrackedDeviceIds);
}


// Function SteamVR.SteamVRHQStereoLayerShape.SetAntiAlias
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// bool                                    InAntiAlias                                            (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void USteamVRHQStereoLayerShape::SetAntiAlias(bool InAntiAlias)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SteamVRHQStereoLayerShape", "SetAntiAlias");

	Params::SteamVRHQStereoLayerShape_SetAntiAlias Parms{};

	Parms.InAntiAlias = InAntiAlias;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function SteamVR.SteamVRHQStereoLayerShape.SetAutoCurveMaxDistance
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// float                                   InDistance                                             (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void USteamVRHQStereoLayerShape::SetAutoCurveMaxDistance(float InDistance)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SteamVRHQStereoLayerShape", "SetAutoCurveMaxDistance");

	Params::SteamVRHQStereoLayerShape_SetAutoCurveMaxDistance Parms{};

	Parms.InDistance = InDistance;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function SteamVR.SteamVRHQStereoLayerShape.SetAutoCurveMinDistance
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// float                                   InDistance                                             (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void USteamVRHQStereoLayerShape::SetAutoCurveMinDistance(float InDistance)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SteamVRHQStereoLayerShape", "SetAutoCurveMinDistance");

	Params::SteamVRHQStereoLayerShape_SetAutoCurveMinDistance Parms{};

	Parms.InDistance = InDistance;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function SteamVR.SteamVRHQStereoLayerShape.SetCurved
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// bool                                    InCurved                                               (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void USteamVRHQStereoLayerShape::SetCurved(bool InCurved)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SteamVRHQStereoLayerShape", "SetCurved");

	Params::SteamVRHQStereoLayerShape_SetCurved Parms{};

	Parms.InCurved = InCurved;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}

}


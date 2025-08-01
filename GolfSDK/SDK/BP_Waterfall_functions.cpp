#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: BP_Waterfall

#include "Basic.hpp"

#include "BP_Waterfall_classes.hpp"
#include "BP_Waterfall_parameters.hpp"


namespace SDK
{

// Function BP_Waterfall.BP_Waterfall_C.ExecuteUbergraph_BP_Waterfall
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_Waterfall_C::ExecuteUbergraph_BP_Waterfall(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Waterfall_C", "ExecuteUbergraph_BP_Waterfall");

	Params::BP_Waterfall_C_ExecuteUbergraph_BP_Waterfall Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_Waterfall.BP_Waterfall_C.OnColorChanged
// (Event, Protected, BlueprintCallable, BlueprintEvent)

void ABP_Waterfall_C::OnColorChanged()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Waterfall_C", "OnColorChanged");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_Waterfall.BP_Waterfall_C.OnSettingsChanged
// (Event, Protected, BlueprintCallable, BlueprintEvent)

void ABP_Waterfall_C::OnSettingsChanged()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Waterfall_C", "OnSettingsChanged");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_Waterfall.BP_Waterfall_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void ABP_Waterfall_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Waterfall_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_Waterfall.BP_Waterfall_C.SetWaterColor
// (Public, BlueprintCallable, BlueprintEvent)

void ABP_Waterfall_C::SetWaterColor()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Waterfall_C", "SetWaterColor");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_Waterfall.BP_Waterfall_C.GetWaterColor
// (Public, BlueprintCallable, BlueprintEvent)

void ABP_Waterfall_C::GetWaterColor()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Waterfall_C", "GetWaterColor");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_Waterfall.BP_Waterfall_C.UseBuoyancy
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Buoyancy                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ABP_Waterfall_C::UseBuoyancy(bool Buoyancy)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Waterfall_C", "UseBuoyancy");

	Params::BP_Waterfall_C_UseBuoyancy Parms{};

	Parms.Buoyancy = Buoyancy;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_Waterfall.BP_Waterfall_C.SetWaterVisibility
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    NewVisibility                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// int32                                   MaterialIndex                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_Waterfall_C::SetWaterVisibility(bool NewVisibility, int32 MaterialIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Waterfall_C", "SetWaterVisibility");

	Params::BP_Waterfall_C_SetWaterVisibility Parms{};

	Parms.NewVisibility = NewVisibility;
	Parms.MaterialIndex = MaterialIndex;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_Waterfall.BP_Waterfall_C.UpdateMaterialScalarSettings
// (Public, BlueprintCallable, BlueprintEvent)

void ABP_Waterfall_C::UpdateMaterialScalarSettings()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Waterfall_C", "UpdateMaterialScalarSettings");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_Waterfall.BP_Waterfall_C.UpdateMaterialColorSettings
// (Public, BlueprintCallable, BlueprintEvent)

void ABP_Waterfall_C::UpdateMaterialColorSettings()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Waterfall_C", "UpdateMaterialColorSettings");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_Waterfall.BP_Waterfall_C.GetBuoyancy
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Buoyancy                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ABP_Waterfall_C::GetBuoyancy(bool* Buoyancy)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Waterfall_C", "GetBuoyancy");

	Params::BP_Waterfall_C_GetBuoyancy Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Buoyancy != nullptr)
		*Buoyancy = Parms.Buoyancy;
}


// Function BP_Waterfall.BP_Waterfall_C.GetIsCameraInUnderwaterEffectSphere
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Yes                                                    (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ABP_Waterfall_C::GetIsCameraInUnderwaterEffectSphere(bool* Yes)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Waterfall_C", "GetIsCameraInUnderwaterEffectSphere");

	Params::BP_Waterfall_C_GetIsCameraInUnderwaterEffectSphere Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Yes != nullptr)
		*Yes = Parms.Yes;
}


// Function BP_Waterfall.BP_Waterfall_C.GetWaterVisibility
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    IsVisible                                              (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
// int32                                   MaterialIndex                                          (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_Waterfall_C::GetWaterVisibility(bool* IsVisible, int32* MaterialIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Waterfall_C", "GetWaterVisibility");

	Params::BP_Waterfall_C_GetWaterVisibility Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (IsVisible != nullptr)
		*IsVisible = Parms.IsVisible;

	if (MaterialIndex != nullptr)
		*MaterialIndex = Parms.MaterialIndex;
}


// Function BP_Waterfall.BP_Waterfall_C.IsWaterObject
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AGolfBall_C*                      Ball                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UPrimitiveComponent*              HitComponent                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   ElementIndex                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    WaterObject                                            (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    UseNewWaterNormal                                      (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
// struct FVector                          NewWaterEffectNormal                                   (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    ShouldResultInReset_                                   (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    NoFX                                                   (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ABP_Waterfall_C::IsWaterObject(class AGolfBall_C* Ball, class UPrimitiveComponent* HitComponent, int32 ElementIndex, bool* WaterObject, bool* UseNewWaterNormal, struct FVector* NewWaterEffectNormal, bool* ShouldResultInReset_, bool* NoFX)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Waterfall_C", "IsWaterObject");

	Params::BP_Waterfall_C_IsWaterObject Parms{};

	Parms.Ball = Ball;
	Parms.HitComponent = HitComponent;
	Parms.ElementIndex = ElementIndex;

	UObject::ProcessEvent(Func, &Parms);

	if (WaterObject != nullptr)
		*WaterObject = Parms.WaterObject;

	if (UseNewWaterNormal != nullptr)
		*UseNewWaterNormal = Parms.UseNewWaterNormal;

	if (NewWaterEffectNormal != nullptr)
		*NewWaterEffectNormal = std::move(Parms.NewWaterEffectNormal);

	if (ShouldResultInReset_ != nullptr)
		*ShouldResultInReset_ = Parms.ShouldResultInReset_;

	if (NoFX != nullptr)
		*NoFX = Parms.NoFX;
}

}


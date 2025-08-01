#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: EditorWater

#include "Basic.hpp"

#include "EditorWater_classes.hpp"
#include "EditorWater_parameters.hpp"


namespace SDK
{

// Function EditorWater.EditorWater_C.ExecuteUbergraph_EditorWater
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AEditorWater_C::ExecuteUbergraph_EditorWater(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "ExecuteUbergraph_EditorWater");

	Params::EditorWater_C_ExecuteUbergraph_EditorWater Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function EditorWater.EditorWater_C.ChangeSettings
// (BlueprintCallable, BlueprintEvent)

void AEditorWater_C::ChangeSettings()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "ChangeSettings");

	UObject::ProcessEvent(Func, nullptr);
}


// Function EditorWater.EditorWater_C.BallLeft
// (BlueprintCallable, BlueprintEvent)

void AEditorWater_C::BallLeft()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "BallLeft");

	UObject::ProcessEvent(Func, nullptr);
}


// Function EditorWater.EditorWater_C.BallEntered
// (BlueprintCallable, BlueprintEvent)

void AEditorWater_C::BallEntered()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "BallEntered");

	UObject::ProcessEvent(Func, nullptr);
}


// Function EditorWater.EditorWater_C.OnColorChanged
// (Event, Protected, BlueprintCallable, BlueprintEvent)

void AEditorWater_C::OnColorChanged()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "OnColorChanged");

	UObject::ProcessEvent(Func, nullptr);
}


// Function EditorWater.EditorWater_C.OnSettingsChanged
// (Event, Protected, BlueprintCallable, BlueprintEvent)

void AEditorWater_C::OnSettingsChanged()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "OnSettingsChanged");

	UObject::ProcessEvent(Func, nullptr);
}


// Function EditorWater.EditorWater_C.UseBuoyancy
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Buoyancy                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AEditorWater_C::UseBuoyancy(bool Buoyancy)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "UseBuoyancy");

	Params::EditorWater_C_UseBuoyancy Parms{};

	Parms.Buoyancy = Buoyancy;

	UObject::ProcessEvent(Func, &Parms);
}


// Function EditorWater.EditorWater_C.HideMesh
// (BlueprintCallable, BlueprintEvent)

void AEditorWater_C::HideMesh()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "HideMesh");

	UObject::ProcessEvent(Func, nullptr);
}


// Function EditorWater.EditorWater_C.UpdateWaterForm
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// EWaterShape                             NewShape                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AEditorWater_C::UpdateWaterForm(EWaterShape NewShape)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "UpdateWaterForm");

	Params::EditorWater_C_UpdateWaterForm Parms{};

	Parms.NewShape = NewShape;

	UObject::ProcessEvent(Func, &Parms);
}


// Function EditorWater.EditorWater_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void AEditorWater_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function EditorWater.EditorWater_C.SetWaterColor
// (Public, BlueprintCallable, BlueprintEvent)

void AEditorWater_C::SetWaterColor()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "SetWaterColor");

	UObject::ProcessEvent(Func, nullptr);
}


// Function EditorWater.EditorWater_C.GetWaterColor
// (Public, BlueprintCallable, BlueprintEvent)

void AEditorWater_C::GetWaterColor()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "GetWaterColor");

	UObject::ProcessEvent(Func, nullptr);
}


// Function EditorWater.EditorWater_C.SetWaterVisibility
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    NewVisibility                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// int32                                   MaterialIndex                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AEditorWater_C::SetWaterVisibility(bool NewVisibility, int32 MaterialIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "SetWaterVisibility");

	Params::EditorWater_C_SetWaterVisibility Parms{};

	Parms.NewVisibility = NewVisibility;
	Parms.MaterialIndex = MaterialIndex;

	UObject::ProcessEvent(Func, &Parms);
}


// Function EditorWater.EditorWater_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void AEditorWater_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}


// Function EditorWater.EditorWater_C.UpdateMaterialScalarSettings
// (Public, BlueprintCallable, BlueprintEvent)

void AEditorWater_C::UpdateMaterialScalarSettings()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "UpdateMaterialScalarSettings");

	UObject::ProcessEvent(Func, nullptr);
}


// Function EditorWater.EditorWater_C.UpdateMaterialColorSettings
// (Public, BlueprintCallable, BlueprintEvent)

void AEditorWater_C::UpdateMaterialColorSettings()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "UpdateMaterialColorSettings");

	UObject::ProcessEvent(Func, nullptr);
}


// Function EditorWater.EditorWater_C.IsWaterObject
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

void AEditorWater_C::IsWaterObject(class AGolfBall_C* Ball, class UPrimitiveComponent* HitComponent, int32 ElementIndex, bool* WaterObject, bool* UseNewWaterNormal, struct FVector* NewWaterEffectNormal, bool* ShouldResultInReset_, bool* NoFX)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "IsWaterObject");

	Params::EditorWater_C_IsWaterObject Parms{};

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


// Function EditorWater.EditorWater_C.GetWaterVisibility
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    IsVisible                                              (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
// int32                                   MaterialIndex                                          (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AEditorWater_C::GetWaterVisibility(bool* IsVisible, int32* MaterialIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "GetWaterVisibility");

	Params::EditorWater_C_GetWaterVisibility Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (IsVisible != nullptr)
		*IsVisible = Parms.IsVisible;

	if (MaterialIndex != nullptr)
		*MaterialIndex = Parms.MaterialIndex;
}


// Function EditorWater.EditorWater_C.GetIsCameraInUnderwaterEffectSphere
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Yes                                                    (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AEditorWater_C::GetIsCameraInUnderwaterEffectSphere(bool* Yes)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "GetIsCameraInUnderwaterEffectSphere");

	Params::EditorWater_C_GetIsCameraInUnderwaterEffectSphere Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Yes != nullptr)
		*Yes = Parms.Yes;
}


// Function EditorWater.EditorWater_C.GetBuoyancy
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Buoyancy                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AEditorWater_C::GetBuoyancy(bool* Buoyancy)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EditorWater_C", "GetBuoyancy");

	Params::EditorWater_C_GetBuoyancy Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Buoyancy != nullptr)
		*Buoyancy = Parms.Buoyancy;
}

}


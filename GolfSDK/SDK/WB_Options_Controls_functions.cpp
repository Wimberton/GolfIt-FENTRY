#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_Options_Controls

#include "Basic.hpp"

#include "WB_Options_Controls_classes.hpp"
#include "WB_Options_Controls_parameters.hpp"


namespace SDK
{

// Function WB_Options_Controls.WB_Options_Controls_C.OnPutterSpeedChanged
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Value                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   ValueNormalized                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_Controls_C::OnPutterSpeedChanged(float Value, float ValueNormalized)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_Controls_C", "OnPutterSpeedChanged");

	Params::WB_Options_Controls_C_OnPutterSpeedChanged Parms{};

	Parms.Value = Value;
	Parms.ValueNormalized = ValueNormalized;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_Controls.WB_Options_Controls_C.OnAlternativeChanged
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Value                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWB_Options_Controls_C::OnAlternativeChanged(bool Value)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_Controls_C", "OnAlternativeChanged");

	Params::WB_Options_Controls_C_OnAlternativeChanged Parms{};

	Parms.Value = Value;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_Controls.WB_Options_Controls_C.OnInvertXChanged
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Value                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWB_Options_Controls_C::OnInvertXChanged(bool Value)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_Controls_C", "OnInvertXChanged");

	Params::WB_Options_Controls_C_OnInvertXChanged Parms{};

	Parms.Value = Value;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_Controls.WB_Options_Controls_C.OnInvertYChanged
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Value                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWB_Options_Controls_C::OnInvertYChanged(bool Value)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_Controls_C", "OnInvertYChanged");

	Params::WB_Options_Controls_C_OnInvertYChanged Parms{};

	Parms.Value = Value;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_Controls.WB_Options_Controls_C.ControllerPutterSpeedChanged
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Value                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   ValueNormalized                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_Controls_C::ControllerPutterSpeedChanged(float Value, float ValueNormalized)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_Controls_C", "ControllerPutterSpeedChanged");

	Params::WB_Options_Controls_C_ControllerPutterSpeedChanged Parms{};

	Parms.Value = Value;
	Parms.ValueNormalized = ValueNormalized;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_Controls.WB_Options_Controls_C.ControllerSpeedChanged
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Value                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   ValueNormalized                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_Controls_C::ControllerSpeedChanged(float Value, float ValueNormalized)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_Controls_C", "ControllerSpeedChanged");

	Params::WB_Options_Controls_C_ControllerSpeedChanged Parms{};

	Parms.Value = Value;
	Parms.ValueNormalized = ValueNormalized;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_Controls.WB_Options_Controls_C.DefaultPutterChanged
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           Option                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)

void UWB_Options_Controls_C::DefaultPutterChanged(const class FString& Option)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_Controls_C", "DefaultPutterChanged");

	Params::WB_Options_Controls_C_DefaultPutterChanged Parms{};

	Parms.Option = std::move(Option);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_Controls.WB_Options_Controls_C.ControllerPutterChanged
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           Option                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)

void UWB_Options_Controls_C::ControllerPutterChanged(const class FString& Option)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_Controls_C", "ControllerPutterChanged");

	Params::WB_Options_Controls_C_ControllerPutterChanged Parms{};

	Parms.Option = std::move(Option);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_Controls.WB_Options_Controls_C.ControllerInvertXChanged
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Value                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWB_Options_Controls_C::ControllerInvertXChanged(bool Value)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_Controls_C", "ControllerInvertXChanged");

	Params::WB_Options_Controls_C_ControllerInvertXChanged Parms{};

	Parms.Value = Value;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_Controls.WB_Options_Controls_C.ControllerInvertYChanged
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Value                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWB_Options_Controls_C::ControllerInvertYChanged(bool Value)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_Controls_C", "ControllerInvertYChanged");

	Params::WB_Options_Controls_C_ControllerInvertYChanged Parms{};

	Parms.Value = Value;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_Controls.WB_Options_Controls_C.OnInputTypeChanged
// (Event, Protected, BlueprintEvent)
// Parameters:
// ECommonInputType                        NewInputType                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_Controls_C::OnInputTypeChanged(ECommonInputType NewInputType)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_Controls_C", "OnInputTypeChanged");

	Params::WB_Options_Controls_C_OnInputTypeChanged Parms{};

	Parms.NewInputType = NewInputType;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_Controls.WB_Options_Controls_C.OnMouseSpeedChanged
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Value                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   ValueNormalized                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_Controls_C::OnMouseSpeedChanged(float Value, float ValueNormalized)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_Controls_C", "OnMouseSpeedChanged");

	Params::WB_Options_Controls_C_OnMouseSpeedChanged Parms{};

	Parms.Value = Value;
	Parms.ValueNormalized = ValueNormalized;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_Controls.WB_Options_Controls_C.BP_OnActivated
// (Event, Protected, BlueprintEvent)

void UWB_Options_Controls_C::BP_OnActivated()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_Controls_C", "BP_OnActivated");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Options_Controls.WB_Options_Controls_C.FreeCamSpeedChanged
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Value                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   ValueNormalized                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_Controls_C::FreeCamSpeedChanged(float Value, float ValueNormalized)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_Controls_C", "FreeCamSpeedChanged");

	Params::WB_Options_Controls_C_FreeCamSpeedChanged Parms{};

	Parms.Value = Value;
	Parms.ValueNormalized = ValueNormalized;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_Controls.WB_Options_Controls_C.PutterSwingChanged
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           Option                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)

void UWB_Options_Controls_C::PutterSwingChanged(const class FString& Option)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_Controls_C", "PutterSwingChanged");

	Params::WB_Options_Controls_C_PutterSwingChanged Parms{};

	Parms.Option = std::move(Option);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_Controls.WB_Options_Controls_C.ExecuteUbergraph_WB_Options_Controls
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_Controls_C::ExecuteUbergraph_WB_Options_Controls(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_Controls_C", "ExecuteUbergraph_WB_Options_Controls");

	Params::WB_Options_Controls_C_ExecuteUbergraph_WB_Options_Controls Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_Controls.WB_Options_Controls_C.BP_GetDesiredFocusTarget
// (Event, Protected, HasOutParams, BlueprintCallable, BlueprintEvent, Const)
// Parameters:
// class UWidget*                          ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

class UWidget* UWB_Options_Controls_C::BP_GetDesiredFocusTarget() const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_Controls_C", "BP_GetDesiredFocusTarget");

	Params::WB_Options_Controls_C_BP_GetDesiredFocusTarget Parms{};

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}

}


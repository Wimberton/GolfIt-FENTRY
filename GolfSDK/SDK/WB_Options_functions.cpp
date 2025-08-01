#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_Options

#include "Basic.hpp"

#include "WB_Options_classes.hpp"
#include "WB_Options_parameters.hpp"


namespace SDK
{

// Function WB_Options.WB_Options_C.DoCustomNavigation_0
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// EUINavigation                           Param_Navigation                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UWidget*                          ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

class UWidget* UWB_Options_C::DoCustomNavigation_0(EUINavigation Param_Navigation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "DoCustomNavigation_0");

	Params::WB_Options_C_DoCustomNavigation_0 Parms{};

	Parms.Param_Navigation = Param_Navigation;

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function WB_Options.WB_Options_C.SetLiveSplitVisibility
// (Public, BlueprintCallable, BlueprintEvent)

void UWB_Options_C::SetLiveSplitVisibility()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "SetLiveSplitVisibility");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Options.WB_Options_C.AbortSettings
// (Public, BlueprintCallable, BlueprintEvent)

void UWB_Options_C::AbortSettings()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "AbortSettings");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Options.WB_Options_C.SaveSettings
// (Public, BlueprintCallable, BlueprintEvent)

void UWB_Options_C::SaveSettings()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "SaveSettings");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Options.WB_Options_C.RequestContentChange
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWidget*                          New_Content                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_C::RequestContentChange(class UWidget* New_Content)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "RequestContentChange");

	Params::WB_Options_C_RequestContentChange Parms{};

	Parms.New_Content = New_Content;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options.WB_Options_C.BndEvt__WB_Options_Button_General_K2Node_ComponentBoundEvent_0_CommonButtonBaseClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButtonBase*                Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_C::BndEvt__WB_Options_Button_General_K2Node_ComponentBoundEvent_0_CommonButtonBaseClicked__DelegateSignature(class UCommonButtonBase* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "BndEvt__WB_Options_Button_General_K2Node_ComponentBoundEvent_0_CommonButtonBaseClicked__DelegateSignature");

	Params::WB_Options_C_BndEvt__WB_Options_Button_General_K2Node_ComponentBoundEvent_0_CommonButtonBaseClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options.WB_Options_C.BndEvt__WB_Options_Button_Controls_K2Node_ComponentBoundEvent_1_CommonButtonBaseClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButtonBase*                Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_C::BndEvt__WB_Options_Button_Controls_K2Node_ComponentBoundEvent_1_CommonButtonBaseClicked__DelegateSignature(class UCommonButtonBase* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "BndEvt__WB_Options_Button_Controls_K2Node_ComponentBoundEvent_1_CommonButtonBaseClicked__DelegateSignature");

	Params::WB_Options_C_BndEvt__WB_Options_Button_Controls_K2Node_ComponentBoundEvent_1_CommonButtonBaseClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options.WB_Options_C.BndEvt__WB_Options_Button_Keyboard_K2Node_ComponentBoundEvent_5_CommonButtonBaseClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButtonBase*                Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_C::BndEvt__WB_Options_Button_Keyboard_K2Node_ComponentBoundEvent_5_CommonButtonBaseClicked__DelegateSignature(class UCommonButtonBase* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "BndEvt__WB_Options_Button_Keyboard_K2Node_ComponentBoundEvent_5_CommonButtonBaseClicked__DelegateSignature");

	Params::WB_Options_C_BndEvt__WB_Options_Button_Keyboard_K2Node_ComponentBoundEvent_5_CommonButtonBaseClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options.WB_Options_C.BndEvt__WB_Options_Button_Editor_K2Node_ComponentBoundEvent_7_CommonButtonBaseClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButtonBase*                Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_C::BndEvt__WB_Options_Button_Editor_K2Node_ComponentBoundEvent_7_CommonButtonBaseClicked__DelegateSignature(class UCommonButtonBase* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "BndEvt__WB_Options_Button_Editor_K2Node_ComponentBoundEvent_7_CommonButtonBaseClicked__DelegateSignature");

	Params::WB_Options_C_BndEvt__WB_Options_Button_Editor_K2Node_ComponentBoundEvent_7_CommonButtonBaseClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options.WB_Options_C.BndEvt__WB_Options_Button_Advanced_K2Node_ComponentBoundEvent_2_CommonButtonBaseClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButtonBase*                Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_C::BndEvt__WB_Options_Button_Advanced_K2Node_ComponentBoundEvent_2_CommonButtonBaseClicked__DelegateSignature(class UCommonButtonBase* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "BndEvt__WB_Options_Button_Advanced_K2Node_ComponentBoundEvent_2_CommonButtonBaseClicked__DelegateSignature");

	Params::WB_Options_C_BndEvt__WB_Options_Button_Advanced_K2Node_ComponentBoundEvent_2_CommonButtonBaseClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options.WB_Options_C.BndEvt__WB_Options_Button_BallSettings_K2Node_ComponentBoundEvent_3_CommonButtonBaseClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButtonBase*                Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_C::BndEvt__WB_Options_Button_BallSettings_K2Node_ComponentBoundEvent_3_CommonButtonBaseClicked__DelegateSignature(class UCommonButtonBase* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "BndEvt__WB_Options_Button_BallSettings_K2Node_ComponentBoundEvent_3_CommonButtonBaseClicked__DelegateSignature");

	Params::WB_Options_C_BndEvt__WB_Options_Button_BallSettings_K2Node_ComponentBoundEvent_3_CommonButtonBaseClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options.WB_Options_C.BndEvt__WB_Options_Button_Bindings_K2Node_ComponentBoundEvent_4_CommonButtonBaseClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButtonBase*                Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_C::BndEvt__WB_Options_Button_Bindings_K2Node_ComponentBoundEvent_4_CommonButtonBaseClicked__DelegateSignature(class UCommonButtonBase* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "BndEvt__WB_Options_Button_Bindings_K2Node_ComponentBoundEvent_4_CommonButtonBaseClicked__DelegateSignature");

	Params::WB_Options_C_BndEvt__WB_Options_Button_Bindings_K2Node_ComponentBoundEvent_4_CommonButtonBaseClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options.WB_Options_C.BndEvt__WB_Options_WB_Button_Default_K2Node_ComponentBoundEvent_9_CommonButtonBaseClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButtonBase*                Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_C::BndEvt__WB_Options_WB_Button_Default_K2Node_ComponentBoundEvent_9_CommonButtonBaseClicked__DelegateSignature(class UCommonButtonBase* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "BndEvt__WB_Options_WB_Button_Default_K2Node_ComponentBoundEvent_9_CommonButtonBaseClicked__DelegateSignature");

	Params::WB_Options_C_BndEvt__WB_Options_WB_Button_Default_K2Node_ComponentBoundEvent_9_CommonButtonBaseClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options.WB_Options_C.BndEvt__WB_Options_WB_Button_Action_K2Node_ComponentBoundEvent_6_CommonButtonBaseClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButtonBase*                Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_C::BndEvt__WB_Options_WB_Button_Action_K2Node_ComponentBoundEvent_6_CommonButtonBaseClicked__DelegateSignature(class UCommonButtonBase* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "BndEvt__WB_Options_WB_Button_Action_K2Node_ComponentBoundEvent_6_CommonButtonBaseClicked__DelegateSignature");

	Params::WB_Options_C_BndEvt__WB_Options_WB_Button_Action_K2Node_ComponentBoundEvent_6_CommonButtonBaseClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options.WB_Options_C.BP_OnDeactivated
// (Event, Protected, BlueprintEvent)

void UWB_Options_C::BP_OnDeactivated()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "BP_OnDeactivated");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Options.WB_Options_C.Handle Cancel Action
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class FName                             ActionName                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_C::Handle_Cancel_Action(class FName ActionName)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "Handle Cancel Action");

	Params::WB_Options_C_Handle_Cancel_Action Parms{};

	Parms.ActionName = ActionName;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options.WB_Options_C.OnInputTypeChanged
// (Event, Protected, BlueprintEvent)
// Parameters:
// ECommonInputType                        NewInputType                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_C::OnInputTypeChanged(ECommonInputType NewInputType)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "OnInputTypeChanged");

	Params::WB_Options_C_OnInputTypeChanged Parms{};

	Parms.NewInputType = NewInputType;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options.WB_Options_C.BndEvt__WB_Options_Button_LiveSplit_K2Node_ComponentBoundEvent_8_CommonButtonBaseClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButtonBase*                Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_C::BndEvt__WB_Options_Button_LiveSplit_K2Node_ComponentBoundEvent_8_CommonButtonBaseClicked__DelegateSignature(class UCommonButtonBase* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "BndEvt__WB_Options_Button_LiveSplit_K2Node_ComponentBoundEvent_8_CommonButtonBaseClicked__DelegateSignature");

	Params::WB_Options_C_BndEvt__WB_Options_Button_LiveSplit_K2Node_ComponentBoundEvent_8_CommonButtonBaseClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options.WB_Options_C.BndEvt__WB_Options_Button_Audio_K2Node_ComponentBoundEvent_10_CommonButtonBaseClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButtonBase*                Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_C::BndEvt__WB_Options_Button_Audio_K2Node_ComponentBoundEvent_10_CommonButtonBaseClicked__DelegateSignature(class UCommonButtonBase* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "BndEvt__WB_Options_Button_Audio_K2Node_ComponentBoundEvent_10_CommonButtonBaseClicked__DelegateSignature");

	Params::WB_Options_C_BndEvt__WB_Options_Button_Audio_K2Node_ComponentBoundEvent_10_CommonButtonBaseClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options.WB_Options_C.Handle Back Action
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class FName                             ActionName                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_C::Handle_Back_Action(class FName ActionName)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "Handle Back Action");

	Params::WB_Options_C_Handle_Back_Action Parms{};

	Parms.ActionName = ActionName;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options.WB_Options_C.BndEvt__WB_Options_Button_SellAll_K2Node_ComponentBoundEvent_11_CommonButtonBaseClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButtonBase*                Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_C::BndEvt__WB_Options_Button_SellAll_K2Node_ComponentBoundEvent_11_CommonButtonBaseClicked__DelegateSignature(class UCommonButtonBase* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "BndEvt__WB_Options_Button_SellAll_K2Node_ComponentBoundEvent_11_CommonButtonBaseClicked__DelegateSignature");

	Params::WB_Options_C_BndEvt__WB_Options_Button_SellAll_K2Node_ComponentBoundEvent_11_CommonButtonBaseClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options.WB_Options_C.ExecuteUbergraph_WB_Options
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_C::ExecuteUbergraph_WB_Options(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "ExecuteUbergraph_WB_Options");

	Params::WB_Options_C_ExecuteUbergraph_WB_Options Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options.WB_Options_C.BP_OnActivated
// (Event, Protected, BlueprintEvent)

void UWB_Options_C::BP_OnActivated()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "BP_OnActivated");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Options.WB_Options_C.Handle Apply Action
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class FName                             ActionName                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_C::Handle_Apply_Action(class FName ActionName)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "Handle Apply Action");

	Params::WB_Options_C_Handle_Apply_Action Parms{};

	Parms.ActionName = ActionName;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options.WB_Options_C.BP_GetDesiredFocusTarget
// (Event, Protected, HasOutParams, BlueprintCallable, BlueprintEvent, Const)
// Parameters:
// class UWidget*                          ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

class UWidget* UWB_Options_C::BP_GetDesiredFocusTarget() const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_C", "BP_GetDesiredFocusTarget");

	Params::WB_Options_C_BP_GetDesiredFocusTarget Parms{};

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}

}


#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_Button_Tab

#include "Basic.hpp"

#include "WB_Button_Tab_classes.hpp"
#include "WB_Button_Tab_parameters.hpp"


namespace SDK
{

// Function WB_Button_Tab.WB_Button_Tab_C.SetText
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FText                             Param_Text                                             (BlueprintVisible, BlueprintReadOnly, Parm)

void UWB_Button_Tab_C::SetText(const class FText& Param_Text)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Button_Tab_C", "SetText");

	Params::WB_Button_Tab_C_SetText Parms{};

	Parms.Param_Text = std::move(Param_Text);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Button_Tab.WB_Button_Tab_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWB_Button_Tab_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Button_Tab_C", "PreConstruct");

	Params::WB_Button_Tab_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Button_Tab.WB_Button_Tab_C.BP_OnHovered
// (Event, Protected, BlueprintEvent)

void UWB_Button_Tab_C::BP_OnHovered()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Button_Tab_C", "BP_OnHovered");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Button_Tab.WB_Button_Tab_C.BP_OnUnhovered
// (Event, Protected, BlueprintEvent)

void UWB_Button_Tab_C::BP_OnUnhovered()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Button_Tab_C", "BP_OnUnhovered");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Button_Tab.WB_Button_Tab_C.BP_OnSelected
// (Event, Protected, BlueprintEvent)

void UWB_Button_Tab_C::BP_OnSelected()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Button_Tab_C", "BP_OnSelected");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Button_Tab.WB_Button_Tab_C.BP_OnDeselected
// (Event, Protected, BlueprintEvent)

void UWB_Button_Tab_C::BP_OnDeselected()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Button_Tab_C", "BP_OnDeselected");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Button_Tab.WB_Button_Tab_C.ExecuteUbergraph_WB_Button_Tab
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Button_Tab_C::ExecuteUbergraph_WB_Button_Tab(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Button_Tab_C", "ExecuteUbergraph_WB_Button_Tab");

	Params::WB_Button_Tab_C_ExecuteUbergraph_WB_Button_Tab Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}

}


#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_Options_BallSettings_Coins

#include "Basic.hpp"

#include "WB_Options_BallSettings_Coins_classes.hpp"
#include "WB_Options_BallSettings_Coins_parameters.hpp"


namespace SDK
{

// Function WB_Options_BallSettings_Coins.WB_Options_BallSettings_Coins_C.OnDragOver
// (BlueprintCosmetic, Event, Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    PointerEvent                                           (BlueprintVisible, BlueprintReadOnly, Parm)
// class UDragDropOperation*               Operation                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool UWB_Options_BallSettings_Coins_C::OnDragOver(const struct FGeometry& MyGeometry, const struct FPointerEvent& PointerEvent, class UDragDropOperation* Operation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_BallSettings_Coins_C", "OnDragOver");

	Params::WB_Options_BallSettings_Coins_C_OnDragOver Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.PointerEvent = std::move(PointerEvent);
	Parms.Operation = Operation;

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function WB_Options_BallSettings_Coins.WB_Options_BallSettings_Coins_C.OnDrop
// (BlueprintCosmetic, Event, Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    PointerEvent                                           (BlueprintVisible, BlueprintReadOnly, Parm)
// class UDragDropOperation*               Operation                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool UWB_Options_BallSettings_Coins_C::OnDrop(const struct FGeometry& MyGeometry, const struct FPointerEvent& PointerEvent, class UDragDropOperation* Operation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_BallSettings_Coins_C", "OnDrop");

	Params::WB_Options_BallSettings_Coins_C_OnDrop Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.PointerEvent = std::move(PointerEvent);
	Parms.Operation = Operation;

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function WB_Options_BallSettings_Coins.WB_Options_BallSettings_Coins_C.SetValue
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   NewValue                                               (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_BallSettings_Coins_C::SetValue(const int32 NewValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_BallSettings_Coins_C", "SetValue");

	Params::WB_Options_BallSettings_Coins_C_SetValue Parms{};

	Parms.NewValue = NewValue;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_BallSettings_Coins.WB_Options_BallSettings_Coins_C.ShowPrice
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   Price                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_BallSettings_Coins_C::ShowPrice(int32 Price)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_BallSettings_Coins_C", "ShowPrice");

	Params::WB_Options_BallSettings_Coins_C_ShowPrice Parms{};

	Parms.Price = Price;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_BallSettings_Coins.WB_Options_BallSettings_Coins_C.HidePrice
// (BlueprintCallable, BlueprintEvent)

void UWB_Options_BallSettings_Coins_C::HidePrice()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_BallSettings_Coins_C", "HidePrice");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Options_BallSettings_Coins.WB_Options_BallSettings_Coins_C.OnDragLeave
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// struct FPointerEvent                    PointerEvent                                           (BlueprintVisible, BlueprintReadOnly, Parm)
// class UDragDropOperation*               Operation                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_BallSettings_Coins_C::OnDragLeave(const struct FPointerEvent& PointerEvent, class UDragDropOperation* Operation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_BallSettings_Coins_C", "OnDragLeave");

	Params::WB_Options_BallSettings_Coins_C_OnDragLeave Parms{};

	Parms.PointerEvent = std::move(PointerEvent);
	Parms.Operation = Operation;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_BallSettings_Coins.WB_Options_BallSettings_Coins_C.ExecuteUbergraph_WB_Options_BallSettings_Coins
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_BallSettings_Coins_C::ExecuteUbergraph_WB_Options_BallSettings_Coins(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_BallSettings_Coins_C", "ExecuteUbergraph_WB_Options_BallSettings_Coins");

	Params::WB_Options_BallSettings_Coins_C_ExecuteUbergraph_WB_Options_BallSettings_Coins Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WB_Options_BallSettings_Coins.WB_Options_BallSettings_Coins_C.OnItemDropped__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWB_Tile_Item_C*                  Tile                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Options_BallSettings_Coins_C::OnItemDropped__DelegateSignature(class UWB_Tile_Item_C* Tile)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Options_BallSettings_Coins_C", "OnItemDropped__DelegateSignature");

	Params::WB_Options_BallSettings_Coins_C_OnItemDropped__DelegateSignature Parms{};

	Parms.Tile = Tile;

	UObject::ProcessEvent(Func, &Parms);
}

}


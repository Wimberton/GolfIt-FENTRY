#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_Tile_Item_Drag

#include "Basic.hpp"

#include "WB_Tile_Item_Drag_classes.hpp"
#include "WB_Tile_Item_Drag_parameters.hpp"


namespace SDK
{

// Function WB_Tile_Item_Drag.WB_Tile_Item_Drag_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UWB_Tile_Item_Drag_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Tile_Item_Drag_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WB_Tile_Item_Drag.WB_Tile_Item_Drag_C.ExecuteUbergraph_WB_Tile_Item_Drag
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWB_Tile_Item_Drag_C::ExecuteUbergraph_WB_Tile_Item_Drag(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WB_Tile_Item_Drag_C", "ExecuteUbergraph_WB_Tile_Item_Drag");

	Params::WB_Tile_Item_Drag_C_ExecuteUbergraph_WB_Tile_Item_Drag Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}

}


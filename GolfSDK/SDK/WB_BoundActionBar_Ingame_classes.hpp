#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_BoundActionBar_Ingame

#include "Basic.hpp"

#include "CommonUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WB_BoundActionBar_Ingame.WB_BoundActionBar_Ingame_C
// 0x0010 (0x0298 - 0x0288)
class UWB_BoundActionBar_Ingame_C final : public UCommonUserWidget
{
public:
	class UCommonBoundActionBar*                  ActionBar;                                         // 0x0288(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USafeZone*                              SafeZone_16;                                       // 0x0290(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WB_BoundActionBar_Ingame_C">();
	}
	static class UWB_BoundActionBar_Ingame_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWB_BoundActionBar_Ingame_C>();
	}
};

}


#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: SimplePlaceableDummy3

#include "Basic.hpp"

#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass SimplePlaceableDummy3.SimplePlaceableDummy3_C
// 0x0018 (0x0238 - 0x0220)
class ASimplePlaceableDummy3_C final : public AActor
{
public:
	class UArrowComponent*                        Arrow;                                             // 0x0220(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   Cube;                                              // 0x0228(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x0230(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SimplePlaceableDummy3_C">();
	}
	static class ASimplePlaceableDummy3_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ASimplePlaceableDummy3_C>();
	}
};

}


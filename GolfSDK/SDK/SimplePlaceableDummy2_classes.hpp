#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: SimplePlaceableDummy2

#include "Basic.hpp"

#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass SimplePlaceableDummy2.SimplePlaceableDummy2_C
// 0x0010 (0x0230 - 0x0220)
class ASimplePlaceableDummy2_C final : public AActor
{
public:
	class UStaticMeshComponent*                   Cube;                                              // 0x0220(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x0228(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SimplePlaceableDummy2_C">();
	}
	static class ASimplePlaceableDummy2_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ASimplePlaceableDummy2_C>();
	}
};

}


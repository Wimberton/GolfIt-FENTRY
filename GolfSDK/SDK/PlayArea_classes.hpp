#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: PlayArea

#include "Basic.hpp"

#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PlayArea.PlayArea_C
// 0x0018 (0x0238 - 0x0220)
class APlayArea_C final : public AActor
{
public:
	class UBoxComponent*                          Box;                                               // 0x0220(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x0228(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	int32                                         HoleArea;                                          // 0x0230(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	int32 GetAssociatedHoleNumber() const;

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PlayArea_C">();
	}
	static class APlayArea_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<APlayArea_C>();
	}
};

}


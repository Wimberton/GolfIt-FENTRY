#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: AC_EventAttachment

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "RotatorStruct_structs.hpp"
#include "EventSingle_structs.hpp"
#include "EventValues_structs.hpp"
#include "EventDefaults_structs.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass AC_EventAttachment.AC_EventAttachment_C
// 0x0130 (0x01E0 - 0x00B0)
class UAC_EventAttachment_C final : public UActorComponent
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x00B0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	struct FEventSingle                           EventSingle;                                       // 0x00B8(0x0048)(Edit, BlueprintVisible, ExposeOnSpawn, HasGetValueTypeHash)
	bool                                          EventRunning;                                      // 0x0100(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_101[0x7];                                      // 0x0101(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<EventDefaults>                         EventTypeQue;                                      // 0x0108(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<struct FEventValues>                   EventValuesQue;                                    // 0x0118(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	int32                                         QueID;                                             // 0x0128(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          RotationAdded;                                     // 0x012C(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_12D[0x3];                                      // 0x012D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         Duration;                                          // 0x0130(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TimeUntilDone;                                     // 0x0134(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_138[0x8];                                      // 0x0138(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTransform                             TransformOrigin;                                   // 0x0140(0x0030)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	struct FTransform                             TransformTarget;                                   // 0x0170(0x0030)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	struct FRotatorStruct                         AddRotations;                                      // 0x01A0(0x0018)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                RotationDelta;                                     // 0x01B8(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                RotationsDone;                                     // 0x01C4(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         UniqueId;                                          // 0x01D0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void GetUniqueID(int32* UniqeID);
	void CheckIfUniqueID(int32 UnqieID, bool* HasID);
	void StartEvent(EventDefaults EventDefaults, const struct FEventValues& EventValues, float* Delay);
	void DetermineIfEventNeedsComponentTick(EventDefaults EventType, const struct FEventValues& EventValues, bool* ContinueOnActor, float* Delay);
	void AddRotationInDuration(float Tick);
	void TransformActorInDuration(const struct FTransform& Target, float Tick);
	void ReStartDynamicEvent();
	void StopDynamicEvent();
	void SetDefaults();
	void ContinueEvent();
	void SetIntegerEventID(int32 Param_UniqueId);
	void DestroyAttachedComponent(class UActorComponent* ComponentToDestroy);
	void AddEvent(const struct FEventSingle& Event);
	void NextEvent();
	void StartDurationTransform(float Param_Duration, const struct FTransform& TargetTransform);
	void StartAddRotation(const struct FRotatorStruct& RotationAdd, float Delay);
	void ReceiveTick(float DeltaSeconds);
	void ResetToDefault();
	void ExecuteUbergraph_AC_EventAttachment(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AC_EventAttachment_C">();
	}
	static class UAC_EventAttachment_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAC_EventAttachment_C>();
	}
};

}


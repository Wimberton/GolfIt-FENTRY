#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: RiverControlPoint

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass RiverControlPoint.RiverControlPoint_C
// 0x0080 (0x02A0 - 0x0220)
class ARiverControlPoint_C final : public AActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0220(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UStaticMeshComponent*                   StaticMesh;                                        // 0x0228(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x0230(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class ARiverEditor_C*                         RiverReference;                                    // 0x0238(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                LastLocation;                                      // 0x0240(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_24C[0x4];                                      // 0x024C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TMap<class ARiverControlPoint_C*, int32>      TempControlMeshes;                                 // 0x0250(0x0050)(Edit, BlueprintVisible, DisableEditOnTemplate, DisableEditOnInstance)

public:
	void ExecuteUbergraph_RiverControlPoint(int32 EntryPoint);
	void MulticastSetRiverReference(class ARiverEditor_C* RiverRef);
	void ServerRebuildSpline();
	void ReceiveDestroyed();
	void AddNewSplinePoint();
	void LostControl();
	void InpAxisKeyEvt_MouseWheelAxis_K2Node_InputAxisKeyEvent_0(float AxisValue);
	void ReceiveTick(float DeltaSeconds);
	void ControlPointMoved();
	void CheckIfRiverControlPoint(class ARiverControlPoint_C** Ref);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"RiverControlPoint_C">();
	}
	static class ARiverControlPoint_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ARiverControlPoint_C>();
	}
};

}


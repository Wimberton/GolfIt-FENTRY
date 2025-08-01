#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: BP_SplineMeshController

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_SplineMeshController.BP_SplineMeshController_C
// 0x0080 (0x02A0 - 0x0220)
class ABP_SplineMeshController_C final : public AActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0220(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UStaticMeshComponent*                   StaticMesh;                                        // 0x0228(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x0230(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class ABP_SplineMeshBuilder_C*                MasterRef;                                         // 0x0238(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                LastLocation;                                      // 0x0240(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_24C[0x4];                                      // 0x024C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TMap<class ABP_SplineMeshController_C*, int32> TempControlMeshes;                                 // 0x0250(0x0050)(Edit, BlueprintVisible, DisableEditOnTemplate, DisableEditOnInstance)

public:
	void CheckIfSplineControlPoint(class ABP_SplineMeshController_C** Ref);
	void ReceiveTick(float DeltaSeconds);
	void InpAxisKeyEvt_MouseWheelAxis_K2Node_InputAxisKeyEvent_0(float AxisValue);
	void ReceiveDestroyed();
	void ServerRebuildSpline();
	void ControlPointChanged();
	void LostControlOfMaster();
	void AddNewSplinePoints();
	void ExecuteUbergraph_BP_SplineMeshController(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_SplineMeshController_C">();
	}
	static class ABP_SplineMeshController_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_SplineMeshController_C>();
	}
};

}


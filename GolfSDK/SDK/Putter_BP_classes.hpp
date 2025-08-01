#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: Putter_BP

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "CoreUObject_structs.hpp"
#include "GolfIt_structs.hpp"
#include "FMODStudio_structs.hpp"
#include "CommonInput_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass Putter_BP.Putter_BP_C
// 0x0110 (0x0330 - 0x0220)
class APutter_BP_C final : public AActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0220(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UStaticMeshComponent*                   Putter;                                            // 0x0228(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        PutterOffsetScene;                                 // 0x0230(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UArrowComponent*                        IronFoward;                                        // 0x0238(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UArrowComponent*                        PutterForward;                                     // 0x0240(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UArrowComponent*                        WedgeForward;                                      // 0x0248(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        Scene;                                             // 0x0250(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class AGolfBall_C*                            OwningGolfBall;                                    // 0x0258(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	bool                                          AltFire;                                           // 0x0260(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn)
	uint8                                         Pad_261[0x3];                                      // 0x0261(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         ClubStrengh;                                       // 0x0264(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         ClubIndex;                                         // 0x0268(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	bool                                          IsSimulation;                                      // 0x026C(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_26D[0x3];                                      // 0x026D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         ClubAngle;                                         // 0x0270(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_274[0x4];                                      // 0x0274(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<float>                                 TrackedDeltas;                                     // 0x0278(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	class UCurveFloat*                            Controller_Curve_Scale;                            // 0x0288(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<float>                                 TrackedVelocities;                                 // 0x0290(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	int32                                         PowerQuePosition;                                  // 0x02A0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         PowerQueSize;                                      // 0x02A4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DistanceToCenter;                                  // 0x02A8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          SimulateShoot;                                     // 0x02AC(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2AD[0x3];                                      // 0x02AD(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         SimulatedPower;                                    // 0x02B0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SimulationMovementSpeed;                           // 0x02B4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector2D                              ControllerMovementMultiplier;                      // 0x02B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector2D                              MouseMovementMultiplier;                           // 0x02C0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         PowerByMovementMultiplier;                         // 0x02C8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         PowerByDistanceMultiplier;                         // 0x02CC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SpawnDistanceMultiplier;                           // 0x02D0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         RotationMovementReduction;                         // 0x02D4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         MaxAllowedDeltaTime;                               // 0x02D8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DisplayPowerMultiplier;                            // 0x02DC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         MaxSimulationAngle;                                // 0x02E0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DragDurationMultiplier;                            // 0x02E4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DragIntensityMultiplier;                           // 0x02E8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DragDirectionMultiplier;                           // 0x02EC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UFMODAudioComponent*                    SwingEvent;                                        // 0x02F0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TSoftObjectPtr<class UStaticMesh>             PutterMesh;                                        // 0x02F8(0x0028)(Edit, BlueprintVisible, ExposeOnSpawn, HasGetValueTypeHash)
	struct FFMODEventInstance                     SwingSound;                                        // 0x0320(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          UseAlternativeShootingRandomness;                  // 0x0328(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void Move_Club(float Y_Movement);
	void Track_Movement(float Y_Movement, float Delta_Time);
	void Set_Club_Data(TSoftObjectPtr<class UStaticMesh> Mesh, float Club_Strengh);
	void InpActEvt_Alternative_Shoot_K2Node_InputActionEvent_2(const struct FKey& Key);
	void InpActEvt_Destroy_Putter_K2Node_InputActionEvent_1(const struct FKey& Key);
	void InpActEvt_Spawn_Putter_K2Node_InputActionEvent_0(const struct FKey& Key);
	void OnInputMethodChanged(ECommonInputType bNewInputType);
	void ReceiveTick(float DeltaSeconds);
	void ReceiveDestroyed();
	void ReceiveBeginPlay();
	void ExecuteUbergraph_Putter_BP(int32 EntryPoint);
	void Rotate_Club(float X_Movement);
	void Set_Putter(int32 PutterIndex, TSoftObjectPtr<class UStaticMesh> Mesh);
	void Update_UI();
	void Initiate_Alternative_Shoot();
	void HideSimulationUIIfAbort();
	void Update_Swing_Sound(float Y_Movement);
	float GetRandomAlternativeSimulatedPower();

	void Check_If_Hit(bool* HitDetected) const;
	void Get_Current_Forward(struct FVector* Forward) const;
	void Get_Impulse(float Power, struct FVector* Impulse) const;
	void Get_Hit_Distance(float* Distance) const;
	void Get_Simulated_Movement(float Delta_Time, struct FVector2D* Movement) const;
	void Get_Input_Movement(float Delta_Time, struct FVector2D* Movement) const;
	void Get_Movement(float Delta_Time, struct FVector2D* Movement) const;
	void Get_Power_By_Distance(float Distance, float* Power) const;
	void Get_Power_By_Movement(float* AveragePower) const;
	void Get_Drag_Parameters(float Power, struct FVector* Drag_Direction, float* Drag_Intensity, float* Drag_Duration) const;
	float Get_Spawn_Distance() const;
	void Get_Putter_Sensitivity(float* Sensitivity) const;
	bool Is_Allowed_To_Hit() const;
	float Get_Distance_To_Ball() const;
	void CheckMouseInversion(float DeltaX, float DeltaY, float* X, float* Y) const;
	void CheckControllerInversion(float DeltaX, float DeltaY, float* X, float* Y) const;

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Putter_BP_C">();
	}
	static class APutter_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<APutter_BP_C>();
	}
};

}


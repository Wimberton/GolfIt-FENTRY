#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: GameSpectatorPawn

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "GolfIt_structs.hpp"
#include "GolfIt_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GameSpectatorPawn.GameSpectatorPawn_C
// 0x0058 (0x0300 - 0x02A8)
class AGameSpectatorPawn_C final : public AGolfItLobbySpectatorPawn
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x02A8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class USpringArmComponent*                    SpringArm;                                         // 0x02B0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        Scene;                                             // 0x02B8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UFloatingPawnMovement*                  FloatingPawnMovement;                              // 0x02C0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UCameraComponent*                       Camera;                                            // 0x02C8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UArrowComponent*                        Arrow;                                             // 0x02D0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   SM_CineCam;                                        // 0x02D8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class APlayerState*                           AttachedPlayer;                                    // 0x02E0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SavedArmLength;                                    // 0x02E8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         RotationTime;                                      // 0x02EC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               GravityRotation;                                   // 0x02F0(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          IsPermanentSpectator;                              // 0x02FC(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void ExecuteUbergraph_GameSpectatorPawn(int32 EntryPoint);
	void ReceiveDestroyed();
	void BallReset(const struct FVector& Location);
	void HoleNumberChanged(int32 LastHole, int32 NextHole);
	void StartSettingsClient();
	void SpectateGolfBall(class AGolfItGolfBallPawn* GolfBall);
	void ReceiveTick(float DeltaSeconds);
	void OnAttachedPlayerEndPlay(class AActor* Actor, EEndPlayReason EndPlayReason);
	void OnAttachedPlayerChanged(class APlayerState* NewPlayer);
	void OnAttachedPlayerPlayStateChanged(ELobbyPlayerPlayState PreviousPlayState, ELobbyPlayerPlayState NewPlayState, const class AGolfItLobbyPlayerState* LobbyPlayerState);
	void InpAxisEvt_Turn_View_K2Node_InputAxisEvent_125(float AxisValue);
	void InpAxisEvt_Up_View_K2Node_InputAxisEvent_72(float AxisValue);
	void InpAxisEvt_Down_K2Node_InputAxisEvent_50(float AxisValue);
	void InpAxisEvt_Up_K2Node_InputAxisEvent_40(float AxisValue);
	void InpAxisEvt_Backwards_K2Node_InputAxisEvent_20(float AxisValue);
	void InpAxisEvt_Right_K2Node_InputAxisEvent_3(float AxisValue);
	void InpAxisEvt_Left_K2Node_InputAxisEvent_1(float AxisValue);
	void ReceivePossessed(class AController* NewController);
	void InpAxisEvt_Forward_K2Node_InputAxisEvent_31(float AxisValue);
	void InpActEvt_FreeCam_K2Node_InputActionEvent_0(const struct FKey& Key);
	void InpActEvt_MouseScrollUp_K2Node_InputKeyEvent_0(const struct FKey& Key);
	void InpActEvt_MouseScrollDown_K2Node_InputKeyEvent_1(const struct FKey& Key);
	void InpActEvt_RightMouseButton_K2Node_InputKeyEvent_2(const struct FKey& Key);
	void InpActEvt_LeftMouseButton_K2Node_InputKeyEvent_3(const struct FKey& Key);
	void InpActEvt_LeftShift_K2Node_InputKeyEvent_4(const struct FKey& Key);
	void InpActEvt_LeftShift_K2Node_InputKeyEvent_5(const struct FKey& Key);
	void Attach_to_Next_Player();
	void Attach_To_Previous_Player();
	void AttachToGolfBall(class AGolfBall_C* GolfBall);
	void IsAttached(bool* Param_IsAttached, class AActor** Actor);
	void Detach_from_Golf_Ball();
	void SetCameraSphere(float Min, float Max);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GameSpectatorPawn_C">();
	}
	static class AGameSpectatorPawn_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AGameSpectatorPawn_C>();
	}
};

}


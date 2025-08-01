#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: Goal_Mesh

#include "Basic.hpp"

#include "Goal_Mesh_classes.hpp"
#include "Goal_Mesh_parameters.hpp"


namespace SDK
{

// Function Goal_Mesh.Goal_Mesh_C.OnFinished__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)

void AGoal_Mesh_C::OnFinished__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "OnFinished__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Goal_Mesh.Goal_Mesh_C.ExecuteUbergraph_Goal_Mesh
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AGoal_Mesh_C::ExecuteUbergraph_Goal_Mesh(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "ExecuteUbergraph_Goal_Mesh");

	Params::Goal_Mesh_C_ExecuteUbergraph_Goal_Mesh Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Goal_Mesh.Goal_Mesh_C.BndEvt__Goal_Mesh_GoalNet_K2Node_ComponentBoundEvent_1_ComponentBeginOverlapSignature__DelegateSignature
// (HasOutParams, BlueprintEvent)
// Parameters:
// class UPrimitiveComponent*              OverlappedComponent                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class AActor*                           OtherActor                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UPrimitiveComponent*              OtherComp                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   OtherBodyIndex                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    bFromSweep                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// struct FHitResult                       SweepResult                                            (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, IsPlainOldData, NoDestructor, ContainsInstancedReference)

void AGoal_Mesh_C::BndEvt__Goal_Mesh_GoalNet_K2Node_ComponentBoundEvent_1_ComponentBeginOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "BndEvt__Goal_Mesh_GoalNet_K2Node_ComponentBoundEvent_1_ComponentBeginOverlapSignature__DelegateSignature");

	Params::Goal_Mesh_C_BndEvt__Goal_Mesh_GoalNet_K2Node_ComponentBoundEvent_1_ComponentBeginOverlapSignature__DelegateSignature Parms{};

	Parms.OverlappedComponent = OverlappedComponent;
	Parms.OtherActor = OtherActor;
	Parms.OtherComp = OtherComp;
	Parms.OtherBodyIndex = OtherBodyIndex;
	Parms.bFromSweep = bFromSweep;
	Parms.SweepResult = std::move(SweepResult);

	UObject::ProcessEvent(Func, &Parms);
}


// Function Goal_Mesh.Goal_Mesh_C.OnColorChanged
// (Event, Public, BlueprintCallable, BlueprintEvent)

void AGoal_Mesh_C::OnColorChanged()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "OnColorChanged");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Goal_Mesh.Goal_Mesh_C.BndEvt__Goal_Mesh_GoalNet_K2Node_ComponentBoundEvent_0_ComponentHitSignature__DelegateSignature
// (HasOutParams, BlueprintEvent)
// Parameters:
// class UPrimitiveComponent*              HitComponent                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class AActor*                           OtherActor                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UPrimitiveComponent*              OtherComp                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          NormalImpulse                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FHitResult                       Hit                                                    (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, IsPlainOldData, NoDestructor, ContainsInstancedReference)

void AGoal_Mesh_C::BndEvt__Goal_Mesh_GoalNet_K2Node_ComponentBoundEvent_0_ComponentHitSignature__DelegateSignature(class UPrimitiveComponent* HitComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, const struct FVector& NormalImpulse, const struct FHitResult& Hit)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "BndEvt__Goal_Mesh_GoalNet_K2Node_ComponentBoundEvent_0_ComponentHitSignature__DelegateSignature");

	Params::Goal_Mesh_C_BndEvt__Goal_Mesh_GoalNet_K2Node_ComponentBoundEvent_0_ComponentHitSignature__DelegateSignature Parms{};

	Parms.HitComponent = HitComponent;
	Parms.OtherActor = OtherActor;
	Parms.OtherComp = OtherComp;
	Parms.NormalImpulse = std::move(NormalImpulse);
	Parms.Hit = std::move(Hit);

	UObject::ProcessEvent(Func, &Parms);
}


// Function Goal_Mesh.Goal_Mesh_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void AGoal_Mesh_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Goal_Mesh.Goal_Mesh_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void AGoal_Mesh_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Goal_Mesh.Goal_Mesh_C.SetupMesh
// (Public, BlueprintCallable, BlueprintEvent)

void AGoal_Mesh_C::SetupMesh()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "SetupMesh");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Goal_Mesh.Goal_Mesh_C.SetupGateWithBar
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void AGoal_Mesh_C::SetupGateWithBar()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "SetupGateWithBar");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Goal_Mesh.Goal_Mesh_C.SetupGateSolo
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void AGoal_Mesh_C::SetupGateSolo()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "SetupGateSolo");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Goal_Mesh.Goal_Mesh_C.SetupRingWithBar
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void AGoal_Mesh_C::SetupRingWithBar()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "SetupRingWithBar");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Goal_Mesh.Goal_Mesh_C.SetupRingSolo
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void AGoal_Mesh_C::SetupRingSolo()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "SetupRingSolo");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Goal_Mesh.Goal_Mesh_C.SetupGong
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void AGoal_Mesh_C::SetupGong()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "SetupGong");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Goal_Mesh.Goal_Mesh_C.PlayBallEnterHoleSound
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FVector                          HitImpulse                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AGoal_Mesh_C::PlayBallEnterHoleSound(const struct FVector& HitImpulse)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "PlayBallEnterHoleSound");

	Params::Goal_Mesh_C_PlayBallEnterHoleSound Parms{};

	Parms.HitImpulse = std::move(HitImpulse);

	UObject::ProcessEvent(Func, &Parms);
}


// Function Goal_Mesh.Goal_Mesh_C.CheckIfHoleValid
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AGolfItGolfBallPawn*              BallReference                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Finish                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
// class AGolfItGolfBallPawn*              FinishingBall                                          (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AGoal_Mesh_C::CheckIfHoleValid(class AGolfItGolfBallPawn* BallReference, bool* Finish, class AGolfItGolfBallPawn** FinishingBall)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "CheckIfHoleValid");

	Params::Goal_Mesh_C_CheckIfHoleValid Parms{};

	Parms.BallReference = BallReference;

	UObject::ProcessEvent(Func, &Parms);

	if (Finish != nullptr)
		*Finish = Parms.Finish;

	if (FinishingBall != nullptr)
		*FinishingBall = Parms.FinishingBall;
}


// Function Goal_Mesh.Goal_Mesh_C.PlayWrongHoleSound
// (Public, BlueprintCallable, BlueprintEvent)

void AGoal_Mesh_C::PlayWrongHoleSound()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "PlayWrongHoleSound");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Goal_Mesh.Goal_Mesh_C.PlayFinishSound
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   Strokes                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   Par                                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AGoal_Mesh_C::PlayFinishSound(int32 Strokes, int32 Par)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "PlayFinishSound");

	Params::Goal_Mesh_C_PlayFinishSound Parms{};

	Parms.Strokes = Strokes;
	Parms.Par = Par;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Goal_Mesh.Goal_Mesh_C.UpdateColors
// (Public, BlueprintCallable, BlueprintEvent)

void AGoal_Mesh_C::UpdateColors()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "UpdateColors");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Goal_Mesh.Goal_Mesh_C.UpdateMeshCollisionOnGoalEntry
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// ECollisionEnabled                       NewType                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AGoal_Mesh_C::UpdateMeshCollisionOnGoalEntry(ECollisionEnabled NewType)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "UpdateMeshCollisionOnGoalEntry");

	Params::Goal_Mesh_C_UpdateMeshCollisionOnGoalEntry Parms{};

	Parms.NewType = NewType;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Goal_Mesh.Goal_Mesh_C.CheckActorAndTriggerFinish
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UObject*                          ActorHit                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Finished                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AGoal_Mesh_C::CheckActorAndTriggerFinish(class UObject* ActorHit, bool* Finished)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "CheckActorAndTriggerFinish");

	Params::Goal_Mesh_C_CheckActorAndTriggerFinish Parms{};

	Parms.ActorHit = ActorHit;

	UObject::ProcessEvent(Func, &Parms);

	if (Finished != nullptr)
		*Finished = Parms.Finished;
}


// Function Goal_Mesh.Goal_Mesh_C.ChangeGoalCustomDepth
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    NewValue                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// int32                                   CurrentHoleNumber                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class AGolfItLobbySettings*             LobbySettings                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Completed                                              (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AGoal_Mesh_C::ChangeGoalCustomDepth(bool NewValue, int32 CurrentHoleNumber, class AGolfItLobbySettings* LobbySettings, bool* Completed)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Goal_Mesh_C", "ChangeGoalCustomDepth");

	Params::Goal_Mesh_C_ChangeGoalCustomDepth Parms{};

	Parms.NewValue = NewValue;
	Parms.CurrentHoleNumber = CurrentHoleNumber;
	Parms.LobbySettings = LobbySettings;

	UObject::ProcessEvent(Func, &Parms);

	if (Completed != nullptr)
		*Completed = Parms.Completed;
}

}


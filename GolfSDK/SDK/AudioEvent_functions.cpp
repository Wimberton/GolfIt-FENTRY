#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: AudioEvent

#include "Basic.hpp"

#include "AudioEvent_classes.hpp"
#include "AudioEvent_parameters.hpp"


namespace SDK
{

// Function AudioEvent.AudioEvent_C.ExecuteUbergraph_AudioEvent
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AAudioEvent_C::ExecuteUbergraph_AudioEvent(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "ExecuteUbergraph_AudioEvent");

	Params::AudioEvent_C_ExecuteUbergraph_AudioEvent Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AudioEvent.AudioEvent_C.ShowAudioVisibility
// (BlueprintCallable, BlueprintEvent)

void AAudioEvent_C::ShowAudioVisibility()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "ShowAudioVisibility");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AudioEvent.AudioEvent_C.HideAudioVisibility
// (BlueprintCallable, BlueprintEvent)

void AAudioEvent_C::HideAudioVisibility()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "HideAudioVisibility");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AudioEvent.AudioEvent_C.AutoHideSphere
// (BlueprintCallable, BlueprintEvent)

void AAudioEvent_C::AutoHideSphere()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "AutoHideSphere");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AudioEvent.AudioEvent_C.ChangeVisibility
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Visible                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// TArray<class FString>                   Exception                                              (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)

void AAudioEvent_C::ChangeVisibility(bool Visible, const TArray<class FString>& Exception)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "ChangeVisibility");

	Params::AudioEvent_C_ChangeVisibility Parms{};

	Parms.Visible = Visible;
	Parms.Exception = std::move(Exception);

	UObject::ProcessEvent(Func, &Parms);
}


// Function AudioEvent.AudioEvent_C.NextEvent
// (Public, BlueprintCallable, BlueprintEvent)

void AAudioEvent_C::NextEvent()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "NextEvent");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AudioEvent.AudioEvent_C.AddEvent
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FEventSingle                     Event                                                  (BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)

void AAudioEvent_C::AddEvent(const struct FEventSingle& Event)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "AddEvent");

	Params::AudioEvent_C_AddEvent Parms{};

	Parms.Event = std::move(Event);

	UObject::ProcessEvent(Func, &Parms);
}


// Function AudioEvent.AudioEvent_C.SetUniqueID
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   NewUniqueID                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AAudioEvent_C::SetUniqueID(int32 NewUniqueID)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "SetUniqueID");

	Params::AudioEvent_C_SetUniqueID Parms{};

	Parms.NewUniqueID = NewUniqueID;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AudioEvent.AudioEvent_C.Deactivate
// (Public, BlueprintCallable, BlueprintEvent)

void AAudioEvent_C::Deactivate()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "Deactivate");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AudioEvent.AudioEvent_C.Activate
// (Public, BlueprintCallable, BlueprintEvent)

void AAudioEvent_C::Activate()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "Activate");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AudioEvent.AudioEvent_C.BndEvt__AudioPlayer_K2Node_ComponentBoundEvent_0_OnAudioFinished__DelegateSignature
// (BlueprintEvent)

void AAudioEvent_C::BndEvt__AudioPlayer_K2Node_ComponentBoundEvent_0_OnAudioFinished__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "BndEvt__AudioPlayer_K2Node_ComponentBoundEvent_0_OnAudioFinished__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AudioEvent.AudioEvent_C.SetNewAudio
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           AudioName                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)

void AAudioEvent_C::SetNewAudio(const class FString& AudioName)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "SetNewAudio");

	Params::AudioEvent_C_SetNewAudio Parms{};

	Parms.AudioName = std::move(AudioName);

	UObject::ProcessEvent(Func, &Parms);
}


// Function AudioEvent.AudioEvent_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void AAudioEvent_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AudioEvent.AudioEvent_C.DestroyAttachedComponent
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UActorComponent*                  ComponentToDestroy                                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AAudioEvent_C::DestroyAttachedComponent(class UActorComponent* ComponentToDestroy)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "DestroyAttachedComponent");

	Params::AudioEvent_C_DestroyAttachedComponent Parms{};

	Parms.ComponentToDestroy = ComponentToDestroy;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AudioEvent.AudioEvent_C.SetIntegerEventID
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   Param_UniqueId                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AAudioEvent_C::SetIntegerEventID(int32 Param_UniqueId)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "SetIntegerEventID");

	Params::AudioEvent_C_SetIntegerEventID Parms{};

	Parms.Param_UniqueId = Param_UniqueId;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AudioEvent.AudioEvent_C.StartAddRotation
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FRotatorStruct                   RotationAdd                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Delay                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AAudioEvent_C::StartAddRotation(const struct FRotatorStruct& RotationAdd, float Delay)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "StartAddRotation");

	Params::AudioEvent_C_StartAddRotation Parms{};

	Parms.RotationAdd = std::move(RotationAdd);
	Parms.Delay = Delay;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AudioEvent.AudioEvent_C.StartDurationTransform
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Duration                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FTransform                       TargetTransform                                        (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)

void AAudioEvent_C::StartDurationTransform(float Duration, const struct FTransform& TargetTransform)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "StartDurationTransform");

	Params::AudioEvent_C_StartDurationTransform Parms{};

	Parms.Duration = Duration;
	Parms.TargetTransform = std::move(TargetTransform);

	UObject::ProcessEvent(Func, &Parms);
}


// Function AudioEvent.AudioEvent_C.ContinueEvent
// (Public, BlueprintCallable, BlueprintEvent)

void AAudioEvent_C::ContinueEvent()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "ContinueEvent");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AudioEvent.AudioEvent_C.SetDefaults
// (Public, BlueprintCallable, BlueprintEvent)

void AAudioEvent_C::SetDefaults()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "SetDefaults");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AudioEvent.AudioEvent_C.ResetToDefault
// (Public, BlueprintCallable, BlueprintEvent)

void AAudioEvent_C::ResetToDefault()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "ResetToDefault");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AudioEvent.AudioEvent_C.StopDynamicEvent
// (Public, BlueprintCallable, BlueprintEvent)

void AAudioEvent_C::StopDynamicEvent()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "StopDynamicEvent");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AudioEvent.AudioEvent_C.ReStartDynamicEvent
// (Public, BlueprintCallable, BlueprintEvent)

void AAudioEvent_C::ReStartDynamicEvent()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "ReStartDynamicEvent");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AudioEvent.AudioEvent_C.SetAttenuationSettings
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FAudioSoundStruct                Param_SoundStruct                                      (BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)

void AAudioEvent_C::SetAttenuationSettings(const struct FAudioSoundStruct& Param_SoundStruct)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "SetAttenuationSettings");

	Params::AudioEvent_C_SetAttenuationSettings Parms{};

	Parms.Param_SoundStruct = std::move(Param_SoundStruct);

	UObject::ProcessEvent(Func, &Parms);
}


// Function AudioEvent.AudioEvent_C.DisplayVisualRadius
// (Public, BlueprintCallable, BlueprintEvent)

void AAudioEvent_C::DisplayVisualRadius()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "DisplayVisualRadius");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AudioEvent.AudioEvent_C.StartEvent
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// EventDefaults                           EventDefaults                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FEventValues                     EventValues                                            (BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)
// float                                   Delay                                                  (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AAudioEvent_C::StartEvent(EventDefaults EventDefaults, const struct FEventValues& EventValues, float* Delay)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "StartEvent");

	Params::AudioEvent_C_StartEvent Parms{};

	Parms.EventDefaults = EventDefaults;
	Parms.EventValues = std::move(EventValues);

	UObject::ProcessEvent(Func, &Parms);

	if (Delay != nullptr)
		*Delay = Parms.Delay;
}


// Function AudioEvent.AudioEvent_C.CheckIfUniqueID
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   UnqieID                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    HasID                                                  (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AAudioEvent_C::CheckIfUniqueID(int32 UnqieID, bool* HasID)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "CheckIfUniqueID");

	Params::AudioEvent_C_CheckIfUniqueID Parms{};

	Parms.UnqieID = UnqieID;

	UObject::ProcessEvent(Func, &Parms);

	if (HasID != nullptr)
		*HasID = Parms.HasID;
}


// Function AudioEvent.AudioEvent_C.GetUniqueID
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   UniqeID                                                (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AAudioEvent_C::GetUniqueID(int32* UniqeID)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AudioEvent_C", "GetUniqueID");

	Params::AudioEvent_C_GetUniqueID Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (UniqeID != nullptr)
		*UniqeID = Parms.UniqeID;
}

}


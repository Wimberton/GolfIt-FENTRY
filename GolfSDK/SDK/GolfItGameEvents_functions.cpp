#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: GolfItGameEvents

#include "Basic.hpp"

#include "GolfItGameEvents_classes.hpp"
#include "GolfItGameEvents_parameters.hpp"


namespace SDK
{

// Function GolfItGameEvents.GolfItGameEventsSubsystem.ExecuteEvent
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// struct FGameplayTag                     GameEventTag                                           (Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UGolfItGameEventsSubsystem::ExecuteEvent(const struct FGameplayTag& GameEventTag)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItGameEventsSubsystem", "ExecuteEvent");

	Params::GolfItGameEventsSubsystem_ExecuteEvent Parms{};

	Parms.GameEventTag = std::move(GameEventTag);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function GolfItGameEvents.GolfItGameEventsSubsystem.ExecuteEvents
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// struct FGameplayTagContainer            GameEventTags                                          (Parm, NativeAccessSpecifierPublic)

void UGolfItGameEventsSubsystem::ExecuteEvents(const struct FGameplayTagContainer& GameEventTags)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItGameEventsSubsystem", "ExecuteEvents");

	Params::GolfItGameEventsSubsystem_ExecuteEvents Parms{};

	Parms.GameEventTags = std::move(GameEventTags);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// DelegateFunction GolfItGameEvents.GolfItGameEventsSubsystem.OnGolfItGameEventExecuteSignature__DelegateSignature
// (Public, Delegate, HasOutParams)
// Parameters:
// struct FGameplayTag                     GameEventTag                                           (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UGolfItGameEventsSubsystem::OnGolfItGameEventExecuteSignature__DelegateSignature(const struct FGameplayTag& GameEventTag)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItGameEventsSubsystem", "OnGolfItGameEventExecuteSignature__DelegateSignature");

	Params::GolfItGameEventsSubsystem_OnGolfItGameEventExecuteSignature__DelegateSignature Parms{};

	Parms.GameEventTag = std::move(GameEventTag);

	UObject::ProcessEvent(Func, &Parms);
}


// DelegateFunction GolfItGameEvents.GolfItGameEventsSubsystem.OnGolfItGameEventListenersSignature__DelegateSignature
// (MulticastDelegate, Public, Delegate, HasOutParams)
// Parameters:
// struct FGameplayTag                     GameEventTag                                           (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UGolfItGameEventsSubsystem::OnGolfItGameEventListenersSignature__DelegateSignature(const struct FGameplayTag& GameEventTag)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItGameEventsSubsystem", "OnGolfItGameEventListenersSignature__DelegateSignature");

	Params::GolfItGameEventsSubsystem_OnGolfItGameEventListenersSignature__DelegateSignature Parms{};

	Parms.GameEventTag = std::move(GameEventTag);

	UObject::ProcessEvent(Func, &Parms);
}


// Function GolfItGameEvents.GolfItGameEventsSubsystem.RegisterEventListener
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// TDelegate<void(struct FGameplayTag& GameEventTag)>OnGameEvent                                            (Parm, ZeroConstructor, NoDestructor, NativeAccessSpecifierPublic)
// struct FGameplayTag                     GameEventTag                                           (Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// bool                                    IMMEDIATE                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// bool                                    FireSingleTime                                         (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// bool                                    AllowDuplicates                                        (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UGolfItGameEventsSubsystem::RegisterEventListener(TDelegate<void(struct FGameplayTag& GameEventTag)> OnGameEvent, const struct FGameplayTag& GameEventTag, bool IMMEDIATE, bool FireSingleTime, bool AllowDuplicates)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItGameEventsSubsystem", "RegisterEventListener");

	Params::GolfItGameEventsSubsystem_RegisterEventListener Parms{};

	Parms.OnGameEvent = OnGameEvent;
	Parms.GameEventTag = std::move(GameEventTag);
	Parms.IMMEDIATE = IMMEDIATE;
	Parms.FireSingleTime = FireSingleTime;
	Parms.AllowDuplicates = AllowDuplicates;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function GolfItGameEvents.GolfItGameEventsSubsystem.RegisterEventsListener
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// TDelegate<void(struct FGameplayTag& GameEventTag)>OnGameEvent                                            (Parm, ZeroConstructor, NoDestructor, NativeAccessSpecifierPublic)
// struct FGameplayTagContainer            GameEventTags                                          (ConstParm, Parm, OutParm, ReferenceParm, NativeAccessSpecifierPublic)
// bool                                    IMMEDIATE                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// bool                                    AllowDuplicates                                        (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UGolfItGameEventsSubsystem::RegisterEventsListener(TDelegate<void(struct FGameplayTag& GameEventTag)> OnGameEvent, const struct FGameplayTagContainer& GameEventTags, bool IMMEDIATE, bool AllowDuplicates)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItGameEventsSubsystem", "RegisterEventsListener");

	Params::GolfItGameEventsSubsystem_RegisterEventsListener Parms{};

	Parms.OnGameEvent = OnGameEvent;
	Parms.GameEventTags = std::move(GameEventTags);
	Parms.IMMEDIATE = IMMEDIATE;
	Parms.AllowDuplicates = AllowDuplicates;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function GolfItGameEvents.GolfItGameEventsSubsystem.UnregisterAllEventListeners
// (Final, Native, Public, BlueprintCallable)

void UGolfItGameEventsSubsystem::UnregisterAllEventListeners()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItGameEventsSubsystem", "UnregisterAllEventListeners");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// Function GolfItGameEvents.GolfItGameEventsSubsystem.UnregisterEventListenerByDelegate
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// TDelegate<void(struct FGameplayTag& GameEventTag)>OnGameEvent                                            (Parm, ZeroConstructor, NoDestructor, NativeAccessSpecifierPublic)

void UGolfItGameEventsSubsystem::UnregisterEventListenerByDelegate(TDelegate<void(struct FGameplayTag& GameEventTag)> OnGameEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItGameEventsSubsystem", "UnregisterEventListenerByDelegate");

	Params::GolfItGameEventsSubsystem_UnregisterEventListenerByDelegate Parms{};

	Parms.OnGameEvent = OnGameEvent;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function GolfItGameEvents.GolfItGameEventsSubsystem.UnregisterEventListenerFromEventByDelegate
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// struct FGameplayTag                     GameEventTag                                           (Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// TDelegate<void(struct FGameplayTag& GameEventTag)>OnGameEvent                                            (Parm, ZeroConstructor, NoDestructor, NativeAccessSpecifierPublic)

void UGolfItGameEventsSubsystem::UnregisterEventListenerFromEventByDelegate(const struct FGameplayTag& GameEventTag, TDelegate<void(struct FGameplayTag& GameEventTag)> OnGameEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItGameEventsSubsystem", "UnregisterEventListenerFromEventByDelegate");

	Params::GolfItGameEventsSubsystem_UnregisterEventListenerFromEventByDelegate Parms{};

	Parms.GameEventTag = std::move(GameEventTag);
	Parms.OnGameEvent = OnGameEvent;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function GolfItGameEvents.GolfItGameEventsSubsystem.UnregisterEventListenersByEventTag
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// struct FGameplayTag                     GameEventTag                                           (Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UGolfItGameEventsSubsystem::UnregisterEventListenersByEventTag(const struct FGameplayTag& GameEventTag)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItGameEventsSubsystem", "UnregisterEventListenersByEventTag");

	Params::GolfItGameEventsSubsystem_UnregisterEventListenersByEventTag Parms{};

	Parms.GameEventTag = std::move(GameEventTag);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}

}


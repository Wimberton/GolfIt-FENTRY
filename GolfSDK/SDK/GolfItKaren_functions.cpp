#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: GolfItKaren

#include "Basic.hpp"

#include "GolfItKaren_classes.hpp"
#include "GolfItKaren_parameters.hpp"


namespace SDK
{

// DelegateFunction GolfItKaren.GolfItKarenSubsystem.OnChallengeAdvanceProgressConnectionError__DelegateSignature
// (MulticastDelegate, Public, Delegate)

void UGolfItKarenSubsystem::OnChallengeAdvanceProgressConnectionError__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItKarenSubsystem", "OnChallengeAdvanceProgressConnectionError__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// DelegateFunction GolfItKaren.GolfItKarenSubsystem.OnChallengesAPIStateRetrieved__DelegateSignature
// (Public, Delegate)
// Parameters:
// EChallengesAPIState                     APIState                                               (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UGolfItKarenSubsystem::OnChallengesAPIStateRetrieved__DelegateSignature(EChallengesAPIState APIState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItKarenSubsystem", "OnChallengesAPIStateRetrieved__DelegateSignature");

	Params::GolfItKarenSubsystem_OnChallengesAPIStateRetrieved__DelegateSignature Parms{};

	Parms.APIState = APIState;

	UObject::ProcessEvent(Func, &Parms);
}


// DelegateFunction GolfItKaren.GolfItKarenSubsystem.OnRetryRewardGrantRetrieved__DelegateSignature
// (Public, Delegate)
// Parameters:
// int32                                   NumToRetry                                             (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// int32                                   NumGranted                                             (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UGolfItKarenSubsystem::OnRetryRewardGrantRetrieved__DelegateSignature(int32 NumToRetry, int32 NumGranted)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItKarenSubsystem", "OnRetryRewardGrantRetrieved__DelegateSignature");

	Params::GolfItKarenSubsystem_OnRetryRewardGrantRetrieved__DelegateSignature Parms{};

	Parms.NumToRetry = NumToRetry;
	Parms.NumGranted = NumGranted;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GolfItKaren.GolfItKarenSubsystem.RequestChallengesAPIState
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// TDelegate<void(EChallengesAPIState APIState)>OnChallengesAPIStateRetrieved                          (Parm, ZeroConstructor, NoDestructor, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool UGolfItKarenSubsystem::RequestChallengesAPIState(TDelegate<void(EChallengesAPIState APIState)> OnChallengesAPIStateRetrieved)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItKarenSubsystem", "RequestChallengesAPIState");

	Params::GolfItKarenSubsystem_RequestChallengesAPIState Parms{};

	Parms.OnChallengesAPIStateRetrieved = OnChallengesAPIStateRetrieved;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function GolfItKaren.GolfItKarenSubsystem.RequestRetryRewardGrant
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// TDelegate<void(int32 NumToRetry, int32 NumGranted)>OnRetryRewardGrantRetrieved                            (Parm, ZeroConstructor, NoDestructor, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool UGolfItKarenSubsystem::RequestRetryRewardGrant(TDelegate<void(int32 NumToRetry, int32 NumGranted)> OnRetryRewardGrantRetrieved)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItKarenSubsystem", "RequestRetryRewardGrant");

	Params::GolfItKarenSubsystem_RequestRetryRewardGrant Parms{};

	Parms.OnRetryRewardGrantRetrieved = OnRetryRewardGrantRetrieved;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}

}


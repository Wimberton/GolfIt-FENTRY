#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: GolfItDataHub

#include "Basic.hpp"

#include "GolfItDataHub_classes.hpp"
#include "GolfItDataHub_parameters.hpp"


namespace SDK
{

// Function GolfItDataHub.GolfItDataHubDataProvider.StoreData
// (Native, Event, Public, BlueprintEvent)
// Parameters:
// class UGolfItDataHubScope*              Scope                                                  (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void IGolfItDataHubDataProvider::StoreData(class UGolfItDataHubScope* Scope)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubDataProvider", "StoreData");

	Params::GolfItDataHubDataProvider_StoreData Parms{};

	Parms.Scope = Scope;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function GolfItDataHub.GolfItDataHubFunctions.MakeDataHubHandle
// (Final, Native, Static, Public, BlueprintCallable, BlueprintPure)
// Parameters:
// struct FGameplayTag                     GameplayTag                                            (Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// struct FDataHubHandle                   ReturnValue                                            (Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

struct FDataHubHandle UGolfItDataHubFunctions::MakeDataHubHandle(const struct FGameplayTag& GameplayTag)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("GolfItDataHubFunctions", "MakeDataHubHandle");

	Params::GolfItDataHubFunctions_MakeDataHubHandle Parms{};

	Parms.GameplayTag = std::move(GameplayTag);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function GolfItDataHub.GolfItDataHubFunctions.MakeDataHubHandleWithIndex
// (Final, Native, Static, Public, BlueprintCallable, BlueprintPure)
// Parameters:
// struct FGameplayTag                     GameplayTag                                            (Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// int32                                   Param_Index                                            (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// struct FDataHubHandle                   ReturnValue                                            (Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

struct FDataHubHandle UGolfItDataHubFunctions::MakeDataHubHandleWithIndex(const struct FGameplayTag& GameplayTag, int32 Param_Index)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("GolfItDataHubFunctions", "MakeDataHubHandleWithIndex");

	Params::GolfItDataHubFunctions_MakeDataHubHandleWithIndex Parms{};

	Parms.GameplayTag = std::move(GameplayTag);
	Parms.Param_Index = Param_Index;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function GolfItDataHub.GolfItDataHubFunctions.MakeDataHubHandleWithLocalPlayer
// (Final, Native, Static, Public, BlueprintCallable, BlueprintPure)
// Parameters:
// struct FGameplayTag                     GameplayTag                                            (Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// struct FDataHubHandle                   ReturnValue                                            (Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

struct FDataHubHandle UGolfItDataHubFunctions::MakeDataHubHandleWithLocalPlayer(const struct FGameplayTag& GameplayTag)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("GolfItDataHubFunctions", "MakeDataHubHandleWithLocalPlayer");

	Params::GolfItDataHubFunctions_MakeDataHubHandleWithLocalPlayer Parms{};

	Parms.GameplayTag = std::move(GameplayTag);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function GolfItDataHub.GolfItDataHubFunctions.MakeDataHubHandleWithPlayer
// (Final, Native, Static, Public, BlueprintCallable, BlueprintPure)
// Parameters:
// struct FGameplayTag                     GameplayTag                                            (Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class APlayerState*                     PlayerState                                            (ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// struct FDataHubHandle                   ReturnValue                                            (Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

struct FDataHubHandle UGolfItDataHubFunctions::MakeDataHubHandleWithPlayer(const struct FGameplayTag& GameplayTag, const class APlayerState* PlayerState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("GolfItDataHubFunctions", "MakeDataHubHandleWithPlayer");

	Params::GolfItDataHubFunctions_MakeDataHubHandleWithPlayer Parms{};

	Parms.GameplayTag = std::move(GameplayTag);
	Parms.PlayerState = PlayerState;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function GolfItDataHub.GolfItDataHubScope.ActivateDataHandle
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// struct FDataHubHandle                   DataHandle                                             (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// EGenericOperationResult                 ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

EGenericOperationResult UGolfItDataHubScope::ActivateDataHandle(const struct FDataHubHandle& DataHandle)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "ActivateDataHandle");

	Params::GolfItDataHubScope_ActivateDataHandle Parms{};

	Parms.DataHandle = std::move(DataHandle);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function GolfItDataHub.GolfItDataHubScope.GetFloatArrayData
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// struct FDataHubHandle                   DataHandle                                             (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// TArray<float>                           FloatArray                                             (Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
// EDataHubGetDataResult                   ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

EDataHubGetDataResult UGolfItDataHubScope::GetFloatArrayData(const struct FDataHubHandle& DataHandle, TArray<float>* FloatArray)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "GetFloatArrayData");

	Params::GolfItDataHubScope_GetFloatArrayData Parms{};

	Parms.DataHandle = std::move(DataHandle);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	if (FloatArray != nullptr)
		*FloatArray = std::move(Parms.FloatArray);

	return Parms.ReturnValue;
}


// Function GolfItDataHub.GolfItDataHubScope.GetFloatData
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// struct FDataHubHandle                   DataHandle                                             (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// float                                   OutFloat                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// EDataHubGetDataResult                   ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

EDataHubGetDataResult UGolfItDataHubScope::GetFloatData(const struct FDataHubHandle& DataHandle, float* OutFloat)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "GetFloatData");

	Params::GolfItDataHubScope_GetFloatData Parms{};

	Parms.DataHandle = std::move(DataHandle);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	if (OutFloat != nullptr)
		*OutFloat = Parms.OutFloat;

	return Parms.ReturnValue;
}


// Function GolfItDataHub.GolfItDataHubScope.GetGameplayTagData
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// struct FDataHubHandle                   DataHandle                                             (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// struct FGameplayTag                     OutTag                                                 (Parm, OutParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// EDataHubGetDataResult                   ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

EDataHubGetDataResult UGolfItDataHubScope::GetGameplayTagData(const struct FDataHubHandle& DataHandle, struct FGameplayTag* OutTag)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "GetGameplayTagData");

	Params::GolfItDataHubScope_GetGameplayTagData Parms{};

	Parms.DataHandle = std::move(DataHandle);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	if (OutTag != nullptr)
		*OutTag = std::move(Parms.OutTag);

	return Parms.ReturnValue;
}


// Function GolfItDataHub.GolfItDataHubScope.GetIntArrayData
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// struct FDataHubHandle                   DataHandle                                             (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// TArray<int32>                           IntArray                                               (Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
// EDataHubGetDataResult                   ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

EDataHubGetDataResult UGolfItDataHubScope::GetIntArrayData(const struct FDataHubHandle& DataHandle, TArray<int32>* IntArray)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "GetIntArrayData");

	Params::GolfItDataHubScope_GetIntArrayData Parms{};

	Parms.DataHandle = std::move(DataHandle);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	if (IntArray != nullptr)
		*IntArray = std::move(Parms.IntArray);

	return Parms.ReturnValue;
}


// Function GolfItDataHub.GolfItDataHubScope.GetIntData
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// struct FDataHubHandle                   DataHandle                                             (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// int32                                   OutInt                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// EDataHubGetDataResult                   ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

EDataHubGetDataResult UGolfItDataHubScope::GetIntData(const struct FDataHubHandle& DataHandle, int32* OutInt)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "GetIntData");

	Params::GolfItDataHubScope_GetIntData Parms{};

	Parms.DataHandle = std::move(DataHandle);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	if (OutInt != nullptr)
		*OutInt = Parms.OutInt;

	return Parms.ReturnValue;
}


// Function GolfItDataHub.GolfItDataHubScope.GetLongIntData
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// struct FDataHubHandle                   DataHandle                                             (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// int64                                   OutInt                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// EDataHubGetDataResult                   ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

EDataHubGetDataResult UGolfItDataHubScope::GetLongIntData(const struct FDataHubHandle& DataHandle, int64* OutInt)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "GetLongIntData");

	Params::GolfItDataHubScope_GetLongIntData Parms{};

	Parms.DataHandle = std::move(DataHandle);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	if (OutInt != nullptr)
		*OutInt = Parms.OutInt;

	return Parms.ReturnValue;
}


// Function GolfItDataHub.GolfItDataHubScope.GetNameData
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// struct FDataHubHandle                   DataHandle                                             (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class FName                             OutName                                                (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// EDataHubGetDataResult                   ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

EDataHubGetDataResult UGolfItDataHubScope::GetNameData(const struct FDataHubHandle& DataHandle, class FName* OutName)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "GetNameData");

	Params::GolfItDataHubScope_GetNameData Parms{};

	Parms.DataHandle = std::move(DataHandle);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	if (OutName != nullptr)
		*OutName = Parms.OutName;

	return Parms.ReturnValue;
}


// Function GolfItDataHub.GolfItDataHubScope.GetWorkshopHandleData
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// struct FDataHubHandle                   DataHandle                                             (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// struct FSteamWorkshopItemHandle         OutWorkshopHandle                                      (Parm, OutParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// EDataHubGetDataResult                   ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

EDataHubGetDataResult UGolfItDataHubScope::GetWorkshopHandleData(const struct FDataHubHandle& DataHandle, struct FSteamWorkshopItemHandle* OutWorkshopHandle)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "GetWorkshopHandleData");

	Params::GolfItDataHubScope_GetWorkshopHandleData Parms{};

	Parms.DataHandle = std::move(DataHandle);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	if (OutWorkshopHandle != nullptr)
		*OutWorkshopHandle = std::move(Parms.OutWorkshopHandle);

	return Parms.ReturnValue;
}


// Function GolfItDataHub.GolfItDataHubScope.OnScopeEndingEvent
// (Final, Native, Private, HasOutParams)
// Parameters:
// struct FGameplayTag                     GameEventTag                                           (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UGolfItDataHubScope::OnScopeEndingEvent(const struct FGameplayTag& GameEventTag)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "OnScopeEndingEvent");

	Params::GolfItDataHubScope_OnScopeEndingEvent Parms{};

	Parms.GameEventTag = std::move(GameEventTag);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function GolfItDataHub.GolfItDataHubScope.RegisterDataProvider
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// TScriptInterface<class IGolfItDataHubDataProvider>Provider                                               (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, NativeAccessSpecifierPublic)

void UGolfItDataHubScope::RegisterDataProvider(TScriptInterface<class IGolfItDataHubDataProvider> Provider)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "RegisterDataProvider");

	Params::GolfItDataHubScope_RegisterDataProvider Parms{};

	Parms.Provider = Provider;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function GolfItDataHub.GolfItDataHubScope.StoreFloatArrayData
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// struct FDataHubHandle                   DataHandle                                             (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// TArray<float>                           Data                                                   (Parm, OutParm, ZeroConstructor, ReferenceParm, NativeAccessSpecifierPublic)

void UGolfItDataHubScope::StoreFloatArrayData(const struct FDataHubHandle& DataHandle, TArray<float>& Data)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "StoreFloatArrayData");

	Params::GolfItDataHubScope_StoreFloatArrayData Parms{};

	Parms.DataHandle = std::move(DataHandle);
	Parms.Data = std::move(Data);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	Data = std::move(Parms.Data);
}


// Function GolfItDataHub.GolfItDataHubScope.StoreFloatData
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// struct FDataHubHandle                   DataTag                                                (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// float                                   Data                                                   (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UGolfItDataHubScope::StoreFloatData(const struct FDataHubHandle& DataTag, float Data)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "StoreFloatData");

	Params::GolfItDataHubScope_StoreFloatData Parms{};

	Parms.DataTag = std::move(DataTag);
	Parms.Data = Data;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function GolfItDataHub.GolfItDataHubScope.StoreGameplayTagData
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// struct FDataHubHandle                   DataHandle                                             (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// struct FGameplayTag                     Data                                                   (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UGolfItDataHubScope::StoreGameplayTagData(const struct FDataHubHandle& DataHandle, const struct FGameplayTag& Data)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "StoreGameplayTagData");

	Params::GolfItDataHubScope_StoreGameplayTagData Parms{};

	Parms.DataHandle = std::move(DataHandle);
	Parms.Data = std::move(Data);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function GolfItDataHub.GolfItDataHubScope.StoreIntArrayData
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// struct FDataHubHandle                   DataHandle                                             (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// TArray<int32>                           Data                                                   (Parm, OutParm, ZeroConstructor, ReferenceParm, NativeAccessSpecifierPublic)

void UGolfItDataHubScope::StoreIntArrayData(const struct FDataHubHandle& DataHandle, TArray<int32>& Data)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "StoreIntArrayData");

	Params::GolfItDataHubScope_StoreIntArrayData Parms{};

	Parms.DataHandle = std::move(DataHandle);
	Parms.Data = std::move(Data);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	Data = std::move(Parms.Data);
}


// Function GolfItDataHub.GolfItDataHubScope.StoreIntData
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// struct FDataHubHandle                   DataHandle                                             (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// int32                                   Data                                                   (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UGolfItDataHubScope::StoreIntData(const struct FDataHubHandle& DataHandle, int32 Data)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "StoreIntData");

	Params::GolfItDataHubScope_StoreIntData Parms{};

	Parms.DataHandle = std::move(DataHandle);
	Parms.Data = Data;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function GolfItDataHub.GolfItDataHubScope.StoreLongIntData
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// struct FDataHubHandle                   DataHandle                                             (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// int64                                   Data                                                   (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UGolfItDataHubScope::StoreLongIntData(const struct FDataHubHandle& DataHandle, int64 Data)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "StoreLongIntData");

	Params::GolfItDataHubScope_StoreLongIntData Parms{};

	Parms.DataHandle = std::move(DataHandle);
	Parms.Data = Data;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function GolfItDataHub.GolfItDataHubScope.StoreNameData
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// struct FDataHubHandle                   DataHandle                                             (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class FName                             Data                                                   (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UGolfItDataHubScope::StoreNameData(const struct FDataHubHandle& DataHandle, const class FName& Data)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "StoreNameData");

	Params::GolfItDataHubScope_StoreNameData Parms{};

	Parms.DataHandle = std::move(DataHandle);
	Parms.Data = Data;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function GolfItDataHub.GolfItDataHubScope.StoreWorkshopHandleData
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// struct FDataHubHandle                   DataHandle                                             (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// struct FSteamWorkshopItemHandle         Data                                                   (ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UGolfItDataHubScope::StoreWorkshopHandleData(const struct FDataHubHandle& DataHandle, const struct FSteamWorkshopItemHandle& Data)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "StoreWorkshopHandleData");

	Params::GolfItDataHubScope_StoreWorkshopHandleData Parms{};

	Parms.DataHandle = std::move(DataHandle);
	Parms.Data = std::move(Data);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function GolfItDataHub.GolfItDataHubScope.GetScopeTag
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// struct FGameplayTag                     ReturnValue                                            (Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

struct FGameplayTag UGolfItDataHubScope::GetScopeTag() const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubScope", "GetScopeTag");

	Params::GolfItDataHubScope_GetScopeTag Parms{};

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function GolfItDataHub.GolfItDataHubSubsystem.GetScope
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// EGenericOperationResult                 OutResult                                              (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// struct FGameplayTag                     ScopeTag                                               (Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class UGolfItDataHubScope*              ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

class UGolfItDataHubScope* UGolfItDataHubSubsystem::GetScope(EGenericOperationResult* OutResult, const struct FGameplayTag& ScopeTag)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GolfItDataHubSubsystem", "GetScope");

	Params::GolfItDataHubSubsystem_GetScope Parms{};

	Parms.ScopeTag = std::move(ScopeTag);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	if (OutResult != nullptr)
		*OutResult = Parms.OutResult;

	return Parms.ReturnValue;
}

}


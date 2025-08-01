#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: LobbySettings

#include "Basic.hpp"

#include "LobbySettings_classes.hpp"
#include "LobbySettings_parameters.hpp"


namespace SDK
{

// Function LobbySettings.LobbySettings_C.ApplyRecommendedSettings
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UCustomLevel_C*                   CustomLevel                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ALobbySettings_C::ApplyRecommendedSettings(class UCustomLevel_C* CustomLevel)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("LobbySettings_C", "ApplyRecommendedSettings");

	Params::LobbySettings_C_ApplyRecommendedSettings Parms{};

	Parms.CustomLevel = CustomLevel;

	UObject::ProcessEvent(Func, &Parms);
}

}


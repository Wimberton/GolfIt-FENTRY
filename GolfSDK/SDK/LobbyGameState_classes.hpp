#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: LobbyGameState

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GolfIt_structs.hpp"
#include "GolfIt_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass LobbyGameState.LobbyGameState_C
// 0x0010 (0x0310 - 0x0300)
class ALobbyGameState_C final : public AGolfItLobbyGameState
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0300(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x0308(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_LobbyGameState(int32 EntryPoint);
	void OpenGate();
	void CloseGate();
	void OnUpdateHoleOutOfTime();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"LobbyGameState_C">();
	}
	static class ALobbyGameState_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ALobbyGameState_C>();
	}
};

}


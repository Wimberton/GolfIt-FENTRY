#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: NiagaraAnimNotifies

#include "Basic.hpp"


namespace SDK::Params
{

// Function NiagaraAnimNotifies.AnimNotify_PlayNiagaraEffect.GetSpawnedEffect
// 0x0008 (0x0008 - 0x0000)
struct AnimNotify_PlayNiagaraEffect_GetSpawnedEffect final
{
public:
	class UFXSystemComponent*                     ReturnValue;                                       // 0x0000(0x0008)(ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function NiagaraAnimNotifies.AnimNotifyState_TimedNiagaraEffect.GetSpawnedEffect
// 0x0010 (0x0010 - 0x0000)
struct AnimNotifyState_TimedNiagaraEffect_GetSpawnedEffect final
{
public:
	class UMeshComponent*                         MeshComp;                                          // 0x0000(0x0008)(Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UFXSystemComponent*                     ReturnValue;                                       // 0x0008(0x0008)(ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function NiagaraAnimNotifies.AnimNotifyState_TimedNiagaraEffectAdvanced.GetNotifyProgress
// 0x0010 (0x0010 - 0x0000)
struct AnimNotifyState_TimedNiagaraEffectAdvanced_GetNotifyProgress final
{
public:
	class UMeshComponent*                         MeshComp;                                          // 0x0000(0x0008)(Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ReturnValue;                                       // 0x0008(0x0004)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_C[0x4];                                        // 0x000C(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

}


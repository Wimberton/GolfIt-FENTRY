#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: S_EditorInstancedMeshes

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "E_Editor_Themes_structs.hpp"


namespace SDK
{

// UserDefinedStruct S_EditorInstancedMeshes.S_EditorInstancedMeshes
// 0x0028 (0x0028 - 0x0000)
struct FS_EditorInstancedMeshes final
{
public:
	E_Editor_Themes                               Theme_30_8078C8384972F47C86D10C96C99C633A;         // 0x0000(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_1[0x3];                                        // 0x0001(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         DrawDistance_33_86D0AE0F4A31F5795554D5A5CB62DCBA;  // 0x0004(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UStaticMesh*                            StaticMesh_36_02DA0DE04E8F0B70636DDCAE5278CE0F;    // 0x0008(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          NoCollision_40_D6224A094109705BD044B3ACE546308E;   // 0x0010(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_11[0x7];                                       // 0x0011(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FTransform>                     SavedTransform_44_F08B6E174501D84C3B5C1D946EE59D6D; // 0x0018(0x0010)(Edit, BlueprintVisible)
};

}


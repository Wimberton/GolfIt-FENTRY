#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: DefaultCameraModifier

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function DefaultCameraModifier.DefaultCameraModifier_C.BlueprintModifyPostProcess
// 0x05C0 (0x05C0 - 0x0000)
struct DefaultCameraModifier_C_BlueprintModifyPostProcess final
{
public:
	float                                         DeltaTime;                                         // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         PostProcessBlendWeight;                            // 0x0004(0x0004)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_8[0x8];                                        // 0x0008(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPostProcessSettings                   PostProcessSettings;                               // 0x0010(0x0560)(Parm, OutParm)
	class UGolfItUserSettings*                    CallFunc_GetGolfItUserSettings_ReturnValue;        // 0x0570(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsBloomEnabled_ReturnValue;               // 0x0578(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_579[0x7];                                      // 0x0579(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UGolfItUserSettings*                    CallFunc_GetGolfItUserSettings_ReturnValue_1;      // 0x0580(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_GetSaturation_ReturnValue;                // 0x0588(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x058C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_58D[0x3];                                      // 0x058D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector4                               K2Node_MakeStruct_Vector4;                         // 0x0590(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_GetGamma_ReturnValue;                     // 0x05A0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5A4[0xC];                                      // 0x05A4(0x000C)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector4                               K2Node_MakeStruct_Vector4_1;                       // 0x05B0(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}


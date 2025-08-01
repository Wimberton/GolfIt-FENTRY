#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: EditorTransformStruct

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK
{

// UserDefinedStruct EditorTransformStruct.EditorTransformStruct
// 0x0090 (0x0090 - 0x0000)
struct FEditorTransformStruct final
{
public:
	float                                         StartDelay_2_B9E7F47C44E1088FB11EF4A388C9E5AA;     // 0x0000(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         PauseDelay_4_03EDA5184AC9EC801179C7A75B648506;     // 0x0004(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_8[0x8];                                        // 0x0008(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTransform                             StartLocalTransform_7_7A69BD464237500155E31184E08D3AFD; // 0x0010(0x0030)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor)
	struct FTransform                             EndLocalTransform_9_78FA2E5643B0D74420544CBBCCF1ECE8; // 0x0040(0x0030)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor)
	float                                         DurationForward_12_3E755D6643E08AA5EAD856A8A31EBA67; // 0x0070(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DurationBackward_14_E9FC1FB14DBE68CADA31B5A8A7D1608F; // 0x0074(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EEasingFunc                                   EaseMethodStart_17_C5B89A82485A0363ECBD65BBBA6C6629; // 0x0078(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EEasingFunc                                   EaseMethodEnd_19_74D6D80E49C674DEBB2A35A51E5E04B6; // 0x0079(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_7A[0x2];                                       // 0x007A(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         FinishedDelay_22_B60D14B24D7B4DCE3F85EC97D8A204F2; // 0x007C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UStaticMesh*                            StaticMesh_25_955D9C434DCFB1C1AC24B0BAC2931536;    // 0x0080(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Hole_28_9B12765B4791D6AF9AC2A0BCA48816D7;          // 0x0088(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         UniqueID_31_A86388114DE5027583DB19889D663918;      // 0x008C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}


#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: LiveLink

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "LiveLinkInterface_structs.hpp"


namespace SDK
{

// Enum LiveLink.ELiveLinkAxis
// NumValues: 0x0007
enum class ELiveLinkAxis : uint8
{
	X                                        = 0,
	Y                                        = 1,
	Z                                        = 2,
	XNeg                                     = 3,
	YNeg                                     = 4,
	ZNeg                                     = 5,
	ELiveLinkAxis_MAX                        = 6,
};

// Enum LiveLink.ELiveLinkTimecodeProviderEvaluationType
// NumValues: 0x0004
enum class ELiveLinkTimecodeProviderEvaluationType : uint32
{
	Lerp                                     = 0,
	Nearest                                  = 1,
	Latest                                   = 2,
	ELiveLinkTimecodeProviderEvaluationType_MAX = 3,
};

// ScriptStruct LiveLink.AnimNode_LiveLinkPose
// 0x0040 (0x0050 - 0x0010)
struct FAnimNode_LiveLinkPose final : public FAnimNode_Base
{
public:
	struct FPoseLink                              InputPose;                                         // 0x0010(0x0010)(Edit, BlueprintVisible, NoDestructor, NativeAccessSpecifierPublic)
	struct FLiveLinkSubjectName                   LiveLinkSubjectName;                               // 0x0020(0x0008)(Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TSubclassOf<class ULiveLinkRetargetAsset>     RetargetAsset;                                     // 0x0028(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoClear, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class ULiveLinkRetargetAsset*                 CurrentRetargetAsset;                              // 0x0030(0x0008)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_38[0x18];                                      // 0x0038(0x0018)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct LiveLink.LiveLinkInstanceProxy
// 0x0050 (0x07C0 - 0x0770)
struct FLiveLinkInstanceProxy final : public FAnimInstanceProxy
{
public:
	struct FAnimNode_LiveLinkPose                 PoseNode;                                          // 0x0770(0x0050)(Edit, NativeAccessSpecifierPublic)
};

// ScriptStruct LiveLink.ProviderPollResult
// 0x0038 (0x0038 - 0x0000)
struct FProviderPollResult final
{
public:
	uint8                                         Pad_0[0x10];                                       // 0x0000(0x0010)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 Name;                                              // 0x0010(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 MachineName;                                       // 0x0020(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	double                                        MachineTimeOffset;                                 // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct LiveLink.LiveLinkRetargetAssetReference
// 0x0001 (0x0001 - 0x0000)
struct FLiveLinkRetargetAssetReference final
{
public:
	uint8                                         Pad_0[0x1];                                        // 0x0000(0x0001)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct LiveLink.LiveLinkRoleProjectSetting
// 0x0028 (0x0028 - 0x0000)
struct FLiveLinkRoleProjectSetting final
{
public:
	TSubclassOf<class ULiveLinkRole>              Role;                                              // 0x0000(0x0008)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TSubclassOf<class ULiveLinkSubjectSettings>   SettingClass;                                      // 0x0008(0x0008)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TSubclassOf<class ULiveLinkFrameInterpolationProcessor> FrameInterpolationProcessor;                       // 0x0010(0x0008)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<TSubclassOf<class ULiveLinkFramePreProcessor>> FramePreProcessors;                                // 0x0018(0x0010)(Edit, ZeroConstructor, Config, UObjectWrapper, NativeAccessSpecifierPublic)
};

}


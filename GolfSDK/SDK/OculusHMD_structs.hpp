#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: OculusHMD

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"


namespace SDK
{

// Enum OculusHMD.EOculusDeviceType
// NumValues: 0x0009
enum class EOculusDeviceType : uint8
{
	OculusMobile_Deprecated0                 = 0,
	OculusQuest                              = 1,
	OculusQuest2                             = 2,
	Rift                                     = 100,
	Rift_S                                   = 101,
	Quest_Link                               = 102,
	Quest2_Link                              = 103,
	OculusUnknown                            = 200,
	EOculusDeviceType_MAX                    = 201,
};

// Enum OculusHMD.EHandTrackingSupport
// NumValues: 0x0004
enum class EHandTrackingSupport : uint8
{
	ControllersOnly                          = 0,
	ControllersAndHands                      = 1,
	HandsOnly                                = 2,
	EHandTrackingSupport_MAX                 = 3,
};

// Enum OculusHMD.EColorSpace
// NumValues: 0x000A
enum class EColorSpace : uint8
{
	Unknown                                  = 0,
	Unmanaged                                = 1,
	Rec_2020                                 = 2,
	Rec_709                                  = 3,
	Rift_CV1                                 = 4,
	Rift_S                                   = 5,
	Quest                                    = 6,
	P3                                       = 7,
	Adobe_RGB                                = 8,
	EColorSpace_MAX                          = 9,
};

// Enum OculusHMD.EBoundaryType
// NumValues: 0x0003
enum class EBoundaryType : uint8
{
	Boundary_Outer                           = 0,
	Boundary_PlayArea                        = 1,
	Boundary_MAX                             = 2,
};

// Enum OculusHMD.EFixedFoveatedRenderingLevel
// NumValues: 0x0006
enum class EFixedFoveatedRenderingLevel : uint8
{
	FFR_Off                                  = 0,
	FFR_Low                                  = 1,
	FFR_Medium                               = 2,
	FFR_High                                 = 3,
	FFR_HighTop                              = 4,
	FFR_MAX                                  = 5,
};

// Enum OculusHMD.ETrackedDeviceType
// NumValues: 0x0008
enum class ETrackedDeviceType : uint8
{
	None                                     = 0,
	HMD                                      = 1,
	LTouch                                   = 2,
	RTouch                                   = 3,
	Touch                                    = 4,
	DeviceObjectZero                         = 5,
	All                                      = 6,
	ETrackedDeviceType_MAX                   = 7,
};

// ScriptStruct OculusHMD.GuardianTestResult
// 0x0020 (0x0020 - 0x0000)
struct FGuardianTestResult final
{
public:
	bool                                          IsTriggering;                                      // 0x0000(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	ETrackedDeviceType                            DeviceType;                                        // 0x0001(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_2[0x2];                                        // 0x0002(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         ClosestDistance;                                   // 0x0004(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector                                ClosestPoint;                                      // 0x0008(0x000C)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector                                ClosestPointNormal;                                // 0x0014(0x000C)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct OculusHMD.HmdUserProfileField
// 0x0020 (0x0020 - 0x0000)
struct FHmdUserProfileField final
{
public:
	class FString                                 FieldName;                                         // 0x0000(0x0010)(BlueprintVisible, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 FieldValue;                                        // 0x0010(0x0010)(BlueprintVisible, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct OculusHMD.HmdUserProfile
// 0x0048 (0x0048 - 0x0000)
struct FHmdUserProfile final
{
public:
	class FString                                 Name;                                              // 0x0000(0x0010)(BlueprintVisible, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 Gender;                                            // 0x0010(0x0010)(BlueprintVisible, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         PlayerHeight;                                      // 0x0020(0x0004)(BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         EyeHeight;                                         // 0x0024(0x0004)(BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         IPD;                                               // 0x0028(0x0004)(BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector2D                              NeckToEyeDistance;                                 // 0x002C(0x0008)(BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_34[0x4];                                       // 0x0034(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FHmdUserProfileField>           ExtraFields;                                       // 0x0038(0x0010)(BlueprintVisible, ZeroConstructor, NativeAccessSpecifierPublic)
};

// ScriptStruct OculusHMD.OculusSplashDesc
// 0x00A0 (0x00A0 - 0x0000)
struct FOculusSplashDesc final
{
public:
	struct FSoftObjectPath                        TexturePath;                                       // 0x0000(0x0018)(Edit, ZeroConstructor, Config, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_18[0x8];                                       // 0x0018(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTransform                             TransformInMeters;                                 // 0x0020(0x0030)(Edit, Config, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
	struct FVector2D                              QuadSizeInMeters;                                  // 0x0050(0x0008)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_58[0x8];                                       // 0x0058(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FQuat                                  DeltaRotation;                                     // 0x0060(0x0010)(Edit, Config, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
	struct FVector2D                              TextureOffset;                                     // 0x0070(0x0008)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector2D                              TextureScale;                                      // 0x0078(0x0008)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bNoAlphaChannel;                                   // 0x0080(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_81[0x1F];                                      // 0x0081(0x001F)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

}


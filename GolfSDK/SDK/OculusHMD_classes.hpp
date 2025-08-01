#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: OculusHMD

#include "Basic.hpp"

#include "Engine_classes.hpp"
#include "CoreUObject_classes.hpp"
#include "HeadMountedDisplay_structs.hpp"
#include "OculusHMD_structs.hpp"


namespace SDK
{

// Class OculusHMD.OculusFunctionLibrary
// 0x0000 (0x0028 - 0x0028)
class UOculusFunctionLibrary final : public UBlueprintFunctionLibrary
{
public:
	static void AddLoadingSplashScreen(class UTexture2D* Texture, const struct FVector& TranslationInMeters, const struct FRotator& Rotation, const struct FVector2D& SizeInMeters, const struct FRotator& DeltaRotation, bool bClearBeforeAdd);
	static void ClearLoadingSplashScreens();
	static void EnableOrientationTracking(bool bOrientationTracking);
	static void EnablePositionTracking(bool bPositionTracking);
	static TArray<float> GetAvailableDisplayFrequencies();
	static void GetBaseRotationAndBaseOffsetInMeters(struct FRotator* OutRotation, struct FVector* OutBaseOffsetInMeters);
	static void GetBaseRotationAndPositionOffset(struct FRotator* OutRot, struct FVector* OutPosOffset);
	static float GetCurrentDisplayFrequency();
	static class FString GetDeviceName();
	static EOculusDeviceType GetDeviceType();
	static EFixedFoveatedRenderingLevel GetFixedFoveatedRenderingLevel();
	static float GetGPUFrameTime();
	static void GetGPUUtilization(bool* IsGPUAvailable, float* GPUUtilization);
	static struct FVector GetGuardianDimensions(EBoundaryType BoundaryType);
	static TArray<struct FVector> GetGuardianPoints(EBoundaryType BoundaryType, bool UsePawnSpace);
	static EColorSpace GetHmdColorDesc();
	static struct FGuardianTestResult GetNodeGuardianIntersection(ETrackedDeviceType DeviceType, EBoundaryType BoundaryType);
	static struct FTransform GetPlayAreaTransform();
	static struct FGuardianTestResult GetPointGuardianIntersection(const struct FVector& Point, EBoundaryType BoundaryType);
	static void GetPose(struct FRotator* DeviceRotation, struct FVector* DevicePosition, struct FVector* NeckPosition, bool bUseOrienationForPlayerCamera, bool bUsePositionForPlayerCamera, const struct FVector& PositionScale);
	static void GetRawSensorData(struct FVector* AngularAcceleration, struct FVector* LinearAcceleration, struct FVector* AngularVelocity, struct FVector* LinearVelocity, float* TimeInSeconds, ETrackedDeviceType DeviceType);
	static bool GetSystemHmd3DofModeEnabled();
	static bool GetUserProfile(struct FHmdUserProfile* Profile);
	static bool HasInputFocus();
	static bool HasSystemOverlayPresent();
	static bool IsDeviceTracked(ETrackedDeviceType DeviceType);
	static bool IsGuardianConfigured();
	static bool IsGuardianDisplayed();
	static void SetBaseRotationAndBaseOffsetInMeters(const struct FRotator& Rotation, const struct FVector& BaseOffsetInMeters, EOrientPositionSelector Options);
	static void SetBaseRotationAndPositionOffset(const struct FRotator& BaseRot, const struct FVector& PosOffset, EOrientPositionSelector Options);
	static void SetClientColorDesc(EColorSpace ColorSpace);
	static void SetColorScaleAndOffset(const struct FLinearColor& ColorScale, const struct FLinearColor& ColorOffset, bool bApplyToAllLayers);
	static void SetCPUAndGPULevels(int32 CPULevel, int32 GPULevel);
	static void SetDisplayFrequency(float RequestedFrequency);
	static void SetFixedFoveatedRenderingLevel(EFixedFoveatedRenderingLevel Level, bool IsDynamic);
	static void SetGuardianVisibility(bool GuardianVisible);
	static void SetPositionScale3D(const struct FVector& PosScale3D);
	static void SetReorientHMDOnControllerRecenter(bool RecenterMode);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"OculusFunctionLibrary">();
	}
	static class UOculusFunctionLibrary* GetDefaultObj()
	{
		return GetDefaultObjImpl<UOculusFunctionLibrary>();
	}
};

// Class OculusHMD.OculusHMDRuntimeSettings
// 0x0040 (0x0068 - 0x0028)
class UOculusHMDRuntimeSettings final : public UObject
{
public:
	bool                                          bAutoEnabled;                                      // 0x0028(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FOculusSplashDesc>              SplashDescs;                                       // 0x0030(0x0010)(Edit, ZeroConstructor, Config, NativeAccessSpecifierPublic)
	bool                                          bEnableSpecificColorGamut;                         // 0x0040(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EColorSpace                                   ColorSpace;                                        // 0x0041(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bSupportsDash;                                     // 0x0042(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bCompositesDepth;                                  // 0x0043(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bHQDistortion;                                     // 0x0044(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_45[0x3];                                       // 0x0045(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         PixelDensityMin;                                   // 0x0048(0x0004)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         PixelDensityMax;                                   // 0x004C(0x0004)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         CPULevel;                                          // 0x0050(0x0004)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         GPULevel;                                          // 0x0054(0x0004)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EFixedFoveatedRenderingLevel                  FFRLevel;                                          // 0x0058(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          FFRDynamic;                                        // 0x0059(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bChromaCorrection;                                 // 0x005A(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bRecenterHMDWithController;                        // 0x005B(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bFocusAware;                                       // 0x005C(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bLateLatching;                                     // 0x005D(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bRequiresSystemKeyboard;                           // 0x005E(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EHandTrackingSupport                          HandTrackingSupport;                               // 0x005F(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bPhaseSync;                                        // 0x0060(0x0001)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_61[0x7];                                       // 0x0061(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"OculusHMDRuntimeSettings">();
	}
	static class UOculusHMDRuntimeSettings* GetDefaultObj()
	{
		return GetDefaultObjImpl<UOculusHMDRuntimeSettings>();
	}
};

// Class OculusHMD.OculusResourceHolder
// 0x0008 (0x0030 - 0x0028)
class UOculusResourceHolder final : public UObject
{
public:
	class UMaterial*                              PokeAHoleMaterial;                                 // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"OculusResourceHolder">();
	}
	static class UOculusResourceHolder* GetDefaultObj()
	{
		return GetDefaultObjImpl<UOculusResourceHolder>();
	}
};

// Class OculusHMD.OculusSceneCaptureCubemap
// 0x0068 (0x0090 - 0x0028)
class alignas(0x10) UOculusSceneCaptureCubemap final : public UObject
{
public:
	uint8                                         Pad_28[0x10];                                      // 0x0028(0x0010)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class USceneCaptureComponent2D*>       CaptureComponents;                                 // 0x0038(0x0010)(ExportObject, ZeroConstructor, ContainsInstancedReference, NativeAccessSpecifierPrivate)
	uint8                                         Pad_48[0x48];                                      // 0x0048(0x0048)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"OculusSceneCaptureCubemap">();
	}
	static class UOculusSceneCaptureCubemap* GetDefaultObj()
	{
		return GetDefaultObjImpl<UOculusSceneCaptureCubemap>();
	}
};

}


#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: BI_WaterInterface

#include "Basic.hpp"

#include "CoreUObject_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BI_WaterInterface.BI_WaterInterface_C
// 0x0000 (0x0028 - 0x0028)
class IBI_WaterInterface_C final : public IInterface
{
public:
	void IsWaterObject(class AGolfBall_C* Ball, class UPrimitiveComponent* HitComponent, int32 ElementIndex, bool* WaterObject, bool* UseNewWaterNormal, struct FVector* NewWaterEffectNormal, bool* ShouldResultInReset_, bool* NoFX);
	void SetWaterVisibility(bool NewVisibility, int32 MaterialIndex);
	void GetWaterVisibility(bool* IsVisible, int32* MaterialIndex);
	void GetIsCameraInUnderwaterEffectSphere(bool* Yes);
	void UseBuoyancy(bool Buoyancy);
	void GetBuoyancy(bool* Buoyancy);
	void GetWaterColor();
	void SetWaterColor();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BI_WaterInterface_C">();
	}
	static class IBI_WaterInterface_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<IBI_WaterInterface_C>();
	}
};

}


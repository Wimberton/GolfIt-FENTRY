#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: EditorPlanetBP

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "PlanetStruct_structs.hpp"
#include "PlanetEnum_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass EditorPlanetBP.EditorPlanetBP_C
// 0x04C8 (0x06E8 - 0x0220)
class AEditorPlanetBP_C final : public AActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0220(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UPointLightComponent*                   PointLight;                                        // 0x0228(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UChildActorComponent*                   ChildActor;                                        // 0x0230(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   Planet;                                            // 0x0238(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	struct FPlanetStruct                          PlanetStruct;                                      // 0x0240(0x0440)(Edit, BlueprintVisible, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               PlanetMaterial;                                    // 0x0680(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class UTexture2D*>                     FractalMasksArray;                                 // 0x0688(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<class UTexture2D*>                     StripeMasksArray;                                  // 0x0698(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<class UTexture2D*>                     CraterNormalArray;                                 // 0x06A8(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	class UMaterialInstanceDynamic*               AtmosphereMaterial;                                // 0x06B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TSoftObjectPtr<class UStaticMesh>             SoftStaticMeshPlanetRef;                           // 0x06C0(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_EditorPlanetBP(int32 EntryPoint);
	void UsePlanetStructMulticastReliable(const struct FPlanetStruct& Struct);
	void UsePlanetStructMulticast(const struct FPlanetStruct& Struct);
	void UsePlanetStructServer(const struct FPlanetStruct& Struct, bool Reliable);
	void GeneratePlanet(bool New);
	void SetWaterColor();
	void GetWaterColor();
	void UseBuoyancy(bool Buoyancy);
	void SetWaterVisibility(bool NewVisibility, int32 MaterialIndex);
	void UserConstructionScript();
	void GenerateNewPlanet();
	void GeneratePlanetFromStruct();
	void SetPlanetMaterialSettings();
	void SetSunMaterialSettings();
	void SetWaterMaterialSettings();
	void SetMoonMaterialSettings();
	void SetGasMaterialSettings();
	void GenerateMasksArrays();
	void SetAlienMaterialSettings();
	void SetLavaMaterialSettings();
	void GetRandomAlien(struct FPlanet_Alien_MaterialStruct* RandomAlien);
	void GetRandomMoon(struct FPlanet_Moon_MaterialStruct* RandomMoon);
	void GetRandomPlanet(struct FPlanet_Planet_MaterialStruct* RandomPlanet);
	void GetRandomSun(struct FPlanet_Sun_MaterialStruct* RandomSun);
	void GetRandomWater(struct FPlanet_Water_MaterialStruct* RandomWater);
	void GetRandomGas(struct FPlanet_Gas_MaterialStruct* RandomGas);
	void GetRandomLava(struct FPlanet_Lava_MaterialStruct* RandomLava);
	void SetMaterial(TSoftObjectPtr<class UObject> Asset);
	void IsWaterObject(class AGolfBall_C* Ball, class UPrimitiveComponent* HitComponent, int32 ElementIndex, bool* WaterObject, bool* UseNewWaterNormal, struct FVector* NewWaterEffectNormal, bool* ShouldResultInReset_, bool* NoFX);
	void GetWaterVisibility(bool* IsVisible, int32* MaterialIndex);
	void GetIsCameraInUnderwaterEffectSphere(bool* Yes);
	void GetBuoyancy(bool* Buoyancy);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"EditorPlanetBP_C">();
	}
	static class AEditorPlanetBP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AEditorPlanetBP_C>();
	}
};

}


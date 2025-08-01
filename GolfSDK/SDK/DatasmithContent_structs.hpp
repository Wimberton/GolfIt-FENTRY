#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: DatasmithContent

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"
#include "CinematicCamera_structs.hpp"


namespace SDK
{

// Enum DatasmithContent.EDatasmithAreaLightActorType
// NumValues: 0x0004
enum class EDatasmithAreaLightActorType : uint8
{
	Point                                    = 0,
	Spot                                     = 1,
	Rect                                     = 2,
	EDatasmithAreaLightActorType_MAX         = 3,
};

// Enum DatasmithContent.EDatasmithAreaLightActorShape
// NumValues: 0x0006
enum class EDatasmithAreaLightActorShape : uint8
{
	Rectangle                                = 0,
	Disc                                     = 1,
	Sphere                                   = 2,
	Cylinder                                 = 3,
	None                                     = 4,
	EDatasmithAreaLightActorShape_MAX        = 5,
};

// Enum DatasmithContent.EDatasmithCADRetessellationRule
// NumValues: 0x0003
enum class EDatasmithCADRetessellationRule : uint8
{
	All                                      = 0,
	SkipDeletedSurfaces                      = 1,
	EDatasmithCADRetessellationRule_MAX      = 2,
};

// Enum DatasmithContent.EDatasmithCADStitchingTechnique
// NumValues: 0x0004
enum class EDatasmithCADStitchingTechnique : uint8
{
	StitchingNone                            = 0,
	StitchingHeal                            = 1,
	StitchingSew                             = 2,
	EDatasmithCADStitchingTechnique_MAX      = 3,
};

// Enum DatasmithContent.EDatasmithImportScene
// NumValues: 0x0004
enum class EDatasmithImportScene : uint8
{
	NewLevel                                 = 0,
	CurrentLevel                             = 1,
	AssetsOnly                               = 2,
	EDatasmithImportScene_MAX                = 3,
};

// Enum DatasmithContent.EDatasmithImportLightmapMax
// NumValues: 0x0008
enum class EDatasmithImportLightmapMax : uint8
{
	LIGHTMAP_64                              = 0,
	LIGHTMAP_128                             = 1,
	LIGHTMAP_256                             = 2,
	LIGHTMAP_512                             = 3,
	LIGHTMAP_1024                            = 4,
	LIGHTMAP_2048                            = 5,
	LIGHTMAP_4096                            = 6,
	LIGHTMAP_MAX                             = 7,
};

// Enum DatasmithContent.EDatasmithImportLightmapMin
// NumValues: 0x0007
enum class EDatasmithImportLightmapMin : uint8
{
	LIGHTMAP_16                              = 0,
	LIGHTMAP_32                              = 1,
	LIGHTMAP_64                              = 2,
	LIGHTMAP_128                             = 3,
	LIGHTMAP_256                             = 4,
	LIGHTMAP_512                             = 5,
	LIGHTMAP_MAX                             = 6,
};

// Enum DatasmithContent.EDatasmithImportMaterialQuality
// NumValues: 0x0004
enum class EDatasmithImportMaterialQuality : uint8
{
	UseNoFresnelCurves                       = 0,
	UseSimplifierFresnelCurves               = 1,
	UseRealFresnelCurves                     = 2,
	EDatasmithImportMaterialQuality_MAX      = 3,
};

// Enum DatasmithContent.EDatasmithImportActorPolicy
// NumValues: 0x0004
enum class EDatasmithImportActorPolicy : uint8
{
	Update                                   = 0,
	Full                                     = 1,
	Ignore                                   = 2,
	EDatasmithImportActorPolicy_MAX          = 3,
};

// Enum DatasmithContent.EDatasmithImportAssetConflictPolicy
// NumValues: 0x0005
enum class EDatasmithImportAssetConflictPolicy : uint8
{
	Replace                                  = 0,
	Update                                   = 1,
	Use                                      = 2,
	Ignore                                   = 3,
	EDatasmithImportAssetConflictPolicy_MAX  = 4,
};

// Enum DatasmithContent.EDatasmithImportSearchPackagePolicy
// NumValues: 0x0003
enum class EDatasmithImportSearchPackagePolicy : uint8
{
	Current                                  = 0,
	All                                      = 1,
	EDatasmithImportSearchPackagePolicy_MAX  = 2,
};

// ScriptStruct DatasmithContent.DatasmithCameraLookatTrackingSettingsTemplate
// 0x0030 (0x0030 - 0x0000)
struct FDatasmithCameraLookatTrackingSettingsTemplate final
{
public:
	uint8                                         bEnableLookAtTracking : 1;                         // 0x0000(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         bAllowRoll : 1;                                    // 0x0000(0x0001)(BitIndex: 0x01, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Pad_1[0x7];                                        // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TSoftObjectPtr<class AActor>                  ActorToTrack;                                      // 0x0008(0x0028)(UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct DatasmithContent.DatasmithPostProcessSettingsTemplate
// 0x0040 (0x0040 - 0x0000)
struct FDatasmithPostProcessSettingsTemplate final
{
public:
	uint8                                         bOverride_WhiteTemp : 1;                           // 0x0000(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         bOverride_ColorSaturation : 1;                     // 0x0000(0x0001)(BitIndex: 0x01, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         bOverride_VignetteIntensity : 1;                   // 0x0000(0x0001)(BitIndex: 0x02, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         bOverride_FilmWhitePoint : 1;                      // 0x0000(0x0001)(BitIndex: 0x03, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         bOverride_AutoExposureMethod : 1;                  // 0x0000(0x0001)(BitIndex: 0x04, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         bOverride_CameraISO : 1;                           // 0x0000(0x0001)(BitIndex: 0x05, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         bOverride_CameraShutterSpeed : 1;                  // 0x0000(0x0001)(BitIndex: 0x06, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         BitPad_0_7 : 1;                                    // 0x0000(0x0001)(Fixing Bit-Field Size For New Byte [ Dumper-7 ])
	uint8                                         Pad_1[0x3];                                        // 0x0001(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	uint8                                         bOverride_DepthOfFieldFstop : 1;                   // 0x0004(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Pad_5[0x3];                                        // 0x0005(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         WhiteTemp;                                         // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         VignetteIntensity;                                 // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FLinearColor                           FilmWhitePoint;                                    // 0x0010(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector4                               ColorSaturation;                                   // 0x0020(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EAutoExposureMethod                           AutoExposureMethod;                                // 0x0030(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_31[0x3];                                       // 0x0031(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CameraISO;                                         // 0x0034(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         CameraShutterSpeed;                                // 0x0038(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         DepthOfFieldFstop;                                 // 0x003C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct DatasmithContent.DatasmithCameraFocusSettingsTemplate
// 0x0008 (0x0008 - 0x0000)
struct FDatasmithCameraFocusSettingsTemplate final
{
public:
	ECameraFocusMethod                            FocusMethod;                                       // 0x0000(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1[0x3];                                        // 0x0001(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         ManualFocusDistance;                               // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct DatasmithContent.DatasmithCameraLensSettingsTemplate
// 0x0004 (0x0004 - 0x0000)
struct FDatasmithCameraLensSettingsTemplate final
{
public:
	float                                         MaxFStop;                                          // 0x0000(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct DatasmithContent.DatasmithCameraFilmbackSettingsTemplate
// 0x0008 (0x0008 - 0x0000)
struct FDatasmithCameraFilmbackSettingsTemplate final
{
public:
	float                                         SensorWidth;                                       // 0x0000(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         SensorHeight;                                      // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct DatasmithContent.DatasmithTessellationOptions
// 0x0010 (0x0010 - 0x0000)
struct FDatasmithTessellationOptions
{
public:
	float                                         ChordTolerance;                                    // 0x0000(0x0004)(Edit, BlueprintVisible, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         MaxEdgeLength;                                     // 0x0004(0x0004)(Edit, BlueprintVisible, ZeroConstructor, Config, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         NormalTolerance;                                   // 0x0008(0x0004)(Edit, BlueprintVisible, ZeroConstructor, Config, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EDatasmithCADStitchingTechnique               StitchingTechnique;                                // 0x000C(0x0001)(Edit, BlueprintVisible, ZeroConstructor, Config, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_D[0x3];                                        // 0x000D(0x0003)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct DatasmithContent.DatasmithRetessellationOptions
// 0x0004 (0x0014 - 0x0010)
struct FDatasmithRetessellationOptions final : public FDatasmithTessellationOptions
{
public:
	EDatasmithCADRetessellationRule               RetessellationRule;                                // 0x0010(0x0001)(Edit, BlueprintVisible, ZeroConstructor, Config, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_11[0x3];                                       // 0x0011(0x0003)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct DatasmithContent.DatasmithAssetImportOptions
// 0x0008 (0x0008 - 0x0000)
struct FDatasmithAssetImportOptions final
{
public:
	class FName                                   PackagePath;                                       // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct DatasmithContent.DatasmithStaticMeshImportOptions
// 0x0004 (0x0004 - 0x0000)
struct FDatasmithStaticMeshImportOptions final
{
public:
	EDatasmithImportLightmapMin                   MinLightmapResolution;                             // 0x0000(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EDatasmithImportLightmapMax                   MaxLightmapResolution;                             // 0x0001(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bGenerateLightmapUVs;                              // 0x0002(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bRemoveDegenerates;                                // 0x0003(0x0001)(BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct DatasmithContent.DatasmithImportBaseOptions
// 0x0014 (0x0014 - 0x0000)
struct FDatasmithImportBaseOptions final
{
public:
	EDatasmithImportScene                         SceneHandling;                                     // 0x0000(0x0001)(BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bIncludeGeometry;                                  // 0x0001(0x0001)(Edit, BlueprintVisible, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bIncludeMaterial;                                  // 0x0002(0x0001)(Edit, BlueprintVisible, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bIncludeLight;                                     // 0x0003(0x0001)(Edit, BlueprintVisible, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bIncludeCamera;                                    // 0x0004(0x0001)(Edit, BlueprintVisible, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bIncludeAnimation;                                 // 0x0005(0x0001)(Edit, BlueprintVisible, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_6[0x2];                                        // 0x0006(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	struct FDatasmithAssetImportOptions           AssetOptions;                                      // 0x0008(0x0008)(BlueprintVisible, NoDestructor, AdvancedDisplay, NativeAccessSpecifierPublic)
	struct FDatasmithStaticMeshImportOptions      StaticMeshOptions;                                 // 0x0010(0x0004)(Edit, BlueprintVisible, Config, NoDestructor, AdvancedDisplay, NativeAccessSpecifierPublic)
};

// ScriptStruct DatasmithContent.DatasmithReimportOptions
// 0x0002 (0x0002 - 0x0000)
struct FDatasmithReimportOptions final
{
public:
	bool                                          bUpdateActors;                                     // 0x0000(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bRespawnDeletedActors;                             // 0x0001(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct DatasmithContent.DatasmithStaticParameterSetTemplate
// 0x0050 (0x0050 - 0x0000)
struct FDatasmithStaticParameterSetTemplate final
{
public:
	TMap<class FName, bool>                       StaticSwitchParameters;                            // 0x0000(0x0050)(NativeAccessSpecifierPublic)
};

// ScriptStruct DatasmithContent.DatasmithMeshSectionInfoTemplate
// 0x0004 (0x0004 - 0x0000)
struct FDatasmithMeshSectionInfoTemplate final
{
public:
	int32                                         MaterialIndex;                                     // 0x0000(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct DatasmithContent.DatasmithMeshSectionInfoMapTemplate
// 0x0050 (0x0050 - 0x0000)
struct FDatasmithMeshSectionInfoMapTemplate final
{
public:
	TMap<uint32, struct FDatasmithMeshSectionInfoTemplate> Map;                                               // 0x0000(0x0050)(NativeAccessSpecifierPublic)
};

// ScriptStruct DatasmithContent.DatasmithStaticMaterialTemplate
// 0x0010 (0x0010 - 0x0000)
struct FDatasmithStaticMaterialTemplate final
{
public:
	class FName                                   MaterialSlotName;                                  // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UMaterialInterface*                     MaterialInterface;                                 // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct DatasmithContent.DatasmithMeshBuildSettingsTemplate
// 0x0010 (0x0010 - 0x0000)
struct FDatasmithMeshBuildSettingsTemplate final
{
public:
	uint8                                         bUseMikkTSpace : 1;                                // 0x0000(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         bRecomputeNormals : 1;                             // 0x0000(0x0001)(BitIndex: 0x01, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         bRecomputeTangents : 1;                            // 0x0000(0x0001)(BitIndex: 0x02, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         bRemoveDegenerates : 1;                            // 0x0000(0x0001)(BitIndex: 0x03, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         bBuildAdjacencyBuffer : 1;                         // 0x0000(0x0001)(BitIndex: 0x04, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         bUseHighPrecisionTangentBasis : 1;                 // 0x0000(0x0001)(BitIndex: 0x05, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         bUseFullPrecisionUVs : 1;                          // 0x0000(0x0001)(BitIndex: 0x06, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         bGenerateLightmapUVs : 1;                          // 0x0000(0x0001)(BitIndex: 0x07, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Pad_1[0x3];                                        // 0x0001(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         MinLightmapResolution;                             // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         SrcLightmapIndex;                                  // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         DstLightmapIndex;                                  // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

}


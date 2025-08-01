#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: LevelSequence

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "MovieScene_structs.hpp"


namespace SDK
{

// ScriptStruct LevelSequence.LevelSequenceCameraSettings
// 0x0002 (0x0002 - 0x0000)
struct FLevelSequenceCameraSettings final
{
public:
	bool                                          bOverrideAspectRatioAxisConstraint;                // 0x0000(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EAspectRatioAxisConstraint                    AspectRatioAxisConstraint;                         // 0x0001(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct LevelSequence.BoundActorProxy
// 0x0001 (0x0001 - 0x0000)
struct FBoundActorProxy final
{
public:
	uint8                                         Pad_0[0x1];                                        // 0x0000(0x0001)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct LevelSequence.LevelSequenceAnimSequenceLinkItem
// 0x0030 (0x0030 - 0x0000)
struct FLevelSequenceAnimSequenceLinkItem final
{
public:
	struct FGuid                                  SkelTrackGuid;                                     // 0x0000(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FSoftObjectPath                        PathToAnimSequence;                                // 0x0010(0x0018)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bExportTransforms;                                 // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bExportCurves;                                     // 0x0029(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bRecordInWorldSpace;                               // 0x002A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_2B[0x5];                                       // 0x002B(0x0005)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct LevelSequence.LevelSequenceBindingReference
// 0x0038 (0x0038 - 0x0000)
struct FLevelSequenceBindingReference final
{
public:
	class FString                                 PackageName;                                       // 0x0000(0x0010)(ZeroConstructor, Deprecated, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	struct FSoftObjectPath                        ExternalObjectPath;                                // 0x0010(0x0018)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class FString                                 ObjectPath;                                        // 0x0028(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
};

// ScriptStruct LevelSequence.LevelSequenceBindingReferenceArray
// 0x0010 (0x0010 - 0x0000)
struct FLevelSequenceBindingReferenceArray final
{
public:
	TArray<struct FLevelSequenceBindingReference> References;                                        // 0x0000(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
};

// ScriptStruct LevelSequence.LevelSequenceBindingReferences
// 0x00A0 (0x00A0 - 0x0000)
struct FLevelSequenceBindingReferences final
{
public:
	TMap<struct FGuid, struct FLevelSequenceBindingReferenceArray> BindingIdToReferences;                             // 0x0000(0x0050)(NativeAccessSpecifierPrivate)
	TSet<struct FGuid>                            AnimSequenceInstances;                             // 0x0050(0x0050)(NativeAccessSpecifierPrivate)
};

// ScriptStruct LevelSequence.LevelSequenceObjectReferenceMap
// 0x0050 (0x0050 - 0x0000)
struct alignas(0x08) FLevelSequenceObjectReferenceMap final
{
public:
	uint8                                         Pad_0[0x50];                                       // 0x0000(0x0050)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct LevelSequence.LevelSequenceLegacyObjectReference
// 0x0020 (0x0020 - 0x0000)
struct alignas(0x08) FLevelSequenceLegacyObjectReference final
{
public:
	uint8                                         Pad_0[0x20];                                       // 0x0000(0x0020)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct LevelSequence.LevelSequenceObject
// 0x0038 (0x0038 - 0x0000)
struct FLevelSequenceObject final
{
public:
	TLazyObjectPtr<class UObject>                 ObjectOrOwner;                                     // 0x0000(0x001C)(IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_1C[0x4];                                       // 0x001C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 ComponentName;                                     // 0x0020(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	TWeakObjectPtr<class UObject>                 CachedComponent;                                   // 0x0030(0x0008)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
};

// ScriptStruct LevelSequence.LevelSequenceSnapshotSettings
// 0x000C (0x000C - 0x0000)
struct FLevelSequenceSnapshotSettings final
{
public:
	uint8                                         ZeroPadAmount;                                     // 0x0000(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1[0x3];                                        // 0x0001(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FFrameRate                             FrameRate;                                         // 0x0004(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct LevelSequence.LevelSequencePlayerSnapshot
// 0x00B8 (0x00B8 - 0x0000)
struct FLevelSequencePlayerSnapshot final
{
public:
	class FString                                 MasterName;                                        // 0x0000(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FQualifiedFrameTime                    MasterTime;                                        // 0x0010(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, EditConst, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FQualifiedFrameTime                    SourceTime;                                        // 0x0020(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, EditConst, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 CurrentShotName;                                   // 0x0030(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FQualifiedFrameTime                    CurrentShotLocalTime;                              // 0x0040(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, EditConst, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FQualifiedFrameTime                    CurrentShotSourceTime;                             // 0x0050(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, EditConst, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 SourceTimecode;                                    // 0x0060(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TSoftObjectPtr<class UCameraComponent>        CameraComponent;                                   // 0x0070(0x0028)(Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, EditConst, InstancedReference, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FLevelSequenceSnapshotSettings         Settings;                                          // 0x0098(0x000C)(Edit, BlueprintVisible, BlueprintReadOnly, EditConst, NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_A4[0x4];                                       // 0x00A4(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class ULevelSequence*                         ActiveShot;                                        // 0x00A8(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FMovieSceneSequenceID                  ShotID;                                            // 0x00B0(0x0004)(NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_B4[0x4];                                       // 0x00B4(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

}


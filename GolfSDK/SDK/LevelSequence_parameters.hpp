#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: LevelSequence

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "MovieScene_structs.hpp"


namespace SDK::Params
{

// Function LevelSequence.LevelSequence.CopyMetaData
// 0x0010 (0x0010 - 0x0000)
struct LevelSequence_CopyMetaData final
{
public:
	class UObject*                                InMetaData;                                        // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UObject*                                ReturnValue;                                       // 0x0008(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequence.FindOrAddMetaDataByClass
// 0x0010 (0x0010 - 0x0000)
struct LevelSequence_FindOrAddMetaDataByClass final
{
public:
	TSubclassOf<class UObject>                    InClass;                                           // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UObject*                                ReturnValue;                                       // 0x0008(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequence.RemoveMetaDataByClass
// 0x0008 (0x0008 - 0x0000)
struct LevelSequence_RemoveMetaDataByClass final
{
public:
	TSubclassOf<class UObject>                    InClass;                                           // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequence.FindMetaDataByClass
// 0x0010 (0x0010 - 0x0000)
struct LevelSequence_FindMetaDataByClass final
{
public:
	TSubclassOf<class UObject>                    InClass;                                           // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UObject*                                ReturnValue;                                       // 0x0008(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceBurnInOptions.SetBurnIn
// 0x0018 (0x0018 - 0x0000)
struct LevelSequenceBurnInOptions_SetBurnIn final
{
public:
	struct FSoftClassPath                         InBurnInClass;                                     // 0x0000(0x0018)(Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceActor.AddBinding
// 0x0028 (0x0028 - 0x0000)
struct LevelSequenceActor_AddBinding final
{
public:
	struct FMovieSceneObjectBindingID             Binding;                                           // 0x0000(0x0018)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class AActor*                                 Actor;                                             // 0x0018(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bAllowBindingsFromAsset;                           // 0x0020(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_21[0x7];                                       // 0x0021(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function LevelSequence.LevelSequenceActor.AddBindingByTag
// 0x0018 (0x0018 - 0x0000)
struct LevelSequenceActor_AddBindingByTag final
{
public:
	class FName                                   BindingTag;                                        // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class AActor*                                 Actor;                                             // 0x0008(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bAllowBindingsFromAsset;                           // 0x0010(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_11[0x7];                                       // 0x0011(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function LevelSequence.LevelSequenceActor.RemoveBinding
// 0x0020 (0x0020 - 0x0000)
struct LevelSequenceActor_RemoveBinding final
{
public:
	struct FMovieSceneObjectBindingID             Binding;                                           // 0x0000(0x0018)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class AActor*                                 Actor;                                             // 0x0018(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceActor.RemoveBindingByTag
// 0x0010 (0x0010 - 0x0000)
struct LevelSequenceActor_RemoveBindingByTag final
{
public:
	class FName                                   Tag;                                               // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class AActor*                                 Actor;                                             // 0x0008(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceActor.ResetBinding
// 0x0018 (0x0018 - 0x0000)
struct LevelSequenceActor_ResetBinding final
{
public:
	struct FMovieSceneObjectBindingID             Binding;                                           // 0x0000(0x0018)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceActor.SetBinding
// 0x0030 (0x0030 - 0x0000)
struct LevelSequenceActor_SetBinding final
{
public:
	struct FMovieSceneObjectBindingID             Binding;                                           // 0x0000(0x0018)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<class AActor*>                         Actors;                                            // 0x0018(0x0010)(ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, NativeAccessSpecifierPublic)
	bool                                          bAllowBindingsFromAsset;                           // 0x0028(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function LevelSequence.LevelSequenceActor.SetBindingByTag
// 0x0020 (0x0020 - 0x0000)
struct LevelSequenceActor_SetBindingByTag final
{
public:
	class FName                                   BindingTag;                                        // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<class AActor*>                         Actors;                                            // 0x0008(0x0010)(ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, NativeAccessSpecifierPublic)
	bool                                          bAllowBindingsFromAsset;                           // 0x0018(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19[0x7];                                       // 0x0019(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function LevelSequence.LevelSequenceActor.SetReplicatePlayback
// 0x0001 (0x0001 - 0x0000)
struct LevelSequenceActor_SetReplicatePlayback final
{
public:
	bool                                          ReplicatePlayback;                                 // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceActor.SetSequence
// 0x0008 (0x0008 - 0x0000)
struct LevelSequenceActor_SetSequence final
{
public:
	class ULevelSequence*                         InSequence;                                        // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceActor.FindNamedBinding
// 0x0020 (0x0020 - 0x0000)
struct LevelSequenceActor_FindNamedBinding final
{
public:
	class FName                                   Tag;                                               // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FMovieSceneObjectBindingID             ReturnValue;                                       // 0x0008(0x0018)(Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceActor.FindNamedBindings
// 0x0018 (0x0018 - 0x0000)
struct LevelSequenceActor_FindNamedBindings final
{
public:
	class FName                                   Tag;                                               // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<struct FMovieSceneObjectBindingID>     ReturnValue;                                       // 0x0008(0x0010)(ConstParm, Parm, OutParm, ZeroConstructor, ReturnParm, ReferenceParm, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceActor.GetSequence
// 0x0008 (0x0008 - 0x0000)
struct LevelSequenceActor_GetSequence final
{
public:
	class ULevelSequence*                         ReturnValue;                                       // 0x0000(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceActor.GetSequencePlayer
// 0x0008 (0x0008 - 0x0000)
struct LevelSequenceActor_GetSequencePlayer final
{
public:
	class ULevelSequencePlayer*                   ReturnValue;                                       // 0x0000(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceActor.LoadSequence
// 0x0008 (0x0008 - 0x0000)
struct LevelSequenceActor_LoadSequence final
{
public:
	class ULevelSequence*                         ReturnValue;                                       // 0x0000(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceBurnIn.SetSettings
// 0x0008 (0x0008 - 0x0000)
struct LevelSequenceBurnIn_SetSettings final
{
public:
	class UObject*                                InSettings;                                        // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceBurnIn.GetSettingsClass
// 0x0008 (0x0008 - 0x0000)
struct LevelSequenceBurnIn_GetSettingsClass final
{
public:
	TSubclassOf<class ULevelSequenceBurnInInitSettings> ReturnValue;                                       // 0x0000(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceDirector.GetBoundActor
// 0x0020 (0x0020 - 0x0000)
struct LevelSequenceDirector_GetBoundActor final
{
public:
	struct FMovieSceneObjectBindingID             ObjectBinding;                                     // 0x0000(0x0018)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class AActor*                                 ReturnValue;                                       // 0x0018(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceDirector.GetBoundActors
// 0x0028 (0x0028 - 0x0000)
struct LevelSequenceDirector_GetBoundActors final
{
public:
	struct FMovieSceneObjectBindingID             ObjectBinding;                                     // 0x0000(0x0018)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<class AActor*>                         ReturnValue;                                       // 0x0018(0x0010)(Parm, OutParm, ZeroConstructor, ReturnParm, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceDirector.GetBoundObject
// 0x0020 (0x0020 - 0x0000)
struct LevelSequenceDirector_GetBoundObject final
{
public:
	struct FMovieSceneObjectBindingID             ObjectBinding;                                     // 0x0000(0x0018)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UObject*                                ReturnValue;                                       // 0x0018(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceDirector.GetBoundObjects
// 0x0028 (0x0028 - 0x0000)
struct LevelSequenceDirector_GetBoundObjects final
{
public:
	struct FMovieSceneObjectBindingID             ObjectBinding;                                     // 0x0000(0x0018)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<class UObject*>                        ReturnValue;                                       // 0x0018(0x0010)(Parm, OutParm, ZeroConstructor, ReturnParm, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceDirector.GetSequence
// 0x0008 (0x0008 - 0x0000)
struct LevelSequenceDirector_GetSequence final
{
public:
	class UMovieSceneSequence*                    ReturnValue;                                       // 0x0000(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequencePlayer.CreateLevelSequencePlayer
// 0x0038 (0x0038 - 0x0000)
struct LevelSequencePlayer_CreateLevelSequencePlayer final
{
public:
	class UObject*                                WorldContextObject;                                // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class ULevelSequence*                         LevelSequence;                                     // 0x0008(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FMovieSceneSequencePlaybackSettings    Settings;                                          // 0x0010(0x0014)(Parm, NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_24[0x4];                                       // 0x0024(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class ALevelSequenceActor*                    OutActor;                                          // 0x0028(0x0008)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class ULevelSequencePlayer*                   ReturnValue;                                       // 0x0030(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequencePlayer.GetActiveCameraComponent
// 0x0008 (0x0008 - 0x0000)
struct LevelSequencePlayer_GetActiveCameraComponent final
{
public:
	class UCameraComponent*                       ReturnValue;                                       // 0x0000(0x0008)(ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceMediaController.SynchronizeToServer
// 0x0004 (0x0004 - 0x0000)
struct LevelSequenceMediaController_SynchronizeToServer final
{
public:
	float                                         DesyncThresholdSeconds;                            // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceMediaController.GetMediaComponent
// 0x0008 (0x0008 - 0x0000)
struct LevelSequenceMediaController_GetMediaComponent final
{
public:
	class UMediaComponent*                        ReturnValue;                                       // 0x0000(0x0008)(ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function LevelSequence.LevelSequenceMediaController.GetSequence
// 0x0008 (0x0008 - 0x0000)
struct LevelSequenceMediaController_GetSequence final
{
public:
	class ALevelSequenceActor*                    ReturnValue;                                       // 0x0000(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

}


#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: DatasmithContent

#include "Basic.hpp"


namespace SDK::Params
{

// Function DatasmithContent.DatasmithContentBlueprintLibrary.GetDatasmithUserData
// 0x0010 (0x0010 - 0x0000)
struct DatasmithContentBlueprintLibrary_GetDatasmithUserData final
{
public:
	class UObject*                                Object;                                            // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UDatasmithAssetUserData*                ReturnValue;                                       // 0x0008(0x0008)(ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function DatasmithContent.DatasmithContentBlueprintLibrary.GetDatasmithUserDataKeysAndValuesForValue
// 0x0038 (0x0038 - 0x0000)
struct DatasmithContentBlueprintLibrary_GetDatasmithUserDataKeysAndValuesForValue final
{
public:
	class UObject*                                Object;                                            // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 StringToMatch;                                     // 0x0008(0x0010)(Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<class FName>                           OutKeys;                                           // 0x0018(0x0010)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
	TArray<class FString>                         OutValues;                                         // 0x0028(0x0010)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// Function DatasmithContent.DatasmithContentBlueprintLibrary.GetDatasmithUserDataValueForKey
// 0x0020 (0x0020 - 0x0000)
struct DatasmithContentBlueprintLibrary_GetDatasmithUserDataValueForKey final
{
public:
	class UObject*                                Object;                                            // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FName                                   Key;                                               // 0x0008(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 ReturnValue;                                       // 0x0010(0x0010)(Parm, OutParm, ZeroConstructor, ReturnParm, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function DatasmithContent.DatasmithImportedSequencesActor.PlayLevelSequence
// 0x0008 (0x0008 - 0x0000)
struct DatasmithImportedSequencesActor_PlayLevelSequence final
{
public:
	class ULevelSequence*                         SequenceToPlay;                                    // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

}


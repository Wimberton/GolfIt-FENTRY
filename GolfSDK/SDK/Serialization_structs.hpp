#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: Serialization

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"


namespace SDK
{

// ScriptStruct Serialization.StructSerializerNumericTestStruct
// 0x0030 (0x0030 - 0x0000)
struct FStructSerializerNumericTestStruct final
{
public:
	int8                                          Int8;                                              // 0x0000(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1[0x1];                                        // 0x0001(0x0001)(Fixing Size After Last Property [ Dumper-7 ])
	int16                                         Int16;                                             // 0x0002(0x0002)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         Int32;                                             // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int64                                         Int64;                                             // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         UInt8;                                             // 0x0010(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_11[0x1];                                       // 0x0011(0x0001)(Fixing Size After Last Property [ Dumper-7 ])
	uint16                                        UInt16;                                            // 0x0012(0x0002)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint32                                        UInt32;                                            // 0x0014(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint64                                        UInt64;                                            // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         Float;                                             // 0x0020(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_24[0x4];                                       // 0x0024(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	double                                        Double;                                            // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct Serialization.StructSerializerBooleanTestStruct
// 0x0003 (0x0003 - 0x0000)
struct FStructSerializerBooleanTestStruct final
{
public:
	bool                                          BoolFalse;                                         // 0x0000(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          BoolTrue;                                          // 0x0001(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Bitfield0 : 1;                                     // 0x0002(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Bitfield1 : 1;                                     // 0x0002(0x0001)(BitIndex: 0x01, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Bitfield2Set : 1;                                  // 0x0002(0x0001)(BitIndex: 0x02, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Bitfield3 : 1;                                     // 0x0002(0x0001)(BitIndex: 0x03, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Bitfield4Set : 1;                                  // 0x0002(0x0001)(BitIndex: 0x04, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Bitfield5Set : 1;                                  // 0x0002(0x0001)(BitIndex: 0x05, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Bitfield6 : 1;                                     // 0x0002(0x0001)(BitIndex: 0x06, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Bitfield7Set : 1;                                  // 0x0002(0x0001)(BitIndex: 0x07, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
};

// ScriptStruct Serialization.StructSerializerObjectTestStruct
// 0x00A0 (0x00A0 - 0x0000)
struct FStructSerializerObjectTestStruct final
{
public:
	class UClass*                                 Class;                                             // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TSubclassOf<class UMetaData>                  SubClass;                                          // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TSoftClassPtr<class UClass>                   SoftClass;                                         // 0x0010(0x0028)(UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UObject*                                Object;                                            // 0x0038(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TWeakObjectPtr<class UMetaData>               WeakObject;                                        // 0x0040(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TSoftObjectPtr<class UMetaData>               SoftObject;                                        // 0x0048(0x0028)(UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FSoftClassPath                         ClassPath;                                         // 0x0070(0x0018)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FSoftObjectPath                        ObjectPath;                                        // 0x0088(0x0018)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct Serialization.StructSerializerBuiltinTestStruct
// 0x0090 (0x0090 - 0x0000)
struct FStructSerializerBuiltinTestStruct final
{
public:
	struct FGuid                                  Guid;                                              // 0x0000(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FName                                   Name;                                              // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 String;                                            // 0x0018(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FText                                   Text;                                              // 0x0028(0x0018)(NativeAccessSpecifierPublic)
	struct FVector                                Vector;                                            // 0x0040(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_4C[0x4];                                       // 0x004C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector4                               Vector4;                                           // 0x0050(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FRotator                               Rotator;                                           // 0x0060(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_6C[0x4];                                       // 0x006C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FQuat                                  Quat;                                              // 0x0070(0x0010)(IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
	struct FColor                                 Color;                                             // 0x0080(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_84[0xC];                                       // 0x0084(0x000C)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct Serialization.StructSerializerArrayTestStruct
// 0x0060 (0x0060 - 0x0000)
struct FStructSerializerArrayTestStruct final
{
public:
	TArray<int32>                                 Int32Array;                                        // 0x0000(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
	TArray<uint8>                                 ByteArray;                                         // 0x0010(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
	int32                                         StaticSingleElement;                               // 0x0020(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         StaticInt32Array[0x3];                             // 0x0024(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         StaticFloatArray[0x3];                             // 0x0030(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_3C[0x4];                                       // 0x003C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FVector>                        VectorArray;                                       // 0x0040(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
	TArray<struct FStructSerializerBuiltinTestStruct> StructArray;                                       // 0x0050(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
};

// ScriptStruct Serialization.StructSerializerMapTestStruct
// 0x0140 (0x0140 - 0x0000)
struct FStructSerializerMapTestStruct final
{
public:
	TMap<int32, class FString>                    IntToStr;                                          // 0x0000(0x0050)(NativeAccessSpecifierPublic)
	TMap<class FString, class FString>            StrToStr;                                          // 0x0050(0x0050)(NativeAccessSpecifierPublic)
	TMap<class FString, struct FVector>           StrToVec;                                          // 0x00A0(0x0050)(NativeAccessSpecifierPublic)
	TMap<class FString, struct FStructSerializerBuiltinTestStruct> StrToStruct;                                       // 0x00F0(0x0050)(NativeAccessSpecifierPublic)
};

// ScriptStruct Serialization.StructSerializerSetTestStruct
// 0x0140 (0x0140 - 0x0000)
struct FStructSerializerSetTestStruct final
{
public:
	TSet<class FString>                           StrSet;                                            // 0x0000(0x0050)(NativeAccessSpecifierPublic)
	TSet<int32>                                   IntSet;                                            // 0x0050(0x0050)(NativeAccessSpecifierPublic)
	TSet<class FName>                             NameSet;                                           // 0x00A0(0x0050)(NativeAccessSpecifierPublic)
	TSet<struct FStructSerializerBuiltinTestStruct> StructSet;                                         // 0x00F0(0x0050)(NativeAccessSpecifierPublic)
};

// ScriptStruct Serialization.StructSerializerTestStruct
// 0x0450 (0x0450 - 0x0000)
struct FStructSerializerTestStruct final
{
public:
	struct FStructSerializerNumericTestStruct     Numerics;                                          // 0x0000(0x0030)(NoDestructor, NativeAccessSpecifierPublic)
	struct FStructSerializerBooleanTestStruct     Booleans;                                          // 0x0030(0x0003)(NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_33[0x5];                                       // 0x0033(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	struct FStructSerializerObjectTestStruct      Objects;                                           // 0x0038(0x00A0)(NativeAccessSpecifierPublic)
	uint8                                         Pad_D8[0x8];                                       // 0x00D8(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FStructSerializerBuiltinTestStruct     Builtins;                                          // 0x00E0(0x0090)(HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FStructSerializerArrayTestStruct       Arrays;                                            // 0x0170(0x0060)(NativeAccessSpecifierPublic)
	struct FStructSerializerMapTestStruct         Maps;                                              // 0x01D0(0x0140)(NativeAccessSpecifierPublic)
	struct FStructSerializerSetTestStruct         Sets;                                              // 0x0310(0x0140)(NativeAccessSpecifierPublic)
};

// ScriptStruct Serialization.StructSerializerByteArray
// 0x0038 (0x0038 - 0x0000)
struct FStructSerializerByteArray final
{
public:
	int32                                         Dummy1;                                            // 0x0000(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<uint8>                                 ByteArray;                                         // 0x0008(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
	int32                                         Dummy2;                                            // 0x0018(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1C[0x4];                                       // 0x001C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<int8>                                  Int8Array;                                         // 0x0020(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
	int32                                         Dummy3;                                            // 0x0030(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_34[0x4];                                       // 0x0034(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

}


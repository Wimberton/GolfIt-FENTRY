#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: OnlineSubsystem

#include "Basic.hpp"


namespace SDK
{

// Enum OnlineSubsystem.EInAppPurchaseState
// NumValues: 0x0009
enum class EInAppPurchaseState : uint8
{
	Unknown                                  = 0,
	Success                                  = 1,
	Failed                                   = 2,
	Cancelled                                = 3,
	Invalid                                  = 4,
	NotAllowed                               = 5,
	Restored                                 = 6,
	AlreadyOwned                             = 7,
	EInAppPurchaseState_MAX                  = 8,
};

// Enum OnlineSubsystem.EMPMatchOutcome
// NumValues: 0x000B
enum class EMPMatchOutcome : uint8
{
	None                                     = 0,
	Quit                                     = 1,
	Won                                      = 2,
	Lost                                     = 3,
	Tied                                     = 4,
	TimeExpired                              = 5,
	First                                    = 6,
	Second                                   = 7,
	Third                                    = 8,
	Fourth                                   = 9,
	EMPMatchOutcome_MAX                      = 10,
};

// ScriptStruct OnlineSubsystem.InAppPurchaseProductInfo
// 0x00A8 (0x00A8 - 0x0000)
struct FInAppPurchaseProductInfo final
{
public:
	class FString                                 Identifier;                                        // 0x0000(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 TransactionIdentifier;                             // 0x0010(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 DisplayName;                                       // 0x0020(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 DisplayDescription;                                // 0x0030(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 DisplayPrice;                                      // 0x0040(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         RawPrice;                                          // 0x0050(0x0004)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_54[0x4];                                       // 0x0054(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 CurrencyCode;                                      // 0x0058(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 CurrencySymbol;                                    // 0x0068(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 DecimalSeparator;                                  // 0x0078(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 GroupingSeparator;                                 // 0x0088(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 ReceiptData;                                       // 0x0098(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct OnlineSubsystem.NamedInterfaceDef
// 0x0018 (0x0018 - 0x0000)
struct FNamedInterfaceDef final
{
public:
	class FName                                   InterfaceName;                                     // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 InterfaceClassName;                                // 0x0008(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct OnlineSubsystem.InAppPurchaseRestoreInfo
// 0x0030 (0x0030 - 0x0000)
struct FInAppPurchaseRestoreInfo final
{
public:
	class FString                                 Identifier;                                        // 0x0000(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 ReceiptData;                                       // 0x0010(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 TransactionIdentifier;                             // 0x0020(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct OnlineSubsystem.NamedInterface
// 0x0010 (0x0010 - 0x0000)
struct FNamedInterface final
{
public:
	class FName                                   InterfaceName;                                     // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UObject*                                InterfaceObject;                                   // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct OnlineSubsystem.InAppPurchaseProductRequest
// 0x0018 (0x0018 - 0x0000)
struct FInAppPurchaseProductRequest final
{
public:
	class FString                                 ProductIdentifier;                                 // 0x0000(0x0010)(BlueprintVisible, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bIsConsumable;                                     // 0x0010(0x0001)(BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_11[0x7];                                       // 0x0011(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

}


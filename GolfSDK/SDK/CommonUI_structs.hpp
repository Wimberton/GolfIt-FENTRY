#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: CommonUI

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "InputCore_structs.hpp"
#include "SlateCore_structs.hpp"
#include "GameplayTags_structs.hpp"


namespace SDK
{

// Enum CommonUI.ECommonNumericType
// NumValues: 0x0005
enum class ECommonNumericType : uint8
{
	Number                                   = 0,
	Percentage                               = 1,
	Seconds                                  = 2,
	Distance                                 = 3,
	ECommonNumericType_MAX                   = 4,
};

// Enum CommonUI.ECommonInputMode
// NumValues: 0x0004
enum class ECommonInputMode : uint8
{
	Menu                                     = 0,
	Game                                     = 1,
	All                                      = 2,
	MAX                                      = 3,
};

// Enum CommonUI.ERichTextInlineIconDisplayMode
// NumValues: 0x0004
enum class ERichTextInlineIconDisplayMode : uint8
{
	IconOnly                                 = 0,
	TextOnly                                 = 1,
	IconAndText                              = 2,
	MAX                                      = 3,
};

// Enum CommonUI.EInputActionState
// NumValues: 0x0005
enum class EInputActionState : uint8
{
	Enabled                                  = 0,
	Disabled                                 = 1,
	Hidden                                   = 2,
	HiddenAndDisabled                        = 3,
	EInputActionState_MAX                    = 4,
};

// Enum CommonUI.ETransitionCurve
// NumValues: 0x0008
enum class ETransitionCurve : uint8
{
	Linear                                   = 0,
	QuadIn                                   = 1,
	QuadOut                                  = 2,
	QuadInOut                                = 3,
	CubicIn                                  = 4,
	CubicOut                                 = 5,
	CubicInOut                               = 6,
	ETransitionCurve_MAX                     = 7,
};

// Enum CommonUI.ECommonSwitcherTransition
// NumValues: 0x0005
enum class ECommonSwitcherTransition : uint8
{
	FadeOnly                                 = 0,
	Horizontal                               = 1,
	Vertical                                 = 2,
	Zoom                                     = 3,
	ECommonSwitcherTransition_MAX            = 4,
};

// ScriptStruct CommonUI.CommonNumberFormattingOptions
// 0x0014 (0x0014 - 0x0000)
struct FCommonNumberFormattingOptions final
{
public:
	ERoundingMode                                 RoundingMode;                                      // 0x0000(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          UseGrouping;                                       // 0x0001(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_2[0x2];                                        // 0x0002(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         MinimumIntegralDigits;                             // 0x0004(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         MaximumIntegralDigits;                             // 0x0008(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         MinimumFractionalDigits;                           // 0x000C(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         MaximumFractionalDigits;                           // 0x0010(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct CommonUI.CommonRegisteredTabInfo
// 0x0018 (0x0018 - 0x0000)
struct FCommonRegisteredTabInfo final
{
public:
	int32                                         TabIndex;                                          // 0x0000(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UCommonButtonBase*                      TabButton;                                         // 0x0008(0x0008)(ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UWidget*                                ContentInstance;                                   // 0x0010(0x0008)(ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct CommonUI.CommonInputActionHandlerData
// 0x0020 (0x0020 - 0x0000)
struct FCommonInputActionHandlerData final
{
public:
	struct FDataTableRowHandle                    InputActionRow;                                    // 0x0000(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, NoDestructor, NativeAccessSpecifierPublic)
	EInputActionState                             State;                                             // 0x0010(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_11[0xF];                                       // 0x0011(0x000F)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct CommonUI.CommonButtonStyleOptionalSlateSound
// 0x0020 (0x0020 - 0x0000)
struct FCommonButtonStyleOptionalSlateSound final
{
public:
	bool                                          bHasSound;                                         // 0x0000(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1[0x7];                                        // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSlateSound                            Sound;                                             // 0x0008(0x0018)(Edit, BlueprintVisible, NoDestructor, NativeAccessSpecifierPublic)
};

// ScriptStruct CommonUI.CommonAnalogCursorSettings
// 0x0024 (0x0024 - 0x0000)
struct FCommonAnalogCursorSettings final
{
public:
	int32                                         PreprocessorPriority;                              // 0x0000(0x0004)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bEnableCursorAcceleration;                         // 0x0004(0x0001)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_5[0x3];                                        // 0x0005(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CursorAcceleration;                                // 0x0008(0x0004)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         CursorMaxSpeed;                                    // 0x000C(0x0004)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         CursorDeadZone;                                    // 0x0010(0x0004)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         HoverSlowdownFactor;                               // 0x0014(0x0004)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ScrollDeadZone;                                    // 0x0018(0x0004)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ScrollUpdatePeriod;                                // 0x001C(0x0004)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ScrollMultiplier;                                  // 0x0020(0x0004)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct CommonUI.UITag
// 0x0000 (0x0008 - 0x0008)
struct FUITag : public FGameplayTag
{
};

// ScriptStruct CommonUI.UIActionTag
// 0x0000 (0x0008 - 0x0008)
struct FUIActionTag final : public FUITag
{
};

// ScriptStruct CommonUI.UIActionKeyMapping
// 0x0020 (0x0020 - 0x0000)
struct FUIActionKeyMapping final
{
public:
	struct FKey                                   Key;                                               // 0x0000(0x0018)(Edit, Config, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         HoldTime;                                          // 0x0018(0x0004)(Edit, ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1C[0x4];                                       // 0x001C(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct CommonUI.UIInputAction
// 0x0030 (0x0030 - 0x0000)
struct FUIInputAction final
{
public:
	struct FUIActionTag                           ActionTag;                                         // 0x0000(0x0008)(Edit, Config, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FText                                   DefaultDisplayName;                                // 0x0008(0x0018)(Edit, Config, NativeAccessSpecifierPublic)
	TArray<struct FUIActionKeyMapping>            KeyMappings;                                       // 0x0020(0x0010)(Edit, ZeroConstructor, Config, NativeAccessSpecifierPublic)
};

// ScriptStruct CommonUI.RichTextIconData
// 0x0048 (0x0050 - 0x0008)
struct FRichTextIconData final : public FTableRowBase
{
public:
	class FText                                   DisplayName;                                       // 0x0008(0x0018)(Edit, DisableEditOnInstance, NativeAccessSpecifierPublic)
	TSoftObjectPtr<class UObject>                 ResourceObject;                                    // 0x0020(0x0028)(Edit, DisableEditOnInstance, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector2D                              ImageSize;                                         // 0x0048(0x0008)(Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct CommonUI.CommonInputTypeInfo
// 0x00A8 (0x00A8 - 0x0000)
struct FCommonInputTypeInfo final
{
public:
	struct FKey                                   Key;                                               // 0x0000(0x0018)(Edit, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	EInputActionState                             OverrrideState;                                    // 0x0018(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bActionRequiresHold;                               // 0x0019(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1A[0x2];                                       // 0x001A(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         HoldTime;                                          // 0x001C(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FSlateBrush                            OverrideBrush;                                     // 0x0020(0x0088)(Edit, NativeAccessSpecifierPublic)
};

// ScriptStruct CommonUI.CommonInputActionDataBase
// 0x0278 (0x0280 - 0x0008)
struct FCommonInputActionDataBase final : public FTableRowBase
{
public:
	class FText                                   DisplayName;                                       // 0x0008(0x0018)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	class FText                                   HoldDisplayName;                                   // 0x0020(0x0018)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	struct FCommonInputTypeInfo                   KeyboardInputTypeInfo;                             // 0x0038(0x00A8)(Edit, Protected, NativeAccessSpecifierProtected)
	struct FCommonInputTypeInfo                   DefaultGamepadInputTypeInfo;                       // 0x00E0(0x00A8)(Edit, Protected, NativeAccessSpecifierProtected)
	TMap<class FName, struct FCommonInputTypeInfo> GamepadInputOverrides;                             // 0x0188(0x0050)(Edit, Protected, NativeAccessSpecifierProtected)
	struct FCommonInputTypeInfo                   TouchInputTypeInfo;                                // 0x01D8(0x00A8)(Edit, Protected, NativeAccessSpecifierProtected)
};

}


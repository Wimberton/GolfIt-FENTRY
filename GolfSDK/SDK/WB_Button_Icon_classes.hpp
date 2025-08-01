#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: WB_Button_Icon

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "SlateCore_structs.hpp"
#include "GolfIt_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WB_Button_Icon.WB_Button_Icon_C
// 0x0150 (0x0D30 - 0x0BE0)
class UWB_Button_Icon_C final : public UGolfItButtonBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0BE0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       OnHovered;                                         // 0x0BE8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UImage*                                 Icon;                                              // 0x0BF0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Icon_Shadow;                                       // 0x0BF8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       TextBlock;                                         // 0x0C00(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class FText                                   Text;                                              // 0x0C08(0x0018)(Edit, BlueprintVisible)
	struct FSlateBrush                            IconBrush;                                         // 0x0C20(0x0088)(Edit, BlueprintVisible)
	struct FSlateBrush                            ShadowBrush;                                       // 0x0CA8(0x0088)(Edit, BlueprintVisible)

public:
	void PreConstruct(bool IsDesignTime);
	void OnMouseEnter(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);
	void OnMouseLeave(const struct FPointerEvent& MouseEvent);
	void ExecuteUbergraph_WB_Button_Icon(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WB_Button_Icon_C">();
	}
	static class UWB_Button_Icon_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWB_Button_Icon_C>();
	}
};

}


#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: BI_EditorData

#include "Basic.hpp"

#include "CoreUObject_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BI_EditorData.BI_EditorData_C
// 0x0000 (0x0028 - 0x0028)
class IBI_EditorData_C final : public IInterface
{
public:
	void UpdateGameView(bool IsGameView, bool* Completed);
	void GenerateUniqueID(struct FGuid* Guid);
	void GetUniqueID(struct FGuid* Guid);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BI_EditorData_C">();
	}
	static class IBI_EditorData_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<IBI_EditorData_C>();
	}
};

}


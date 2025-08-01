#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: BI_EditorData

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function BI_EditorData.BI_EditorData_C.UpdateGameView
// 0x0002 (0x0002 - 0x0000)
struct BI_EditorData_C_UpdateGameView final
{
public:
	bool                                          IsGameView;                                        // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Completed;                                         // 0x0001(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};

// Function BI_EditorData.BI_EditorData_C.GenerateUniqueID
// 0x0010 (0x0010 - 0x0000)
struct BI_EditorData_C_GenerateUniqueID final
{
public:
	struct FGuid                                  Guid;                                              // 0x0000(0x0010)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// Function BI_EditorData.BI_EditorData_C.GetUniqueID
// 0x0010 (0x0010 - 0x0000)
struct BI_EditorData_C_GetUniqueID final
{
public:
	struct FGuid                                  Guid;                                              // 0x0000(0x0010)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}


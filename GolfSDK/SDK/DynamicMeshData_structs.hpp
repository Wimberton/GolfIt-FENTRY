#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: DynamicMeshData

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "RuntimeMeshComponent_structs.hpp"


namespace SDK
{

// UserDefinedStruct DynamicMeshData.DynamicMeshData
// 0x0050 (0x0050 - 0x0000)
struct FDynamicMeshData final
{
public:
	TArray<struct FVector>                        Verts_6_04FD180646FC89D56F42189584CEA5BD;          // 0x0000(0x0010)(Edit, BlueprintVisible)
	TArray<int32>                                 Triangles_13_00B0FD84490677B15F48D6BF29D99EC1;     // 0x0010(0x0010)(Edit, BlueprintVisible)
	TArray<struct FVector>                        Normals_8_878F499748B2808FB1D4F39F37DC0019;        // 0x0020(0x0010)(Edit, BlueprintVisible)
	TArray<struct FVector2D>                      TextureCords_14_AF570AE84B33D4C8FC269E9D89F45A08;  // 0x0030(0x0010)(Edit, BlueprintVisible)
	TArray<struct FRuntimeMeshTangent>            Tangents_20_C8B19FFE47D383E69DE7E28BA496624D;      // 0x0040(0x0010)(Edit, BlueprintVisible)
};

}


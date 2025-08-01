#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: RuntimeMeshComponent

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"


namespace SDK
{

// Enum RuntimeMeshComponent.ERuntimeMeshCollisionFaceSourceType
// NumValues: 0x0003
enum class ERuntimeMeshCollisionFaceSourceType : uint8
{
	Collision                                = 0,
	Renderable                               = 1,
	ERuntimeMeshCollisionFaceSourceType_MAX  = 2,
};

// Enum RuntimeMeshComponent.ERuntimeMeshThreadingPriority
// NumValues: 0x0008
enum class ERuntimeMeshThreadingPriority : uint8
{
	Normal                                   = 0,
	AboveNormal                              = 1,
	BelowNormal                              = 2,
	Highest                                  = 3,
	Lowest                                   = 4,
	SlightlyBelowNormal                      = 5,
	TimeCritical                             = 6,
	ERuntimeMeshThreadingPriority_MAX        = 7,
};

// Enum RuntimeMeshComponent.ERuntimeMeshCollisionCookingMode
// NumValues: 0x0003
enum class ERuntimeMeshCollisionCookingMode : uint8
{
	CollisionPerformance                     = 0,
	CookingPerformance                       = 1,
	ERuntimeMeshCollisionCookingMode_MAX     = 2,
};

// Enum RuntimeMeshComponent.ERuntimeMeshUpdateFrequency
// NumValues: 0x0004
enum class ERuntimeMeshUpdateFrequency : uint8
{
	Average                                  = 0,
	Frequent                                 = 1,
	Infrequent                               = 2,
	ERuntimeMeshUpdateFrequency_MAX          = 3,
};

// Enum RuntimeMeshComponent.ERuntimeMeshMobility
// NumValues: 0x0004
enum class ERuntimeMeshMobility : uint8
{
	Movable                                  = 0,
	Stationary                               = 1,
	Static                                   = 2,
	ERuntimeMeshMobility_MAX                 = 3,
};

// Enum RuntimeMeshComponent.ERuntimeMeshSliceCapOption
// NumValues: 0x0004
enum class ERuntimeMeshSliceCapOption : uint8
{
	NoCap                                    = 0,
	CreateNewSectionForCap                   = 1,
	UseLastSectionForCap                     = 2,
	ERuntimeMeshSliceCapOption_MAX           = 3,
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshCollisionVertexStream
// 0x0010 (0x0010 - 0x0000)
struct alignas(0x08) FRuntimeMeshCollisionVertexStream final
{
public:
	uint8                                         Pad_0[0x10];                                       // 0x0000(0x0010)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshCollisionTriangleStream
// 0x0010 (0x0010 - 0x0000)
struct alignas(0x08) FRuntimeMeshCollisionTriangleStream final
{
public:
	uint8                                         Pad_0[0x10];                                       // 0x0000(0x0010)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshCollisionTexCoordStream
// 0x0010 (0x0010 - 0x0000)
struct alignas(0x08) FRuntimeMeshCollisionTexCoordStream final
{
public:
	uint8                                         Pad_0[0x10];                                       // 0x0000(0x0010)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshRenderableCollisionData
// 0x0030 (0x0030 - 0x0000)
struct FRuntimeMeshRenderableCollisionData final
{
public:
	struct FRuntimeMeshCollisionVertexStream      Vertices;                                          // 0x0000(0x0010)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
	struct FRuntimeMeshCollisionTriangleStream    Triangles;                                         // 0x0010(0x0010)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
	struct FRuntimeMeshCollisionTexCoordStream    TexCoords;                                         // 0x0020(0x0010)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshCollisionSourceSectionInfo
// 0x0018 (0x0018 - 0x0000)
struct FRuntimeMeshCollisionSourceSectionInfo final
{
public:
	int32                                         StartIndex;                                        // 0x0000(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         EndIndex;                                          // 0x0004(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TWeakObjectPtr<class URuntimeMeshProvider>    SourceProvider;                                    // 0x0008(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         SectionId;                                         // 0x0010(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	ERuntimeMeshCollisionFaceSourceType           SourceType;                                        // 0x0014(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_15[0x3];                                       // 0x0015(0x0003)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshAsyncBodySetupData
// 0x0018 (0x0018 - 0x0000)
struct FRuntimeMeshAsyncBodySetupData final
{
public:
	class UBodySetup*                             BodySetup;                                         // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<struct FRuntimeMeshCollisionSourceSectionInfo> CollisionSources;                                  // 0x0008(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshCollisionMaterialIndexStream
// 0x0010 (0x0010 - 0x0000)
struct alignas(0x08) FRuntimeMeshCollisionMaterialIndexStream final
{
public:
	uint8                                         Pad_0[0x10];                                       // 0x0000(0x0010)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshCollisionData
// 0x0058 (0x0058 - 0x0000)
struct FRuntimeMeshCollisionData final
{
public:
	struct FRuntimeMeshCollisionVertexStream      Vertices;                                          // 0x0000(0x0010)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
	struct FRuntimeMeshCollisionTriangleStream    Triangles;                                         // 0x0010(0x0010)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
	struct FRuntimeMeshCollisionTexCoordStream    TexCoords;                                         // 0x0020(0x0010)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
	struct FRuntimeMeshCollisionMaterialIndexStream MaterialIndices;                                   // 0x0030(0x0010)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
	TArray<struct FRuntimeMeshCollisionSourceSectionInfo> CollisionSources;                                  // 0x0040(0x0010)(Edit, BlueprintVisible, ZeroConstructor, NativeAccessSpecifierPublic)
	bool                                          bFlipNormals;                                      // 0x0050(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bDeformableMesh;                                   // 0x0051(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bFastCook;                                         // 0x0052(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bDisableActiveEdgePrecompute;                      // 0x0053(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_54[0x4];                                       // 0x0054(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshCollisionHitInfo
// 0x0020 (0x0020 - 0x0000)
struct FRuntimeMeshCollisionHitInfo final
{
public:
	TWeakObjectPtr<class URuntimeMeshProvider>    SourceProvider;                                    // 0x0000(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	ERuntimeMeshCollisionFaceSourceType           SourceType;                                        // 0x0008(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_9[0x3];                                        // 0x0009(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         SectionId;                                         // 0x000C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         FaceIndex;                                         // 0x0010(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_14[0x4];                                       // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UMaterialInterface*                     Material;                                          // 0x0018(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshCollisionConvexMesh
// 0x0030 (0x0030 - 0x0000)
struct FRuntimeMeshCollisionConvexMesh final
{
public:
	TArray<struct FVector>                        VertexBuffer;                                      // 0x0000(0x0010)(Edit, BlueprintVisible, ZeroConstructor, NativeAccessSpecifierPublic)
	struct FBox                                   BoundingBox;                                       // 0x0010(0x001C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_2C[0x4];                                       // 0x002C(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshCollisionSphere
// 0x0010 (0x0010 - 0x0000)
struct FRuntimeMeshCollisionSphere final
{
public:
	struct FVector                                Center;                                            // 0x0000(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         Radius;                                            // 0x000C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshCollisionBox
// 0x0024 (0x0024 - 0x0000)
struct FRuntimeMeshCollisionBox final
{
public:
	struct FVector                                Center;                                            // 0x0000(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FRotator                               Rotation;                                          // 0x000C(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
	struct FVector                                Extents;                                           // 0x0018(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshCollisionCapsule
// 0x0020 (0x0020 - 0x0000)
struct FRuntimeMeshCollisionCapsule final
{
public:
	struct FVector                                Center;                                            // 0x0000(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FRotator                               Rotation;                                          // 0x000C(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
	float                                         Radius;                                            // 0x0018(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         Length;                                            // 0x001C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshCollisionSettings
// 0x0048 (0x0048 - 0x0000)
struct FRuntimeMeshCollisionSettings final
{
public:
	bool                                          bUseComplexAsSimple;                               // 0x0000(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bUseAsyncCooking;                                  // 0x0001(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	ERuntimeMeshCollisionCookingMode              CookingMode;                                       // 0x0002(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_3[0x5];                                        // 0x0003(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FRuntimeMeshCollisionConvexMesh> ConvexElements;                                    // 0x0008(0x0010)(Edit, BlueprintVisible, ZeroConstructor, NativeAccessSpecifierPublic)
	TArray<struct FRuntimeMeshCollisionSphere>    Spheres;                                           // 0x0018(0x0010)(Edit, BlueprintVisible, ZeroConstructor, NativeAccessSpecifierPublic)
	TArray<struct FRuntimeMeshCollisionBox>       Boxes;                                             // 0x0028(0x0010)(Edit, BlueprintVisible, ZeroConstructor, NativeAccessSpecifierPublic)
	TArray<struct FRuntimeMeshCollisionCapsule>   Capsules;                                          // 0x0038(0x0010)(Edit, BlueprintVisible, ZeroConstructor, NativeAccessSpecifierPublic)
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshDistanceFieldData
// 0x0048 (0x0048 - 0x0000)
struct alignas(0x08) FRuntimeMeshDistanceFieldData final
{
public:
	uint8                                         Pad_0[0x48];                                       // 0x0000(0x0048)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshTangent
// 0x0010 (0x0010 - 0x0000)
struct FRuntimeMeshTangent final
{
public:
	struct FVector                                TangentX;                                          // 0x0000(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bFlipTangentY;                                     // 0x000C(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_D[0x3];                                        // 0x000D(0x0003)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshSectionData
// 0x0090 (0x0090 - 0x0000)
struct alignas(0x08) FRuntimeMeshSectionData final
{
public:
	uint8                                         Pad_0[0x90];                                       // 0x0000(0x0090)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshVertexPositionStream
// 0x0010 (0x0010 - 0x0000)
struct alignas(0x08) FRuntimeMeshVertexPositionStream final
{
public:
	uint8                                         Pad_0[0x10];                                       // 0x0000(0x0010)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshVertexTangentStream
// 0x0018 (0x0018 - 0x0000)
struct alignas(0x08) FRuntimeMeshVertexTangentStream final
{
public:
	uint8                                         Pad_0[0x18];                                       // 0x0000(0x0018)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshVertexTexCoordStream
// 0x0018 (0x0018 - 0x0000)
struct alignas(0x08) FRuntimeMeshVertexTexCoordStream final
{
public:
	uint8                                         Pad_0[0x18];                                       // 0x0000(0x0018)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshVertexColorStream
// 0x0010 (0x0010 - 0x0000)
struct alignas(0x08) FRuntimeMeshVertexColorStream final
{
public:
	uint8                                         Pad_0[0x10];                                       // 0x0000(0x0010)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshTriangleStream
// 0x0018 (0x0018 - 0x0000)
struct alignas(0x08) FRuntimeMeshTriangleStream final
{
public:
	uint8                                         Pad_0[0x18];                                       // 0x0000(0x0018)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshRenderableMeshData
// 0x0080 (0x0080 - 0x0000)
struct FRuntimeMeshRenderableMeshData final
{
public:
	struct FRuntimeMeshVertexPositionStream       Positions;                                         // 0x0000(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, EditConst, NativeAccessSpecifierPublic)
	struct FRuntimeMeshVertexTangentStream        Tangents;                                          // 0x0010(0x0018)(Edit, BlueprintVisible, BlueprintReadOnly, EditConst, NativeAccessSpecifierPublic)
	struct FRuntimeMeshVertexTexCoordStream       TexCoords;                                         // 0x0028(0x0018)(Edit, BlueprintVisible, BlueprintReadOnly, EditConst, NativeAccessSpecifierPublic)
	struct FRuntimeMeshVertexColorStream          Colors;                                            // 0x0040(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, EditConst, NativeAccessSpecifierPublic)
	struct FRuntimeMeshTriangleStream             Triangles;                                         // 0x0050(0x0018)(Edit, BlueprintVisible, BlueprintReadOnly, EditConst, NativeAccessSpecifierPublic)
	struct FRuntimeMeshTriangleStream             AdjacencyTriangles;                                // 0x0068(0x0018)(Edit, BlueprintVisible, BlueprintReadOnly, EditConst, NativeAccessSpecifierPublic)
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshMaterialSlot
// 0x0010 (0x0010 - 0x0000)
struct FRuntimeMeshMaterialSlot final
{
public:
	class FName                                   SlotName;                                          // 0x0000(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UMaterialInterface*                     Material;                                          // 0x0008(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshLODProperties
// 0x0008 (0x0008 - 0x0000)
struct FRuntimeMeshLODProperties final
{
public:
	float                                         ScreenSize;                                        // 0x0000(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bCanGetSectionsIndependently;                      // 0x0004(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bCanGetAllSectionsAtOnce;                          // 0x0005(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bShouldMergeStaticSectionBuffers;                  // 0x0006(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_7[0x1];                                        // 0x0007(0x0001)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct RuntimeMeshComponent.RuntimeMeshSectionProperties
// 0x0010 (0x0010 - 0x0000)
struct FRuntimeMeshSectionProperties final
{
public:
	ERuntimeMeshUpdateFrequency                   UpdateFrequency;                                   // 0x0000(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1[0x3];                                        // 0x0001(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         MaterialSlot;                                      // 0x0004(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bIsVisible;                                        // 0x0008(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bIsMainPassRenderable;                             // 0x0009(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bCastsShadow;                                      // 0x000A(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bForceOpaque;                                      // 0x000B(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bUseHighPrecisionTangents;                         // 0x000C(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bUseHighPrecisionTexCoords;                        // 0x000D(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         NumTexCoords;                                      // 0x000E(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bWants32BitIndices;                                // 0x000F(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

}


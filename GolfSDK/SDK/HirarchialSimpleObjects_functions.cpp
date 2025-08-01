#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: HirarchialSimpleObjects

#include "Basic.hpp"

#include "HirarchialSimpleObjects_classes.hpp"
#include "HirarchialSimpleObjects_parameters.hpp"


namespace SDK
{

// Function HirarchialSimpleObjects.HirarchialSimpleObjects_C.ChangeMaterialOnInstance
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// E_Editor_Themes                         Theme                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UInstancedStaticMeshComponent*    InstancedMesh                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AHirarchialSimpleObjects_C::ChangeMaterialOnInstance(E_Editor_Themes Theme, class UInstancedStaticMeshComponent* InstancedMesh)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HirarchialSimpleObjects_C", "ChangeMaterialOnInstance");

	Params::HirarchialSimpleObjects_C_ChangeMaterialOnInstance Parms{};

	Parms.Theme = Theme;
	Parms.InstancedMesh = InstancedMesh;

	UObject::ProcessEvent(Func, &Parms);
}


// Function HirarchialSimpleObjects.HirarchialSimpleObjects_C.DefaultInstanceMaterialInstance
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UInstancedStaticMeshComponent*    InstancedMesh                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AHirarchialSimpleObjects_C::DefaultInstanceMaterialInstance(class UInstancedStaticMeshComponent* InstancedMesh)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HirarchialSimpleObjects_C", "DefaultInstanceMaterialInstance");

	Params::HirarchialSimpleObjects_C_DefaultInstanceMaterialInstance Parms{};

	Parms.InstancedMesh = InstancedMesh;

	UObject::ProcessEvent(Func, &Parms);
}


// Function HirarchialSimpleObjects.HirarchialSimpleObjects_C.AddInstancesFromLoad
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FS_EditorInstancedMeshes         InstanceToAdd                                          (BlueprintVisible, BlueprintReadOnly, Parm, ContainsInstancedReference, HasGetValueTypeHash)

void AHirarchialSimpleObjects_C::AddInstancesFromLoad(const struct FS_EditorInstancedMeshes& InstanceToAdd)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HirarchialSimpleObjects_C", "AddInstancesFromLoad");

	Params::HirarchialSimpleObjects_C_AddInstancesFromLoad Parms{};

	Parms.InstanceToAdd = std::move(InstanceToAdd);

	UObject::ProcessEvent(Func, &Parms);
}


// Function HirarchialSimpleObjects.HirarchialSimpleObjects_C.AddInstanceObject
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UStaticMesh*                      Mesh                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    NoCollision                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// struct FTransform                       ObjectsTransform                                       (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// E_Editor_Themes                         Theme                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   Cull                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UInstancedStaticMeshComponent*    InstancedMesh                                          (Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UHierarchicalInstancedStaticMeshComponent*HierarchicalInstancedMesh                              (Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AHirarchialSimpleObjects_C::AddInstanceObject(class UStaticMesh* Mesh, bool NoCollision, const struct FTransform& ObjectsTransform, E_Editor_Themes Theme, int32 Cull, class UInstancedStaticMeshComponent** InstancedMesh, class UHierarchicalInstancedStaticMeshComponent** HierarchicalInstancedMesh)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HirarchialSimpleObjects_C", "AddInstanceObject");

	Params::HirarchialSimpleObjects_C_AddInstanceObject Parms{};

	Parms.Mesh = Mesh;
	Parms.NoCollision = NoCollision;
	Parms.ObjectsTransform = std::move(ObjectsTransform);
	Parms.Theme = Theme;
	Parms.Cull = Cull;

	UObject::ProcessEvent(Func, &Parms);

	if (InstancedMesh != nullptr)
		*InstancedMesh = Parms.InstancedMesh;

	if (HierarchicalInstancedMesh != nullptr)
		*HierarchicalInstancedMesh = Parms.HierarchicalInstancedMesh;
}


// Function HirarchialSimpleObjects.HirarchialSimpleObjects_C.CheckClusterSize
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UInstancedStaticMeshComponent*    InstancedStaticMesh                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class AActor*                           Actor                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool AHirarchialSimpleObjects_C::CheckClusterSize(class UInstancedStaticMeshComponent* InstancedStaticMesh, class AActor* Actor)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HirarchialSimpleObjects_C", "CheckClusterSize");

	Params::HirarchialSimpleObjects_C_CheckClusterSize Parms{};

	Parms.InstancedStaticMesh = InstancedStaticMesh;
	Parms.Actor = Actor;

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function HirarchialSimpleObjects.HirarchialSimpleObjects_C.Check If Mesh In Global Object List
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Exist                                                  (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
// struct FS_InstancedMeshArray            OutputInstances                                        (Parm, OutParm, ContainsInstancedReference, HasGetValueTypeHash)

void AHirarchialSimpleObjects_C::Check_If_Mesh_In_Global_Object_List(bool* Exist, struct FS_InstancedMeshArray* OutputInstances)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HirarchialSimpleObjects_C", "Check If Mesh In Global Object List");

	Params::HirarchialSimpleObjects_C_Check_If_Mesh_In_Global_Object_List Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Exist != nullptr)
		*Exist = Parms.Exist;

	if (OutputInstances != nullptr)
		*OutputInstances = std::move(Parms.OutputInstances);
}


// Function HirarchialSimpleObjects.HirarchialSimpleObjects_C.AllowedMaterials
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// TArray<class UMaterialInterface*>       InstancesToChck                                        (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// bool                                    Continue                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AHirarchialSimpleObjects_C::AllowedMaterials(TArray<class UMaterialInterface*>& InstancesToChck, bool* Continue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HirarchialSimpleObjects_C", "AllowedMaterials");

	Params::HirarchialSimpleObjects_C_AllowedMaterials Parms{};

	Parms.InstancesToChck = std::move(InstancesToChck);

	UObject::ProcessEvent(Func, &Parms);

	InstancesToChck = std::move(Parms.InstancesToChck);

	if (Continue != nullptr)
		*Continue = Parms.Continue;
}


// Function HirarchialSimpleObjects.HirarchialSimpleObjects_C.Add Stuff Function
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UStaticMesh*                      Mesh                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class AActor*                           Actor                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// E_Editor_Themes                         Area                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   CullDistance                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    NoCollision                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// struct FS_FullLaneComposition           LaneComposition                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UInstancedStaticMeshComponent*    InstancedMesh                                          (Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UHierarchicalInstancedStaticMeshComponent*HierarchicalInstancedMesh                              (Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AHirarchialSimpleObjects_C::Add_Stuff_Function(class UStaticMesh* Mesh, class AActor* Actor, E_Editor_Themes Area, int32 CullDistance, bool NoCollision, const struct FS_FullLaneComposition& LaneComposition, class UInstancedStaticMeshComponent** InstancedMesh, class UHierarchicalInstancedStaticMeshComponent** HierarchicalInstancedMesh)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HirarchialSimpleObjects_C", "Add Stuff Function");

	Params::HirarchialSimpleObjects_C_Add_Stuff_Function Parms{};

	Parms.Mesh = Mesh;
	Parms.Actor = Actor;
	Parms.Area = Area;
	Parms.CullDistance = CullDistance;
	Parms.NoCollision = NoCollision;
	Parms.LaneComposition = std::move(LaneComposition);

	UObject::ProcessEvent(Func, &Parms);

	if (InstancedMesh != nullptr)
		*InstancedMesh = Parms.InstancedMesh;

	if (HierarchicalInstancedMesh != nullptr)
		*HierarchicalInstancedMesh = Parms.HierarchicalInstancedMesh;
}


// Function HirarchialSimpleObjects.HirarchialSimpleObjects_C.ClearAll
// (BlueprintCallable, BlueprintEvent)

void AHirarchialSimpleObjects_C::ClearAll()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HirarchialSimpleObjects_C", "ClearAll");

	UObject::ProcessEvent(Func, nullptr);
}


// Function HirarchialSimpleObjects.HirarchialSimpleObjects_C.ChangeCull
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   ViewDistance                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AHirarchialSimpleObjects_C::ChangeCull(int32 ViewDistance)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HirarchialSimpleObjects_C", "ChangeCull");

	Params::HirarchialSimpleObjects_C_ChangeCull Parms{};

	Parms.ViewDistance = ViewDistance;

	UObject::ProcessEvent(Func, &Parms);
}


// Function HirarchialSimpleObjects.HirarchialSimpleObjects_C.SetOriginalViewDistance
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   ViewDistanceSetting                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AHirarchialSimpleObjects_C::SetOriginalViewDistance(int32 ViewDistanceSetting)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HirarchialSimpleObjects_C", "SetOriginalViewDistance");

	Params::HirarchialSimpleObjects_C_SetOriginalViewDistance Parms{};

	Parms.ViewDistanceSetting = ViewDistanceSetting;

	UObject::ProcessEvent(Func, &Parms);
}


// Function HirarchialSimpleObjects.HirarchialSimpleObjects_C.SetAllInstancesToStatic
// (BlueprintCallable, BlueprintEvent)

void AHirarchialSimpleObjects_C::SetAllInstancesToStatic()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HirarchialSimpleObjects_C", "SetAllInstancesToStatic");

	UObject::ProcessEvent(Func, nullptr);
}


// Function HirarchialSimpleObjects.HirarchialSimpleObjects_C.RememberPlaceableObjects
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// TArray<class AActor*>                   PlaceableActors                                        (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// class UInstancedStaticMeshComponent*    InstancedMesh                                          (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UHierarchicalInstancedStaticMeshComponent*HierarchicalInstancedMesh                              (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   InstancedID                                            (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AHirarchialSimpleObjects_C::RememberPlaceableObjects(const TArray<class AActor*>& PlaceableActors, const class UInstancedStaticMeshComponent* InstancedMesh, const class UHierarchicalInstancedStaticMeshComponent* HierarchicalInstancedMesh, const int32 InstancedID)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HirarchialSimpleObjects_C", "RememberPlaceableObjects");

	Params::HirarchialSimpleObjects_C_RememberPlaceableObjects Parms{};

	Parms.PlaceableActors = std::move(PlaceableActors);
	Parms.InstancedMesh = InstancedMesh;
	Parms.HierarchicalInstancedMesh = HierarchicalInstancedMesh;
	Parms.InstancedID = InstancedID;

	UObject::ProcessEvent(Func, &Parms);
}


// Function HirarchialSimpleObjects.HirarchialSimpleObjects_C.RemovePlacableObjects
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class UInstancedStaticMeshComponent*    InstancedMesh                                          (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UHierarchicalInstancedStaticMeshComponent*HierarchicalInstancedMesh                              (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   InstancedID                                            (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AHirarchialSimpleObjects_C::RemovePlacableObjects(const class UInstancedStaticMeshComponent* InstancedMesh, const class UHierarchicalInstancedStaticMeshComponent* HierarchicalInstancedMesh, const int32 InstancedID)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HirarchialSimpleObjects_C", "RemovePlacableObjects");

	Params::HirarchialSimpleObjects_C_RemovePlacableObjects Parms{};

	Parms.InstancedMesh = InstancedMesh;
	Parms.HierarchicalInstancedMesh = HierarchicalInstancedMesh;
	Parms.InstancedID = InstancedID;

	UObject::ProcessEvent(Func, &Parms);
}


// Function HirarchialSimpleObjects.HirarchialSimpleObjects_C.MulticastAddInstance
// (Net, NetReliable, NetMulticast, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UStaticMesh*                      StaticMesh                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    NoCollision                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// struct FTransform                       ObjectTransform                                        (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)

void AHirarchialSimpleObjects_C::MulticastAddInstance(class UStaticMesh* StaticMesh, bool NoCollision, const struct FTransform& ObjectTransform)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HirarchialSimpleObjects_C", "MulticastAddInstance");

	Params::HirarchialSimpleObjects_C_MulticastAddInstance Parms{};

	Parms.StaticMesh = StaticMesh;
	Parms.NoCollision = NoCollision;
	Parms.ObjectTransform = std::move(ObjectTransform);

	UObject::ProcessEvent(Func, &Parms);
}


// Function HirarchialSimpleObjects.HirarchialSimpleObjects_C.ChangeInstancesToMeshes
// (BlueprintCallable, BlueprintEvent)

void AHirarchialSimpleObjects_C::ChangeInstancesToMeshes()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HirarchialSimpleObjects_C", "ChangeInstancesToMeshes");

	UObject::ProcessEvent(Func, nullptr);
}


// Function HirarchialSimpleObjects.HirarchialSimpleObjects_C.ChangeBasicToInstances
// (BlueprintCallable, BlueprintEvent)

void AHirarchialSimpleObjects_C::ChangeBasicToInstances()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HirarchialSimpleObjects_C", "ChangeBasicToInstances");

	UObject::ProcessEvent(Func, nullptr);
}


// Function HirarchialSimpleObjects.HirarchialSimpleObjects_C.ExecuteUbergraph_HirarchialSimpleObjects
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AHirarchialSimpleObjects_C::ExecuteUbergraph_HirarchialSimpleObjects(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HirarchialSimpleObjects_C", "ExecuteUbergraph_HirarchialSimpleObjects");

	Params::HirarchialSimpleObjects_C_ExecuteUbergraph_HirarchialSimpleObjects Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}

}


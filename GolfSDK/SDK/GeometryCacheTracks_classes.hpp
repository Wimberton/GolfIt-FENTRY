#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: GeometryCacheTracks

#include "Basic.hpp"

#include "GeometryCacheTracks_structs.hpp"
#include "MovieScene_classes.hpp"


namespace SDK
{

// Class GeometryCacheTracks.MovieSceneGeometryCacheSection
// 0x0040 (0x0128 - 0x00E8)
class UMovieSceneGeometryCacheSection final : public UMovieSceneSection
{
public:
	struct FMovieSceneGeometryCacheParams         Params;                                            // 0x00E8(0x0040)(Edit, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"MovieSceneGeometryCacheSection">();
	}
	static class UMovieSceneGeometryCacheSection* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMovieSceneGeometryCacheSection>();
	}
};

// Class GeometryCacheTracks.MovieSceneGeometryCacheTrack
// 0x0018 (0x00A8 - 0x0090)
class UMovieSceneGeometryCacheTrack final : public UMovieSceneNameableTrack
{
public:
	uint8                                         Pad_90[0x8];                                       // 0x0090(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class UMovieSceneSection*>             AnimationSections;                                 // 0x0098(0x0010)(ExportObject, ZeroConstructor, ContainsInstancedReference, NativeAccessSpecifierPrivate)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"MovieSceneGeometryCacheTrack">();
	}
	static class UMovieSceneGeometryCacheTrack* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMovieSceneGeometryCacheTrack>();
	}
};

}


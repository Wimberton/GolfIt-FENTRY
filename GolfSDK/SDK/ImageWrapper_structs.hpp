#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: ImageWrapper

#include "Basic.hpp"


namespace SDK
{

// Enum ImageWrapper.EBitmapCSType
// NumValues: 0x0006
enum class EBitmapCSType : uint32
{
	BCST_BLCS_CALIBRATED_RGB                 = 0,
	BCST_LCS_sRGB                            = 1934772034,
	BCST_LCS_WINDOWS_COLOR_SPACE             = 1466527264,
	BCST_PROFILE_LINKED                      = 1279872587,
	BCST_PROFILE_EMBEDDED                    = 1296188740,
	BCST_MAX                                 = 1934772035,
};

// Enum ImageWrapper.EBitmapHeaderVersion
// NumValues: 0x0006
enum class EBitmapHeaderVersion : uint8
{
	BHV_BITMAPINFOHEADER                     = 0,
	BHV_BITMAPV2INFOHEADER                   = 1,
	BHV_BITMAPV3INFOHEADER                   = 2,
	BHV_BITMAPV4HEADER                       = 3,
	BHV_BITMAPV5HEADER                       = 4,
	BHV_MAX                                  = 5,
};

}


#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: Planet_Planet_MaterialStruct

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"


namespace SDK
{

// UserDefinedStruct Planet_Planet_MaterialStruct.Planet_Planet_MaterialStruct
// 0x00D8 (0x00D8 - 0x0000)
struct FPlanet_Planet_MaterialStruct final
{
public:
	float                                         AtmBrightness_71_3A3ECBCB4DB9EA42EA3E2FA3F2A3CD4B; // 0x0000(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         AtmDensity_72_A3D679554B86D12E46E4E1AA9D31A977;    // 0x0004(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         AtmFalloff_73_DA1E1CBA4CABE41B24A21594B3E5DDF8;    // 0x0008(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           AtmosphereColor_10_F30AD4524EDFB294B9A62AA506E7FFE1; // 0x000C(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           CloudsColor_74_A684EB324E1920E8697EE98F3CB7751F;   // 0x001C(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CloudsDensity_75_8F5C0CFD49EBBAF236F1A396EC2DF518; // 0x002C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CloudsFlow_76_6C47690E462D7FC03C16BDAAB7E73F81;    // 0x0030(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CloudsOpacity_77_71DEBBA24460FB3C563D1E925DFCC588; // 0x0034(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CloudsPower_78_07BEC4B247BC5E8A69C277AABDF422F9;   // 0x0038(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CloudsScale_79_877F8BE84FC0AC6ACCE056AAEA38887E;   // 0x003C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CloudsSpeed_80_26A9D2BF4526A5509E1081B7DEAFEB32;   // 0x0040(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           Color1_81_D7F30CD54817179779B317BD9FA03325;        // 0x0044(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           Color2_82_F58C020D49ADEB62B6D0E6AD99CB6E5B;        // 0x0054(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           Color3_83_C3591FE3444E3ADEFA160B90B535B63D;        // 0x0064(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           Color4_84_ACDA1EDC45D11D9E030A16AF84D926C3;        // 0x0074(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         GlobalContrast_38_9B495F074D24C4B5266C36965CCD044E; // 0x0084(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Heightfield_40_3531D8AE421B63B222E92F8F32CB1EC6;   // 0x0088(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SmoothEdges_42_DB65BD7D40621794BEC86C97DBE8E18E;   // 0x008C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         WaterGroundBalance_44_9ECAC32643AD82FD96128BB5A7FB27A0; // 0x0090(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ContinentsScale_90_15D52B384C2F0AD35E2655A17E0DB1D3; // 0x0094(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         VerticalCorrection_92_ED462DC5423178FF8E44199E212546BC; // 0x0098(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Layer1Scale_85_E4977C4F4ADE8D70ADD9769419921082;   // 0x009C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Layer2Scale_86_E13314A74BEB55F0D37843A5A99658A5;   // 0x00A0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Layer3Scale_87_04E193D54C48E568E75D8489E0EE3F56;   // 0x00A4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         PlanetBrightness_52_4C8E4F68478866E76CA0269498EB2FF3; // 0x00A8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Rough_93_022EAC974F51166CC41E578E7419B88B;         // 0x00AC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Specular_56_B08E54AA47CBBE7FAB76A696A781114F;      // 0x00B0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DirtBalance_94_2211AAE546B4110854012F989AE965EE;   // 0x00B4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DirtSmooth_95_773D0DDC43E64A40CFD4F1983635A51F;    // 0x00B8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         PolarPower_62_070ADE9E435F6961C6B0259A7AE82155;    // 0x00BC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SnowBalance_64_69799BB24B8C09D193725E98A5CE6173;   // 0x00C0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SnowOpacity_66_BF8A6F34439D952742AC0B911CB21AFE;   // 0x00C4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SnowPower_69_056967C348E84EB7CA2F47B849C1FE9D;     // 0x00C8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SnowSmooth_70_643868724C4AEF7209ADEDAC971BDB60;    // 0x00CC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UTexture2D*                             FormerMasks_98_905CB5924B9198371077579C3DD5E165;   // 0x00D0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}


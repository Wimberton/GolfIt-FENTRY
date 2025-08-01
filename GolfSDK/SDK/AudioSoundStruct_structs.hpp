#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: AudioSoundStruct

#include "Basic.hpp"


namespace SDK
{

// UserDefinedStruct AudioSoundStruct.AudioSoundStruct
// 0x0040 (0x0040 - 0x0000)
struct FAudioSoundStruct final
{
public:
	float                                         Volume_30_3ECC92664C85A34C4CE6B2A0256D2836;        // 0x0000(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         PitchRandomMin_22_234D8E3248F53CA41CE0D7B6D1CBCEA5; // 0x0004(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         PitchRandomMax_23_D0C190B64BB75DB1BB8589BE23CCACB0; // 0x0008(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Attenuate_9_363EDA32488C9D13B1B0ABA6B3302125;      // 0x000C(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Spatialize_12_5D5BE6A6419517E2351A5FB2AF69810D;    // 0x000D(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_E[0x2];                                        // 0x000E(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         Radius_15_D2D983854325E60FDD83E49A9AE69A29;        // 0x0010(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FalloffDistance_17_B9D88E804B8B84FD228FA1B7A4E74ADC; // 0x0014(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FString                                 DistanceAlgorithm_20_EC0EB40448D4D7047F315FB98F990061; // 0x0018(0x0010)(Edit, BlueprintVisible, ZeroConstructor, HasGetValueTypeHash)
	class FString                                 SoundName_26_D8CC55CA471320E1122069957563A846;     // 0x0028(0x0010)(Edit, BlueprintVisible, ZeroConstructor, HasGetValueTypeHash)
	bool                                          Looping_29_2999508B4EF58292FC34868F5DC9970D;       // 0x0038(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          PlayFromStart_32_BFA34E1B4AE630512A630BAA9C625E0F; // 0x0039(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
};

}


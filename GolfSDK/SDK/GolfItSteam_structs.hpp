#pragma once

/*
* SDK generated by Dumper-7 ~ https://github.com/Encryqed/Dumper-7
*
* [Modified by OriginSoftware] ~ https://github.com/Wimberton/OriginPalia
*/

// Package: GolfItSteam

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"


namespace SDK
{

// Enum GolfItSteam.EUGCItemVisibility
// NumValues: 0x0006
enum class EUGCItemVisibility : uint8
{
	Unknown                                  = 0,
	Public                                   = 1,
	FriendsOnly                              = 2,
	Private                                  = 3,
	Unlisted                                 = 4,
	EUGCItemVisibility_MAX                   = 5,
};

// Enum GolfItSteam.EUGCItemFavoriteState
// NumValues: 0x0004
enum class EUGCItemFavoriteState : uint8
{
	Favorite                                 = 0,
	NotFavorite                              = 1,
	Unknown                                  = 2,
	EUGCItemFavoriteState_MAX                = 3,
};

// Enum GolfItSteam.EUGCItemPlayedState
// NumValues: 0x0004
enum class EUGCItemPlayedState : uint8
{
	Played                                   = 0,
	NotPlayed                                = 1,
	Unknown                                  = 2,
	EUGCItemPlayedState_MAX                  = 3,
};

// Enum GolfItSteam.EUGCUserItemVote
// NumValues: 0x0004
enum class EUGCUserItemVote : uint8
{
	VoteUp                                   = 0,
	VoteDown                                 = 1,
	VoteSkipped                              = 2,
	EUGCUserItemVote_MAX                     = 3,
};

// Enum GolfItSteam.EUGCUserQuerySortMethod
// NumValues: 0x0008
enum class EUGCUserQuerySortMethod : uint8
{
	CreationOrderDesc                        = 0,
	CreationOrderAsc                         = 1,
	TitleAsc                                 = 2,
	LastUpdatedDesc                          = 3,
	SubscriptionDateDesc                     = 4,
	VoteScoreDesc                            = 5,
	ForModeration                            = 6,
	EUGCUserQuerySortMethod_MAX              = 7,
};

// Enum GolfItSteam.EUGCUserQueryList
// NumValues: 0x0009
enum class EUGCUserQueryList : uint8
{
	Published                                = 0,
	VotedOn                                  = 1,
	VotedUp                                  = 2,
	VotedDown                                = 3,
	Favorited                                = 4,
	Subscribed                               = 5,
	UsedOrPlayed                             = 6,
	Followed                                 = 7,
	EUGCUserQueryList_MAX                    = 8,
};

// Enum GolfItSteam.EUGCQueryMatchingType
// NumValues: 0x000F
enum class EUGCQueryMatchingType : uint8
{
	Items                                    = 0,
	Items_Mtx                                = 1,
	Items_ReadyToUse                         = 2,
	Collections                              = 3,
	Artwork                                  = 4,
	Videos                                   = 5,
	Screenshots                              = 6,
	AllGuides                                = 7,
	WebGuides                                = 8,
	IntegratedGuides                         = 9,
	UsableInGame                             = 10,
	ControllerBindings                       = 11,
	GameManagedItems                         = 12,
	All                                      = 13,
	EUGCQueryMatchingType_MAX                = 14,
};

// Enum GolfItSteam.EUGCAllQueryType
// NumValues: 0x0015
enum class EUGCAllQueryType : uint8
{
	RankedByVote                             = 0,
	RankedByPublicationDate                  = 1,
	AcceptedForGameRankedByAcceptanceDate    = 2,
	RankedByTrend                            = 3,
	FavoritedByFriendsRankedByPublicationDate = 4,
	CreatedByFriendsRankedByPublicationDate  = 5,
	RankedByNumTimesReported                 = 6,
	CreatedByFollowedUsersRankedByPublicationDate = 7,
	NotYetRated                              = 8,
	RankedByTotalVotesAsc                    = 9,
	RankedByVotesUp                          = 10,
	RankedByTextSearch                       = 11,
	RankedByTotalUniqueSubscriptions         = 12,
	RankedByPlaytimeTrend                    = 13,
	RankedByTotalPlaytime                    = 14,
	RankedByAveragePlaytimeTrend             = 15,
	RankedByLifetimeAveragePlaytime          = 16,
	RankedByPlaytimeSessionsTrend            = 17,
	RankedByLifetimePlaytimeSessions         = 18,
	RankedByLastUpdatedDate                  = 19,
	EUGCAllQueryType_MAX                     = 20,
};

// Enum GolfItSteam.EUGCItemUpdateStatus
// NumValues: 0x0006
enum class EUGCItemUpdateStatus : uint8
{
	Invalid                                  = 0,
	Preparing                                = 1,
	UploadingContent                         = 2,
	UploadingPreview                         = 3,
	Finishing                                = 4,
	EUGCItemUpdateStatus_MAX                 = 5,
};

// Enum GolfItSteam.ESteamGamepadTextInputMode
// NumValues: 0x0005
enum class ESteamGamepadTextInputMode : uint8
{
	SingleLine                               = 0,
	MultipleLines                            = 1,
	Email                                    = 2,
	Numeric                                  = 3,
	ESteamGamepadTextInputMode_MAX           = 4,
};

// Enum GolfItSteam.ESteamControllerType
// NumValues: 0x0010
enum class ESteamControllerType : uint8
{
	Unknown                                  = 0,
	SteamController                          = 1,
	XBox360Controller                        = 2,
	XBoxOneController                        = 3,
	GenericGamepad                           = 4,
	PS4Controller                            = 5,
	AppleMFiController                       = 6,
	AndroidController                        = 7,
	SwitchJoyConPair                         = 8,
	SwitchJoyConSingle                       = 9,
	SwitchProController                      = 10,
	MobileTouch                              = 11,
	PS3Controller                            = 12,
	PS5Controller                            = 13,
	SteamDeckController                      = 14,
	ESteamControllerType_MAX                 = 15,
};

// Enum GolfItSteam.ESteamInventoryItemRarity
// NumValues: 0x0009
enum class ESteamInventoryItemRarity : uint8
{
	Undefined                                = 0,
	Common                                   = 1,
	Uncommon                                 = 2,
	Rare                                     = 3,
	Ultrarare                                = 4,
	Legendary                                = 5,
	Special                                  = 6,
	Mythical                                 = 7,
	ESteamInventoryItemRarity_MAX            = 8,
};

// Enum GolfItSteam.ESteamInventoryItemType
// NumValues: 0x000A
enum class ESteamInventoryItemType : uint8
{
	Undefined                                = 0,
	Exchangecoin                             = 1,
	Hat                                      = 2,
	Trail                                    = 3,
	Skin                                     = 4,
	Accessories                              = 5,
	GoalEffect                               = 6,
	Putter                                   = 7,
	Generator                                = 8,
	ESteamInventoryItemType_MAX              = 9,
};

// Enum GolfItSteam.EUGCDesiredItemFavoriteState
// NumValues: 0x0003
enum class EUGCDesiredItemFavoriteState : uint8
{
	Favorite                                 = 0,
	NotFavorite                              = 1,
	EUGCDesiredItemFavoriteState_MAX         = 2,
};

// Enum GolfItSteam.EGolfItStatCategory
// NumValues: 0x0006
enum class EGolfItStatCategory : uint8
{
	None                                     = 0,
	General                                  = 1,
	Records                                  = 2,
	Scores                                   = 3,
	Secrets                                  = 4,
	EGolfItStatCategory_MAX                  = 5,
};

// Enum GolfItSteam.EUserStatsUpdateResult
// NumValues: 0x0004
enum class EUserStatsUpdateResult : uint8
{
	Success                                  = 0,
	Pending                                  = 1,
	Failed                                   = 2,
	EUserStatsUpdateResult_MAX               = 3,
};

// Enum GolfItSteam.EStatsUpdateValueCondition
// NumValues: 0x0004
enum class EStatsUpdateValueCondition : uint8
{
	None                                     = 0,
	OnlyIfSmaller                            = 1,
	OnlyIfLarger                             = 2,
	EStatsUpdateValueCondition_MAX           = 3,
};

// Enum GolfItSteam.EStatsUpdateOperation
// NumValues: 0x0004
enum class EStatsUpdateOperation : uint8
{
	Set                                      = 0,
	Add                                      = 1,
	Sub                                      = 2,
	EStatsUpdateOperation_MAX                = 3,
};

// ScriptStruct GolfItSteam.SteamInventoryItemInstanceHandle
// 0x0008 (0x0008 - 0x0000)
struct alignas(0x08) FSteamInventoryItemInstanceHandle final
{
public:
	uint8                                         Pad_0[0x8];                                        // 0x0000(0x0008)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct GolfItSteam.SteamInventoryItemInstance
// 0x0018 (0x0018 - 0x0000)
struct FSteamInventoryItemInstance final
{
public:
	struct FSteamInventoryItemInstanceHandle      MItemInstanceHandle;                               // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         MQuantity;                                         // 0x0008(0x0004)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_C[0x4];                                        // 0x000C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FDateTime                              MAcquiredAt;                                       // 0x0010(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct GolfItSteam.SteamFriend
// 0x0040 (0x0040 - 0x0000)
struct FSteamFriend final
{
public:
	uint8                                         Pad_0[0x10];                                       // 0x0000(0x0010)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 MDisplayName;                                      // 0x0010(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         MIsOnline : 1;                                     // 0x0020(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (BlueprintVisible, BlueprintReadOnly, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         MIsInSession : 1;                                  // 0x0020(0x0001)(BitIndex: 0x01, PropSize: 0x0001 (BlueprintVisible, BlueprintReadOnly, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         MIsPlayingGame : 1;                                // 0x0020(0x0001)(BitIndex: 0x02, PropSize: 0x0001 (BlueprintVisible, BlueprintReadOnly, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         MIsPlayingThisGame : 1;                            // 0x0020(0x0001)(BitIndex: 0x03, PropSize: 0x0001 (BlueprintVisible, BlueprintReadOnly, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Pad_21[0x7];                                       // 0x0021(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 MStatusString;                                     // 0x0028(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FDateTime                              MLastOnline;                                       // 0x0038(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct GolfItSteam.SteamInventoryItem
// 0x0028 (0x0028 - 0x0000)
struct FSteamInventoryItem final
{
public:
	struct FPrimaryAssetId                        MDataAssetID;                                      // 0x0000(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<struct FSteamInventoryItemInstance>    MItemInstances;                                    // 0x0010(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, NativeAccessSpecifierPublic)
	int32                                         MTotalQuantity;                                    // 0x0020(0x0004)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_24[0x4];                                       // 0x0024(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct GolfItSteam.SteamInventoryUpdateChange
// 0x0038 (0x0038 - 0x0000)
struct FSteamInventoryUpdateChange final
{
public:
	struct FSteamInventoryItem                    MItem;                                             // 0x0000(0x0028)(BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	struct FSteamInventoryItemInstanceHandle      MItemInstanceHandle;                               // 0x0028(0x0008)(BlueprintVisible, BlueprintReadOnly, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         MPreviousQuantity;                                 // 0x0030(0x0004)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         MNewQuantity;                                      // 0x0034(0x0004)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct GolfItSteam.SteamInventoryItemDefinitionHandle
// 0x0004 (0x0004 - 0x0000)
struct alignas(0x04) FSteamInventoryItemDefinitionHandle final
{
public:
	uint8                                         Pad_0[0x4];                                        // 0x0000(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct GolfItSteam.LeaderboardRow
// 0x0028 (0x0028 - 0x0000)
struct FLeaderboardRow final
{
public:
	class FString                                 MUserName;                                         // 0x0000(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         MRank;                                             // 0x0010(0x0004)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         MScore;                                            // 0x0014(0x0004)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<int32>                                 MScoreDetails;                                     // 0x0018(0x0010)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, NativeAccessSpecifierPublic)
};

// ScriptStruct GolfItSteam.SteamUGCItemUpdateInfo
// 0x0090 (0x0090 - 0x0000)
struct FSteamUGCItemUpdateInfo final
{
public:
	class FString                                 MTitle;                                            // 0x0000(0x0010)(BlueprintVisible, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FText                                   MDescription;                                      // 0x0010(0x0018)(BlueprintVisible, NativeAccessSpecifierPublic)
	EUGCItemVisibility                            MVisibility;                                       // 0x0028(0x0001)(BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TMap<class FName, class FName>                MTags;                                             // 0x0030(0x0050)(BlueprintVisible, NativeAccessSpecifierPublic)
	class FString                                 MChangeNotes;                                      // 0x0080(0x0010)(BlueprintVisible, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct GolfItSteam.SteamWorkshopItemHandle
// 0x0008 (0x0008 - 0x0000)
struct FSteamWorkshopItemHandle final
{
public:
	uint64                                        MSteamWorkshopItemId;                              // 0x0000(0x0008)(Edit, ZeroConstructor, EditConst, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
};

// ScriptStruct GolfItSteam.SteamUGCQueryResult
// 0x00B8 (0x00B8 - 0x0000)
struct FSteamUGCQueryResult final
{
public:
	struct FSteamWorkshopItemHandle               MItemHandle;                                       // 0x0000(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, EditConst, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FName                                   MTitle;                                            // 0x0008(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 MDescription;                                      // 0x0010(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_20[0x8];                                       // 0x0020(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FDateTime                              MCreatedAt;                                        // 0x0028(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FDateTime                              MUpdatedAt;                                        // 0x0030(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FDateTime                              MTimeAddedToUserList;                              // 0x0038(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EUGCItemVisibility                            MVisibility;                                       // 0x0040(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         MIsBanned : 1;                                     // 0x0041(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (Edit, BlueprintVisible, BlueprintReadOnly, EditConst, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         MIsAcceptedForUse : 1;                             // 0x0041(0x0001)(BitIndex: 0x01, PropSize: 0x0001 (Edit, BlueprintVisible, BlueprintReadOnly, EditConst, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Pad_42[0x6];                                       // 0x0042(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	TSet<class FName>                             MTags;                                             // 0x0048(0x0050)(Edit, BlueprintVisible, BlueprintReadOnly, EditConst, NativeAccessSpecifierPublic)
	class FString                                 MURL;                                              // 0x0098(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         MNumVotesUp;                                       // 0x00A8(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         MNumVotesDown;                                     // 0x00AC(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         MScore;                                            // 0x00B0(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_B4[0x4];                                       // 0x00B4(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct GolfItSteam.GolfItStatDescription
// 0x0020 (0x0020 - 0x0000)
struct FGolfItStatDescription final
{
public:
	class FText                                   MDescription;                                      // 0x0000(0x0018)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	EGolfItStatCategory                           MCategory;                                         // 0x0018(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19[0x3];                                       // 0x0019(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         MValue;                                            // 0x001C(0x0004)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

}


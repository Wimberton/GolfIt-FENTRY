#include "ActorCache.h"
#include "TfdOverlay.h"
#include "SDKExt.h"
#include "Utils.h"
#include <algorithm>
#include <thread>
#include <Fonts.h>

using namespace SDK;

// Singleton instance
ActorCache& ActorCache::GetInstance() {
    static ActorCache instance;
    return instance;
}

ActorCache::ActorCache()
    : LastCachedTime(0.0),
      LastRetryTime(std::chrono::steady_clock::now()) {
}

void ActorCache::Initialize(TfdOverlay* overlay) {
    OverlayInstance = overlay;
    CachedActors.clear();
    BackBufferActors.clear();
    ActorHashes.clear();
    CachedActorSet.clear();
}

void ActorCache::ClearCacheDuringLevelTransition() {
    std::lock_guard<std::mutex> lock(CacheMutex);
    
    // Clear all cached data during level transitions
    CachedActors.clear();
    BackBufferActors.clear();
    ActorHashes.clear();
    CachedActorSet.clear();
    
    // Reset timing
    LastCachedTime = 0.0;
    LastRetryTime = std::chrono::steady_clock::now();
    
    // Stop any ongoing cache updates
    bCacheUpdateInProgress.store(false);
}

void ActorCache::Update() {
    auto* World = GetWorld();
    if (!World) return;

    // Check for level transitions and clear cache if needed
    extern std::atomic<bool> IsLevelTransitioning;
    if (IsLevelTransitioning.load()) {
        ClearCacheDuringLevelTransition();
        return;
    }

    auto* PlayerController = GetAPC();
    if (!PlayerController) return;

    auto* LocalPlayer = PlayerController->K2_GetPawn();
    if (!LocalPlayer || !IsActorValid(LocalPlayer)) return;

    // Check if it's time to update the cache
    double CurrentTime = UGameplayStatics::GetTimeSeconds(World);
    if (fabs(CurrentTime - LastCachedTime) > CacheIntervalSeconds && !bCacheUpdateInProgress.load()) {
        LastCachedTime = CurrentTime;
        
        // Run cache update in background thread
        std::thread([this]() {
            this->CacheActors();
        }).detach();
    }
}

void ActorCache::ForceCacheUpdate() {
    if (!bCacheUpdateInProgress.load()) {
        std::thread([this]() {
            this->CacheActors();
        }).detach();
    }
}

void ActorCache::CacheActors() {
    if (bCacheUpdateInProgress.load())
        return;

    bCacheUpdateInProgress.store(true);

    auto* World = GetWorld();
    if (!World) {
        bCacheUpdateInProgress.store(false);
        return;
    }

    // Check for level transitions and abort caching if needed
    extern std::atomic<bool> IsLevelTransitioning;
    if (IsLevelTransitioning.load()) {
        bCacheUpdateInProgress.store(false);
        return;
    }

    auto* PlayerController = GetAPC();
    if (!PlayerController) {
        bCacheUpdateInProgress.store(false);
        return;
    }

    auto* LocalPlayer = PlayerController->K2_GetPawn();
    if (!LocalPlayer || !IsActorValid(LocalPlayer)) {
        bCacheUpdateInProgress.store(false);
        return;
    }
    
    // Get the local golf ball specifically for comparison
    auto* LocalGolfBall = GetGolfBallC();

    std::vector<CachedActorInfo> newActors;
    newActors.reserve(128); // Reserve space for golf balls

    // Process Golf Balls - iterate through all levels to find AGolfBall_C actors
    if (World->Levels.IsValidIndex(0)) {
        for (int i = 0; i < World->Levels.Num(); i++) {
            if (!World->Levels.IsValidIndex(i))
                continue;
            
            ULevel* Level = World->Levels[i];
            if (!Level)
                continue;
            
            for (int j = 0; j < Level->Actors.Num(); j++) {
                if (!Level->Actors.IsValidIndex(j))
                    continue;
                
                AActor* Actor = Level->Actors[j];
                if (!Actor || !IsActorValid(Actor))
                    continue;
                
                // Check if it's a golf ball
                if (Actor->IsA(AGolfBall_C::StaticClass())) {
                    AGolfBall_C* GolfBall = static_cast<AGolfBall_C*>(Actor);
                    
                    // Skip if it's the local player's golf ball
                    if (GolfBall == LocalGolfBall || GolfBall == LocalPlayer)
                        continue;
                    
                    CachedActorInfo info = ProcessGolfBall(GolfBall, PlayerController, LocalPlayer);
                    if (info.Actor) {
                        newActors.push_back(info);
                    }
                }
                // Check if it's a goal flag
                else if (Actor->IsA(AGoalNumberRotation_C::StaticClass())) {
                    AGoalNumberRotation_C* GoalFlag = static_cast<AGoalNumberRotation_C*>(Actor);
                    
                    CachedActorInfo info = ProcessGoalFlag(GoalFlag, PlayerController, LocalPlayer);
                    if (info.Actor) {
                        newActors.push_back(info);
                    }
                }
            }
        }
    }

    // Swap buffers under lock
    {
        std::lock_guard<std::mutex> lock(CacheMutex);
        BackBufferActors.swap(newActors);
        CachedActors.swap(BackBufferActors);
    }

    bCacheUpdateInProgress.store(false);
}

CachedActorInfo ActorCache::ProcessGolfBall(AGolfBall_C* GolfBall, APlayerController* PlayerController, AActor* LocalPlayer) {
    CachedActorInfo info;
    
    if (!GolfBall || !IsActorValid(GolfBall))
        return info;

    info.Actor = GolfBall;
    info.Category = ActorCategory::GolfBall;
    info.WorldPosition = GolfBall->K2_GetActorLocation();
    
    // Get player name from the golf ball's controller/player state
    std::string playerName = "Golf Ball";
    
    // Try to get the player name from the current controller
    if (GolfBall->MCurrentController && IsActorValid(GolfBall->MCurrentController)) {
        AGolfItBasePlayerController* Controller = GolfBall->MCurrentController;
        if (Controller->PlayerState && IsActorValid(Controller->PlayerState)) {
            APlayerState* PlayerState = Controller->PlayerState;
            if (PlayerState->PlayerNamePrivate.ToString() != "") {
                playerName = PlayerState->PlayerNamePrivate.ToString();
                
                // Add crown icon for host player
                if (GolfBall->MCurrentPlayerState->MIsHost) {
                    playerName = ICON_FA_CROWN " " + playerName;
                }
            }
        }
    }
    
    // Fallback: try to get name from current player state
    if (playerName == "Golf Ball" && GolfBall->MCurrentPlayerState && IsActorValid(GolfBall->MCurrentPlayerState)) {
        APlayerState* PlayerState = static_cast<APlayerState*>(GolfBall->MCurrentPlayerState);
        if (PlayerState->PlayerNamePrivate.ToString() != "") {
            playerName = PlayerState->PlayerNamePrivate.ToString();
            
            // Add crown icon for host player
            if (GolfBall->MCurrentPlayerState->MIsHost) {
                playerName = ICON_FA_CROWN " " + playerName;
            }
        }
    }
    
    // Final fallback: use a generic name with golf ball icon if no player name found
    if (playerName == "Golf Ball") {
        playerName = ICON_FA_GOLF_BALL_TEE " Unknown Player";
    }
    
    info.DisplayName = playerName;

    return info;
}

CachedActorInfo ActorCache::ProcessGoalFlag(AGoalNumberRotation_C* GoalFlag, APlayerController* PlayerController, AActor* LocalPlayer) {
    CachedActorInfo info;
    
    if (!GoalFlag || !IsActorValid(GoalFlag))
        return info;

    info.Actor = GoalFlag;
    info.Category = ActorCategory::GoalFlag;
    info.WorldPosition = GoalFlag->K2_GetActorLocation();
    
    // Set display name for goal flag with flag icon
    std::string flagName = ICON_FA_FLAG_CHECKERED " Golf Goal";
    
    info.DisplayName = flagName;

    return info;
} 
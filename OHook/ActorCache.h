#pragma once

#include <vector>
#include <chrono>
#include <string>
#include <mutex>
#include <atomic>
#include <unordered_map>
#include <unordered_set>
#include <imgui.h>
#include "Utils.h"
#include "Configuration.h"
#include <SDK.hpp>

// Forward declarations
class TfdOverlay;

// Actor categories for Golf It
enum class ActorCategory {
    GolfBall,
    GoalFlag,
    Unknown
};

// Cached actor info structure - simplified for Golf It
struct CachedActorInfo {
    SDK::AActor* Actor = nullptr;
    ActorCategory Category = ActorCategory::Unknown;
    SDK::FVector WorldPosition;
    std::string DisplayName;
};

class ActorCache {
public:
    static ActorCache& GetInstance();

    void Initialize(TfdOverlay* overlay);
    void Update();
    void CacheActors();
    void ForceCacheUpdate();
    void ClearCacheDuringLevelTransition();

    // Access cached actors
    std::vector<CachedActorInfo> GetCachedActors() {
        std::lock_guard<std::mutex> lock(CacheMutex);
        return CachedActors;
    }
    
    std::vector<CachedActorInfo> GetCachedGolfBalls() {
        std::lock_guard<std::mutex> lock(CacheMutex);
        std::vector<CachedActorInfo> result;
        for (const auto& actor : CachedActors) {
            if (actor.Category == ActorCategory::GolfBall) {
                result.push_back(actor);
            }
        }
        return result;
    }
    
    std::vector<CachedActorInfo> GetCachedGoalFlags() {
        std::lock_guard<std::mutex> lock(CacheMutex);
        std::vector<CachedActorInfo> result;
        for (const auto& actor : CachedActors) {
            if (actor.Category == ActorCategory::GoalFlag) {
                result.push_back(actor);
            }
        }
        return result;
    }

private:
    ActorCache();
    ~ActorCache() = default;
    
    // Helper methods - simplified for Golf It
    CachedActorInfo ProcessGolfBall(SDK::AGolfBall_C* GolfBall, SDK::APlayerController* PlayerController, SDK::AActor* LocalPlayer);
    CachedActorInfo ProcessGoalFlag(SDK::AGoalNumberRotation_C* GoalFlag, SDK::APlayerController* PlayerController, SDK::AActor* LocalPlayer);

    // Cache variables
    TfdOverlay* OverlayInstance = nullptr;
    double LastCachedTime = 0.0;
    std::chrono::steady_clock::time_point LastRetryTime;
    std::mutex CacheMutex;
    std::atomic<bool> bCacheUpdateInProgress{false};
    
    // Cached actors
    std::vector<CachedActorInfo> CachedActors;
    std::vector<CachedActorInfo> BackBufferActors;
    
    // Hash maps for detecting changes
    std::unordered_map<const SDK::AActor*, size_t> ActorHashes;
    std::unordered_set<SDK::AActor*> CachedActorSet;
    
    // Cache settings
    const float CacheIntervalSeconds = 0.5f; // Update every half second
}; 
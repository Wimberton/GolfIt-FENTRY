#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <functional>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <Windows.h>
#include <ShlObj.h>
#include <tchar.h>

#include "SDKExt.h"
#include "Configuration.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include "DetourManager.h"
#include "includes.h"
#include "../console/console.hpp"
#include "ActorCache.h"

inline bool MemoryCompare(const BYTE* bData, const BYTE* bSig, const char* szMask)
{
    for (; *szMask; szMask++, bData++, bSig++)
        if (*szMask == 'x' && *bData != *bSig)
            return false;
    return true;
}

inline uintptr_t SearchSignature(int procID, uintptr_t base, uintptr_t size, const char* sig, const char* mask)
{
    BYTE* data = new BYTE[size];
    SIZE_T bytesRead;

    ReadProcessMemory(GetCurrentProcess(), (LPVOID)(base), data, size, &bytesRead);

    for (uintptr_t i = 0; i < size; i++) {
        if (MemoryCompare((const BYTE*)(data + i), (const BYTE*)sig, mask)) {
            delete[] data;
            return i;
        }
    }
    delete[] data;
    return NULL;
}

// Text drawing utility - drawTextOutlined function
inline void drawTextOutlined(ImDrawList* drawList, ImVec2 pos, ImU32 color, const char* text, const ImFont* font) {
    if (!text || !drawList || !font || !*text)
        return;

    // Validate position is on screen
    if (pos.x < -1000 || pos.y < -1000 || pos.x > 10000 || pos.y > 10000)
        return;

    const float fontSize = font->FontSize;
    constexpr ImU32 outlineColor = IM_COL32(0, 0, 0, 170);
    const float outlineThickness = 1.0f;

    // Use only 4 offsets instead of 12
    static const ImVec2 offsets[] = {
        {  0, -1 }, {  1,  0 }, {  0,  1 }, { -1,  0 }
    };

    for (const auto& offset : offsets) {
        drawList->AddText(
            font,
            fontSize,
            ImVec2(pos.x + offset.x * outlineThickness, pos.y + offset.y * outlineThickness),
            outlineColor,
            text
        );
    }

    drawList->AddText(font, fontSize, pos, color, text);
}

// Color handling utilities
namespace ColorUtils {
    // Standard ARGB format (0xAARRGGBB) - this is our "canonical" format
    inline ImU32 ARGBToImU32(uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
        return IM_COL32(r, g, b, a);
    }

    // Convert hex ARGB (0xAARRGGBB) to ImGui's ImU32 format
    inline ImU32 HexARGBToImU32(uint32_t argb) {
        uint8_t a = (argb >> 24) & 0xFF;
        uint8_t r = (argb >> 16) & 0xFF;
        uint8_t g = (argb >> 8) & 0xFF;
        uint8_t b = argb & 0xFF;
        
        // If alpha is 0, set it to 255 (fully opaque) as a fallback
        if (a == 0) a = 255;
        
        return IM_COL32(r, g, b, a);
    }

    // Convert ImGui's ImU32 to float[4] for color editors
    inline void ImU32ToFloat4(ImU32 color, float outColor[4]) {
        outColor[0] = ((color >> IM_COL32_R_SHIFT) & 0xFF) / 255.0f; // Red
        outColor[1] = ((color >> IM_COL32_G_SHIFT) & 0xFF) / 255.0f; // Green
        outColor[2] = ((color >> IM_COL32_B_SHIFT) & 0xFF) / 255.0f; // Blue
        outColor[3] = ((color >> IM_COL32_A_SHIFT) & 0xFF) / 255.0f; // Alpha
    }

    // Convert float[4] back to ImGui's ImU32
    inline ImU32 Float4ToImU32(const float color[4]) {
        return IM_COL32(
            static_cast<int>(color[0] * 255.0f), // Red
            static_cast<int>(color[1] * 255.0f), // Green
            static_cast<int>(color[2] * 255.0f), // Blue
            static_cast<int>(color[3] * 255.0f)  // Alpha
        );
    }

    // Create a color with RGBA components (0-255)
    inline ImU32 RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) {
        return IM_COL32(r, g, b, a);
    }
}

// Legacy function for backward compatibility - redirects to the new system
inline ImU32 IntToImU32(int color) {
    // The color in the config file is stored as a negative integer in ARGB format
    // We need to convert it to ImGui's RGBA format
    uint32_t argb = static_cast<uint32_t>(color);
    
    // Extract components
    uint8_t a = (argb >> 24) & 0xFF;
    uint8_t r = (argb >> 16) & 0xFF;
    uint8_t g = (argb >> 8) & 0xFF;
    uint8_t b = argb & 0xFF;
    
    // If alpha is 0, set it to 255 (fully opaque) as a fallback
    if (a == 0) a = 255;
    
    return IM_COL32(r, g, b, a);
}

// Legacy functions for backward compatibility
inline void ImU32ToFloat4(ImU32 color, float outColor[4]) {
    ColorUtils::ImU32ToFloat4(color, outColor);
}

inline ImU32 Float4ToImU32(const float color[4]) {
    return ColorUtils::Float4ToImU32(color);
}

// Helper to convert FLinearColor to ImU32
inline ImU32 FLinearColorToImU32(const FLinearColor& Color) {
    uint8_t R = static_cast<uint8_t>(Color.R * 255.0f);
    uint8_t G = static_cast<uint8_t>(Color.G * 255.0f);
    uint8_t B = static_cast<uint8_t>(Color.B * 255.0f);
    uint8_t A = static_cast<uint8_t>(Color.A * 255.0f);
    return IM_COL32(R, G, B, A);
}

// Component Validator
inline bool IsComponentValid(const UActorComponent* Component) {
    return Component && Component->IsValidLowLevel() && !Component->IsDefaultObject();
}
// Actor Validator
inline bool IsActorValid(const AActor* Actor) {
    return Actor && Actor->IsValidLowLevel() && IsComponentValid(Actor->RootComponent) && !Actor->IsActorBeingDestroyed() && !Actor->bActorIsBeingDestroyed;
}

//APC
inline APlayerController* CachedAPC = nullptr;
inline AGolfItLobbyPlayerController* CachedGolfItLobbyPC = nullptr;
inline AGolfItDefaultGamePlayerController* CachedGolfItGamePC = nullptr;
inline AGolfItGolfBallPawn* CachedGolfBall = nullptr;
inline AGolfBall_C* CachedGolfBallC = nullptr;
inline AGolfItLobbyPlayerState* CachedGolfItPS = nullptr;
inline UCheatManager* CachedCheatManager = nullptr;

// Level transition detection and cleanup
inline std::string CurrentLevelName = "";
inline std::atomic<bool> IsLevelTransitioning{false};
inline std::mutex LevelTransitionMutex;

inline void CheckForLevelTransition() {
    const UWorld* World = GetWorld();
    if (!World) return;
    
    std::string levelName = World->Name.ToString();
    
    // Thread-safe level transition detection
    std::lock_guard<std::mutex> lock(LevelTransitionMutex);
    
    if (levelName != CurrentLevelName) {
        // Level transition detected
        IsLevelTransitioning.store(true);
        
        // Clear all cached actors during level transition
        CachedAPC = nullptr;
        CachedGolfItLobbyPC = nullptr;
        CachedGolfItGamePC = nullptr;
        CachedGolfBall = nullptr;
        CachedGolfBallC = nullptr;
        CachedGolfItPS = nullptr;
        
        // Clear ActorCache as well - will be handled by ActorCache::Update() when it detects level transition
        
        LOG_DEBUG("Level transition detected: %s -> %s", CurrentLevelName.c_str(), levelName.c_str());
        CurrentLevelName = levelName;
        
        // Reset transition flag after a brief delay with proper synchronization
        std::thread([](std::atomic<bool>* flag) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            flag->store(false);
        }, &IsLevelTransitioning).detach();
    }
}

inline APlayerController* GetAPC() {
    // Check for level transitions first
    CheckForLevelTransition();
    
    // Skip during level transitions to prevent crashes
    if (IsLevelTransitioning.load()) {
        return nullptr;
    }
    
    // Cached Validation
    if (IsActorValid(CachedAPC)) {
        return CachedAPC;
    }

    // Reset Value
    CachedAPC = nullptr;

    const UWorld* World = GetWorld();
    if (!World) return nullptr;
    if (World->Name.ToString() == "Lobby_P" || World->Name.ToString() == "Level_Transition") return nullptr;

    UGameInstance* GameInstance = World->OwningGameInstance;
    if (!GameInstance || !GameInstance->LocalPlayers || GameInstance->LocalPlayers.Num() <= 0) return nullptr;

    const ULocalPlayer* LocalPlayer = GameInstance->LocalPlayers[0];
    if (!LocalPlayer || !LocalPlayer->PlayerController || !LocalPlayer->PlayerController->IsA(APlayerController::StaticClass())) return nullptr;

    auto APC = static_cast<APlayerController*>(LocalPlayer->PlayerController);
    return IsActorValid(APC) ? CachedAPC = APC : nullptr;
}

// GolfItLobbyPC
inline AGolfItLobbyPlayerController* GetGolfItLobbyPC() {
    // Skip during level transitions to prevent crashes
    if (IsLevelTransitioning.load()) {
        return nullptr;
    }
    
    // Cached Validation
    if (IsActorValid(CachedGolfItLobbyPC)) {
        return CachedGolfItLobbyPC;
    }

    // Reset Value
    CachedGolfItLobbyPC = nullptr;

    const UWorld* World = GetWorld();
    if (!World) return nullptr;
    if (World->Name.ToString() == "Lobby_P" || World->Name.ToString() == "Level_Transition") return nullptr;

    UGameInstance* GameInstance = World->OwningGameInstance;
    if (!GameInstance || !GameInstance->LocalPlayers || GameInstance->LocalPlayers.Num() <= 0) return nullptr;

    const ULocalPlayer* LocalPlayer = GameInstance->LocalPlayers[0];
    if (!LocalPlayer || !LocalPlayer->PlayerController || !LocalPlayer->PlayerController->IsA(AGolfItLobbyPlayerController::StaticClass())) return nullptr;

    auto GolfItLobbyPC = static_cast<AGolfItLobbyPlayerController*>(LocalPlayer->PlayerController);
    return IsActorValid(GolfItLobbyPC) ? CachedGolfItLobbyPC = GolfItLobbyPC : nullptr;
}

// GolfItGamePC
inline AGolfItDefaultGamePlayerController* GetGolfItGamePC() {
    // Skip during level transitions to prevent crashes
    if (IsLevelTransitioning.load()) {
        return nullptr;
    }
    
    // Cached Validation
    if (IsActorValid(CachedGolfItGamePC)) {
        return CachedGolfItGamePC;
    }

    // Reset Value
    CachedGolfItGamePC = nullptr;

    AGolfItLobbyPlayerController* LocalPC = GetGolfItLobbyPC();
    if (!IsActorValid(LocalPC)) return nullptr;

    // Try to cast to AGolfItDefaultGamePlayerController
    if (!LocalPC->IsA(AGolfItDefaultGamePlayerController::StaticClass())) return nullptr;
    
    auto GamePlayerController = static_cast<AGolfItDefaultGamePlayerController*>(LocalPC);
    return IsActorValid(GamePlayerController) ? CachedGolfItGamePC = GamePlayerController : nullptr;
}

// GolfBall
inline AGolfItGolfBallPawn* GetGolfBall() {
    // Skip during level transitions to prevent crashes
    if (IsLevelTransitioning.load()) {
        return nullptr;
    }
    
    // Cached Validation
    if(IsActorValid(CachedGolfBall)) {
        return CachedGolfBall;
    }

    CachedGolfBall = nullptr;

    AGolfItLobbyPlayerController* LocalPC = GetGolfItLobbyPC();
    if(!IsActorValid(LocalPC)) return nullptr;

    // In GolfIt, the pawn is the golf ball
    if (!LocalPC->K2_GetPawn() || !LocalPC->K2_GetPawn()->IsA(AGolfItGolfBallPawn::StaticClass())) return nullptr;
    
    auto GolfBall = static_cast<AGolfItGolfBallPawn*>(LocalPC->K2_GetPawn());
    return IsActorValid(GolfBall) ? CachedGolfBall = GolfBall : nullptr;
}

// GolfBallC (Blueprint Implementation)
inline AGolfBall_C* GetGolfBallC() {
    // Skip during level transitions to prevent crashes
    if (IsLevelTransitioning.load()) {
        return nullptr;
    }
    
    // Cached Validation
    if(IsActorValid(CachedGolfBallC)) {
        return CachedGolfBallC;
    }

    CachedGolfBallC = nullptr;

    AGolfItLobbyPlayerController* LocalPC = GetGolfItLobbyPC();
    if(!IsActorValid(LocalPC)) return nullptr;

    // The actual golf ball implementation is AGolfBall_C
    if (!LocalPC->K2_GetPawn() || !LocalPC->K2_GetPawn()->IsA(AGolfBall_C::StaticClass())) return nullptr;
    
    auto GolfBallC = static_cast<AGolfBall_C*>(LocalPC->K2_GetPawn());
    return IsActorValid(GolfBallC) ? CachedGolfBallC = GolfBallC : nullptr;
}

// GolfItPS
inline AGolfItLobbyPlayerState* GetGolfItPS() {
    // Skip during level transitions to prevent crashes
    if (IsLevelTransitioning.load()) {
        return nullptr;
    }
    
    // Cached Validation
    if (IsActorValid(CachedGolfItPS)) {
        return CachedGolfItPS;
    }

    CachedGolfItPS = nullptr;

    AGolfItLobbyPlayerController* LocalPC = GetGolfItLobbyPC();
    if (!IsActorValid(LocalPC)) return nullptr;

    if (!LocalPC->PlayerState || !LocalPC->PlayerState->IsA(AGolfItLobbyPlayerState::StaticClass())) return nullptr;

    auto GolfItPS = static_cast<AGolfItLobbyPlayerState*>(LocalPC->PlayerState);
    return IsActorValid(GolfItPS) ? CachedGolfItPS = GolfItPS : nullptr;
}

// CheatManager
inline UCheatManager* GetCheatManager() {
    // Validate cached CheatManager
    if (CachedCheatManager && CachedCheatManager->IsValidLowLevel()) {
        return CachedCheatManager;
    }

    CachedCheatManager = nullptr;

    // Get player controller
    APlayerController* PlayerController = GetAPC();
    if (!PlayerController || !IsActorValid(PlayerController)) {
        return nullptr;
    }

    // Check if CheatManager exists
    if (!PlayerController->CheatManager || !PlayerController->CheatManager->IsValidLowLevel()) {
        return nullptr;
    }

    CachedCheatManager = PlayerController->CheatManager;
    return CachedCheatManager;
}

// DRAWING UTILS
inline void Box3D(APlayerController* PlayerController, FVector Origin, FVector Extents, ImU32 Col, ImDrawList* DrawList, float Thickness) {
    std::vector<FVector> Points(8); // 3D corner points
    std::vector<ImVec2> ScreenPoints(8); // Screen-projected corner points

    // Calculate the 8 corners of the 3D box
    Points[0] = Origin - Extents; // Bottom-back-left
    Points[1] = Origin + FVector(Extents.X, -Extents.Y, -Extents.Z); // Bottom-back-right
    Points[2] = Origin + FVector(Extents.X, Extents.Y, -Extents.Z); // Bottom-front-right
    Points[3] = Origin + FVector(-Extents.X, Extents.Y, -Extents.Z); // Bottom-front-left
    Points[4] = Points[0] + FVector(0, 0, 2 * Extents.Z); // Top-back-left
    Points[5] = Points[1] + FVector(0, 0, 2 * Extents.Z); // Top-back-right
    Points[6] = Points[2] + FVector(0, 0, 2 * Extents.Z); // Top-front-right
    Points[7] = Points[3] + FVector(0, 0, 2 * Extents.Z); // Top-front-left

    // Project the 3D points onto the screen
    bool AllProjected = true;
    for (int i = 0; i < 8; ++i) {
        FVector2D ScreenPosition;
        if (PlayerController->ProjectWorldLocationToScreen(Points[i], &ScreenPosition, true)) {
            ScreenPoints[i] = ImVec2(ScreenPosition.X, ScreenPosition.Y);
        }
        else {
            AllProjected = false;
            break;
        }
    }

    if (!AllProjected) return; // Only draw if all points are successfully projected

    // Draw the edges of the box
    for (int i = 0; i < 4; ++i) {
        // Draw bottom edges
        DrawList->AddLine(ScreenPoints[i], ScreenPoints[(i + 1) % 4], Col, Thickness);

        // Draw top edges
        DrawList->AddLine(ScreenPoints[i + 4], ScreenPoints[((i + 1) % 4) + 4], Col, Thickness);

        // Draw vertical edges
        DrawList->AddLine(ScreenPoints[i], ScreenPoints[i + 4], Col, Thickness);
    }
}
inline void CorneredBox(ImVec2 TopLeft, ImVec2 BottomRight, ImU32 Col, ImDrawList* DrawList, float Thickness, float CornerLength) {
    // Top-left corner
    DrawList->AddLine(TopLeft, ImVec2(TopLeft.x + CornerLength, TopLeft.y), Col, Thickness); // Horizontal
    DrawList->AddLine(TopLeft, ImVec2(TopLeft.x, TopLeft.y + CornerLength), Col, Thickness); // Vertical

    // Top-right corner
    DrawList->AddLine(ImVec2(BottomRight.x, TopLeft.y), ImVec2(BottomRight.x - CornerLength, TopLeft.y), Col, Thickness); // Horizontal
    DrawList->AddLine(ImVec2(BottomRight.x, TopLeft.y), ImVec2(BottomRight.x, TopLeft.y + CornerLength), Col, Thickness); // Vertical

    // Bottom-left corner
    DrawList->AddLine(ImVec2(TopLeft.x, BottomRight.y), ImVec2(TopLeft.x + CornerLength, BottomRight.y), Col, Thickness); // Horizontal
    DrawList->AddLine(ImVec2(TopLeft.x, BottomRight.y), ImVec2(TopLeft.x, BottomRight.y - CornerLength), Col, Thickness); // Vertical

    // Bottom-right corner
    DrawList->AddLine(BottomRight, ImVec2(BottomRight.x - CornerLength, BottomRight.y), Col, Thickness); // Horizontal
    DrawList->AddLine(BottomRight, ImVec2(BottomRight.x, BottomRight.y - CornerLength), Col, Thickness); // Vertical
}
inline void FlatBox(ImVec2 TopLeft, ImVec2 BottomRight, ImU32 Col, ImDrawList* DrawList, float Thickness) {
    DrawList->AddRect(TopLeft, BottomRight, Col, 0.0f /*No Rounding*/, 0 /*Flags*/, Thickness);
}

// AimRotation Calc
inline FRotator CalculateAimRotation(const FVector& TargetLocation, const FVector& CurrentLocation) {
    FVector Direction = (TargetLocation - CurrentLocation).GetNormalized();

    FRotator AimRotation;
    AimRotation.Pitch = std::atan2(Direction.Z, std::sqrt(Direction.X * Direction.X + Direction.Y * Direction.Y)) * (180.0f / M_PI); // Convert rad to degrees
    AimRotation.Yaw = std::atan2(Direction.Y, Direction.X) * (180.0f / M_PI); // Convert rad to degrees
    AimRotation.Roll = 0; // Usually zero for aim

    return AimRotation;
}
// Aim 2D Distance Calc
inline float GetDistance2D(const FVector2D& A, const FVector2D& B) {
    return std::sqrt((A.X - B.X) * (A.X - B.X) + (A.Y - B.Y) * (A.Y - B.Y));
}
// Aim 3D Distance Calc
inline float GetDistance3D(const FVector& A, const FVector& B) {
    return std::sqrt(
        (A.X - B.X) * (A.X - B.X) +
        (A.Y - B.Y) * (A.Y - B.Y) +
        (A.Z - B.Z) * (A.Z - B.Z)
    );
}

inline bool WorldToScreen(const SDK::FVector& worldLoc, SDK::FVector2D* screenPos)
{
    bool isOnScreen = SDK::UGameplayStatics::ProjectWorldToScreen(GetAPC(), worldLoc, screenPos, true);
    return isOnScreen;
}

#define IsKeyHeld(key) (GetAsyncKeyState(key) & 0x8000)
#define StrPrinter ::_StrPrinter()

class _StrPrinter : public std::string {
public:
    _StrPrinter() = default;

    template <typename T>
    _StrPrinter& operator<<(T&& data) {
        _stream << std::forward<T>(data);
        this->std::string::operator=(_stream.str());
        return *this;
    }

    std::string operator<<(std::ostream& (*f)(std::ostream&)) const { return static_cast<std::string>(*this); }

private:
    std::stringstream _stream;
};

#define WStrPrinter ::_WStrPrinter()

class _WStrPrinter : public std::wstring {
public:
    _WStrPrinter() = default;

    template <typename T>
    _WStrPrinter& operator<<(T&& data) {
        _stream << std::forward<T>(data);
        this->std::wstring::operator=(_stream.str());
        return *this;
    }

    std::wstring operator<<(std::ostream& (*f)(std::ostream&)) const { return static_cast<std::wstring>(*this); }

private:
    std::wstringstream _stream;
};

struct vec3 {
    float x, y, z;

    explicit vec3(const float x = 0.0f, const float y = 0.0f, const float z = 0.0f) : x(x), y(y), z(z) {}

    FVector ToFVector() const { return FVector(x, y, z); }

    // Vector addition
    vec3 operator+(const vec3& other) const { return vec3(x + other.x, y + other.y, z + other.z); }

    // Vector subtraction
    vec3 operator-(const vec3& other) const { return vec3(x - other.x, y - other.y, z - other.z); }

    // Scalar multiplication
    vec3 operator*(const float scalar) const { return vec3(x * scalar, y * scalar, z * scalar); }

    // Dot product
    float Dot(const vec3& other) const { return x * other.x + y * other.y + z * other.z; }

    // Cross product
    vec3 Cross(const vec3& other) const {
        return vec3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    // Size of the vector
    float Size() const { return std::sqrt(x * x + y * y + z * z); }

    // Distance between two vectors
    float Distance(const vec3& other) const { return (*this - other).Size(); }

    // Convert to string (for debugging)
    std::string ToString() const {
        std::stringstream ss;
        ss << "vec3(" << x << ", " << y << ", " << z << ")";
        return ss.str();
    }
};

inline FString CharToWide(const char* NarrowString) {
    wchar_t WideString[1024];
    MultiByteToWideChar(CP_ACP, 0, NarrowString, -1, WideString, 1024);
    return FString(WideString);
}

template <typename SearchType>
SearchType GetFlagSingle(std::string Text, std::map<SearchType, std::vector<std::string>>& map) {
    SearchType T = static_cast<SearchType>(0);
    for (auto& Entry : map) {
        bool bFound = false;

        for (auto& Str : Entry.second) {
            if (Text.find(Str) != std::string::npos) {
                T = Entry.first;
                bFound = true;
                break;
            }
        }

        if (bFound)
            break;
    }
    return T;
}

template <typename SearchType>
SearchType GetFlagSingleEnd(std::string Text, std::map<SearchType, std::vector<std::string>>& map) {
    SearchType T = static_cast<SearchType>(0);
    for (auto& Entry : map) {
        bool bFound = false;

        for (auto& Str : Entry.second) {
            if (Text.ends_with(Str)) {
                T = Entry.first;
                bFound = true;
                break;
            }
        }

        if (bFound)
            break;
    }
    return T;
}

template <typename SearchType>
SearchType GetFlagMulti(std::string Text, std::map<SearchType, std::vector<std::string>>& map) {
    SearchType T = static_cast<SearchType>(0);
    for (auto& Entry : map) {
        for (auto& Str : Entry.second) { if (Text.find(Str) != std::string::npos) { T |= Entry.first; } }
    }
    return T;
}

template <size_t size_x>
bool AnyTrue(bool(&arr)[size_x]) {
    for (int x = 0; x < size_x; x++) {
        if (arr[x])
            return true;
    }
    return false;
}

template <size_t size_x, size_t size_y>
bool AnyTrue2D(bool(&arr)[size_x][size_y]) {
    for (int x = 0; x < size_x; x++) {
        for (int y = 0; y < size_y; y++) {
            if (arr[x][y])
                return true;
        }
    }
    return false;
}

template <size_t size_x, size_t size_y, size_t size_z>
bool AnyTrue3D(bool(&arr)[size_x][size_y][size_z]) {
    for (int x = 0; x < size_x; x++) {
        for (int y = 0; y < size_y; y++) {
            for (int z = 0; z < size_z; z++) {
                if (arr[x][y][z])
                    return true;
            }
        }
    }
    return false;
}

inline bool IsGameWindowActive() {
    const HWND foregroundWindow = GetForegroundWindow();
    TCHAR windowClassName[256];
    GetClassName(foregroundWindow, windowClassName, sizeof(windowClassName) / sizeof(TCHAR));
    return _tcscmp(windowClassName, TEXT("UnrealWindow")) == 0;
}

union FunctionPointerUnion {
    const void* ProcessEventPointer;
    void (*ProcessEventFunction)(const UObject*, UFunction*, void*);
};

#define STATIC_CLASS(CName, SearchContainer)                          \
{                                                                     \
    static class UClass* Clss = nullptr;                              \
    if (!Clss || !Clss->IsValidLowLevel() || Clss->IsDefaultObject()) \
        Clss = UObject::FindClassFast(CName);                         \
    SearchContainer.push_back(Clss);                                  \
}

inline bool IsKeyUp(const int key) {
    static bool wasKeyDown = false;
    bool isKeyDown = GetAsyncKeyState(key) & 0x8000;

    if (wasKeyDown && !isKeyDown) {
        // Key was released
        wasKeyDown = false; // Update the state
        return true;
    }

    // Update the state for the next call
    wasKeyDown = isKeyDown;
    return false;
}

// Vector math utilities
namespace VectorMath {

    static FVector GetVectorRight(const FRotator& Rotation) {
        const float YawRadians = Rotation.Yaw * M_PI / 180.0f;

        const float CY = std::cos(YawRadians - M_PI / 2); // Subtract 90 degrees to get the right vector
        const float SY = std::sin(YawRadians - M_PI / 2);

        return FVector(CY, SY, 0.0f); // Right vector is on the horizontal plane, so Z component is 0
    }
}

namespace CustomMath {

    constexpr float PI = 3.14159265358979323846f;

    template <typename T>
    inline T Clamp(const T& value, const T& min, const T& max) {
        return value < min ? min : (value > max ? max : value);
    }

    template <typename T>
    inline T Abs(const T& value) { return value < 0 ? -value : value; }

    inline float DegreesToRadians(float degrees) { return degrees * (PI / 180.0f); }

    // Custom square root function
    inline float Sqrt(float value) { return std::sqrt(value); }

    // Custom square function
    template <typename T>
    inline T Square(const T& value) { return value * value; }

    // Custom arccosine function
    inline float Acos(float value) { return std::acos(Clamp(value, -1.0f, 1.0f)); }

    inline float DistanceBetweenPoints(const FVector2D& Point1, const FVector2D& Point2) {
        return sqrt(pow(Point2.X - Point1.X, 2) + pow(Point2.Y - Point1.Y, 2));
    }
    
    // Vector distance calculation for 3D vectors
    inline float VectorDistance(const FVector& Vec1, const FVector& Vec2) {
        return std::sqrt(Square(Vec2.X - Vec1.X) + Square(Vec2.Y - Vec1.Y) + Square(Vec2.Z - Vec1.Z));
    }

    // Custom radians to degrees function
    inline float RadiansToDegrees(float radians) { return radians * (180.0f / PI); }

    inline double Fmod(double Value, double Mod) { return std::fmod(Value, Mod); }

    inline FRotator RInterpTo(const FRotator& Current, const FRotator& Target, double DeltaTime, float InterpSpeed) {
        // If no interpolation speed, just return the target
        if (InterpSpeed <= 0.0f) { return Target; }

        // Calculate the difference in each component
        double DeltaPitch = Target.Pitch - Current.Pitch;
        double DeltaYaw = Target.Yaw - Current.Yaw;
        double DeltaRoll = Target.Roll - Current.Roll;

        // Wrap angles to ensure shortest path is taken
        DeltaPitch = Fmod(DeltaPitch + 180.0, 360.0) - 180.0;
        DeltaYaw = Fmod(DeltaYaw + 180.0, 360.0) - 180.0;
        DeltaRoll = Fmod(DeltaRoll + 180.0, 360.0) - 180.0;

        // Calculate the step for each component based on the interpolation speed and delta time
        double PitchStep = DeltaPitch * Clamp(InterpSpeed * DeltaTime, 0.0, 1.0);
        double YawStep = DeltaYaw * Clamp(InterpSpeed * DeltaTime, 0.0, 1.0);
        double RollStep = DeltaRoll * Clamp(InterpSpeed * DeltaTime, 0.0, 1.0);

        // Generate the new interpolated rotation
        FRotator InterpolatedRotation;
        InterpolatedRotation.Pitch = Current.Pitch + PitchStep;
        InterpolatedRotation.Yaw = Current.Yaw + YawStep;
        InterpolatedRotation.Roll = Current.Roll + RollStep;

        return InterpolatedRotation;
    }

    inline ImVec2 addImVec2(ImVec2 a, ImVec2 b) {
        return { a.x + b.x, a.y + b.y };
    }
}
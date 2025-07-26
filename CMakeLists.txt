
cmake_minimum_required(VERSION 3.6)
project(OHook CXX)
enable_language(C)

set(CMAKE_CXX_STANDARD 23)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/MP /MD)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

# Detours
file(GLOB DETOURS_SOURCES detours/*.cpp)
file(GLOB DETOURS_HEADERS detours/*.h)
add_library(detours STATIC ${DETOURS_SOURCES} ${DETOURS_HEADERS})
target_include_directories(detours PUBLIC detours)

# ImGUI
file(GLOB IMGUI_SOURCES ImGui/*.cpp ImGui/impls/*.cpp)
file(GLOB IMGUI_HEADERS ImGui/*.h ImGui/impls/*.h)
if(WIN32)
    file(GLOB IMGUI_PLATFORM_SOURCES ImGui/impls/windows/*.cpp)
    file(GLOB IMGUI_PLATFORM_HEADERS ImGui/impls/windows/*.h)
elseif(UNIX AND NOT APPLE)
    file(GLOB IMGUI_PLATFORM_SOURCES ImGui/impls/linux/*.cpp)
    file(GLOB IMGUI_PLATFORM_HEADERS ImGui/impls/linux/*.h)
endif()
list(APPEND IMGUI_SOURCES ${IMGUI_PLATFORM_SOURCES})
list(APPEND IMGUI_HEADERS ${IMGUI_PLATFORM_HEADERS})

add_library(imgui STATIC ${IMGUI_SOURCES} ${IMGUI_HEADERS})
target_include_directories(imgui PUBLIC ImGui glew/include)
target_compile_definitions(imgui PRIVATE IMGUI_DEFINE_MATH_OPERATORS $<$<BOOL:${WIN32}>:GLEW_STATIC>)

# RendererHook
file(GLOB_RECURSE RENDERERHOOK_SOURCES RendererHook/*.cpp)
file(GLOB_RECURSE RENDERERHOOK_HEADERS RendererHook/*.h)
add_library(RendererHook STATIC ${RENDERERHOOK_SOURCES} ${RENDERERHOOK_HEADERS})
target_include_directories(RendererHook PUBLIC RendererHook glew/include)
target_compile_definitions(RendererHook PRIVATE $<$<BOOL:${WIN32}>:GLEW_STATIC>)
target_link_libraries(RendererHook PUBLIC detours imgui)

# GolfSDK
file(GLOB_RECURSE GOLFSDK_SOURCES GolfSDK/*.cpp)
file(GLOB_RECURSE GOLFSDK_HEADERS GolfSDK/*.hpp)
add_library(GolfSDK STATIC ${GOLFSDK_SOURCES} ${GOLFSDK_HEADERS})
target_include_directories(GolfSDK PUBLIC GolfSDK)
target_precompile_headers(GolfSDK PRIVATE GolfSDK/SDK.hpp)

# ZeroGUI
file(GLOB_RECURSE ZEROGUI_HEADERS zerogui/*.h)
add_library(zerogui INTERFACE)
target_include_directories(zerogui INTERFACE zerogui)

# OHook DLL
if(EXISTS "${CMAKE_BINARY_DIR}/OHook.pdb")
   file(REMOVE ${CMAKE_BINARY_DIR}/OHook.pdb)
endif()
file(GLOB_RECURSE OHook_SOURCES OHook/*.cpp)
file(GLOB_RECURSE OHook_HEADERS OHook/*.h)
file(GLOB_RECURSE OHook_SOURCES OHook/*.cpp console/*.cpp)
file(GLOB_RECURSE OHook_HEADERS OHook/*.h console/*.hpp)
file(GLOB GLEW_SOURCES glew/src/glew.c)
set_source_files_properties(${GLEW_SOURCES} PROPERTIES LANGUAGE C)
add_library(OHook SHARED ${OHook_SOURCES} ${OHook_HEADERS} ${GLEW_SOURCES})
target_compile_definitions(OHook PRIVATE $<$<BOOL:${WIN32}>:GLEW_STATIC>)
target_link_libraries(OHook PRIVATE RendererHook GolfSDK $<$<BOOL:${WIN32}>:ws2_32> $<$<BOOL:${WIN32}>:iphlpapi> $<$<BOOL:${WIN32}>:psapi> $<$<BOOL:${WIN32}>:opengl32.lib> $<$<BOOL:${WIN32}>:Winmm.lib>)
#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "../GolfSDK/SDK.hpp"
#include <map>
#include <TlHelp32.h>
#include <bitset>

/*
*  Hooks
*/
static __int64 (*M1org)(void* ViewportClient, void* DebugCanvas) = NULL;

/*
*  Signatures
*/
struct sigmod {
	uintptr_t dwBase, dwSize;
};
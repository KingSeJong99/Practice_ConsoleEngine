#pragma once

// #define ENGINE_BUILD_DLL 1

#define DLLEXPORT   __declspec(dllexport)
#define DLLIMPORT   __declspec(dllimport)

// ENGINE_BUILD_DLL이 선언되어 있는지에 따라 분기
#if ENGINE_BUILD_DLL
#define MINT_API DLLEXPORT
#else
#define MINT_API DLLIMPORT
#endif
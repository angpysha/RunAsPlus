#pragma once
#if defined(_MSC_VER) || defined(_WIN32) || defined(_WIN64)
#define msgbx(x) MessageBoxA(NULL,x,x,0)
#define msgbxw(x) MessageBoxW(NULL,x,x,0)
#ifdef DLL_EXPORT
#define NATIVEFUNC __declspec(dllexport)
#else
#define NATIVEFUNC __declspec(dllimport)
#endif
#ifdef __cplusplus
#define externC extern "C"
#define Cdecl __cdecl
#else
#define externC
#define Cdecl
#endif
#define HIDDEN
#elif defined(__GNUC__) || defined(__linux__)
#define msgbx(x)
#define NATIVEFUNC __attribute__((visibility("default")))
#define HIDDEN __attribute__((visibility("hidden")))
#ifdef __cplusplus
#define externC extern "C"
#define Cdecl
#else
#define externC
#define Cdecl
#endif
#endif

#define GenerationEx(x) /*x*/
#define returnData(x) /*x---xxx*/

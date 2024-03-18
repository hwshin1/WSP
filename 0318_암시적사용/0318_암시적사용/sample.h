//sample.h
#pragma once
#include <Windows.h>

#ifdef DLL_SOURCE
	#define DLLFUN __declspec(dllexport)
#else
	#define DLLFUN __declspec(dllimport)
#endif

EXTERN_C DLLFUN void Add(int a, int b);
EXTERN_C DLLFUN void Sub(int a, int b);
EXTERN_C DLLFUN int GetResult1();
EXTERN_C DLLFUN void GetResult(int *result);
void foo(int flag);								//DLL 내부에서만 사용하겠다.

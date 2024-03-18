//sample.cpp
#define DLL_SOURCE										//실행파일에서 헤더 위에 디파인을 해주면 export로 바뀜

#include "sample.h"

static int g_result;

void Add(int a, int b)
{
	g_result = a + b;
	foo(1);
}

void Sub(int a, int b)
{
	g_result = a - b;
	foo(2);
}

int GetResult1()
{
	return g_result;
}

void GetResult2(int* result)
{
	*result = g_result;
}

void foo(int flag)
{
	if (flag == 1)
		MessageBox(0, TEXT("Add"), TEXT("알림"), MB_OK);
	else if (flag == 2)
		MessageBox(0, TEXT("Sub"), TEXT("알림"), MB_OK);
}
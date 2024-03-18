//암시적사용.cpp
//.h, .lib, .dll 필요(소스파일과 동일한 dir에 복사)
#include <Windows.h>
#include <stdio.h>
#include "sample.h"						//dll.h (선언부가져옴)
#pragma comment(lib, "0318_DLL.lib")	//lib (export된 정보 획득)

int main()
{
	Add(10, 20);
	printf("%d\n", GetResult1());

	Sub(10, 20);
	int result;

	GetResult(&result);
	printf("%d\n", result);

	return 0;
}


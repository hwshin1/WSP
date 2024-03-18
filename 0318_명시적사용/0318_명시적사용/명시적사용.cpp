//명시적사용.cpp
//.dll만 소스파일과 동일한 위치의 폴더에 복사
#include <stdio.h>
#include <Windows.h>

//함수포인터 타입 정의 ---------------
typedef void (*Func_Cal)(int, int);		//Add, Sub
typedef int (*Func_Get)();				//Result1
typedef void (*Func_Get1)(int*);		//Result2
//------------------------------------

int main()
{
	//장점 : 필요할 떄 메모리에 올려서 사용하고 내린다.
	HMODULE hDll = LoadLibrary(TEXT("0318_DLL.dll"));
	if (hDll == 0)
	{
		printf("dll 로딩 오류\n");
		return 0;
	}

	//h 파일이 없기 때문에 직접 함수의 주소를 획득해야 함
	Func_Cal Add = (Func_Cal)GetProcAddress(hDll, "Add");
	Func_Cal Sub = (Func_Cal)GetProcAddress(hDll, "Sub");
	Func_Get GetResult1 = (Func_Get)GetProcAddress(hDll, "GetResult1");
	Func_Get1 GetResult2 = (Func_Get1)GetProcAddress(hDll, "GetResult2");

	if (Add == 0 || Sub == 0 || GetResult1 == 0 || GetResult2 == 0)
	{
		printf("해당 함수를 찾을수 없습니다.\n");
		return 0;
	}

	//사용
	Add(10, 20);
	printf("%d\n", GetResult1());

	FreeLibrary(hDll);
	return 0;
}
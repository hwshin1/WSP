//��������.cpp
//.dll�� �ҽ����ϰ� ������ ��ġ�� ������ ����
#include <stdio.h>
#include <Windows.h>

//�Լ������� Ÿ�� ���� ---------------
typedef void (*Func_Cal)(int, int);		//Add, Sub
typedef int (*Func_Get)();				//Result1
typedef void (*Func_Get1)(int*);		//Result2
//------------------------------------

int main()
{
	//���� : �ʿ��� �� �޸𸮿� �÷��� ����ϰ� ������.
	HMODULE hDll = LoadLibrary(TEXT("0318_DLL.dll"));
	if (hDll == 0)
	{
		printf("dll �ε� ����\n");
		return 0;
	}

	//h ������ ���� ������ ���� �Լ��� �ּҸ� ȹ���ؾ� ��
	Func_Cal Add = (Func_Cal)GetProcAddress(hDll, "Add");
	Func_Cal Sub = (Func_Cal)GetProcAddress(hDll, "Sub");
	Func_Get GetResult1 = (Func_Get)GetProcAddress(hDll, "GetResult1");
	Func_Get1 GetResult2 = (Func_Get1)GetProcAddress(hDll, "GetResult2");

	if (Add == 0 || Sub == 0 || GetResult1 == 0 || GetResult2 == 0)
	{
		printf("�ش� �Լ��� ã���� �����ϴ�.\n");
		return 0;
	}

	//���
	Add(10, 20);
	printf("%d\n", GetResult1());

	FreeLibrary(hDll);
	return 0;
}
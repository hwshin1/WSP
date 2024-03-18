//MMF.cpp
#include <Windows.h>
#include <tchar.h>
#include <stdio.h>

int main()
{
	//1. 颇老 积己
	HANDLE hFile = CreateFile(TEXT("a.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
		0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

	//2. MMF按眉 积己
	HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READWRITE, 0, 100, TEXT("map"));

	//3. 林家客 颇老 楷搬
	TCHAR* p = (TCHAR*)MapViewOfFile(hMap, FILE_MAP_WRITE, 0, 0, 0);
	if (p == NULL)
		printf("error\n");
	else
	{
		printf("甘俏等 林家 : %p\n", p);
		_tcscpy_s(p, 6, TEXT("Hello"));
		p[20] = 'A';
	}

	UnmapViewOfFile(p);
	CloseHandle(hMap);
	CloseHandle(hFile);
	return 0;
}
//�Ͻ������.cpp
//.h, .lib, .dll �ʿ�(�ҽ����ϰ� ������ dir�� ����)
#include <Windows.h>
#include <stdio.h>
#include "sample.h"						//dll.h (����ΰ�����)
#pragma comment(lib, "0318_DLL.lib")	//lib (export�� ���� ȹ��)

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


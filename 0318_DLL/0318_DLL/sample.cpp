//sample.cpp
#define DLL_SOURCE										//�������Ͽ��� ��� ���� �������� ���ָ� export�� �ٲ�

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
		MessageBox(0, TEXT("Add"), TEXT("�˸�"), MB_OK);
	else if (flag == 2)
		MessageBox(0, TEXT("Sub"), TEXT("�˸�"), MB_OK);
}
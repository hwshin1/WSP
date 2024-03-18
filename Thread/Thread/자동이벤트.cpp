//자동 이벤트.cpp
#include <iostream>
#include <Windows.h>
using namespace std;

HANDLE hEvent1, hEvent2;
BOOL bContinue = TRUE;
int g_x, sum;

DWORD WINAPI ServerThread(LPVOID p)
{
	while (bContinue)
	{
		WaitForSingleObject(hEvent1, INFINITE);
		sum = 0;
		for (int i = 0; i < g_x; i++)
		{
			sum += i;
		}
		SetEvent(hEvent2);
	}
	cout << "Server종료" << endl;
	return 0;
}

void main()
{
	hEvent1 = CreateEvent(0, 0, 0, TEXT("e1"));
	hEvent2 = CreateEvent(0, 0, 0, TEXT("e2"));
	HANDLE hThread = CreateThread(NULL, NULL, ServerThread, 0, 0, 0);
	while (1)
	{
		cin >> g_x;
		if (g_x == -1)
			break;
		SetEvent(hEvent1);
		WaitForSingleObject(hEvent2, INFINITE);
		cout << "결과 : " << sum << endl;
	}
	bContinue = FALSE;
	SetEvent(hEvent1);

	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);
}
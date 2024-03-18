//MMF���ź�.cpp
#pragma comment (linker, "/subsystem:windows")

#include <Windows.h>
#include <tchar.h>

//����
typedef struct tagLINE
{
	POINTS ptFrom;	//����
	POINTS ptTo;	//��
}LINE;

//Ư���� �Լ�
DWORD WINAPI foo(void* p)
{
	HWND hwnd = (HWND)p;

	//�˸���ü OPEN
	HANDLE hEvent = OpenEvent(EVENT_ALL_ACCESS, 0, TEXT("signal"));

	//1. MMF��ü OPEN
	HANDLE hMap = OpenFileMapping(FILE_MAP_ALL_ACCESS, 0, TEXT("map"));
	if (hMap == 0)
	{
		MessageBox(0, TEXT("���� ���α׷��� ���� ����"), TEXT("�˸�"), MB_OK);
		return 0;
	}

	//2. �ּҿ� ���� ����
	LINE* pLine = (LINE*)MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
	if (pLine == NULL)
	{
		MessageBox(0, TEXT("error"), TEXT("�˸�"), MB_OK);
	}

	while (true)
	{
		WaitForSingleObject(hEvent, INFINITE);
		HDC hdc = GetDC(hwnd);

		MoveToEx(hdc, pLine->ptFrom.x, pLine->ptFrom.y, 0);
		LineTo(hdc, pLine->ptTo.x, pLine->ptTo.y);

		ReleaseDC(hwnd, hdc);
	}

	UnmapViewOfFile(pLine);
	CloseHandle(hMap);
	CloseHandle(hEvent);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:
	{
		//foo(hwnd);
		HANDLE hThread = CreateThread(0, 0, foo, (void*)hwnd, 0, 0);
		CloseHandle(hThread);

		return 0;
	}
	case WM_CREATE:
	{
		return 0;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}


int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd)
{
	WNDCLASS wc;
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = TEXT("First");
	wc.lpszMenuName = 0;
	wc.style = 0;

	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(0, TEXT("First"), TEXT("Hello"), WS_OVERLAPPEDWINDOW,
		0, 0, 500, 500, 0, 0, hInst, 0);

	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}
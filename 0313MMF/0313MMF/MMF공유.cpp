//MMF공유.cpp
#pragma comment (linker, "/subsystem:windows")

#include <Windows.h>
#include <tchar.h>

//공유
typedef struct tagLINE
{
	POINTS ptFrom;	//시작
	POINTS ptTo;	//끝
}LINE;


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//그릴때 사용
	static POINTS ptFrom;
	//MMF(WM_CREATE : 생성 / WM_DESTROY:소멸)
	static HANDLE hMap;
	static LINE* p;
	//알림(WM_CREATE: 생성 / WM_DESTROY:소멸)
	static HANDLE hEvent;

	switch (msg)
	{
	case WM_LBUTTONDOWN:
	{
		ptFrom = MAKEPOINTS(lParam);
		return 0;
	}
	case WM_MOUSEMOVE:
	{
		if (wParam & MK_LBUTTON)
		{
			POINTS pt = MAKEPOINTS(lParam);

			HDC hdc = GetDC(hwnd);
			MoveToEx(hdc, ptFrom.x, ptFrom.y, 0);
			LineTo(hdc, pt.x, pt.y);

			//---------------- MMF 사용 ------------------------------
			//파일에 좌표 저장
			p->ptFrom = ptFrom;
			p->ptTo = pt;
			//상대방에게 알림.
			SetEvent(hEvent);	//*********************
			//--------------------------------------------------------
			ptFrom = pt;

			ReleaseDC(hwnd, hdc);
		}
		return 0;
	}
	case WM_CREATE:
	{
		//알림객체 생성
		hEvent = CreateEvent(0, TRUE, 0, TEXT("signal"));

		//1. MMF객체 생성
		hMap = CreateFileMapping((HANDLE)-1, 0, PAGE_READWRITE, 0, sizeof(LINE), TEXT("map"));

		//2. 주소와 파일 연결
		p = (LINE*)MapViewOfFile(hMap, FILE_MAP_WRITE, 0, 0, 0);
		if (p == NULL)
			MessageBox(0, TEXT("error"), TEXT("알림"), MB_OK);
		return 0;
	}
	case WM_DESTROY:
	{
		CloseHandle(hEvent);
		UnmapViewOfFile(p);
		CloseHandle(hMap);
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
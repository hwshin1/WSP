//handler.cpp
#include "std.h"

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	con_Init(hwnd);
	return 0;
}

LRESULT OnDestroy(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
	return 0;
}

LRESULT OnPaint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	con_PrintGameView(hwnd, hdc);

	EndPaint(hwnd, &ps);
	return 0;
}

LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case ID_GAME_NEW:
		con_Game_New(hwnd);
	case ID_GAME_HINT:
		return 0;
	case ID_GAME_EXIT:
		SendMessage(hwnd, WM_CLOSE, 0, 0);
	}
	return 0;
}

LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	POINTS pt = MAKEPOINTS(lParam);
	con_Click(hwnd, pt);
	return 0;
}
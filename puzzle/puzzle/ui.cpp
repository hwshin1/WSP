//ui.cpp
#include "std.h"

SIZE g_szFull; //윈도우(이미지 크기)

void ui_SetWindowRect(HWND hwnd, int w, int h)
{
	g_szFull.cx = w;
	g_szFull.cy = h;

	RECT r = { 0, 0, g_szFull.cx + OX * 2, g_szFull.cy + OY * 2 };
	AdjustWindowRect(&r, GetWindowLong(hwnd, GWL_STYLE), TRUE);

	//모니터 정중앙에 출력
	int width = r.right - r.left;
	int height = r.bottom - r.top;
	int x = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
	int y = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
	MoveWindow(hwnd, x, y, width, height, TRUE);
}

SIZE ui_GetszFull()
{
	return g_szFull;
}

extern SIZE g_szBlock; // 테스트 나중에 삭제
void ui_PrintGameView(HWND hwnd, HDC hdc, HBITMAP bmp, int(*g_image)[5])
{
	Rectangle(hdc, OX - 5, OY - 5, OX + g_szFull.cx + 5, OY + g_szFull.cy + 5);
	SetViewportOrgEx(hdc, OX, OY, 0);
	HDC dcMem = CreateCompatibleDC(hdc);
	HBITMAP old = (HBITMAP)SelectObject(dcMem, bmp);

	for (int y = 0; y < COUNT; y++)
	{
		for (int x = 0; x < COUNT; x++)
		{
			if (g_image[y][x] == EMPTY) // EMPTY
			{
				PatBlt(hdc, x * g_szBlock.cx, y * g_szBlock.cy, g_szBlock.cx, g_szBlock.cy, WHITENESS);
			}
			else
			{
				POINTS pt = { g_image[y][x] % COUNT, g_image[y][x] / COUNT };
				BitBlt(hdc, x * g_szBlock.cx, y * g_szBlock.cy, g_szBlock.cx, g_szBlock.cy,
					dcMem, pt.x * g_szBlock.cx, pt.y * g_szBlock.cy, SRCCOPY);
			}
		}
	}

	SelectObject(dcMem, old);
	DeleteDC(dcMem);
}
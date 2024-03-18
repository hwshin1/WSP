//game.cpp
#include "std.h"

HBITMAP g_hBitmap;
BOOL g_bRunning;
SIZE g_szBlock;
int	g_image[COUNT][COUNT]; //이미지 위치 저장

SIZE game_GetszBlock()
{
	return g_szBlock;
}

BITMAP game_LoadImage(HWND hwnd, const TCHAR* path)
{
	//비트맵 로드
	HINSTANCE hInstace = GetModuleHandle(0);
	g_hBitmap = (HBITMAP)LoadImage(0, path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	BITMAP bm;
	GetObject(g_hBitmap, sizeof(bm), &bm);

	return bm;
}

void game_SetBlockSize(HWND hwnd, SIZE size)
{
	g_szBlock.cx = size.cx / COUNT;
	g_szBlock.cy = size.cy / COUNT;
}

void game_State(BOOL b)
{
	g_bRunning = b;
}

BOOL game_GetState()
{
	return g_bRunning;
}

void game_ImageNumber_Init(HWND hwnd)
{
	int k = 0;
	for (int y = 0; y < COUNT; y++)
		for (int x = 0; x < COUNT; x++)
			g_image[y][x] = k++;
}

HBITMAP game_GetBitMap()
{
	return g_hBitmap;
}

int* game_GetImage()
{
	return (int*) g_image;
}

void game_Swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

BOOL game_MoveBlock(HWND hwnd, int x, int y)
{
	// Rectangle Current Block
	RECT r = { x * g_szBlock.cx,y * g_szBlock.cy,(x + 1) * g_szBlock.cx, (y + 1) * g_szBlock.cy };
	if (y > 0 && g_image[y - 1][x] == EMPTY)
	{
		game_Swap(&g_image[y][x], &g_image[y - 1][x]);
		r.top -= g_szBlock.cy;
	}
	else if (y < COUNT - 1 && g_image[y + 1][x] == EMPTY)
	{
		game_Swap(&g_image[y][x], &g_image[y + 1][x]);
		r.bottom += g_szBlock.cy;
	}
	else if (x > 0 && g_image[y][x - 1] == EMPTY)
	{
		game_Swap(&g_image[y][x], &g_image[y][x - 1]);
		r.left -= g_szBlock.cx;
	}
	else if (x < COUNT - 1 && g_image[y][x + 1] == EMPTY)
	{
		game_Swap(&g_image[y][x], &g_image[y][x + 1]);
		r.right += g_szBlock.cx;
	}
	else
		return FALSE;

	OffsetRect(&r, OX, OY);
	InvalidateRect(hwnd, &r, TRUE);
	UpdateWindow(hwnd);

	return TRUE;
}

void game_Shuffle(HWND hwnd)
{
	enum { LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3 };
	srand(time(0));
	int empty_x = 4;
	int empty_y = 4;

	int count = 0;

	while (1)
	{
		switch ((rand() % 4))
		{
		case LEFT: empty_x = max(0, empty_x - 1); break;
		case RIGHT:empty_x = min(4, empty_x + 1); break;
		case UP:   empty_y = max(0, empty_y - 1); break;
		case DOWN: empty_y = min(4, empty_y + 1); break;
		}
		if (game_MoveBlock(hwnd, empty_x, empty_y))
		{
			++count;
			if (count == COUNT * 50) 
				break;

			Sleep(50);
		}
	}
}

BOOL game_IsSuccess()
{
	int k = 0;
	for (int y = 0; y < COUNT; y++)
	{
		for (int x = 0; x < COUNT; x++)
		{
			if (g_image[y][x] != k++)
				return FALSE;
		}
	}
	return TRUE;
}
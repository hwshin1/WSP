//control.cpp
#include "std.h"

#define GAME_IMG_DIR TEXT("image\\OIP.bmp")

void con_Init(HWND hwnd)
{
	//비트맵 로드
	BITMAP bm = game_LoadImage(hwnd, GAME_IMG_DIR);

	//윈도우 크기 조절
	ui_SetWindowRect(hwnd, bm.bmWidth, bm.bmHeight);
	
	//블록의 크기 조절
	SIZE size = ui_GetszFull();
	game_SetBlockSize(hwnd, size);
	
	game_State(FALSE);

	//이미지 저장 배열
	game_ImageNumber_Init(hwnd);
}

void con_PrintGameView(HWND hwnd, HDC hdc)
{
	HBITMAP bmp = game_GetBitMap();
	int* arr = game_GetImage();

	ui_PrintGameView(hwnd, hdc, bmp, (int(*)[5])arr);
}

void con_Game_New(HWND hwnd)
{
	if (game_GetState() == TRUE)
	{
		UINT ret = MessageBox(hwnd, TEXT("현재 게임을 포기 하시겠습니까 ?"),  TEXT("확인"), MB_YESNO);
		if (ret != IDYES) return;
	}

	game_Shuffle(hwnd);
	game_State(TRUE);
}

void con_Click(HWND hwnd, POINTS pt)
{
	SIZE szFull = ui_GetszFull();
	SIZE szBlock = game_GetszBlock();

	if ((game_GetState() == FALSE) || (pt.x < OX) || (pt.x > OX + szFull.cx) ||
		(pt.y < OY) || (pt.y > OY + szFull.cy))
		return;

	int xBlock = (pt.x - OX) / szBlock.cx;
	int yBlock = (pt.y - OY) / szBlock.cy;
	if (!game_MoveBlock(hwnd, xBlock, yBlock))
	{ 
		MessageBeep(0);
	}
	else
	{
		if (game_IsSuccess())
		{
			MessageBox(hwnd, TEXT("축하합니다 . ^ ^!"), TEXT("성공!"), MB_OK);
			game_State(FALSE);
		}
	}
}
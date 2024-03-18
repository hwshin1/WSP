//game.h
#pragma once

#define COUNT 5

BITMAP game_LoadImage(HWND hwnd, const TCHAR* path);
void game_SetBlockSize(HWND hwnd, SIZE size);
void game_State(BOOL b);
BOOL game_GetState();
void game_ImageNumber_Init(HWND hwnd);
HBITMAP game_GetBitMap();
int* game_GetImage();
//게임진행
void game_Swap(int* a, int* b);
BOOL game_MoveBlock(HWND hwnd, int x, int y);
SIZE game_GetszBlock();
void game_Shuffle(HWND hwnd);
BOOL game_IsSuccess();
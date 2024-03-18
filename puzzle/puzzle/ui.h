//ui.h
#pragma once

#define OX 10 //여백
#define OY 10 //여백
#define EMPTY (COUNT*COUNT-1)

void ui_SetWindowRect(HWND hwnd, int w, int h);
SIZE ui_GetszFull();
void ui_PrintGameView(HWND hwnd, HDC hdc, HBITMAP bmp, int(*arr)[5]);

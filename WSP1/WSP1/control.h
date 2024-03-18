//control.h
#pragma once
#include "std.h"

void con_Init(HWND hDlg);
void con_CreateProcess(HWND hDlg);
void con_ListltemChanged(HWND hDlg, WPARAM wParam, LPARAM lParam);
void con_ProcessExit(HWND hDlg);
void con_ProcessCodeCheck(HWND hDlg);
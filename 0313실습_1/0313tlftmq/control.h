//control.h
#pragma once
void con_Init(HWND hDlg);
void con_Connect(HWND hDlg);
void con_ShortMessage(HWND hDlg, TCHAR* msg, int size);
void con_Connect(HWND hDlg, LPARAM lParam);
void con_CopyData(HWND hDlg, WPARAM wParam, LPARAM lParam);
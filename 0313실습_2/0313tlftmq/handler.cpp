//handler.cpp
#include "std.h"

INT_PTR OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	con_Init(hDlg);
	return TRUE;
}

INT_PTR OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	con_Connect(hDlg);
	con_ShortMessage(hDlg, wParam, lParam);
	return TRUE;
}

INT_PTR OnConnect(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	con_Connect(hDlg, lParam);
}

INT_PTR OnCopyData(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	con_CopyData(hDlg, wParam, lParam);
	return TRUE;
}
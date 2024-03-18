//handler.cpp
#include "std.h"

BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	con_Init(hDlg);
	return TRUE;
}

BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	if (LOWORD(wParam) == IDCANCEL)
		return OnClose(hDlg);
	else if (LOWORD(wParam) == IDC_BUTTON1)
	{
		con_CreateProcess(hDlg);
		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_BUTTON2)
	{
		con_ProcessCodeCheck(hDlg);
		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_BUTTON3)
	{
		con_ProcessExit(hDlg);
		return TRUE;
	}
	return FALSE;
}

BOOL OnNotify(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	con_ListltemChanged(hDlg, wParam, lParam);
}

BOOL OnClose(HWND hDlg)
{
	EndDialog(hDlg, IDCANCEL);
	return TRUE;
}
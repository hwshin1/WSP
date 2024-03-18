//handler.cpp
#include "std.h"

BOOL OnInitDiaglog(HWND hDlg, WPARAM wParam, LPARAM lParam)
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
		
		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_BUTTON2)
	{
		return TRUE;
	}
	return FALSE;
}

BOOL OnNotify(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}

BOOL OnClose(HWND hDlg)
{
	EndDialog(hDlg, IDCANCEL);
	return TRUE;
}
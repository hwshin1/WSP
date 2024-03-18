//handler.cpp
#include "std.h"

INT_PTR OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}

INT_PTR OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	if (LOWORD(wParam) == IDCANCEL)
	{
		EndDialog(hDlg, IDCANCEL);
		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_BUTTON1)
	{
		con_CreatePipe(hDlg);
	}
	else if (LOWORD(wParam) == IDC_BUTTON2)
	{
		con_Connect(hDlg);
	}
	else if (LOWORD(wParam) == IDC_BUTTON3)
	{
		con_SendMessage(hDlg);
	}
	else if (LOWORD(wParam) == IDC_BUTTON4)
	{
		con_DisConnect(hDlg);
	}
	return FALSE;
}
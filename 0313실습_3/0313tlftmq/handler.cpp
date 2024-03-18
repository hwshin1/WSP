//handler.cpp
#include "std.h"

INT_PTR OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	con_Init(hDlg);
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
		con_Connect(hDlg);
		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_BUTTON2)
	{
		con_DisConnect(hDlg);
		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_BUTTON3)
	{
		con_ShortMessage(hDlg);
		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_BUTTON4)
	{
		con_SetNickName(hDlg);
		return TRUE;
	}
	return FALSE;
}

INT_PTR OnConnect(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	con_Connect2(hDlg, lParam);
	return TRUE;
}

INT_PTR OnCopyData(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	con_CopyData(hDlg, wParam, lParam);
	return TRUE;
}
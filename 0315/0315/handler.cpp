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
		con_ComConnect(hDlg);
		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_BUTTON2)
	{
		con_DisComConnect(hDlg);
		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_BUTTON3)
	{
		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_BUTTON4)
	{
		return TRUE;
	}
	return FALSE;
}

INT_PTR OnConnect(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	con_Connect(hDlg, lParam);
	return TRUE;
}

INT_PTR OnCopyData(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	con_CopyData(hDlg, wParam, lParam);
	return TRUE;
}
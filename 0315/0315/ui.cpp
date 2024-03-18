//ui.cpp
#include "std.h"

HWND button1, button2, button3, button4;
HWND edit1;

void ui_GetControlHandle(HWND hDlg)
{
	button1 = GetDlgItem(hDlg, IDC_BUTTON1);
	button2 = GetDlgItem(hDlg, IDC_BUTTON2);
	button3 = GetDlgItem(hDlg, IDC_BUTTON3);
	button4 = GetDlgItem(hDlg, IDC_BUTTON4);
	edit1 = GetDlgItem(hDlg, IDC_EDIT1);
}

void ui_ButtonState(BOOL b1, BOOL b2, BOOL b3, BOOL b4)
{
	EnableWindow(button1, b1);
	EnableWindow(button2, b2);
	EnableWindow(button3, b3);
	EnableWindow(button4, b4);
}

void ui_PrintMessage(HWND hDlg, const TCHAR* msg)
{
	SYSTEMTIME st;
	GetLocalTime(&st);

	TCHAR buf[512];
	wsprintf(buf, TEXT("[%s] %s (%02d:%02d:%02d)"), msg, st.wHour, st.wMinute, st.wSecond);

	SendMessage(hDlg, EM_REPLACESEL, 0, (LPARAM)(buf));
	SendMessage(hDlg, EM_REPLACESEL, 0, (LPARAM)TEXT("\r\n"));
}

void ui_GetTargetName(HWND hDlg, TCHAR* name, int size)
{
	GetDlgItemText(hDlg, IDC_EDIT1, name, size);
}
//ui.cpp
#include "std.h"

HWND button1, button2, button3;

void ui_GetControlHandle(HWND hDlg)
{
	button1 = GetDlgItem(hDlg, IDC_BUTTON1);
	button2 = GetDlgItem(hDlg, IDC_BUTTON2);
	button3 = GetDlgItem(hDlg, IDC_BUTTON3);
}

void ui_ButtonState(BOOL b1, BOOL b2, BOOL b3)
{
	EnableWindow(button1, b1);
	EnableWindow(button2, b2);
	EnableWindow(button3, b3);
}

void ui_GetTargetName(HWND hDlg, TCHAR* msg)
{

}

void ui_GetChildName(HWND hDlg)
{

}

void ui_PrintMessage(HWND hDlg, const TCHAR* msg)
{
	TCHAR buf[512];
	//wsprintf(buf, TEXT("[%s] %s (%02d:%02d:%02d)"), msg, );

	SendMessage(hDlg, EM_REPLACESEL, 0, (LPARAM)(buf));
	SendMessage(hDlg, EM_REPLACESEL, 0, (LPARAM)TEXT("\r\n"));
}

void ui_GetShortMessage(HWND hDlg, TCHAR* msg, int size)
{

}

void ui_SetShortMessage(HWND hDlg, const TCHAR* msg)
{
	//SetDlgItemInt(hDlg, IDC_EDIT2, )
}
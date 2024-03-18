//control.cpp
#include "std.h"

void con_Init(HWND hDlg)
{
	ui_GetControlHandle(hDlg);
	ui_ButtonState(TRUE, TRUE, TRUE);
}

void con_Connect(HWND hDlg)
{
	TCHAR name[50];
	ui_GetTargetName(hDlg, name);

	ui_GetChildName(hDlg);
	ui_PrintMessage(hDlg, name);
	ui_ButtonState(TRUE,TRUE,FALSE);
	ipc_Connect(hDlg, name);
}

void con_ShortMessage(HWND hDlg, TCHAR* msg, int size)
{
	TCHAR name[50];
	ui_GetShortMessage(hDlg, msg, _countof(msg));
	ui_SetShortMessage(hDlg, msg, (int)(_tcsclen(msg)+1)*2);
	ui_PrintMessage(hDlg, msg);

	ipc_ShortMessage(hDlg, name, size);
}

void con_Connect(HWND hDlg, LPARAM lParam)
{
	ipc_Connect2(hDlg, lParam);
	ui_ButtonState(FALSE, TRUE, TRUE);
	ui_PrintMessage(hDlg, TEXT("立加 夸没捞 客辑 贸府凳"));

}

void con_CopyData(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	COPYDATASTRUCT* pData = (COPYDATASTRUCT*)lParam;
	DATA* p = (DATA*)pData->lpData;

	TCHAR buf[512];
	wsprintf(buf, TEXT("[%s] %s"), p->nickname, p->msg);
	ui_PrintMessage(hDlg, buf);
}
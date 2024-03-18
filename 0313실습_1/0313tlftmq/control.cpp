//control.cpp
#include "std.h"

void con_Init(HWND hDlg)
{
	ui_GetControlHandle(hDlg);
	ui_ButtonState(TRUE, FALSE, FALSE);
}

void con_Connect(HWND hDlg)
{
	TCHAR name[50];
	ui_GetTargetName(hDlg, name, _countof(name));

	if (ipc_Connect(hDlg, name) == TRUE)
	{
		ui_ButtonState(FALSE, TRUE, TRUE);
		ui_PrintMessage(hDlg, TEXT("연결 성공"));
	}
	else
	{
		ui_PrintMessage(hDlg, TEXT("연결 실패"));
	}
	ui_GetChildName(hDlg);
}

void con_ShortMessage(HWND hDlg, TCHAR* msg, int size)
{
	TCHAR name[50];
	ui_GetShortMessage(hDlg, msg, _countof(msg));
	ui_SetShortMessage(hDlg, msg, (int)(_tcsclen(msg) + 1) * 2);
	ui_PrintMessage(hDlg, msg);

	ipc_ShortMessage(hDlg, name, size);
}

void con_Connect(HWND hDlg, LPARAM lParam)
{
	ui_ButtonState(FALSE, TRUE, TRUE);
	ui_PrintMessage(hDlg, TEXT("접속 요청이 와서 처리됨"));
}

void con_CopyData(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	COPYDATASTRUCT* pData = (COPYDATASTRUCT*)lParam;
	DATA* p = (DATA*)pData->lpData;

	TCHAR buf[512];
	wsprintf(buf, TEXT("[%s] %s"), p->nickname, p->msg);
	ui_PrintMessage(hDlg, buf);
}
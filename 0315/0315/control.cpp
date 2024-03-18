//control.cpp
#include "std.h"

void con_Init(HWND hDlg)
{
	ui_GetControlHandle(hDlg);
	ui_ButtonState(TRUE, FALSE, FALSE, FALSE);
}

void con_ComConnect(HWND hDlg)
{
	TCHAR name[50];
	ui_GetTargetName(hDlg, name, _countof(name));

	if (ipc_ComConnect(hDlg, name) == TRUE)
	{
		ui_ButtonState(TRUE, FALSE, FALSE, FALSE);
		ui_PrintMessage(hDlg, TEXT("연결 성공"));
	}
	else
	{
		ui_PrintMessage(hDlg, TEXT("연결 실패"));
	}
}

void con_DisComConnect(HWND hDlg)
{
	ipc_DisConnect(hDlg);
	ui_ButtonState(TRUE, FALSE, FALSE, FALSE);
	ui_PrintMessage(hDlg, TEXT("연결해제 성공"));
}

void con_CopyData(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	COPYDATASTRUCT* pData = (COPYDATASTRUCT*)lParam;
	DATA* p = (DATA*)pData->lpData;

	TCHAR buf[512];
	wsprintf(buf, TEXT("[%s] %s"), p->nickname, p->msg);
	ui_PrintMessage(hDlg, buf);
}

void con_Connect(HWND hDlg, LPARAM lParam)
{
	ipc_Connect(hDlg, lParam);
	ui_ButtonState(FALSE, TRUE, TRUE, FALSE);
	ui_PrintMessage(hDlg, TEXT("접속 요청이 와서 처리됨"));
}
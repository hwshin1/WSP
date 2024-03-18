//ipc.cpp
#include "std.h"

HWND htarget;

BOOL ipc_Connect(HWND hDlg, TCHAR* name)
{
	htarget = FindWindow(0, name);
	if (htarget == 0)
		return FALSE;
	else
	{
		SendMessage(htarget, WM_CONNECT, 0, (LPARAM)hDlg);
		return TRUE;
	}
}

void ipc_DisConnect(HWND hDlg)
{
	htarget = 0;
}

void ipc_ShortMessage(HWND hDlg, TCHAR* msg, int size)
{
	TCHAR nickname[20];
	GetWindowText(hDlg, nickname, _countof(nickname));

	DATA data;
	_tcscpy_s(data.nickname, _countof(data.nickname), nickname);
	_tcscpy_s(data.msg, _countof(data.msg), msg);
	GetLocalTime(&data.st);

	COPYDATASTRUCT cds;
	cds.dwData = (ULONG_PTR)hDlg;   //자신의 핸들
	cds.lpData = &data; //주소
	cds.cbData = sizeof(data);

	SendMessage(htarget, WM_COPYDATA, 0, (LPARAM)&cds);
}

void ipc_Connect2(HWND hDlg, LPARAM lParam)
{
	htarget = (HWND)lParam;
}
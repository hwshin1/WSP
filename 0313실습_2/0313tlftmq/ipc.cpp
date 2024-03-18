//ipc.cpp
#include "std.h"

HWND htarget;

BOOL ipc_Connect(HWND hDlg, TCHAR* name)
{
	htarget = FindWindow(0, name);
	if (htarget == 0)
		return TRUE;
	else
		return FALSE;
}

int ipc_ShortMessage(HWND hDlg, TCHAR* msg, int size)
{
	DATA data;
	_tcscpy_s(data.nickname, _countof(data.nickname), TEXT("½ÅÇö¿ì"));
	_tcscpy_s(data.msg, _countof(data.msg), msg);
	GetLocalTime(&data.st);

	COPYDATASTRUCT cds;
}

void ipc_Connect2(HWND hDlg, LPARAM lParam)
{
	htarget = (HWND)lParam;
}
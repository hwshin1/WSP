//ipc.cpp
#include "std.h"

HWND htarget;

BOOL ipc_Connect(HWND hDlg, TCHAR* name)
{
	htarget = FindWindow(0, name);
	if (htarget == 0)
		return FALSE;
	else
		return TRUE;
}

int ipc_ShortMessage(HWND hDlg, TCHAR* msg, int size)
{
	DATA data;
	_tcscpy_s(data.nickname, _countof(data.nickname), TEXT("½ÅÇö¿ì"));
	_tcscpy_s(data.msg, _countof(data.msg), msg);
	GetLocalTime(&data.st);

	COPYDATASTRUCT cds;
}
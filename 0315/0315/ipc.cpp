//ipc.cpp
#include "std.h"

HWND htarget;

BOOL ipc_ComConnect(HWND hDlg, TCHAR* name)
{
	htarget = FindWindow(0, name);
	if (htarget == 0)
		return FALSE;
	else
		return TRUE;
}

void ipc_DisConnect(HWND hDlg)
{
	htarget = 0;
}

void ipc_Connect(HWND hDlg, LPARAM lParam)
{
	htarget = (HWND)lParam;
}
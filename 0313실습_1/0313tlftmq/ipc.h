//ipc.h
#pragma once

BOOL ipc_Connect(HWND hDlg, TCHAR* name);
int ipc_ShortMessage(HWND hDlg, TCHAR* msg, int size);
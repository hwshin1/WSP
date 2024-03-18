//ipc.h
#pragma once

BOOL ipc_Connect(HWND hDlg, TCHAR* name);
void ipc_ShortMessage(HWND hDlg, TCHAR* msg, int size);
void ipc_Connect2(HWND hDlg, LPARAM lParam);
void ipc_DisConnect(HWND hDlg);
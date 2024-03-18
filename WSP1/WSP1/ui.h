//ui.h
#pragma once

//---list control--------------------------------
void ui_GetHandle(HWND hDlg);
void ui_List_InitHeader(HWND hDlg);
BOOL ui_ListItemChanged(HWND hDlg, WPARAM wParam, LPARAM lParam, ListPrintData* pdata);
//------------------------------------------------

HANDLE ui_GetProcessHandle(HWND hDlg);

void ui_SelectPrint(HWND hDlg, ListPrintData data);

void ui_GetProcessName(HWND hDlg, TCHAR* pname, int size);

void ui_Process_Print(HWND hDlg, TCHAR* pname, PROCESS_INFORMATION pi);
//ui.h
#pragma once
void ui_GetControlHandle(HWND hDlg);
void ui_ButtonState(BOOL b1, BOOL b2, BOOL b3);
void ui_GetTargetName(HWND hDlg, TCHAR* name, int size);
void ui_PrintMessage(HWND hDlg, const TCHAR* msg);
void ui_GetShortMessage(HWND hDlg, TCHAR* msg, int size);
void ui_SetShortMessage(HWND hDlg, const TCHAR* msg);
//ui.h
#pragma once

void ui_GetControlHandle(HWND hDlg);
void ui_ButtonState(BOOL b1, BOOL b2, BOOL b3, BOOL b4);
void ui_PrintMessage(HWND hDlg, const TCHAR* msg);
void ui_GetTargetName(HWND hDlg, TCHAR* name, int size);
//ui.cpp
#include "std.h"

HWND hList1;

void ui_GetHandle(HWND hDlg)
{
	hList1 = GetDlgItem(hDlg, IDC_LIST2);
}
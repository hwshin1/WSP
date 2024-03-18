//ui.cpp
#include "std.h"

HWND hList1;

void ui_GetHandle(HWND hDlg)
{
	hList1 = GetDlgItem(hDlg, IDC_LIST1);
}

void ui_List_InitHeader(HWND hDlg)
{
	LVCOLUMN COL;
	COL.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	COL.fmt = LVCFMT_LEFT;
	COL.cx = 80;
	COL.pszText = (LPWSTR)TEXT("이름");				// 첫 번째 헤더
	COL.iSubItem = 0;
	SendMessage(hList1, LVM_INSERTCOLUMN, 0, (LPARAM)&COL);

	COL.pszText = (LPWSTR)TEXT("PID");			// 두 번째 헤더
	COL.iSubItem = 1;
	SendMessage(hList1, LVM_INSERTCOLUMN, 1, (LPARAM)&COL);

	COL.cx = 80;
	COL.pszText = (LPWSTR)TEXT("PHandle");				// 세 번째 헤더
	COL.iSubItem = 2;
	SendMessage(hList1, LVM_INSERTCOLUMN, 2, (LPARAM)&COL);

	COL.pszText = (LPWSTR)TEXT("쓰레드ID");			// 두 번째 헤더
	COL.iSubItem = 3;
	SendMessage(hList1, LVM_INSERTCOLUMN, 3, (LPARAM)&COL);

	COL.pszText = (LPWSTR)TEXT("쓰레드Handle");			// 두 번째 헤더
	COL.iSubItem = 4;
	SendMessage(hList1, LVM_INSERTCOLUMN, 4, (LPARAM)&COL);
}


void ui_Process_Print(HWND hDlg, TCHAR* pname , PROCESS_INFORMATION pi)
{
	TCHAR buf[50];

	// 텍스트 아이템들을 등록한다.
	LVITEM LI;

	LI.mask = LVIF_TEXT;

	LI.iItem = 0;		//*
	LI.iSubItem = 0;	//*
	LI.pszText = (LPWSTR)pname;			// 첫 번째 아이템
	SendMessage(hList1, LVM_INSERTITEM, 0, (LPARAM)&LI);

	LI.iSubItem = 1;	//*	
	wsprintf(buf, TEXT("%d"), pi.dwProcessId);
	LI.pszText = (LPWSTR)buf;
	SendMessage(hList1, LVM_SETITEM, 0, (LPARAM)&LI);

	LI.iSubItem = 2;
	wsprintf(buf, TEXT("%d"), pi.hProcess);
	LI.pszText = (LPWSTR)buf;
	LI.pszText = (LPWSTR)buf;
	SendMessage(hList1, LVM_SETITEM, 0, (LPARAM)&LI);

	LI.iSubItem = 3;
	wsprintf(buf, TEXT("%d"), pi.dwThreadId);
	LI.pszText = (LPWSTR)buf;
	LI.pszText = (LPWSTR)buf;
	SendMessage(hList1, LVM_SETITEM, 0, (LPARAM)&LI);

	LI.iSubItem = 4;
	wsprintf(buf, TEXT("%d"), pi.hThread);
	LI.pszText = (LPWSTR)buf;
	LI.pszText = (LPWSTR)buf;
	SendMessage(hList1, LVM_SETITEM, 0, (LPARAM)&LI);
}


BOOL ui_ListItemChanged(HWND hDlg, WPARAM wParam, LPARAM lParam, ListPrintData* pdata)
{
	LPNMHDR hdr = (LPNMHDR)lParam;
	LPNMLISTVIEW nlv = (LPNMLISTVIEW)lParam;
	TCHAR Caption[255];

	if (hdr->hwndFrom == hList1)
	{
		switch (hdr->code)
		{
		case LVN_ITEMCHANGED:
			if (nlv->uChanged == LVIF_STATE && nlv->uNewState == (LVIS_SELECTED | LVIS_FOCUSED))
			{
				ListView_GetItemText(hList1, nlv->iItem, 0, pdata->name, _countof(pdata->name));
				ListView_GetItemText(hList1, nlv->iItem, 1, Caption, _countof(Caption));
				pdata->pid = _tstoi(Caption);
				ListView_GetItemText(hList1, nlv->iItem, 2, Caption, _countof(Caption));
				pdata->phandle = _tstoi(Caption);
				ListView_GetItemText(hList1, nlv->iItem, 3, Caption, _countof(Caption));
				pdata->tid = _tstoi(Caption);
				ListView_GetItemText(hList1, nlv->iItem, 4, Caption, _countof(Caption));
				pdata->thandle = _tstoi(Caption);
				return TRUE;
			}
		}
	}

	return FALSE;
}

HANDLE ui_GetProcessHandle(HWND hDlg)
{
	return (HANDLE)GetDlgItemInt(hDlg, IDC_EDIT4, 0, 0);
}

void ui_SelectPrint(HWND hDlg, ListPrintData data)
{
	SetDlgItemText(hDlg, IDC_EDIT2, data.name);
	SetDlgItemInt(hDlg, IDC_EDIT3, data.pid, 0);
	SetDlgItemInt(hDlg, IDC_EDIT4, data.phandle, 0);
	SetDlgItemInt(hDlg, IDC_EDIT5, data.tid, 0);
	SetDlgItemInt(hDlg, IDC_EDIT6, data.thandle, 0);
}

void ui_GetProcessName(HWND hDlg, TCHAR* pname, int size)
{
	GetDlgItemText(hDlg, IDC_EDIT1, pname, size);
}
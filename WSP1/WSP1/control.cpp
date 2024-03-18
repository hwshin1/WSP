//control.cpp
#include "std.h"

void con_Init(HWND hDlg)
{
	ui_GetHandle(hDlg);
	ui_List_InitHeader(hDlg);
}

void con_CreateProcess(HWND hDlg)
{
	TCHAR pname[50];
	ui_GetProcessName(hDlg, pname, _countof(pname));

	//SetWindowText(hDlg, pname);
	
	PROCESS_INFORMATION pi;
	if (pro_CreateProcess(pname, &pi) == TRUE)
	{
		ui_Process_Print(hDlg, pname, pi);
	}
	else
	{
		MessageBox(hDlg, TEXT("실패"), TEXT("알림"), MB_OK);
	}
}

void con_ListltemChanged(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	ListPrintData data;

	if (ui_ListItemChanged(hDlg, wParam, lParam, &data) == FALSE)
		return;

	ui_SelectPrint(hDlg, data);
}

void con_ProcessCodeCheck(HWND hDlg)
{
	HANDLE phandle;

	phandle = ui_GetProcessHandle(hDlg);

	if (pro_ProcessCodeCheck(phandle) == TRUE)
		MessageBox(0, TEXT("실행중"), TEXT("확인"), MB_OK);
	else
		MessageBox(0, TEXT("종료됨"), TEXT("확인"), MB_OK);
}

void con_ProcessExit(HWND hDlg)
{
	HANDLE phandle;
	phandle = ui_GetProcessHandle(hDlg);
	pro_ProcessExit(phandle);
}
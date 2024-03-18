//ui.cpp
#include "std.h"

HANDLE hRead, hWrite, hRead1, hWrite1;
HWND hwnd;

void ui_EditPrint(HWND hDlg, const TCHAR* buf)
{
	HWND hEdit = GetDlgItem(hDlg, IDC_EDIT1);

	SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)(buf));
	SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)TEXT("\r\n"));
}

void ui_CreatePipe(HWND hDlg)
{
	BOOL b1 = CreatePipe(&hRead, &hWrite, 0, 4096);
	BOOL b2 = CreatePipe(&hRead1, &hWrite1, 0, 4096);

	if (b1 == TRUE && b2 == TRUE)
	{
		MessageBox(0, TEXT("성공"), TEXT("알림"), MB_OK);
	}
	else
	{
		MessageBox(0, TEXT("실패"), TEXT("알림"), MB_OK);
	}
	return;
}

void ui_Connect(HWND hDlg)
{
	hwnd = FindWindow(0, TEXT("수신자"));
	if (hwnd == 0)
	{
		MessageBox(hwnd, TEXT("못찾음"), TEXT("알림"), MB_OK);
		return;
	}
	// HWND -> PID -> PHANDLE
	DWORD pid;
	GetWindowThreadProcessId(hwnd, &pid);
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);

	//핸들복사
	HANDLE c_hRead, c_hWrite;
	DuplicateHandle(GetCurrentProcess(), hRead, hProcess, &c_hRead, 0, 0, DUPLICATE_SAME_ACCESS);
	DuplicateHandle(GetCurrentProcess(), hWrite1, hProcess, &c_hWrite, 0, 0, DUPLICATE_SAME_ACCESS);

	//핸들 전송
	SendMessage(hwnd, WM_READ_HANDLE, (WPARAM)c_hWrite, (LPARAM)c_hRead);

	//정리
	CloseHandle(hWrite1);
	CloseHandle(hRead);
	CloseHandle(hProcess);

	/*HANDLE h = CreateThread(0, 0, RecvThread, hDlg, 0, 0);
	CloseHandle(h);*/

	ui_EditPrint(hDlg, TEXT("연결 성공"));
	return;
}
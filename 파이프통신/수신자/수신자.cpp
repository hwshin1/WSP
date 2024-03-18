//수신자.cpp
#pragma comment (linker, "/subsystem:windows")

#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

#include "resource.h"

#define WM_READ_HANDLE WM_USER+100
#define WM_DISCONNECT WM_USER+200

HANDLE hRead, hWrite;

void Edit_Print(HWND hDlg, const TCHAR* buf)
{
	HWND hEdit = GetDlgItem(hDlg, IDC_EDIT1);

	SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)(buf));
	SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)TEXT("\r\n"));
}

unsigned long __stdcall RecvThread(void* p)
{
	HWND hDlg = (HWND)p;
	TCHAR buf[512];

	while (true)
	{
		memset(buf, 0, sizeof(buf));
		DWORD len;
		BOOL b = ReadFile(hRead, buf, _countof(buf), &len, 0);
		if (b == FALSE)
			break;

		Edit_Print(hDlg, buf);

		//전송
		WriteFile(hWrite, buf, (DWORD)((_tcslen(buf) + 1) * 2), &len, 0);
		Edit_Print(hDlg, TEXT(">> 전송\r\n"));
	}

	CloseHandle(hRead);
	Edit_Print(hDlg, TEXT("파이프고장 - 스레드 종료"));

	return 0;
}

INT_PTR OnConnect(HWND hDlg, LPARAM lParam)
{
	hRead = (HANDLE)lParam;
	Edit_Print(hDlg, TEXT("핸들 수신"));

	HANDLE h = CreateThread(0, 0, RecvThread, hDlg, 0, 0);
	CloseHandle(h);

	return TRUE;
}

INT_PTR CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_READ_HANDLE:
		return OnConnect(hDlg, lParam);
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			EndDialog(hDlg, IDCANCEL);
			return TRUE;
		}
	}
	return FALSE;
}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd)
{
	INT_PTR ret = DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc);
	return 0;
}
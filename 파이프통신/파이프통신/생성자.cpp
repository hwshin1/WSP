#pragma comment (linker, "/subsystem:windows")
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include "resource.h"

#define WM_READ_HANDLE WM_USER+100
#define WM_DISCONNECT WM_USER+200

HANDLE hRead, hWrite;
HWND hwnd;

INT_PTR OnCreatePipe(HWND hDlg)
{
	if (CreatePipe(&hRead, &hWrite, 0, 4096) == TRUE)
	{
		MessageBox(0, TEXT("����"), TEXT("�˸�"), MB_OK);
	}
	else
	{
		MessageBox(0, TEXT("����"), TEXT("�˸�"), MB_OK);
	}
	return FALSE;
}

INT_PTR OnConnect(HWND hDlg)
{
	hwnd = FindWindow(0, TEXT("����"));
	if (hwnd == 0)
	{
		MessageBox(hwnd, TEXT("��ã��"), TEXT("�˸�"), MB_OK);
		return TRUE;
	}
	// HWND -> PID -> PHANDLE
	DWORD pid;
	GetWindowThreadProcessId(hwnd, &pid);
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);

	//�ڵ麹��
	HANDLE hRead1;
	DuplicateHandle(GetCurrentProcess(), hRead, hProcess, &hRead1, 0, 0, DUPLICATE_SAME_ACCESS);

	//�ڵ� ����
	SendMessage(hwnd, WM_READ_HANDLE, 0, (LPARAM)hRead1);

	//����
	CloseHandle(hRead);
	CloseHandle(hProcess);

	MessageBox(hwnd, TEXT("���� ����"), TEXT("�˸�"), MB_OK);
	return TRUE;
}

INT_PTR OnSendMessage(HWND hDlg)
{
	TCHAR msg[512];
	GetDlgItemText(hDlg, IDC_EDIT2, msg, _countof(msg));

	DWORD len;
	WriteFile(hWrite, msg, (DWORD)((_tcslen(msg) + 1) * 2), &len, 0);

	TCHAR buf[50];
	wsprintf(buf, TEXT("����: %dbyte"), len);
	SetDlgItemText(hDlg, IDC_STATIC1, buf);

	return TRUE;
}

INT_PTR OnDisConnect(HWND hDlg)
{
	SendMessage(hwnd, WM_DISCONNECT, 0, 0);
	CloseHandle(hWrite);
	return 0;
}

INT_PTR CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			EndDialog(hDlg, IDCANCEL);
			return TRUE;
		case IDC_BUTTON1:
			return OnCreatePipe(hDlg);
		case IDC_BUTTON2:
			return OnConnect(hDlg);
		case IDC_BUTTON3:
			return OnSendMessage(hDlg);
		case IDC_BUTTON4:
			return OnDisConnect(hDlg);
		}
	}
	return FALSE;
}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd)
{
	INT_PTR ret = DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc);
	return 0;
}
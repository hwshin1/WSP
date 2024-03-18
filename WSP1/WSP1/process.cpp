//process.cpp
#include "std.h"

BOOL pro_CreateProcess(TCHAR* pname, PROCESS_INFORMATION *ppi)		//21
{
	PROCESS_INFORMATION pi;					//out
	STARTUPINFO si = { sizeof(si) };		//in

	BOOL b = CreateProcess(0, pname, 0, 0, 0, 0, 0, 0, &si, &pi);
	*ppi = pi;

	return b;
}

BOOL pro_ProcessCodeCheck(HANDLE handle)
{
	DWORD code;
	GetExitCodeProcess(handle, &code);
	if (code == STILL_ACTIVE)
		return TRUE;
	else
	{
		CloseHandle(handle);
		return FALSE;
	}
}

void pro_ProcessExit(HANDLE handle)
{
	TerminateProcess(handle, 0);
}
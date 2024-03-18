//process.h
#pragma once
#include "std.h"

BOOL pro_CreateProcess(TCHAR* pname, PROCESS_INFORMATION* ppi);
BOOL pro_ProcessCodeCheck(HANDLE handle);
void pro_ProcessExit(HANDLE handle);
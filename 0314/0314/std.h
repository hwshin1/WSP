//std.h
#pragma once

#pragma comment (linker, "/subsystem:windows")

#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

#include "handler.h"
#include "control.h"
#include "resource.h"
#include "ui.h"

#define WM_READ_HANDLE WM_USER+100
#define WM_DISCONNECT WM_USER+200
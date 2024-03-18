//std.h
#pragma once
#pragma comment (linker, "/subsystem:windows")

#include <Windows.h>
#include <tchar.h>

#include "handler.h"
#include "control.h"
#include "resource.h"
#include "ui.h"
#include "data.h"
#include "ipc.h"

#define WM_CONNECT WM_USER+100
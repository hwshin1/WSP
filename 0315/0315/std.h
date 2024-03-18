//std.h
#pragma once
#pragma comment (linker, "/subsystem:windows")

#include <Windows.h>
#include <tchar.h>

#include "resource.h"
#include "handler.h"
#include "control.h"
#include "ui.h"
#include "ipc.h"
#include "data.h"

#define WM_CONNECT WM_USER+100
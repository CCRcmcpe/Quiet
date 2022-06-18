#include <iostream>
#include <Windows.h>
using namespace std;

LPCWSTR help_info = LR"(Quiet v1.1 RcINS 2022
Creates a process without windows (CreateProcessW, CREATE_NO_WINDOW).

Usage: quiet.exe cmdLine

cmdLine     Command line to start.
/?          Displays this help.

Remarks:
1. Quiet creates no window unless it's displaying help.
2. Created process inherits working directory from Quiet.)";

int APIENTRY wWinMain(
	_In_ HINSTANCE,
	_In_opt_ HINSTANCE,
	_In_ LPWSTR lpCmdLine,
	_In_ int)
{
	if (wcslen(lpCmdLine) == 0 || wcscmp(lpCmdLine, L"/?") == 0)
	{
		MessageBoxW(nullptr, help_info, L"Help: Quiet", MB_OK);
		return 1;
	}
	STARTUPINFOW startup_info{};
	PROCESS_INFORMATION process_info{};
	if (!CreateProcess(nullptr, lpCmdLine, nullptr, nullptr, false,
	                   CREATE_NO_WINDOW, nullptr, nullptr, &startup_info, &process_info))
	{
		return -1;
	}
	CloseHandle(process_info.hProcess);
	CloseHandle(process_info.hThread);
	return 0;
}

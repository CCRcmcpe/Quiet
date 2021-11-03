#include <iostream>
#include <Windows.h>
using namespace std;

LPCWSTR info_help = LR"(Quiet v1.0 RcINS 2021
Creates a process without window (CREATE_NO_WINDOW).

Usage: quiet.exe cmdLine

cmdLine     Command line to start.
/?          Displays this help.

Remarks:
1. Quiet creates no window unless it's displaying help.
2. Created process inherits working directory from Quiet.)";

int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR lpCmdLine, int)
{
	if (wcslen(lpCmdLine) == 0 || wcscmp(lpCmdLine, L"/?") == 0)
	{
		MessageBoxW(nullptr, info_help, L"Help: Quiet", MB_OK);
	}
	STARTUPINFOW si{};
	PROCESS_INFORMATION pi;
	CreateProcess(nullptr, lpCmdLine, nullptr, nullptr, false,
	              CREATE_NO_WINDOW, nullptr, nullptr, &si, &pi);
}

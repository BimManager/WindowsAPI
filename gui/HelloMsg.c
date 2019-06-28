/*
 *  HelloMsg.c
 */

#include "stdafx.h"

#define BUF_SIZE 4096

TCHAR   buffer[BUF_SIZE] = {_T("Hiya")};

int FASTCALL _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PTSTR pszCmdLine, int iCmdShow)
{
    HANDLE  hOut;
    DWORD   dwOut;
    FILE    *pf;

    MessageBox(NULL, _T("Hello, Windows 98!"), _T("HelloMsg"), MB_OK | MB_HELP | MB_ICONINFORMATION );
    if (AllocConsole)
    {
        AttachConsole(GetCurrentProcessId());
        freopen(_T("CONOUT$"), "w", stdout);
        _cwprintf(L"Hiya!");
    }
    return (0);
}

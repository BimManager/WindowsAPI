/*
 *  WinMain.c
 */

#include "stdafx.h"
#include "WndTmpl.h"

int FASTCALL    _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    TCHAR pszCmdLine, int iShowCmd)
{
    HWND    hwnd;
    MSG     msg;

    hwnd = GenerateWindow(hInstance, &WndProc, CLASS_NAME);
    ShowWindow(hwnd, iShowCmd);
    UpdateWindow(hwnd);
    /* STEP 3: The message loop */
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (msg.wParam);
}
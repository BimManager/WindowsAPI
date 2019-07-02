/*
 *  WinMainClassic.c
 */

#include "stdafx.h"
#include "WndTmpl.h"

int FASTCALL _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                LPTSTR pszCmdLine, int iShowCmd)
{
    WNDCLASSEX  wc;
    HWND        hwnd;
    MSG         msg;

    /* STEP 1: Register the Window Class */
    wc.cbSize       = sizeof(WNDCLASSEX);
    wc.style        = 0;
    wc.lpfnWndProc  = WndProc;
    wc.cbClsExtra   = 0;
    wc.cbWndExtra   = 0;
    wc.hInstance    = hInstance;
    wc.hIcon        = NULL;
    wc.hCursor      = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground    = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName     = NULL;
    wc.lpszClassName    = CLASS_NAME;
    wc.hIconSm          = NULL;
    if (!RegisterClassEx(&wc))
    {
        MessageBox(NULL, GenErrorMessage(GetLastError()),
                    _T("RegisterClassEx"), MB_ICONERROR | MB_OK);
        return (1);
    }

    /* STEP 2: Create the Window */
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        CLASS_NAME,
        _T("Template Window"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, hInstance, NULL);
    if (hwnd == NULL)
    {
        MessageBox(NULL, GenErrorMessage(GetLastError()),
                    _T("CreateWindowEx"), MB_ICONERROR | MB_OK);
        return (2);
    }
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
/*
 *  main.c
 */

#include "stdafx.h"
#include "WndTmpl.h"

int main(void)
{
    HWND    hwnd;
    MSG     msg;

    hwnd = GenerateWindow(NULL, &WndProc, CLASS_NAME);
    ShowWindow(hwnd, 1);
    UpdateWindow(hwnd);
    /* STEP 3: The message loop */
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (0);
}
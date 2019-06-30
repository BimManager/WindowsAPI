/*
 *  main.c
 */

#include "stdafx.h"
#include "WndTmpl.h"

int main(void)
{
    HANDLE      hInstance;
    HWND        hwnd;
    WNDCLASSEX  wc;
    MSG         msg;

    hInstance = GetModuleHandle(NULL);
    if (hInstance == NULL)
    {
        GenErrorMessage(GetLastError());
        return (1);
    }
    if (RegisterWindow(&wc, hInstance, CLASS_NAME, &WndProc) == -1)
        return (1);
    //hwnd = GenerateWindow(NULL, &WndProc, CLASS_NAME);
    hwnd = GenWindow(hInstance, CLASS_NAME);
    if (hwnd == NULL)
        return (2);
    ShowWindow(hwnd, 1);
    UpdateWindow(hwnd);
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (0);
}
/*
 *  WndTmpl.c
 */

#include "stdafx.h"
#include "WndTmpl.h"

HWND FASTCALL   GenerateWindow(
                    HINSTANCE hInstance,
                    LRESULT (*WndProc)(HWND, UINT, WPARAM, LPARAM),
                    TCHAR   pszClassName)
{
    WNDCLASSEX  wc;
    HWND        hwnd;

    /* STEP 1: Register the Window Class */
    wc.cbSize       = sizeof(WNDCLASSEX);
    wc.style        = 0;
    wc.lpfnWndProc  = WndProc;
    wc.cbClsExtra   = 0;
    wc.cbWndExtra   = 0;
    wc.hInstance    = hInstance;
    wc.hIcon        = NULL;
    wc.hCursor      = NULL;
    wc.hbrBackground    = (HBRUSH)(COLOR_MENU + 1);
    wc.lpszMenuName     = NULL;
    wc.lpszClassName    = pszClassName;
    wc.hIconSm          = NULL;

    if (!RegisterClassEx(&wc))
    {
        MessageBox(NULL, _T("Window registration has failed."),
                    _T("Error"), MB_ICONERROR | MB_OK);
        return (NULL);
    }

    /* STEP 2: Create the Window */
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        pszClassName,
        _T("Template Window"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, hInstance, NULL);
    if (hwnd == NULL)
    {
        MessageBox(NULL, _T("Window creation has failed."),
                    _T("Error"), MB_ICONERROR | MB_OK);
        return (NULL);
    }
    return (hwnd);
}

LRESULT CALLBACK    WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break ;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default :
            return (DefWindowProc(hwnd, uMsg, wParam, lParam));
    }
    return (0);
}

int                 RegisterWindow(
                        WNDCLASSEX *pWc,
                        HINSTANCE hInstance,
                        TCHAR   pszClassName,
                        LRESULT (*WndProc)(HWND, UINT, WPARAM, LPARAM))
{
    pWc->cbSize       = sizeof(WNDCLASSEX);
    pWc->style        = 0;
    pWc->lpfnWndProc  = WndProc;
    pWc->cbClsExtra   = 0;
    pWc->cbWndExtra   = 0;
    pWc->hInstance    = hInstance;
    pWc->hIcon        = NULL;
    pWc->hCursor      = NULL;
    pWc->hbrBackground    = (HBRUSH)(COLOR_MENU + 1);
    pWc->lpszMenuName     = NULL;
    pWc->lpszClassName    = pszClassName;
    pWc->hIconSm          = NULL;

    if (!RegisterClassEx(pWc))
    {
        MessageBox(NULL, _T("Window registration has failed."),
                    _T("Error"), MB_ICONERROR | MB_OK);
        return (-1);
    }
    return (0);
}

HWND FASTCALL       GenWindow(HINSTANCE hInstance, TCHAR pszClassName)
{
    HWND    hwnd;
    LPTSTR  pszMsg;

    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        pszClassName,
        _T("Template Window"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, hInstance, NULL);
    if (hwnd == NULL)
    {
        pszMsg = GenErrorMessage(GetLastError());
        if (pszMsg == NULL)
        {
            MessageBox(NULL, _T("Error message has failed."),
                    _T("Error"), MB_ICONERROR | MB_OK);
            return (NULL);
        }
        MessageBox(NULL, pszMsg,
                    _T("Error"), MB_ICONERROR | MB_OK);
        LocalFree(pszMsg);
        return (NULL);
    }
    return (hwnd);
}

LPTSTR                GenErrorMessage(DWORD dwErrId)
{
    LPTSTR   pvBuffer;
    DWORD    dwMsgLen;

    dwMsgLen = FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM,
        NULL, dwErrId, 0,
        (LPTSTR)&pvBuffer, 0, NULL);
    if (dwMsgLen > 0)
        return (pvBuffer);
    return (NULL);
}
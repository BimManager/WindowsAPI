/*
 *  AboutDlgProc.c
 */

#include "stdafx.h"
#include "WndTmpl.h"
#include "resource.h"

BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_INITDIALOG:
            return (TRUE);
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDOK:
                    EndDialog(hwnd, IDOK);
                    break ;
                case IDCANCEL:
                    EndDialog(hwnd, IDCANCEL);
                    break ;
                
            }
            break ;
        default:
            return (FALSE);
    }
    return (TRUE);
}
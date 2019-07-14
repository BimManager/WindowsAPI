/*
 *  ToolDlgProc.c
 */

#include "stdafx.h"
#include "WndTmpl.h"
#include "resource.h"

INT_PTR CALLBACK    ToolDlgProc(HWND hwnd, UINT uMsg,
                        WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_INITDIALOG:
            return (TRUE);
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDC_PRESS:
                    break ;
                case IDC_OTHER:
                    break ;
            }
            break ;
        }
        default:
            return (FALSE);
    }
    return (TRUE);
}                        
/*
 *  WndProc.c
 */

#include "stdafx.h"
#include "WndTmpl.h"
#include "resource.h"

#define BUFF_SIZE 4096

void    CreateSomeFile(void);
void    discurdir(void);
void    LaunchNotepad(void);

LRESULT CALLBACK    WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static TCHAR buffer[BUFF_SIZE];
    switch (uMsg)
    {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break ;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_KEYDOWN:
            switch (wParam)
            {
                case VK_TAB:
                    discurdir();
                    break ;
                case VK_RETURN:
                    LaunchNotepad();
                    break ;
            }
            break;
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case ID_FILE_EXIT:
                    if (MessageBox(hwnd, _T("Are you certain that you wish to git rid of this window?"),
                        _T("Exit?"), MB_OKCANCEL) == IDOK)
                        PostMessage(hwnd, WM_CLOSE, 0, 0);
                    break ;
                case ID_FILE_ABOUT:
                    MessageBox(hwnd, _T("What is up?"), _T("Exit?"), MB_OK);
                    break ;
                default:
                    wcscpy(buffer, _T("LOWORD(wParam) = "));
                    _itow(LOWORD(wParam), buffer + wcslen(buffer), 10);
                    MessageBox(hwnd, buffer, _T("Default"), MB_OK);
                    break ;
            }
            break ;
        default:
            return (DefWindowProc(hwnd, uMsg, wParam, lParam));
    }
    return (0);
}            

void    CreateSomeFile(void)
{
    FILE    *pf;
    char    *filename;

    filename = "Foo.txt";
    pf = fopen(filename, "w");
    if (pf != NULL)
    {
        fwrite(filename, sizeof(char), 
            strlen(filename), pf);
        fclose(pf);
    }
}

void    discurdir(void)
{
    TCHAR   buffer[MAX_PATH + 2];
    DWORD   dwPathLen;

    if ((dwPathLen = GetCurrentDirectory(MAX_PATH + 2, buffer)))
    {
        buffer[dwPathLen] = '\0';
        MessageBox(NULL, (LPTSTR)buffer, 
            _T("Current Directory"), MB_OK | MB_ICONINFORMATION);
    }
}

void    LaunchNotepad(void)
{
    LPCTSTR             appName;
    STARTUPINFO         startupInfo;
    PROCESS_INFORMATION processInfo;
    
    appName = _T("c:\\windows\\notepad.exe");
    startupInfo.cb = sizeof(STARTUPINFO);
    if (!CreateProcess(appName, NULL, NULL, NULL,
        0, 0, NULL, NULL, &startupInfo, &processInfo))
        MessageBox(NULL, GenErrorMessage(GetLastError()),
            _T("CreateProcess"), MB_ICONERROR | MB_OK);
}
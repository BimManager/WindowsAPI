/*
 *  WndProc.c
 */

#include "stdafx.h"
#include "WndTmpl.h"

void    CreateSomeFile(void);
void    discurdir(void);
void    LaunchNotepad(void);

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
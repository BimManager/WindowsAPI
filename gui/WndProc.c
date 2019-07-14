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
    static HWND hTool;

    switch (uMsg)
    {
        case WM_CREATE:
            hTool = CreateDialog(GetModuleHandle(NULL),
                MAKEINTRESOURCE(IDD_TOOLBAR), hwnd, ToolDlgProc);
            if (hTool)
                ShowWindow(hTool, SW_SHOW);
            break ;
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break ;
        case WM_DESTROY:
            PostQuitMessage(0);
            break ;
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
                    if (MessageBox(hwnd, _T("Kill this window?"),
                        _T("Exit?"), MB_OKCANCEL) == IDOK)
                        PostMessage(hwnd, WM_CLOSE, 0, 0);
                    break ;
                case ID_FILE_ABOUT:
                    int ret = DialogBox(GetModuleHandle(NULL), 
                        MAKEINTRESOURCE(IDD_ABOUT), hwnd, AboutDlgProc);
                    if (ret == IDOK)
                        MessageBox(hwnd, _T("Dialog exited with IDOK"), _T("Gen"), 
                            MB_OK | MB_ICONINFORMATION);
                    else if (ret == IDCANCEL)
                        MessageBox(hwnd, _T("Dialog exited with IDCANCEL"), _T("Gen"), 
                            MB_OK | MB_ICONINFORMATION);
                    else if (ret == -1)
                        MessageBox(hwnd, GenErrorMessage(GetLastError()), _T("Error"), 
                            MB_OK | MB_ICONINFORMATION);
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
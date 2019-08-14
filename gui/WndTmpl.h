/*
 *  WndTmpl.h
 */

#ifndef WND_TMPL_H
# define WND_TMPL_H

# define FASTCALL   __fastcall
# define CLASS_NAME _T("WindowTemplate")

__declspec(dllexport) int FASTCALL _tMinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                LPTSTR pszCmdLine, int iShowCmd);

/* __declspec(dllexport) 
BOOL WINAPI DllMain(HINSTANCE hinstDll, DWORD dwReason, LPVOID lpvReserved);*/

HWND FASTCALL       GenerateWindow(
                        HINSTANCE hInstance,
                        LRESULT (*WndProc)(HWND, UINT, WPARAM, LPARAM),
                        TCHAR   pszClassName);

LRESULT CALLBACK    WndProc(HWND hwnd, UINT uMsg, 
                        WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK       AboutDlgProc(HWND hwnd, UINT uMsg,
                        WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK       ToolDlgProc(HWND hwnd, UINT uMsg,
                        WPARAM wParam, LPARAM lParam);                        

int                 RegisterWindow(
                        WNDCLASSEX *wc,
                        HINSTANCE hInstance,
                        TCHAR   pszClassName,
                        LRESULT (*WndProc)(HWND, UINT, WPARAM, LPARAM));

HWND FASTCALL       GenWindow(HINSTANCE hInstance, TCHAR pszClassName);

LPTSTR              GenErrorMessage(DWORD dwErrId);

#endif
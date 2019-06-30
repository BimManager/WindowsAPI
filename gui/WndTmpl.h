/*
 *  WndTmpl.h
 */

#ifndef WND_TMPL_H
# define WND_TMPL_H

# define CLASS_NAME _T("WindowTemplate")

HWND FASTCALL       GenerateWindow(
                        HINSTANCE hInstance,
                        LRESULT (*WndProc)(HWND, UINT, WPARAM, LPARAM),
                        TCHAR   pszClassName);

LRESULT CALLBACK    WndProc(HWND hwnd, UINT uMsg, 
                            WPARAM wParam, LPARAM lParam);

int                 RegisterWindow(
                        WNDCLASSEX *wc,
                        HINSTANCE hInstance,
                        TCHAR   pszClassName,
                        LRESULT (*WndProc)(HWND, UINT, WPARAM, LPARAM));
HWND FASTCALL       GenWindow(HINSTANCE hInstance, TCHAR pszClassName);

LPTSTR              GenErrorMessage(DWORD dwErrId);


#endif
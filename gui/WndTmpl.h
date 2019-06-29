/*
 *  WndTmpl.h
 */

#pragma once

#ifndef WND_TMPL_H
# define WND_TMPL_H

# define CLASS_NAME _T("WindowTemplate")

HWND FASTCALL       GenerateWindow(
                        HINSTANCE hInstance,
                        LRESULT (*WndProc)(HWND, UINT, WPARAM, LPARAM),
                        TCHAR   pszClassName);

LRESULT CALLBACK    WndProc(HWND hwnd, UINT uMsg, 
                            WPARAM wParam, LPARAM lParam);

#endif
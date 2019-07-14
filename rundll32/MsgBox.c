/*#if 0
    MsgBox.c
#endif*/

#include "stdafx.h"

/* BOOL DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) */
#ifdef __cplusplus
extern "C" {
#endif    
    __declspec(dllexport)
    void CALLBACK
    MsgBox(HWND hwnd, HINSTANCE hinst, LPSTR lpszCmdLine, int nCmdShow)
    {
        MessageBox(NULL, _T("Test"), _T("Test"), MB_OK);
    }
#ifdef __cplusplis
 } /* extern "C" */
 #endif
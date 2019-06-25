/*
 *  ReportError.c
 */

#include "stdafx.h"

VOID    ReportError(LPCTSTR pszUserMessage, DWORD dwExitCode, BOOL fPrintErrorMessage)
{
    DWORD   dwMsgLen;    
    DWORD   dwErrId;
    LPTSTR  pszBuffer;

    _ftprintf(stderr, _T("%s\n"), pszUserMessage);
    if (fPrintErrorMessage)
    {
        dwErrId = GetLastError();
        dwMsgLen = FormatMessage(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
            NULL, dwErrId, 0, (LPTSTR)&pszBuffer, 0, NULL);
        if (dwMsgLen > 0)            
            _ftprintf(stderr, _T("%s\n"), pszBuffer);
        else
            _ftprintf(stderr, _T("Last error number: %d.\n"), dwErrId);
        if (pszBuffer != NULL)                
            LocalFree(pszBuffer);
    }
    if (dwExitCode > 0)
        ExitProcess(dwExitCode);
}

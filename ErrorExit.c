/*
 *	ErrorExit.c
 */

#include "stdafx.h"

VOID	ErrorExit(LPTSTR pszFuncName)
{
	LPVOID	pvMsgBuffer;
	LPVOID	pvDisplayBuffer;
	DWORD	dwErrorId;

	dwErrorId = GetLastError();
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, dwErrorId,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&pvMsgBuffer, 0, NULL);
	
	pvDisplayBuffer = (LPVOID)HeapAlloc(GetProcessHeap(),
		HEAP_ZERO_MEMORY,  
		(lstrlen((LPCTSTR)pvMsgBuffer) + 
		lstrlen((LPCTSTR)pszFuncName) + 40) * sizeof(TCHAR));
	if(pvDisplayBuffer) 
	{
		StringCchPrintf(
			(LPTSTR)pvDisplayBuffer, 
			LocalSize(pvDisplayBuffer) / sizeof(TCHAR),
			_T("%s failed with error %d: %s"),
			pszFuncName, dwErrorId, pvMsgBuffer);
		MessageBox(NULL, (LPCTSTR)pvDisplayBuffer, NULL, MB_OK);
		HeapFree(GetProcessHeap(), 0, pvDisplayBuffer);
	}
	HeapFree(GetProcessHeap(), 0, pvMsgBuffer);
	ExitProcess(dwErrorId);
}

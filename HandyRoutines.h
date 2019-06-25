/*
 *  HandyRoutines.h
 */

#ifndef HANDY_ROUTINES_H
# define HANDY_ROUTINES_H

VOID    ReportError(LPCTSTR pszUserMessage, DWORD dwExitCode, BOOL fPrintErrorMessage);
VOID    EmptyBin();
VOID	ErrorExit(LPTSTR lpszFunction);

#endif

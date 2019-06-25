@echo off
set SRCS=main.c ReportError.c ErrorExit.c EmptyBin.c

if "%1"=="" goto compile
if "%1"=="fclean" goto fclean
 
:compile
cl /Zi %SRCS% /Fe:a.exe /link User32.lib Shell32.lib Kernel32.lib
goto:eof

:fclean
del /q /f *.exe *.ilk *.obj *.pdb 
goto:eof



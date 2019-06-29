@echo off
set SRCS=main.c ReportError.c ErrorExit.c EmptyBin.c
set LIBS=kernel32.lib user32.lib shell32.lib

if "%1"=="" goto compile
if "%1"=="fclean" goto fclean
 
:compile
cl /I..\ /Zi %SRCS% /Fe:a.exe /link %LIBS%
goto:eof

:fclean
del /q /f *.exe *.ilk *.obj *.pdb 
goto:eof



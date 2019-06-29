@echo off

set SRCS=WinMain.c WndTmpl.c
set LIBS=kernel32.lib user32.lib gdi32.lib
set NAME=a.exe

if "%1"=="" goto _compile
if "%1"=="clean" goto _clean
if "%1"=="fclean" goto _fclean

:_compile
cl /Zi /I..\ %SRCS% %LIBS% /showIncludes /Fe:%NAME%
goto:eof

:_clean
del *.ilk *.pdb *.obj
goto:eof

:_fclean
del *.ilk *.pdb *.obj %NAME%
goto:eof

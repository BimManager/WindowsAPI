@echo off
set file=vcvars64.bat
set PATH=%PATH%;%ProgramFiles%\Autodesk\Revit 2020
set PATH=%PATH%;%UserProfile%\emacs\bin
set PATH=%PATH%;%ProgramFiles(x86)%\google\chrome\application
title dev
call "%UserProfile%\tmp\winapi\cmd\aliases.bat"
echo Looking for %file%
for /f "tokens=*" %%a in ('dir/s/b "C:\Program Files (x86)\%file%"') do "%%a"

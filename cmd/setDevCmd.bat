@echo off
set file=vcvars64.bat
set PATH=%PATH%;%ProgramFiles%\Autodesk\Revit 2020
echo Looking for %file%
for /f "tokens=*" %%a in ('dir/s/b "C:\Program Files (x86)\%file%"') do "%%a"
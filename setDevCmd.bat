@echo off
set file=vcvars64.bat
echo Looking for %file%
for /f "tokens=*" %%a in ('dir/s/b "C:\Program Files (x86)\%file%"') do "%%a" 

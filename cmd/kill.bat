@echo off
if "%1"=="" goto usage
:: for /f "tokens=2 skip=3" %%a in ('tasklist /fi "imagename eq %1"') do taskkill /pid %%a 
taskkill /f /im %1
goto:eof
:usage
echo usage: kill imagename
goto:eof
:: utils.bat
@echo off
if "%1"=="killrvt" goto kill_rvt:
goto:usage

:kill_rvt
taskkill /f /fi "imagename eq revit.exe"
goto:eof

:usage
echo usage: utils ^{killrvt ^|^}

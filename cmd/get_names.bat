:: get_names
@echo off
if "%1"=="" (
    goto usage
)
if "%2"=="" (
    goto usage
)
chcp 65001
for /f "tokens=*" %%a in ('forfiles /s /p %1 /c "cmd /c echo @fname"') do echo %%~a >> %2 
goto:eof

:usage
    echo get_names path outfile 
    echo Example: get_names c:\users c:\users\public\output.txt
goto:eof    

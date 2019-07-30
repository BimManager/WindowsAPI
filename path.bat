@echo off

set Path=^
%WINDIR%\system32;^
%WINDIR%;^
%WINDIR%\System32\Wbem;^
%WINDIR%\System32\WindowsPowerShell\v1.0\;^
%WINDIR%\System32\OpenSSH\;^
%USERPROFILE%\AppData\Local\Microsoft\WindowsApps;^
%USERPROFILE%\AppData\Local\Programs\Microsoft VS Code\bin;^
%PROGRAMFILES%\Autodesk\Revit 2019;^
X:\kkozlov\7-Zip;^
%PROGRAMFILES(x86)%\Microsoft SDKs\Windows\v10.0A\bin\NETFX 4.7.2 Tools\x64;^
%PROGRAMFILES%\Microsoft Office\root\Office16;^
%PROGRAMFILES(x86)%\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\TeamFoundation\Team Explorer\Git\cmd;^
%PROGRAMFILES(x86)%\Windows Kits\10\Debuggers\x64;^
%PROGRAMFILES%\Autodesk\Navisworks Manage 2019;^
%PROGRAMFILES(x86)%\Microsoft SDKs\Windows\v10.0A\bin\NETFX 4.6.1 Tools;^
%PROGRAMFILES(x86)%\Microsoft Visual Studio\2019\Community\MSBuild\Microsoft\VisualStudio\NodeJs\win-x64;^
%PROGRAMFILES(x86)%\Google\Chrome\Application;^
%USERPROFILE%\AppData\Local\Programs\Python\Python37;^
%USERPROFILE%\AppData\Local\Programs\Python\Python37\Scripts

doskey ls=dir/b $1
doskey cat=type $1
doskey gs=git status
doskey gc= git commit -m $1

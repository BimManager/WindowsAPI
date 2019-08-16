# Set-ExecutionPolicy -Scope CurrentUser RemoteSigned
Add-Type -Path "$env:ProgramFiles\Autodesk\Revit 2019\RevitAPI.dll"
Add-Type -Path "$env:ProgramFiles\Autodesk\Revit 2019\RevitAPIUI.dll"
Add-Type -Path "$env:ProgramFiles\Autodesk\Revit 2019\RevitAPIIFC.dll"
$global:db = [AppDomain]::CurrentDomain.GetAssemblies() | where {$_.FullName -like "*RevitAPI*"} | select -First 1
$global:ui = [AppDomain]::CurrentDomain.GetAssemblies() | where {$_.FullName -like "*RevitAPIUI*"} | select -First 1
$global:ifc = [AppDomain]::CurrentDomain.GetAssemblies() | where {$_.FullName -like "*RevitAPIIFC*"} | select -First 1

$global:res = $null
function Add($a, $b)
{
    $a + $b
}
$global:res = Add 1 2
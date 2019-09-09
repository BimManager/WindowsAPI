# Set-ExecutionPolicy -Scope CurrentUser RemoteSigned
$netAsmbs = "${env:ProgramFiles(x86)}\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.6\"

Add-Type -Path "$env:ProgramFiles\Autodesk\Revit 2020\RevitAPI.dll"
Add-Type -Path "$env:ProgramFiles\Autodesk\Revit 2020\RevitAPIUI.dll"
Add-Type -Path "$env:ProgramFiles\Autodesk\Revit 2020\RevitAPIIFC.dll"

Add-Type -Path $netAsmbs\System.Windows.Forms.dll

$global:db = [AppDomain]::CurrentDomain.GetAssemblies() | where {$_.FullName -like "*RevitAPI*"} | select -First 1
$global:ui = [AppDomain]::CurrentDomain.GetAssemblies() | where {$_.FullName -like "*RevitAPIUI*"} | select -First 1
$global:ifc = [AppDomain]::CurrentDomain.GetAssemblies() | where {$_.FullName -like "*RevitAPIIFC*"} | select -First 1
$global:forms = [AppDomain]::CurrentDomain.GetAssemblies() | where {$_.FullName -like "*Forms*"} | select -First 1

$global:res = $null
function Add($a, $b)
{
    $a + $b
}
$global:res = Add 1 2
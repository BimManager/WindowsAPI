; # Win
; ! Alt
; ^ Control
; + Shift
; & to combine two keys
; ~ to preserve the origin shortcut

^m::
Send, {enter}
return

$^w::
if WinActive("ahk_exe kali.exe")
    Send ^w
else
    Send ^{backspace}
return

^a::
Send, {home}
return

!b::
Send, ^{left}
return

^b::
Send, {left}
return

^e::
Send, {end}
return

^p::
Send, {up}
return

^n::
Send, {down}
return

^u::
Send, ^{home}
return

^d::
Send, {delete}
return


$^h::
if WinActive("ahk_exe kali.exe")
    Send, ^h
else
    Send, {backspace}
return

$^k::
if WinActive("ahk_exe kali.exe")
    Send, ^k
else
    Send, ^{end}
return

^f::
Send, {right}
return

!f::
Send, ^{right}
return

$~^L::
if WinActive("ahk_exe kali.exe")
    Send ^l
else 
    Send, cls ^m
return 

$!d::
if WinActive("ahk_exe kali.exe")
    Send, !d
else 
{
    Send, ^{right}
    Send, ^{backspace}
}
return

::kk::kkozlov
; # Win
; ! Alt
; ^ Control
; + Shift
; & to combine two keys
; ~ to preserve the origin shortcut

$^m::
if WinActive("ahk_exe kali.exe") || WinActive("ahk_exe emacs.exe")
   Send ^m
else
   Send, {enter}
return

$^w::
if (WinActive("ahk_exe kali.exe") || WinActive("ahk_exe emacs.exe"))
    Send, ^w
else
    Send ^{backspace}
return

$^a::
if (WinActive("ahk_exe kali.exe") || WinActive("ahk_exe emacs.exe"))
   Send, ^a
else
   Send, {home}
return

$!b::
if (WinActive("ahk_exe kali.exe") || WinActive("ahk_exe emacs.exe"))
   Send, !b
else
   Send, ^{left}
return

$^b::
if (WinActive("ahk_exe kali.exe") || WinActive("ahk_exe emacs.exe"))
   Send, ^b
else
   Send, {left}
return

$^e::
if (WinActive("ahk_exe kali.exe") || WinActive("ahk_exe emacs.exe"))
   Send, ^e
else
   Send, {end}
return

$^p::
if (WinActive("ahk_exe kali.exe") || WinActive("ahk_exe emacs.exe"))
   Send, ^p
else
   Send, {up}
return

$^n::
if (WinActive("ahk_exe kali.exe") || WinActive("ahk_exe emacs.exe"))
   Send, ^n
else
   Send, {down}
return

$^u::
if (WinActive("ahk_exe kali.exe") || WinActive("ahk_exe emacs.exe"))
   Send, ^u
else
   Send, ^{home}
return

$^d::
if (WinActive("ahk_exe kali.exe") || WinActive("ahk_exe emacs.exe"))
   Send, ^d
else
   Send, {delete}
return


$^h::
if (WinActive("ahk_exe kali.exe") || WinActive("ahk_exe emacs.exe"))
    Send, ^h
else
    Send, {backspace}
return

$^k::
if (WinActive("ahk_exe kali.exe") || WinActive("ahk_exe emacs.exe"))
    Send, ^k
else
    Send, ^{end}
return

$^f::
if (WinActive("ahk_exe kali.exe") || WinActive("ahk_exe emacs.exe"))
   Send, ^f
else
   Send, {right}
return

$!f::
if (WinActive("ahk_exe kali.exe") || WinActive("ahk_exe emacs.exe"))
   Send, !f
else
   Send, ^{right}
return

$^l::
if WinActive("ahk_exe cmd.exe")
    Send, cls {enter}
else 
     Send, ^l
return 

$!d::
if (WinActive("ahk_exe kali.exe") || WinActive("ahk_exe emacs.exe"))
    Send, !d
else
{
    Send, ^{right}
    Send, ^{backspace}
}
return

::kk::kkozlov
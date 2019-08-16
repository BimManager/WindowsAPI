@echo off

:: bash equivalents
doskey ls=dir/b $1
doskey pwd=echo %cd%
doskey cat=type $*
doskey rm=del/q $*
doskey make=nmake $1

:: git alaises
doskey gs=git status
doskey gc=git commit -m $1
doskey gp=git push
doskey ga=git add $*
doskey gcl=git clone
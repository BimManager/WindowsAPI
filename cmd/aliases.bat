@echo off

:: bash equivalents
doskey ls=dir $*
doskey pwd=echo %cd%
doskey cat=type n$*
doskey rm=del $*
doskey mv=move $*
doskey cp=copy $*
doskey make=nmake /nologo $*

:: git aliases
doskey gs=git status
doskey gc=git commit -m $1
doskey gp=git push
doskey ga=git add $*
doskey gcl=git clone
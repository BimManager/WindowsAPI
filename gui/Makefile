CC=cl.exe
LD=link.exe
RC=rc.exe

CFLAGS=/Zi /c /I..
LDFLAGS=kernel32.lib user32.lib gdi32.lib

HDRS=WndTmpl.h WndTmpl.h stdafx.h resource.h 
SRCS=WinMainClassic.c WndTmpl.c WndProc.c AboutDlgProc.c ToolDlgProc.c
OBJS=WinMainClassic.obj WndTmpl.obj WndProc.obj AboutDlgProc.obj ToolDlgProc.obj
RES=resource.rc
CRES=resource.res
NAME=a.exe

all : $(NAME)

$(NAME) : $(OBJS) $(CRES)
	$(LD) $(LDFLAGS) $(OBJS) $(CRES) /OUT:$(NAME)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS)

$(CRES)	: $(RES)
	$(RC) $(RES)

.PHONY : all clean fclean re	

clean :
	del *.obj *.pdb	

fclean : clean
	del $(NAME)

re : fclean all	




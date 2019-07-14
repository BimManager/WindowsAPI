CC = cl
CFLAGS = /c /I..
LD = link
LDFLAGS = /DLL /ENTRY:MsgBox  user32.lib

HDRS = stdafx.h
SRCS = MsgBox.c
OBJS = MsgBox.obj
NAME = a.dll

all : $(NAME)

$(NAME) : $(OBJS)
	$(LD) $(LDFLAGS) $** /OUT:$@

$(OBJS)	: $(SRCS)
	$(CC) $(CFLAGS) $**

.PHONY : all clean f clean re

clean :
	@del /f /q *.obj *.exp

fclean : clean
	@del /f /q 	$(NAME) *.lib

re : fclean all	
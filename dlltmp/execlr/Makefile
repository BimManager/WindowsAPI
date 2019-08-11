# Makefile

CC = cl.exe
CFLAGS = /clr /nologo /c /Zi /Wall
LD = link.exe
LDFLAGS = /NOLOGO /LIBPATH:"F:\\winapi\\dlls\\maths" a.lib

PREFIX = main

HDRS = $(PREFIX).h
SRCS = $(PREFIX).cpp
OBJS = $(PREFIX).obj
NAME = a.exe

all : $(NAME)

$(NAME) : $(OBJS)
	$(LD) $(LDFLAGS) $** /OUT:$@

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS)	$**

clean :
	@del/f/q *.obj *.pdb

fclean : clean
	@del/f/q $(NAME)

re : fclean all	

.PHONY : all clean fclean re
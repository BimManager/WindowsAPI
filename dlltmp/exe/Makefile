# Makefile

CC = cl.exe
CFLAGS = /nologo /c /EHs /Zi /Wall
LD = link.exe
LDFLAGS = /NOLOGO /LIBPATH:"F:\\winapi\\dlls\\maths" a.lib

PREFIX = main

HDRS = $(PREFIX).h
SRCS = $(PREFIX).c
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
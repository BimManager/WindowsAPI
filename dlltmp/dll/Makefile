# Makefile

CC = cl.exe
CFLAGS = /nologo /c /EHs /Zi /Wall
LD = link.exe
LDFLAGS = /DLL /MACHINE:x64

PREFIX = maths

HDRS = $(PREFIX).h
SRCS = $(PREFIX).c
OBJS = $(PREFIX).obj
NAME = a.dll

all : $(NAME)

$(NAME) : $(OBJS)
	$(LD) $(LDFLAGS) $** /OUT:$@

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS)	$**

clean :
	@del/f/q *.obj

fclean : clean
	@del/f/q $(NAME) *.pdb *.lib *exp

re : fclean all	

.PHONY : all clean fclean re
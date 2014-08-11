# dlopen test

CC	= gcc
RM	= rm -fr

SRC	= foo1.c foo2.c
OBJ	= $(SRC:.c=.o)
OUT	= foo1 foo2.so dlopen

CFLAGS	+= -g
CFLAGS	+= -fPIC

all:	$(SRC) $(OBJ) $(OUT)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

foo1:	foo1.o foo2.so
	$(CC) -o $@ foo1.o foo2.so

foo2.so:	foo2.o
	$(CC) -shared -o foo2.so foo2.o

clean:
	$(RM) foo[12].o
	$(RM) foo2.so
	$(RM) foo1 dlopen

dlopen:	dlopen.c
	$(CC) -o $@ dlopen.c -ldl

run:	foo1 dlopen foo2.so
	LD_LIBRARY_PATH=. foo1
	LD_LIBRARY_PATH=. dlopen foo2.so


# dlopen test

CC	= g++
RM	= rm -fr

SRC	= foo1.cpp foo2.cpp
OBJ	= $(SRC:.cpp=.o)
OUT	= foo1 foo2.so dlopen

CFLAGS	+= -std=c++11
CFLAGS	+= -g
CFLAGS	+= -fPIC

all:	$(SRC) $(OBJ) $(OUT)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

foo1:	foo1.o foo2.so
	$(CC) -o $@ foo1.o foo2.so

foo2.so:	foo2.o
	$(CC) -shared -o foo2.so foo2.o

clean:
	$(RM) foo[12].o
	$(RM) foo2.so
	$(RM) foo1 dlopen

dlopen:	dlopen.cpp
	$(CC) -o $@ dlopen.cpp -ldl

run:	foo1 dlopen foo2.so
	LD_LIBRARY_PATH=. foo1
	LD_LIBRARY_PATH=. dlopen foo2.so


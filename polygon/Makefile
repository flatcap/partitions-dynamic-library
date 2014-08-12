CC	= g++
RM	= rm -fr

SRC	= triangle.cpp
OBJ	= $(SRC:.cpp=.o)
OUT	= triangle.so main

CFLAGS	+= -std=c++11
CFLAGS	+= -g
CFLAGS	+= -fPIC

all:	$(SRC) $(OBJ) $(OUT)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

triangle.so:	triangle.o
	$(CC) $(CFLAGS) -shared -o triangle.so triangle.o

clean:
	$(RM) triangle.o triangle.so
	$(RM) main

main:	main.cpp
	$(CC) $(CFLAGS) -o $@ main.cpp -ldl


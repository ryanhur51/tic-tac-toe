CC=g++
CFLAGS=-g -c -Wall -Wextra -Wwrite-strings
LFLAGS=-g

main: main.o Board.o
	${CC} ${LFLAGS} -o main main.o Board.o
main.o: main.cpp
	${CC} ${CFLAGS} main.cpp
Board.o: Board.cpp Board.h
	${CC} ${CFLAGS} Board.cpp
clean:
	rm -f *.o main
	rm -f main
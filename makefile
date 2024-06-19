CC=g++
CFLAGS=-g -c -Wall -Wextra -Wwrite-strings
LFLAGS=-g

SRC_DIR=src
INC_DIR=include

main: main.o Board.o
	${CC} ${LFLAGS} -o main main.o Board.o

main.o: ${SRC_DIR}/main.cpp ${INC_DIR}/main.h
	${CC} ${CFLAGS} -o main.o ${SRC_DIR}/main.cpp

Board.o: ${SRC_DIR}/Board.cpp ${INC_DIR}/Board.h
	${CC} ${CFLAGS} -o Board.o ${SRC_DIR}/Board.cpp

clean:
	rm -f *.o main
	rm -f main

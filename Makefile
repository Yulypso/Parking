all: PROJECT EXEC CLEAR

PROJECT: ncurses.o decoration.o main.o 
	gcc -o PROJET ncurses.o decoration.o main.o -lncurses

main.o: main.c main.h
	gcc -Wall -o main.o -c main.c -lncurses

ncurses.o: ncurses.c main.h
	gcc -Wall -o ncurses.o -c ncurses.c -lncurses

decoration.o : decoration.c main.h
	gcc -Wall -o decoration.o -c decoration.c -lncurses

EXEC : 
	./PROJET

CLEAR : 
	rm -f a
	rm -f *.o core

all: txtfind isort

clean:
	rm -f *.o isort txtfind

.PHONEY: all clean

isort.o: isort.c isort.h
	gcc -Wall -c isort.c -o isort.o

isort: isort.o
	gcc isort.o -o isort

txtfind.o: txtfind.c txtfind.h
	gcc -Wall -c txtfind.c -o txtfind.o

txtfind: txtfind.o
	gcc txtfind.o -o txtfind

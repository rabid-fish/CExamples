all: example

example: main.o example1.o example2.o
	gcc main.o example1.o example2.o -o example

main.o: main.c
	gcc -c main.c

example1.o: example1.c
	gcc -c example1.c

example2.o: example2.c
	gcc -c example2.c

clean:
	rm -rf *o example

CFLAGS=-Wall -g -std=c99
CC=clang

all: ex1 ex3 ex4 ex5 ex6 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16 ex17 ex18 ex19 ex20

clean:
	rm -f ex1 ex3 ex4 ex5 ex6 ex7 ex8 ex9 ex10
	rm -f ex11 ex12 ex13 ex14 ex15 ex16 ex17 ex18 ex19 ex20
	rm -f object.o

ex19: object.o

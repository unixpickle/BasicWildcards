wildcard_test: BasicWildcards.o main.c
	gcc BasicWildcards.o main.c -o wildcard_test
	rm BasicWildcards.o

BasicWildcards.o: BasicWildcards.c BasicWildcards.h
	gcc -c BasicWildcards.c -o BasicWildcards.o

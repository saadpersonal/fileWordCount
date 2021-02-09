all:
	gcc -Wall -o count count.c
	./count string.txt

all: run

run: main
	./main

main: main.o
	gcc -o main *.o

main.o: main.c list_io.c higher_ord_func.c linked_list.c clean
	gcc -pedantic-errors -Wall -Werror -c *.c

clean:
	rm -f *.o main saved.bin saved.txt

CC = gcc
OUTPUT = build/main
SRC = ./
OBJ = obj/
LIBS = -lm
LFOLD= -L./lib/

all: main.o bmp.o librotation.so
	$(CC) -rdynamic -o $(OUTPUT) $(OBJ)main.o $(OBJ)bmp.o $(LIBS) -ldl

main.o: ./main.c
	$(CC) -o $(OBJ)main.o -c $(SRC)main.c

bmp.o: ./bmp.c
	$(CC) -o $(OBJ)bmp.o -c $(SRC)bmp.c

librotation.so: rotation.o
	$(CC) -shared -o lib/librotation.so obj/rotation.o -lm

rotation.o: ./rotation.c
	$(CC) -o $(OBJ)rotation.o -c $(SRC)rotation.c $(LIBS)

clean:
	rm obj/* build/*

rotation: all
	build/main -t rotation -p res/arrow.bmp -o res/out.bmp -a 45

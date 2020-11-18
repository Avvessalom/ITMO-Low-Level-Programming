CC = cc
SRC = lab6.c bmp_io.c bmp_rotation.c 
OUT = lab6.o
PIC1 = arrow.bmp
PIC2 = 3_3.bmp
all:
	$(CC) $(SRC) -o $(OUT)
start1:
	./$(OUT) $(PIC1)
start2:
	./$(OUT) $(PIC2)
clean:
	rm -rf $(OUT) out.bmp
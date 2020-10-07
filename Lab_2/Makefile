NASM = nasm -f elf64
DICT = dict.asm
LIB = lib.asm
MAIN = main.asm
SRCS = $(DICT) $(LIB) $(MAIN)
OBJ = $(SRCS:.asm=.o)
NAME = lab2

all: build

objects: $(SRCS)
	$(NASM) $(DICT) -o $(DICT:.asm=.o)
	$(NASM) $(LIB) -o $(LIB:.asm=.o)
	$(NASM) $(MAIN) -o $(MAIN:.asm=.o)

build: objects $(OBJ)
	ld -o $(NAME) $(OBJ)
	rm $(OBJ)


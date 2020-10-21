SRC1 = lab3_part1.c 
SRC2 = lab3_part2.c
SRC_TEST = test.c
CC = cc
OUTPUT1 = lab_part1 
OUTPUT2 = lab_part2
OUTPUT_TEST = test
CRITERION = -lcriterion

part1:
	$(CC) -o $(OUTPUT1) $(SRC1)

part2:
	$(CC) -o $(OUTPUT2) $(SRC2)

clear:
	rm -rf lab_part1 lab_part2 *.out test

test:
	$(CC) -o $(OUTPUT_TEST) $(SRC_TEST) $(CRITERION)
	./test
	rm -rf test
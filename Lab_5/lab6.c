#include <stdio.h>
#include <stdlib.h>

#include "bmp_io.h"

int main(int argc, char **argv) {
    if (argc != 2 && argc != 3){
        puts("[input] [output]");
        return 1;
    }

    const char *input = argv[1];
    const char *output;

    if (argc == 2){
        output = "out.bmp";
    } else {
        output = argv[2];
    }

    struct img *input_img = (struct img *) malloc(sizeof(struct img));
    switch (read_bmp(input, input_img)){
    case READ_OK:
        puts("Image is OK.");
        break;
    case READ_FILENAME_NOT_FOUND:
        puts("Filename not found.");
    case READ_FILE_ERROR:
        puts("Unable to open input file");
        return 1;
    case READ_INVALID_BITS:
        puts("Inalid input data");
        return 1;
    case READ_INVALID_HEADER:
        puts("Input file is not a bmp");
        return 1;
    default:
        puts("Undefined reading error");
        return 1;
    }

    struct img *output_img = input_img; //-----------------------------------------------
    write_bmp(output, output_img);
}
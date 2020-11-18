#include <stdio.h>
#include <stdlib.h>

#include "bmp_io.h"
#include "bmp_rotation.h"

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

    struct img *output_img = rotate(input_img); //-----------------------------------------------
    switch (write_bmp(output, output_img)){
        case WRITE_OK: 
            puts("Image is saved");
            return 0;
        case WRITE_FILENAME_NOT_FOUND:
            puts("Output file name is not specified");
            return 1;
        case WRITE_IMAGE_NOT_FOUND: 
            puts("Output image is null.");
            return 1;
        case WRITE_FILE_ERROR: 
            puts("Unable to open output file.");
            return 1;
        default: 
            puts("Undefined writing error.");
            return 1;
    }
}
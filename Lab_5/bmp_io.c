#include <stdlib.h>
#include <stdio.h>
#include "bmp_io.h"

struct bmp_header *create_header(struct img const *pic, int padding){
    struct bmp_header *header = (struct bmp_header *) malloc(sizeof(struct bmp_header));

    //BITMAPFILEHEADER
    header->bfType = 19778; // 4D42 (little-endian)
    header->bfSize = pic->width * pic->height * sizeof(struct pixel) + pic->height * padding + sizeof(struct bmp_header);
    header->bfReserved = 0;
    header->bfOffBits = sizeof(struct bmp_header);

    //BITMAPINFO
    header->biSize = 40;
    header->biWidth = pic->width;
    header->biHeight = pic->height;
    header->biPlanes = 1;
    header->biBitCount = 24;
    header->biCompression = 0;
    header->biSizeImage = header->bfSize - header->bfOffBits;
    header->biXPelsPerMeter = 0;
    header->biYPelsPerMeter = 0;
    header->biClrUsed = 0;
    header->biClrImportant = 0;
    return header;
};


enum read_error read_bmp(char const *filename, struct img* in_bmp){
    if (filename == NULL){
        return READ_FILENAME_NOT_FOUND;
    }
    
    FILE *file = fopen(filename, "rb");
    
    if (file == NULL){
        return READ_FILE_ERROR;
    }

    struct bmp_header header;

    fread(&header, 1, sizeof(header), file);
    if (header.bfType == 0){
        return READ_INVALID_HEADER;
    }

    uint8_t *data = (uint8_t *) malloc(header.biSizeImage);
    fseek(file, header.bfOffBits, SEEK_SET);
    fread(data, 1, header.biSizeImage, file);

    if (data == NULL){
        return READ_INVALID_BITS;
    }
    if (in_bmp == NULL){
        in_bmp = (struct img *) malloc(sizeof(struct img));
    }

    in_bmp->data = (struct pixel *) malloc(header.biHeight * header.biWidth * sizeof(struct pixel));
    in_bmp->height = header.biHeight;
    in_bmp->width = header.biWidth;
    int padding = header.biWidth %4;

    for (int row = 0; row < header.biHeight; row++){
        for (int col = 0; col < header.biWidth; col++){
            in_bmp->data[row * header.biWidth + col] = *(struct pixel *) ((data) + sizeof(struct pixel) * (row * header.biWidth + col) + padding * row);
        }
    }
    fclose(file);
    return READ_OK;    
}

enum write_error write_bmp(char const *filename, struct img const* out_bmp){
    if (filename == NULL){
        return WRITE_FILENAME_NOT_FOUND;
    }
    if (out_bmp == NULL){
        return WRITE_IMAGE_NOT_FOUND;
    }

    int padding = out_bmp->width % 4;
    struct bmp_header *header = create_header(out_bmp, padding);

    uint64_t data_size = (out_bmp->width + padding) * out_bmp->height * sizeof(struct pixel);
    uint8_t *data = (uint8_t *) calloc(1, data_size);

    for (int row = 0; row < out_bmp->height; row++){
        for (int col = 0; col < out_bmp->width; col++){
            uint64_t pixel_i = row * out_bmp->width + col;
            *((struct pixel *) (data + sizeof(struct pixel) *pixel_i + row * padding)) = out_bmp->data[pixel_i];
        }
    }

    FILE *file = fopen(filename, "wb");
    if (file == NULL){
        return WRITE_FILE_ERROR;
    }

    fwrite(header, 1, sizeof(struct bmp_header), file);
    fwrite(data, 1, (out_bmp->width + padding) * out_bmp->height * sizeof(struct pixel), file);
    fclose(file);
    return WRITE_OK;
}
#ifndef BMP_IO_H
#define BMP_IO_H

#include <stdint.h>

struct pixel{
    unsigned char r, g, b;
};


struct img{
    uint32_t width, height;
    struct pixel *data;
};

struct __attribute__((packed)) bmp_header {
    //BITMAPFILEHEADER
    uint16_t bfType;
    uint32_t bfSize;
    uint32_t bfReserved;
    uint32_t bfOffBits;

    //BITMAPINFO
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};


enum read_error{
    READ_OK = 0,
    READ_FILENAME_NOT_FOUND,
    READ_FILE_ERROR,
    READ_INVALID_BITS,
    READ_INVALID_HEADER,
};

enum write_error{
    WRITE_OK = 0,
    WRITE_FILE_ERROR,
    WRITE_IMAGE_NOT_FOUND,
    WRITE_FILENAME_NOT_FOUND,
};

enum read_error read_bmp(char const *filename, struct img *in_bmp);
enum write_error write_bmp(char const *filename, struct img const* img);
#endif // !BMP_IO_H

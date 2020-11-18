#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bmp_rotation.h"
#include "bmp_io.h"

struct img *rotate(struct img const *pic){
    struct img *rotated_pic = (struct img *) malloc(sizeof(struct img));
    rotated_pic->width = pic->width;
    rotated_pic->height = pic->height;
    rotated_pic->data = (struct pixel *) malloc(pic->height * pic->width * sizeof(struct pixel));

    for (int row = 0; row < pic->height; row++){
        for (int col = 0; col < pic->width; col++){
            rotated_pic->data[((rotated_pic->height - col -1) * rotated_pic->width) + row] = pic->data[row * pic->width + col];
        }
    }
    return rotated_pic;
}
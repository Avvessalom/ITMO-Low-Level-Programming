#ifndef LAB7_ALLOCATION_H
#define LAB7_ALLOCATION_H

#include <stdbool.h>
#include <stddef.h>
#include <sys/mman.h>


#define CHUNK 5*1024*1024
#define HEAP_START ((void *)0x04040000)
#define MAP_ANONYMOUS	0x20

struct mem{
    struct mem * next;
    size_t capacity;
    bool is_free;
};

void *heap_init(size_t init_size);

void *_malloc(size_t query);

void _free(void *p);

void * find_last();

void align_mem();

#endif
#include <stdbool.h>
#include <stdio.h>
#include "allocation.h"
#include <sys/mman.h>
#include <sys/types.h>

static void *start;

void *heap_init(size_t init_size) {
    void *mem_pointer = mmap(HEAP_START, init_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (!start) {
        start = mem_pointer;
    }
    struct mem *head;
    head = (struct mem *) mem_pointer;
    head->next = NULL;
    head->capacity = init_size - sizeof(struct mem);
    head->is_free = true;
    return mem_pointer;
}

void *_malloc(size_t query) {
    struct mem *pointer;
    if (start) {
        struct mem *tmp = find_last();

        pointer = heap_init(query + sizeof(struct mem) > CHUNK ? query + sizeof(struct mem) : CHUNK);
        tmp->next = pointer;

        pointer->is_free = 0;
        pointer->next = NULL;
        pointer->capacity = query;
        return pointer + sizeof(struct mem);
    }
    pointer = heap_init(query + sizeof(struct mem) > CHUNK ? query + sizeof(struct mem) : CHUNK);
    pointer->is_free = 0;
    return pointer + sizeof(struct mem);
}


void _free(void *p) {
    struct mem *delete = (struct mem *) p;
    delete->is_free = 1;
    align_mem();
}


void *find_last() {
    struct mem *head = (struct mem *) start;
    while (head->next) {
        head = head->next;
    }
    return head;
}

void align_mem() {
    struct mem *head = (struct mem *) start;
    while (head->is_free && head->next->is_free && head + head->capacity + sizeof(struct mem) == head->next) {
        head->capacity = head->capacity + sizeof(struct mem) + head->next->capacity;
        head->next = head->next->next;
    }
    head = head->next;
}
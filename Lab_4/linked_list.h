#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>

typedef int value;

struct Node {
    struct Node* next_elem;
    value node_value;
};

typedef struct Node* linked_list;

linked_list list_create(value new_value);

linked_list list_add_front(value new_value, const linked_list list);
linked_list list_add_back(value new_value, const linked_list list);

void list_free(const linked_list list);

size_t list_length(const linked_list list);

value list_sum(const linked_list list);

linked_list list_node_at(size_t pos, const linked_list list);
value list_get(size_t pos, const linked_list list);

void print_list(const linked_list);

#endif

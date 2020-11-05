#include "stdlib.h"
#include "stdio.h"

#include "linked_list.h"
#include "higher_ord_func.h"

linked_list list_create(value new_value) {
    linked_list node_p = malloc(sizeof(struct Node));
    node_p->node_value = new_value;
    node_p->next_elem = NULL;
    
    return node_p;
}

void list_free(const linked_list list) {
    linked_list next_node = list;
    
    while (next_node != NULL) {
        linked_list prev_node = next_node;
        next_node = next_node->next_elem;
        free(prev_node);
    }
}

linked_list list_add_front(value new_value, const linked_list list) {
    linked_list new_node = list_create(new_value);
    new_node->next_elem = list;
    
    return new_node;
}

linked_list list_add_back(value new_value, const linked_list list) {
    linked_list next_node = list;
    while(next_node->next_elem != NULL) {
        next_node = next_node->next_elem;
    }
    
    linked_list new_node = list_create(new_value);
    next_node->next_elem = new_node;
    
    return list;
}

linked_list list_node_at(size_t pos, const linked_list list) {
    linked_list next_node = list;
    
    if (pos < 0) return NULL;
    else {
        size_t iter;
        for (iter = 0; iter < pos; iter++) {
            if (next_node->next_elem == NULL) break;
            else next_node = next_node->next_elem;
        }
        if (iter != pos) return NULL;
        else return next_node;
    }
}

value list_get(size_t pos, const linked_list list){
    linked_list desired_node = list_node_at(pos, list);
    if (desired_node == NULL) return -1;
    else return desired_node->node_value;
}


static void print_elem(value v) {
    printf("%d ", v);
}

void print_list(const linked_list list) {
    foreach(list, &print_elem);
    puts("");
}


static value sum(value a, value b){
    return a + b;
}

value list_sum(const linked_list list) {
    return fold_l(list, 0, &sum);
}

size_t list_length(const linked_list list) {
    linked_list next_node = list;
    
    size_t len = 0;
    while (next_node != NULL) {
        len += 1;
        next_node = next_node->next_elem;
    }
    
    return len;
}


#include "stdlib.h"
#include "higher_ord_func.h"

void foreach(const linked_list list, void(*func)(value)) {
    linked_list next_node = list;
    while (next_node != NULL) {
        func(next_node->node_value);
        next_node = next_node->next_elem;
    }
}

linked_list map(const linked_list list, value(*op)(value)) {
    if (list != NULL) {
        linked_list next_node = list;
        linked_list new_node = list_create(op(next_node->node_value));
        linked_list new_list = new_node;
        
        next_node = next_node->next_elem;
        while (next_node->next_elem != NULL) {
            new_node = list_add_back(op(next_node->node_value), new_node)->next_elem;
            next_node = next_node->next_elem;
        }; list_add_back(op(next_node->node_value), new_node);

        return new_list;
    } else {
        return NULL;
    }
}

void map_mut(const linked_list list, value(*op)(value)) {
    linked_list next_node = list;
    while (next_node != NULL) {
        next_node->node_value = op(next_node->node_value);
        next_node = next_node->next_elem;
    };
}

value fold_l(const linked_list list, value acc, value(*op)(value, value)) {
    linked_list next_node = list;
    while (next_node != NULL) {
        acc = op(acc, next_node->node_value);
        next_node = next_node->next_elem;
    }
    
    return acc;
}

linked_list unfold_l(value init, size_t length, value(*op)(value)) {
    linked_list new_list = list_create(init);
    linked_list new_node = new_list;
    
    size_t iter;
    for (iter = 1; iter < length; iter++) {
        init = op(init);
        new_node = list_add_back(init, new_node)->next_elem;
    }
    
    return new_list;
}

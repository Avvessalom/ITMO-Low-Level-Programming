#include <stdio.h>
#include <errno.h>

#include "list_io.h"

static int check_file(FILE* file) {
    if (errno || ferror(file)) {
        fclose(file);
        return 0;
    } else return 1;
}

static int close_file(FILE* file) {
    fclose(file);
    if (errno) return 0;
    else return 1;
}

static FILE* open_file(const char* filename, const char* mode) {
    errno = 0;
    FILE* file = fopen(filename, mode);
    if (errno) return NULL;
    else return file;
}

int save(linked_list list, const char* filename) {
    FILE* file = open_file(filename, "w");
    if (file == NULL) return 0;
    
    linked_list next_node = list;
    while (next_node != NULL) {
        fprintf(file, "%d ", next_node->node_value);
        if (!check_file(file)) return 0;
        next_node = next_node->next_elem;
    }
    
    return close_file(file);
}

int load(linked_list* list, const char* filename) {
    FILE* file = open_file(filename, "r");
    if (file == NULL) return 0;
    
    linked_list next_node = NULL , new_list = NULL;
    
    value read_val;
    
    while (1) {
        fscanf(file, "%d", &read_val);
        if (feof(file)) break;
        if (!check_file(file)) return 0;
        
        
        if (new_list == NULL) {
            new_list = list_create(read_val);
            next_node = new_list;
        } else {
            next_node = list_add_back(read_val, next_node)->next_elem;
        }
    }
    
    *list = new_list;
    return close_file(file);
}

int serialize(linked_list list, const char* filename) {
    FILE* file = open_file(filename, "wb");
    if (file == NULL) return 0;
    
    linked_list next_node = list;
    while (next_node != NULL) {
        fwrite(&next_node->node_value, sizeof(value), 1, file);
        if (!check_file(file)) return 0;
        next_node = next_node->next_elem;
    }
    
    return close_file(file);
}

int deserialize(linked_list* list, const char* filename) {
    FILE* file = open_file(filename, "rb");
    if (file == NULL) return 0;
    
    linked_list next_node = NULL , new_list = NULL;
    
    value read_val;
    
    while (1) {
        fread(&read_val, sizeof(value), 1, file);
        if (feof(file)) break;
        if (!check_file(file)) return 0;
        
        if (new_list == NULL) {
            new_list = list_create(read_val);
            next_node = new_list;
        } else {
            next_node = list_add_back(read_val, next_node)->next_elem;
        }
    }
    
    *list = new_list;
    return close_file(file);
}

linked_list read_from_console() {
    value read_val;
    
    linked_list new_list = NULL;
    
    puts("Введите длинну массива: ");
    
    if (scanf("%d", &read_val) != 1) return NULL;
    
    puts("Введите сам массив:");
    
    int n = read_val;
    int i;
    for(i = 0; i < n; i++) {
        if (scanf("%d", &read_val) != 1) break;
        else new_list = list_add_front(read_val, new_list);
    }
    
    return new_list;
}

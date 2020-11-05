#ifndef list_io_h
#define list_io_h

#include <stdio.h>

#include "linked_list.h"

int save(const linked_list list, const char* filename);
int load(linked_list* list, const char* filename);

int serialize(const linked_list list, const char* filename);
int deserialize(linked_list* list, const char* filename);

linked_list read_from_console(void);
#endif

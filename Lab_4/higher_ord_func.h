#ifndef functional_h
#define functional_h

#include "linked_list.h"

void foreach(const linked_list list, void(*func)(value));

linked_list map(const linked_list list, value(*op)(value));

void map_mut(const linked_list list, value(*op)(value));

value fold_l(const linked_list list, value acc, value(*op)(value, value));

linked_list unfold_l(value init, size_t length, value(*op)(value));

#endif 
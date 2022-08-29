//
// Created by eternal on 2022/8/29.
//

#ifndef ALGORITHM__C_LINEAR_LIST_H
#define ALGORITHM__C_LINEAR_LIST_H
#include <stddef.h>
#include "linear_list_node.h"


typedef struct linear_list {
    size_t length;
    linear_list_node_ptr head;
    linear_list_node_ptr tail;
} linear_list, *linear_list_ptr;


linear_list_ptr linear_list_create();

void linear_list_destroy(linear_list_ptr llp);

void linear_list_clear(linear_list_ptr llp);

void linear_list_push_back(linear_list_ptr llp, int val);

void linear_list_push_front(linear_list_ptr llp, int val);

int linear_list_pop_front(linear_list_ptr llp);

int linear_list_pop_back(linear_list_ptr llp);

_Bool linear_list_find(linear_list_ptr llp, int tar);

void linear_list_foreach(linear_list_ptr llp, void (*func)(int));

#endif //ALGORITHM__C_LINEAR_LIST_H

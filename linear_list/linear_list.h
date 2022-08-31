//
// Created by eternal on 2022/8/29.
//

#ifndef ALGORITHM__C_LINEAR_LIST_H
#define ALGORITHM__C_LINEAR_LIST_H
#include <stddef.h>
#include "linear_list_node.h"
#include <stdbool.h>


typedef struct linear_list {
    size_t length;
    linear_list_node_ptr head;
    linear_list_node_ptr tail;
} linear_list, *linear_list_ptr;


linear_list_ptr linear_list_create();

void linear_list_destroy(linear_list_ptr llp);

void linear_list_clear(linear_list_ptr llp);

int linear_list_get_front(linear_list_ptr llp);

int linear_list_get_back(linear_list_ptr llp);

void linear_list_push_back(linear_list_ptr llp, int val);

void linear_list_push_front(linear_list_ptr llp, int val);

int linear_list_pop_front(linear_list_ptr llp);

int linear_list_pop_back(linear_list_ptr llp);

_Bool linear_list_find(linear_list_ptr llp, int tar);

linear_list_node_ptr linear_list_get_ptr(linear_list_ptr llp, int index);

int linear_list_get_elem(linear_list_ptr llp, int index);

bool linear_list_set_elem(linear_list_ptr llp, int index, int val);

bool linear_list_insert(linear_list_ptr llp, int index, int val);

bool linear_list_remove(linear_list_ptr llp, int index);

void linear_list_foreach(linear_list_ptr llp, void (*func)(int));

void linear_list_foreach_mutable(linear_list_ptr llp, void (*func)(int *));

#endif //ALGORITHM__C_LINEAR_LIST_H

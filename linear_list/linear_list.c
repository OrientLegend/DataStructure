//
// Created by eternal on 2022/8/29.
//

#include "linear_list.h"
#include <stddef.h>
#include "../util.h"
#include <stdlib.h>
#include <assert.h>

linear_list_ptr linear_list_create() {
    linear_list_ptr llp = (linear_list_ptr) malloc(sizeof(linear_list));
    if (llp == NULL) {
        print_error("create_linear_list error: llp is NULL");
        return NULL;
    }
    llp->length = 0;
    llp->head = NULL;
    llp->tail = NULL;
    return llp;
}

void linear_list_destroy(linear_list_ptr llp) {
    if (llp == NULL) return;
    linear_list_clear(llp);
    free(llp);
}

void linear_list_clear(linear_list_ptr llp) {
    if (llp == NULL) return;
    linear_list_node_ptr node = llp -> head;
    while (node != NULL) {
        linear_list_node_ptr next = node->next;
        linear_list_node_destroy(node);
        node = next;
    }
}

void linear_list_push_front(linear_list_ptr llp, int val) {
    assert(llp != NULL);
    if (llp->head == NULL) {
        linear_list_node_ptr llnp = linear_list_node_create(val, NULL, NULL);
        llp->head = llp -> tail = llnp;
        ++(llp->length);
    } else {
        linear_list_node_ptr llnp = linear_list_node_create(val, NULL, llp->head);
        llp->head = llnp;
        ++(llp->length);
    }
}

void linear_list_push_back(linear_list_ptr llp, int val) {
    assert(llp != NULL);
    if (llp->tail == NULL) {
        linear_list_node_ptr llnp = linear_list_node_create(val, NULL, NULL);
        llp->head = llp->tail = llnp;
        ++(llp->length);
    } else {
        linear_list_node_ptr llnp = linear_list_node_create(val, llp->tail, NULL);
        llp->tail = llnp;
        ++(llp->length);
    }
}

int linear_list_pop_front(linear_list_ptr llp) {
    assert(llp != NULL && llp->head != NULL);
    linear_list_node_ptr head = llp->head;
    int res = head->data;
    llp->head = head->next;
    linear_list_node_destroy(head);
    --(llp->length);
    return res;
}

int linear_list_pop_back(linear_list_ptr llp) {
    assert(llp != NULL && llp->tail != NULL);
    linear_list_node_ptr tail = llp->tail;
    int res = tail->data;
    llp->tail = tail->prev;
    linear_list_node_destroy(tail);
    --(llp->length);
    return res;
}

_Bool linear_list_find(linear_list_ptr llp, int tar) {
    if (llp == NULL || llp->length == 0) return 0;
    linear_list_node_ptr node = llp->head;
    while(node != NULL) {
        if (node->data == tar) return 1;
        node = node->next;
    }
    return 0;
}

void linear_list_foreach(linear_list_ptr llp, void (*func)(int)) {
    if (llp == NULL || llp->length == 0) return;
    linear_list_node_ptr node = llp->head;
    while(node != NULL) {
        func(node->data);
        node = node->next;
    }
}
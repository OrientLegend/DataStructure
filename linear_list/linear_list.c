//
// Created by eternal on 2022/8/29.
//

#include "linear_list.h"
#include "../util.h"
#include <stdlib.h>
#include <assert.h>

linear_list_ptr linear_list_create() {
    linear_list_ptr llp = (linear_list_ptr) malloc(sizeof(linear_list));
    if (llp == NULL) {
        println_error("create_linear_list error: llp is NULL");
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

int linear_list_get_front(linear_list_ptr llp) {
    assert(llp != NULL && llp->head != NULL);
    return llp->head->data;
}

int linear_list_get_back(linear_list_ptr llp) {
    assert(llp != NULL && llp->tail != NULL);
    return llp->tail->data;
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

bool linear_list_find(linear_list_ptr llp, int tar) {
    if (llp == NULL || llp->length == 0) return 0;
    linear_list_node_ptr node = llp->head;
    while(node != NULL) {
        if (node->data == tar) return true;
        node = node->next;
    }
    return false;
}

linear_list_node_ptr linear_list_get_ptr(linear_list_ptr llp, int index) {
    if (llp == NULL) return NULL;
    linear_list_node_ptr node = llp->head;
    for (int i = 0; i < index; ++i) {
        if (node == NULL) return NULL;
        node = node->next;
    }
    return node;
}

int linear_list_get_elem(linear_list_ptr llp, int index) {
    linear_list_node_ptr node = linear_list_get_ptr(llp, index);
    assert(node != NULL);
    return node->data;
}

bool linear_list_set_elem(linear_list_ptr llp, int index, int val) {
    linear_list_node_ptr node = linear_list_get_ptr(llp, index);
    if (node == NULL) return false;
    node->data = val;
    return true;
}

bool linear_list_insert(linear_list_ptr llp, int index, int val) {
    assert(llp != NULL);
    linear_list_node_ptr node = linear_list_get_ptr(llp, index);
    if (node == NULL) return false;
    linear_list_node_ptr prev = node->prev;
    linear_list_node_create(val, prev, node); // Here we can ignore the return value
}

bool linear_list_remove(linear_list_ptr llp, int index) {
    assert(llp != NULL);
    linear_list_node_ptr node = linear_list_get_ptr(llp, index);
    if (node == NULL) return false;
    linear_list_node_destroy(node);
}

void linear_list_foreach(linear_list_ptr llp, void (*func)(int)) {
    if (llp == NULL || llp->length == 0) return;
    linear_list_node_ptr node = llp->head;
    while(node != NULL) {
        func(node->data);
        node = node->next;
    }
}

void linear_list_foreach_mutable(linear_list_ptr llp, void (*func)(int *)) {
    if (llp == NULL || llp->length == 0) return;
    linear_list_node_ptr node = llp->head;
    while(node != NULL) {
        func(&(node->data));
        node = node->next;
    }
}
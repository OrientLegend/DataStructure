//
// Created by eternal on 2022/8/29.
//
#include "linear_list_node.h"
#include "../util.h"
#include <stdlib.h>

linear_list_node_ptr linear_list_node_create(int val, linear_list_node_ptr prev, linear_list_node_ptr next) {
    linear_list_node_ptr llnp = (linear_list_node_ptr) malloc(sizeof(linear_list_node));
    if (llnp == NULL) {
        print_error("create_linear_list_node error");
        return NULL;
    }
    llnp->data = val;
    llnp->prev = prev;
    if (prev != NULL) {
        prev->next = llnp;
    }
    llnp->next = next;
    if (next != NULL) {
        next->prev = llnp;
    }
    return llnp;
}

void linear_list_node_destroy(linear_list_node_ptr llnp) {
    if (llnp->prev != NULL) {
        llnp->prev->next = NULL;
    }
    if (llnp->next != NULL) {
        llnp->next->prev = NULL;
    }
    free(llnp);
}



//
// Created by eternal on 2022/8/29.
//

#ifndef ALGORITHM__C_LINEAR_LIST_NODE_H
#define ALGORITHM__C_LINEAR_LIST_NODE_H


typedef struct linear_list_node {
    int data;
    struct linear_list_node* prev;
    struct linear_list_node* next;
}linear_list_node, *linear_list_node_ptr;

linear_list_node_ptr linear_list_node_create(int val, linear_list_node_ptr prev, linear_list_node_ptr next);

void linear_list_node_destroy(linear_list_node_ptr llnp);

#endif //ALGORITHM__C_LINEAR_LIST_NODE_H

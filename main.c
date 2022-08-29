#include <stdio.h>
#include "linear_list/linear_list.h"
#include <assert.h>

void print_int(int num) {
    printf("%d ", num);
}

int main() {
    linear_list_ptr llp = linear_list_create();
    int front[] = {1, 2, 3, 4, 5};
    int back[] = {10, 9, 8, 7, 6};
    for (int i = 0; i < 5; ++i) {
        linear_list_push_front(llp, front[i]);
    }
    for (int i = 0; i < 5; ++i) {
        linear_list_push_back(llp, back[i]);
    }
    linear_list_foreach(llp, print_int);
    int val = linear_list_pop_front(llp);
    assert(val == 5);
    assert(llp->length == 9);
    val = linear_list_pop_back(llp);
    assert(val == 6);
    assert(llp->length == 8);
    linear_list_destroy(llp);
    return 0;
}

#include <stdio.h>
#include "include/linked_list.h"

int main() {
    LinkedList *L = LinkedList_create();

    LinkedList_add_first(L, 3);

    return 0;
}

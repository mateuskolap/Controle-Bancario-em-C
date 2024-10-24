#include <stdlib.h>
#include "../include/linked_list.h"

typedef struct _snode {
    int value;
    struct _snode *next;
} SNode;

typedef struct _linkedList {
    SNode *head;
    SNode *tail;
} LinkedList;

LinkedList *LinkedList_create() {
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));

    L->head = NULL;
    L->tail = NULL;

    return L;
}
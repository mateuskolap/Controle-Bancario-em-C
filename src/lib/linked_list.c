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

SNode *Snode_create(int value) {
    SNode *snode = (SNode *) calloc(1, sizeof(SNode));

    snode->value = value;
    snode->next = NULL;

    return snode;
}

LinkedList *LinkedList_create() {
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));

    L->head = NULL;
    L->tail = NULL;

    return L;
}

void LinkedList_add_first(LinkedList *L, int value) {
    SNode *p = Snode_create(value);
    p->next = L->head;
    L->head = p;
}
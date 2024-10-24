#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _snode SNode;
typedef struct _linkedList LinkedList;

SNode *Snode_create(int value);
LinkedList *LinkedList_create();
void LinkedList_add_first(LinkedList *L, int value);

#endif
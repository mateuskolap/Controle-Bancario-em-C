#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _snode SNode;
typedef struct _linkedList LinkedList;

// cria um nó de uma lista simplesmente encadeada
SNode *SNode_account_create(int value);

// cria uma lista simplesmente encadeada
LinkedList *LinkedList_account_create();

// adiciona um nó no inicio da lista simplesmente encadeada
void LinkedList_account_add_first(LinkedList *L, int value);

// adiciona um nó no final da lista simplesmente encadeada
void LinkedList_account_add_last(LinkedList *L, int value);

#endif
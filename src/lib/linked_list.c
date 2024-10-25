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

/**
 * @brief cria um nó de uma lista simplesmente encadeada
 * @param value:
 */
SNode *Snode_create(int value) {
    SNode *snode = (SNode *) calloc(1, sizeof(SNode));

    snode->value = value;
    snode->next = NULL;

    return snode;
}

/**
 * @brief cria a lista simplesmente encadeada
 */
LinkedList *LinkedList_create() {
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));

    L->head = NULL;
    L->tail = NULL;

    return L;
}

/**
 * @brief adiciona um nó ao inicio da lista
 * @param *L :passa uma lista como parametro para ser adicionado 
 * @param value:  
 */
void LinkedList_add_first(LinkedList *L, int value) {
    SNode *p = Snode_create(value);
    p->next = L->head;
    L->head = p;
}
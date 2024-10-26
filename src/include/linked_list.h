#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct _bank_account bank_account;
typedef struct _snode SNode;
typedef struct _linkedList LinkedList;

// Cria um nó de uma lista simplesmente encadeada
SNode *SNode_account_create(bank_account content);

// Cria uma lista simplesmente encadeada
LinkedList *LinkedList_account_create();

// Verifica se a lista está vazia
bool LinkedList_account_is_empty(const LinkedList *L);

// Adiciona um nó no início da lista simplesmente encadeada
void LinkedList_account_add_first(LinkedList *L, bank_account content);

// Adiciona um nó no final da lista simplesmente encadeada
void LinkedList_account_add_last(LinkedList *L, bank_account content);

// Adiciona um nó no em uma determinada posição da lista simplesmente encadeada
void LinkedList_account_add_at_position(LinkedList *L, bank_account content, int position);

#endif // LINKED_LIST_H

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct _bank_account bank_account;
typedef struct _snode SNode;
typedef struct _linkedList LinkedList;

LinkedList *LinkedList_account_create();
SNode *SNode_account_create(bank_account *content);
void SNode_destroy(SNode **snode_ref);
void LinkedList_destroy(LinkedList **L_ref);
bool LinkedList_account_is_empty(const LinkedList *L);
void LinkedList_account_add_first(LinkedList *L, bank_account *content);
void LinkedList_account_add_last(LinkedList *L, bank_account *content);
void LinkedList_account_add_at_position(LinkedList *L, bank_account *content, int position);
void LinkedList_account_remove_first(LinkedList *L);
void LinkedList_account_remove_end(LinkedList *L);
void LinkedList_account_remove_at_position(LinkedList *L, int position);

#endif
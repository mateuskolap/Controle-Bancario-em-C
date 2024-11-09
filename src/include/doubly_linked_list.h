/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * subfunção..: cabeçalho lista duplamente encadeada
 */

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct _bank_transaction bank_transaction;
typedef struct _dnode DNode;
typedef struct _dLinkedList dLinkedList;

dLinkedList *dLinkedList_transaction_create();
DNode *DNode_transaction_create(bank_transaction *content);
void DNode_destroy(DNode **dnode_ref);
void dLinkedList_destroy(dLinkedList **L_ref);
bool dLinkedList_account_is_empty(const dLinkedList *L);
void dLinkedList_account_add_first(dLinkedList *L, bank_transaction *content);
void dLinkedList_account_add_last(dLinkedList *L, bank_transaction *content);

#endif
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/doubly_linked_list.h"

// Estrutura que armazenará as movimentações bancárias
typedef struct _bank_transaction {
    int sequencial;
    int codigo_conta;
    char data_movimento[11];
    char tp_movimentacao[15];
    double vl_movimento;
    double vl_saldo;
} bank_transaction;

// Nó que armazenará o conteúdo das movimentações bancárias, um ponteiro para o nó anterior e o próximo
typedef struct _dnode {
    bank_transaction *content;
    struct _dnode *previous;
    struct _dnode *next;
} DNode;

// Estrutura da lista duplamente encadeada
typedef struct _dLinkedList {
    DNode *head;
    DNode *tail;
    int size;
} dLinkedList;


/******************* "CONSTRUTORES" *******************/

/**
 * @brief Cria uma lista duplamente encadeada
 * @return Ponteiro para a lista criada
 */
dLinkedList *dLinkedList_transaction_create() {
    dLinkedList *T = (dLinkedList *) calloc(1, sizeof(dLinkedList));

    T->head = NULL;
    T->tail = NULL;
    T->size = 0;

    return T;
}

/**
 * @brief Cria um nó de uma lista duplamente encadeada
 * @param content: informações da transação
 * @return Ponteiro para o nó criado
 */
DNode *DNode_transaction_create(bank_transaction *content) {
    DNode *dnode = (DNode *) calloc(1, sizeof(DNode));

    dnode->content = content;
    dnode->next = NULL;
    dnode->previous = NULL;

    return dnode;
}

/******************* "DESTRUIDORES" *******************/

/**
 * @brief Destrói um nó duplo e seu conteúdo
 * @param L_ref: Endereço de memória de um nó duplo
 */
void DNode_destroy(DNode **dnode_ref) {
    DNode *dnode = *dnode_ref;

    free(dnode->content);
    free(dnode);

    *dnode_ref = NULL;
}

/**
 * @brief Destrói todos os elementos da lista duplamente encadeada.
 * @param L_ref: Endereço de memória da lista
 */
void dLinkedList_destroy(dLinkedList **L_ref) {
    dLinkedList *T = *L_ref;

    DNode *current = T->head;
    DNode *aux = NULL;

    while (current != NULL) {
        aux = current;
        current = current->next;

        DNode_destroy(&aux);
    }

    free(T);
    *L_ref = NULL;
}
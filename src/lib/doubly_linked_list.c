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
    dLinkedList *L = (dLinkedList *) calloc(1, sizeof(dLinkedList));

    L->head = NULL;
    L->tail = NULL;
    L->size = 0;

    return L;
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
    dLinkedList *L = *L_ref;

    DNode *current = L->head;
    DNode *aux = NULL;

    while (current != NULL) {
        aux = current;
        current = current->next;

        DNode_destroy(&aux);
    }

    free(L);
    *L_ref = NULL;
}

/******************* FUNÇÕES DE VERIFICAÇÃO NA LISTA *******************/

/**
 * @brief Verifica se a lista está vazia
 * @param L_ref: Endereço de memória da lista
 */
bool dLinkedList_account_is_empty(const dLinkedList *L) {
    return L->size == 0;
}

/******************* FUNÇÕES DE INSERÇÃO NA LISTA *******************/

/**
 * @brief Adiciona um novo nó ao inicio da lista
 * @param L: Endereço de memória da lista
 * @param content: Conteúdo que deverá ser armazenado no nó
 */
void dLinkedList_account_add_first(dLinkedList *L, bank_transaction *content) {
    // Cria um novo nó com o conteúdo desejado
    DNode *p = DNode_transaction_create(content);
    p->next = L->head;

    if (dLinkedList_account_is_empty(L)) {
        L->tail = p;
    } else {
        L->head->previous = p;
    }

    L->head = p;
    L->size++;
}

/**
 * @brief Adiciona um novo nó ao final da lista
 * @param L: Endereço de memória da lista
 * @param content: Conteúdo que deverá ser armazenado no nó
 */
void dLinkedList_account_add_last(dLinkedList *L, bank_transaction *content) {
    // Cria um novo nó com o conteúdo desejado
    DNode *p = DNode_transaction_create(content);
    p->previous = L->tail;

    if (dLinkedList_account_is_empty(L)) {
        L->head = p;
    } else {
        L->tail->next = p;
    }

    L->tail = p;
    L->size++;
}

void dLinkedList_account_add_at_position(dLinkedList *L, bank_transaction *content, int position) {
    // Verificando se a posição desejada existe.
    if ((position < 1) || (position > L->size + 1)) {
        fprintf(stderr, "ERROR in 'LinkedList_account_add_at_position'\n");
        fprintf(stderr, "Position [%d] is out of bounds: [1, %d]\n", position, L->size);
        return;
    }

    DNode *p = DNode_transaction_create(content);

    // Se a inserção for na primeira posição
    if (position == 1) {
        dLinkedList_account_add_first(L, content);
        return;
    } 

    DNode *current = L->head;
    DNode *previous = NULL;

    // Percorre os elementos da lista até a posição desejada
    for (int count = 1; (current != NULL) && count < position; count++) {
        previous = current; // Armazena o elemento anterior
        current = current->next; // Armazena o próximo elemento
    }

    p->next = current;
    p->previous = previous;

    previous->next = p;
    current->previous = p;
}
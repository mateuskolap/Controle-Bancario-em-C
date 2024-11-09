/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * subfunção..: funçoes lista simplesmente encadeada
 */


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/linked_list.h"
#include "../include/doubly_linked_list.h"

// Estrutura que armazenará as informações da conta bancária
typedef struct _bank_account {
    int codigo_conta;
    char banco[50];
    char agencia[10];
    char numero_conta[20];
    char tipo_conta[20];
    double vl_saldo;
    double vl_limite;
    char status[10];
    dLinkedList *transacoes;
} bank_account;

// Nó que armazenará o conteúdo da estrutura de contas bancárias e um ponteiro para o próximo nó
typedef struct _snode {
    bank_account *content; // Conteúdo
    struct _snode *next;
} SNode;

// Estrutura da lista simplesmente encadeada
typedef struct _linkedList {
    SNode *head;
    SNode *tail;
    int size;
} LinkedList;

/******************* "CONSTRUTORES" *******************/

/**
 * @brief Cria uma lista simplesmente encadeada
 * @return Ponteiro para a lista criada
 */
LinkedList *LinkedList_account_create() {
    // Aloca um espaço na memória heap para armazenar um novo nó
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));

    L->head = NULL;
    L->tail = NULL;
    L->size = 0;

    return L;
}

/**
 * @brief Cria um nó de uma lista simplesmente encadeada
 * @param content: informações da conta
 * @return Ponteiro para o nó criado
 */
SNode *SNode_account_create(bank_account *content) {
    // Aloca um espaço na memória heap para armazenar um novo nó
    SNode *snode = (SNode *) calloc(1, sizeof(SNode));

    snode->content = content;
    snode->next = NULL;

    return snode;
}

/******************* "DESTRUIDORES" *******************/

/**
 * @brief Destrói um nó e seu conteúdo
 * @param L_ref: Endereço de memória de um nó
 */
void SNode_destroy(SNode **snode_ref) {
    SNode *snode = *snode_ref;

    dLinkedList_destroy(&snode->content->transacoes);

    free(snode->content);
    free(snode);

    *snode_ref = NULL;
}

/**
 * @brief Destrói todos os elementos da lista simplesmente encadeada.
 * @param L_ref: Endereço de memória da lista
 */
void LinkedList_destroy(LinkedList **L_ref) {
    LinkedList *L = *L_ref;

    SNode *current = L->head;
    SNode *aux = NULL;

    while (current != NULL) {
        aux = current;
        current = current->next;

        SNode_destroy(&aux);
    }

    free(L);
    *L_ref = NULL;
}

/******************* FUNÇÕES DE VERIFICAÇÃO NA LISTA *******************/

/**
 * @brief Verifica se a lista está vazia
 * @param L_ref: Endereço de memória da lista
 */
bool LinkedList_account_is_empty(const LinkedList *L) {
    return L->size == 0;
}

/******************* FUNÇÕES DE INSERÇÃO NA LISTA *******************/

/**
 * @brief Adiciona um nó ao início da lista
 * @param L: Endereço de memória da lista
 * @param content: valor da conta bancária a ser armazenado no novo nó
 */
void LinkedList_account_add_first(LinkedList *L, bank_account *content) {
    // Cria um novo nó com o conteúdo desejado
    SNode *p = SNode_account_create(content);

    p->next = L->head; // O ponteiro próximo do novo nó apontará para o primeiro nó da lista

    // Verifica se a lista está vazia
    if (LinkedList_account_is_empty(L)) {
        L->tail = p;
    } 

    L->head = p; // A cabeça da lista será alterada para guardar o novo nó   

    L->size++; 
}

/**
 * @brief Adiciona um nó ao final da lista
 * @param L: Endereço de memória da lista
 * @param content: valor da conta bancária a ser armazenado no novo nó
 */
void LinkedList_account_add_last(LinkedList *L, bank_account *content) {
    // Cria um novo nó com o conteúdo desejado
    SNode *p = SNode_account_create(content);

    // Se a lista estiver vazia
    if (LinkedList_account_is_empty(L)) {
        L->head = p;
    // Se a lista não estiver vazia
    } else {        
        L->tail->next = p;
    }

    L->tail = p;
    L->size++; 
}

/**
 * @brief Adiciona um nó em uma determinada posição da lista
 * @param L: Endereço de memória da lista
 * @param content: valor da conta bancária a ser armazenado no novo nó
 * @param position: posicção na qual deverá ser inserido o novo nó
 */
void LinkedList_account_add_at_position(LinkedList *L, bank_account *content, int position) {
    // Verificando se a posição desejada existe.
    if ((position < 1) || (position > L->size + 1)) {
        fprintf(stderr, "ERROR in 'LinkedList_account_add_at_position'\n");
        fprintf(stderr, "Position [%d] is out of bounds: [1, %d]\n", position, L->size);
        return;
    }

    SNode *p = SNode_account_create(content);
 
    // Se a inserção for na primeira posição
    if (position == 1) {
        LinkedList_account_add_first(L, content);
        return;
    } 

    SNode *current = L->head;
    SNode *previous = NULL;

    // Percorre os elementos da lista até a posição desejada
    for (int count = 1; (current != NULL) && (count < position); count++) {
        previous = current; // Armazena o elemento anterior
        current = current->next; // Armazena o próximo elemento
    }

    // Insere o valor do próximo elemento em "p"
    p->next = current;
    
    previous->next = p;

    // Se a inserção for no final da lista, o novo elemento deve estar presente no campo "tail"
    if (current == NULL) {
        L->tail = p;
    }

    L->size++; 
}

/*******************************************************************/

/******************* FUNÇÕES DE REMOÇÃO NA LISTA *******************/

/**
 * @brief Remove o primeiro nó da lista
 * @param L: Endereço de memória da lista
 */
void LinkedList_account_remove_first(LinkedList *L) {
    // Retorna um erro se a lista estiver vazia
    if (LinkedList_account_is_empty(L)) {
        fprintf(stderr, "ERROR in 'LinkedList_account_remove_first': The list is already empty.\n");
        return;
    }

    // Nó temporário que auxiliará na remoção do primeiro elemento
    SNode *temp = L->head;

    // Se a lista possuir somente um elemento
    if (L->head == L->tail) {
        L->tail = NULL;
    }

    // A cabeça da lista passa a apontar para o segundo elemento
    L->head = L->head->next;
    SNode_destroy(&temp); // O primeiro nó é desalocado

    L->size--; // Decrementa o tamanho da lista
}

/**
 * @brief Remove o último nó da lista
 * @param L: Endereço de memória da lista
 */
void LinkedList_account_remove_end(LinkedList *L) {
    // Retorna um erro se a lista estiver vazia
    if (LinkedList_account_is_empty(L)) {
        fprintf(stderr, "ERROR in 'LinkedList_account_remove_end': The list is already empty.\n");
        return;
    }

    // Caso especial para quando a lista possuir somente um elemento
    if (L->head == L->tail) {
        SNode_destroy(&L->head);
        L->head = NULL;
        L->tail = NULL;
        L->size--;
        return;
    }

    // Auxiliares para remoção
    SNode *current = L->head->next;
    SNode *previous = NULL;

    // Encontra o último nó para remover, e o anterior
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    // Desaloca e reorganiza a lista
    previous->next = NULL;
    L->tail = previous;
    SNode_destroy(&current);

    L->size--;
}

/**
 * @brief Remove um nó em uma determinada posição da lista
 * @param L: Endereço de memória da lista
 * @param position: posicção na qual deverá ser removido o nó
 */
void LinkedList_account_remove_at_position(LinkedList *L, int position) {
    // Retorna um erro se a lista estiver vazia
    if (LinkedList_account_is_empty(L)) {
        fprintf(stderr, "ERROR in 'LinkedList_account_remove_at_position': The list is already empty.\n");
        return;
    }

    // Verificando se a posição desejada existe.
    if ((position < 1) || (position > L->size)) {
        fprintf(stderr, "ERROR in 'LinkedList_account_remove_at_position'\n");
        fprintf(stderr, "Position [%d] is out of bounds: [1, %d]\n", position, L->size);
        return;
    }

    // Se for a primeira posição
    if (position == 1) {
        LinkedList_account_remove_first(L);
        return;
    }

    // Auxiliares para remoção
    SNode *current = L->head;
    SNode *previous = NULL;

    // Encontra o nó desejado para remover, e o anterior
    for (int count = 1; (current != NULL) && (count < position); count++) {
        previous = current;
        current = current->next;
    }

    // O próximo nó do anterior, será o próximo nó do atual
    previous->next = current->next;

    // Se a remoção for na cauda
    if (current == L->tail) {
        L->tail = previous;
    }
    
    // O nó é desalocado
    SNode_destroy(&current);

    L->size--; // Decrementa o tamanho da lista
}

/*******************************************************************/
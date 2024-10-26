#include <stdlib.h>
#include <stdio.h>
#include "../include/linked_list.h"

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
} bank_account;

// Nó que armazenará o conteúdo da estrutura de contas bancárias e um ponteiro para o próximo nó
typedef struct _snode {
    bank_account content; // Conteúdo
    struct _snode *next;
} SNode;

// Estrutura da lista simplesmente encadeada
typedef struct _linkedList {
    SNode *head;
    SNode *tail;
    int size;
} LinkedList;

/**
 * @brief Cria uma lista simplesmente encadeada
 * @return Ponteiro para a lista criada
 */
LinkedList *LinkedList_account_create() {
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));

    L->head = NULL;
    L->tail = NULL;
    L->size = 0;

    return L;
}

/**
 * @brief Cria um nó de uma lista simplesmente encadeada
 * @param content: valor da conta bancária a ser armazenado no nó
 * @return Ponteiro para o nó criado
 */
SNode *SNode_account_create(bank_account content) {
    // Aloca um espaço na memória heap para armazenar um novo nó
    SNode *snode = (SNode *) calloc(1, sizeof(SNode));

    snode->content = content;
    snode->next = NULL;

    return snode;
}

// Verifica se a lista está vazia
bool LinkedList_account_is_empty(const LinkedList *L) {
    return (L->head == NULL && L->tail == NULL);
}

/******************* FUNÇÕES DE INSERÇÃO NA LISTA *******************/

/**
 * @brief Adiciona um nó ao início da lista
 * @param L: Endereço de memória da lista
 * @param content: valor da conta bancária a ser armazenado no novo nó
 */
void LinkedList_account_add_first(LinkedList *L, bank_account content) {
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
void LinkedList_account_add_last(LinkedList *L, bank_account content) {
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
void LinkedList_account_add_at_position(LinkedList *L, bank_account content, int position) {

    // Verificando se a posição desejada existe.
    if ((position < 1) || (position > L->size + 1)) {
        fprintf(stderr, "ERROR in 'LinkedList_account_add_at_position'\n");
        fprintf(stderr, "Position [%d] is out of bounds: [1, %d]\n", position, L->size);
        exit(EXIT_FAILURE);
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
    
    // Se o nó anterior não for nulo, ele deve apontar para o novo elemento
    if (previous != NULL) {
        previous->next = p;
    }

    // Se a inserção for no final da lista, o novo elemento deve estar presente no campo "tail"
    if (current == NULL) {
        L->tail = p;
    }

    L->size++; 
}

/*******************************************************************/

/******************* FUNÇÕES DE REMOÇÃO NA LISTA *******************/

/*******************************************************************/
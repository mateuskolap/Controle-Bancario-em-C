#include <stdlib.h>
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

typedef struct _linkedList {
    SNode *head;
    SNode *tail;
} LinkedList;

/**
 * @brief Cria uma lista simplesmente encadeada
 * @return Ponteiro para a lista criada
 */
LinkedList *LinkedList_account_create() {
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));

    L->head = NULL;
    L->tail = NULL;

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

/**
 * @brief Adiciona um nó ao início da lista
 * @param L: Endereço de memória da lista
 * @param content: valor da conta bancária a ser armazenado no novo nó
 */
void LinkedList_account_add_first(LinkedList *L, bank_account content) {
    // Cria um novo nó com o conteúdo desejado
    SNode *p = SNode_account_create(content);

    p->next = L->head; // Agora, o campo "next" do ponteiro, apontará para o primeiro nó da lista.
    L->head = p; // A cabeça da lista passa a ser o novo elemento inserido.

    // Se não houver um novo elemento no final da lista, a cauda 
    if (L->tail == NULL) {
        L->tail = p;
    }
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
    if (L->head == NULL) {
        L->head = p;
    // Se a lista não estiver vazia
    } else {        
        L->tail->next = p;
    }

    L->tail = p;
}
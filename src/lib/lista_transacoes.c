/**
 * Autor......: Mateus Kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus Kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: funçoes lista duplamente encadeada
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/lista_contas.h"
#include "../include/lista_transacoes.h"

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
} List;

/******************* "CONSTRUTORES" *******************/

/**
 * @brief Cria uma nova lista de transações e inicializa suas propriedades.
 * 
 * A função aloca dinamicamente memória para uma nova lista duplamente encadeada (`List`) e
 * inicializa seus campos:
 * - `head` é configurado como `NULL`, indicando que a lista está vazia;
 * - `tail` também é configurado como `NULL`, já que não há elementos na lista;
 * - `size` é inicializado como 0, pois a lista começa sem elementos.
 * 
 * A função retorna o ponteiro para a nova lista de transações criada.
 * 
 * @return Ponteiro para a nova lista de transações (`List`). Caso a alocação de memória falhe, 
 *         a função retornará `NULL`.
 */
List *CriarListaTransacoes() {
    List *L = (List *) calloc(1, sizeof(List));

    L->head = NULL;
    L->tail = NULL;
    L->size = 0;

    return L;
}
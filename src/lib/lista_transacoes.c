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
#include <string.h>
#include "../include/lista_contas.h"
#include "../include/lista_transacoes.h"
#include "../include/funcionalidades.h"

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
    L->ultimo_sequencial = 1;

    return L;
}

/**
 * @brief Cria um novo nó de transação para uma lista duplamente encadeada.
 * 
 * A função aloca memória para um novo nó de transação (`DNode`) e inicializa seus ponteiros
 * `next` e `previous` como `NULL`, configurando o conteúdo do nó com o ponteiro fornecido 
 * (`content`).
 * 
 * @param content Ponteiro para a estrutura `bank_transaction` que contém as informações
 * da transação que serão armazenadas no nó.
 * 
 * @return Ponteiro para o novo nó de transação criado (`DNode`).
 * 
 * @note A função assume que `content` é um ponteiro válido para `bank_transaction`. A
 * responsabilidade de liberar a memória do nó e do conteúdo posteriormente cabe à função
 * que utilizará este nó.
 */
DNode *CriarTransacao(bank_transaction *content) {
    DNode *dnode = (DNode *) calloc(1, sizeof(DNode));

    dnode->content = content;
    dnode->next = NULL;
    dnode->previous = NULL;

    return dnode;
}

/******************* FUNÇÕES DE VERIFICAÇÃO NA LISTA *******************/

/**
 * @brief Verifica se a lista está vazia
 * @param L_ref: Endereço de memória da lista
 */
bool ListaTransacoesEstaVazia(const List *L) {
    return L->size == 0;
}

/******************* FUNÇÕES DE INSERÇÃO NA LISTA *******************/

void AdicionarTransacao(List *Lt, LinkedList *Lc, bank_transaction *content) {
    // Cria um novo nó com o conteúdo desejado
    DNode *p = CriarTransacao(content);

    p->previous = Lt->tail;

    if (ListaTransacoesEstaVazia(Lt)) {
        Lt->head = p;
    } else {
        Lt->tail->next = p;
    }

    Lt->tail = p;
    Lt->size++;

    Lt->tail->content->sequencial = Lt->ultimo_sequencial;
    Lt->ultimo_sequencial++;

    // Realizando as alterações na conta pertencente à transação
    bank_account *conta = ConsultarConta(Lc, p->content->codigo_conta);

    conta->num_transacoes++;

    if (strcmp(p->content->tp_movimentacao, "CREDITO") == 0) {
        Creditar(conta, p->content->vl_movimento);
    } else if (strcmp(p->content->tp_movimentacao, "DEBITO") == 0) {
        Debitar(conta, p->content->vl_movimento);
    }
}
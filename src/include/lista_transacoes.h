/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: cabeçalho lista duplamente encadeada
 */

#ifndef LISTA_TRANSACOES_H
#define LISTA_TRANSACOES_H

#include <stdbool.h>

// Estrutura que armazenará as movimentações bancárias
typedef struct _bank_transaction {
    int sequencial;
    int codigo_conta;
    char data_movimento[11];
    char tp_movimentacao[7];
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
    int ultimo_sequencial;
} List;

List *CriarListaTransacoes();
DNode *CriarTransacao(bank_transaction *content);
void AdicionarTransacao(List *Lt, LinkedList *Lc, bank_transaction *content);

#endif
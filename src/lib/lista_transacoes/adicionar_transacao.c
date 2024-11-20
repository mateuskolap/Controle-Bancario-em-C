/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Adicionar uma transação
 */


#include "../../include/funcoes.h"
#include <string.h>

void AdicionarTransacao(List *lista_transacoes, LinkedList *lista_contas, bank_transaction *content) {
    // Cria um novo nó com o conteúdo desejado
    DNode *p = CriarTransacao(content);

    p->previous = lista_transacoes->tail;

    if (ListaTransacoesEstaVazia(lista_transacoes)) {
        lista_transacoes->head = p;
    } else {
        lista_transacoes->tail->next = p;
    }

    lista_transacoes->tail = p;
    lista_transacoes->size++;

    lista_transacoes->tail->content->sequencial = lista_transacoes->size;

    // Realizando as alterações na conta pertencente à transação
    bank_account *conta = ConsultarConta(lista_contas, p->content->codigo_conta);

    conta->num_transacoes++;

    if (strcmp(p->content->tp_movimentacao, "CREDITO") == 0) {
        conta->vl_saldo += p->content->vl_movimento;
    } else if (strcmp(p->content->tp_movimentacao, "DEBITO") == 0) {
        conta->vl_saldo -= p->content->vl_movimento;
    }
}
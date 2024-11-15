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
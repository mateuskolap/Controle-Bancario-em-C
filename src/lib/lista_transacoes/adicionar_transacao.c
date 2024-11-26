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

/**
 * @brief Adiciona uma nova transacao bancária ao final da lista.
 * 
 * A função insere uma nova transacao ao final da lista de transacões.
 * 
 * @param lista_transacoes Ponteiro para a lista de transacões (`List`).
 * @param lista_contas Ponteiro para a lista de contas (`LinkedList`).
 * @param content Ponteiro para uma estrutura de transacoes (`bank_transaction`).
 * @param tipo_transacao Constante que definirá qual a operação de deverá ser executada (`CREDITO` ou `DEBITO`).
 * 
 */
void AdicionarTransacao(List *lista_transacoes, LinkedList *lista_contas, bank_transaction *content, const int tipo_transacao) {
    // Cria um novo nó com o conteúdo desejado
    DNode *p = CriarTransacao(content);

    // O ponteiro para o nó anterior é atualizado, e conterá o endereço do nó final da lista
    p->previous = lista_transacoes->tail;

    // Caso especial para quando a lista estiver vazia
    if (ListaTransacoesEstaVazia(lista_transacoes)) {
        lista_transacoes->head = p;
    } else {
        lista_transacoes->tail->next = p;
    }

    // O nó da lista é atualizado
    lista_transacoes->tail = p;
    // O tamanho da lista de transacoes é acrescentado em 1
    lista_transacoes->size++;

    // Informando o sequencial da transacao
    lista_transacoes->tail->content->sequencial = lista_transacoes->size;

    // Realizando as alterações na conta pertencente à transação
    bank_account *conta = ConsultarConta(lista_contas, p->content->codigo_conta);

    // O número de transações da conta é acrescentado em 1
    conta->num_transacoes++;

    // Verificando qual operação deverá ser realizada
    if (tipo_transacao == 1) {
        conta->vl_saldo += p->content->vl_movimento;
    } else if (tipo_transacao == 2) {
        conta->vl_saldo -= p->content->vl_movimento;
    }
}
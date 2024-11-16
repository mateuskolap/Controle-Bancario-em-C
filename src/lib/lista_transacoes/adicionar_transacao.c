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

void AdicionarTransacao(LinkedList *lista_contas, List *lista_transacoes, const int codigo_conta, char data_movimento[], const int tipo_movimentacao, const double valor_movimentacao) {

    bank_transaction transacao;

    if (tipo_movimentacao == 1) {
        bank_account *conta = ConsultarConta(lista_contas, codigo_conta);

        transacao.codigo_conta = codigo_conta;
        strcpy(transacao.data_movimento, data_movimento);
        strcpy(transacao.tp_movimentacao, "CREDITO");
        transacao.vl_movimento = valor_movimentacao;
        
        conta->vl_saldo += valor_movimentacao; // Atualizando o saldo da conta

        transacao.vl_saldo = conta->vl_saldo;

    } else if (tipo_movimentacao == 2) {
        bank_account *conta = ConsultarConta(lista_contas, codigo_conta);

        transacao.codigo_conta = codigo_conta;
        strcpy(transacao.data_movimento, data_movimento);
        strcpy(transacao.tp_movimentacao, "DEBITO");
        transacao.vl_movimento = valor_movimentacao;

        conta->vl_saldo -= valor_movimentacao; // Atualizando o saldo da conta

        transacao.vl_saldo = conta->vl_saldo;
    }

    lista_transacoes++;

    return;
}
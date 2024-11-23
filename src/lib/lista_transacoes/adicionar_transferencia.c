/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Criar uma conta
 */

#include "../../include/funcoes.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void AdicionarTransferencia(List *lista_transacoes, LinkedList *lista_contas, bank_account *conta_origem, bank_account *conta_destino, const double valor, char data[]) {
    // Transação de origem
    bank_transaction *transacao_origem = (bank_transaction *) calloc(1, sizeof(bank_transaction));

    transacao_origem->codigo_conta = conta_origem->codigo_conta;
    strcpy(transacao_origem->data_movimento, data);
    strcpy(transacao_origem->tp_movimentacao, "DEBITO");
    transacao_origem->vl_movimento = valor;
    sprintf(transacao_origem->favorecido, "TRANSFERENCIA PARA %s", conta_destino->banco);
    transacao_origem->vl_saldo = conta_origem->vl_saldo - valor;

    AdicionarTransacao(lista_transacoes, lista_contas, transacao_origem, 2);

    // Transação de destino
    bank_transaction *transacao_destino = (bank_transaction *) calloc(1, sizeof(bank_transaction));

    transacao_destino->codigo_conta = conta_destino->codigo_conta;
    strcpy(transacao_destino->data_movimento, data);
    strcpy(transacao_destino->tp_movimentacao, "CREDITO");
    transacao_destino->vl_movimento = valor;
    sprintf(transacao_destino->favorecido, "TRANSFERENCIA DE %s", conta_origem->banco);
    transacao_destino->vl_saldo = conta_destino->vl_saldo + valor;

    AdicionarTransacao(lista_transacoes, lista_contas, transacao_destino, 1);
}
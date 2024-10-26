#ifndef STRUCTS_H
#define STRUCTS_H

// estrutura de informações da movimentação bancaria
typedef struct _bank_transaction {
    int sequencial;
    int codigo_conta;
    char data_movimento[11];
    char tp_movimentacao[15];
    double vl_movimento;
    double vl_saldo;
} bank_transaction;

#endif
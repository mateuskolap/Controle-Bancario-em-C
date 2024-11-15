#include "../../include/funcoes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Altera uma determinada informação de uma conta bancária.
 * 
 * A função modifica um campo específico da estrutura `bank_account` com base no valor do parâmetro `informacao`.
 * Dependendo do campo selecionado, a função copia o valor de `nova_informacao` para o campo da estrutura 
 * ou converte `nova_informacao` para o tipo adequado (por exemplo, `double` para `vl_limite`).
 *
 * @param conta Endereço de memória da estrutura `bank_account` que contém a conta a ser alterada.
 * @param informacao Código que indica qual campo da estrutura será alterado:
 *      1: Altera o nome do banco.
 *      2: Altera o número da agência.
 *      3: Altera o número da conta.
 *      4: Altera o tipo da conta.
 *      5: Alterar o saldo (não permitido, gera mensagem de erro).
 *      6: Altera o limite da conta (converte `nova_informacao` para `double`).
 *      7: Altera o status da conta.
 * @param nova_informacao Uma string contendo o novo valor que será atribuído ao campo indicado.
 * 
 * @note Se o código `informacao` for 5 (saldo), a função emitirá uma mensagem de erro informando que o saldo 
 *       não pode ser alterado diretamente. Se `informacao` for inválido, uma mensagem de erro é exibida.
 */
void AlterarInformacao(bank_account *conta, const int informacao, char nova_informacao[]) {
    switch (informacao) {
        case 1: // Alterando o banco
            strncpy(conta->banco, nova_informacao, sizeof(conta->banco) - 1);
            conta->banco[sizeof(conta->banco) - 1] = '\0';
            break;
        case 2: // Alterando a agência
            strncpy(conta->agencia, nova_informacao, sizeof(conta->agencia) - 1);
            conta->agencia[sizeof(conta->agencia) - 1] = '\0';
            break;
        case 3: // Alterando o numero da conta
            strncpy(conta->numero_conta, nova_informacao, sizeof(conta->numero_conta) - 1);
            conta->numero_conta[sizeof(conta->numero_conta) - 1] = '\0';
            break;
        case 4: // Alterando o tipo da conta
            strncpy(conta->tipo_conta, nova_informacao, sizeof(conta->tipo_conta) - 1);
            conta->tipo_conta[sizeof(conta->tipo_conta) - 1] = '\0';
            break;
        case 5:// Alterando o saldo da conta
            fprintf(stderr, "O saldo da conta não pode ser alterado!");
            return;
        case 6: // Alterando o limite da conta
            conta->vl_limite = atof(nova_informacao);
            break;
        case 7: // Alterando o status da conta
            strncpy(conta->status, nova_informacao, sizeof(conta->status) - 1);
            conta->status[sizeof(conta->status) - 1] = '\0';
            break;
    }
}
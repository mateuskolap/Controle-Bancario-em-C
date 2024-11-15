#include "../../include/funcoes.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Consulta o saldo de uma conta bancária.
 * 
 * A função localiza a conta bancária com o código informado na lista de contas (`LinkedList`),
 * utilizando a função `ConsultarConta`. Em seguida, retorna o saldo da conta (`vl_saldo`).
 * 
 * Caso a conta não seja encontrada na lista, a função pode retornar um valor indefinido, pois a
 * função `ConsultarConta` retornaria `NULL`.
 * 
 * @param L Ponteiro para a lista de contas bancárias (`LinkedList`).
 * @param codigo_conta Código da conta bancária que se deseja consultar.
 * 
 * @return Saldo da conta bancária (`vl_saldo`).
 * 
 * @note Caso a conta não seja encontrada, a função retornará o valor '-1'.
 */
double ConsultarSaldo(LinkedList *L, int codigo_conta) {
    bank_account *conta = ConsultarConta(L, codigo_conta);
    
    if (conta != NULL) {
        return conta->vl_saldo;
    }

    fprintf(stderr, "ERROR in 'ConsultarSaldo': This account doesn't exists.\n");
    exit(EXIT_FAILURE);
}
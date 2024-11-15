/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Consultar o0 numero de transacoes de uma determinada conta
 */

#include "../../include/funcoes.h"

int ConsultarNumTransacoes(bank_account *conta) {
    return conta->num_transacoes;
}
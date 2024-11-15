/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Creditar um valor em uma determinada conta
 */

#include "../../include/funcoes.h"

void Creditar(bank_account *conta, double valor) {
    conta->vl_saldo += valor;
}
#include "../../include/funcoes.h"

void Creditar(bank_account *conta, double valor) {
    conta->vl_saldo += valor;
}
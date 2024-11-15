#include "../../include/funcoes.h"

void Debitar(bank_account *conta, double valor) {
    conta->vl_saldo -= valor;
}

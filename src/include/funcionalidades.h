#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

double ConsultarSaldo(LinkedList *L, int codigo_conta);
void Creditar(bank_account *conta, double valor);
void Debitar(bank_account *conta, double valor);

#endif
#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void ExibirFormularioTransferencia(int x_inicial, int y_inicial) {
    AlinharTextoNaPosicao(x_inicial, y_inicial, "Banco...........:");
    AlinharTextoNaPosicao(x_inicial, ++y_inicial, "Agencia.........:");
    AlinharTextoNaPosicao(x_inicial, ++y_inicial, "Numero da Conta.:");
    AlinharTextoNaPosicao(x_inicial, ++y_inicial, "Saldo...........:");
    AlinharTextoNaPosicao(x_inicial, ++y_inicial, "Limite..........:");
    AlinharTextoNaPosicao(x_inicial, ++y_inicial, "Saldo + Limite..:");
    AlinharTextoNaPosicao(x_inicial, ++y_inicial, "Novo Saldo......:");
}
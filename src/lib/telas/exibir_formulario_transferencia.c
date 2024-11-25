/**
 * Autor......: Rian da Cruz
 * Data.......: 16/11/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: tela formulario de transaçoes
 */

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
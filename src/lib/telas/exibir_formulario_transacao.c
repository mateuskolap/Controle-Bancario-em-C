#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void ExibirFormularioTransacao() {

   int nLinha = 7;

   AlinharTextoNaPosicao(4, nLinha++, "Codigo da Conta........:");
   AlinharTextoNaPosicao(4, nLinha++, "Banco..................:");
   AlinharTextoNaPosicao(4, nLinha++, "Agencia................:");
   AlinharTextoNaPosicao(4, nLinha++, "Numero da Conta........:");
   AlinharTextoNaPosicao(4, nLinha++, "Tipo da conta..........:");
   AlinharTextoNaPosicao(4, nLinha++, "Saldo..................:");
   AlinharTextoNaPosicao(4, nLinha++, "Limite.................:");
   AlinharTextoNaPosicao(4, nLinha++, "Total Saldo + Limite...:");
   AlinharTextoNaPosicao(4, ++nLinha, "1-Data Movimentacao....:");
   AlinharTextoNaPosicao(4, ++nLinha, "2-Tipo Movimentacao....:");
   AlinharTextoNaPosicao(4, ++nLinha, "3-Favorecido...........:");
   AlinharTextoNaPosicao(4, ++nLinha, "4-Valor movimentacao...:");
   AlinharTextoNaPosicao(4, ++nLinha, "1-Novo Saldo...........:");

}
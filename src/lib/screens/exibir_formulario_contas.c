#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void ExibirFormularioContas(int tipo_cadastro) {
    AlinharTextoNaPosicao(4, 6, "   Codigo..........:");
    AlinharTextoNaPosicao(4, 8, "1. Banco...........:");
    AlinharTextoNaPosicao(4, 10, "2. Agencia.........:");
    AlinharTextoNaPosicao(4, 12, "3. Numero Conta....:");
    AlinharTextoNaPosicao(4, 14, "4. Tipo de Conta...:");
    AlinharTextoNaPosicao(4, 16, "5. Saldo...........:");
    AlinharTextoNaPosicao(4, 18, "6. Limite..........:");

    if (tipo_cadastro == 4) {
        AlinharTextoNaPosicao(4, 20, "Status da Conta:...:");
    }
    
    if (tipo_cadastro == 3) {
        AlinharTextoNaPosicao(4, 22, "Posicao de cadastro:");
    }

}
/**
 * Autor......: Rian da Cruz
 * Data.......: 16/11/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: tela formulario de contas
 */

#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void ExibirFormularioContas(int tipo_cadastro) {
    AlinharTextoNaPosicao(3, 6, "  Codigo.............:");
    AlinharTextoNaPosicao(3, 8, "1.Banco..............:");
    AlinharTextoNaPosicao(3, 10, "2.Agencia............:");
    AlinharTextoNaPosicao(3, 12, "3.Numero Conta.......:");
    AlinharTextoNaPosicao(3, 14, "4.Tipo de Conta......:");
    AlinharTextoNaPosicao(3, 16, "5.Saldo..............:");
    AlinharTextoNaPosicao(3, 18, "6.Limite.............:");

    if (tipo_cadastro == 4) {
        AlinharTextoNaPosicao(3, 20, "7.Status da Conta:...:");
    }
    
    if (tipo_cadastro == 3) {
        AlinharTextoNaPosicao(3, 22, "Posicao de cadastro:");
    }

}
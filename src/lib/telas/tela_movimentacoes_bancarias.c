#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void TelaMovimentacoesBancarias(LinkedList *lista_contas, List *lista_transacoes) {

    int opcao;
    
    while(1) {

        Moldura(); 
        CriarTitulo("MENU DE MOVIMENTACOES BANCARIAS");
        AlinharTextoNaPosicao(4, 10, "1. Movimentacao de Debito e Credito");
        AlinharTextoNaPosicao(4, 12, "2. Transferencia entre Contas Bancarias");
        AlinharTextoNaPosicao(4, 14, "3. Consulta Movimentacoes Bancarias");
        AlinharTextoNaPosicao(4, 16, "4. Retornar ao Menu Anterior");
        
        gotoxy(8, 24);
        scanf("%d", &opcao);
        
        switch (opcao) {
        
        case 1: 

            TelaMovimentacaoDebitoCredito(lista_contas, lista_transacoes);
            break;

        case 2:

            TelaTransferenciaEntreContas(lista_contas, lista_transacoes);
            break;

        case 3:

            TelaConsultarTransacoes(lista_contas, lista_transacoes);
            break;

        case 4:

            return;

        default:
        
            AlinharTextoNaPosicao(8, 24, "Digite uma opcao valida!");
            getch();
            AlinharTextoNaPosicao(8, 24, "                        ");

        }
    }
}
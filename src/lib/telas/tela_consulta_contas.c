#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void TelaConsultaContas(LinkedList *lista_contas) {
    int opcao;

    while(1) {

        Moldura();
        CriarTitulo("TELA DE CONSULTA DE CONTAS");

        AlinharTextoNaPosicao(4, 8, "1. Consulta Geral");
        AlinharTextoNaPosicao(4, 10, "2. Consulta por Codigo");
        AlinharTextoNaPosicao(4, 12, "3. Consulta por Ordem de Codigo");
        AlinharTextoNaPosicao(4, 14, "4. Consulta por Ordem Alfabetica");
        AlinharTextoNaPosicao(4, 16, "5. Consulta Contas Inativas");
        AlinharTextoNaPosicao(4, 18, "6. Retorna ao Menu Anterior");

        gotoxy(8, 24);
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                TelaConsultaGeralContas(lista_contas);
                break;
            case 2:
                TelaConsultarContaCodigo(lista_contas);
                break;
            case 3:
                TelaConsultarContaPorOrdem(lista_contas, 2);
                break;
            case 4:
                TelaConsultarContaPorOrdem(lista_contas, 1);
                break;
            case 5:
                TelaConsultarContasInativas(lista_contas);
                break;
            case 6:
                return;
            default:
                AlinharTextoNaPosicao(8, 24, "Digite uma opcao valida!");
                getch();
                AlinharTextoNaPosicao(8, 24, "                        ");
        }

        gotoxy(8, 24);
    }
}
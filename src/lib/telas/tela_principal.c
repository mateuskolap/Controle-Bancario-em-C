#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void TelaPrincipal(LinkedList *lista_contas, List *lista_transacoes) {
    int opcao;

    while (1) {
        Moldura();
        CriarTitulo("Selecione o Menu que Deseja Acessar");

        AlinharTextoNaPosicao(4, 11, "1. Contas Bancarias");
        AlinharTextoNaPosicao(4, 13, "2. Movimentacoes Bancarias");
        AlinharTextoNaPosicao(4, 15, "3. Sair do Programa");

        gotoxy(8, 24);
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                TelaContasBancarias(lista_contas);
                break;
            case 2:
                TelaMovimentacoesBancarias(lista_contas, lista_transacoes);
                break;
            case 3:
                SalvarContasEmArquivo(lista_contas);
                SalvarTransacoesEmArquivo(lista_transacoes);
                return;
            default:
                gotoxy(8, 24);
                printf("Digite uma opcao valida!");
                getch();
        }
    }
}
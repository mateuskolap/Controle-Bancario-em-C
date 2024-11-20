#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void TelaContasBancarias(LinkedList *lista_contas) {
    int opcao;

    while(1) {

        Moldura();
        CriarTitulo("TELA DE CONTAS BANCARIAS");

        AlinharTextoNaPosicao(4, 9, "1. Cadastrar Conta Bancaria no Final");
        AlinharTextoNaPosicao(4, 10, "2. Cadastrar Conta Bancaria no Inicio");
        AlinharTextoNaPosicao(4, 11, "3. Cadastrar Conta Bancaria na Posicao");
        AlinharTextoNaPosicao(4, 12, "4. Remover Conta Bancaria no Final");
        AlinharTextoNaPosicao(4, 13, "5. Remover Conta Bancaria no Inicio");
        AlinharTextoNaPosicao(4, 14, "6. Remover Conta Bancaria na Posicao");
        AlinharTextoNaPosicao(4, 15, "7. Alteracao de Conta Bancaria");
        AlinharTextoNaPosicao(4, 16, "8. Consulta de Conta Bancaria");
        AlinharTextoNaPosicao(4, 17, "9. Retornar ao Menu Anterior");

        gotoxy(8, 24);
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                TelaCadastrarConta(lista_contas, 1);
                break;
            case 2:
                TelaCadastrarConta(lista_contas, 2);
                break;
            case 3:
                TelaCadastrarConta(lista_contas, 3);
                break;
            case 4:
                TelaRemoverConta(lista_contas, 2);
                break;
            case 5:
                TelaRemoverConta(lista_contas, 1);
                break;
            case 6:
                TelaRemoverConta(lista_contas, 3);
                break;
            case 7:
                TelaAlteracaoConta(lista_contas);
                break;
            case 8:
                TelaConsultaContas(lista_contas);
                break;
            case 9:
                return;
            default:
                AlinharTextoNaPosicao(8, 24, "Digite uma opcao valida!");
                getch();
                AlinharTextoNaPosicao(8, 24, "                        ");
        }

        gotoxy(8, 24);
    }
}
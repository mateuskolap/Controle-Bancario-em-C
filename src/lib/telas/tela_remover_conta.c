/**
 * Autor......: Rian da Cruz
 * Data.......: 13/11/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: tela de remoção de contas
 */
#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void TelaRemoverConta(LinkedList *lista_contas, const int tipo_exclusao) {
    int posicao_conta, continuar_exclusao, confirma_exclusao;

    if (ListaContasEstaVazia(lista_contas)) {
        gotoxy(8, 24);
        printf("Nao ha nenhuma conta cadastrada.");
        getch();
        return;
    }
    
    while(1) {
        Moldura();
        CriarTitulo("TELA DE EXCLUSAO DE CONTAS");

        ExibirFormularioContas(4);

        bank_account *conta;

        if (tipo_exclusao == 1) {
            conta = lista_contas->head->content;
        } else if (tipo_exclusao == 2) {
            conta = lista_contas->tail->content;
        } else {
            while(1) {
                AlinharTextoNaPosicao(8, 24, "Digite a posicao: ");
                scanf("%d", &posicao_conta);

                if (posicao_conta < 0 || posicao_conta > lista_contas->size) {
                    AlinharTextoNaPosicao(8, 24, "                  ");
                    AlinharTextoNaPosicao(8, 24, "Digite uma posicao valida");
                    getch();
                    AlinharTextoNaPosicao(8, 24, "                         ");
                } else {
                    break;
                }
            }

            conta = ConsultarContaPosicao(lista_contas, posicao_conta);
        }

        if (conta->num_transacoes > 0){
            gotoxy(8, 24);
            printf("Conta com transações, impossivel excluir!");
            getch();
            return;
        }

        if (conta != NULL) {
            gotoxy(25, 6);
            printf("%d", conta->codigo_conta);
            gotoxy(25, 8);
            printf("%s", conta->banco);
            gotoxy(25, 10);
            printf("%s", conta->agencia);
            gotoxy(25, 12);
            printf("%s", conta->numero_conta);
            gotoxy(25, 14);
            printf("%s", conta->tipo_conta);
            gotoxy(25, 16);
            printf("%lf", conta->vl_saldo);
            gotoxy(25, 18);
            printf("%lf", conta->vl_limite);
            gotoxy(25, 20);
            printf("%s", conta->status);
        }

        while(1) {
            gotoxy(8, 24);
            printf("[1] Confirmar Exclusao [2] Voltar: ");
            scanf("%d", &confirma_exclusao);

            if (confirma_exclusao != 1 && confirma_exclusao != 2) {
                gotoxy(8,24);
                printf("                                                       ");
                gotoxy(8,24);
                printf("Digite uma opcao valida");
                getch();
                gotoxy(8,24);
                printf("                                                       ");
            } else if (confirma_exclusao == 1) {
                if (tipo_exclusao == 1) {
                    RemoverContaInicio(lista_contas);
                } else if (tipo_exclusao == 2) {
                    RemoverContaFinal(lista_contas);
                } else {
                    RemoverContaEm(lista_contas, posicao_conta);
                }

                AlinharTextoNaPosicao(8, 24, "Conta excluida com sucesso!");
                getch();
                AlinharTextoNaPosicao(8, 24, "                                               ");

                break;
            } else if (confirma_exclusao == 2) {
                break;
            }
        }

        gotoxy(8,24);
        printf("[1] Excluir Outra Conta [2] Voltar ao Menu Anterior: ");
        scanf("%d", &continuar_exclusao);

        if (continuar_exclusao != 1 && continuar_exclusao != 2) {
            gotoxy(8,24);
            printf("                                                        ");
            gotoxy(8,24);
            printf("Digite uma opcao valida");
            getch();
            gotoxy(8,24);
            printf("                                                         ");
        } else if (continuar_exclusao == 2) {
            break;
        }

    }
}
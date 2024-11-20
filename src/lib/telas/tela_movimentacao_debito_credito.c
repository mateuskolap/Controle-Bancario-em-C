#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void TelaMovimentacaoDebitoCredito(LinkedList *lista_contas, List *lista_transacoes) {

    while(1) {
        
        bank_transaction *transacao = (bank_transaction *) calloc(1, sizeof(bank_transaction));

        Moldura();
        CriarTitulo("CADASTRAR MOVIMENTACOES BANCARIAS"); 

        ExibirFormularioTransacao();

        while (1) {

            gotoxy(30, 7);
            printf("                                       ");
            gotoxy(30, 7);

            scanf("%d", &transacao->codigo_conta);

            if (transacao->codigo_conta < 0) {

                AlinharTextoNaPosicao(8 ,24, "Digite um codigo maior que 0!");
                getch();
                gotoxy(8, 24);
                printf("                                                   ");
                
                continue;

            } else if (ConsultarConta(lista_contas, transacao->codigo_conta) == NULL) {
             
                AlinharTextoNaPosicao(8 ,24, "Codigo nao existente, digite outro!");
                getch();
                gotoxy(8, 24);
                printf("                                                        ");
                
                continue; 
            
            }

            break;

        }

        free(transacao);
        transacao = NULL;

        getch();

    }
}
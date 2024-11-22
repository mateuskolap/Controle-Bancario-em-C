#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void TelaMovimentacaoDebitoCredito(LinkedList *lista_contas, List *lista_transacoes) {

    int aux = 0;
    int confirma = 0;
    int confirma2 = 0;

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
        
        bank_account *conta = ConsultarConta(lista_contas, transacao->codigo_conta);

        gotoxy(29, 8);
        printf("%s", conta->banco);
        gotoxy(29, 9);
        printf("%s", conta->agencia);
        gotoxy(29, 10);
        printf("%s", conta->numero_conta);
        gotoxy(29, 11);
        printf("%s", conta->tipo_conta);
        gotoxy(29, 12);
        printf("%.2lf", conta->vl_saldo);
        gotoxy(29, 13);
        printf("%.2lf", conta->vl_limite);
        gotoxy(29, 14);
        printf("%.2lf", conta->vl_saldo + conta->vl_limite);

        while(1){

            gotoxy(29,16);
            printf("                      ");
            gotoxy(29,16);
            fflush(stdin);
            fgets(transacao->data_movimento, sizeof(transacao->data_movimento), stdin);
            
            if(transacao->data_movimento[0] != '\n'){
                if(ValidarData(transacao->data_movimento)){
                    break;
                }else{
                    gotoxy(8, 24);
                    printf("digite uma data valida!");
                    getch();
                    gotoxy(8,24);
                    printf("                                          ");
                }
            }
        }

        while (1) {
            gotoxy(8,24);
            printf("[1]debito [2]credito:");
            gotoxy(29,17);
            scanf("%d", &aux);

            switch (aux)
            {
            case 1:
                strcpy(transacao->tp_movimentacao, "DEBITO");
                break;
            case 2:
                strcpy(transacao->tp_movimentacao, "CREDITO");
                break;
            default:
                gotoxy(8, 24);
                printf("Digite um valor valido!");
                getch();
                gotoxy(8, 24);
                printf("                                                      ");
            }

            if (aux >= 1 && aux <=2) {
                break;
            }
            
        }
        gotoxy(30,17);
        printf(" - %s", transacao->tp_movimentacao);

        while (1){
        
            gotoxy(29, 18);
            fflush(stdin);
            fgets(transacao->favorecido, sizeof(transacao->favorecido), stdin);   
            
            if(transacao->favorecido[0] != '\n'){
                break;
            }
        }

        double vl_limite_total = conta->vl_saldo + conta->vl_limite;

        while (1){
            gotoxy(29,19);
            printf("                                 ");
            gotoxy(29,19);
            scanf("%lf", &transacao->vl_movimento);

            if(transacao->vl_movimento <= 0 || transacao->vl_movimento > vl_limite_total){
                gotoxy(8, 24);
                printf("Digite um valor dentro do limite!");
                getch();
                gotoxy(8, 24);
                printf("                                 ");
            } else {
                break;
            }
        }
        

        gotoxy(29,20);
        if (aux == 1) {            
            printf("%.2lf", transacao->vl_saldo - transacao->vl_movimento);
        } else {
            printf("%.2lf", transacao->vl_saldo + transacao->vl_movimento);
        }
        
        while (1) {
            gotoxy(8,24);
            printf("[1] Confirmar transacao [2] Voltar: ");
            scanf("%d", &confirma);

            if (confirma != 1 && confirma != 2) {
                gotoxy(8, 24);
                printf("                                   ");
                gotoxy(8, 24);
                printf("Digite uma opcao valida!");
                getch();
                gotoxy(8, 24);
                printf("                       ");
            } else {
                AdicionarTransacao(lista_transacoes, lista_contas, transacao);   
                break;
            }
        }


        free(transacao);
        transacao = NULL;

        while (1) {
            gotoxy(8,24);
            printf("[1] Nova transacao [2] Voltar ao Menu de transacao: ");
            scanf("%d", &confirma2);

            if (confirma2 != 1 && confirma2 != 2) {
                gotoxy(8, 24);
                printf("                                   ");
                gotoxy(8, 24);
                printf("Digite uma opcao valida!");
                getch();
                gotoxy(8, 24);
                printf("                       ");
            } else {
                break;
            }
        }

        if (confirma2 == 2) {
            break;
        }
    }
}
#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void TelaCadastrarConta(LinkedList *lista_contas, int tipo_cadastro) {
    int confirma, confirma2, aux_conta, posicao;


    while (1) {
        bank_account *conta = (bank_account *) calloc(1, sizeof(bank_account));

        Moldura();
        CriarTitulo("TELA DE CONTAS BANCARIAS");

        ExibirFormularioContas(tipo_cadastro);

        while (1) {
            gotoxy(8, 24);
            printf("Digite 0 para sair:");
            gotoxy(26, 6);
            printf("                                       ");
            gotoxy(26, 6);


            scanf("%d", &conta->codigo_conta);

            if (conta->codigo_conta < 0) {
                AlinharTextoNaPosicao(8, 24, "Digite um codigo maior que 0!");
                getch();
                gotoxy(8, 24);
                printf("                                                   ");
            } else if (ConsultarConta(lista_contas, conta->codigo_conta) != NULL) {
                AlinharTextoNaPosicao(8, 24, "Codigo ja existente, digite outro!");
                getch();
                gotoxy(8, 24);
                printf("                                                        ");
            } else if (conta->codigo_conta == 0 ){
                return;
            }else{
                break;
            }
        }

        gotoxy(8, 24);
        printf("                                       ");

        while (1){
        
            gotoxy(26, 8);
            fflush(stdin);
            fgets(conta->banco, sizeof(conta->banco), stdin);   
            
            if (conta->banco[0] == '\n' || strcspn(conta->banco, " \t\n") == strlen(conta->banco)) {
                continue;
            } 

            break;

        }

        while (1){
        
            gotoxy(26, 10);
            fflush(stdin);
            fgets(conta->agencia, sizeof(conta->agencia), stdin);
            
            if (conta->agencia[0] == '\n' || strcspn(conta->agencia, " \t\n") == strlen(conta->agencia)) {
                continue;
            } 

            break;
        }

        while (1){
        
            gotoxy(26, 12);
            fflush(stdin);
            fgets(conta->numero_conta, sizeof(conta->numero_conta), stdin);   
            
            if (conta->numero_conta[0] == '\n' || strcspn(conta->numero_conta, " \t\n") == strlen(conta->numero_conta)) {
                continue;
            } 

            break;
        }
        
        while (1) {
            gotoxy(26, 14);
            printf("                                          "); 
            gotoxy(8, 24);
            printf("1=Corrente / 2=Poupanca / 3=Cartao Credito");
            gotoxy(26, 14);
            scanf("%d", &aux_conta);

            gotoxy(8, 24);
            printf("                                          ");

            switch (aux_conta) {
                case 1:
                    strcpy(conta->tipo_conta, "CORRENTE");
                    break;
                case 2:
                    strcpy(conta->tipo_conta, "POUPANCA");
                    break;
                case 3:
                    strcpy(conta->tipo_conta, "CREDITO");
                    break;
                default:
                    gotoxy(8, 24);
                    printf("Digite um valor valido!");
                    getch();
                    gotoxy(8, 24);
                    printf("                                                      ");
            }
            if(aux_conta >= 1 && aux_conta <= 3){
                break;
            }
        }
        gotoxy(28, 14);
        printf("- %s", conta->tipo_conta); // Exibindo o tipo de conta na frente
        
        while(1) {
            gotoxy(26, 16);
            printf("                                       ");
            gotoxy(26, 16);
            scanf("%lf", &conta->vl_saldo);

            if (conta->vl_saldo >= 0) {
                break;
            } else {
                gotoxy(8, 24);
                printf("Digite um valor maior que 0!");
                getch();
                gotoxy(8, 24);
                printf("                            ");
            }
        }

        while(1) {
            gotoxy(26, 18);
            printf("                                       ");
            gotoxy(26, 18);
            
            scanf("%lf", &conta->vl_limite);

            if (conta->vl_limite >= 0) {
                break;
            } else {
                gotoxy(8, 24);
                printf("Digite um valor maior que 0!");
                getch();
                gotoxy(8, 24);
                printf("                            ");
            }
        }

        if (tipo_cadastro == 3) {
            while (1) {
                gotoxy(26, 22);
                printf("                                       ");
                gotoxy(26, 22);
                scanf("%d", &posicao);

                if (posicao >= 0) {
                    break;
                } else {
                    gotoxy(8, 24);
                    printf("Digite um valor maior que 0!");
                    getch();
                    gotoxy(8, 24);
                    printf("                            ");
                }
            }
        }

        while (1) {
            AlinharTextoNaPosicao(8, 24, "[1] Confirmar Cadastro [2] Voltar: ");
            scanf("%d", &confirma);

            if (confirma != 1 && confirma != 2) {
                gotoxy(8, 24);
                printf("                                   ");
                gotoxy(8, 24);
                printf("Digite um valor valido!");
                getch();
                gotoxy(8, 24);
                printf("                       ");
            } else {
                break;
            }
        }

        if (confirma == 1) {
            if (tipo_cadastro == 1) {
                AdicionarContaFinal(lista_contas, conta);
            } else if (tipo_cadastro == 2) {
                AdicionarContaInicio(lista_contas, conta);
            } else {
                AdicionarContaEm(lista_contas, conta, posicao);
            }
            conta = NULL; // Apenas a nivel de informação: neste momento, o gerenciamento da memória da conta, passa a ser realizado pela lista
        }

        free(conta);
        conta = NULL;
        
        while (1) {
            AlinharTextoNaPosicao(8, 24, "[1] Novo Cadastro [2] Voltar ao Menu de Contas: ");
            scanf("%d", &confirma2);

            if (confirma2 != 1 && confirma2 != 2) {
                gotoxy(8, 24);
                printf("                                   ");
                gotoxy(8, 24);
                printf("Digite um valor valido!");
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
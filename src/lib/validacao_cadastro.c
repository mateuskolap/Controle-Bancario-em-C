/**
 * Autor......: Rian da Cruz
 * Data.......: 12/11/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * subfunção..: validações de cadastros
 */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include "../include/lista_contas.h"
#include "../include/screens.h"

void adicionar_conta(LinkedList *L, const int op) {

    int opc = 0;

    while (1) {

        bank_account conta;

        registration_query();

        while (1) {
            
            gotoxy(25,5);
            scanf("%d", conta.codigo_conta);

            if(ConsultarConta(L, conta.codigo_conta) != NULL || (conta.codigo_conta) < 0) {
                
                gotoxy(7,23);
                printf("escolha um codigo valido!");
                getch();

                gotoxy(7,23);
                printf("                         ");

            } else {
                break;
            } 
        }
        
        if (conta.codigo_conta == 0) {
            break;
        }
        
        gotoxy(25,7);
        fflush(stdin);
        fgets(conta.banco, sizeof(conta.banco), stdin);

        gotoxy(25,9);
        fflush(stdin);
        fgets(conta.agencia, sizeof(conta.agencia), stdin);

        gotoxy(25,11);
        fflush(stdin);
        fgets(conta.numero_conta, sizeof(conta.numero_conta), stdin);


        while (1) {

            int aux = 0;

            gotoxy(7,23);
            printf("1-corrente / 2-poupanca / 3-cartao credito:");
            scanf("%d", &aux);

            switch (aux)
            {
            case 1:
                strncpy(conta.tipo_conta, "corrente", sizeof(conta.tipo_conta) - 1);
                conta.tipo_conta[sizeof(conta.tipo_conta) - 1] = "\0";
                break;
            
            case 2:
                strncpy(conta.tipo_conta, "poupanca", sizeof(conta.tipo_conta) - 1);
                conta.tipo_conta[sizeof(conta.tipo_conta) - 1] = "\0";
                break;
            
            case 3:
                strncpy(conta.tipo_conta, "cartao credito", sizeof(conta.tipo_conta) - 1);
                conta.tipo_conta[sizeof(conta.tipo_conta) - 1] = "\0";
                break;

            default:
                gotoxy(7,23);
                printf("                                           ");
                gotoxy(7,23);
                printf("digite um tipo de conta valido!");
            }

            break;

        }
        gotoxy(7,23);
        printf("                                            ");


        gotoxy(25,13);
        printf("%s", conta.tipo_conta);
        

        while (1) {
            gotoxy(25,15);
            scanf("%lf", &conta.vl_saldo);

            if (conta.vl_saldo > 0) {
                break;
            } else {
                gotoxy(7,23);
                printf("escolha um valor maior ou igual a 0!");
                getch();

                gotoxy(7,23);
                printf("                                    ");
            }
        }

        while (1) {
            gotoxy(25,15);
            scanf("%lf", &conta.vl_limite);

            if (conta.vl_limite > 0) {
                break;
            } else {
                gotoxy(7,23);
                printf("escolha um valor maior ou igual a 0!");
                getch();

                gotoxy(7,23);
                printf("                                    ");
            }
        }


        gotoxy(25,19);
        fflush(stdin);
        fgets(conta.status, sizeof(conta.status), stdin);
    
    }

    gotoxy(7,23);
    printf("deseja salvar o cadastro? [1]sim / [2]nao:");
    scanf("%d", &opc);
    gotoxy(7,23);
    printf("                                          ");

    if (opc == 1);
    {
        if ()
    }
    
    


}
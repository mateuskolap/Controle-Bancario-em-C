/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Alterar a informação de alguma conta
 */

#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

/**
 * @brief Tela para alterar informações de uma conta bancária.
 *
 * @param lista_contas Lista encadeada contendo todas as contas cadastradas.
 */
void TelaAlteracaoConta(LinkedList *lista_contas) {

    int aux_alteracao = 0, codigo_conta = 0, aux_tipo_conta = 0, aux_satus_conta = 0, editar_outra_informacao = 0, editar_outra_conta = 0;
    
    while (1) {

        Moldura();
        CriarTitulo("ALTERAR INFORMACAO DE UMA CONTA");

        ExibirFormularioContas(4);

        AlinharTextoNaPosicao(8, 24, "'0' para voltar");

        // Validando o código inserido pelo usuário
        while (1) {

            // Limpando conteúdo do campo de inserção do código
            AlinharTextoNaPosicao(26, 6, "                                                      ");
            gotoxy(26, 6);

            scanf("%d", &codigo_conta);

            if (codigo_conta == 0) {
                return;

            } else if (codigo_conta < 0) {
                AlinharTextoNaPosicao(8, 24, "                                                 ");
                AlinharTextoNaPosicao(8, 24, "Digite um numero maior que 0!");
                getch();
                AlinharTextoNaPosicao(8, 24, "                                                 ");

                continue;
                
            } else if (ConsultarConta(lista_contas, codigo_conta) == NULL) {
                AlinharTextoNaPosicao(8, 24, "                                                 ");
                AlinharTextoNaPosicao(8, 24, "Insira uma conta existente!");
                getch();
                AlinharTextoNaPosicao(8, 24, "                                                    ");

                continue;
            }

            break;
        }

        // Obtendo a conta inserida pelo usuário
        bank_account *conta = ConsultarConta(lista_contas, codigo_conta);

        gotoxy(26, 8);
        printf("%s", conta->banco);
        gotoxy(26, 10);
        printf("%s", conta->agencia);
        gotoxy(26, 12);
        printf("%s", conta->numero_conta);
        gotoxy(26, 14);
        printf("%s", conta->tipo_conta);
        gotoxy(26, 16);
        printf("%.2lf", conta->vl_saldo);
        gotoxy(26, 18);
        printf("%.2lf", conta->vl_limite);
        gotoxy(26, 20);
        printf("%s", conta->status);

        while (1) {

            // Verificando a alteração que o usuário deseja alterar
            while (1) {
                AlinharTextoNaPosicao(8, 24, "                                                                ");
                AlinharTextoNaPosicao(8, 24, "Digite o codigo da informacao que deseja alterar: ");
                scanf("%d", &aux_alteracao);

                if (aux_alteracao == 0) {
                    return;
                } else if ((aux_alteracao < 1) || (aux_alteracao > 7 && aux_alteracao != 5)) {
                    AlinharTextoNaPosicao(8, 24, "                                                ");
                    AlinharTextoNaPosicao(8, 24, "Digite um valor valido!");
                    getch();
                    AlinharTextoNaPosicao(8, 24, "                                               ");

                    continue;
                } else if (aux_alteracao == 5) {
                    AlinharTextoNaPosicao(8, 24, "                                              ");
                    AlinharTextoNaPosicao(8, 24, "O saldo nao pode ser alterado!");
                    getch();
                    AlinharTextoNaPosicao(8, 24, "                                               ");

                    continue;
                }

                break;
            }

            if (aux_alteracao == 1) {
                // Validando o novo banco inserido pelo usuário
                while (1) {
                    AlinharTextoNaPosicao(26, 8, "                                              ");
                    gotoxy(26, 8);
                    
                    fflush(stdin);
                    fgets(conta->banco, sizeof(conta->banco), stdin);

                    if (conta->banco[0] == '\n' || strcspn(conta->banco, " \t\n") == strlen(conta->banco)) {
                        continue;
                    } 

                    break;
                }

            } else if (aux_alteracao == 2) {
                // Validando a nova agencia inserida
                while (1) {
                    AlinharTextoNaPosicao(26, 10, "                                                ");
                    gotoxy(26, 10); 
                    
                    fflush(stdin);
                    fgets(conta->agencia, sizeof(conta->agencia), stdin);

                    if (conta->agencia[0] == '\n' || strcspn(conta->agencia, " \t\n") == strlen(conta->agencia)) {
                        continue;
                    } 

                    break;
                }

            } else if (aux_alteracao == 3) {
                // Validando o novo numero da conta inserido
                while (1) {
                    AlinharTextoNaPosicao(26, 12, "                                            ");
                    gotoxy(26, 12);
                    
                    fflush(stdin);
                    fgets(conta->numero_conta, sizeof(conta->numero_conta), stdin);

                    if (conta->numero_conta[0] == '\n' || strcspn(conta->numero_conta, " \t\n") == strlen(conta->numero_conta)) {
                        continue;
                    } 

                    break;
                }

            } else if (aux_alteracao == 4) {
                // Validando o tipo de conta (corrente, poupança e cartão de crédito)
                while (1) {
                    gotoxy(26, 14);
                    printf("                                                     "); 
                    gotoxy(8, 24);
                    printf("                                           ");
                    gotoxy(8, 24);
                    printf("1=Corrente / 2=Poupanca / 3=Cartao Credito");
                    gotoxy(26, 14);
                    scanf("%d", &aux_tipo_conta);

                    gotoxy(8, 24);
                    printf("                                                    ");

                    switch (aux_tipo_conta) {
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
                            printf("                                                               ");
                    }
                    if(aux_tipo_conta >= 1 && aux_tipo_conta <= 3){
                        break;
                    }
                }
                gotoxy(28, 14);
                printf("- %s", conta->tipo_conta); // Exibindo o tipo de conta na frente

            } else if (aux_alteracao == 6) {

                while (1) {
                    AlinharTextoNaPosicao(26, 18, "                                               ");
                    gotoxy(26, 18);

                    scanf("%lf", &conta->vl_limite);

                    if (conta->vl_limite < 0) {
                        AlinharTextoNaPosicao(8, 24, "                                               ");
                        AlinharTextoNaPosicao(8, 24, "Digite um valor maior que 0!");
                        getch();
                        AlinharTextoNaPosicao(8, 24, "                                              ");

                        continue;
                    }

                    break;
                }
            } else if (aux_alteracao == 7) {
                // Validando o tipo de conta (corrente, poupança e cartão de crédito)
                while (1) {
                    gotoxy(26, 20);
                    printf("                                                   "); 
                    gotoxy(8, 24);
                    printf("                                                               ");
                    gotoxy(8, 24);
                    printf("1=ATIVA / 2=INATIVA");
                    gotoxy(26, 20);
                    scanf("%d", &aux_satus_conta);

                    gotoxy(8, 24);
                    printf("                                                     ");

                    switch (aux_satus_conta) {
                        case 1:
                            strcpy(conta->status, "ATIVA");
                            break;
                        case 2:
                            strcpy(conta->status, "INATIVA");
                            break;
                        default:
                            gotoxy(8, 24);
                            printf("Digite um valor valido!");
                            getch();
                            gotoxy(8, 24);
                            printf("                                                            ");
                    }
                    if(aux_satus_conta >= 1 && aux_satus_conta <= 3){
                        break;
                    }
                }
                gotoxy(28, 20);
                printf("- %s", conta->status); // Exibindo o tipo de conta na frente
            }
            
            while (1) {
                AlinharTextoNaPosicao(8, 24, "                                                         ");
                AlinharTextoNaPosicao(8, 24, "[1] Editar outra informacao [2] Voltar: ");

                scanf("%d", &editar_outra_informacao);

                if (editar_outra_informacao != 1 && editar_outra_informacao != 2) {
                    AlinharTextoNaPosicao(8, 24, "                                                         ");
                    AlinharTextoNaPosicao(8, 24, "Digite uma opcao valida!");
                    getch();
                    AlinharTextoNaPosicao(8, 24, "                                                    ");

                    continue;
                }

                break;
            }

            if (editar_outra_informacao == 1) {
                continue;
            }

            break;
        }

        while (1) {
            AlinharTextoNaPosicao(8, 24, "                                                       ");
            AlinharTextoNaPosicao(8, 24, "[1] Editar outra conta [2] Voltar: ");

            scanf("%d", &editar_outra_conta);

            if (editar_outra_conta != 1 && editar_outra_conta != 2) {
                AlinharTextoNaPosicao(8, 24, "                                               ");
                AlinharTextoNaPosicao(8, 24, "Digite uma opcao valida!");
                getch();
                AlinharTextoNaPosicao(8, 24, "                                                ");

                continue;
            }

            break;
        }

        if (editar_outra_conta == 1) {
            continue;
        }

        break;
    }
}

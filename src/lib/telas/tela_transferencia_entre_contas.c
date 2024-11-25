#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void TelaTransferenciaEntreContas(LinkedList *lista_contas, List *lista_transacoes) {

    int codigo_conta_origem, codigo_conta_destino, confirma_transferencia, nova_transferencia;
    double valor_transferencia;
    char data[12], aux_maior_data[12], ultima_data_origem[12], ultima_data_destino[12];

    while (1) {

        Moldura();
        CriarTitulo("TRANSFERENCIA ENTRE CONTAS");
        CriarTitulo("INSERIR TRANSFERENCIA BANCARIA");
        
        for (int i = 8; i < 18; i++) {
            EscreverNoCentro(i, "|");
        }

        for (int i = 2; i < 118; i++) {
            gotoxy(i, 7);
            printf("-");
            gotoxy(i, 18);
            printf("-");
        }

        AlinharTextoNaPosicao(1, 7, "+");
        AlinharTextoNaPosicao(59, 7, "+");
        AlinharTextoNaPosicao(118, 7, "+");
        AlinharTextoNaPosicao(59, 18, "+");

        EscreverNoCentroX1X2(2, 59, 7, "C O N T A  O R I G E M");
        EscreverNoCentroX1X2(59, 119, 7, "C O N T A  D E S T I N O");

        AlinharTextoNaPosicao(3, 9,  "Codigo Origem...: ");
        AlinharTextoNaPosicao(61, 9, "Codigo Destino..: ");

        ExibirFormularioTransferencia(3, 10);
        ExibirFormularioTransferencia(61, 10);
        
        AlinharTextoNaPosicao(3, 20, "Valor a Ser transferido.:");
        AlinharTextoNaPosicao(3, 21, "Data da Transferencia...:");

        // Validando o código de origem inserido pelo usuário
        while (1) {

            // Limpando conteúdo do campo de inserção do código
            AlinharTextoNaPosicao(21, 9, "                                     ");
            gotoxy(21, 9);

            scanf("%d", &codigo_conta_origem);

            if (codigo_conta_origem == 0) {
                return;

            } else if (codigo_conta_origem < 0) {
                AlinharTextoNaPosicao(8, 24, "                                                 ");
                AlinharTextoNaPosicao(8, 24, "Digite um numero maior que 0!");
                getch();
                AlinharTextoNaPosicao(8, 24, "                                                 ");

                continue;
                
            } else if (ConsultarConta(lista_contas, codigo_conta_origem) == NULL) {
                AlinharTextoNaPosicao(8, 24, "                                                 ");
                AlinharTextoNaPosicao(8, 24, "Insira uma conta existente!");
                getch();
                AlinharTextoNaPosicao(8, 24, "                                                    ");

                continue;
            }

            break;
        }

        bank_account *conta_origem = ConsultarConta(lista_contas, codigo_conta_origem);
        double saldo_limite_conta_origem = conta_origem->vl_saldo + conta_origem->vl_limite;

        if (strcmp(conta_origem->status, "INATIVO") == 0) {
            AlinharTextoNaPosicao(8, 24, "                                                 ");
            AlinharTextoNaPosicao(8, 24, "A conta esta inativa!");
            getch();
            AlinharTextoNaPosicao(8, 24, "                                                    ");

            return;
        }

        gotoxy(21, 10);
        printf("%s", conta_origem->banco);
        gotoxy(21, 11);
        printf("%s", conta_origem->agencia);
        gotoxy(21, 12);
        printf("%s", conta_origem->numero_conta);
        gotoxy(21, 13);
        printf("%.2lf", conta_origem->vl_saldo);
        gotoxy(21, 14);
        printf("%.2lf", conta_origem->vl_limite);
        gotoxy(21, 15);
        printf("%.2lf", saldo_limite_conta_origem);

        // Validando o código de destino inserido pelo usuário
        while (1) {

            // Limpando conteúdo do campo de inserção do código
            AlinharTextoNaPosicao(79, 9, "                                     ");
            gotoxy(79, 9);

            scanf("%d", &codigo_conta_destino);

            if (codigo_conta_destino == 0) {
                return;

            } else if (codigo_conta_destino < 0) {
                AlinharTextoNaPosicao(8, 24, "                                                 ");
                AlinharTextoNaPosicao(8, 24, "Digite um numero maior que 0!");
                getch();
                AlinharTextoNaPosicao(8, 24, "                                                 ");

                continue;
            } else if (codigo_conta_destino == codigo_conta_origem) {
                AlinharTextoNaPosicao(8, 24, "                                                   ");
                AlinharTextoNaPosicao(8, 24, "A conta destino não pode ser a mesma de origem!");
                getch();
                AlinharTextoNaPosicao(8, 24, "                                                   ");

                continue;
                
            } else if (ConsultarConta(lista_contas, codigo_conta_destino) == NULL) {
                AlinharTextoNaPosicao(8, 24, "                                                 ");
                AlinharTextoNaPosicao(8, 24, "Insira uma conta existente!");
                getch();
                AlinharTextoNaPosicao(8, 24, "                                                    ");

                continue;
            }

            break;
        }

        bank_account *conta_destino = ConsultarConta(lista_contas, codigo_conta_destino);
        double saldo_limite_conta_destino = conta_destino->vl_saldo + conta_destino->vl_limite;

        if (strcmp(conta_destino->status, "INATIVO") == 0) {
            AlinharTextoNaPosicao(8, 24, "                                                 ");
            AlinharTextoNaPosicao(8, 24, "A conta esta inativa!");
            getch();
            AlinharTextoNaPosicao(8, 24, "                                                    ");

            return;
        }

        gotoxy(79, 10);
        printf("%s", conta_destino->banco);
        gotoxy(79, 11);
        printf("%s", conta_destino->agencia);
        gotoxy(79, 12);
        printf("%s", conta_destino->numero_conta);
        gotoxy(79, 13);
        printf("%.2lf", conta_destino->vl_saldo);
        gotoxy(79, 14);
        printf("%.2lf", conta_destino->vl_limite);
        gotoxy(79, 15);
        printf("%.2lf", saldo_limite_conta_destino);

        // Validando o valor inserido pelo usuário
        while (1) {
            // Limpando conteúdo do campo de inserção do valor
            AlinharTextoNaPosicao(29, 20, "                                           ");
            gotoxy(29, 20);

            scanf("%lf", &valor_transferencia);

            if (valor_transferencia < 0) {
                AlinharTextoNaPosicao(8, 24, "                                                    ");
                AlinharTextoNaPosicao(8, 24, "Insira um valor maior que 0!");
                getch();
                AlinharTextoNaPosicao(8, 24, "                                                    ");

                continue;
            } else if (valor_transferencia > saldo_limite_conta_origem) {
                AlinharTextoNaPosicao(8, 24, "                                                    ");
                AlinharTextoNaPosicao(8, 24, "O valor inserido ultrapassa o credito disponivel!");
                getch();
                AlinharTextoNaPosicao(8, 24, "                                                    ");

                continue;
            }

            break;
        }

        // Validando a data inserida pelo usuário
        while (1) {
            AlinharTextoNaPosicao(29, 21, "                                           ");
            gotoxy(29, 21);

            fflush(stdin);
            fgets(data, sizeof(data), stdin);

            if (data[0] == '\n' || strcspn(data, " \t\n") == strlen(data)) {
                continue;
            } else if (ValidarData(data) == false) {
                AlinharTextoNaPosicao(8, 24, "                                                    ");
                AlinharTextoNaPosicao(8, 24, "Digite uma data valida!");
                getch();
                AlinharTextoNaPosicao(8, 24, "                                                    ");
                
                continue;
            } else {
                strcpy(ultima_data_origem, VerificarUltimaData(lista_transacoes, codigo_conta_origem));
                strcpy(ultima_data_destino, VerificarUltimaData(lista_transacoes, codigo_conta_destino));

                if ((InverterData(ultima_data_origem) > InverterData(ultima_data_destino))) {
                    strcpy(aux_maior_data, ultima_data_origem);
                } else {
                    strcpy(aux_maior_data, ultima_data_destino);
                }
                
                if (InverterData(data) < InverterData(aux_maior_data)) {
                    AlinharTextoNaPosicao(8, 24, "                                                    ");
                    gotoxy(8, 24);
                    printf("Digite uma data posterior ou igual a %s", aux_maior_data);
                    getch();
                    AlinharTextoNaPosicao(8, 24, "                                                    ");

                    continue;
                }

                break;

            }
        }

        gotoxy(21, 16);
        printf("%.2lf", conta_origem->vl_saldo - valor_transferencia);
        gotoxy(79, 16);
        printf("%.2lf", conta_destino->vl_saldo - valor_transferencia);

        while(1) {
            AlinharTextoNaPosicao(8, 24, "                                                    ");
            gotoxy(8, 24);
            printf("[1] Confirma a Transferencia [2] Retorna: ");
            scanf("%d", &confirma_transferencia);

            if (confirma_transferencia != 1 && confirma_transferencia != 2) {
                gotoxy(8,24);
                printf("                                                       ");
                gotoxy(8,24);
                printf("Digite uma opcao valida");
                getch();
                gotoxy(8,24);
                printf("                                                       ");
            } else if (confirma_transferencia == 1) {
                AdicionarTransferencia(lista_transacoes, lista_contas, conta_origem, conta_destino, valor_transferencia, data);

                AlinharTextoNaPosicao(8, 24, "                                                    ");
                AlinharTextoNaPosicao(8, 24, "Transferencia Realizada!");
                getch();
                AlinharTextoNaPosicao(8, 24, "                                                    ");

                break;
            } else if (confirma_transferencia == 2) {
                break;
            }
        }

        // Verificando se o usuário deseja realizar uma nova transferencia
        while(1) {
            AlinharTextoNaPosicao(8, 24, "                                                    ");
            gotoxy(8, 24);
            printf("[1] Nova Transferencia [2] Retorna: ");
            scanf("%d", &nova_transferencia);

            if (nova_transferencia != 1 && nova_transferencia != 2) {
                gotoxy(8,24);
                printf("                                                       ");
                gotoxy(8,24);
                printf("Digite uma opcao valida");
                getch();
                gotoxy(8,24);
                printf("                                                       ");
            } else if (nova_transferencia == 1) {
                continue;
            } else if (nova_transferencia == 2) {
                return;
            }
        }
    }
}
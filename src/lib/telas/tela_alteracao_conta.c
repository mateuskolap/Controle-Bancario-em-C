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
    int codigo_conta, continuar_consulta, opcao_alteracao, continuar_alteracao;
    char novo_banco[20];
    char nova_agencia[10];
    char novo_numero_conta[15];
    char novo_tipo_conta[20];
    double novo_limite;
    char novo_status[10];

    while (1) {       
        Moldura();
        CriarTitulo("ALTERAÇÃO DE INFORMACAO DA CONTA");
        ExibirFormularioContas(4);

        gotoxy(8, 24);
        printf("Pressione ESC para voltar");

        gotoxy(25, 6);

        char tecla = getch(); 
        if (tecla == 27) { 
            return; 
        }

        scanf("%d", &codigo_conta);
        bank_account *conta = ConsultarConta(lista_contas, codigo_conta);

        if (conta != NULL) {
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
        } else {
            gotoxy(8, 24);
            printf("O codigo informado nao existe");
            getch();
            continue;
        }

        while (1) {
            AlinharTextoNaPosicao(8, 24, "Digite uma opcao para alterar: ");
            scanf("%d", &opcao_alteracao);

            switch (opcao_alteracao) {
                case 1: // Alterar Banco
                    AlinharTextoNaPosicao(25, 8, "                               ");
                    gotoxy(25, 8);
                    fflush(stdin);
                    fgets(novo_banco, sizeof(novo_banco), stdin);

                    AlterarInformacao(conta, 1, novo_banco);
                    break;

                case 2: // Alterar Agência
                    AlinharTextoNaPosicao(25, 10, "                               ");
                    gotoxy(25, 10);
                    fflush(stdin);
                    fgets(nova_agencia, sizeof(nova_agencia), stdin);

                    AlterarInformacao(conta, 2, nova_agencia);
                    break;

                case 3: // Alterar Número da Conta
                    AlinharTextoNaPosicao(25, 12, "                               ");
                    gotoxy(25, 12);
                    fflush(stdin);
                    fgets(novo_numero_conta, sizeof(novo_numero_conta), stdin);

                    AlterarInformacao(conta, 3, novo_numero_conta);
                    break;

                case 4: // Alterar Tipo da Conta
                    AlinharTextoNaPosicao(25, 14, "                               ");
                    gotoxy(25, 14);
                    fflush(stdin);
                    fgets(novo_tipo_conta, sizeof(novo_tipo_conta), stdin);

                    AlterarInformacao(conta, 4, novo_tipo_conta);
                    break;

                case 5: // Tentativa de Alterar Saldo
                    AlinharTextoNaPosicao(8, 24, "Alteracao de saldo nao permitida!");
                    getch();
                    break;

                case 6: // Alterar Limite
                    AlinharTextoNaPosicao(25, 18, "                               ");
                    gotoxy(25, 18);
                    scanf("%lf", &novo_limite);

                    AlterarInformacao(conta, 6, &novo_limite);
                    break;

                case 7: // Alterar Status
                    AlinharTextoNaPosicao(25, 20, "                               ");
                    gotoxy(25, 20);
                    fflush(stdin);
                    fgets(novo_status, sizeof(novo_status), stdin);

                    AlterarInformacao(conta, 7, novo_status);
                    break;

                default: // Opção inválida
                    AlinharTextoNaPosicao(8, 24, "Opcao invalida! Tente novamente.");
                    getch();
                    continue;
            }

            AlinharTextoNaPosicao(8, 24, "                                         ");
            AlinharTextoNaPosicao(8, 24, "Informacao alterada com sucesso!");
            getch();
            
            AlinharTextoNaPosicao(8, 24, "[1] Alterar outra informacao [2] Voltar");
            scanf("%d", &continuar_alteracao);

            if (continuar_alteracao != 1 && continuar_alteracao != 2) {
                gotoxy(8,24);
                printf("                                                       ");
                gotoxy(8,24);
                printf("Digite uma opcao valida");
                getch();
                gotoxy(8,24);
                printf("                                                       ");
            } else if (continuar_alteracao == 2) {
                break;
            }
        }

        gotoxy(8,24);
        printf("[1] Consultar Outra Conta [2] Voltar ao Menu Anterior: ");
        scanf("%d", &continuar_consulta);
        
        if (continuar_consulta != 1 && continuar_consulta != 2) {
            gotoxy(8,24);
            printf("                                                       ");
            gotoxy(8,24);
            printf("Digite uma opcao valida");
            getch();
            gotoxy(8,24);
            printf("                                                       ");
        } else if (continuar_consulta == 2) {
            break;
        }
    }
}

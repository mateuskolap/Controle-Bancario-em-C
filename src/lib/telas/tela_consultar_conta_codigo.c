#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void TelaConsultarContaCodigo(LinkedList *lista_contas) {
    int codigo_conta, continuar_consulta;

    while (1) {       
        Moldura();
        CriarTitulo("CONSULTA DE CONTAS POR CODIGO");
        ExibirFormularioContas(4);

        gotoxy(8, 24);
        printf("Pressione 0 para voltar");

        gotoxy(25, 6);



        scanf("%d", &codigo_conta);
        
        if (codigo_conta == 0) {
            break;
        }
        

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
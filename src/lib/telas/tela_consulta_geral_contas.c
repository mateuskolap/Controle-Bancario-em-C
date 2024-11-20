#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void TelaConsultaGeralContas(LinkedList *lista_contas) {

    if (ListaContasEstaVazia(lista_contas)) {
        gotoxy(8, 24);
        printf("Nao ha nenhuma conta cadastrada.");
        getch();
        return;
    }

    SNode *current = lista_contas->head;

    while (current != NULL) {
        Moldura();
        CriarTitulo("CONSULTA GERAL DE CONTAS");
        ExibirFormularioContas(4);

        gotoxy(25, 6);
        printf("%d", current->content->codigo_conta);
        gotoxy(25, 8);
        printf("%s", current->content->banco);
        gotoxy(25, 10);
        printf("%s", current->content->agencia);
        gotoxy(25, 12);
        printf("%s", current->content->numero_conta);
        gotoxy(25, 14);
        printf("%s", current->content->tipo_conta);
        gotoxy(25, 16);
        printf("%lf", current->content->vl_saldo);
        gotoxy(25, 18);
        printf("%lf", current->content->vl_limite);
        gotoxy(25, 20);
        printf("%s", current->content->status);

        gotoxy(8, 24);
        printf("Pressione qualquer tecla para continuar...");
        getch();
        current = current->next;
    }
}
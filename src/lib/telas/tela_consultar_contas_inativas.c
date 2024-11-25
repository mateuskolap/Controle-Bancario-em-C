#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

// Função para consultar lista de contas por ordem
void TelaConsultarContasInativas(LinkedList *lista_contas) {
    if (ListaContasEstaVazia(lista_contas)) {
        gotoxy(8, 24);
        printf("Nao ha nenhuma conta cadastrada.");
        getch();
        return;
    }

    int linhas_pagina = 13, numero_pagina = 1, opcao;

    while (1) {
        // Desenha moldura e título da tela
        Moldura();

        // Cabeçalho ajustado com alinhamento manual
        gotoxy(3, 6);
        printf("Cod");
        gotoxy(8, 6);
        printf("Banco");
        gotoxy(35, 6);
        printf("Agencia");
        gotoxy(47, 6);
        printf("Conta");
        gotoxy(58, 6);
        printf("Tipo Conta");
        gotoxy(72, 6);
        printf("Saldo");
        gotoxy(85, 6);
        printf("Limite");
        gotoxy(98, 6);
        printf("Status");
        gotoxy(107, 6);
        printf("Transacoes");

        // Cálculo do início da página
        int inicio = (numero_pagina - 1) * linhas_pagina;
        int contagem = 0;

        // Itera pelos elementos da lista e exibe os registros da página atual
        SNode *current = lista_contas->head;
        for (int i = 0; current != NULL && i < inicio + linhas_pagina; i++) {
            if (strcmp(current->content->status, "INATIVA") == 0) {
                if (i >= inicio) {
                    contagem++;

                    int linha_atual = 7 + contagem;
                    gotoxy(4, linha_atual);
                    printf("%d", current->content->codigo_conta);
                    gotoxy(8, linha_atual);
                    printf("%s", current->content->banco);
                    gotoxy(35, linha_atual);
                    printf("%s", current->content->agencia);
                    gotoxy(47, linha_atual);
                    printf("%s", current->content->numero_conta);
                    gotoxy(58, linha_atual);
                    printf("%s", current->content->tipo_conta);
                    gotoxy(72, linha_atual);
                    printf("%.2f", current->content->vl_saldo);
                    gotoxy(85, linha_atual);
                    printf("%.2f", current->content->vl_limite);
                    gotoxy(98, linha_atual);
                    printf("%s", current->content->status);
                    gotoxy(107, linha_atual);
                    printf("%d", current->content->num_transacoes);
                    
                }
            }
            current = current->next; // Avança para o próximo nó
        }

        // Opções de navegação entre páginas
        gotoxy(8, 24);
        printf("Pagina %d de %d ([0] Sair, [1] Anterior, [2] Proxima): ", 
               numero_pagina, (lista_contas->size + linhas_pagina - 1) / linhas_pagina);
        scanf("%d", &opcao);

        if (opcao == 1 && numero_pagina > 1) { 
            numero_pagina--; // Vai para a página anterior
        } else if (opcao == 2 && inicio + linhas_pagina < lista_contas->size) { 
            numero_pagina++; // Vai para a próxima página
        } else if (opcao == 0) {
            return;
        }
    }
}

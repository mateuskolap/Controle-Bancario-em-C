/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Consultar transações bancárias por ordenação
 */

#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

// Função para consultar lista de transações por ordem
void TelaConsultarTransacoes(LinkedList *lista_contas, List *lista_transacoes) {

    int linhas_pagina = 13, numero_pagina = 1, opcao, codigo_conta;

    while (1) {

        // Desenha moldura e título da tela
        Moldura();

        for (int i = 2; i < 118; i++) {
            gotoxy(i, 6);
            printf("-");
        }

        AlinharTextoNaPosicao(3, 5, "Digite o codigo da conta: ");

        while (1) {

            // Limpando conteúdo do campo de inserção do código
            AlinharTextoNaPosicao(30, 5, "                                     ");
            gotoxy(30, 5);

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

        // Cabeçalho ajustado com alinhamento manual
        gotoxy(3, 8);
        printf("Seq");
        gotoxy(8, 8);
        printf("Banco");
        gotoxy(15, 8);
        printf("Data");
        gotoxy(27, 8);
        printf("Tipo");
        gotoxy(37, 8);
        printf("Favorecido");
        gotoxy(85, 8);
        printf("Valor");
        gotoxy(100, 8);
        printf("Saldo");

        // Cálculo do início da página
        int inicio = (numero_pagina - 1) * linhas_pagina;
        int contagem = 0;

        // Itera pelos elementos da lista e exibe os registros da página atual
        DNode *current = lista_transacoes->head;
        for (int i = 0; current != NULL && i < inicio + linhas_pagina; i++) {
            if (current->content->codigo_conta == codigo_conta) {
                if (i >= inicio) {
                    contagem++;

                    int linha_atual = 9 + contagem;
                    gotoxy(3, linha_atual);
                    printf("%d", current->content->sequencial);
                    gotoxy(8, linha_atual);
                    printf("%d", current->content->codigo_conta);
                    gotoxy(15, linha_atual);
                    printf("%s", current->content->data_movimento);
                    gotoxy(27, linha_atual);
                    printf("%s", current->content->tp_movimentacao);
                    gotoxy(37, linha_atual);
                    printf("%s", current->content->favorecido);
                    gotoxy(85, linha_atual);
                    printf("%.2f", current->content->vl_movimento);
                    gotoxy(100, linha_atual);
                    printf("%.2f", current->content->vl_saldo);

                }
            }
            current = current->next; // Avança para o próximo nó
        }

        // Opções de navegação entre páginas
        gotoxy(8, 24);
        printf("Pagina %d de %d ([0] Sair, [1] Anterior, [2] Proxima): ", 
               numero_pagina, (lista_transacoes->size + linhas_pagina - 1) / linhas_pagina);
        scanf("%d", &opcao);

        if (opcao == 1 && numero_pagina > 1) { 
            numero_pagina--; // Vai para a página anterior
        } else if (opcao == 2 && inicio + linhas_pagina < lista_transacoes->size) { 
            numero_pagina++; // Vai para a próxima página
        } else if (opcao == 0) {
            return;
        }
    }
}

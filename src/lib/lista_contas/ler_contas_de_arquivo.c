/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Ler as contas de um arquivo
 */


#include "../../include/funcoes.h"
#include <stdio.h>
#include <stdlib.h>

void LerContasDeArquivo(LinkedList *L) {
    FILE *file = fopen("../database/lista_contas.dat", "rb");

    if (file == NULL) {
        return;
    }

    bank_account conta;
    while (fread(&conta, sizeof(bank_account), 1, file) == 1) {
        SNode *novoNode = (SNode *) calloc(1, sizeof(SNode));
        if (novoNode == NULL) {
            fclose(file);
            return;
        }

        novoNode->content = (bank_account *) malloc(sizeof(bank_account));
        if (novoNode->content == NULL) {
            fclose(file);
            return;
        }

        novoNode->next = NULL;

        if (L->head == NULL) {
            L->head = novoNode;
            L->tail = novoNode;
        } else {
            L->tail->next = novoNode;
            L->tail = novoNode;
        }
    }

    fclose(file);
}
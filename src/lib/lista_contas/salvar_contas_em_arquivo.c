/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Salvar a lista de contas em um arquivo binário
 */


#include "../../include/funcoes.h"
#include <stdio.h>
#include <stdlib.h>

void SalvarContasEmArquivo(LinkedList *L) {
    FILE *file = fopen("../database/lista_contas.dat", "wb");

    if (file == NULL) {
        return;
    }
    
    SNode *current = L->head;
    while (current != NULL) {
        fwrite(current->content, sizeof(bank_account), 1, file);
        current = current->next;
    }
    
    fclose(file);
}
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
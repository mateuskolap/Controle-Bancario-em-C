#include "../../include/funcoes.h"
#include <stdlib.h>

char *VerificarUltimaData(List *lista_transacoes, const int codigo_conta) {
    DNode *current = lista_transacoes->tail;

    while (current != NULL) {
        if (current->content->codigo_conta == codigo_conta) {
            return current->content->data_movimento;
        }
        current = current->previous;
    }

    return "0";
}
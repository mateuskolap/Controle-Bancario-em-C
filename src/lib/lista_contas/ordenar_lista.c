#include "../../include/funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void OrdenarLista(LinkedList *lista_contas, const int tipo_ordenacao) {
    int swapped;
    SNode *current;
    SNode *previous = NULL;

    do {
        swapped = 0;
        current = lista_contas->head;

        while (current->next != previous) {
            if (tipo_ordenacao == 1) {
                if (strcmp(current->content->banco, current->next->content->banco) > 0) {
                    void *aux = current->content;
                    current->content = current->next->content;
                    current->next->content = aux;
                    swapped = 1;
                }
            } else if (tipo_ordenacao == 2) {
                if (current->content->codigo_conta > current->next->content->codigo_conta) {
                    void *aux = current->content;
                    current->content = current->next->content;
                    current->next->content = aux;
                    swapped = 1;
                }
            } 
            current = current->next;

        }
        previous = current;

    } while (swapped);
}
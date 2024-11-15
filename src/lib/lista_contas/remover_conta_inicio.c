#include "../../include/funcoes.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Remove o primeiro nó da lista de contas.
 * 
 * A função remove o nó da cabeça da lista, ajustando o ponteiro `head` para o próximo nó.
 * Se a lista contiver apenas um nó, o ponteiro `tail` também será ajustado para `NULL`.
 * O nó removido é desalocado e o tamanho da lista é decrementado.
 * 
 * @param L Ponteiro para a lista de contas (`LinkedList`).
 * 
 * @note A função verifica se a lista está vazia antes de tentar realizar a remoção. 
 *       Caso contrário, a remoção é realizada e o tamanho da lista é atualizado.
 */
void RemoverContaInicio(LinkedList *L) {
    // Retorna um erro se a lista estiver vazia
    if (ListaContasEstaVazia(L)) {
        fprintf(stderr, "ERROR in 'RemoverContaInicio': The list is already empty.\n");
        return;
    }

    // Nó temporário que auxiliará na remoção do primeiro elemento
    SNode *temp = L->head;

    // Se a lista possuir somente um elemento
    if (L->head == L->tail) {
        L->tail = NULL;
    }

    // A cabeça da lista passa a apontar para o segundo elemento
    L->head = L->head->next;
    ExcluirConta(&temp); // O primeiro nó é desalocado

    L->size--; // Decrementa o tamanho da lista
}
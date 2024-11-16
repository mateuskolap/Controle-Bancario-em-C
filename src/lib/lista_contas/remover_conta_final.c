/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Remover uma conta do final da lista
 */

#include "../../include/funcoes.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Remove o último nó da lista de contas.
 * 
 * A função remove o nó final da lista, ajustando o ponteiro `tail` para o nó anterior.
 * Se a lista contiver apenas um nó, o ponteiro `head` também será ajustado para `NULL`.
 * O nó removido é desalocado e o tamanho da lista é decrementado.
 * 
 * @param L Ponteiro para a lista de contas (`LinkedList`).
 * 
 * @note A função verifica se a lista está vazia antes de tentar realizar a remoção. 
 *       Caso contrário, a remoção é realizada e o tamanho da lista é atualizado.
 */
void RemoverContaFinal(LinkedList *L) {
    // Retorna um erro se a lista estiver vazia
    if (ListaContasEstaVazia(L)) {
        fprintf(stderr, "ERROR in 'RemoverContaFinal': The list is already empty.\n");
        return;
    }

    // Nós temporário que auxiliará na remoção do primeiro elemento  
    SNode *current = L->head;
    SNode *previous = NULL;

    // Caso especial para caso a lista possuir apenas um elemento
    if (L->head == L->tail) {
        L->head = NULL;
        L->tail = NULL;
    } else {
        while (current->next != NULL) {
            previous = current;
            current = current->next;
        }

        previous->next = NULL;
        L->tail = previous;
    }

    ExcluirConta(&current);

    L->size--;
}
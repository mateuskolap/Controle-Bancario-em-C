#include "../../include/funcoes.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Remove uma conta bancária em uma posição específica da lista.
 * 
 * A função remove um nó da lista de contas na posição indicada pelo parâmetro `position`.
 * Se a posição for a primeira, a função `RemoverContaInicio` é chamada. Caso contrário, o nó desejado
 * é removido após percorrer a lista. A função também cuida da atualização do ponteiro para a cauda da lista
 * e do ajuste do tamanho da lista.
 * 
 * @param L Ponteiro para a lista de contas (`LinkedList`).
 * @param position A posição do nó (conta) a ser removido na lista. O índice é baseado em 1.
 * 
 * @note A função verifica se a lista está vazia ou se a posição fornecida está fora dos limites válidos
 *       antes de proceder com a remoção. Se a posição for inválida, a função exibe uma mensagem de erro.
 */
void RemoverContaEm(LinkedList *L, int position) {
    // Retorna um erro se a lista estiver vazia
    if (ListaContasEstaVazia(L)) {
        fprintf(stderr, "ERROR in 'RemoverContaEm': The list is already empty.\n");
        return;
    }

    // Verificando se a posição desejada existe.
    if ((position < 1) || (position > L->size)) {
        fprintf(stderr, "ERROR in 'RemoverContaEm'\n");
        fprintf(stderr, "Position [%d] is out of bounds: [1, %d]\n", position, L->size);
        return;
    }

    // Se for a primeira posição
    if (position == 1) {
        RemoverContaInicio(L);
        return;
    }

    // Auxiliares para remoção
    SNode *current = L->head;
    SNode *previous = NULL;

    // Encontra o nó desejado para remover, e o anterior
    for (int count = 1; (current != NULL) && (count < position); count++) {
        previous = current;
        current = current->next;
    }

    // O próximo nó do anterior, será o próximo nó do atual
    previous->next = current->next;

    // Se a remoção for na cauda
    if (current == L->tail) {
        L->tail = previous;
    }
    
    // O nó é desalocado
    ExcluirConta(&current);

    L->size--; // Decrementa o tamanho da lista
}
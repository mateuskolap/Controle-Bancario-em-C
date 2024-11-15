#include "../../include/funcoes.h"
#include <stdlib.h>

/**
 * @brief Cria uma nova lista de contas bancárias e inicializa suas propriedades.
 * 
 * A função aloca dinamicamente memória para uma nova lista (`LinkedList`) e inicializa seus campos:
 * - `head` é configurado como `NULL`, indicando que a lista está vazia;
 * - `tail` também é configurado como `NULL`, já que não há elementos na lista;
 * - `size` é inicializado como 0, já que a lista começa sem elementos.
 * 
 * A função retorna o ponteiro para a nova lista de contas criada.
 * 
 * @return Ponteiro para a nova lista de contas (`LinkedList`). Caso a alocação de memória falhe, a função
 *         retornará `NULL`.
 */
LinkedList *CriarListaContas() {
    // Aloca um espaço na memória heap para armazenar um novo nó
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));

    L->head = NULL;
    L->tail = NULL;
    L->size = 0;

    return L;
}
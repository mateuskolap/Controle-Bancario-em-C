/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Criar uma lista de transações
 */

#include "../../include/funcoes.h"
#include <stdlib.h>

/**
 * @brief Cria uma nova lista de transações e inicializa suas propriedades.
 * 
 * A função aloca dinamicamente memória para uma nova lista duplamente encadeada (`List`) e
 * inicializa seus campos:
 * - `head` é configurado como `NULL`, indicando que a lista está vazia;
 * - `tail` também é configurado como `NULL`, já que não há elementos na lista;
 * - `size` é inicializado como 0, pois a lista começa sem elementos.
 * 
 * A função retorna o ponteiro para a nova lista de transações criada.
 * 
 * @return Ponteiro para a nova lista de transações (`List`). Caso a alocação de memória falhe, 
 *         a função retornará `NULL`.
 */
List *CriarListaTransacoes() {
    List *L = (List *) calloc(1, sizeof(List));

    L->head = NULL;
    L->tail = NULL;
    L->size = 0;

    return L;
}
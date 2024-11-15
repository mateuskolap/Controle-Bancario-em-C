/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Verificar se a lista de contas está vazia
 */


#include "../../include/funcoes.h"
#include <stdbool.h>

/**
 * @brief Verifica se a lista de contas está vazia.
 * 
 * A função retorna um valor booleano que indica se a lista contém ou não elementos. 
 * Se o tamanho da lista (`size`) for igual a 0, a lista é considerada vazia, e a função retorna `true`.
 * Caso contrário, retorna `false`.
 * 
 * @param L Ponteiro para a lista de contas (`LinkedList`).
 * 
 * @return `true` se a lista estiver vazia, `false` caso contrário.
 */

bool ListaContasEstaVazia(const LinkedList *L) {
    return L->size == 0;
}
#include "../../include/funcoes.h"
#include <stdbool.h>

/**
 * @brief Verifica se a lista está vazia
 * @param L_ref: Endereço de memória da lista
 */
bool ListaTransacoesEstaVazia(const List *L) {
    return L->size == 0;
}
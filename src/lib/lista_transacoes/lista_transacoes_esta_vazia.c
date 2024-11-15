/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Verificar se a lista de transacoes está vazia
 */


#include "../../include/funcoes.h"
#include <stdbool.h>

/**
 * @brief Verifica se a lista está vazia
 * @param L_ref: Endereço de memória da lista
 */
bool ListaTransacoesEstaVazia(const List *L) {
    return L->size == 0;
}
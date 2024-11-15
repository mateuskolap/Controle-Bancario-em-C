/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Consultar uma conta
 */

#include "../../include/funcoes.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Consulta uma conta bancária na lista de contas.
 * 
 * A função percorre a lista de contas bancárias e busca uma conta com o código especificado.
 * Se a conta for encontrada, o ponteiro para a estrutura da conta é retornado.
 * Caso contrário, a função retorna `NULL` para indicar que a conta não foi encontrada.
 * 
 * @param L Ponteiro para a lista de contas (do tipo `LinkedList`).
 * @param codigo_conta O código da conta a ser buscada.
 * 
 * @return Ponteiro para a estrutura `bank_account` correspondente ao código da conta, 
 *         ou `NULL` se a conta não for encontrada.
 * 
 * @note A função emite uma mensagem de erro caso a lista esteja vazia.
 */
bank_account *ConsultarConta(LinkedList *L, const int codigo_conta) {
    // Retorna um erro se a lista estiver vazia
    if (ListaContasEstaVazia(L)) {
        fprintf(stderr, "ERROR in 'ConsultarConta': The list is already empty.\n");
        return NULL;
    }

    SNode *aux = L->head;

    while (aux != NULL) {
        if (aux->content->codigo_conta == codigo_conta) {
            return aux->content; // Conta encontrada, retorna o conteúdo
        }
        aux = aux->next;
    }

    return NULL; // Conta não encontrada, retorna NULL (vazio)
}
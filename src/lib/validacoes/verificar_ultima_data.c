/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Verifica a última data de transação de uma conta
 */

#include "../../include/funcoes.h"
#include <stdlib.h>

char *VerificarUltimaData(List *lista_transacoes, const int codigo_conta) {
    DNode *current = lista_transacoes->tail;

    while (current != NULL) {
        if (current->content->codigo_conta == codigo_conta) {
            return current->content->data_movimento;
        }
        current = current->previous;
    }

    return "0";
}
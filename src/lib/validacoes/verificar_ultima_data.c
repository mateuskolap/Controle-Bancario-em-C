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
    // Ponteiro que percorrerá toda a lista até encontrar o valor especificado
    DNode *current = lista_transacoes->tail;

    // Enquanto current não chegar ao final da lista
    while (current != NULL) {
        // Verifica se a transação para a qual current está apontando no momento contém o código da conta especificada
        if (current->content->codigo_conta == codigo_conta) {
            return current->content->data_movimento; // Se sim, quebra a função aqui
        }
        current = current->previous; // Se não, continua até encontrar
    }

    return "0"; // Não encontrado nenhum valor, retorna 0 (para possibilitar a inserção de qualquer data)
}
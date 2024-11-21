/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Excluir uma conta
 */

#include "../../include/funcoes.h"
#include <stdlib.h>

/**
 * @brief Exclui o nó da lista de transacoes e desaloca sua memória.
 * 
 * A função remove o nó apontado por `dnode_ref` e desaloca tanto o conteúdo da transacao bancária (armazenado no campo `content`)
 * quanto o próprio nó da lista. Após a liberação de memória, o ponteiro que referencia o nó é setado como `NULL`, 
 * garantindo que o ponteiro que chamou a função não aponte para uma área de memória já liberada.
 * 
 * @param dnode_ref Ponteiro duplo para o nó (`DNode`). Esse ponteiro é utilizado para liberar a memória do nó
 *                  e garantir que o ponteiro original seja atualizado para `NULL`.
 */
void ExcluirTransacao(DNode **dnode_ref) {
    // Auxiliar para acessar o conteúdo da conta
    DNode *dnode = *dnode_ref;

    free(dnode->content); // Liberando o conteúdo do nó
    free(dnode); // Liberando o nó

    *dnode_ref = NULL;
}
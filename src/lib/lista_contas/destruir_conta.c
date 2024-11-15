#include "../../include/funcoes.h"
#include <stdlib.h>

/**
 * @brief Exclui o nó da lista de contas e desaloca sua memória.
 * 
 * A função remove o nó apontado por `snode_ref` e desaloca tanto o conteúdo da conta bancária (armazenado no campo `content`)
 * quanto o próprio nó da lista. Após a liberação de memória, o ponteiro que referencia o nó é setado como `NULL`, 
 * garantindo que o ponteiro que chamou a função não aponte para uma área de memória já liberada.
 * 
 * @param snode_ref Ponteiro duplo para o nó (`SNode`). Esse ponteiro é utilizado para liberar a memória do nó
 *                  e garantir que o ponteiro original seja atualizado para `NULL`.
 * 
 * @note A função presume que a memória alocada para o conteúdo da conta bancária e para o nó da lista foi alocada
 *       dinamicamente e deve ser liberada adequadamente. A destruição da lista de transações da conta deve ser implementada.
 */
void ExcluirConta(SNode **snode_ref) {
    // Auxiliar para acessar o conteúdo da conta
    SNode *snode = *snode_ref;

    free(snode->content); // Liberando o conteúdo do nó
    free(snode); // Liberando o nó

    *snode_ref = NULL;
}
#include "../../include/funcoes.h"
#include <stdlib.h>

/**
 * @brief Exclui completamente a lista de contas e desaloca sua memória.
 * 
 * A função percorre todos os nós da lista de contas, removendo cada um deles e desalocando a memória associada.
 * Após a remoção de todos os nós, a memória da própria lista é liberada. O ponteiro para a lista é setado como `NULL`
 * para garantir que a referência seja perdida após a exclusão. 
 * 
 * @param L_ref Ponteiro duplo para a lista de contas (`LinkedList`). Esse ponteiro é utilizado para liberar a memória da estrutura da lista.
 * 
 * @note Após o uso dessa função, o ponteiro para a lista (`L_ref`) deverá ser considerado inválido,
 *       pois a memória foi liberada e o ponteiro é setado como `NULL`.
 */
void ExcluirListaContas(LinkedList **L_ref) {
    // Auxiliar para acessar o conteúdo da lista
    LinkedList *L = *L_ref;

    // Ponteiros auxiliares para a remoção
    SNode *current = L->head;
    SNode *aux = NULL;

    // Repetição para abranger todos os nós da lista
    while (current != NULL) {
        aux = current;
        current = current->next;

        ExcluirConta(&aux);
    }

    free(L); // Desaloca a lista
    L_ref = NULL;
}
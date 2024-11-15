#include "../../include/funcoes.h"
#include <stdlib.h>

/**
 * @brief Adiciona uma nova conta bancária no início da lista.
 * 
 * A função cria um novo nó com os dados da conta fornecida e insere esse nó no início da lista de contas.
 * O ponteiro `next` do novo nó será ajustado para apontar para o nó atualmente na cabeça da lista.
 * Se a lista estiver vazia, o novo nó será atribuído ao ponteiro `tail`, já que ele será o único nó da lista.
 * O ponteiro `head` é atualizado para o novo nó, tornando-o o primeiro da lista.
 * 
 * @param L Ponteiro para a lista de contas (`LinkedList`).
 * @param content Ponteiro para a estrutura `bank_account` que contém os dados da conta a ser adicionada.
 * 
 * @note A função garante que, se a lista estiver vazia, o ponteiro `tail` seja corretamente atualizado,
 *       e que o ponteiro `head` sempre aponte para o novo nó inserido.
 */
void AdicionarContaInicio(LinkedList *L, bank_account *content) {
    // Cria um novo nó com o conteúdo desejado
    SNode *p = CriarConta(content);

    p->next = L->head; // O ponteiro próximo do novo nó apontará para o primeiro nó da lista

    // Verifica se a lista está vazia
    if (ListaContasEstaVazia(L)) {
        L->tail = p;
    } 

    L->head = p; // A cabeça da lista será alterada para guardar o novo nó   

    L->size++; 
}
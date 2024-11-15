#include "../../include/funcoes.h"
#include <stdlib.h>

/**
 * @brief Adiciona uma nova conta bancária no final da lista.
 * 
 * A função cria um novo nó com os dados da conta fornecida e insere esse nó no final da lista de contas.
 * Se a lista estiver vazia, o novo nó é atribuído tanto ao ponteiro `head` quanto ao `tail`. Caso contrário,
 * o novo nó é ligado ao final da lista, e o ponteiro `tail` é atualizado para o novo nó.
 * 
 * @param L Ponteiro para a lista de contas (`LinkedList`).
 * @param content Ponteiro para a estrutura `bank_account` que contém os dados da conta a ser adicionada.
 * 
 * @note A função trata o caso da lista estar vazia e garante que os ponteiros `head` e `tail` sejam corretamente
 *       atualizados conforme necessário.
 */
void AdicionarContaFinal(LinkedList *L, bank_account *content) {
    // Cria um novo nó com o conteúdo desejado
    SNode *p = CriarConta(content);

    // Se a lista estiver vazia
    if (ListaContasEstaVazia(L)) {
        L->head = p;
    // Se a lista não estiver vazia
    } else {        
        L->tail->next = p;
    }

    L->tail = p;
    L->size++; 
}
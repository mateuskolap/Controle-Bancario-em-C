#include "../../include/funcoes.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief Cria um novo nó para armazenar uma conta bancária e inicializa suas propriedades.
 * 
 * A função aloca dinamicamente memória para um novo nó (`SNode`) e associa o conteúdo da conta bancária
 * ao campo `content` do nó. O ponteiro `next` do nó é configurado para `NULL`, indicando que ele não
 * aponta para nenhum próximo nó. A função retorna o ponteiro
 * para o novo nó criado.
 * 
 * @param content Ponteiro para a conta bancária (`bank_account`) que será armazenada no novo nó.
 * 
 * @return Ponteiro para o novo nó (`SNode`) contendo a conta bancária. Caso a alocação de memória falhe,
 *         a função retornará `NULL`.
 * 
 * @note A função não cria a lista de transações associada à conta.
 */
SNode *CriarConta(bank_account *content) {
    // Aloca um espaço na memória heap para armazenar um novo nó
    SNode *snode = (SNode *) calloc(1, sizeof(SNode));

    snode->content = content;
    snode->next = NULL;
    snode->content->num_transacoes = 0;
    strncpy(snode->content->status, "ATIVA", sizeof(snode->content->status));

    return snode;
}
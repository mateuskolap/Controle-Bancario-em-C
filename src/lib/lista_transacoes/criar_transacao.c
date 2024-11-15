#include "../../include/funcoes.h"
#include <stdlib.h>

/**
 * @brief Cria um novo nó de transação para uma lista duplamente encadeada.
 * 
 * A função aloca memória para um novo nó de transação (`DNode`) e inicializa seus ponteiros
 * `next` e `previous` como `NULL`, configurando o conteúdo do nó com o ponteiro fornecido 
 * (`content`).
 * 
 * @param content Ponteiro para a estrutura `bank_transaction` que contém as informações
 * da transação que serão armazenadas no nó.
 * 
 * @return Ponteiro para o novo nó de transação criado (`DNode`).
 * 
 * @note A função assume que `content` é um ponteiro válido para `bank_transaction`. A
 * responsabilidade de liberar a memória do nó e do conteúdo posteriormente cabe à função
 * que utilizará este nó.
 */
DNode *CriarTransacao(bank_transaction *content) {
    DNode *dnode = (DNode *) calloc(1, sizeof(DNode));

    dnode->content = content;
    dnode->next = NULL;
    dnode->previous = NULL;

    return dnode;
}
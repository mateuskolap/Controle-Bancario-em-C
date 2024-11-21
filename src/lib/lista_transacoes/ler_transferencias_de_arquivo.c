/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Ler lista de transacoes em arquivo
 */

#include "../../include/funcoes.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Lê dados de transações bancárias de um arquivo binário e os insere em uma lista duplamente encadeada.
 *
 * @param lista_transacoes Ponteiro para a lista de transações onde os dados lidos do arquivo serão armazenados.
 *
 * @details
 * - O arquivo binário é lido a partir do caminho "src/database/lista_transacoes.dat".
 * - Cada transação lida do arquivo é armazenada em um nó da lista duplamente encadeada.
 */
void LerTransacaoDeArquivo(List *lista_transacoes) {
    FILE *file = fopen("src/database/lista_transacoes.dat", "rb");
    if (file == NULL) {
        return;
    }

    bank_transaction transacao;
    while (fread(&transacao, sizeof(bank_transaction), 1, file) == 1) {
        // Aloca memória para o novo nó
        DNode *novoNode = (DNode *) calloc(1, sizeof(DNode));
        if (novoNode == NULL) {
            fclose(file);
            return;
        }

        // Aloca memória para armazenar os dados da transação
        novoNode->content = (bank_transaction *) malloc(sizeof(bank_transaction));
        if (novoNode->content == NULL) {
            free(novoNode);
            fclose(file);
            return;
        }

        // Copia os dados da transação para o novo nó
        *(novoNode->content) = transacao;

        // Insere o nó na lista duplamente encadeada
        if (lista_transacoes->head == NULL) {
            // Lista vazia: novo nó é o único elemento
            lista_transacoes->head = novoNode;
            lista_transacoes->tail = novoNode;
        } else {
            // Insere no final da lista
            novoNode->previous = lista_transacoes->tail;
            lista_transacoes->tail->next = novoNode;
            lista_transacoes->tail = novoNode;
        }

        // Incrementa o tamanho da lista
        lista_transacoes->size++;
    }

    fclose(file);
}

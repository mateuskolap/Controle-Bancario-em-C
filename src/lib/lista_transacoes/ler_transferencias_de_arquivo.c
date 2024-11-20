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
 * @brief Lê dados de contas bancárias de um arquivo binário e os insere em uma lista duplamente encadeada.
 *
 * @param lista_transacoes Ponteiro para a lista duplamente encadeada onde as contas bancárias lidas do arquivo serão armazenadas.
 * @param lista_contas Ponteiro para a lista de contas bancárias (usada para consultar as contas durante a leitura).
 *
 * @details
 *  - O arquivo binário é lido a partir do caminho "../database/lsita_contas.dat".
 *  - Se a memória para o nó ou para o conteúdo do nó não puder ser alocada, a função interrompe a execução
 *    e fecha o arquivo.
 */
void LerContasDeArquivo(List *lista_transacoes, LinkedList *lista_contas) {
    return;
}

/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Ler as contas de um arquivo
 */

#include "../../include/funcoes.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Lê dados de contas bancárias de um arquivo binário e os insere em uma lista encadeada.
 *
 * @param L Ponteiro para a lista encadeada onde as contas bancárias lidas do arquivo serão armazenadas.
 *
 * @details
 *  - O arquivo binário é lido a partir do caminho "../database/lista_contas.dat".
 *  - Se a memória para o nó ou para o conteúdo do nó não puder ser alocada, a função interrompe a execução
 *    e fecha o arquivo.
 */
void LerContasDeArquivo(LinkedList *L) {
    FILE *file = fopen("src/database/lista_contas.dat", "rb");

    if (file == NULL) {
        return;
    }

    bank_account conta;
    while (fread(&conta, sizeof(bank_account), 1, file) == 1) {
        // Alocar memória para o conteúdo da conta
        bank_account *novaConta = (bank_account *) malloc(sizeof(bank_account));
        if (novaConta == NULL) {
            fclose(file);
            return;
        }

        // Copiar os dados da conta lida para a nova estrutura
        *novaConta = conta;

        // Usar a função para adicionar a nova conta ao final da lista
        AdicionarContaFinal(L, novaConta);
    }

    fclose(file);
}
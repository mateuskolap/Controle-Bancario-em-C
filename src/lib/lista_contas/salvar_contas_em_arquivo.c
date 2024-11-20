/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Salvar a lista de contas em um arquivo binário
 */


#include "../../include/funcoes.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Salva os dados de uma lista encadeada de contas bancárias em um arquivo binário.
 *
 * @param L Ponteiro para a lista encadeada contendo as contas bancárias a serem salvas.
 * 
 * @details
 *  - O arquivo binário é criado no caminho "../database/lista_contas.dat".
 */
void SalvarContasEmArquivo(LinkedList *L) {
    FILE *file = fopen("src/database/lista_contas.dat", "wb");

    // Verificando se houve algum erro na abertura do arquivo
    if (file == NULL) {
        return;
    }
    
    // Nó que percorrerá a lista
    SNode *current = L->head;
    while (current != NULL) {
        // Escrevendo cada nó da lista no arquivo
        fwrite(current->content, sizeof(bank_account), 1, file);
        current = current->next;
    }
    
    fclose(file); // Fecha a lista
}
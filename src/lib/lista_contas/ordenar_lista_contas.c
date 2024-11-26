/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Ordenar a lista de contas
 */

#include "../../include/funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * @brief Ordena uma lista encadeada de contas com base em critérios especificados.
 * 
 * A função utiliza o algoritmo de ordenação Bubble Sort para reorganizar os elementos
 * da lista encadeada (`LinkedList`). A ordenação pode ser feita com base no nome do banco
 * ou no código da conta, dependendo do valor de `tipo_ordenacao`.
 * 
 * @param lista_contas Ponteiro para a lista encadeada (`LinkedList`) a ser ordenada.
 * @param tipo_ordenacao Critério de ordenação:
 *                       - 1: Ordenar alfabeticamente pelo nome do banco.
 *                       - 2: Ordenar numericamente pelo código da conta.
 * 
 * @note A função verifica iterativamente os pares de nós adjacentes e troca seus conteúdos
 *       caso estejam fora da ordem especificada. O processo continua até que nenhuma troca
 *       seja necessária (a lista esteja ordenada).
 */
void OrdenarListaContas(LinkedList *lista_contas, const int tipo_ordenacao) {
    int swapped;              // Indicador de troca para determinar se a lista foi alterada durante a iteração.
    SNode *current;           // Ponteiro para o nó atualmente sendo comparado.
    SNode *previous = NULL;   // Ponteiro para o último nó já ordenado, necessário para reduzir o escopo da próxima iteração.

    do {
        swapped = 0;          // Reinicia o indicador de troca no início de cada iteração.
        current = lista_contas->head;  // Inicia a verificação a partir do primeiro nó.

        while (current->next != previous) {  // Itera até o último nó não ordenado.
            if (tipo_ordenacao == 1) {       // Critério: Ordenação por nome do banco.
                if (strcmp(current->content->banco, current->next->content->banco) > 0) {
                    // Realiza a troca dos conteúdos se os bancos estiverem fora de ordem alfabética.
                    void *aux = current->content;
                    current->content = current->next->content;
                    current->next->content = aux;
                    swapped = 1;  // Indica que houve uma troca.
                }
            } else if (tipo_ordenacao == 2) {  // Critério: Ordenação por código da conta.
                if (current->content->codigo_conta > current->next->content->codigo_conta) {
                    // Realiza a troca dos conteúdos se os códigos das contas estiverem fora de ordem crescente.
                    void *aux = current->content;
                    current->content = current->next->content;
                    current->next->content = aux;
                    swapped = 1;  // Indica que houve uma troca.
                }
            }
            current = current->next;  // Avança para o próximo par de nós.
        }
        previous = current;  // Atualiza o nó limite da próxima iteração.
    } while (swapped);  // Repete enquanto houver trocas.
}
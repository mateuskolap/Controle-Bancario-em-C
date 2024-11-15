#include "../../include/funcoes.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Adiciona uma nova conta bancária em uma posição específica da lista.
 * 
 * A função insere uma nova conta na lista de contas na posição indicada pelo parâmetro `position`.
 * Se a posição for a primeira, a conta é adicionada no início utilizando a função `AdicionarContaInicio`.
 * Caso contrário, a lista é percorrida até a posição desejada, e a nova conta é inserida entre os nós correspondentes.
 * Se a inserção for no final da lista, o ponteiro `tail` é atualizado para o novo nó.
 * 
 * @param L Ponteiro para a lista de contas (`LinkedList`).
 * @param content Ponteiro para a estrutura `bank_account` que contém os dados da conta a ser adicionada.
 * @param position A posição onde a conta será inserida. O índice é baseado em 1.
 * 
 * @note A função verifica se a posição fornecida está dentro dos limites válidos antes de proceder com a inserção.
 *       Caso a posição seja inválida, uma mensagem de erro será exibida.
 */
void AdicionarContaEm(LinkedList *L, bank_account *content, int position) {
    // Verificando se a posição desejada existe.
    if ((position < 1) || (position > L->size + 1)) {
        fprintf(stderr, "ERROR in 'AdicionarContaEm'\n");
        fprintf(stderr, "Position [%d] is out of bounds: [1, %d]\n", position, L->size);
        return;
    }

    SNode *p = CriarConta(content);
 
    // Se a inserção for na primeira posição
    if (position == 1) {
        AdicionarContaInicio(L, content);
        return;
    } 

    SNode *current = L->head;
    SNode *previous = NULL;

    // Percorre os elementos da lista até a posição desejada
    for (int count = 1; (current != NULL) && (count < position); count++) {
        previous = current; // Armazena o elemento anterior
        current = current->next; // Armazena o próximo elemento
    }

    // Insere o valor do próximo elemento em "p"
    p->next = current;
    
    previous->next = p;

    // Se a inserção for no final da lista, o novo elemento deve estar presente no campo "tail"
    if (current == NULL) {
        L->tail = p;
    }

    L->size++; 
}
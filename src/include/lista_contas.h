/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * subfunção..: cabeçalho lista simplesmente encadeada
 */

#ifndef LISTA_CONTAS_H
#define LISTA_CONTAS_H

#include <stdbool.h>

typedef struct _bank_account bank_account;
typedef struct _snode SNode;
typedef struct _linkedList LinkedList;

LinkedList *CriarListaContas();
SNode *CriarConta(bank_account *content);
void ExcluirConta(SNode **snode_ref);
void ExcluirListaContas(LinkedList **L_ref);
bool ListaContasEstaVazia(const LinkedList *L);
void AdicionarContaInicio(LinkedList *L, bank_account *content);void AdicionarContaFinal(LinkedList *L, bank_account *content);
void AdicionarContaEm(LinkedList *L, bank_account *content, int position);
void RemoverContaInicio(LinkedList *L);
void RemoverContaEm(LinkedList *L, int position);
bank_account *ConsultarConta(LinkedList *L, const int codigo_conta);
void AlterarInformacao(bank_account *conta, const int informacao, char nova_informacao[]);

#endif
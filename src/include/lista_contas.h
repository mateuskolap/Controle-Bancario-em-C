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

// Estrutura que armazenará as informações da conta bancária
typedef struct _bank_account {
    int codigo_conta;
    char banco[50];
    char agencia[10];
    char numero_conta[20];
    char tipo_conta[20];
    double vl_saldo;
    double vl_limite;
    char status[10];
} bank_account;

// Nó que armazenará o conteúdo da estrutura de contas bancárias e um ponteiro para o próximo nó
typedef struct _snode {
    bank_account *content; // Ponteiro para o conteúdo da conta
    struct _snode *next;
} SNode;

// Estrutura da lista simplesmente encadeada
typedef struct _linkedList {
    SNode *head;
    SNode *tail;
    int size;
} LinkedList;

LinkedList *CriarListaContas();
SNode *CriarConta(bank_account *content);
void ExcluirConta(SNode **snode_ref);
void ExcluirListaContas(LinkedList **L_ref);
bool ListaContasEstaVazia(const LinkedList *L);
void AdicionarContaInicio(LinkedList *L, bank_account *content);
void AdicionarContaFinal(LinkedList *L, bank_account *content);
void AdicionarContaEm(LinkedList *L, bank_account *content, int position);
void RemoverContaInicio(LinkedList *L);
void RemoverContaEm(LinkedList *L, int position);
bank_account *ConsultarConta(LinkedList *L, const int codigo_conta);
void AlterarInformacao(bank_account *conta, const int informacao, char nova_informacao[]);

#endif
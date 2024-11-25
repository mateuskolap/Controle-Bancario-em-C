#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdbool.h>

/***************************** LISTA DE CONTAS *****************************/
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
    int num_transacoes;
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
void RemoverContaFinal(LinkedList *L);
void RemoverContaEm(LinkedList *L, int position);
bank_account *ConsultarConta(LinkedList *L, const int codigo_conta);
bank_account *ConsultarContaPosicao(LinkedList *L, const int posicao);
void LerContasDeArquivo(LinkedList *L);
void SalvarContasEmArquivo(LinkedList *L);
void OrdenarListaContas(LinkedList *lista_contas, const int tipo_ordenacao);

/***************************** LISTA DE TRANSACOES *****************************/
// Estrutura que armazenará as movimentações bancárias
typedef struct _bank_transaction {
    int sequencial;
    int codigo_conta;
    char data_movimento[12];
    char tp_movimentacao[10];
    char favorecido[50];
    double vl_movimento;
    double vl_saldo;
} bank_transaction;

// Nó que armazenará o conteúdo das movimentações bancárias, um ponteiro para o nó anterior e o próximo
typedef struct _dnode {
    bank_transaction *content;
    struct _dnode *previous;
    struct _dnode *next;
} DNode;

// Estrutura das movimentações bancárias
typedef struct _dLinkedList {
    DNode *head;
    DNode *tail;
    int size;
} List;

List *CriarListaTransacoes();
DNode *CriarTransacao(bank_transaction *content);
void AdicionarTransacao(List *lista_transacoes, LinkedList *lista_contas, bank_transaction *content, const int tipo_transacao);
bool ListaTransacoesEstaVazia(const List *L);
void AdicionarTransferencia(List *lista_transacoes, LinkedList *lista_contas, bank_account *conta_origem, bank_account *conta_destino, const double valor, char data[]);
void SalvarTransacoesEmArquivo(List *L);
void ExcluirTransacao(DNode **dnode_ref);
void ExcluirListaTransacoes(List **L_ref);
void LerTransacaoDeArquivo(List *lista_transacoes);

/***************************** TELAS *****************************/
void gotoxy(int x, int y);
void ExibirFormularioContas(int tipo_cadastro);
void Moldura();
void TelaPrincipal(LinkedList *lista_contas, List *lista_transacoes);
void TelaContasBancarias(LinkedList *lista_contas);
void TelaCadastrarConta(LinkedList *lista_contas, int tipo_cadastro);
void TelaConsultaContas(LinkedList *lista_contas);
void TelaConsultaGeralContas(LinkedList *lista_contas);
void TelaConsultarContaCodigo(LinkedList *lista_contas);
void TelaConsultarContaPorOrdem(LinkedList *lista_contas, const int tipo_ordenacao);
void TelaConsultarContasInativas(LinkedList *lista_contas);
void TelaRemoverConta(LinkedList *lista_contas, const int tipo_exclusao);
void TelaAlteracaoConta(LinkedList *lista_contas);
void EscreverNoCentro(int y, char texto[]);
void EscreverNoCentroX1X2(int x1, int x2, int y, char texto[]);
void AlinharTextoNaPosicao(int x, int y, char texto[]);
void CriarTitulo(char titulo[]);
void ExibirFormularioTransacao();
void TelaMovimentacaoDebitoCredito(LinkedList *lista_contas, List *lista_transacoes);
void TelaMovimentacoesBancarias(LinkedList *lista_contas, List *lista_transacoes);
void TelaTransferenciaEntreContas(LinkedList *lista_contas, List *lista_transacoes);
void ExibirFormularioTransferencia(int x_inicial, int y_inicial);
void TelaConsultarTransacoes(LinkedList *lista_contas, List *lista_transacoes);

/***************************** VERIFICAÇÕES *****************************/
bool ValidarData(char data[]);
int InverterData(char data[]);
char *VerificarUltimaData(List *lista_transacoes, const int codigo_conta);

#endif
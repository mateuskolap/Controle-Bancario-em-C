/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * subfunção..: funçoes lista simplesmente encadeada
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../include/lista_contas.h"
#include "../include/lista_transacoes.h"

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
    List *transacoes;
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

/******************* "CONSTRUTORES" *******************/

/**
 * @brief Cria uma nova lista de contas bancárias e inicializa suas propriedades.
 * 
 * A função aloca dinamicamente memória para uma nova lista (`LinkedList`) e inicializa seus campos:
 * - `head` é configurado como `NULL`, indicando que a lista está vazia;
 * - `tail` também é configurado como `NULL`, já que não há elementos na lista;
 * - `size` é inicializado como 0, já que a lista começa sem elementos.
 * 
 * A função retorna o ponteiro para a nova lista de contas criada.
 * 
 * @return Ponteiro para a nova lista de contas (`LinkedList`). Caso a alocação de memória falhe, a função
 *         retornará `NULL`.
 */
LinkedList *CriarListaContas() {
    // Aloca um espaço na memória heap para armazenar um novo nó
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));

    L->head = NULL;
    L->tail = NULL;
    L->size = 0;

    return L;
}

/**
 * @brief Cria um novo nó para armazenar uma conta bancária e inicializa suas propriedades.
 * 
 * A função aloca dinamicamente memória para um novo nó (`SNode`) e associa o conteúdo da conta bancária
 * ao campo `content` do nó. O campo `transacoes` da conta é inicializado como `NULL`, e o ponteiro `next` do nó
 * é configurado para `NULL`, indicando que ele não aponta para nenhum próximo nó. A função retorna o ponteiro
 * para o novo nó criado.
 * 
 * @param content Ponteiro para a conta bancária (`bank_account`) que será armazenada no novo nó.
 * 
 * @return Ponteiro para o novo nó (`SNode`) contendo a conta bancária. Caso a alocação de memória falhe,
 *         a função retornará `NULL`.
 * 
 * @note A função não cria a lista de transações associada à conta.
 */
SNode *CriarConta(bank_account *content) {
    // Aloca um espaço na memória heap para armazenar um novo nó
    SNode *snode = (SNode *) calloc(1, sizeof(SNode));

    snode->content = content;
    snode->content->transacoes = CriarListaTransacoes();
    snode->next = NULL;

    return snode;
}

/******************* "DESTRUIDORES" *******************/

/**
 * @brief Exclui o nó da lista de contas e desaloca sua memória.
 * 
 * A função remove o nó apontado por `snode_ref` e desaloca tanto o conteúdo da conta bancária (armazenado no campo `content`)
 * quanto o próprio nó da lista. Após a liberação de memória, o ponteiro que referencia o nó é setado como `NULL`, 
 * garantindo que o ponteiro que chamou a função não aponte para uma área de memória já liberada.
 * 
 * @param snode_ref Ponteiro duplo para o nó (`SNode`). Esse ponteiro é utilizado para liberar a memória do nó
 *                  e garantir que o ponteiro original seja atualizado para `NULL`.
 * 
 * @note A função presume que a memória alocada para o conteúdo da conta bancária e para o nó da lista foi alocada
 *       dinamicamente e deve ser liberada adequadamente. A destruição da lista de transações da conta deve ser implementada.
 */
void ExcluirConta(SNode **snode_ref) {
    // Auxiliar para acessar o conteúdo da conta
    SNode *snode = *snode_ref;

    // Implementar aqui a função para destruir a lista de transacoes ----------------------------------------

    free(snode->content); // Liberando o conteúdo do nó
    free(snode); // Liberando o nó

    *snode_ref = NULL;
}

/**
 * @brief Exclui completamente a lista de contas e desaloca sua memória.
 * 
 * A função percorre todos os nós da lista de contas, removendo cada um deles e desalocando a memória associada.
 * Após a remoção de todos os nós, a memória da própria lista é liberada. O ponteiro para a lista é setado como `NULL`
 * para garantir que a referência seja perdida após a exclusão. 
 * 
 * @param L_ref Ponteiro duplo para a lista de contas (`LinkedList`). Esse ponteiro é utilizado para liberar a memória da estrutura da lista.
 * 
 * @note Após o uso dessa função, o ponteiro para a lista (`L_ref`) deverá ser considerado inválido,
 *       pois a memória foi liberada e o ponteiro é setado como `NULL`.
 */
void ExcluirListaContas(LinkedList **L_ref) {
    // Auxiliar para acessar o conteúdo da lista
    LinkedList *L = *L_ref;

    // Ponteiros auxiliares para a remoção
    SNode *current = L->head;
    SNode *aux = NULL;

    // Repetição para abranger todos os nós da lista
    while (current != NULL) {
        aux = current;
        current = current->next;

        ExcluirConta(&aux);
    }

    free(L); // Desaloca a lista
    L_ref = NULL;
}

/******************* FUNÇÕES DE VERIFICAÇÃO NA LISTA *******************/

/**
 * @brief Verifica se a lista de contas está vazia.
 * 
 * A função retorna um valor booleano que indica se a lista contém ou não elementos. 
 * Se o tamanho da lista (`size`) for igual a 0, a lista é considerada vazia, e a função retorna `true`.
 * Caso contrário, retorna `false`.
 * 
 * @param L Ponteiro para a lista de contas (`LinkedList`).
 * 
 * @return `true` se a lista estiver vazia, `false` caso contrário.
 */

bool ListaContasEstaVazia(const LinkedList *L) {
    return L->size == 0;
}

/**
 * @brief Consulta o saldo de uma conta bancária.
 * 
 * A função localiza a conta bancária com o código informado na lista de contas (`LinkedList`),
 * utilizando a função `ConsultarConta`. Em seguida, retorna o saldo da conta (`vl_saldo`).
 * 
 * Caso a conta não seja encontrada na lista, a função pode retornar um valor indefinido, pois a
 * função `ConsultarConta` retornaria `NULL`.
 * 
 * @param L Ponteiro para a lista de contas bancárias (`LinkedList`).
 * @param codigo_conta Código da conta bancária que se deseja consultar.
 * 
 * @return Saldo da conta bancária (`vl_saldo`).
 * 
 * @note Caso a conta não seja encontrada, a função retornará o valor '-1'.
 */
double ConsultarSaldo(LinkedList *L, int codigo_conta) {
    bank_account *conta = ConsultarConta(L, codigo_conta);
    
    if (conta != NULL) {
        return conta->vl_saldo;
    }

    fprintf(stderr, "ERROR in 'ConsultarSaldo': This account doesn't exists.\n");
    exit(EXIT_FAILURE);
}

/******************* FUNÇÕES DE INSERÇÃO NA LISTA *******************/

/**
 * @brief Adiciona uma nova conta bancária no início da lista.
 * 
 * A função cria um novo nó com os dados da conta fornecida e insere esse nó no início da lista de contas.
 * O ponteiro `next` do novo nó será ajustado para apontar para o nó atualmente na cabeça da lista.
 * Se a lista estiver vazia, o novo nó será atribuído ao ponteiro `tail`, já que ele será o único nó da lista.
 * O ponteiro `head` é atualizado para o novo nó, tornando-o o primeiro da lista.
 * 
 * @param L Ponteiro para a lista de contas (`LinkedList`).
 * @param content Ponteiro para a estrutura `bank_account` que contém os dados da conta a ser adicionada.
 * 
 * @note A função garante que, se a lista estiver vazia, o ponteiro `tail` seja corretamente atualizado,
 *       e que o ponteiro `head` sempre aponte para o novo nó inserido.
 */
void AdicionarContaInicio(LinkedList *L, bank_account *content) {
    // Cria um novo nó com o conteúdo desejado
    SNode *p = CriarConta(content);

    p->next = L->head; // O ponteiro próximo do novo nó apontará para o primeiro nó da lista

    // Verifica se a lista está vazia
    if (ListaContasEstaVazia(L)) {
        L->tail = p;
    } 

    L->head = p; // A cabeça da lista será alterada para guardar o novo nó   

    L->size++; 
}

/**
 * @brief Adiciona uma nova conta bancária no final da lista.
 * 
 * A função cria um novo nó com os dados da conta fornecida e insere esse nó no final da lista de contas.
 * Se a lista estiver vazia, o novo nó é atribuído tanto ao ponteiro `head` quanto ao `tail`. Caso contrário,
 * o novo nó é ligado ao final da lista, e o ponteiro `tail` é atualizado para o novo nó.
 * 
 * @param L Ponteiro para a lista de contas (`LinkedList`).
 * @param content Ponteiro para a estrutura `bank_account` que contém os dados da conta a ser adicionada.
 * 
 * @note A função trata o caso da lista estar vazia e garante que os ponteiros `head` e `tail` sejam corretamente
 *       atualizados conforme necessário.
 */
void AdicionarContaFinal(LinkedList *L, bank_account *content) {
    // Cria um novo nó com o conteúdo desejado
    SNode *p = CriarConta(content);

    // Se a lista estiver vazia
    if (ListaContasEstaVazia(L)) {
        L->head = p;
    // Se a lista não estiver vazia
    } else {        
        L->tail->next = p;
    }

    L->tail = p;
    L->size++; 
}

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

/******************* FUNÇÕES DE REMOÇÃO NA LISTA *******************/

/**
 * @brief Remove o primeiro nó da lista de contas.
 * 
 * A função remove o nó da cabeça da lista, ajustando o ponteiro `head` para o próximo nó.
 * Se a lista contiver apenas um nó, o ponteiro `tail` também será ajustado para `NULL`.
 * O nó removido é desalocado e o tamanho da lista é decrementado.
 * 
 * @param L Ponteiro para a lista de contas (`LinkedList`).
 * 
 * @note A função verifica se a lista está vazia antes de tentar realizar a remoção. 
 *       Caso contrário, a remoção é realizada e o tamanho da lista é atualizado.
 */
void RemoverContaInicio(LinkedList *L) {
    // Retorna um erro se a lista estiver vazia
    if (ListaContasEstaVazia(L)) {
        fprintf(stderr, "ERROR in 'RemoverContaInicio': The list is already empty.\n");
        return;
    }

    // Nó temporário que auxiliará na remoção do primeiro elemento
    SNode *temp = L->head;

    // Se a lista possuir somente um elemento
    if (L->head == L->tail) {
        L->tail = NULL;
    }

    // A cabeça da lista passa a apontar para o segundo elemento
    L->head = L->head->next;
    ExcluirConta(&temp); // O primeiro nó é desalocado

    L->size--; // Decrementa o tamanho da lista
}

/**
 * @brief Remove uma conta bancária em uma posição específica da lista.
 * 
 * A função remove um nó da lista de contas na posição indicada pelo parâmetro `position`.
 * Se a posição for a primeira, a função `RemoverContaInicio` é chamada. Caso contrário, o nó desejado
 * é removido após percorrer a lista. A função também cuida da atualização do ponteiro para a cauda da lista
 * e do ajuste do tamanho da lista.
 * 
 * @param L Ponteiro para a lista de contas (`LinkedList`).
 * @param position A posição do nó (conta) a ser removido na lista. O índice é baseado em 1.
 * 
 * @note A função verifica se a lista está vazia ou se a posição fornecida está fora dos limites válidos
 *       antes de proceder com a remoção. Se a posição for inválida, a função exibe uma mensagem de erro.
 */
void RemoverContaEm(LinkedList *L, int position) {
    // Retorna um erro se a lista estiver vazia
    if (ListaContasEstaVazia(L)) {
        fprintf(stderr, "ERROR in 'RemoverContaEm': The list is already empty.\n");
        return;
    }

    // Verificando se a posição desejada existe.
    if ((position < 1) || (position > L->size)) {
        fprintf(stderr, "ERROR in 'RemoverContaEm'\n");
        fprintf(stderr, "Position [%d] is out of bounds: [1, %d]\n", position, L->size);
        return;
    }

    // Se for a primeira posição
    if (position == 1) {
        RemoverContaInicio(L);
        return;
    }

    // Auxiliares para remoção
    SNode *current = L->head;
    SNode *previous = NULL;

    // Encontra o nó desejado para remover, e o anterior
    for (int count = 1; (current != NULL) && (count < position); count++) {
        previous = current;
        current = current->next;
    }

    // O próximo nó do anterior, será o próximo nó do atual
    previous->next = current->next;

    // Se a remoção for na cauda
    if (current == L->tail) {
        L->tail = previous;
    }
    
    // O nó é desalocado
    ExcluirConta(&current);

    L->size--; // Decrementa o tamanho da lista
}

/******************* FUNÇÕES DE CONSULTA NA LISTA *******************/

/**
 * @brief Consulta uma conta bancária na lista de contas.
 * 
 * A função percorre a lista de contas bancárias e busca uma conta com o código especificado.
 * Se a conta for encontrada, o ponteiro para a estrutura da conta é retornado.
 * Caso contrário, a função retorna `NULL` para indicar que a conta não foi encontrada.
 * 
 * @param L Ponteiro para a lista de contas (do tipo `LinkedList`).
 * @param codigo_conta O código da conta a ser buscada.
 * 
 * @return Ponteiro para a estrutura `bank_account` correspondente ao código da conta, 
 *         ou `NULL` se a conta não for encontrada.
 * 
 * @note A função emite uma mensagem de erro caso a lista esteja vazia.
 */
bank_account *ConsultarConta(LinkedList *L, const int codigo_conta) {
    // Retorna um erro se a lista estiver vazia
    if (ListaContasEstaVazia(L)) {
        fprintf(stderr, "ERROR in 'ConsultarConta': The list is already empty.\n");
        return NULL;
    }

    SNode *aux = L->head;

    while (aux != NULL) {
        if (aux->content->codigo_conta == codigo_conta) {
            return aux->content; // Conta encontrada, retorna o conteúdo
        }
        aux = aux->next;
    }

    return NULL; // Conta não encontrada, retorna NULL (vazio)
}

/******************* FUNÇÕES DE ALTERAÇÃO NA LISTA *******************/

/**
 * @brief Altera uma determinada informação de uma conta bancária.
 * 
 * A função modifica um campo específico da estrutura `bank_account` com base no valor do parâmetro `informacao`.
 * Dependendo do campo selecionado, a função copia o valor de `nova_informacao` para o campo da estrutura 
 * ou converte `nova_informacao` para o tipo adequado (por exemplo, `double` para `vl_limite`).
 *
 * @param conta Endereço de memória da estrutura `bank_account` que contém a conta a ser alterada.
 * @param informacao Código que indica qual campo da estrutura será alterado:
 *      1: Altera o nome do banco.
 *      2: Altera o número da agência.
 *      3: Altera o número da conta.
 *      4: Altera o tipo da conta.
 *      5: Alterar o saldo (não permitido, gera mensagem de erro).
 *      6: Altera o limite da conta (converte `nova_informacao` para `double`).
 *      7: Altera o status da conta.
 * @param nova_informacao Uma string contendo o novo valor que será atribuído ao campo indicado.
 * 
 * @note Se o código `informacao` for 5 (saldo), a função emitirá uma mensagem de erro informando que o saldo 
 *       não pode ser alterado diretamente. Se `informacao` for inválido, uma mensagem de erro é exibida.
 */
void AlterarInformacao(bank_account *conta, const int informacao, char nova_informacao[]) {
    switch (informacao) {
        case 1: // Alterando o banco
            strncpy(conta->banco, nova_informacao, sizeof(conta->banco) - 1);
            conta->banco[sizeof(conta->banco) - 1] = '\0';
            break;
        case 2: // Alterando a agência
            strncpy(conta->agencia, nova_informacao, sizeof(conta->agencia) - 1);
            conta->agencia[sizeof(conta->agencia) - 1] = '\0';
            break;
        case 3: // Alterando o numero da conta
            strncpy(conta->numero_conta, nova_informacao, sizeof(conta->numero_conta) - 1);
            conta->numero_conta[sizeof(conta->numero_conta) - 1] = '\0';
            break;
        case 4: // Alterando o tipo da conta
            strncpy(conta->tipo_conta, nova_informacao, sizeof(conta->tipo_conta) - 1);
            conta->tipo_conta[sizeof(conta->tipo_conta) - 1] = '\0';
            break;
        case 5:// Alterando o saldo da conta
            fprintf(stderr, "O saldo da conta não pode ser alterado!");
            return;
        case 6: // Alterando o limite da conta
            conta->vl_limite = atof(nova_informacao);
            break;
        case 7: // Alterando o status da conta
            strncpy(conta->status, nova_informacao, sizeof(conta->status) - 1);
            conta->status[sizeof(conta->status) - 1] = '\0';
            break;
        default:
            fprintf(stderr, "Error in 'AlterarInformação': The 'informacao' parameter entered does not exist");
            return;
    }
}
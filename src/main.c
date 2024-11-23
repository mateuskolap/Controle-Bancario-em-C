#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "include/funcoes.h"

int main() {
    LinkedList *lista_contas = CriarListaContas();
    List *lista_transacoes = CriarListaTransacoes();
    LerContasDeArquivo(lista_contas);
    LerTransacaoDeArquivo(lista_transacoes);

    TelaPrincipal(lista_contas, lista_transacoes);

    ExcluirListaContas(&lista_contas);
    ExcluirListaTransacoes(&lista_transacoes);
    
    return 0;
}

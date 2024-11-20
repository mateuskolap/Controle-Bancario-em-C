#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "include/funcoes.h"

int main() {
    LinkedList *lista_contas = CriarListaContas();
    List *lista_transacoes = CriarListaTransacoes();
    LerContasDeArquivo(lista_contas);

    TelaPrincipal(lista_contas, lista_transacoes);

    return 0;
}

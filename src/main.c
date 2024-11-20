#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "include/funcoes.h"

int main() {
    LinkedList *lista_contas = CriarListaContas();
    LerContasDeArquivo(lista_contas);

    TelaPrincipal(lista_contas);

    return 0;
}

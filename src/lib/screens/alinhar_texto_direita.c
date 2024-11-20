#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>

void AlinharTextoDireita(int y, char texto[]) {
    int largura_tela = 120;
    int largura_texto = strlen(texto);

    int x = (largura_tela / 2) - largura_texto;

    gotoxy(x, y);
    printf("%s", texto);
}
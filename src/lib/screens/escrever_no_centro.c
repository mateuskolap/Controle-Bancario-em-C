#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>

void EscreverNoCentro(int y, char texto[]) {
    int largura_tela = 119;
    int largura_texto = strlen(texto);

    int x = (largura_tela / 2) - (largura_texto / 2);

    gotoxy(x, y);
    printf("%s", texto);
}
#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>

#define LARGURA_TELA_PADRAO 119

void EscreverNoCentroX1X2(int x1, int x2, int y, char texto[]) {
    int largura_texto = strlen(texto);

    // Calcula o ponto médio entre x1 e x2
    int largura_disponivel = x2 - x1;
    int x_centro = x1 + (largura_disponivel / 2) - (largura_texto / 2);

    // Escreve o texto no centro calculado
    gotoxy(x_centro, y);
    printf("%s", texto);
}

void EscreverNoCentro(int y, char texto[]) {
    int largura_texto = strlen(texto);

    int x = (LARGURA_TELA_PADRAO / 2) - (largura_texto / 2);

    gotoxy(x, y);
    printf("%s", texto);
}
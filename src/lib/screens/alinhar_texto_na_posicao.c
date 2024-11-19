#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>

void AlinharTextoNaPosicao(int x, int y, char texto[]) {
    gotoxy(x, y);
    printf("%s", texto);
}
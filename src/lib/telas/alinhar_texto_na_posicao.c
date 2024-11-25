/**
 * Autor......: Rian da Cruz
 * Data.......: 16/11/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: alinha o texto desejano na posição indicada
 */
#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>

void AlinharTextoNaPosicao(int x, int y, char texto[]) {
    gotoxy(x, y);
    printf("%s", texto);
}
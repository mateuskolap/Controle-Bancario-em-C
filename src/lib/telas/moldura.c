/**
 * Autor......: Rian da Cruz
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: moldura padrão do programa
 */

#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

// Função que permitirá criar uma estrutura de tela padrão
void Moldura() {
    system("cls"); 

    // Criando as limitações da tela.
    gotoxy(1, 1);
    for (int i = 1; i < 119; i++) {
        gotoxy(i, 1);
        puts("-");
        gotoxy(i, 4);
        puts("-");
        gotoxy(i, 23);
        puts("-");
        gotoxy(i, 25);
        puts("-");

        if (i < 26) {
            gotoxy(1, i);
            puts("|");
            gotoxy(118, i);
            puts("|");
        }
    }

    gotoxy(1, 1);
    puts("+");
    gotoxy(1, 4);
    puts("+");
    gotoxy(1, 23);
    puts("+");
    gotoxy(1, 25);
    puts("+");
    gotoxy(118, 1);
    puts("+");
    gotoxy(118, 4);
    puts("+");
    gotoxy(118, 23);
    puts("+");
    gotoxy(118, 25);
    puts("+");

    gotoxy(2, 24);
    printf("MSG.:");
}
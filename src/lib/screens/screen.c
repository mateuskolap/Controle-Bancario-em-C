/**
 * Autor......: Rian Torres
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Função para criar a tela padrão
 */


#include "../../include/funcoes.h"
#include <stdio.h>
#include<conio.h>
#include<windows.h>

void screen() {

    for(int i = 0; i < 80; i++) {
        gotoxy(i, 0);
        printf("=");
        gotoxy(i, 3);
        printf("=");
        gotoxy(i, 22);
        printf("=");
        gotoxy(i, 24);
        printf("=");
    }

    for (int i = 0; i < 25; i++) {
        gotoxy(0, i);
        printf("|");
        gotoxy(80, i);
        printf("|");
    }

    gotoxy(0,0);
    printf("+");
    gotoxy(80,0);
    printf("+");
    gotoxy(0,3);
    printf("+");
    gotoxy(80,3);
    printf("+");
    gotoxy(0,24);
    printf("+");
    gotoxy(80,24);
    printf("+");

    gotoxy(1,23);
    printf("SAIDA:");

    gotoxy(1,1);
    printf("2 ADS");
    gotoxy(1,2);
    printf("Trabalho final:");

    gotoxy(62,1);
    printf("Rian Torres");
    gotoxy(62,2);
    printf("Mateus kolapouski");
}
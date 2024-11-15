#include "../../include/funcoes.h"
#include <stdio.h>
#include<conio.h>
#include<windows.h>

void main_menu () {

    system("cls");
    screen();

    gotoxy(27,10);
    printf("1. Cadastro de Contas");
    gotoxy(27,12);
    printf("2. Movimentacao Financeira");
    gotoxy(27,14);
    printf("3. Sair");

}
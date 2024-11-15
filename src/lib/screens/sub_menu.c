#include "../../include/funcoes.h"
#include <stdio.h>
#include<conio.h>
#include<windows.h>

void subMenu () {

    system("cls");
    screen();

    gotoxy(27,10);
    printf("1. Incluir Conta");
    gotoxy(27,12);
    printf("2. Alterar Conta");
    gotoxy(27,14);
    printf("3. Consultar Conta");
    gotoxy(27,16);
    printf("4. Remover Conta");
    gotoxy(27,18);
    printf("5. Voltar");
}
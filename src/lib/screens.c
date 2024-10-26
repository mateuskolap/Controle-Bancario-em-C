#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

void gotoxy (int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void screen ()
{
    for(int i = 0; i < 80; i++)
    {
        gotoxy(i, 0);
        printf("=");
        gotoxy(i, 3);
        printf("=");
        gotoxy(i, 22);
        printf("=");
        gotoxy(i, 24);
        printf("=");
    }

    for (int i = 0; i < 25; i++)
    {
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

void main_menu() {

    gotoxy(27,10);
    printf("1. Cadastro de Contas");
    gotoxy(27,12);
    printf("2. Movimentacao Financeira");
    gotoxy(27,14);
    printf("3. Sair");

}

void subMenu () {
    gotoxy(27,10);
    printf("1. Incluir Conta");
    gotoxy(27,12);
    printf("2. Alterar Conta");
    gotoxy(27,14);
    printf("3. Consultar Conta");
    gotoxy(27,16);
    printf("4. Remover Conta");
}

void Financial_Transaction () {

    gotoxy(27,10);
    printf("1. Registrar Entrada");
    gotoxy(27,12);
    printf("2. Registrar Saida");
    gotoxy(27,14);
    printf("3. Consultar Movimentacao");

}
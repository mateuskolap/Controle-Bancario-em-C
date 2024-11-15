/**
 * Autor......: Rian da Cruz
 * Data.......: 26/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * subfunção..: funçoes de telas
 */

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

void Financial_Transaction () {

    system("cls");
    screen();


    gotoxy(27,10);
    printf("1. Registrar Entrada");
    gotoxy(27,12);
    printf("2. Registrar Saida");
    gotoxy(27,14);
    printf("3. Consultar Movimentacao");

}

void registration_query () {

    system("cls");
    screen();

    gotoxy(5,5);
    printf("1- codigo.........:");
    gotoxy(5,7);
    printf("2- branco.........:");
    gotoxy(5,9);
    printf("3- agencia........:");
    gotoxy(5,11);
    printf("4- numero da conta:");
    gotoxy(5,13);
    printf("5- tipo de conta..:");
    gotoxy(5,15);
    printf("6- saldo..........:");
    gotoxy(5,17);
    printf("7- limite.........:");
    gotoxy(5,19);
    printf("8- status.........:");

}
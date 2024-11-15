/**
 * Autor......: Rian Torres
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Função de registrar uma conta
 */


#include "../../include/funcoes.h"
#include <stdio.h>
#include<conio.h>
#include<windows.h>

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
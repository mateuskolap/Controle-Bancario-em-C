/**
 * Autor......: Rian Torres
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Criar a tela de transações financeiras
 */

#include "../../include/funcoes.h"
#include <stdio.h>
#include<conio.h>
#include<windows.h>

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
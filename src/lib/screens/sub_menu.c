/**
 * Autor......: Rian Torres
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Função para criar a tela de contas
 */

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
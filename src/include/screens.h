/**
 * Autor......: Rian da Cruz
 * Data.......: 26/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * subfunção..: cabeçalho lista duplamente encadeada
 */


#ifndef SCREENS_H
#define SCREENS_H

/**
 * função que define posição do cursor na tela
 */
void gotoxy (int x, int y);

/**
 * função que define a tela padrão do sistema
 */
void screen();

/**
 * tela de menu principal
 */
void main_menu();

/**
 * tela submenu para cadastro de contas
 */
void subMenu ();

/**
 * tela submenu de movimentação financeira
 */
void Financial_Transaction();

#endif
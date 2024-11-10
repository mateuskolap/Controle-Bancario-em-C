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
/**
 * Autor......: Rian da Cruz
 * Data.......: 16/11/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: cria um titulo
 */
#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void CriarTitulo(char titulo[]) {
    EscreverNoCentro(2, "SISTEMA DE CONTROLE BANCARIO");
    EscreverNoCentro(3, titulo);
}
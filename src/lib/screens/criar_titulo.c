#include "../../include/funcoes.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void CriarTitulo(char titulo[]) {
    EscreverNoCentro(2, "SISTEMA DE CONTROLE BANCARIO");
    EscreverNoCentro(3, titulo);
}
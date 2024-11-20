/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Inverter uma data para tornar possível a comparação
 */

#include "../../include/funcoes.h"
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int InverterData(char data[]) {
    char dia[3], mes[3], ano[5];
    char dataInvertida[9];

    sscanf(data, "%2s/%2s/%4s", dia, mes, ano);

    sprintf(dataInvertida, "%s%s%s", ano, mes, dia);

    return atoi(dataInvertida);
}
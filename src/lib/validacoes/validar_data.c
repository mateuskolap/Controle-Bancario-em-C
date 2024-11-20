#include "../../include/funcoes.h"
#include <string.h>
#include <time.h>
#include <stdbool.h>

bool ValidarData(char data[]) {
    int dia, mes, ano;

    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    int anoAtual = tm_info->tm_year + 1900;

    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) == 3) {
        if (ano < 1900 || ano > anoAtual) {
            return false;
        }

        if (mes < 1 || mes > 12) {
            return false;
        }

        int diasNoMes;
        if (mes == 2) {
            bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
            diasNoMes = bissexto ? 29 : 28; // Fevereiro
        } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            diasNoMes = 30; // Abril, Junho, Setembro, Novembro
        } else {
            diasNoMes = 31; // Janeiro, Março, Maio, Julho, Agosto, Outubro, Dezembro
        }

        if (dia < 1 || dia > diasNoMes) {
            return false;
        }

        return true;
    } 

    return false; // Caso o formato da string seja inválido
}
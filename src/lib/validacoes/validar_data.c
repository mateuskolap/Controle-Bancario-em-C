/**
 * Autor......: Mateus kolapouski
 * Data.......: 31/10/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * Objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * Subfunção..: Verificar se a data inserida é válida
 */


#include "../../include/funcoes.h"
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>


/**
 * @brief Valida uma data fornecida como string no formato "dd/mm/aaaa".
 * 
 * A função verifica se a data fornecida está no formato correto e se é uma data válida,
 * levando em consideração os meses, anos bissextos e o intervalo de anos permitido (de 1900 até o ano atual).
 * 
 * @param data String representando a data no formato "dd/mm/aaaa".
 * @return `true` se a data for válida; caso contrário, retorna `false`.
 * 
 * @note A função utiliza a biblioteca `time.h` para obter o ano atual. 
 */
bool ValidarData(char data[]) {
    // Variáveis para separação dos valores das datas
    int dia, mes, ano;

    // Obtendo o ano atual
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    int anoAtual = tm_info->tm_year + 1900;

    // Verificando se a entrada do usuário está no formato correto
    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) == 3) {
        // Validando o ano (serão aceitos somente valores acima de 1900)
        if (ano < 1900 || ano > anoAtual) {
            return false;
        }

        // Validando o mes inserido
        if (mes < 1 || mes > 12) {
            return false;
        }

        // Casos especiais para os dias dos meses
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
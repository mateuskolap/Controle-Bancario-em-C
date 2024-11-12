/**
 * Autor......: Rian da Cruz
 * Data.......: 12/11/2024
 * Equipe.....: 150020-2023 Mateus kolapouski
 *              231597-2024 Rian da Cruz
 * 
 * objetivo...: criar um sistema bancario para registro de contas e transações
 * 
 * subfunção..: cabeçalho lista duplamente encadeada
 */



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "include/linked_list.h"
#include "include/doubly_linked_list.h"
#include "include/screens.h"

int main() {

    
    
    int opc=0;

    do{
        main_menu();

        gotoxy(7,23);
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:

            int op=0;

            do
            {
                subMenu();

                gotoxy(7,23);
                scanf("%d", &op);

                if (op = 1) {
                    registration_query();

                    gotoxy(16,5);
                    scanf("%d", &bank_account.codigo_conta);

                    gotoxy(16,7);
                    scanf("%s", &bank_account.banco);

                    gotoxy(16,9);
                    scanf("%s", &bank_account.agencia);

                    gotoxy(16,11);
                    scanf("%s", &bank_account.numero_conta);

                    gotoxy(16,13);
                    scanf("%s", &bank_account.tipo_conta);

                    gotoxy(16,15);
                    scanf("%d", &bank_account.vl_saldo);

                    gotoxy(16,17);
                    scanf("%d", &bank_account.vl_limite);

                    gotoxy(16,19);
                    scanf("%s", &bank_account.status);


                    
                }


                
            } while (op!=5);
            


            break;
        case 2:
            Financial_Transaction();
            break;
        default:
            break;
        }

    } while (opc != 3);

    return 0;
}

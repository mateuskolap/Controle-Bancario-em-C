#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "include/funcoes.h"



int main() {

    LinkedList *L = CriarListaContas();  
    
    int opc=0;

    do{
        main_menu();

        gotoxy(7,23);
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:

            int op = 0;
            
            do
            {
                subMenu();
                

                gotoxy(7,23);
                scanf("%d", &op);

                if (op = 1) {
                    bank_account conta;

                }
            
            } while (op!=5);
            


            break;
        case 2:

            break;
        default:
            break;
        }
    } while (opc != 3);

    return 0;
}

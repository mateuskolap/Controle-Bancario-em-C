/**
 * 
 */



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "include/linked_list.h"
#include "include/screens.h"

int main() {
    
    int opc;

    do{
        main_menu();

        gotoxy(7,23);
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            subMenu();

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

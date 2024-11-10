#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "include/linked_list.h"
#include "include/screens.h"

int main() {
    
    int opc;

    do{
        screen();
        main_menu();

        gotoxy(7,23);
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            system("cls");
            screen();
            subMenu();
            break;
        case 2:
            system("cls");
            screen();
            Financial_Transaction();
        default:
            break;
        }
    } while (opc != 3);

    return 0;
}

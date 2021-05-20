#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <locale.h>

#include "debugmalloc.h"
#include "gyakeslabmenu.h"
#include "hallgatokmenu.h"
#include "oktatokmenu.h"
#include "structok.h"


int main(){
    setlocale(LC_ALL, "");
    SetConsoleCP(1250); SetConsoleOutputCP(1250);
    int valasz;
    bool vege=false;
    do{
        printf("A következõ gombokkal érheted el a lent látható menüket:\n"
               "1:Hallgatók menü.\n"
               "2:Oktatók menü.\n"
               "3:Gyakorlatok es laborok menü.\n"
               "9:Kilépés a programból.\n");
        scanf("%d", &valasz);
        switch (valasz) {
            case 1:
                printf("Hallgatók menü megnyitva:\n");
                hallgatokm(&vege);
                if(vege)
                    valasz=9;
                break;
            case 2:
                printf("Oktatók menü megnyitva:\n");
                oktatokm(&vege);
                if(vege)
                    valasz=9;
                break;
            case 3:
                printf("Gyakorlatok es laborok menü megnyitva:\n");
                gyakeslabm(&vege);
                if(vege)
                    valasz=9;
                break;
            case 9:
                printf("Kilépve a programból.\n");
                break;
            default:
                printf("Érvénytelen válasz, add meg újra!\n");
                break;
        }
    }while(valasz!=9);
    return 0;
}

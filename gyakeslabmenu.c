#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "debugmalloc.h"
#include "gyakeslabmenu.h"
#include "listaz.h"
#include "keresesek.h"
#include "hozzaad.h"
#include "torol.h"


void gyakeslabm(bool *vege){
    int valasz;
    do{
        printf("A következõ gombokkal érheted el a lent látható menüket:\n"
               "1:Labor hozzáadása.\n"
               "2:Gyakorlat hozzáadása.\n"
               "3:Labor törlése.\n"
               "4:Gyakorlat törlése.\n"
               "5:Laborok kilistázása.\n"
               "6:Gyakorlatok kilistázása.\n"
               "7:Kilépés a fõmenübe.\n"
               "8:Kilépés a programból.\n");
        scanf("%d", &valasz);
        switch (valasz) {
            case 1:hozzaad_lab();
                break;
            case 2:hozzaad_gyak();
                break;
            case 3:torol_lab();
                break;
            case 4:torol_gyak();
                break;
            case 5:lablista();
                break;
            case 6:gyaklista();
                break;
            case 7:
                printf("Visszalépve a fõmenübe.\n");
                break;
            case 8:
                printf("Kilépve a programból.\n");
                *vege=true;
                break;
            default:
                printf("Érvenytelen válasz, add meg újra!\n");
                break;
        }
    }while(!(valasz==7 || valasz==8));
}

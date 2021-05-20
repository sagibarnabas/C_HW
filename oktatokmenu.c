#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "debugmalloc.h"
#include "oktatokmenu.h"
#include "listaz.h"
#include "keresesek.h"
#include "modosit.h"
#include "hozzaad.h"
#include "torol.h"


void oktatokm(bool* vege){
    int valasz;
    do{
        printf("A következõ gombokkal érheted el a lent látható menüket:\n"
               "1:Oktató hozzáadása.\n"
               "2:Oktató adatainak módosítása(név alapján).\n"
               "3:Oktató törlése.\n"
               "4.Oktató keresése(név alapján).\n"
               "5:Oktatók kilistázása.\n"
               "6:Kilépés a fõmenübe.\n"
               "7:Kilépés a programból.\n");
        scanf("%d", &valasz);
        switch (valasz) {
            case 1:hozzaad_oktato();
                break;
            case 2:modosit_oktato();
                break;
            case 3:torol_oktato();
                break;
            case 4:keres_oktato();
                break;
            case 5:oktatolista();
                break;
            case 6:
                printf("Visszalépve a fõmenübe.\n");
                break;
            case 7:
                printf("Kilépve a programból.\n");
                *vege=true;
                break;
            default:
                printf("Érvénytelen válasz, add meg újra!\n");
                break;
        }
    }while(!(valasz==6 || valasz==7));
}

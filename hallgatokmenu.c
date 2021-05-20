#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "debugmalloc.h"
#include "hallgatokmenu.h"
#include "listaz.h"
#include "keresesek.h"
#include "modosit.h"
#include "hozzaad.h"
#include "torol.h"


void hallgatokm(bool * vege){
    int valasz;
    do{
        printf("A következõ gombokkal érheted el a lenti menüket:\n"
               "1:A tárgykövetelmények meglétének ellenõrzése lista.\n"
               "2:PótZH írása szükséges lista.\n"
               "3:HF pótlása szükséges lista.\n"
               "4:Pontok szerinti sorbarendezés.\n"
               "5:NEPTUN-kód szerinti keresés.\n"
               "6:Név szerinti keresés.\n"
               "7:Adatok módosítása(NEPTUN-kód alapján).\n"
               "8:Hallgató hozzáadása.\n"
               "9:Hallgató törlése(NEPTUN-kód alapján).\n"
               "10:Kilépés a fõmenübe.\n"
               "11:Kilépés a programból.\n");
        scanf("%d", &valasz);
        switch (valasz) {
            case 1:kovetelmenyeklista();
                break;
            case 2:potzh();
                break;
            case 3:hfhiany();
                break;
            case 4:tanulolista();
                break;
            case 5:keres_diak_neptun();
                break;
            case 6:keres_diak();
                break;
            case 7:modosit_diak();
                break;
            case 8:hozzaad_diak();
                break;
            case 9:torol_diak();
                break;
            case 10:
                printf("Visszalépve a fõmenübe.\n");
                break;
            case 11:
                printf("Kilépve a programból.\n");
                *vege=true;
                break;
            default:
                printf("Érvénytelen válasz, add meg újra!\n");
                break;
        }
    }while(!(valasz==10 || valasz==11));
}

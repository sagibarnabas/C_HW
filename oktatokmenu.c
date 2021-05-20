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
        printf("A k�vetkez� gombokkal �rheted el a lent l�that� men�ket:\n"
               "1:Oktat� hozz�ad�sa.\n"
               "2:Oktat� adatainak m�dos�t�sa(n�v alapj�n).\n"
               "3:Oktat� t�rl�se.\n"
               "4.Oktat� keres�se(n�v alapj�n).\n"
               "5:Oktat�k kilist�z�sa.\n"
               "6:Kil�p�s a f�men�be.\n"
               "7:Kil�p�s a programb�l.\n");
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
                printf("Visszal�pve a f�men�be.\n");
                break;
            case 7:
                printf("Kil�pve a programb�l.\n");
                *vege=true;
                break;
            default:
                printf("�rv�nytelen v�lasz, add meg �jra!\n");
                break;
        }
    }while(!(valasz==6 || valasz==7));
}

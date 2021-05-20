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
        printf("A k�vetkez� gombokkal �rheted el a lent l�that� men�ket:\n"
               "1:Labor hozz�ad�sa.\n"
               "2:Gyakorlat hozz�ad�sa.\n"
               "3:Labor t�rl�se.\n"
               "4:Gyakorlat t�rl�se.\n"
               "5:Laborok kilist�z�sa.\n"
               "6:Gyakorlatok kilist�z�sa.\n"
               "7:Kil�p�s a f�men�be.\n"
               "8:Kil�p�s a programb�l.\n");
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
                printf("Visszal�pve a f�men�be.\n");
                break;
            case 8:
                printf("Kil�pve a programb�l.\n");
                *vege=true;
                break;
            default:
                printf("�rvenytelen v�lasz, add meg �jra!\n");
                break;
        }
    }while(!(valasz==7 || valasz==8));
}

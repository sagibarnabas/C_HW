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
        printf("A k�vetkez� gombokkal �rheted el a lenti men�ket:\n"
               "1:A t�rgyk�vetelm�nyek megl�t�nek ellen�rz�se lista.\n"
               "2:P�tZH �r�sa sz�ks�ges lista.\n"
               "3:HF p�tl�sa sz�ks�ges lista.\n"
               "4:Pontok szerinti sorbarendez�s.\n"
               "5:NEPTUN-k�d szerinti keres�s.\n"
               "6:N�v szerinti keres�s.\n"
               "7:Adatok m�dos�t�sa(NEPTUN-k�d alapj�n).\n"
               "8:Hallgat� hozz�ad�sa.\n"
               "9:Hallgat� t�rl�se(NEPTUN-k�d alapj�n).\n"
               "10:Kil�p�s a f�men�be.\n"
               "11:Kil�p�s a programb�l.\n");
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
                printf("Visszal�pve a f�men�be.\n");
                break;
            case 11:
                printf("Kil�pve a programb�l.\n");
                *vege=true;
                break;
            default:
                printf("�rv�nytelen v�lasz, add meg �jra!\n");
                break;
        }
    }while(!(valasz==10 || valasz==11));
}

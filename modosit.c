#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debugmalloc.h"
#include "kiir.h"
#include "hozzaad.h"
#include "keresesek.h"
#include "beolvas.h"
#include "felszabadit.h"


void modosit_diak(){
    diak* eleje=beolvas_diak(false);
    diak* mozgo=eleje;
    char neptun[7];
    char criterium[51];
    do{
        printf("�rj be egy Neptun-k�dot, ami alapj�n m�dos�tan�l!\n");
        scanf("\n%[^\n]", neptun);
    }while(!(strlen(neptun)==6 || strcmp(neptun,"0")==0));
    if(strcmp(neptun,"0")!=0){
        while (mozgo != NULL && strcmp(mozgo->neptun,neptun)!=0) {
            mozgo = mozgo->kov;
        }
        do{
            printf("H�ny pontos kisZH-kat �rt �sszesen?\n");
            scanf("\n%[^\n]", criterium);
        }while(!(atoi(criterium)>=-1 && (atoi(criterium)<=40 && strlen(criterium)==2)));
        if(strcmp(criterium,"-1")!=0){
            strcpy(mozgo->kiszh, criterium);
        }
        do{
            printf("H�ny pontos nagyZH-kat �rt �sszesen?\n");
            scanf("\n%[^\n]", criterium);
        }while(!(atoi(criterium)>=-1 && (atoi(criterium)<=80 && strlen(criterium)==2)));
        if(strcmp(criterium,"-1")!=0){
            strcpy(mozgo->nagyzh, criterium);
        }
        do{
            printf("H�ny pontos h�zifeladatot �rt?\n");
            scanf("\n%[^\n]", criterium);
        }while(!(atoi(criterium)>=-1 && (atoi(criterium)<=20 && strlen(criterium)==2)));
        if(strcmp(criterium,"-1")!=0){
            strcpy(mozgo->hf, criterium);
        }
        do{
            printf("H�ny labort teljes�tett?\n");
            scanf("\n%[^\n]", criterium);
        }while(!(atoi(criterium)>=-1 && (atoi(criterium)<=20) && strlen(criterium)==2));
        if(strcmp(criterium,"-1")!=0){
            strcpy(mozgo->labordb, criterium);
        }
        do{
            printf("Melyik laboron van?\n");
            scanf("\n%[^\n]", criterium);
        }while(!(strcmp(criterium,"-1")==0 || (keres_lab(criterium) && strlen(criterium)==3)));
        if(strcmp(criterium,"-1")!=0){
            strcpy(mozgo->labor, criterium);
        }
        do{
            printf("Melyik gyakorlaton van?\n");
            scanf("\n%[^\n]", criterium);
        }while(!(strcmp(criterium,"-1")==0 || (keres_gyak(criterium) && strlen(criterium)==3)));
        if(strcmp(criterium,"-1")!=0){
            strcpy(mozgo->gyak, criterium);
        }
        do{
            printf("Melyik eload�son van?\n");
            scanf("\n%[^\n]", criterium);
        }while(!(strcmp(criterium,"-1")==0 ||((strcmp(criterium, "E1")==0|| strcmp(criterium, "E2")==0) && strlen(criterium)==2)));
        if(strcmp(criterium,"-1")!=0){
            strcpy(mozgo->ea, criterium);
        }
        printf("Sikeres m�dos�t�s.\n\n");
        kiir_diak(eleje);
    }else if(strcmp(neptun,"0")==0){
        printf("Sikeres megszak�t�s.\n\n");
    }
    free_diak(eleje);
}

void modosit_oktato(){
    oktato*eleje=beolvas_oktato();
    oktato*mozgo=eleje;
    char criterium[51];
    char neve[51];
    printf("Melyik oktat� legyen m�dos�tva(n�v)?\n");
    scanf("\n%[^\n]", neve);
    if(strcmp(neve,"0")!=0){
        while (mozgo != NULL && strcmp(mozgo->nev,neve)!=0) {
            mozgo = mozgo->kov;
        }
        do{
            printf("Melyik laboron van?\n");
            scanf("\n%[^\n]", criterium);
        }while(!(strcmp(criterium,"-1")==0 || (keres_lab(criterium) && strlen(criterium)==3)));
        if(strcmp(criterium,"-1")!=0){
            strcpy(mozgo->labor, criterium);
        }
        do{
            printf("Melyik gyakorlaton van?\n");
            scanf("\n%[^\n]", criterium);
        }while(!(strcmp(criterium,"-1")==0 || (keres_gyak(criterium) && strlen(criterium)==3)));
        if(strcmp(criterium,"-1")!=0){
            strcpy(mozgo->gyak, criterium);
        }
        do{
            printf("Melyik eload�son van?\n");
            scanf("\n%[^\n]", criterium);
        }while(!(strcmp(criterium,"-1")==0 ||((strcmp(criterium, "E1")==0|| strcmp(criterium, "E2")==0) && strlen(criterium)==2)));
        if(strcmp(criterium,"-1")!=0){
            strcpy(mozgo->ea, criterium);
        }
        kiir_oktato(eleje);
        printf("Sikeres m�dos�t�s.\n\n");
    }else if(strcmp(neve,"0")==0){
        printf("Sikeres megszak�t�s.\n\n");
    }
    free_oktato(eleje);
}

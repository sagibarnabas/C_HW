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
        printf("Írj be egy Neptun-kódot, ami alapján módosítanál!\n");
        scanf("\n%[^\n]", neptun);
    }while(!(strlen(neptun)==6 || strcmp(neptun,"0")==0));
    if(strcmp(neptun,"0")!=0){
        while (mozgo != NULL && strcmp(mozgo->neptun,neptun)!=0) {
            mozgo = mozgo->kov;
        }
        do{
            printf("Hány pontos kisZH-kat írt összesen?\n");
            scanf("\n%[^\n]", criterium);
        }while(!(atoi(criterium)>=-1 && (atoi(criterium)<=40 && strlen(criterium)==2)));
        if(strcmp(criterium,"-1")!=0){
            strcpy(mozgo->kiszh, criterium);
        }
        do{
            printf("Hány pontos nagyZH-kat írt összesen?\n");
            scanf("\n%[^\n]", criterium);
        }while(!(atoi(criterium)>=-1 && (atoi(criterium)<=80 && strlen(criterium)==2)));
        if(strcmp(criterium,"-1")!=0){
            strcpy(mozgo->nagyzh, criterium);
        }
        do{
            printf("Hány pontos házifeladatot írt?\n");
            scanf("\n%[^\n]", criterium);
        }while(!(atoi(criterium)>=-1 && (atoi(criterium)<=20 && strlen(criterium)==2)));
        if(strcmp(criterium,"-1")!=0){
            strcpy(mozgo->hf, criterium);
        }
        do{
            printf("Hány labort teljesített?\n");
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
            printf("Melyik eloadáson van?\n");
            scanf("\n%[^\n]", criterium);
        }while(!(strcmp(criterium,"-1")==0 ||((strcmp(criterium, "E1")==0|| strcmp(criterium, "E2")==0) && strlen(criterium)==2)));
        if(strcmp(criterium,"-1")!=0){
            strcpy(mozgo->ea, criterium);
        }
        printf("Sikeres módosítás.\n\n");
        kiir_diak(eleje);
    }else if(strcmp(neptun,"0")==0){
        printf("Sikeres megszakítás.\n\n");
    }
    free_diak(eleje);
}

void modosit_oktato(){
    oktato*eleje=beolvas_oktato();
    oktato*mozgo=eleje;
    char criterium[51];
    char neve[51];
    printf("Melyik oktató legyen módosítva(név)?\n");
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
            printf("Melyik eloadáson van?\n");
            scanf("\n%[^\n]", criterium);
        }while(!(strcmp(criterium,"-1")==0 ||((strcmp(criterium, "E1")==0|| strcmp(criterium, "E2")==0) && strlen(criterium)==2)));
        if(strcmp(criterium,"-1")!=0){
            strcpy(mozgo->ea, criterium);
        }
        kiir_oktato(eleje);
        printf("Sikeres módosítás.\n\n");
    }else if(strcmp(neve,"0")==0){
        printf("Sikeres megszakítás.\n\n");
    }
    free_oktato(eleje);
}

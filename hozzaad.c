#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "felszabadit.h"
#include "debugmalloc.h"
#include "kiir.h"
#include "beolvas.h"
#include "hozzaad.h"
#include "keresesek.h"

void hozzaad_diak(){
    diak *uj;
    char criterium[51];
    uj = (diak*) malloc(sizeof(diak));
    printf("Mi a diák neve?\n");
    scanf("\n%[^\n]", uj->nev);
    do{
        printf("Mi a diák Neptun-kódja?\n");
        scanf("\n%[^\n]", criterium);
    }while(!(strlen(criterium)==6));
    strcpy(uj->neptun, criterium);
    do{
        printf("Hány pontos kisZH-kat írt összesen?\n");
        scanf("\n%[^\n]", criterium);
    }while(!(atoi(criterium)<=40 && strlen(criterium)==2));
    strcpy(uj->kiszh, criterium);
    do{
        printf("Hány pontos nagyZH-kat írt összesen?\n");
        scanf("\n%[^\n]", criterium);
    }while(!(atoi(criterium)<=80 && strlen(criterium)==2));
    strcpy(uj->nagyzh, criterium);
    do{
        printf("Hány pontos házifeladatot írt?\n");
        scanf("\n%[^\n]", criterium);
    }while(!(atoi(criterium)<=20 && strlen(criterium)==2));
    strcpy(uj->hf, criterium);
    do{
        printf("Hány labort teljesített?\n");
        scanf("\n%[^\n]", criterium);
    }while(!(atoi(criterium)<=20 && strlen(criterium)==2));
    strcpy(uj->labordb, criterium);
    do{
        printf("Melyik laboron van?\n");
        scanf("\n%[^\n]", criterium);
    }while(!(keres_lab(criterium) && strlen(criterium)==3));
    strcpy(uj->labor, criterium);
    do{
        printf("Melyik gyakorlaton van?\n");
        scanf("\n%[^\n]", criterium);
    }while(!(keres_gyak(criterium) && strlen(criterium)==3));
    strcpy(uj->gyak, criterium);
    do{
        printf("Melyik elõadáson van?\n");
        scanf("\n%[^\n]", criterium);
    }while(!((strcmp(criterium, "E1")==0|| strcmp(criterium, "E2")==0) && strlen(criterium)==2));
    strcpy(uj->ea, criterium);
    diak* eleje=beolvas_diak(false);
    diak* mozgo=eleje;
    while (mozgo->kov != NULL)
        mozgo = mozgo->kov;
    mozgo->kov = uj;
    uj->kov = NULL;
    kiir_diak(eleje);
    printf("Sikeres hozzáadás.\n\n");
    free_diak(eleje);
}

void hozzaad_oktato(){
    oktato *uj;
    char criterium[51];
    uj = (oktato*) malloc(sizeof(oktato));
    printf("Mi az oktató neve?\n");
    scanf("\n%[^\n]", uj->nev);
    do{
        printf("Melyik laboron van?\n");
        scanf("\n%[^\n]", criterium);
    }while(!(keres_lab(criterium) && strlen(criterium)==3));
    strcpy(uj->labor, criterium);
    do{
        printf("Melyik gyakorlaton van?\n");
        scanf("\n%[^\n]", criterium);
    }while(!(keres_gyak(criterium) && strlen(criterium)==3));
        strcpy(uj->gyak, criterium);
    do{
        printf("Melyik elõadáson van?\n");
        scanf("\n%[^\n]", criterium);
    }while(!((strcmp(criterium, "E1")==0|| strcmp(criterium, "E2")==0) && strlen(criterium)==2));
    strcpy(uj->ea, criterium);
    oktato* eleje=beolvas_oktato();
    oktato* mozgo=eleje;
    while (mozgo->kov != NULL)
        mozgo = mozgo->kov;
    mozgo->kov = uj;
    uj->kov = NULL;
    kiir_oktato(eleje);
    printf("Sikeres hozzáadás.\n\n");
    free_oktato(eleje);
}

void hozzaad_lab(){
    lab *uj;
    char criterium[51];
    uj = (lab*) malloc(sizeof(lab));
    do{
        printf("Mi a labor neve?\n");
        scanf("\n%[^\n]", criterium);
    }while(!(strlen(criterium)==3));
        strcpy(uj->nev, criterium);
    lab* eleje=beolvas_lab();
    lab* mozgo=eleje;
    while (mozgo->kov != NULL)
        mozgo = mozgo->kov;
    mozgo->kov = uj;
    uj->kov = NULL;
    kiir_lab(eleje);
    printf("Sikeres hozzáadás.\n\n");
    free_lab(eleje);
}

void hozzaad_gyak(){
    gyak *uj;
    char criterium[51];
    uj = (gyak*) malloc(sizeof(gyak));
    do{
    printf("Mi a gyakorlat neve?\n");
    scanf("\n%[^\n]", criterium);
    }while(!(strlen(criterium)==3));
    strcpy(uj->nev, criterium);
    gyak* eleje=beolvas_gyak();
    gyak* mozgo=eleje;
    while (mozgo->kov != NULL)
        mozgo = mozgo->kov;
    mozgo->kov = uj;
    uj->kov = NULL;
    kiir_gyak(eleje);
    printf("Sikeres hozzáadás.\n\n");
    free_gyak(eleje);
}

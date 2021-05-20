#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debugmalloc.h"
#include "kiir.h"
#include "keresesek.h"
#include "beolvas.h"
#include "structok.h"
#include "felszabadit.h"


void torol_diak(){
    diak* lemarado=NULL;
    diak* eleje=beolvas_diak(false);
    diak* mozgo=eleje;
    char neptun[7];
    do{
        printf("Írj be egy Neptun-kódot, ami alapján törölnél!\n");
        scanf("\n%[^\n]", neptun);
    }while(!(strlen(neptun)==6 || strcmp(neptun,"0")==0));
    if(strcmp(neptun,"0")!=0){
        while (mozgo != NULL && (strcmp(mozgo->neptun,neptun))!=0) {
            lemarado = mozgo;
            mozgo = mozgo->kov;
        }
        if (mozgo == NULL) {
            printf("Nincs ilyen Neptun-kód.\n\n");
        }else if(lemarado == NULL) {
            diak *ujeleje = mozgo->kov;
            eleje = ujeleje;
            free(mozgo);
            printf("Sikeres törlés.\n\n");
        }else{
            lemarado->kov = mozgo->kov;
            free(mozgo);
            printf("Sikeres törlés.\n\n");
        }
        kiir_diak(eleje);
    }else if(strcmp(neptun,"0")==0){
        printf("Sikeres megszakás.\n\n");
    }
    free_diak(eleje);
}

void torol_oktato(){
    oktato* lemarado=NULL;
    oktato* eleje=beolvas_oktato();
    oktato* mozgo=eleje;
    char neve[51];
        printf("Melyik oktató legyen törölve(Név)?\n");
        scanf("\n%[^\n]", neve);
    if(strcmp(neve, "0")!=0){
        while (mozgo != NULL && strcmp(mozgo->nev,neve)!=0) {
            lemarado = mozgo;
            mozgo = mozgo->kov;
        }
        if (mozgo == NULL) {
            printf("Nincs ilyen nevû oktató.\n\n");
        }else if(lemarado == NULL) {
            oktato *ujeleje = mozgo->kov;
            free(mozgo);
            eleje = ujeleje;
            printf("Sikeres törlés.\n\n");
        }else{
            lemarado->kov = mozgo->kov;
            free(mozgo);
            printf("Sikeres törlés.\n\n");
        }
        kiir_oktato(eleje);
    }else if(strcmp(neve,"0")==0){
        printf("Sikeres megszakítás.\n\n");
    }
    free_oktato(eleje);
}

void torol_lab(){
    lab* lemarado=NULL;
    lab* eleje=beolvas_lab();
    lab* mozgo=eleje;
    char labom[4];
    do{
        printf("Melyik labor legyen törölve?\n");
        scanf("\n%[^\n]", labom);
    }while(!(strlen(labom)==3 || strcmp(labom,"0")==0));
    if(strcmp(labom,"0")!=0){
        while (mozgo != NULL && strcmp(mozgo->nev,labom)!=0) {
            lemarado = mozgo;
            mozgo = mozgo->kov;
        }
        if (mozgo == NULL) {
            printf("Nincs ilyen labor.\n\n");
        }else if(lemarado == NULL) {
            lab *ujeleje = mozgo->kov;
            free(mozgo);
            eleje = ujeleje;
            printf("Sikeres törlés.\n\n");
        }else{
            lemarado->kov = mozgo->kov;
            free(mozgo);
            printf("Sikeres törlés.\n\n");
        }
        kiir_lab(eleje);
    }else if(strcmp(labom,"0")==0){
        printf("Sikeres megszakítás.\n\n");
    }
    free_lab(eleje);
}

void torol_gyak(){
    gyak* lemarado=NULL;
    gyak* eleje=beolvas_gyak();
    gyak* mozgo=eleje;
    char gyakom[4];
    do{
        printf("Melyik gyakorlat legyen törölve?\n");
        scanf("\n%[^\n]", gyakom);
    }while(!(strlen(gyakom)==3 || strcmp(gyakom,"0")==0));
    if(strcmp(gyakom,"0")!=0){
        while (mozgo != NULL && strcmp(mozgo->nev,gyakom)!=0) {
            lemarado = mozgo;
            mozgo = mozgo->kov;
        }
        if (mozgo == NULL) {
            printf("Nincs ilyen labor.\n\n");
        }else if(lemarado == NULL) {
            gyak *ujeleje = mozgo->kov;
            free(mozgo);
            eleje = ujeleje;
            printf("Sikeres törlés.\n\n");
        }else{
            lemarado->kov = mozgo->kov;
            free(mozgo);
            printf("Sikeres törlés.\n\n");
        }
        kiir_gyak(eleje);
    }else if(strcmp(gyakom,"0")==0){
        printf("Sikeres megszakítás.\n\n");
    }
    free_gyak(eleje);
}

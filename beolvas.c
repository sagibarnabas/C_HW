#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "debugmalloc.h"
#include "structok.h"
#include "beolvas.h"


static bool pontokszerint(diak*elem1,diak*elem2, bool pontoktrue){
    if(pontoktrue){
        return (atoi(elem2->kiszh)+atoi(elem2->nagyzh)+atoi(elem2->hf))<=(atoi(elem1->kiszh)+atoi(elem1->nagyzh)+atoi(elem1->hf));
    }else{
        return strcmp(elem1->nev,elem2->nev)<0;
    }
}

diak* beolvas_diak(bool pontoktrue){
    char diakszoveg[100];
    FILE* fp;
    fp = fopen("DIAK.txt", "rt");
    if (fp == NULL) {
        perror("Nem lehet megnyitni a fájlt!");
        return NULL;
    }
    diak *eleje=NULL;
    while(fgets(diakszoveg, 100, fp)) {
        diak *uj;
        uj = (diak*) malloc(sizeof(diak));
        for(int i=0; i<(strstr(diakszoveg, ",")-diakszoveg); i++){
            uj->nev[i]=diakszoveg[i];
        }
        uj->nev[(strstr(diakszoveg, ",")-diakszoveg)]='\0';
        for(int i=0; i<6; i++){
            uj->neptun[i]=diakszoveg[i+(strstr(diakszoveg, ",")-diakszoveg)+1];
        }
        uj->neptun[6]='\0';
        for(int i=0; i<2; i++){
            uj->kiszh[i]=diakszoveg[i+(strstr(diakszoveg, ",")-diakszoveg)+8];
        }
        uj->kiszh[2]='\0';
        for(int i=0; i<2; i++){
            uj->nagyzh[i]=diakszoveg[i+(strstr(diakszoveg, ",")-diakszoveg)+11];
        }
        uj->nagyzh[2]='\0';
        for(int i=0; i<2; i++){
            uj->hf[i]=diakszoveg[i+(strstr(diakszoveg, ",")-diakszoveg)+14];
        }
        uj->hf[2]='\0';
        for(int i=0; i<2; i++){
            uj->labordb[i]=diakszoveg[i+(strstr(diakszoveg, ",")-diakszoveg)+17];
        }
        uj->labordb[2]='\0';
        for(int i=0; i<3; i++){
            uj->labor[i]=diakszoveg[i+(strstr(diakszoveg, ",")-diakszoveg)+20];
        }
        uj->labor[3]='\0';
        for(int i=0; i<3; i++){
            uj->gyak[i]=diakszoveg[i+(strstr(diakszoveg, ",")-diakszoveg)+24];
        }
        uj->gyak[3]='\0';
        for(int i=0; i<2; i++){
            uj->ea[i]=diakszoveg[i+(strstr(diakszoveg, ",")-diakszoveg)+28];
        }
        uj->ea[2]='\0';
        uj->kov = NULL;
        diak *lemarado = NULL;
        diak *mozgo = eleje;
        while (mozgo != NULL && pontokszerint(mozgo, uj, pontoktrue)) {
            lemarado = mozgo;
            mozgo = mozgo->kov;
        }
        if (lemarado == NULL) {
            uj->kov = eleje;
            eleje = uj;
        }else{
            lemarado->kov = uj;
            uj->kov = mozgo;
        }
    }
    fclose(fp);
    return eleje;
}

oktato* beolvas_oktato(){
    char oktatoszoveg[100];
    FILE* fp;
    fp = fopen("OKTATO.txt", "rt");
    if (fp == NULL) {
        perror("Nem lehet megnyitni a fájlt!");
        return NULL;
    }
    oktato *eleje=NULL;
    while(fgets(oktatoszoveg, 100, fp)) {
        oktato *uj;
            uj = (oktato*) malloc(sizeof(oktato));
        for(int i=0; i<(strstr(oktatoszoveg, ",")-oktatoszoveg); i++){
            uj->nev[i]=oktatoszoveg[i];
        }
        uj->nev[(strstr(oktatoszoveg, ",")-oktatoszoveg)]='\0';
        for(int i=0; i<3; i++){
            uj->labor[i]=oktatoszoveg[i+(strstr(oktatoszoveg, ",")-oktatoszoveg)+1];
        }
        uj->labor[3]='\0';
        for(int i=0; i<3; i++){
            uj->gyak[i]=oktatoszoveg[i+(strstr(oktatoszoveg, ",")-oktatoszoveg)+5];
        }
        uj->gyak[3]='\0';
        for(int i=0; i<2; i++){
            uj->ea[i]=oktatoszoveg[i+(strstr(oktatoszoveg, ",")-oktatoszoveg)+9];
        }
        uj->ea[2]='\0';
        uj->kov = NULL;
        oktato *lemarado = NULL;
        oktato *mozgo = eleje;
        while (mozgo != NULL && strcmp(mozgo->nev,uj->nev)<0) {
            lemarado = mozgo;
            mozgo = mozgo->kov;
        }
        if (lemarado == NULL) {
            uj->kov = eleje;
            eleje = uj;
        } else {
            lemarado->kov = uj;
            uj->kov = mozgo;
        }
    }
    fclose(fp);
    return eleje;
}

gyak* beolvas_gyak(void){
    char gyakszoveg[100];
    FILE* fp;
    fp = fopen("GYAK.txt", "rt");
    if (fp == NULL) {
        perror("Nem lehet megnyitni a fájlt!");
        return NULL;
    }
    gyak* eleje=NULL;
    while(fgets(gyakszoveg, 100, fp)) {
        gyak *uj;
        uj = (gyak*) malloc(sizeof(gyak));
        strcpy(uj->nev, gyakszoveg);
        uj->nev[3]='\0';
        uj->kov = NULL;
        gyak *lemarado = NULL;
        gyak *mozgo = eleje;
        while (mozgo != NULL && strcmp(mozgo->nev,uj->nev)<0) {
            lemarado = mozgo;
            mozgo = mozgo->kov;
        }
        if (lemarado == NULL) {
            uj->kov = eleje;
            eleje = uj;
        } else {
            lemarado->kov = uj;
            uj->kov = mozgo;
        }
    }
    fclose(fp);
    return eleje;
}

lab* beolvas_lab(void){
    char labszoveg[100];
    FILE* fp;
    fp = fopen("LAB.txt", "rt");
    if (fp == NULL) {
        perror("Nem lehet megnyitni a fájlt!");
        return NULL;
    }
    lab* eleje=NULL;
    while(fgets(labszoveg, 100, fp)) {
        lab *uj;
        uj = (lab*) malloc(sizeof(lab));
        strcpy(uj->nev, labszoveg);
        uj->nev[3]='\0';
        uj->kov = NULL;
        lab *lemarado = NULL;
        lab *mozgo = eleje;
        while (mozgo != NULL && strcmp(mozgo->nev,uj->nev)<0) {
            lemarado = mozgo;
            mozgo = mozgo->kov;
        }
        if (lemarado == NULL) {
            uj->kov = eleje;
            eleje = uj;
        } else {
            lemarado->kov = uj;
            uj->kov = mozgo;
        }
    }
    fclose(fp);
    return eleje;
}

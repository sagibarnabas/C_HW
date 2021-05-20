#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "debugmalloc.h"
#include "structok.h"
#include "beolvas.h"
#include "keresesek.h"
#include "felszabadit.h"
#include "listaz.h"

void keres_diak(){
    bool vanilyen=false;
    printf("\nKit keresel?\n");
    char nev[51];
    scanf("\n%[^\n]", nev);
    diak* eleje= beolvas_diak(false);
    diak *mozgo;
    for (mozgo=eleje; mozgo != NULL; mozgo = mozgo->kov){
        if(strcmp(mozgo->nev, nev)==0){
            printf("Név:%s, Neptun-kód:%s, KisZH eredmények:%s, NagyZH eredmények:%s, Házifeladat eredménye:%s,\nTeljesített laborok száma:%s, Labor csoport:%s, Gyakorlat csoport:%s, Eloadás csoport:%s\n"
            ,mozgo->nev,mozgo->neptun, mozgo->kiszh, mozgo->nagyzh,mozgo->hf,mozgo->labordb,mozgo->labor,mozgo->gyak,mozgo->ea);
            vanilyen=true;
        }
    }
    nincsilyen(vanilyen);
    printf("\n");
    free_diak(eleje);
}


void keres_diak_neptun(){
    bool vanilyen=false;
    char neptun[7];
    do{
    printf("\nÍrj be egy Neptun-kódot, ami alapján keresel!\n");
    scanf("\n%[^\n]", neptun);
    }while(!(strlen(neptun)==6));
    diak* eleje= beolvas_diak(false);
    diak *mozgo;
    for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov){
        if(strcmp(mozgo->neptun, neptun)==0){
            printf("Név:%s, Neptun-kód:%s, KisZH eredmények:%s, NagyZH eredmények:%s, Házifeladat eredménye:%s,\nTeljesített laborok száma:%s, Labor csoport:%s, Gyakorlat csoport:%s, Eloadás csoport:%s\n"
            ,mozgo->nev,mozgo->neptun, mozgo->kiszh, mozgo->nagyzh,mozgo->hf,mozgo->labordb,mozgo->labor,mozgo->gyak,mozgo->ea);
            vanilyen=true;
        }
    }
    nincsilyen(vanilyen);
    printf("\n");
    free_diak(eleje);
}

void keres_oktato(){
    bool vanilyen=false;
    printf("\nKit keresel?\n");
    char nev[51];
    scanf("\n%[^\n]", nev);
    oktato* eleje=beolvas_oktato();
    oktato *mozgo;
    for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov){
        if(strcmp(mozgo->nev, nev)==0){
            printf("Név:%s, Labor csoport:%s, Gyakorlat csoport:%s, Eloadás csoport:%s\n",mozgo->nev,mozgo->labor,mozgo->gyak,mozgo->ea);
            vanilyen=true;
        }
    }
    nincsilyen(vanilyen);
    printf("\n");
    free_oktato(eleje);
}

bool keres_lab(char *nev){
    lab* eleje=beolvas_lab();
    lab *mozgo;
    for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov){
        if(strcmp(mozgo->nev, nev)==0){
            free_lab(eleje);
            return true;
        }
    }
    free_lab(eleje);
    return false;
}

bool keres_gyak(char *nev){
    gyak* eleje=beolvas_gyak();
    gyak *mozgo;
    for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov){
        if(strcmp(mozgo->nev, nev)==0){
            free_gyak(eleje);
            return true;
        }
    }
    free_gyak(eleje);
    return false;
}

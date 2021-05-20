#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "debugmalloc.h"
#include "structok.h"
#include "beolvas.h"
#include "listaz.h"
#include "felszabadit.h"

static int osztalyzat(int osszeg){
    if(osszeg<70)
       return 1;
    if(osszeg<90)
       return 2;
    if(osszeg<110)
       return 3;
    if(osszeg<125)
       return 4;
    return 5;
}

void nincsilyen(bool van){
    if(!van)
        printf("Nincs ilyen ember.\n");
}

bool kovetelmenyek(int kiszh, int nagyzh, int hf, int labor){
    if(kiszh>=20 && nagyzh>=40 && hf>=10 && labor>=9)
        return true;
    else{
        return false;
    }
}

void kovetelmenyeklista(){
    bool vanilyen=false;
    diak* eleje=beolvas_diak(false);
    diak *mozgo;
    printf("\nAkik teljesítették az elvárt szintet:\n");
    for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov){
        if(kovetelmenyek(atoi(mozgo->kiszh),atoi(mozgo->nagyzh),atoi(mozgo->hf),atoi(mozgo->labordb))){
            int szum=atoi(mozgo->kiszh)+atoi(mozgo->nagyzh)+atoi(mozgo->hf);
            printf("Név:%s, Neptun-kód:%s, Pontszám:%d, Osztályzat: %d\n",mozgo->nev,mozgo->neptun, szum, osztalyzat(szum));
            vanilyen=true;
        }
    }
    free_diak(eleje);
    nincsilyen(vanilyen);
    printf("\n");
}

void potzh(){
    bool vanilyen=false;
    diak* eleje=beolvas_diak(false);
    diak *mozgo;
    printf("\nAkik nem teljesítették az elvárt szintet a nagyZH-nál:\n");
    for (mozgo =eleje; mozgo != NULL; mozgo = mozgo->kov){
        if(atoi(mozgo->nagyzh)<40){
            printf("Név:%s, Neptun-kód:%s, Eddigi nagyZh pontszám:%s\n",mozgo->nev,mozgo->neptun,mozgo->nagyzh);
            vanilyen=true;
        }
    }
    free_diak(eleje);
    nincsilyen(vanilyen);
    printf("\n");
}

void hfhiany(){
    bool vanilyen=false;
    diak*eleje= beolvas_diak(false);
    diak *mozgo;
    printf("\nAkik nem teljesítették az elvárt szintet a házifeladatnál:\n");
    for (mozgo =eleje; mozgo != NULL; mozgo = mozgo->kov){
        if(atoi(mozgo->hf)<10){
            printf("Név:%s, Neptun-kód:%s, Eddigi házifeladat pontszám:%s\n",mozgo->nev,mozgo->neptun,mozgo->hf);
            vanilyen=true;
        }
    }
    free_diak(eleje);
    nincsilyen(vanilyen);
    printf("\n");
}
void tanulolista(){
    diak*mozgo;
    diak *eleje=beolvas_diak(true);
    printf("\nPontszámok szerinti sorbarendezés(nagy->kicsi):\n");
     for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov){
        int szum=atoi(mozgo->kiszh)+atoi(mozgo->nagyzh)+atoi(mozgo->hf);
        printf("Név:%s, Neptun-kód:%s, Pontszám:%d, Osztályzat:%d\n",mozgo->nev,mozgo->neptun, szum, osztalyzat(szum));
    }
    free_diak(eleje);
    printf("\n");
}

void lablista(){
    lab *eleje=beolvas_lab();
    lab *mozgo;
    printf("\nLaborok név szerint sorbarendezve:\n");
    for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov){
        printf("Név:%s\n",mozgo->nev);
    }
    free_lab(eleje);
    printf("\n");
}

void gyaklista(){
    gyak *eleje=beolvas_gyak();
    gyak *mozgo;
    printf("\nGyakorlatok név szerint sorbarendezve:\n");
    for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov){
        printf("Név:%s\n",mozgo->nev);
    }
    free_gyak(eleje);
    printf("\n");
}

void oktatolista(){
    oktato *eleje=beolvas_oktato();
    oktato *mozgo;
    printf("\nOktatók név szerint sorbarendezve:\n");
    for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov){
        printf("Név:%s, Labor:%s, Gyakorlat:%s, Elõadás:%s\n",mozgo->nev,mozgo->labor,mozgo->gyak,mozgo->ea);
    }
    free_oktato(eleje);
    printf("\n");
}

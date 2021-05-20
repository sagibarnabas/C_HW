#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debugmalloc.h"
#include "structok.h"
#include "kiir.h"


void kiir_diak(diak *eleje){

    FILE *f = fopen("DIAK.txt", "wt");
    if (f == NULL) {
        perror("Nem lehet megnyitni a fájlt!");
    }
    diak *mozgo;
    for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov){
        fprintf(f,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n",mozgo->nev,mozgo->neptun,mozgo->kiszh,mozgo->nagyzh,mozgo->hf,mozgo->labordb,mozgo->labor,mozgo->gyak,mozgo->ea);
    }
    fclose(f);
}
void kiir_oktato(oktato *eleje){
    FILE *f = fopen("OKTATO.txt", "wt");
    if (f == NULL) {
        perror("Nem lehet megnyitni a fájlt!");
        return;
    }
    oktato *mozgo;
    for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov){
        fprintf(f,"%s,%s,%s,%s\n",mozgo->nev,mozgo->labor,mozgo->gyak,mozgo->ea);
    }
    fclose(f);
}

void kiir_gyak(gyak *eleje){
    FILE *f = fopen("GYAK.txt", "wt");
    if (f == NULL) {
        perror("Nem lehet megnyitni a fájlt!");
    }
    gyak *mozgo;
    for (mozgo = eleje; mozgo != NULL;mozgo = mozgo->kov){
        fprintf(f,"%s\n", mozgo->nev);
    }
    fclose(f);
}

void kiir_lab(lab *eleje){
    FILE *f = fopen("LAB.txt", "wt");
    if (f == NULL) {
        perror("Nem lehet megnyitni a fájlt!");
    }
    lab *mozgo;
    for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov){
        fprintf(f,"%s\n",mozgo->nev);
    }
    fclose(f);
}

#include <stdio.h>
#include <stdlib.h>

#include "debugmalloc.h"
#include "felszabadit.h"
#include "structok.h"


void free_diak(diak* eleje){
    diak* iter=eleje;
    while (iter != NULL) {
        diak* kov = iter->kov;
        free(iter);
        iter = kov;
    }
}

void free_oktato(oktato* torol){
    while (torol != NULL) {
        oktato *kov = torol->kov;
        free(torol);
        torol = kov;
    }
}

void free_lab(lab* torol){
    while (torol != NULL) {
        lab *kov = torol->kov;
        free(torol);
        torol = kov;
    }
}

void free_gyak(gyak* torol){
    while (torol != NULL) {
        gyak *kov = torol->kov;
        free(torol);
        torol = kov;
    }
}

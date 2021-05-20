#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <locale.h>

#include "debugmalloc.h"
#include "gyakeslabmenu.h"
#include "hallgatokmenu.h"
#include "oktatokmenu.h"
#include "structok.h"


int main(){
    setlocale(LC_ALL, "");
    SetConsoleCP(1250); SetConsoleOutputCP(1250);
    int valasz;
    bool vege=false;
    do{
        printf("A k�vetkez� gombokkal �rheted el a lent l�that� men�ket:\n"
               "1:Hallgat�k men�.\n"
               "2:Oktat�k men�.\n"
               "3:Gyakorlatok es laborok men�.\n"
               "9:Kil�p�s a programb�l.\n");
        scanf("%d", &valasz);
        switch (valasz) {
            case 1:
                printf("Hallgat�k men� megnyitva:\n");
                hallgatokm(&vege);
                if(vege)
                    valasz=9;
                break;
            case 2:
                printf("Oktat�k men� megnyitva:\n");
                oktatokm(&vege);
                if(vege)
                    valasz=9;
                break;
            case 3:
                printf("Gyakorlatok es laborok men� megnyitva:\n");
                gyakeslabm(&vege);
                if(vege)
                    valasz=9;
                break;
            case 9:
                printf("Kil�pve a programb�l.\n");
                break;
            default:
                printf("�rv�nytelen v�lasz, add meg �jra!\n");
                break;
        }
    }while(valasz!=9);
    return 0;
}

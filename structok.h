#ifndef STRUCTOK_H_INCLUDED
#define STRUCTOK_H_INCLUDED

typedef struct diak{
    char nev[51];
    char neptun[7];
    char kiszh[3];
    char nagyzh[3];
    char hf[3];
    char labordb[3];
    char labor[4];
    char gyak[4];
    char ea[3];
    struct diak *kov;
}diak;

typedef struct oktato{
    char nev[51];
    char labor[4];
    char gyak[4];
    char ea[3];
    struct oktato *kov;
}oktato;

typedef struct gyak{
    char nev[4];
    struct gyak *kov;
}gyak;

typedef struct lab{
    char nev[4];
    struct lab *kov;
}lab;

#endif // STRUCTOK_H_INCLUDED

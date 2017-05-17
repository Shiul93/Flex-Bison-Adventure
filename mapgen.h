#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h> //Needed for strcat()
#include <ctype.h>
#include <ctype.h>
#include "namegen.c"

#include "slowprint.c"

#define ENEMPROB 100

void pt() ;
void printEnem(struct ENEMIGO e);
struct ENEMIGO enegen();
struct CASILLA casGen();
void printCas(struct CASILLA c);
struct MAPA mapGen();
void printMap(struct MAPA m);
int randPercent(int porcentaje);

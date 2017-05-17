#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <ctype.h>
#include "tipos.h"
#include "slowprint.c"


struct JUGADOR mover(struct JUGADOR j,int dir);
struct JUGADOR huir(struct JUGADOR j);
struct JUGADOR atacar(struct JUGADOR j,struct MAPA * m);
void mirarLugar(struct CASILLA c);
void mirarAnimal(struct ANIMAL a);

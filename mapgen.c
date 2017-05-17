#include "mapgen.h"
void pt() {
  printf("TEST\n");
}

void printEnem(struct ENEMIGO e);

struct ENEMIGO enegen(){
  struct ENEMIGO enemigo;


  NameGen(enemigo.nombre);

  enemigo.ataque = (rand() % 20)+1;
  enemigo.defensa = (rand() % 20)+1;
  enemigo.tipo = (rand()%6);

  //enemigo.inventario = 0;

  //printEnem(enemigo);
  return enemigo;

}

void printEnem(struct ENEMIGO e){

  char* nombre = e.nombre;

  int ataque = e.ataque;
  int defensa = e.defensa;
  int tipo = e.tipo;
  if (tipo == 7){
    sp("No hay enemigo\n" );
  }else{

    printf("Nombre %s, Atk: %i, Def: %i,Tipo: %s \n",nombre,ataque,defensa,enemNam[tipo] );
  }

}


struct CASILLA casGen(){


  struct CASILLA casilla;

  casilla.tipo = (rand()%6);
  casilla.enemigo = enegen();
  if (!randPercent(ENEMPROB)){
    casilla.enemigo.tipo=7;
  }
  return casilla;
}

void printCas(struct CASILLA c){

  int tipo = c.tipo;

  struct ENEMIGO enem = c.enemigo;

  printf("Tipo: %s\n\t",lugNam[tipo]);

  printEnem(enem);

}

struct MAPA mapGen(){
  struct MAPA m;
  for (int i = 0; i < MAPTAMX; i++) {
    for (int j = 0; j < MAPTAMY; j++) {
        m.casillas[i][j]=casGen();
    }
  }
  return m;
}

void printMap(struct MAPA m){
  for (int i = 0; i < MAPTAMX; i++) {
    for (int j = 0; j < MAPTAMY; j++) {
        printf("(%i,%i)\n\t",i,j);
        printCas(m.casillas[i][j]);
    }
  }
}
int randPercent(int porcentaje){
  int genNum = rand()%100;
  if (genNum<porcentaje){
    return 1;
  }else{
    return 0;
  }

}

int main(int argc, char const *argv[]) {
  srand (time (0));

  struct MAPA m = mapGen();

  printMap(m);

  return 0;
}

#include "acciones.h"


struct JUGADOR mover(struct JUGADOR j,int dir){
  switch (dir) {
    case 1://NORTE
      j.posY = j.posY+1;
    case 2://ESTE
      j.posX = j.posX+1;
    case 3://SUR
      j.posY = j.posY-1;
    case 4://OESTE
      j.posX = j.posX-1;
  }
}
struct JUGADOR huir(struct JUGADOR j){
  int dir = (rand()%4)+1;
  return mover(j,dir);
}

struct JUGADOR atacar(struct JUGADOR j,struct MAPA * m){
  if (m->casillas[j.posX][j.posY].enemigo.tipo == 7){
    sp("Atacas, ¡pero no sabes a quien!");
  }else{
    m->casillas[j.posX][j.posY].enemigo.vida = m->casillas[j.posX][j.posY].enemigo.vida -j.ataque;

  }

}

void mirarLugar(struct CASILLA c){
  sp("A lo lejos ves un");
  sp(lugDesc[c.tipo] );
  if (c.enemigo.tipo==7){
    sp("No parece haber enemigos en la zona");
  }else{
    sp("rondando la zona hay un ");
    sp(enemNam[c.enemigo.tipo] );
  }
}
void mirarAnimal(struct ANIMAL a){
  if (a.tipo==7){
    sp("No parece haber enemigos en la zona");
  }else{
    sp("Observas un ");
    sp(enemNam[enemDesc[a.tipo]] );
    sp("Puntos de Vida:");
    printf(" %i\n",a.vida );
    sp("Ataque:");
    printf(" %i\n",a.ataque );
    sp("Defensa:");
    printf(" %i\n",a.defensa );
  }
}

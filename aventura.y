%{

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h> //Needed for strcat()
#include <ctype.h>
#include <ctype.h>
#include "namegen.c"

#include "slowprint.c"

#include "tipos.h"

#define ENEMPROB 50

int numMedidas = 0;

int accion;
int argumento;
int setup =1;
struct JUGADOR jugador;
struct MAPA mapa;
void actualizar();
void ayuda();

//struct MAPA mapa;
void inven(struct JUGADOR j);
void yyerror (char const *);
%}
%union{
	int valInt;
	float valFloat;
	char * valString;
}
%token <valString> MOVIMIENTO COGER ATACAR INVENTARIO MIRAR DORMIR EQUIPAR ABRIR USAR	HUIR
%token <valString> N S E O DIRECCION OBJETO ANIMAL LUGAR SALIR AYUDA ESTADO ERROR
%start ST
%%
ST : ListaAcciones
ListaAcciones : Accion|Accion ListaAcciones
AcciTok: MOVIMIENTO|COGER|EQUIPAR|MIRAR|ABRIR|ATACAR|EQUIPAR{;}
ArgTok:N| S| E| O| DIRECCION| OBJETO| ANIMAL| LUGAR
Accion: Mover|Coger|Equipar|Atacar|Accion|Mirar|Inventario|Salir|Abrir|Estado|Ayuda|AcciError|DefErr;
Mover: MOVIMIENTO DIRECCION{ accion = 1;argumento = dirToInt($2);actualizar();printf("\n>>");};
Coger: COGER OBJETO{ accion = 7;actualizar();printf("\n>>");};
Ayuda: AYUDA{ ayuda();printf("\n>>");};
Equipar: EQUIPAR OBJETO{ accion = 10;argumento = objToInt($2);actualizar();printf("\n>>");};
Atacar: ATACAR ANIMAL{accion = 2;argumento = enemToInt($2);actualizar();printf("\n>>");};
Inventario: INVENTARIO{ accion = 8;actualizar();printf("\n>>");};
Mirar: MIRAR DIRECCION{  accion =5;argumento =dirToInt($2);actualizar();;printf("\n>>");}
						| MIRAR LUGAR{ accion =4;argumento =locToInt($2);actualizar();printf("\n>>");}
						| MIRAR OBJETO { accion = 11;argumento = objToInt($2);actualizar();printf("\n>>");}
						| MIRAR ANIMAL { accion =3;argumento =enemToInt($2);actualizar();printf("\n>>");}
Salir: SALIR {exit(1);}
Abrir: ABRIR OBJETO {accion= 9;actualizar();printf("\n>>");}
Estado: ESTADO {accion = 6; actualizar();printf("\n>>");}
AcciError: AcciTok DefErr{;}|DefErr ArgTok {;}|ArgTok AcciTok{;}
DefErr: Error {;}
Error: Errchar|Errchar Error{};
Errchar: ERROR{;}
%%

void printEnem(struct ENEMIGO e);

struct ENEMIGO enegen(){
  struct ENEMIGO enemigo;

  enemigo.ataque = (rand() % 15)+1;
  enemigo.defensa = (rand() % 5)+1;
  enemigo.tipo = (rand()%6);
	enemigo.vida = (rand() % 20)+1;
	if (enemigo.tipo==juandopico){
		strcpy(enemigo.nombre ,"Juan Dopico");
	}else{
		NameGen(enemigo.nombre);
	}
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
	casilla.inventario = ninguno;
  if (!randPercent(ENEMPROB)){
    casilla.enemigo.tipo=6;
  }
  return casilla;
}
void ayuda(){
	sp("Comandos disponibles:\n");
	sp("Movimiento:\n");
	sp("ir, caminar <direccion>\n");
	sp("Mirar:\n");
	sp("Mirar, observar <enemigo,lugar,direccion,objeto>\n");
	sp("Atacar:\n");
	sp("Atacar <enemigo>:\n");
	sp("Coger:\n");
	sp("Coger <objeto>\n");
	sp("Abrir:\n");
	sp("Abrir <objeto>\n");
	sp("Ver inventario:\n");
	sp("inventario\n");
	sp("Equipar:\n");
	sp("Equipar <Objeto>\n");
	sp("Estado actual:\n");
	sp("estado\n");
	sp("Para salir del juego, utiliza el comando salir\n");
	sp("El objetivo del juego es encontrar el cofre del tesoro\n");
	sp("y su llave para abrirlo, que se encuentran en alguna\n");
	sp("parte del mapa\n");
}
void printCas(struct CASILLA c){

  int tipo = c.tipo;

  struct ENEMIGO enem = c.enemigo;

  printf(" %c ",(lugNam[tipo][0]));

  //printEnem(enem);

}

void printPos(struct JUGADOR j) {
	printf("%i,%i\n",j.posX,j.posY );

}

struct MAPA mapGen(){
  struct MAPA m;


  for (int i = 0; i < MAPTAMX; i++) {

    for (int j = 0; j < MAPTAMY; j++) {
        m.casillas[i][j]=casGen();
    }
  }
	int x = rand()%MAPTAMX;
	int y = rand()%MAPTAMY;

	x = rand()%MAPTAMX;
	y = rand()%MAPTAMY;

	m.casillas[x][y].inventario = espada;
	x = rand()%MAPTAMX;
	y = rand()%MAPTAMY;

	m.casillas[x][y].inventario = pala;
	x = rand()%MAPTAMX;
	y = rand()%MAPTAMY;
	m.casillas[x][y].inventario = palo;
	x = rand()%MAPTAMX;
	y = rand()%MAPTAMY;

	m.casillas[x][y].inventario = escudo;
	x = rand()%MAPTAMX;
	y = rand()%MAPTAMY;
	m.casillas[x][y].inventario = cofre;
	x = rand()%MAPTAMX;
	y = rand()%MAPTAMY;
	m.casillas[x][y].inventario = llave;

  return m;
}

void printMap(struct MAPA m){
	printf("   0  1  2  3  4  5  6  7  8  9\n" );
  for (int i = 0; i < MAPTAMX; i++) {
		printf("%i ",i );
    for (int j = 0; j < MAPTAMY; j++) {
        //printf("(%i,%i)\n\t",i,j);

        printCas(m.casillas[i][j]);
    }
		printf("\n" );
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

struct JUGADOR coger(struct JUGADOR j,struct MAPA *m){
	int aux = m->casillas[j.posX][j.posY].inventario;
	if (m->casillas[j.posX][j.posY].enemigo.tipo==ausente){
		if (m->casillas[j.posX][j.posY].inventario!=ninguno){
			if (j.inventario == ninguno){
			j.inventario = m->casillas[j.posX][j.posY].inventario;
			sp("Has recogido una ");
			ws();
			sp(objNam[j.inventario]);
			m->casillas[j.posX][j.posY].inventario = ninguno;
			printf("\n" );
			return j;}
			else{

				sp("Tienes los bolsillos llenos, \n¿quieres intercambiar los objetos? [si/no]\n");
				char resp[10];
				scanf("%s",resp);

				if(strcmp(resp,"si")==0){

					m->casillas[j.posX][j.posY].inventario = j.inventario;

					j.inventario = aux;

					sp("Has intercambiado objetos\n");

				}
				else{
					sp("Decides mantener tu objeto actual\n");
				}

				return j;
			}

		}else{
			sp("No hay nada que recoger.\n");

			return j;
		}
}else{
	sp("Enemigos guardan la zona, no has podido coger nada\n");
	return j;
}

}
int dirToInt(char * dir){

	if (strcmp(dir,"norte")==0){
		return 1;
	}
	if (strcmp(dir,"este")==0){
		return 2;
	}
	if (strcmp(dir,"sur")==0){
		return 3;
	}
	if (strcmp(dir,"oeste")==0){
		return 4;
	}
}
void inven(struct JUGADOR j) {
	if(j.inventario==ninguno){
		sp("Miras en tus bolsillos, pero estan vacios");
	}else{
		sp("Miras lo que llevas encima y encuentras un");
		ws();
		sp(objNam[j.inventario]);
		sp("\n");


	}
	if (j.equipado != ninguno){
		sp("\n");
		sp("en tus manos llevas un");
		ws();
		sp(objNam[j.equipado]);

	}
	sp("\n");
	/* code */
}
int enemToInt(char * enem){
	if (strcmp(enem,"oso")==0){
		return 0;
	}
	if (strcmp(enem,"araña")==0){
		return 1;
	}
	if (strcmp(enem,"perro")==0){
		return 2;
	}
	if (strcmp(enem,"lobo")==0){
		return 3;
	}
	if (strcmp(enem,"murloc")==0){
		return 4;
	}
	if (strcmp(enem,"juandopico")==0){
		return 5;
	}
}

int objToInt(char * o){
	if (strcmp(o,"llave")==0){
		return 0;
	}
	if (strcmp(o,"espada")==0){
		return 1;
	}
	if (strcmp(o,"palo")==0){
		return 2;
	}
	if (strcmp(o,"escudo")==0){
		return 3;
	}
	if (strcmp(0,"pala")==0){
		return 4;
	}
	if (strcmp(o,"cofre")==0){
		return 5;
	}
}

int locToInt(char * enem){
	if (strcmp(enem,"casa")==0){
		return 0;
	}
	if (strcmp(enem,"bosque")==0){
		return 1;
	}
	if (strcmp(enem,"valle")==0){
		return 2;
	}
	if (strcmp(enem,"volcan")==0){
		return 3;
	}
	if (strcmp(enem,"cueva")==0){
		return 4;
	}
	if (strcmp(enem,"playa")==0){
		return 5;
	}
	if (strcmp(enem,"oceano")==0){
		return 6;
	}
}

struct JUGADOR mover(struct JUGADOR j,int dir){
  switch (dir) {
    case 1://NORTE

      j.posY = j.posY+1;
			if (j.posY>=MAPTAMY){
				sp("Has llegado al fin del mundo, felicidades!\n");
				sp("No puedes seguir caminando\n");
				j.posY = j.posY-1;
				return j;
			}
			sp("Caminas hacia el Norte\n");
			return j;


    case 2://ESTE
		j.posX = j.posX+1;
		if (j.posX>=MAPTAMX){
			sp("Has llegado al fin del mundo, felicidades!\n");
			sp("No puedes seguir caminando\n");
			j.posX = j.posX-1;
			return j;
		}
			sp("Caminas hacia el Este\n");
			return j;

    case 3://SUR
			sp("Caminas hacia el Sur\n");
      j.posY = j.posY-1;
			if (j.posY<0){
				sp("Has llegado al fin del mundo, felicidades!\n");
				sp("No puedes seguir caminando\n");
				j.posY = j.posY+1;
				return j;
			}
			return j;

    case 4://OESTE
		j.posX = j.posX-1;
		if (j.posX<0){
			sp("Has llegado al fin del mundo, felicidades!\n");
			sp("No puedes seguir caminando\n");
			j.posX = j.posX+1;
			return j;
		}
			sp("Caminas hacia el Oeste\n");
			return j;
  	}

}
void mirarObj(struct JUGADOR j,struct CASILLA c,enum OBJ o){
	if ((j.inventario== o)||(j.equipado == o)||(c.inventario == o)){
		sp(objDesc[o]);
		sp("\n");
	}else{
		sp("No encuentras lo que buscas\n");
	}
}
struct JUGADOR huir(struct JUGADOR j){
  int dir = (rand()%4)+1;
  return mover(j,dir);
}

void gameover(){
	sp("Has sido derrotado!\n\n");
	sp("GAME OVER\n");
	exit(1);
}
struct JUGADOR equipar(struct JUGADOR j, enum OBJ o){
	enum OBJ aux = j.inventario;
	if (j.inventario!=o){
		sp("No puedes equipar algo que no tienes\n");
		return j;
	}else{

		j.inventario = j.equipado;
		j.equipado = aux;
		sp("Equipas un");
		ws();
		sp(objNam[aux]);
		sp("\n");

		return j;
	}
}
struct JUGADOR atacar(struct JUGADOR j,struct MAPA * m){


	struct ENEMIGO enem = (*m).casillas[j.posX][j.posY].enemigo;
	//printEnem(enem);

  if (enem.tipo == 6){
    sp("Atacas, ¡pero no sabes a quien!\n");
		return j;
  }else{

		//printMap(*m);
    enem.vida = enem.vida+ enem.defensa - j.ataque-atkMod[j.equipado];
		sp("Atacas a tu enemigo, ");
		printf(" %i ",j.ataque+atkMod[j.equipado]-enem.defensa);
		sp("puntos de daño!\n");
		if (enem.vida<1){
			sp("Has vencido a");
			ws();
			sp(enem.nombre);
			sp("!\n");
			enem.tipo = ausente;
			(*m).casillas[j.posX][j.posY].enemigo= enem;
			//printEnem(enem);
			return j;

		}else{
			int daño = enem.ataque-j.defensa-defMod[j.equipado];
			if (daño<=0){
				daño = 0;
			}
			sp(enem.nombre);
			ws();
			sp("te ataca!\n Recibes ");

			printf(" %i ",enem.ataque-j.defensa );
			sp(" puntos de daño!\n");
			j.vida = j.vida-enem.ataque+j.defensa;

			if (j.vida<=0){
				gameover();
			}
			//printEnem(enem);
			(*m).casillas[j.posX][j.posY].enemigo= enem;
			return j;
		}

  }

}
void abrir(struct JUGADOR j, struct MAPA * m){
	if (m->casillas[j.posX][j.posY].inventario != cofre){
		sp("Aqui no hay nada que abrir\n");
	}else if (j.inventario != llave){
		sp("No eres capaz de abrir el cofre, quizas haya una llave en la zona...\n");
	}else if(m->casillas[j.posX][j.posY].enemigo.tipo != ausente){
		sp("Hay un enemigo cerca, parece que tendras que pelear por el cofre");
	}else{
		sp("Abres el cofre y está lleno de oro!\nFIN DE LA PARTIDA");
		exit(0);
	}
}
void mirarLugar(struct CASILLA c){
  sp("Ves un");
	ws();
  sp(lugNam[c.tipo] );
	ws();
  if (c.enemigo.tipo==6){
    sp("\nNo parece haber enemigos en la zona\n");
  }else{
    sp("\nrondando la zona hay un ");
		ws();
    sp(enemNam[c.enemigo.tipo] );
		printf("\n");
  }
	if (c.inventario != ninguno){
		sp("Alguien se ha dejado un");
		ws();
		sp(objNam[c.inventario]);
		ws();
		sp("en el suelo\n");
	}
}

void mirarLoc(int i){
	sp(lugDesc[i]);

}

void mirarAnimal(struct ENEMIGO e){
  if (e.tipo==7){
    sp("No parece haber enemigos en la zona");
  }else{
    sp("Observas un ");
    printf("%s\n",enemNam[e.tipo] );
		sp("\tNombre: ");
		printf(" %s\n",e.nombre );
    sp("\tPuntos de Vida:");
    printf(" %i\n",e.vida );
    sp("\tAtaque:");
    printf(" %i\n",e.ataque );
    sp("\tDefensa:");
    printf(" %i\n",e.defensa );
		sp(enemDesc[e.tipo] );
		printf("\n");
  }
}
void printStatus(struct JUGADOR j) {
	sp("Vida:");
	printf(" %i\n",j.vida );
	sp("Ataque:");
	printf(" %i\n",j.ataque+atkMod[j.equipado] );
	sp("Defensa:");
	printf(" %i\n",j.defensa+defMod[j.equipado] );
}
void actualizar(){

	if (setup){

		jugador.vida = 20;
		jugador.ataque = 5;
		jugador.defensa = 0;
		jugador.posX = MAPTAMX/2;
		jugador.posY = MAPTAMY/2;
		jugador.inventario = palo;
		jugador.equipado = ninguno;

		mapa = mapGen();

		mirarLugar(mapa.casillas[jugador.posX][jugador.posY]);
		setup = 0;
		printf(">>" );
	}
	switch (accion) {

		case  1:

			jugador=mover(jugador,argumento);
			mirarLugar(mapa.casillas[jugador.posX][jugador.posY]);
			printPos(jugador);
			break;

		case 2:
			if (mapa.casillas[jugador.posX][jugador.posY].enemigo.tipo == argumento){
				jugador =atacar(jugador,&mapa);
			}else{
				sp("Has atacado a alguien que no esta presente!\n");
			}
			break;
		case 3:
			if (mapa.casillas[jugador.posX][jugador.posY].enemigo.tipo == argumento){
				mirarAnimal(mapa.casillas[jugador.posX][jugador.posY].enemigo);
			}else{
				sp("Miras a tu alrededor, pero no encuentras lo que buscas\n");
			}
		break;
		case 4:
			if (mapa.casillas[jugador.posX][jugador.posY].tipo == argumento){
				mirarLoc(mapa.casillas[jugador.posX][jugador.posY].tipo);
			}else{
				sp("Miras a tu alrededor, pero no encuentras lo que buscas\n");
			}
			break;
		case 5:
			switch (argumento) {
				case 1:
					mirarLugar(mapa.casillas[jugador.posX][jugador.posY+1]);
					break;
				case 2:
					mirarLugar(mapa.casillas[jugador.posX+1][jugador.posY]);
					break;
				case 3:
					mirarLugar(mapa.casillas[jugador.posX][jugador.posY-1]);
					break;
				case 4:
					mirarLugar(mapa.casillas[jugador.posX-1][jugador.posY]);
					break;

			}
			break;
		case 6:
			printStatus(jugador);
			break;

		case 7:
			jugador = coger(jugador, &mapa);
			break;

		case 8:
			inven(jugador);
			break;

		case 9:
			abrir(jugador, &mapa);
			break;
		case 10:
			jugador = equipar(jugador,argumento);
			break;
		case 11:
			mirarObj(jugador,mapa.casillas[jugador.posX][jugador.posY],argumento);
			break;
	}

}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	actualizar();
	yyparse();


	return 0;
}

void yyerror (char const *message) { fprintf (stderr, "%s\n", message);}

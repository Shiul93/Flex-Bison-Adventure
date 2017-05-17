#define MAPTAMX 10
#define MAPTAMY 10
#define TAMINV  5
#define LOCNUM  7



const char *objNam[7]={
  "llave",
  "espada",
  "palo",
  "escudo",
  "pala",
  "cofre",
  "ninguno"
  };
  const int atkMod[7]={
    0,
    10,
    2,
    0,
    5,
    0,
    0
    };
  const int defMod[7]={
    0,
    0,
    0,
    10,
    0,
    0,
    0
    };
const char * objDesc[6]={
  "Es una llave,¿Que abrira?",
  "Una espada, no la agarres por el lado puntiagudo!\n +10 puntos de ataque",
  "UN PALOOOOOOOO! ES UN PALOOOOOO!\n+2 puntos de ataque",
  "Un viejo escudo de madera,no es muy bonito,pero para parar golpes vale\n +10 puntos de defensa",
  "Una pala, por si hay que deshacerse de un cadaver\n +5 puntos de ataque",
  "Un cofre con un gran tesoro en su interior"
  };
enum OBJ {
  llave,
  espada,
  palo,
  escudo,
  pala,
  cofre,
  ninguno
};
const char *enemNam[7]={
    "oso",
    "araña",
    "perro",
    "lobo",
    "murloc",
    "juandopico",
    "ninguno"
  };
  const char *enemDesc[7]={
      "Un oso, ",
      "Una araña, con ocho patas",
      "Un perro vagabundo",
      "Un lobo feroz y hambriento",
      "Un murloc (WTF)",
      "Te mira a los ojos, con desprecio, y golpea tu cara mal texturizada con un prominente bitch slap\n(***MLG***)"
    };
enum ENEM{
  oso,
  araña,
  perro,
  lobo,
  murloc,
  juandopico,
  ausente
};
const char *lugDesc[7]={
  "Una casa, igual hay algo interesante en su interior\n",
  "Un bosque sombrio\n",
  "Un valle despejado\n",
  "Un volcan rugiente\n",
  "Una cueva oscura\n",
  "Una playa paradisiaca\n",
  "Mar hasta donde alcanza la vista\n"
};
const char *lugNam[7]={
  "casa",
  "bosque",
  "valle",
  "volcan",
  "cueva",
  "playa",
  "oceano"
};


enum LUG{
  casa,
  bosque,
  valle,
  volcan,
  cueva,
  playa,
  oceano
};

//typedef struct OBJETO{
//  char* nombre;
//  enum OBJ tipo;
//  int ataque;
//  int defensa;
//}o;

typedef struct ENEMIGO {
   char nombre[50];
   enum ENEM tipo;
   int ataque;
   int defensa;
   int vida;
   //struct OBJETO inventario;
}e;


typedef struct CASILLA{
  enum LUG tipo;
  enum OBJ inventario;
  struct ENEMIGO enemigo;
}c;

typedef struct MAPA{
  struct CASILLA casillas[MAPTAMX][MAPTAMY];
}m;

typedef struct JUGADOR{
  int vida;
  int ataque;
  int defensa;
  int posX;
  int posY;
  enum OBJ equipado;
  enum OBJ inventario;
}j;

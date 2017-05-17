%{
	#include "aventura.tab.h"
	# define YYLEX yylex()
%}
MOVIMIENTO (?i:"andar")|(?i:"caminar")|(?i:"mover")|(?i:"ir")
COGER			 (?i:"coger")|(?i:"recoger")|(?i:"obtener")
ATACAR		 (?i:"atacar")|(?i:"pegar")
INVENTARIO (?i:"inventario")
MIRAR 		 (?i:"mirar")|(?i:"inspeccionar")
DORMIR     (?i:"dormir")
EQUIPAR    (?i:"equipar")|(?i:"poner")
ABRIR 		 (?i:"abrir")
USAR			 (?i:"usar")|(?i:"utilizar")
HUIR			 (?i:"huir")|(?i:"escapar")
N					 (?i:"adelante")|(?i:"norte")|(?i:"frente")
S					 (?i:"atras")|(?i:"sur")
E					 (?i:"derecha")|(?i:"este")
O 				 (?i:"izquierda")|(?i:"oeste")
DIRECCION  {N}|{S}|{E}|{O}
OBJETO 		 (?i:"llave")|(?i:"espada")|(?i:"palo")|(?i:"escudo")|(?i:"cofre")|(?i:"pala")
ANIMAL		 (?i:"oso")|(?i:"araña")|(?i:"perro")|(?i:"lobo")|(?i:"murloc")|(?i:"JuanDopico")
LUGAR			 (?i:"casa")|(?i:"bosque")|(?i:"valle")|(?i:"volcan")|(?i:"cueva")|(?i:"playa")|(?i:"oceano")
SALIR			 (?i:"salir")|(?i:"terminar")
AYUDA			 (?i:"ayuda")|(?i:"help")
ESTADO		 (?i:"estado")
ws         " "
salto \n



%%
{MOVIMIENTO} {yylval.valString = strdup(yytext);return MOVIMIENTO;}
{COGER}			 {yylval.valString = strdup(yytext);return COGER;}
{ATACAR}		 {yylval.valString = strdup(yytext);return ATACAR;}
{INVENTARIO} {yylval.valString = strdup(yytext);return INVENTARIO;}
{MIRAR} 		 {yylval.valString = strdup(yytext);return MIRAR;}
{DORMIR}     {yylval.valString = strdup(yytext);return DORMIR;}
{EQUIPAR}    {yylval.valString = strdup(yytext);return EQUIPAR;}
{ABRIR} 		 {yylval.valString = strdup(yytext);return ABRIR;}
{USAR}			 {yylval.valString = strdup(yytext);return USAR;}
{HUIR}			 {yylval.valString = strdup(yytext);return HUIR;}
{DIRECCION}  {yylval.valString = strdup(yytext);return DIRECCION;}
{OBJETO} 		 {yylval.valString = strdup(yytext);return OBJETO;}
{ANIMAL}		 {yylval.valString = strdup(yytext);return ANIMAL;}
{LUGAR}			 {yylval.valString = strdup(yytext);return LUGAR;}
{SALIR}			 {yylval.valString = strdup(yytext);return SALIR;}
{AYUDA}			 {yylval.valString = strdup(yytext);return AYUDA;}
{ESTADO}			 {yylval.valString = strdup(yytext);return ESTADO;}
{ws}				 {}
{salto}				 {}
[A-Za-z]+ {printf("Comando desconocido\n>>");return ERROR;}
.	{;}
%%

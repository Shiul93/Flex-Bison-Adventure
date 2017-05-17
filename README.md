Luis Felipe Llamas Luaces

Procesado de Lenguajes - Curso 2015/2016

En esta practica se ha implementado un juego de aventuras.
El objetivo del juego es encontrar un cofre que se encuentra en una de las
casillas del mapa y la llave para abrirlo.

En el analizador lexico se reconocen los diferentes tokens que pueden conformar
los comandos, en principio sin ser sensible a mayusculas y minusculas.

El analizador sintactico contiene la gramática que define los diferentes
comandos, ademas del control de errores. En este fichero (aventura.y) tambien
se encuentra la mayoría de la lógica del programa. Esto se intentó evitar y
implementar de manera modular, pero por errores a la hora de realizar el linkeado
se ha tenido que dejar todo en el fichero .y.

El fichero tipos.h contiene la definicion de tipos básicos del juego,tales como
el mapa, casillas, jugador, etc... valores asignados a los mismos, y descripciones.

Slowprint.c es un modulo bajado de internet y modificado que permite la impresion
del texto de manera lenta, dando una sensacion más interesante al juego.

NameGen.c tambien se obtuvo de internet y es un generador de nombres aleatorios.

En ejemploejecucion.txt se muestra un ejemplo de una partida completa.

Al ser un juego interactivo no se incluye un fichero de prueba, sin embargo
existe el comando "ayuda" dentro del mismo, que provee al usuario de un pequeño
manual.

Errores conocidos:

Por alguna razon desconocida, el interactuar con la pala pruduce un segfault.

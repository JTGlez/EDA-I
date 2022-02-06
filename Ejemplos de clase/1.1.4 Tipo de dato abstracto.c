/*

    Tema 1.1.4: Tipo de dato abstracto.

    Los datos abstractos son un conjunto de variables, arreglos o apuntadores de tipo de dato primitivo que permiten modelar entidades
    de mayor complejidad con sus respectivas propiedades (o atributos).

        El tipo de dato abstracto se compone de dos partes:

            1. Su estructura b�sica de definici�n; la cual incluye todas sus propiedades modeladas que son contiguas en la memoria.
            2. La variable abstracta; que representa un ente individual con todas las propiedades definidas en la estructura b�sica.

    +DECLARACI�N:

        struct TipoDeDatoAbstracto {

            //Variables.
            //Arreglos.
            //Apuntadores.

        };

    +DECLARACI�N DE UNA VARIABLE ABSTRACTA:

    struct TipoDeDatoAbstracto variableAbstracta;


    +ACCESO A LOS ATRIBUTOS DE UNA VARIABLE ABSTRACTA:

    Se utiliza el operador binario ".", que permite relacionar una variable abstracta con una de sus propiedades y
    acceder a ella; con la posibilidad de modificar su valor.

        variableAbstracta.propiedad;


    +SIN�NIMOS DE UNA VARIABLE ABSTRACTA:

    Con el fin de evitar escribir m�ltiples veces la etiqueta "struct", el lenguaje C permite darle un sin�nimo a un tipo de dato
    abstracto con el fin de hacer la escritura m�s eficiente y legible. Existen dos formas de realizarlo:

        1. Desde la definici�n del tipo de dato abstracto:

            typedef struct TipoDeDatoAbstracto{

                //Variables.
                //Arreglos.
                //Apuntadores.

            }sinonimo;

        2. Escribiendo la siguiente l�nea de c�digo tras haber declarado el tipo de dato abstracto:

            typedef struct TipoDeDatoAbstracto sinonimo;


    Ejemplo: A continuaci�n se encuentra un programa que modela un tipo de dato abstracto para una pel�cula; en este se observar�
             la sint�xis b�sica y el acceso a las propiedades.

*/

#include <stdio.h>
#include<string.h>
#include <locale.h>

#define NUMERO_TOTAL_ACTORES 10

//Definici�n del tipo de dato abstracto que modela una pel�cula:

    typedef struct Pelicula {

        int duracion;
        char genero[50];
        char clasificacion[5];
        char director[50];
        char actores[NUMERO_TOTAL_ACTORES][50];
        char nombre[100];
        double calificacion;

    }Pelicula;

    //Declaraci�n de una funci�n que imprima algunos datos de una pel�cula recibida por valor:

    void imprimirPelicula(Pelicula p){

    int numActores; //Variable iteradora para imprimir los actores almacenados.

    printf("\nNombre de la pel�cula: %s" ,p.nombre);
    printf("\nDuraci�n de la pel�cula: %d" ,p.duracion);

    for(numActores=0;numActores<NUMERO_TOTAL_ACTORES;numActores++){

    printf("\nEl actor %d es: %s",numActores+1, p.actores[numActores]);

        }

    }

    //Creaci�n de una variable de tipo Pelicula e inicializaci�n de sus propiedades:


    int main(){

    setlocale(LC_CTYPE,"spanish");

    Pelicula avengersEndGame;

    //Inicializando sus propiedades:

    avengersEndGame.duracion=120;
    avengersEndGame.calificacion=10.0;

    //Usando strcpy para copiar cadenas de caracteres a las propiedades de tipo de dato primitivo char:

    strcpy(avengersEndGame.nombre,"Avengers: End Game");
	strcpy(avengersEndGame.genero,"Accion");
	strcpy(avengersEndGame.clasificacion,"B");
	strcpy(avengersEndGame.director,"Russo Brothers");
	strcpy(&avengersEndGame.actores[0][0],"Robert Downey Jr."); //Cabe se�alar que el ampersan no es necesario.
	strcpy(&avengersEndGame.actores[1][0],"Chris Evans");

	imprimirPelicula(avengersEndGame);

    }

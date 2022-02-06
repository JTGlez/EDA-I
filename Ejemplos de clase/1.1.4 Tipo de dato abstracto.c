/*

    Tema 1.1.4: Tipo de dato abstracto.

    Los datos abstractos son un conjunto de variables, arreglos o apuntadores de tipo de dato primitivo que permiten modelar entidades
    de mayor complejidad con sus respectivas propiedades (o atributos).

        El tipo de dato abstracto se compone de dos partes:

            1. Su estructura básica de definición; la cual incluye todas sus propiedades modeladas que son contiguas en la memoria.
            2. La variable abstracta; que representa un ente individual con todas las propiedades definidas en la estructura básica.

    +DECLARACIÓN:

        struct TipoDeDatoAbstracto {

            //Variables.
            //Arreglos.
            //Apuntadores.

        };

    +DECLARACIÓN DE UNA VARIABLE ABSTRACTA:

    struct TipoDeDatoAbstracto variableAbstracta;


    +ACCESO A LOS ATRIBUTOS DE UNA VARIABLE ABSTRACTA:

    Se utiliza el operador binario ".", que permite relacionar una variable abstracta con una de sus propiedades y
    acceder a ella; con la posibilidad de modificar su valor.

        variableAbstracta.propiedad;


    +SINÓNIMOS DE UNA VARIABLE ABSTRACTA:

    Con el fin de evitar escribir múltiples veces la etiqueta "struct", el lenguaje C permite darle un sinónimo a un tipo de dato
    abstracto con el fin de hacer la escritura más eficiente y legible. Existen dos formas de realizarlo:

        1. Desde la definición del tipo de dato abstracto:

            typedef struct TipoDeDatoAbstracto{

                //Variables.
                //Arreglos.
                //Apuntadores.

            }sinonimo;

        2. Escribiendo la siguiente línea de código tras haber declarado el tipo de dato abstracto:

            typedef struct TipoDeDatoAbstracto sinonimo;


    Ejemplo: A continuación se encuentra un programa que modela un tipo de dato abstracto para una película; en este se observará
             la sintáxis básica y el acceso a las propiedades.

*/

#include <stdio.h>
#include<string.h>
#include <locale.h>

#define NUMERO_TOTAL_ACTORES 10

//Definición del tipo de dato abstracto que modela una película:

    typedef struct Pelicula {

        int duracion;
        char genero[50];
        char clasificacion[5];
        char director[50];
        char actores[NUMERO_TOTAL_ACTORES][50];
        char nombre[100];
        double calificacion;

    }Pelicula;

    //Declaración de una función que imprima algunos datos de una película recibida por valor:

    void imprimirPelicula(Pelicula p){

    int numActores; //Variable iteradora para imprimir los actores almacenados.

    printf("\nNombre de la película: %s" ,p.nombre);
    printf("\nDuración de la película: %d" ,p.duracion);

    for(numActores=0;numActores<NUMERO_TOTAL_ACTORES;numActores++){

    printf("\nEl actor %d es: %s",numActores+1, p.actores[numActores]);

        }

    }

    //Creación de una variable de tipo Pelicula e inicialización de sus propiedades:


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
	strcpy(&avengersEndGame.actores[0][0],"Robert Downey Jr."); //Cabe señalar que el ampersan no es necesario.
	strcpy(&avengersEndGame.actores[1][0],"Chris Evans");

	imprimirPelicula(avengersEndGame);

    }

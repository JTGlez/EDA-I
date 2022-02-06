/*

    Tema 1.1.4.1: Arreglos y apuntadores a tipo de datos abstractos.

    As� como se puede definir para un arreglo y un apuntador el tipo de dato primitivo que guardar�, tambi�n se puede realizar
    con un tipo de dato abstracto previamente definido.

    + Arreglos de tipo de dato abstracto:

    Estos arreglos son variables contiguas en la memoria que son del tipo de dato abstracto definido y guardan sus propiedades
    modeladas previamente de forma individual.


    DECLARACI�N:

    struct TipoDeDatoAbstracto nombreArreglo[numElementos];

    +Apuntador a tipo de dato abstracto:

    Variable que almacena la direcci�n de memoria de otra variable de tipo de dato abstracto.


    DECLARACI�N:

    struct TipoDeDatoAbstracto *ap;

    El uso del operador unario & sigue funcionando con normalidad al operar con datos abstractos.


    Ejemplo: Usando parte del c�digo anterior, se mostrar� la declaraci�n y el uso b�sico de los arreglos y apuntadores abstractos.


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

    //Creaci�n de una variable de tipo Pelicula e inicializaci�n de sus propiedades:


    int main(){

    setlocale(LC_CTYPE,"spanish");

    Pelicula avengersEndGame;

	//Declaraci�n del arreglo abstracto.

	Pelicula peliculasDeMarvel[20];

	//Si se quisiera establecer para la pel�cula 5 del arreglo anterior su propiedad "duraci�n":

	peliculasDeMarvel[4].duracion=120;


	//Declaraci�n de un apuntador a la variable avengersEndGame:

	struct Pelicula *apEndGame;

	apEndGame=&avengersEndGame;

    }

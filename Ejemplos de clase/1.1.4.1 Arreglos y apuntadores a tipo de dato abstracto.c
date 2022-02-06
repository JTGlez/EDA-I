/*

    Tema 1.1.4.1: Arreglos y apuntadores a tipo de datos abstractos.

    Así como se puede definir para un arreglo y un apuntador el tipo de dato primitivo que guardará, también se puede realizar
    con un tipo de dato abstracto previamente definido.

    + Arreglos de tipo de dato abstracto:

    Estos arreglos son variables contiguas en la memoria que son del tipo de dato abstracto definido y guardan sus propiedades
    modeladas previamente de forma individual.


    DECLARACIÓN:

    struct TipoDeDatoAbstracto nombreArreglo[numElementos];

    +Apuntador a tipo de dato abstracto:

    Variable que almacena la dirección de memoria de otra variable de tipo de dato abstracto.


    DECLARACIÓN:

    struct TipoDeDatoAbstracto *ap;

    El uso del operador unario & sigue funcionando con normalidad al operar con datos abstractos.


    Ejemplo: Usando parte del código anterior, se mostrará la declaración y el uso básico de los arreglos y apuntadores abstractos.


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

    //Creación de una variable de tipo Pelicula e inicialización de sus propiedades:


    int main(){

    setlocale(LC_CTYPE,"spanish");

    Pelicula avengersEndGame;

	//Declaración del arreglo abstracto.

	Pelicula peliculasDeMarvel[20];

	//Si se quisiera establecer para la película 5 del arreglo anterior su propiedad "duración":

	peliculasDeMarvel[4].duracion=120;


	//Declaración de un apuntador a la variable avengersEndGame:

	struct Pelicula *apEndGame;

	apEndGame=&avengersEndGame;

    }

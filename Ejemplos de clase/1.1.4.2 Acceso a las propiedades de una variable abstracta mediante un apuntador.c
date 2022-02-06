/*

    Tema 1.1.4.2: Acceso a las propiedades de una variable abstracta mediante un apuntador.

    Al utilizar un apuntador a tipo de variable abstracta, es posible manipular ese apuntador para acceder a la variable abstracta
    a la que apunta y modificar directamente su propiedad mediante el operador "->" que relaciona al apuntador y a una propiedad de
    la variable a la que apunta.


    DECLARACI�N:
    Sea un apuntador a tipo de dato abstracto y una propiedad:

        ap->propiedad;

    Ejemplo: Con partes del c�digo anterior, se explorar� la idea anterior para usar un apuntador y modificar con �l los datos
             de una pel�cula. As� mismo, se modificar� el c�digo de impresi�n de una pel�cula para que los datos sean imprimidos
             por referencia y no por valor. Por �ltimo, se har� una funci�n que inicialize una pel�cula dada.

*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

#define NUMERO_TOTAL_ACTORES 10


typedef struct Pelicula {

        int duracion;
        char genero[50];
        char clasificacion[5];
        char director[50];
        char actores[NUMERO_TOTAL_ACTORES][50];
        char nombre[100];
        double calificacion;

    }Pelicula;

    //Modificaci�n de la funci�n imprimirPelicula por valor.

    void imprimirPelicula(Pelicula *p){

    int numActores; //Variable iteradora para imprimir los actores almacenados.

    printf("\nNombre de la pel�cula: %s" ,p->nombre);
    printf("\nDuraci�n de la pel�cula: %d" ,p->duracion);
    printf("\nG�nero de la pel�cula: %s" ,p->genero);
    printf("\nCalificaci�n de la pel�cula: %f" ,p->calificacion);


    for(numActores=0;numActores<NUMERO_TOTAL_ACTORES;numActores++){

    printf("\nEl actor %d es: %s",numActores+1, p->actores[numActores]);

        }

    }

    //Inicializaci�n de una variable de tipo Pelicula.

    void inicializarPelicula(Pelicula *p, char nombre[], int duracion, char genero[], double calificacion){

    strcpy(p->nombre, nombre);
    p->duracion=duracion;
    strcpy((p->genero), genero);
    p->calificacion=calificacion;

    int numActores;

    for (numActores=0; numActores<NUMERO_TOTAL_ACTORES; numActores++){

     printf("\nIngrese el actor %d: \n", (numActores+1));
     gets(p->actores[numActores]);

        }

    }

    //Creaci�n de una variable de tipo Pelicula y un apuntador al tipo de dato Pelicula.

    int main(){

    setlocale(LC_CTYPE,"spanish");

    Pelicula avengersEndGame;


    Pelicula *apuntadorAPelicula;

    apuntadorAPelicula=&avengersEndGame;

    apuntadorAPelicula->calificacion=9; //Acceso mediante el apuntador por el operador ->.

    //Otra forma posible de realizar lo anterior sin la notaci�n -> es la siguiente:

    (*apuntadorAPelicula).calificacion=10; //Los par�ntesis son importantes para evitar un error de compilaci�n.

    inicializarPelicula(apuntadorAPelicula, "EndGame", 120, "Accion", 10);

    printf("\nImpresion de la pelicula: \n");

    imprimirPelicula(&avengersEndGame);


    return 0;
    }

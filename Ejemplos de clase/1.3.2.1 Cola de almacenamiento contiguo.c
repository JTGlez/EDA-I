/*
    Elementos necesarios para construir una cola con almacenamiento contiguo:

    1. Un arreglo de N valores a guardar en la cola.

    2.Un índice que indique la posición en el arreglo del primer elemento (head).

    3.Un índice que indique la posición del arreglo del último elemento (tail).

    Ejemplo: Sean los enteros i y n, determine el operador # tal que i#n devuelva un entero entre 0 y n-1.
             Escribe un programa que muestre tal comportamiento.


        int main() {

        int i=0, n=10;

        for(i=0; i30;i++){

            printf("i=%d e i mod n=%d\n", i, i%n); //i mod n siempre estara en un intervalo de [0,9].

        }

            return 0;
        }


    Ejemplo 2: Construir una cola con almacenamiento contiguo que almacene enteros.


*/

    #include <stdio.h>
    #include <stdlib.h>
    #define ERROR_COLA_LLENA -1
    #define ERROR_COLA_VACIA 1
    #define OK 0

    struct Cola{

    int *valor; //Apuntador al bloque de memoria que funciona como arreglo.

    int head;
    int tail;

    int capacidadMaxima;
    int numeroDeElementos;

    };

    typedef struct Cola Cola;

    Cola* crearCola(int capacidad){

        Cola *colaCreada=0;
        //Creación de la cola.
        colaCreada=(Cola *)malloc(sizeof(Cola)); //Bloque de memoria con las variables valor, head, tail, etc.
        //Inicialización de las propiedades.
        colaCreada->capacidadMaxima=capacidad;
        colaCreada->numeroDeElementos=0;
        colaCreada->head=-1;
        colaCreada->tail=-1;
        //Bloque de memoria que usa como arreglo.
        colaCreada->valor=malloc(capacidad*sizeof(int));


    }

    //Funciones de encolar y desencolar.

    int encolar(Cola *c, int valorAInsertar){

    if (c->capacidadMaxima==c->numeroDeElementos){ //Cola completamente llena.

        printf("Cola llena!");
        return ERROR_COLA_LLENA;
    }

    if(c->numeroDeElementos==0){ //Primer elemento de la cola.

        c->head=c->tail=0;
        c->valor[c->tail]=valorAInsertar; //Recordando que valor es un apuntador y un arreglo en si mismo.
    }
    else{

    c->tail=c->tail+1;
    int posicionAInsertar=(c->tail)%(c->capacidadMaxima);

    c->valor[posicionAInsertar]=valorAInsertar;

    c->numeroDeElementos++;

        }

    return OK;

    }

    int desencolar(Cola *c, int* elementoSacado){

        if(c->numeroDeElementos==0){ //No existen elementos a desencolar.

            return ERROR_COLA_VACIA;
        }

        if(c->numeroDeElementos==1){ //Solo hay un elemento por eliminar (se reestablece la cola).

            int posicionARetirar=(c->head)%(c->capacidadMaxima);
            *elementoSacado=c->valor[posicionARetirar]; //Se devuleve el valor head que fue sacado de la cola.

            c->head=c->tail=-1;
            c->numeroDeElementos=0;

        } else{

            int posicionARetirar=(c->head)%(c->capacidadMaxima);
            *elementoSacado=c->valor[posicionARetirar];

            c->head++; //Se incrementa head a una posicion.
            c->numeroDeElementos--;

        }

    }

    //Funcion para imprimir la cola.

    void imprimirCola(Cola *c){

        if(c->numeroDeElementos>0){

        int elementoAImprimir=c->head;

        while(elementoAImprimir<=c->tail){

            int posicionAImprimir=(elementoAImprimir)%(c->capacidadMaxima);
            printf("%d", c->valor[posicionAImprimir]);
            elementoAImprimir++;
           }
        }

        else{

            printf("Cola vacia!");

        }

    }

    int main(){

    Cola *c=0;
    c=crearCola(10);

    if(c==0){

    return -1;

    }


    return 0;
    }

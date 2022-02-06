#include <stdio.h>
#include <stdlib.h>
#define ERROR_PILA_VACIA -1001
#define ERROR_PILA_LLENA -1000
#define OK 1

//Implementacion haciendo uso de una variable global.


    struct Nodo{

        int valor;
        struct Nodo *siguiente;

    };

    typedef struct Nodo Nodo;

    Nodo *tope=NULL;

    Nodo* crearNodo(void){

        Nodo *n=(Nodo *)malloc(sizeof(Nodo));
        return n;

    }

    void push(Nodo *nodoAInsertar) {


         if (nodoAInsertar==NULL){ //Si malloc falla en asignar memoria, tendremos un codigo de error.

            printf("Pila llena! :( \n");
            //return -1001;

        }

        else //Si tenemos memoria disponible, ahora revisemos si vamos a insertar un primer elemento a la pila.

        if(tope==NULL){ /*Si el tope de la pila no guarda ninguna direccion, entonces la nueva direccion de tope sera la del
                          primer nodo creado*/

            nodoAInsertar->siguiente=NULL;
            tope=nodoAInsertar;

        }

        else { //Ahora, si la insercion es para un elemento cualquiera...

            nodoAInsertar->siguiente=tope;
            tope=nodoAInsertar;

            /* Lo primero es guardar en el nuevo nodo la direccion de tope (es decir, la dir. del nodo anterior).
               Hecho esto, cambiamos la direccion de tope por la del nuevo nodo.
            */

        }


    }

    Nodo* pop(){

        if(tope==NULL){

            printf("Pila vacia!");
            return NULL;
        }

        Nodo *nodoRemovido;
        nodoRemovido=tope;
        tope=nodoRemovido->siguiente;

        return nodoRemovido;

    }

    int popS(Nodo** nodoRemovido){ //Esta implementacion retorna un codigo de error.

        if(tope==NULL){
            return ERROR_PILA_VACIA;
        }

            *nodoRemovido=tope;
            tope=(*nodoRemovido)->siguiente;
            return OK;

    }

    void imprimirPila() { //Operacion de inicio, condicion de ruptura y operacion entre cada iteracion.

    for(Nodo *elemento=tope; elemento==NULL; elemento=elemento->siguiente){

        printf("El valor de este elemento es: %d", elemento->valor);

        }
    }

    void imprimirPila2() { //Operacion de inicio, condicion de ruptura y operacion entre cada iteracion.

    Nodo*elemento;
    elemento=tope;
    while(elemento!=NULL){
            printf("El valor de este elemento es: %d", elemento->valor);
            elemento=elemento->siguiente;

        }
    }

    int main (){

        Nodo *nodoAInsertar=crearNodo(); //Creemos un nuevo nodo con nombre "nodoAInsertar".

        nodoAInsertar->valor=1;
        push(nodoAInsertar);

        nodoAInsertar=crearNodo();
        nodoAInsertar->valor=2;
        push(nodoAInsertar);

        Nodo *ultimoElemento=pop();

        popS(&ultimoElemento);

     return 0;
    }

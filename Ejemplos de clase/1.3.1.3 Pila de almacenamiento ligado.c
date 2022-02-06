/*

    Ejemplo: Implementar una pila de enteros con almacenamiento ligado.

        +Los elementos necesarios para crear la pila es un tipo de dato abstracto y un apuntador al último elemento de
         una pila (es decir, el tope de la pila).


*/

#include <stdio.h>
#include <stdlib.h>

    struct Nodo{

        int valor;
        struct Nodo *siguiente;

    };

    typedef struct Nodo Nodo;

    Nodo* crearNodo(void){

        Nodo *n=(Nodo *)malloc(sizeof(Nodo));
        return n;

    }

    void push(Nodo** tope, Nodo *nodoAInsertar) {

         if (nodoAInsertar==NULL){ //Si malloc falla en asignar memoria, tendremos un codigo de error.

            printf("Pila llena! :( \n");
            //return -1001;

        }

        else //Si tenemos memoria disponible, ahora revisemos si vamos a insertar un primer elemento a la pila.

        if(*tope==NULL){ /*Si el tope de la pila no guarda ninguna direccion, entonces la nueva direccion de tope sera la del
                          primer nodo creado*/

            nodoAInsertar->siguiente=NULL;
            *tope=nodoAInsertar;

        }

        else { //Ahora, si la insercion es para un elemento cualquiera...

            nodoAInsertar->siguiente=*tope;
            *tope=nodoAInsertar;

            /* Lo primero es guardar en el nuevo nodo la direccion de tope (es decir, la dir. del nodo anterior).
               Hecho esto, cambiamos la direccion de tope por la del nuevo nodo.
            */

        }

    }

    void pop(Nodo** tope, Nodo**nodoARemover){

        if(*tope==NULL) {

            printf("Pila vacia!");
            //return ERROR_PILA_VACIA;
        }

        else {

            *nodoARemover=*tope;
            *tope=(*nodoARemover)->siguiente;
        }

        //return TODO_BIEN;
    }

        void imprimirPila3(Nodo *tope){ //Para el tope como variable local.uk

        Nodo*elemento;
        elemento=tope;

        while(elemento!=NULL){

            printf("El valor de este elemento es: %d", elemento->valor);
            elemento=elemento->siguiente;

        }


    }


    int main (){

        Nodo *tope=NULL; //Se establece que la pila se encuentra vacía.

        Nodo *nodoAInsertar=crearNodo(); //Creemos un nuevo nodo con nombre "nodoAInsertar".
        nodoAInsertar->valor=2;
        push(&tope, nodoAInsertar);

        Nodo* ultimoNodo=NULL;
        pop(&tope, &ultimoNodo);



     return 0;
    }

/*

    +Cola doble: A continuación se encuentran funciones representativas para la cola doble; recordando las nuevas
                 dos operaciones a tomar en cuenta para volver una cola ligada en una cola doble.

*/
#define NULL 0
#define OK 0
#define ERROR_COLA_LLENA -1
#define ERROR_COLA_VACIA -2
#include <stdio.h>

 struct Nodo {

        int valorAlmacenado; //Valor almacenado por el nodo.

        struct Nodo* nodoSiguiente; //Variable apuntadora al nodo siguiente en la cola.

    };

    typedef struct Nodo Nodo;

    struct Cola { //Esta estructura da la pauta de la posición relativa de los nodos en la cola.

        Nodo* head;
        Nodo* tail;

    };

    typedef struct Cola Cola;

 int encolarPorCabeza(Cola *c, Nodo *nodoAInsertar){ //Función que recibe los atributos H, T y el nodo.

        if (nodoAInsertar==NULL){
            return ERROR_COLA_LLENA; //Si el nodo recibido carece de una dirección de memoria válida.
        }

        if(c->head==NULL && c->tail==NULL) { //Primer elemento de la cola.

            c->head=nodoAInsertar;
            c->tail=nodoAInsertar;

        } else {  //Existe un elemento a cola.

        (nodoAInsertar->nodoSiguiente)=c->head;
        (c->head)=nodoAInsertar;


        }
        return 0;
    }



Nodo* encontrarPenultimoNodo(Cola *c){

    Nodo *penultimoNodo=NULL;
    penultimoNodo=c->head;

    while(penultimoNodo->nodoSiguiente!=c->tail){

        penultimoNodo=penultimoNodo->nodoSiguiente;
    }

    return penultimoNodo;
}

int desencolarPorTail (Cola *c, Nodo **nodoADesencolar) {

        if (c->head==NULL && c->tail==NULL){

            return ERROR_COLA_VACIA;
        }

        if (c->head==c->tail){ //Solo un elemento en la cola.

            *nodoADesencolar=c->head;
            c->head=NULL; c->tail=NULL;

        }

        else { //Se desencolan elementos intermedios en la cola.

            Nodo* penultimo=NULL;
            penultimo=encontrarPenultimoNodo(c);
            *nodoADesencolar=c->tail;
            c->tail=penultimo;
        }

        return OK;
    }



int main(){

return 0;
}

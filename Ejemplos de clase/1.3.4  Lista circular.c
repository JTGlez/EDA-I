/*
    Elementos para construir una lista circular con almacenamiento ligado.

    +Un tipo de dato abstracto (Nodo) que tenga dos propiedades:

        1)El valor a almacenar en la lista.
        2)Una referencia al elemento (Nodo) que le sigue en la lista.

    +Un apuntador al primer nodo de la lista (Head).

    +Un apuntador al último nodo de la lista (Tail).

    Nota: Es importante remarcar que los elementos necesarios serán similares a los de la cola; por lo tanto, su
          implementación será similar.

    Ejemplo: Construya una lista circular de enteros con almacenamiento ligado en C.

*/

    #define ERROR_LISTA_LLENA -1
    #define ERROR_LISTA_VACIA -2
    #define OK 1;
    #include <stdio.h>
    #include <stdlib.h>

    typedef struct Nodo {

        int valorAlmacenado; //Valor almacenado por el nodo.

        struct Nodo* nodoSiguiente; //Variable apuntadora al nodo siguiente en la lista.

    }Nodo;

     typedef struct Lista { //Esta estructura da la pauta de la posición relativa de los nodos en la lista.

        Nodo* head;
        Nodo* tail;

    }Lista;

    void inicializarLista(Lista *l){

        l->head=NULL;
        l->tail=NULL;

    }

     Nodo* crearNodo(int valorPorAlmacenar){

        Nodo *nodoCreado=(Nodo*)malloc(sizeof(Nodo));

        if(nodoCreado!=NULL){

            nodoCreado->valorAlmacenado=valorPorAlmacenar;
            nodoCreado->nodoSiguiente=NULL;
        }

        return nodoCreado;
    }

    int insertar(Lista *l, Nodo* nodoAInsertar){ //Se inserta desde el inicio.

        if(nodoAInsertar=NULL){

            return ERROR_LISTA_VACIA; //No se creo la lista.

        }

         if(l->head==NULL && l->tail==NULL) { //Primer elemento de la lista.

            l->head=nodoAInsertar;
            l->tail=nodoAInsertar;
            nodoAInsertar->nodoSiguiente=l->head; //=nodoAInsertar

        } else {  //Existe un elemento en la lista.

            (nodoAInsertar->nodoSiguiente)=l->head;
            l->head=nodoAInsertar;
            (l->tail)->nodoSiguiente=l->head;

        }
        return OK;

    }

    Nodo* buscar (Lista *l, int valorABuscar){

        if(l->head==NULL && l->tail==NULL){

            return NULL;

        }

        Nodo *nodoBuscado=NULL, *nodoActual=NULL;


        nodoBuscado=l->head;
        while(nodoActual!=l->tail){

            if(nodoActual->valorAlmacenado==valorABuscar){
                nodoBuscado=nodoActual;
                break;
                }
                nodoActual=nodoActual->nodoSiguiente;
                }

        if(l->tail->valorAlmacenado==valorABuscar){

                nodoBuscado=l->tail;

            }

            return nodoBuscado;

        }

int main(){

    Lista l;
    inicializarLista(&l);
    Nodo *nodoAInsertar=crearNodo(25);
    insertar(&l, nodoAInsertar);
    insertar(&l, crearNodo(20));
    insertar(&l, crearNodo(15));
    insertar(&l, crearNodo(10));
    insertar(&l, crearNodo(5));

    Nodo *nodoBuscado;
    nodoBuscado=buscar(&l, 10);

return 0;
}

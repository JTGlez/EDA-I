/*
 Actividades:

    1. Terminar la lista doblemente ligada simple.

*/

#include <stdio.h>
#include <stdlib.h>

#define ERROR_LISTA_LLENA -1
#define OK 0
#define ERROR_LISTA_VACIA -2
#define ERROR_VALOR_NO_EXISTE -3

typedef struct Nodo{
    struct Nodo* anterior;
    int valor;
    struct Nodo* siguiente;
} Nodo;

typedef struct ListaDoblementeLigada{
    Nodo *head;
    Nodo *tail;
}ListaDoblementeLigada;

Nodo* crearNodo(int v){
    Nodo *n;
    n=(Nodo*)malloc(sizeof(Nodo));
    if(n!=NULL){
        n->valor=v;
        n->anterior=n->siguiente=NULL;
    }
    return n;
}

void inicializarLista(ListaDoblementeLigada* l){
    if(l!=NULL){
        l->head=l->tail=NULL;
    }
}

int listaVacia(ListaDoblementeLigada*l){
    return (l->head==NULL&&l->tail==NULL);
}

int insertar(ListaDoblementeLigada *l, Nodo *nodoAInsertar){
    if(nodoAInsertar==NULL){
        return ERROR_LISTA_LLENA;
    }
    else{
        if(listaVacia(l)){ //Caso de una lista vacía.

            l->head=nodoAInsertar;
            l->tail=nodoAInsertar;

        }else{
            (l->head)->anterior=nodoAInsertar; //Inserción por la cabeza!
            nodoAInsertar->siguiente=l->head; //Enlace doble entre los nodos.
            l->head=nodoAInsertar;

        }
    }

    return OK;
}

int insertarAlFinal(ListaDoblementeLigada *l, Nodo *nodoAInsertar){
    if(nodoAInsertar==NULL){
        return ERROR_LISTA_LLENA;
    }
    else{
        if(listaVacia(l)){ //Caso de una lista vacía.

            l->head=nodoAInsertar;
            l->tail=nodoAInsertar;

        }else{
            (l->tail)->siguiente=nodoAInsertar; //Inserción por la cabeza!
            nodoAInsertar->anterior=l->tail; //Enlace doble entre los nodos.
            l->tail=nodoAInsertar;

        }
    }

    return OK;
}

Nodo* buscar(ListaDoblementeLigada *l, int valorABuscar){

    if(l->head==NULL && l->tail==NULL){
        return NULL;
    } else {

        Nodo *nodoBuscado=l->head;
        do{

            if(nodoBuscado->valor==valorABuscar){
                return nodoBuscado;
            }
            nodoBuscado=nodoBuscado->siguiente;

        }while(nodoBuscado!=NULL);


    }
    return NULL;
}

/*
 Otra posible vía para la función buscar:

 Nodo *nodoBuscado;
 nodoBuscado=l->head;

 while(nodoBuscado!=NULL){

    if(nodoBuscado->valor==valorABuscar){
        return nodoBuscado;
    }
    nodoBuscado=nodoBuscado->siguiente;

 }


 */

int eliminar(ListaDoblementeLigada *l, int valorAEliminar){

    if(l->head==NULL && l->tail==NULL){ //Lista vacia.
        return ERROR_LISTA_VACIA;
    }
    else {

        if(l->head==l->tail){ //Lista con un elemento.

            if(valorAEliminar==l->head->valor){
                free(l->head);
                l->head=NULL;
                l->tail=NULL;
                return OK;
            }
            else {

                return ERROR_VALOR_NO_EXISTE; //El valor buscado no está en el único elemento.
            }

        } else { //Buscador en lista con múltiples elementos.

            Nodo *nodoActual;

            nodoActual=l->head;
            int valorEncontrado=0;

            do {

                if(valorAEliminar==nodoActual->valor){
                    valorEncontrado=1;
                    break;
                } else {
                    nodoActual=nodoActual->siguiente;
                }

            }while(nodoActual!=NULL);

            if(valorEncontrado==0){ //Si no se encontró el elemento entre toda la lista.
                return ERROR_VALOR_NO_EXISTE;
            } else { //Si se logró encontrar un elemento al inicio, al final o en otra ubicación.

                if(nodoActual==l->head){ //Se eliminan las ligaduras entre los antecesores y sucesores.
                    l->head=nodoActual->siguiente;
                    (nodoActual->siguiente)->anterior=NULL;
                    free (nodoActual);
                    return OK;
                } else {

                    if(nodoActual==l->tail){

                        l->tail=(l->tail)->anterior;
                        (l->tail)->siguiente=NULL;
                        free(nodoActual);
                        return OK;

                    } else {

                        (nodoActual->anterior)->siguiente=nodoActual->siguiente;
                        (nodoActual->siguiente)->anterior=nodoActual->anterior;
                        free(nodoActual);
                        return OK;

                    }

                }

            }

        }

    }

}

void imprimir(ListaDoblementeLigada *l){

    Nodo *nodoAImprimir;
    nodoAImprimir=l->head;

    while(nodoAImprimir!=NULL){

        printf("%d", nodoAImprimir->valor);
        nodoAImprimir=nodoAImprimir->siguiente;
    }
    printf("\n");
}



int main()
{
    ListaDoblementeLigada l;
    inicializarLista(&l);
    insertar(&l, crearNodo(9));
    insertar(&l, crearNodo(8));
    insertar(&l, crearNodo(7));
    insertar(&l, crearNodo(6));

    imprimir(&l);

    Nodo *nodoBuscado;
    nodoBuscado=buscar(&l, 6);

    if(nodoBuscado!=NULL){

        printf("El nodo existe y tiene valor: %d", nodoBuscado->valor);

    } else {

        printf("El nodo no existe. :(");

    }

    eliminar(&l, 7);
    eliminar(&l, 6);
    imprimir(&l);

    return 0;
}


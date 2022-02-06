/*
    Lista doblemente ligada: Implementación en lenguaje C.

    ¿Qué elementos se necesitan para construir una lista doblemente ligada?

    +Un tipo de dato abstracto (Nodo) que posea tres propiedades:

        1)Su valor a almacenar en la lista.
        2)Una referencia al Nodo que le precede en la lista.
        3)Otra referencia al Nodo que le sigue en la lista.

    +Un apuntador al primer nodo de la lista (Head) y un apuntador al último nodo de la lista (Tail).

    La lista doblemente ligada posee las siguientes operaciones definidas:

        +Insertar
        +Buscar
        +Eliminar

*/

#include <stdio.h>
#include <stdlib.h>
#define ERROR_LISTA_LLENA -1
#define ERROR_LISTA_VACIA -2
#define ERROR_VALOR_NO_EXISTE -3
#define OK 1

typedef struct Nodo{ //Tipo de dato abstracto que modela al nodo.

    struct Nodo *nodoSiguiente;
    struct Nodo *nodoAnterior;
    int valorAlmacenado;

}Nodo;

typedef struct ListaDoblementeLigada{ //Tipo de dato abstracto que modela la cabeza y la cola de la lista.

    Nodo* head;
    Nodo* tail;

}ListaDoblementeLigada;

Nodo *crearNodo(int valorAIngresar){ //Función que devuelve la dirección solicitada para almacenar un nuevo nodo-

    Nodo* nodoCreado=(Nodo*)malloc(sizeof(Nodo));
    if(nodoCreado!=NULL){

        nodoCreado->valorAlmacenado=valorAIngresar; //Inicialización de las propiedades del nodo.
        nodoCreado->nodoAnterior=NULL;
        nodoCreado->nodoSiguiente=NULL;
        return nodoCreado;
    }

}

void inicializarLista(ListaDoblementeLigada *lista){ //Función opcional que inicializa una lista de 0.

    if(lista!=NULL){
        lista->head=lista->tail=NULL;
    }
}

int insertarPorHead(ListaDoblementeLigada *lista, Nodo *nodoAInsertar){ //Operación de Insertar por la cabeza.

    if(nodoAInsertar==NULL){ //Si la función recibe una dirección nula, eso implica que no existe más memoria para crear nodos.
        return ERROR_LISTA_LLENA;
    }
    else {

        if(lista->head==NULL && lista->tail==NULL){
            lista->head=nodoAInsertar;
            lista->tail=nodoAInsertar;
        }
        else{

            (lista->head)->nodoAnterior=nodoAInsertar;
            nodoAInsertar->nodoSiguiente=lista->head;
            lista->head=nodoAInsertar;
        }

    }

    return OK;

}

int insertarPorTail(ListaDoblementeLigada *lista, Nodo* nodoAInsertar){

if(nodoAInsertar==NULL){
        return ERROR_LISTA_LLENA;
    }
    else {

        if(lista->head==NULL && lista->tail==NULL){
            lista->head=nodoAInsertar;
            lista->tail=nodoAInsertar;
        }
        else{

            (lista->tail)->nodoSiguiente=nodoAInsertar;
            nodoAInsertar->nodoAnterior=lista->tail;
            lista->tail=nodoAInsertar;
        }

    }

    return OK;

}

Nodo *buscar(ListaDoblementeLigada *lista, int valorABuscar){

    if(lista->head==NULL && lista->tail==NULL){
        return NULL;
    }
    else {

        Nodo *nodoBuscado;
        nodoBuscado=lista->head;

        while(nodoBuscado!=NULL){

            if(nodoBuscado->valorAlmacenado==valorABuscar){
                return nodoBuscado;
            }
            nodoBuscado=nodoBuscado->nodoSiguiente;

        }

    }

}

int eliminar (ListaDoblementeLigada *lista, int valorAEliminar){

    if(lista->head==NULL && lista->tail==NULL){
        return NULL;
    }
    else {

        if(lista->head==lista->tail){

            if(valorAEliminar==(lista->head)->valorAlmacenado){
                free(lista->head);
                lista->head=NULL;
                lista->tail=NULL;
                return OK;
            }
            else {
                return ERROR_VALOR_NO_EXISTE;
            }

        } else {

            Nodo *nodoActual;
            nodoActual=lista->head;
            int valorEncontrado=0;

            do {

                if(valorAEliminar==nodoActual->valorAlmacenado){
                    valorEncontrado=1;
                    break;
                } else {
                    nodoActual=nodoActual->nodoSiguiente;
                }

            }while(nodoActual!=NULL);

            if(valorEncontrado==0){
                return ERROR_VALOR_NO_EXISTE;
            }
            else {

                if(nodoActual==lista->head){
                    lista->head=nodoActual->nodoSiguiente;
                    (nodoActual->nodoSiguiente)->nodoAnterior=NULL;
                    free(nodoActual);
                    return OK;
                }
                else {

                    if(nodoActual==lista->tail){
                        lista->tail=nodoActual->nodoAnterior;
                        (nodoActual->nodoAnterior)->nodoSiguiente=NULL;
                        free(nodoActual);
                        return OK;
                    }
                    else {

                        (nodoActual->nodoAnterior)->nodoSiguiente=nodoActual->nodoSiguiente;
                        (nodoActual->nodoSiguiente)->nodoAnterior=nodoActual->nodoAnterior;
                        free(nodoActual);
                        return OK;
                    }

                }

            }

        }

    }

}

void imprimir(ListaDoblementeLigada *lista){

    Nodo* nodoAImprimir;
    nodoAImprimir=lista->head;

    while(nodoAImprimir!=NULL){

        printf("%d", nodoAImprimir->valorAlmacenado);
        nodoAImprimir=nodoAImprimir->nodoSiguiente;
    }

}

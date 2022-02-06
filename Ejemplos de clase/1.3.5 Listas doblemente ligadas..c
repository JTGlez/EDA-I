/*

    Tema 1.3.5: Lista doblemente ligada.

    Elementos para construir una lista doblemente ligada con almacenamiento ligado:

    +Un tipo de dato abstracto (Nodo) que tenga tres propiedades:

        1) El valor a almacenar en la lista.
        2) Una referencia al elemento (Nodo) que le precede en la lista.
        3) Una referencia al elemento (Nodo) que le sigue en la lista.

    +Un apuntador al primer nodo de la lista (Head).

    +(Opcional) Un apuntador al último nodo de la lista (Tail).


    Ejemplo: Construya una lista doblemente ligada de enteros con almacenamiento ligado en el lenguaje C.

*/

    #include <stdio.h>
    #include <stdlib.h>
    #define ERROR_LISTA_LLENA -1

    typedef struct Nodo{

        struct Nodo *nodoAnterior;
        struct Nodo *nodoSiguiente;
        int valorAlmacenado;

    }Nodo;

    typedef struct ListaDobleLigada {

    Nodo *head;
    Nodo *tail;

    }ListaDobleLigada;

    Nodo* crearNodo(int valorAIngresar){

        Nodo* nodoCreado=(Nodo*)malloc(sizeof(Nodo));
        if(nodoCreado!=NULL){

            nodoCreado->valorAlmacenado=valorAIngresar;
            nodoCreado->nodoAnterior=NULL;
            nodoCreado->nodoSiguiente=NULL;
            return nodoCreado;

        }

    }

    void inicializarListaDobleLigada(ListaDobleLigada *listaAInicializar){

        if(listaAInicializar!=NULL){

            listaAInicializar->head=listaAInicializar->tail=NULL;
        }

    }

    int listaVacia(ListaDobleLigada *listaAVerificar){

        return (listaAVerificar->head==NULL && listaAVerificar->tail==NULL);

    }

    int insertar(ListaDobleLigada *lista, Nodo* nodoAInsertar){

        if(nodoAInsertar==NULL){
            return ERROR_LISTA_LLENA;
        }
        else

        if(listaVacia(1)){



        } else {




        }

    }





    int main(){

    ListaDobleLigada listaNueva;



    return 0;
    }

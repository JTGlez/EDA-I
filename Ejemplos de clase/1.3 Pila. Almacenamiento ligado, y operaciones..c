/*

    Tema 1.3 Pila: almacenamiento ligado y operaciones.

    ¿Cuáles son los tipos de almacenamientos?

        +Contiguo: Los bloques de memoria se encuentran ubicados unos tras otros.

        +Ligado: Bloques de memoria ubicados en ubicaciones distintas de la memoria.


    ¿Qué es una pila? Es una estructura de datos lineal en la que el último elemento en entrar es el primero en salir.
                      (Last-in Last-out). La pila posee dos operaciones:

                      +Insertar(Push)

                      +Eliminar(Pop)


    Al analizar o crear una estructura de datos deben definirse las operaciones teniendo en cuenta los tres siguientes casos:

    1) La estructura está vacía.
    2) La estructura está llena.
    3) La eatructura tiene al menos un elemento.


    DEFINICIÓN DE LAS OPERACIONES EN CADA CASO:

    +Caso 1) La pila está vacía:

        Eliminar(Pop):  ERROR! No hay elementos que eliminar.

        Insertar(Push): Se inserta el elemento, y se incrementa el índice que indica cuál es el último elemento.

    +Caso 2) La pila está llena:

        Eliminar(Pop): Saca el último elemento (tope) y el nuevo tope será el penúltimo elemento de la pila.

        Insertar(Push): ERROR: No hay más lugar para insertar nuevos elementos.

    +Caso 3) La pila posee algún elementos:

        Eliminar(Pop): Saca el último elemento (tope) y el nuevo tope será el penúltimo elemento de la pila.

        Insertar(Push): Se inserta el nuevo elemento y se convierte en el nuevo tope, incrementándose el mismo.


    CASO LIGADO: ¿Qué se necesita para construir una pila con almacenamiento ligado?

        1) Un tipo de dato abstracto que modele a los elementos o nodos.
        2) Un apuntador al último elemento de la pila (es decir, el tope).


    El almacenamiento ligado conecta nodos de información por medio de apuntadores, con el fin de que cada nodo conozca
    la ubicación en la memoria del nodo que le sigue (permitiendo conocer la posición relativa del último elemento de
    una pila).

        Si no se usaran apuntadores para lo anterior, los nodos no conocerían la posición en memoria de los otros nodos y,
    por lo tanto, la información cada nodo quedaría perdida en la memoria y la pila dejaría de tener sentido.


    Ejemplo: Se analizará un implementación ligada de una pila de enteros. Se verán las partes que conforman a la estructura
             de datos y su función interna.

*/

    #include <stdio.h>
    #include <stdlib.h>

    //Modelado del ente "Nodo" que almacena un valor entero y la dirección de memoria del nodo que le sigue.

    typedef struct Nodo{

    int valorAlmacenado;
    struct Nodo *nodoSiguiente;

    }Nodo;

    //Estructura que almacena un apuntador que indica al elemento que es el tope actual en la pila.

    typedef struct Pila{

    Nodo *tope;

    }Pila;

    //Función que reserva un bloque de memoria dinámica para un nuevo nodo.

    Nodo *crearNodo(int valor){

    Nodo* nodoCreado=(Nodo*)malloc(sizeof(Nodo));
    nodoCreado->valorAlmacenado=valor;
    return nodoCreado;

    }

    void push(Pila *pila, Nodo *nodoAInsertar) {

    if (nodoAInsertar==NULL){ //Si malloc falla en asignar memoria, tendremos un codigo de error.

            printf("Pila llena! :( \n");
        }

    else

    if(pila->tope==NULL){

    nodoAInsertar->nodoSiguiente=NULL;
    pila->tope=nodoAInsertar;

    }

        else {

    nodoAInsertar->nodoSiguiente=pila->tope;
    pila->tope=nodoAInsertar;

        }

    }


    void pop(Pila *pila, Nodo *nodoARemover) {

    if (pila->tope==NULL){ //Si malloc falla en asignar memoria, tendremos un codigo de error.

            printf("Pila vacia! :( \n");
        }

    else {

            nodoARemover=pila->tope;
            pila->tope=(nodoARemover)->nodoSiguiente;
        }


    }

    void imprimirPila(Pila *pilaAImprimir){

        Nodo *elemento=pilaAImprimir->tope;

        while(elemento!=NULL){

            printf("\nEl valor del elemento es: %i", elemento->valorAlmacenado);
            elemento=elemento->nodoSiguiente;

        }

    }

    int main(){

    Pila pilaNueva;
    pilaNueva.tope=NULL;

    Nodo *nodoNuevo=crearNodo(5);

    push(&pilaNueva, nodoNuevo);
    push(&pilaNueva, crearNodo(6));
    push(&pilaNueva, crearNodo(7));

    Nodo *nodoEliminado;
    pop(&pilaNueva, nodoEliminado);



    printf("Impresión de valores: \n");
    imprimirPila(&pilaNueva);



    return 0;
    }



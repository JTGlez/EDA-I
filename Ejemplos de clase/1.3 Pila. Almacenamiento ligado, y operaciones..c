/*

    Tema 1.3 Pila: almacenamiento ligado y operaciones.

    �Cu�les son los tipos de almacenamientos?

        +Contiguo: Los bloques de memoria se encuentran ubicados unos tras otros.

        +Ligado: Bloques de memoria ubicados en ubicaciones distintas de la memoria.


    �Qu� es una pila? Es una estructura de datos lineal en la que el �ltimo elemento en entrar es el primero en salir.
                      (Last-in Last-out). La pila posee dos operaciones:

                      +Insertar(Push)

                      +Eliminar(Pop)


    Al analizar o crear una estructura de datos deben definirse las operaciones teniendo en cuenta los tres siguientes casos:

    1) La estructura est� vac�a.
    2) La estructura est� llena.
    3) La eatructura tiene al menos un elemento.


    DEFINICI�N DE LAS OPERACIONES EN CADA CASO:

    +Caso 1) La pila est� vac�a:

        Eliminar(Pop):  ERROR! No hay elementos que eliminar.

        Insertar(Push): Se inserta el elemento, y se incrementa el �ndice que indica cu�l es el �ltimo elemento.

    +Caso 2) La pila est� llena:

        Eliminar(Pop): Saca el �ltimo elemento (tope) y el nuevo tope ser� el pen�ltimo elemento de la pila.

        Insertar(Push): ERROR: No hay m�s lugar para insertar nuevos elementos.

    +Caso 3) La pila posee alg�n elementos:

        Eliminar(Pop): Saca el �ltimo elemento (tope) y el nuevo tope ser� el pen�ltimo elemento de la pila.

        Insertar(Push): Se inserta el nuevo elemento y se convierte en el nuevo tope, increment�ndose el mismo.


    CASO LIGADO: �Qu� se necesita para construir una pila con almacenamiento ligado?

        1) Un tipo de dato abstracto que modele a los elementos o nodos.
        2) Un apuntador al �ltimo elemento de la pila (es decir, el tope).


    El almacenamiento ligado conecta nodos de informaci�n por medio de apuntadores, con el fin de que cada nodo conozca
    la ubicaci�n en la memoria del nodo que le sigue (permitiendo conocer la posici�n relativa del �ltimo elemento de
    una pila).

        Si no se usaran apuntadores para lo anterior, los nodos no conocer�an la posici�n en memoria de los otros nodos y,
    por lo tanto, la informaci�n cada nodo quedar�a perdida en la memoria y la pila dejar�a de tener sentido.


    Ejemplo: Se analizar� un implementaci�n ligada de una pila de enteros. Se ver�n las partes que conforman a la estructura
             de datos y su funci�n interna.

*/

    #include <stdio.h>
    #include <stdlib.h>

    //Modelado del ente "Nodo" que almacena un valor entero y la direcci�n de memoria del nodo que le sigue.

    typedef struct Nodo{

    int valorAlmacenado;
    struct Nodo *nodoSiguiente;

    }Nodo;

    //Estructura que almacena un apuntador que indica al elemento que es el tope actual en la pila.

    typedef struct Pila{

    Nodo *tope;

    }Pila;

    //Funci�n que reserva un bloque de memoria din�mica para un nuevo nodo.

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



    printf("Impresi�n de valores: \n");
    imprimirPila(&pilaNueva);



    return 0;
    }



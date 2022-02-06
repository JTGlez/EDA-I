/*

    Elementos necesarios para construir una cola con almacenamiento ligado:

        1. Tipo de dato abstracto (Nodo) con dos propiedades:

            -El valor a almacenar.
            -Un apuntador al nodo que sigue.

        2. Un apuntador al primer elemento (Nodo) de la cola (Head).

        3. Un apuntador al último elemento (Nodo) de la cola (Tail).



    Ejemplo: Construir una cola en C que almacene enteros.


*/
    #define NULL 0
    #define ERROR_COLA_LLENA -1
    #define ERROR_COLA_VACIA -2
    #define OK 1;
    #include <stdio.h>
    #include <stdlib.h>

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

    //Definición de funciones principales para la cola.

    int encolar(Cola *c, Nodo *nodoAInsertar){ //Función que recibe los atributos H, T y el nodo.

        if (nodoAInsertar==NULL){
            return ERROR_COLA_LLENA; //Si el nodo recibido carece de una dirección de memoria válida.
        }

        if(c->head==NULL && c->tail==NULL) { //Primer elemento de la cola.

            c->head=nodoAInsertar;
            c->tail=nodoAInsertar;

        } else {  //Existe un elemento a cola.

        (c->tail)->nodoSiguiente=nodoAInsertar;
         c->tail=nodoAInsertar;


        }
        return 0;
    }

    int desencolar (Cola *c, Nodo **nodoADesencolar) {

        if (c->head==NULL && c->tail==NULL){

            return ERROR_COLA_VACIA;
        }

        if (c->head==c->tail){ //Solo un elemento en la cola.

            *nodoADesencolar=c->head;
            c->head=NULL; c->tail=NULL;

        }

        else { //Se desencolan elementos intermedios en la cola.

            *nodoADesencolar=c->head; //Recuperamos la dirección a eliminar.
            c->head=(*nodoADesencolar)->nodoSiguiente; //La nueva cola será el siguiente que
                                                       //el nodo removido almacenaba.
        }

        return OK;
    }

    Nodo* crearNodo(int valorPorAlmacenar){

        Nodo *nodoCreado=(Nodo*)malloc(sizeof(Nodo));

        if(nodoCreado!=NULL){

            nodoCreado->valorAlmacenado=valorPorAlmacenar;
            nodoCreado->nodoSiguiente=NULL;
        }

        return nodoCreado;
    }

    //Impresión de elementos.

    void imprimirCola(Cola *c){

        Nodo *nodoAImprimir=c->head;

        printf("\n\nLa cola contiene los siguientes elementos: \n\n");
        while(nodoAImprimir!=NULL){

            printf("%d  ", nodoAImprimir->valorAlmacenado);
            nodoAImprimir=nodoAImprimir->nodoSiguiente;

        }

    }


    //FIN.

    int main () {

        Cola c; //Creación de un nuevo nodo.
        c.head=NULL; c.tail=NULL; //Inicialización de sus propiedades.
        Nodo *nodoNuevo=NULL;
        nodoNuevo=crearNodo(5);

        encolar(&c, nodoNuevo);
        encolar(&c, crearNodo(6));
        encolar(&c, crearNodo(7));
        encolar(&c, crearNodo(8));
        imprimirCola(&c);

        Nodo *nodoSacado;
        desencolar(&c, &nodoSacado);
        printf("\nEl valor del nodo sacado es: %d", nodoSacado->valorAlmacenado);
        free(nodoSacado);
        imprimirCola(&c);
        desencolar(&c, &nodoSacado);
        printf("\nEl valor del nodo sacado es: %d", nodoSacado->valorAlmacenado);



    return 0;
}

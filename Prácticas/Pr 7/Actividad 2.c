/*
 Actividad 2: Algunas implementaciones de lista no almacenan un apuntador al último elemento. Crear una lista simple que solamente use un apuntador al primer elemento (head).


 */

#include <stdio.h>
#include <stdlib.h>

#define TODO_BIEN 0

#define ERROR_LISTA_LLENA -1
#define ERROR_LISTA_VACIA -2
#define ERROR_VALOR_NO_EXISTE -3

struct Nodo{
    int valor;
    struct Nodo *siguiente;
};
typedef struct Nodo Nodo;

typedef struct Lista{
    Nodo *head;
}Lista;

void inicializarLista(Lista *l){
    l->head=NULL;
}

Nodo *crearNodo(int valorDelNodo){
    Nodo* nodoCreado;
    nodoCreado=(Nodo*)malloc(sizeof(Nodo));
    if(nodoCreado!=NULL){
        nodoCreado->valor=valorDelNodo;
        nodoCreado->siguiente=NULL;
    }
    return (nodoCreado);
}

int insertar(Lista* l,Nodo* nodoAInsertar){
    if(nodoAInsertar==NULL){
        return ERROR_LISTA_LLENA;
    }else{
        if(l->head==NULL){
            //Se inserta el primer elemento
            l->head=nodoAInsertar;
            nodoAInsertar->siguiente=NULL; //La lista simple hace que la cola apunte a NULL.
        }else{
            nodoAInsertar->siguiente=l->head;
            l->head=nodoAInsertar;
        }
    }
    return TODO_BIEN;
}

Nodo *buscar(Lista *l,int valorABuscar){
    if(l->head==NULL){
        return NULL;
    }//Reescritura.
    else{
        Nodo *nodo=l->head;
        do{
            if(nodo->valor==valorABuscar){
                return nodo;
            }
            nodo=nodo->siguiente;
        }while(nodo!=NULL); //Hasta que el nodo sea NULL.
    }
    return NULL;
}

/*Reescritura del Nodo *buscar para la lista simple.

 Nodo *nodo=l->head;
 while(nodo!=NULL){
 if(nodo->valor==valorABuscar){
 return nodo;

    }

 }

 return NULL;

 */

int eliminar(Lista *l,int valorAEliminar){
    if(l->head==NULL){
        return ERROR_LISTA_VACIA;
    }
    //Reescritura.
    Nodo *antecesor, *nodoActual;
    int seEncontroElValor;

    antecesor=NULL;
    nodoActual=l->head;
    seEncontroElValor=0;

    while(nodoActual!=NULL){

        if(nodoActual->valor==valorAEliminar){
            seEncontroElValor=1;
            break;
        } else {
            antecesor=nodoActual;
            nodoActual=nodoActual->siguiente;

        }

    }



        if(seEncontroElValor==0){
            return ERROR_VALOR_NO_EXISTE;
        }

        if(nodoActual==l->head &&nodoActual->siguiente==NULL){

            //El nodo a eliminar es el único elemento.

            nodoActual->siguiente=NULL;
        } else if(nodoActual==l->head){ //El nodo a eliminar es la cabeza.

            l->head=nodoActual->siguiente;

        } else if(nodoActual->siguiente==NULL){ //El nodo a eliminar es la cola.

            antecesor->siguiente=NULL;
        } else { //El nodo a eliminar no es la cabeza ni la cola.

            antecesor->siguiente=nodoActual->siguiente;
        }

        free(nodoActual);
        return TODO_BIEN;

    }


/*Reescritura:



 Nodo *antecesor, *nodoActual;
 int seEncontroElValor;

 antecesor=NULL;
 nodoAcytual=l->head;
 seEncontroElValor=0;

 while(nodoActual!=NULL){

 if(nodoActual->valor==valorAEliminar){
 seEncontroElValor=1;
 break;
 } else {
 antecesor=nodoActual;
 nodoActual=nodoActual->siguiente;


 }

 )

 if(seEncontroElValor==0){
 return ERROR_VALOR_NO_EXISTE;
 }

 if(nodoActual==l->head &&nodoActual==l->tail){

    //El nodo a eliminar es el único elemento.

 l->head=l->tail=NULL;
 } else if(nodoActual==l->head){ //El nodo a eliminar es la cabeza.

 l->head=nodoActual->siguiente;

 } else if(nodoActual==l->tail){ //El nodo a eliminar es la cola.

 l->tail=antecesor;
 antecesor->siguiente=NULL;
 } else { //El nodo a eliminar no es la cabeza ni la cola.

 antecesor->siguiente=nodoActual->siguiente;
 }

 free(nodoActual);
 return TODO_BIEN;

 }

*/

void imprimir(Lista *l){
    if(l->head==NULL){
        printf("La lista está vacía.");
    }else{
        Nodo *nodoActual=l->head;
        printf("\nLa lista contiene: ");
        do{
            printf("%d ",nodoActual->valor);
            nodoActual=nodoActual->siguiente;
        }while(nodoActual!=NULL); //Ahora apunta a NULL.
        printf("\n");
    }
}


int insertarAlFinal(Lista *l, Nodo *nodoAInsertar){

    if(nodoAInsertar==NULL){
        return ERROR_LISTA_LLENA;
    }else{
        if(l->head==NULL){
            //Se inserta el primer elemento
            l->head=nodoAInsertar;
            nodoAInsertar->siguiente=NULL; //La lista simple hace que la cola apunte a NULL.
        }else{

            Nodo *nodo;
            nodo=l->head;
            while(nodo->siguiente!=NULL){
                nodo=nodo->siguiente;
            }
            nodo->siguiente=nodoAInsertar;
            nodoAInsertar->siguiente=NULL;

        }
    }
    return TODO_BIEN;
}

int main(){
    Lista l;
    inicializarLista(&l);
    Nodo *nodoNuevo=crearNodo(25);
    insertar(&l,nodoNuevo);
    insertar(&l,crearNodo(20));
    insertar(&l,crearNodo(15));
    insertar(&l,crearNodo(10));
    insertar(&l,crearNodo(5));

    imprimir(&l);

    Nodo* nodoBuscado;
    nodoBuscado=buscar(&l,10);
    if(nodoBuscado==NULL){
        printf("No se encuentra el valor.");
    }else{
        printf("Se encontró el nodo: %d\n",nodoBuscado->valor);
    }

    eliminar(&l,10);

    imprimir(&l);

    return 0;
}



typedef struct Contacto {

    char nombre[50];
    //Otras propiedades...si el tipo de dato fuese distinto.

}Contacto;





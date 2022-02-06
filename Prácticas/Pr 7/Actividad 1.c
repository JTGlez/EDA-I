/*
 Actividad 1: Convertir la implementaciòn de la lista circular hecha en clase en una lista
 simple.

 a. Considerar que el siguiente del ùltimo elemento es el apuntador nulo.
 b. Agregar la operaciòn insertarAlFinal.
 c. Modificar las operaciones de inserciòn, eliminaciòn y bùsqueda.

 */

#include <stdio.h>
#include<stdlib.h>

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
    Nodo *tail;
}Lista;

void inicializarLista(Lista *l){
    l->head=NULL;
    l->tail=NULL;
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
        if(l->head==NULL && l->tail==NULL){
            //Se inserta el primer elemento
            l->head=nodoAInsertar;
            l->tail=nodoAInsertar;
            nodoAInsertar->siguiente=NULL; //La lista simple hace que la cola apunte a NULL.
        }else{
            nodoAInsertar->siguiente=l->head;
            l->head=nodoAInsertar;
            (l->tail)->siguiente=NULL; //Esto elimina la ligadura circular.
        }
    }
    return TODO_BIEN;
}

Nodo *buscar(Lista *l,int valorABuscar){
    if(l->head==NULL && l->tail==NULL){
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
    if(l->head==NULL && l->tail==NULL){
        return ERROR_LISTA_VACIA;
    }
    //Reescritura.
    else{
        if(l->head==l->tail){
            //Eliminar cuando la lista tiene un solo elemento
            if(valorAEliminar==(l->head)->valor){
                free(l->head);
                l->head=l->tail=NULL;
                return TODO_BIEN;
            }else{
                return ERROR_VALOR_NO_EXISTE;
            }
        }else{
            //Eliminar cuando la lista tiene más de un elemento.
            Nodo *antecesor,*nodoActual;
            int seEncontroElValor;
            antecesor=NULL;
            nodoActual=l->head;
            seEncontroElValor=0;
            do{
                if(valorAEliminar==nodoActual->valor){
                    seEncontroElValor=1;
                    break;
                }else{
                    antecesor=nodoActual;
                    nodoActual=nodoActual->siguiente;
                }
            }while(nodoActual!=NULL); //Cambio en la condición del while.

            if(seEncontroElValor==0){
                return ERROR_VALOR_NO_EXISTE;
            }else{
                if(nodoActual==l->head){
                    l->head=nodoActual->siguiente;
                    (l->tail)->siguiente=NULL;
                    free(nodoActual);
                    return TODO_BIEN;
                }else if(nodoActual==l->tail){
                    antecesor->siguiente=NULL;
                    l->tail=antecesor;
                    free(nodoActual);
                    return TODO_BIEN;
                }else{
                    antecesor->siguiente=nodoActual->siguiente;
                    free(nodoActual);
                    return TODO_BIEN;
                }
            }
        }
    }
    return ERROR_VALOR_NO_EXISTE;
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
    if(l->head==NULL&&l->tail==NULL){
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

    Nodo* antecesor=NULL;
    if(nodoAInsertar==NULL){
        return ERROR_LISTA_LLENA;
    }else{
        if(l->head==NULL && l->tail==NULL){
            //Se inserta el primer elemento
            l->head=nodoAInsertar;
            l->tail=nodoAInsertar;
            nodoAInsertar->siguiente=NULL; //La lista simple hace que la cola apunte a NULL.
        }else{
            antecesor=l->tail;
            antecesor->siguiente=nodoAInsertar;
            l->tail=nodoAInsertar;
            (l->tail)->siguiente=NULL;
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

/*
    Reescritura de la funcion "buscar".

*/

 #define ERROR_LISTA_LLENA -1
    #define ERROR_LISTA_VACIA -2
    #define ERROR_VALOR_NO_EXISTE -1000
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
    else{

        Nodo *nodo=l->head;
        do{

            if(nodo->valorAlmacenado==valorABuscar){
                return nodo;
            }
            nodo=nodo->nodoSiguiente;
        } while(nodo!=l->tail); //Evitar que la lista regrese a la cabeza.

    }
        return NULL;
    }

    int eliminar(Lista *l, int valorAEliminar){

        if(l->head==NULL && l->tail==NULL){

            printf("Lista vacia!");
            return ERROR_LISTA_VACIA;
        }
        else

        if(l->head==l->tail){ //Cuando solo existe un elemento: Existe tal elemento o no existe en la lista.

            if(valorAEliminar==(l->head)->valorAlmacenado){

                free(l->head); //Se reestablece la lista.
                l->head=NULL;
                l->tail=NULL;
                return OK;
            }
            else{

                printf("No se encontro el valor.");
                return ERROR_VALOR_NO_EXISTE;
            }

        }
        else{ //Eliminar cuando la lista tiene mas de un elemento.

            Nodo *antecesor,*nodoActual, *nodoEliminado; //nodoActual es la variable iteradora que dara la pauta para encontrar el valor a eliminar.
                                         //Con el antecesor se recordara para recordar el anterior.
            nodoActual=l->head;
            antecesor=NULL;
            nodoActual=l->head;
            int seEncontroElValor=0;

            do{

                if(valorAEliminar==nodoActual->valorAlmacenado){
                    seEncontroElValor=1;
                    break;
                }
                else{

                    antecesor=nodoActual;
                    nodoActual=nodoActual->nodoSiguiente;
                }

            }while(nodoActual!=l->head);

            if(seEncontroElValor==0){
                return ERROR_VALOR_NO_EXISTE;
            }
            else{

                if(nodoActual==l->head){

                l->head=nodoActual->nodoSiguiente;
                (l->tail)->nodoSiguiente=l->head;
                free(nodoActual);
                return OK;

                } else

                if(nodoActual==l->tail){

                antecesor->nodoSiguiente=l->head;
                l->tail=antecesor;
                free(nodoActual);
                return OK;
                }

                else{

                antecesor->nodoSiguiente=nodoActual->nodoSiguiente;
                free(nodoActual);
                return OK;

                }

            }

        }

    }

    void imprimir(Lista *l){

    if(l->head==NULL && l->tail==NULL){

        printf("Lista vacia!");
    }
    else{

        Nodo *nodoActual=l->head;

        do{

            printf("%d", nodoActual->valorAlmacenado);
            nodoActual=nodoActual->nodoSiguiente;

        }while(nodoActual!=l->head);

        /*
        for(;nodoActual!=l->head;nodoActual=nodoActual->nodoSiguiente){

            printf("%d", nodoActual->valorAlmacenado)
        }

        */






    }



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
    if(nodoBuscado==NULL){

        printf("No existe el nodo indicado.");
    }
    else{
        printf("Nodo encontrado: %d", nodoBuscado->valorAlmacenado);
    }

    eliminar(&l,10);

return 0;
}

    #define NULL 0
    #define ERROR_COLA_LLENA -1
    #define ERROR_COLA_VACIA -2
    #define OK 1;
    #include <stdio.h>
    #include <stdlib.h>
    #define MAX_DE_CARACTERES_DE_NOMBRE 100
    #define MAX_DE_CARACTERES_DE_ACTOR 100

    //Declaración de estructuras.

    typedef struct Superheroe{

	char nombre[MAX_DE_CARACTERES_DE_NOMBRE+1];
	char actor[MAX_DE_CARACTERES_DE_ACTOR+1];

    }Superheroe;

    typedef struct Nodo {

        Superheroe superheroe; //Valor almacenado por el nodo.

        struct Nodo *siguiente; //Variable apuntadora al nodo siguiente en la cola.

    }Nodo;

    typedef struct Cola { //Esta estructura da la pauta de la posición relativa de los nodos en la cola.

        Nodo* head;
        Nodo* tail;

    }Cola;

    //Función de recopilación de datos del superhéroe.

    void pedirInformacionDeSuperheroe(Superheroe *superheroeNuevo){
	setbuf(stdin,NULL);
	printf("\nEscriba el nombre del superheroe: ");
	fgets(superheroeNuevo->nombre,MAX_DE_CARACTERES_DE_NOMBRE,stdin);

	setbuf(stdin,NULL);
	printf("\nEscriba el actor que lo interpreta: ");
	fgets(superheroeNuevo->actor,MAX_DE_CARACTERES_DE_ACTOR,stdin);
	}


    //Función de creación del nodo.

    Nodo* crearNodo(){

        Nodo *nodoCreado=(Nodo*)malloc(sizeof(Nodo));

        if(nodoCreado!=NULL){

            pedirInformacionDeSuperheroe(&(nodoCreado->superheroe));
            (nodoCreado->siguiente)=NULL;
        }

        return nodoCreado;
    }

    //Funciones de operaciones internas en la cola.

    int encolar(Cola *c, Nodo *nodoAInsertar){

        if (nodoAInsertar==NULL){
            return ERROR_COLA_LLENA; //Si el nodo recibido carece de una dirección de memoria válida.
        }

        if(c->head==NULL && c->tail==NULL) { //Primer elemento de la cola.

            c->head=nodoAInsertar;
            c->tail=nodoAInsertar;

        } else {  //Existe un elemento a cola.

        (c->tail)->siguiente=nodoAInsertar;
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
            c->head=(*nodoADesencolar)->siguiente; //La nueva cola será el siguiente que
                                                       //el nodo removido almacenaba.
        }

        return OK;
    }

    //Impresión de elementos.

    void imprimirCola(Cola *c){

        Nodo *nodoAImprimir=c->head;

        if(nodoAImprimir==NULL){

            printf("Cola vacia! Reinicie el programa.");
            exit(0);

        } else {

        printf("\n\nLa cola contiene los siguientes elementos: \n\n");
        while(nodoAImprimir!=NULL){

            printf("%s ", (nodoAImprimir->superheroe.actor));
            printf("%s ", (nodoAImprimir->superheroe.nombre));
            printf("------------------------------------\n");
            nodoAImprimir=nodoAImprimir->siguiente;

            }

        }

    }

    int main() {

    int opcion=1;
    while(opcion==1){

    Cola c; //Creación de un nuevo nodo.
    c.head=NULL; c.tail=NULL; //Inicialización de sus propiedades.
    Nodo *nodoNuevo=NULL;
    int numeroDeSuperheroes, numeroEliminado, i=0, j=0;

        printf("\n¿Cuantos superheroes desea agregar?\n");
        scanf("%d", &numeroDeSuperheroes);

        while(i<numeroDeSuperheroes){

            encolar(&c, crearNodo());
            i++;
        }

        imprimirCola(&c);

        Nodo *nodoSacado;

        printf("\n¿Cuantos superheroes desea eliminar?\n");
        scanf("%d", &numeroEliminado);

        while(j<numeroEliminado){

            desencolar(&c, &nodoSacado);
            printf("\nSuperheroe eliminado de la cola: \n");
            printf("\nEl nombre del actor es: %s", nodoSacado->superheroe.actor);
            printf("\nEl nombre del superheroe es: %s", nodoSacado->superheroe.nombre);
            free(nodoSacado);
            j++;
        }

        printf("\n¿Desea reiniciar el programa? Presione 1) si desea continuar o ingrese cualquier otro valor si desea terminar la ejecucion: \t");
        scanf("%d", &opcion);

    }


    return 0;
    }


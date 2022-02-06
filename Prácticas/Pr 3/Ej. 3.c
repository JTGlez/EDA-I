//En el ejercicio 2, utilizar directamente los �ndices del arreglo sin un elemento de por medio.

#include<stdio.h>
#define TAM 2
#define NUM_DIR 2

struct pelicula{
char nombre[20];
char genero[20];
int anio;      //Propiedades de struct pelicula.
short numDirectores;
char directores[NUM_DIR][20];
};


void llenarArreglo(struct pelicula *); //Declaraci�n de dos prototipos de funciones.
void imprimirArreglo(struct pelicula *);

int main(){

    struct pelicula arreglo[TAM]; //Se crea una variable del tipo de dato abstracto con los atributos de "pelicula".
    llenarArreglo (arreglo);
    imprimirArreglo (arreglo); //La primera direcci�n del arreglo vac�o se env�a directamente a las dos funciones.
    return 0;
}

    void llenarArreglo(struct pelicula arreglo[TAM]) { //SE ENV�A DIRECTAMENTE EL ARREGLO SIN NINGUNA VARIABLE INTERMEDIA.
        int iesimo, enesimo; //Variables de control.
        for (iesimo=0 ; iesimo<TAM ; iesimo++) {
            printf("####### Pel�cula %d #######\n", iesimo+1);
            printf("Ingrese nombre pel�cula:");
            setbuf(stdin, NULL); //Standard input no tendr� nada.
            scanf("%s", arreglo[iesimo].nombre); //Se reciben arreglos de caracteres.
            getchar();
            printf("Ingrese g�nero pel�cula:");
            setbuf(stdin, NULL);
            scanf("%s", arreglo[iesimo].genero);
            getchar();
            printf("Ingrese a�o pel�cula:");
            setbuf(stdin, NULL);
            scanf("%d", &arreglo[iesimo].anio);
            arreglo[iesimo].numDirectores = NUM_DIR;
            //El "define" de NUM DIR se asigna al atributo movie.numDirectores.
            for (enesimo=0 ; enesimo<NUM_DIR ; enesimo++){
                printf("Ingrese director %d:", enesimo+1);
                setbuf(stdin, NULL);
                scanf("%s", arreglo[iesimo].directores[enesimo]);
                getchar();

            }
        }

    }
        void imprimirArreglo(struct pelicula arreglo[TAM]){
            int iesimo, enesimo;
            printf("####### Contenido del arreglo #######\n");
            for (iesimo=TAM-1 ; iesimo>=0 ; iesimo--) {  //Imprime el �ltimo elemento del arreglo.
                printf("####### Pel�cula %d #######\n", iesimo+1);
                printf("PEL�CULA: %s\n", arreglo[iesimo].nombre); //variable.propiedad o atributo.
                printf("G�NERO: %s\n", arreglo[iesimo].genero);
                printf("A�O: %d\n", arreglo[iesimo].anio);
                printf("DIRECTOR(ES):\n");
                for (enesimo=0 ; enesimo<arreglo[iesimo].numDirectores ;enesimo++){
                        printf("%s\n", arreglo[iesimo].directores[enesimo]);

                }
            }

        }

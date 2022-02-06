/*

*/

#include <stdio.h>

#define N 10
#define ERROR_PILA_LLENA -1000
#define ERROR_PILA_VACIA -1001
#define OK 0

int push(int pila[], int* tope, int elementoAInsertar) {

    if(*tope==(N-1)){
        return ERROR_PILA_LLENA;
    }

    *tope=*tope+1;
    pila[*tope]=elementoAInsertar;
    return OK;

}

int pop(int pila[], int* tope, int *elementoSacado) {

    if(*tope==-1) {
        return ERROR_PILA_VACIA;
        //return INT_MIN;
    }

    *elementoSacado=pila[*tope]; //Extracción del elemento superior de la pila.
    *tope=*tope-1; //Decremento del tope, tras extraer un elemento.

}

void imprimirPila(int pila[], int tope){

    if(tope==-1){
        imprimirError(ERROR_PILA_VACIA);
    }

    for(int i=0; i<=tope; i++){
        printf("Pila[%d]: %d\n", i, pila[i]);

    }


}





//Version de Popo que como valor devuelto da el enetero que fue sacado de la pila.

int pop2(int pila[], int *tope){

if (*tope==-1) {
    printf("Pila vacia");
    return -1;

}
    int elementoSacado=pila[*tope];
    *tope=*tope-1;


}

void imprimirError(int error) {

    switch(error){

    case ERROR_PILA_LLENA: {

        printf("La pila esta llena. \n");

    } break;

    case ERROR_PILA_VACIA: {

        printf("La pila esta vacia. \n");

    } break;

    }


}

int main(void) {

    int Pila[N];
    int tope=-1;

    int error=OK;

    error=push(Pila, &tope, 5);

    if (error!=OK){

        imprimirError(error);
    }

    int elementoSacadoDeLaPila;

}

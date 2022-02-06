#include <stdio.h>

void pasarValor(int);
void pasarReferencia(int *);
int main(){
    int nums[] = {55,44,33,22,11};
    int *ap;
    ap = nums;       //Se asigna la direcci�n de arreglo al apuntador ap.
    printf("Contenido de *ap antes de pasarValor %d\n", *ap);
    pasarValor(*ap);     //Env�a lo que est� adentro de la direcci�n a la que apunta *ap.
    printf("Contenido de *ap despu�s de pasarValor: %d\n", *ap);
    pasarReferencia(ap); //Env�a directamente la direcci�n de memoria que guarda *ap.
    printf("Contenido de *ap despu�s de pasarReferencia: %d\n", *ap);
    return 0;
}

void pasarValor(int equis){
    printf("%d\n", equis);
    equis = 128;             //Se env�a un 55 que es modificado a un 120, sin embargo, al terminar la ejecuci�n el valor no se altera.
    printf("%d\n", equis);
}

    void pasarReferencia(int *equis){
        printf("%d\n", *equis);
        *equis = 128;        //Se env�a una direcci�n que enlaza con nums[0] y modifica directamente su valor.
        printf("%d\n", *equis);
}

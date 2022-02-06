#include <stdio.h>

void pasarValor(int);
void pasarReferencia(int *);
int main(){
    int nums[] = {55,44,33,22,11};
    int *ap;
    ap = nums;       //Se asigna la dirección de arreglo al apuntador ap.
    printf("Contenido de *ap antes de pasarValor %d\n", *ap);
    pasarValor(*ap);     //Envìa lo que está adentro de la dirección a la que apunta *ap.
    printf("Contenido de *ap después de pasarValor: %d\n", *ap);
    pasarReferencia(ap); //Envía directamente la dirección de memoria que guarda *ap.
    printf("Contenido de *ap después de pasarReferencia: %d\n", *ap);
    return 0;
}

void pasarValor(int equis){
    printf("%d\n", equis);
    equis = 128;             //Se envía un 55 que es modificado a un 120, sin embargo, al terminar la ejecución el valor no se altera.
    printf("%d\n", equis);
}

    void pasarReferencia(int *equis){
        printf("%d\n", *equis);
        *equis = 128;        //Se envía una dirección que enlaza con nums[0] y modifica directamente su valor.
        printf("%d\n", *equis);
}

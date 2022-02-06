#include <stdio.h>

/*Este programa crea un apuntador de tipo entero
 que apunta al inicio de un arreglo.*/

int main () {
    short arr[5], *apArr;
    apArr = &arr[0];
    // Imprime la dirección de memoria del arreglo en la posición [0].
    printf("Dirección del arreglo en la primera posición: %p\n",&arr[0]);
    // Imprime la dirección de memoria del arreglo (el nombre del arreglo es un apuntador por sí mismo).
    printf("Dirección del arreglo: %p\n",&arr);
    // imprime la dirección de memoria del apuntador apArr
    printf("Dirección del apuntador: %p\n",apArr);

    *(apArr+2)=6;  /*Modificamos el valor del arreglo en la posición 2 usando aritmética de operadores. Dado que apArr dirige a un arreglo, con esa expresión nos dirigimos a modificar
                     lo que apunta apArr (Posición 0) más 2 localidades (que son contiguas en la memoria), lo que finalmente lleva a la posición 2. */
    printf ("\nNuevo valor %i \n", arr[2]);

    return 0;


}

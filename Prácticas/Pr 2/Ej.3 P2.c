#include <stdio.h>

/*Este programa crea un apuntador de tipo entero
 que apunta al inicio de un arreglo.*/

int main () {
    short arr[5], *apArr;
    apArr = &arr[0];
    // Imprime la direcci�n de memoria del arreglo en la posici�n [0].
    printf("Direcci�n del arreglo en la primera posici�n: %p\n",&arr[0]);
    // Imprime la direcci�n de memoria del arreglo (el nombre del arreglo es un apuntador por s� mismo).
    printf("Direcci�n del arreglo: %p\n",&arr);
    // imprime la direcci�n de memoria del apuntador apArr
    printf("Direcci�n del apuntador: %p\n",apArr);

    *(apArr+2)=6;  /*Modificamos el valor del arreglo en la posici�n 2 usando aritm�tica de operadores. Dado que apArr dirige a un arreglo, con esa expresi�n nos dirigimos a modificar
                     lo que apunta apArr (Posici�n 0) m�s 2 localidades (que son contiguas en la memoria), lo que finalmente lleva a la posici�n 2. */
    printf ("\nNuevo valor %i \n", arr[2]);

    return 0;


}

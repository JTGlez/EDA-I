/*
Tema 1.1.3.1: Apuntadores a apuntador

    Una extensi�n de los apuntadores consiste en los apuntadores doble: variables especiales que almacenan la direcci�n de
    otro apuntador. Este permite modificar la direcci�n de un apuntador, y a su vez, modificar lo que contiene la
    direcci�n a la que apunta el apuntador simple.

    DECLARACI�N
     tipoDato **nombreApuntadorAApuntador;

    Ejemplo
    1) Declare un double que contenga una aproximaci�n de Pi.
    2) Declare un apuntador a ese double.
    3) Declare un apuntador doble que dirija al apunador inicial, y �selo para modificar la variable de 1).

*/
#include <stdio.h>

int main () {

    double pi=3.1416;

    double *ap=0;

    ap = &pi; //En este punto ap ya tiene guardada la direccion de la variable pi.

    printf("Valor guardado: %f \n", pi);

    double **aAp=0;

    aAp = &ap;

    **aAp = 3.141592;

    printf("Nuevo valor guardado: %f \n", pi);

return 0;
}

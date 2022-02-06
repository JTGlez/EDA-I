/*
Tema 1.1.3.1: Apuntadores a apuntador

    Una extensión de los apuntadores consiste en los apuntadores doble: variables especiales que almacenan la dirección de
    otro apuntador. Este permite modificar la dirección de un apuntador, y a su vez, modificar lo que contiene la
    dirección a la que apunta el apuntador simple.

    DECLARACIÓN
     tipoDato **nombreApuntadorAApuntador;

    Ejemplo
    1) Declare un double que contenga una aproximación de Pi.
    2) Declare un apuntador a ese double.
    3) Declare un apuntador doble que dirija al apunador inicial, y úselo para modificar la variable de 1).

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

#include <stdio.h>

/*
 Este programa crea un apuntador de tipo car�cter.
 */

int main () {

    char *ap, c;
    c = 'x'; ap = &c;
    // Esta l�nea imprime el car�cter contenido en la localidad a la que apunta *ap.
    printf("Car�cter: %c\n",*ap);
    // Esta l�nea imprime el c�digo ASCII del car�cter contenido en la localidad a la que apunta *ap.
    printf("C�digo ASCII: %d\n",*ap);
    // Esta l�nea imprime la direcci�n de memoria a la que apunta *ap.
    printf("Direcci�n de memoria: %x\n",ap);
    return 0;

    }

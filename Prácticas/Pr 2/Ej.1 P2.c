#include <stdio.h>

/*
 Este programa crea un apuntador de tipo carácter.
 */

int main () {

    char *ap, c;
    c = 'x'; ap = &c;
    // Esta línea imprime el carácter contenido en la localidad a la que apunta *ap.
    printf("Carácter: %c\n",*ap);
    // Esta línea imprime el código ASCII del carácter contenido en la localidad a la que apunta *ap.
    printf("Código ASCII: %d\n",*ap);
    // Esta línea imprime la dirección de memoria a la que apunta *ap.
    printf("Dirección de memoria: %x\n",ap);
    return 0;

    }

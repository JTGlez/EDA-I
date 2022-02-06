/*
Anexo: Separar código en diferentes archivos.

    +Ventaja: Tener código legible y fácil de leer.

    Esto consiste en poner declaraciones de variables globales, constantes, estructuras y declaraciones de funciones en un
    archivo .h

       En cambio, las definiciones de las funciones (es decir, el cuerpo de las funciones)se deben escribir en archivos .c

    Por ejemplo, tomando el ejemplo de una Pila, podemos crear dos archivos: pila.h y pila.c

    Para incluir el archivo .h en pila.c se usarían las líneas (siempre que los archivos estén en un mismo directorio):

                                                    #include "pila.h"

    Con el fin de evitar que el preprocesador incluya más de una vez las definiciones incluidas en el archivo .h

                                                    #ifndef ARCHIVO_H //if not defined...

                                                    #define ARCHIVO_H

                                                    #endif

*/


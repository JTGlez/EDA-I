/*
Anexo: Separar c�digo en diferentes archivos.

    +Ventaja: Tener c�digo legible y f�cil de leer.

    Esto consiste en poner declaraciones de variables globales, constantes, estructuras y declaraciones de funciones en un
    archivo .h

       En cambio, las definiciones de las funciones (es decir, el cuerpo de las funciones)se deben escribir en archivos .c

    Por ejemplo, tomando el ejemplo de una Pila, podemos crear dos archivos: pila.h y pila.c

    Para incluir el archivo .h en pila.c se usar�an las l�neas (siempre que los archivos est�n en un mismo directorio):

                                                    #include "pila.h"

    Con el fin de evitar que el preprocesador incluya m�s de una vez las definiciones incluidas en el archivo .h

                                                    #ifndef ARCHIVO_H //if not defined...

                                                    #define ARCHIVO_H

                                                    #endif

*/


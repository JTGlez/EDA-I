/*
Tema 1.1.3: Apuntadores

    +Apuntador: Variable especial que permite almacenar direcciones de memoria así como leer o escribir lo que contenga
                esa dirección de memoria.

    DECLARACIÓN
     tipoDatoApuntado *nombreAP;

     Cabe señalar desde este punto que un apuntador, como toda variable, también posee su propia dirección de memoria.
     Esto es especialmente importante a la hora de asignar valores a los apuntadores; pues una sintáxis incorrecta
     provocará que modifiquemos la dirección del apuntador, arruinándolo en el proceso.

     -----Operadores unarios de acceso-----

        +El operador * permite acceder a la información contenida en la dirección apuntada o almacenada en un apuntador.

        +El operador & recupera la dirección de memoria de cualquier variable.

    Ejemplo 1: Declare un entero que contenga un cinco y un apuntador que apunte a tal número.

*/

#include <stdio.h>

int main() {

    int entero = 5; //Variable de tipo de dato primitivo int con valor de 5 asignado.

    int *apuntadorAEntero; //Declaración inicial de un apuntador. No está inicializado, así que no apunta a nada en específico.

    apuntadorAEntero = &entero; //A la variable apuntadora se le asigna la dirección extraída de la variable entero.

    /*Ejemplo 2: Modifique el entero del ejemplo anterior usando el apuntador y asigne un 10. Guarde en otro entero el valor
                 contenido en la dirección almacenada por el apuntador. */

    *apuntadorAEntero=10; /*El operador unario accede a lo que contiene la dirección de memoria almacenada por el apuntador y
                           le asigna un 10. */

    int entero2= *apuntadorAEntero; /*PELIGRO! Es vital usar el operador asterisco, de lo contrario, se está asignando
                                      la dirección de memoria al entero2. */

return 0;
}

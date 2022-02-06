/*
Tema 1.1.3: Apuntadores

    +Apuntador: Variable especial que permite almacenar direcciones de memoria as� como leer o escribir lo que contenga
                esa direcci�n de memoria.

    DECLARACI�N
     tipoDatoApuntado *nombreAP;

     Cabe se�alar desde este punto que un apuntador, como toda variable, tambi�n posee su propia direcci�n de memoria.
     Esto es especialmente importante a la hora de asignar valores a los apuntadores; pues una sint�xis incorrecta
     provocar� que modifiquemos la direcci�n del apuntador, arruin�ndolo en el proceso.

     -----Operadores unarios de acceso-----

        +El operador * permite acceder a la informaci�n contenida en la direcci�n apuntada o almacenada en un apuntador.

        +El operador & recupera la direcci�n de memoria de cualquier variable.

    Ejemplo 1: Declare un entero que contenga un cinco y un apuntador que apunte a tal n�mero.

*/

#include <stdio.h>

int main() {

    int entero = 5; //Variable de tipo de dato primitivo int con valor de 5 asignado.

    int *apuntadorAEntero; //Declaraci�n inicial de un apuntador. No est� inicializado, as� que no apunta a nada en espec�fico.

    apuntadorAEntero = &entero; //A la variable apuntadora se le asigna la direcci�n extra�da de la variable entero.

    /*Ejemplo 2: Modifique el entero del ejemplo anterior usando el apuntador y asigne un 10. Guarde en otro entero el valor
                 contenido en la direcci�n almacenada por el apuntador. */

    *apuntadorAEntero=10; /*El operador unario accede a lo que contiene la direcci�n de memoria almacenada por el apuntador y
                           le asigna un 10. */

    int entero2= *apuntadorAEntero; /*PELIGRO! Es vital usar el operador asterisco, de lo contrario, se est� asignando
                                      la direcci�n de memoria al entero2. */

return 0;
}

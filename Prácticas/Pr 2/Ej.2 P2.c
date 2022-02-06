#include <stdio.h>

/*
 Este programa crea un apuntador de tipo entero
 y modifica la informaci�n a trav�s del mismo.
 */

int main () { //Funci�n que manda a llamar el S.O. en primer lugar para su ejecuci�n.
    short a = 5, b = 10;
    short *apEnt;
    apEnt = &a;
    // Esta l�nea imprime el valor entero de a.
    printf("a = %i\n", a);
    b=*apEnt; //b=5
    // La siguiente l�nea imprime el valor de lo que apunta apEnt.
    printf("b = %i //*apEnt\n", b);
    b=*apEnt+1; //b=6 OJO! No lleva par�ntesis ya que eso provocar�a asignar a b un valor basura proveniente de una direcci�n de memoria diferente.
    // Imprime el valor de lo que apunta apEnt + 1
    printf("b = %i //*apEnt+1\n", b);
    *apEnt=0; //a=0
    // Le asigna el valor de 0 a la variable al que apunta apEnt (que es "a" en este caso).
    printf("a = %i //*apEnt = 0\n", a);
    return 0; }

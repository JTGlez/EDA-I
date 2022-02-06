/*
Tema 1.1.3.2: Apuntadores a funciones

    Consisten en apuntadores dedicados a almacenar direcciones de memoria de funciones completas. Se comportan como otra funci�n.

    DECLARACI�N
     tipoDevuelto (*nombreApuntador) (tipoDato1, tipoDato2,..., tipoDatoX);

    Ejemplo 1: Declare una funci�n que devuelva un double, tenga por nombre "Posici�n" y que reciba como par�metro un double.
               La funci�n debe evaluar la expresi�n de ca�da libre de un cuerpo:

                                                    f(t)=(1/2)gt^2

               Luego, declare un apuntador a la funci�n y �selo para evaluar f(3).
*/

#include <stdio.h>

double posicion (double t){

    return (0.5*9.81*t*t); //La funci�n recibe a t y lo ocupa para regresar un resultado evaluado con ese t.

}

int main () {

    double (*ap)(double)=posicion; //La declaraci�n se hace como una funci�n. Por recomendaci�n se inicializa en su declaraci�n.

    double s=(*ap)(3);

    printf("Valor para t=3: %f", s);


return 0;
}

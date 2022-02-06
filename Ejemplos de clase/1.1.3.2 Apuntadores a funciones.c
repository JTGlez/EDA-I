/*
Tema 1.1.3.2: Apuntadores a funciones

    Consisten en apuntadores dedicados a almacenar direcciones de memoria de funciones completas. Se comportan como otra función.

    DECLARACIÓN
     tipoDevuelto (*nombreApuntador) (tipoDato1, tipoDato2,..., tipoDatoX);

    Ejemplo 1: Declare una función que devuelva un double, tenga por nombre "Posición" y que reciba como parámetro un double.
               La función debe evaluar la expresión de caída libre de un cuerpo:

                                                    f(t)=(1/2)gt^2

               Luego, declare un apuntador a la función y úselo para evaluar f(3).
*/

#include <stdio.h>

double posicion (double t){

    return (0.5*9.81*t*t); //La función recibe a t y lo ocupa para regresar un resultado evaluado con ese t.

}

int main () {

    double (*ap)(double)=posicion; //La declaración se hace como una función. Por recomendación se inicializa en su declaración.

    double s=(*ap)(3);

    printf("Valor para t=3: %f", s);


return 0;
}

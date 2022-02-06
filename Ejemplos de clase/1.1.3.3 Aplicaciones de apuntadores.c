/*
Tema 1.1.3.3: Aplicaciones de apuntadores

    +Paso de par�metros de funciones por valor o referencia.

        En el lenguaje C los par�metros que recibe una funci�n se reciben por valor, es decir, se genera una copia interna
        de los par�metros recibidos a variables "dummy" que son destruidas inmediatamente tras la ejecuci�n de la funci�n.

             Para modificar el valor de una variable declarada a trav�s de una funci�n es necesario el uso de apuntadores;
        a esta aplicaci�n se le denomina "paso de par�metros por referencia".

        +Veamos la siguiente funci�n:

            int funcionValorAsignaDiez (int x) {
                x=10;
            }
            //La funci�n recibe por valor una variable de tipo int. El valor de esta variable es copiado a una variable dummy
              llamada "x". Luego, el valor de esta variable es modificado y la funci�n termina. N�tese que la variable de entrada
              original permanece inalterada; pues la variable "x" fue destru�da al terminar la ejecuci�n de la funci�n.

        En una funci�n main lo anterior quedar�a expresado de la siguiente forma:

            int main () {

                int a=3;

                funcionValorAsignaDiez(a);

                //Internamente solo pasamos el valor de "a" a la variable dummy de funcionValorAsignaDiez.

            }

        �Como podr�amos modificar el valor de "a" entonces? La clave se encuentra en los apuntadores, concretamente,
        redefiniendo la funci�n de asignaci�n haciendo que reciba como par�metro una direcci�n de memoria:

        +Ahora vemos la funci�n redefinida:

        int funcionParametroAsignaDiez (int *x) {
                *x=10;
            }

        int main() {

        int a=3;

        funcionParametroAsignaDiez(&a);
        //V�ase que ahora la funci�n redefinada recibe una direcci�n de memoria. Esa direcci�n de memoria es almacenada por
          un apuntador "dummy" que, usando el operador unario *, modifica lo que contiene la direcci�n a la que apunta.

        return 0;
        }

        Ejemplo 1: Defina una funci�n que llene un arreglo de caracteres con un car�cter recibido como par�metro. Luego, pruebe
                   la funci�n con un arreglo de 50 elementos desde la funci�n main.

*/


#include <stdio.h>

    void llenarArreglo(char *ap, char caracter, int indiceArreglo) {

    for (int i=0; i<indiceArreglo; i++) {

        *(ap+i)=caracter;

        }
    }

    int main() {

    char arreglo[50];

    llenarArreglo(arreglo, 'A', 50);

    for (int i=0; i<50; i++) {

        printf("%c", arreglo[i]);

        }

    return 0;
    }

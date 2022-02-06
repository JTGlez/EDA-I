/*
Tema 1.1.3.3: Aplicaciones de apuntadores

    +Paso de parámetros de funciones por valor o referencia.

        En el lenguaje C los parámetros que recibe una función se reciben por valor, es decir, se genera una copia interna
        de los parámetros recibidos a variables "dummy" que son destruidas inmediatamente tras la ejecución de la función.

             Para modificar el valor de una variable declarada a través de una función es necesario el uso de apuntadores;
        a esta aplicación se le denomina "paso de parámetros por referencia".

        +Veamos la siguiente función:

            int funcionValorAsignaDiez (int x) {
                x=10;
            }
            //La función recibe por valor una variable de tipo int. El valor de esta variable es copiado a una variable dummy
              llamada "x". Luego, el valor de esta variable es modificado y la función termina. Nótese que la variable de entrada
              original permanece inalterada; pues la variable "x" fue destruída al terminar la ejecución de la función.

        En una función main lo anterior quedaría expresado de la siguiente forma:

            int main () {

                int a=3;

                funcionValorAsignaDiez(a);

                //Internamente solo pasamos el valor de "a" a la variable dummy de funcionValorAsignaDiez.

            }

        ¿Como podríamos modificar el valor de "a" entonces? La clave se encuentra en los apuntadores, concretamente,
        redefiniendo la función de asignación haciendo que reciba como parámetro una dirección de memoria:

        +Ahora vemos la función redefinida:

        int funcionParametroAsignaDiez (int *x) {
                *x=10;
            }

        int main() {

        int a=3;

        funcionParametroAsignaDiez(&a);
        //Véase que ahora la función redefinada recibe una dirección de memoria. Esa dirección de memoria es almacenada por
          un apuntador "dummy" que, usando el operador unario *, modifica lo que contiene la dirección a la que apunta.

        return 0;
        }

        Ejemplo 1: Defina una función que llene un arreglo de caracteres con un carácter recibido como parámetro. Luego, pruebe
                   la función con un arreglo de 50 elementos desde la función main.

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

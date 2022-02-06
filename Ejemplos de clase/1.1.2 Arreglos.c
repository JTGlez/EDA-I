/*
Tema 1.1.2: Arreglos

    +Arreglo: Es un conjunto ordenado de variables del mismo tipo de dato que son contiguas en la memoria. Su orden
              está dado por un índice entero (el cual generalmente inicia en 0). Una forma de visualizarlo es como
              un vector, donde su dimensión corresponde al índice que se le asigne.

                   El índice de un arreglo considera un espacio vacío que indica el fin del arreglo; recordando que
              la numeración inicia desde 0.


    DECLARACIÓN:
     tipoDato nombreArreglo[tamaño];

    -> ¿Como inicializar un arreglo? Existen dos formas:

        -Definir su tamaño con un índice dado:

            int arreglo[10]; //Arreglo con un intervalo de [0,9].

        -Definir explícitamente los elementos del arreglo:

            int arreglo[]={1,2,3,4,5,6,7,8,9,10}; //Nótese que el compilador automáticamente le asignará un índice 10.


    ->Una cadena de caracteres en el lenguaje C corresponde a un arreglo de caracteres. Si quisieramos declarar una cadena
      que diga "Hola mundo":

            char cadena[]="Hola mundo";

      El arreglo declarado anteriormente si fuese declarado explícitamente tendría la siguiente forma:

            char cadena[]={'H','o','l','a','','m','u','n','d','o', 0}; //El 0 indica el fin de la cadena.


    -----Accediendo a los elementos de un arreglo-----

    Usando la noción vectorial en un arreglo, es posible acceder a cada elemento de un arreglo que indique su posición
    relativa en todo el arreglo:

        (0,1,2,3,4,...,n-1)

    Sea [i] el índice de un arreglo y sea 'n' el tamaño total del arreglo, el índice tendrá un intervalo de [0, n-1].
    Véase que desde un inicio se comentó que se consideraba un espacio vacío!

    Cabe señalar que cada elemento de un arreglo es una variable como tal y puede ser manipulado de dicha forma.

    PELIGRO!
    Si [i]>=n el arreglo comenzará a invadir memoria que no le corresponde. En S.O como Linux esto producirá el denominado
    error de segmentación.


    +Ejemplo 1: Sean los arreglos declarados e inicializados por un programador:

        int arreglo[10];
        char arreglo2[50];
        double lulo[25];

        ¿Las siguientes lineas de código son correctas?

        a) lulo[5]=60;
        b) double a=lulo[65];
        c) arreglo[10]=3758;

        Para a)
        Claro! Se está accediendo correctamente al índice 5 del arreglo y se le está asignando el valor de 60. Cabe recordar
        que los float y los double también admiten enteros sin ningún problema.

        Para b)
        No! Si analizamos la línea, observamos que se está asignando lo contenido en lulo[65] a una variable de tipo
        double llamada 'a'. El problema reside en que el tamaño de lulo llega hasta el índice 25, es decir, le estamos
        asignando basura que no le pertenece al arreglo a la variable 'a'.

        Para c)
        Tampoco! Se estableció que solo es posible alojar valores en el intervalo [0, n-1]. Por lo tanto, el programador está
        invadiendo memoria que no le corresponde :(


    +Ejemplo 2: Defina un arreglo de mil flotantes de doble precisión que empiecen en 0 e incrementen de 0.5 en 0.5 cada uno.
                0, 0.5, 1.5,..., etc.

*/
#include <stdio.h> //Biblioteca estándar de entrada/salida.

int main() { //Función principal leída por el S.O.

    double arreglo[1000]; //Nuestro arreglo de mil flotantes declarado.

    int i=0; //Variable de control.

    for(i=0; i<1000; i++){ //Cada elemento tendrá un incremento de 0.5 en cada iteración: (0, 0.5, 1, 1.5, 2,..., 499.5).
        arreglo[i]=i*0.5;
    }

return 0;
}



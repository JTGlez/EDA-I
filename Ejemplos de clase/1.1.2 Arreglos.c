/*
Tema 1.1.2: Arreglos

    +Arreglo: Es un conjunto ordenado de variables del mismo tipo de dato que son contiguas en la memoria. Su orden
              est� dado por un �ndice entero (el cual generalmente inicia en 0). Una forma de visualizarlo es como
              un vector, donde su dimensi�n corresponde al �ndice que se le asigne.

                   El �ndice de un arreglo considera un espacio vac�o que indica el fin del arreglo; recordando que
              la numeraci�n inicia desde 0.


    DECLARACI�N:
     tipoDato nombreArreglo[tama�o];

    -> �Como inicializar un arreglo? Existen dos formas:

        -Definir su tama�o con un �ndice dado:

            int arreglo[10]; //Arreglo con un intervalo de [0,9].

        -Definir expl�citamente los elementos del arreglo:

            int arreglo[]={1,2,3,4,5,6,7,8,9,10}; //N�tese que el compilador autom�ticamente le asignar� un �ndice 10.


    ->Una cadena de caracteres en el lenguaje C corresponde a un arreglo de caracteres. Si quisieramos declarar una cadena
      que diga "Hola mundo":

            char cadena[]="Hola mundo";

      El arreglo declarado anteriormente si fuese declarado expl�citamente tendr�a la siguiente forma:

            char cadena[]={'H','o','l','a','','m','u','n','d','o', 0}; //El 0 indica el fin de la cadena.


    -----Accediendo a los elementos de un arreglo-----

    Usando la noci�n vectorial en un arreglo, es posible acceder a cada elemento de un arreglo que indique su posici�n
    relativa en todo el arreglo:

        (0,1,2,3,4,...,n-1)

    Sea [i] el �ndice de un arreglo y sea 'n' el tama�o total del arreglo, el �ndice tendr� un intervalo de [0, n-1].
    V�ase que desde un inicio se coment� que se consideraba un espacio vac�o!

    Cabe se�alar que cada elemento de un arreglo es una variable como tal y puede ser manipulado de dicha forma.

    PELIGRO!
    Si [i]>=n el arreglo comenzar� a invadir memoria que no le corresponde. En S.O como Linux esto producir� el denominado
    error de segmentaci�n.


    +Ejemplo 1: Sean los arreglos declarados e inicializados por un programador:

        int arreglo[10];
        char arreglo2[50];
        double lulo[25];

        �Las siguientes lineas de c�digo son correctas?

        a) lulo[5]=60;
        b) double a=lulo[65];
        c) arreglo[10]=3758;

        Para a)
        Claro! Se est� accediendo correctamente al �ndice 5 del arreglo y se le est� asignando el valor de 60. Cabe recordar
        que los float y los double tambi�n admiten enteros sin ning�n problema.

        Para b)
        No! Si analizamos la l�nea, observamos que se est� asignando lo contenido en lulo[65] a una variable de tipo
        double llamada 'a'. El problema reside en que el tama�o de lulo llega hasta el �ndice 25, es decir, le estamos
        asignando basura que no le pertenece al arreglo a la variable 'a'.

        Para c)
        Tampoco! Se estableci� que solo es posible alojar valores en el intervalo [0, n-1]. Por lo tanto, el programador est�
        invadiendo memoria que no le corresponde :(


    +Ejemplo 2: Defina un arreglo de mil flotantes de doble precisi�n que empiecen en 0 e incrementen de 0.5 en 0.5 cada uno.
                0, 0.5, 1.5,..., etc.

*/
#include <stdio.h> //Biblioteca est�ndar de entrada/salida.

int main() { //Funci�n principal le�da por el S.O.

    double arreglo[1000]; //Nuestro arreglo de mil flotantes declarado.

    int i=0; //Variable de control.

    for(i=0; i<1000; i++){ //Cada elemento tendr� un incremento de 0.5 en cada iteraci�n: (0, 0.5, 1, 1.5, 2,..., 499.5).
        arreglo[i]=i*0.5;
    }

return 0;
}



/*
Tema 1.1.3: Apuntadores aplicados a arreglos.

    Los apuntadores poseen una importancia fundamental en el lenguaje C, pues a partir de ellos se definen los arreglos.
    La notaci�n usada para acceder a los elementos de un arreglo utiliza impl�citamente apuntadores para acceder a la
    informaci�n almacenada en cada espacio de memoria.

    De all� que son importantes las siguientes observaciones:

    +El nombre de un arreglo contiene la direcci�n de memoria de su primer elemento.
    +Cuando un apuntador apunta a un arreglo es posible acceder a sus elementos de dos formas:

     1. Usando el apuntador como un arreglo, usando su notaci�n usual.
     2. Usar aritm�tica de apuntadores.

     ->Aritm�tica de apuntadores

     Como un apuntador almacena una direcci�n de memoria (que esencialmente es un n�mero entero), se puede saltar a localidades
     vecinas sumando o restando el n�mero que representa al salto.

     Ejemplo 1: Declare un arreglo de 10 enteros y un apuntador que guarde la direcci�n de memoria del 1er elemento del arreglo.
                Utilice el apuntador para inicializar los elementos del arreglo con ceros.

 */

 #include <stdio.h>
 #define NULL 0

 int main () {

    int vector[10]; //Arreglo de 10 enteros declarado.

    int *ap=NULL; //Apuntador inicializado a 0. Es sugerido siempre que un apuntador siempre se inicialize en 0.

    ap=&vector[0]; //Recordando que el nombre de un vector guarda la direcci�n de memoria, se puede prescindir del &.

    //Un apuntador puede utilizarse con la notaci�n de arreglo.

    for (int i=0; i<10; i++) {

        ap[i]=0; //Accedemos al contenido de la i�sima direcci�n del arreglo al que apunta ap y se le asigna un 0.
    }

    //La otra v�a es con aritm�tica de apuntadores.

    for (int i=0; i<10; i++) {

        *(ap+i)=0; //Accedemos movi�ndonos un espacio entre cada iteraci�n; recordando la contiguidad de los elementos.

    }

 return 0;
 }

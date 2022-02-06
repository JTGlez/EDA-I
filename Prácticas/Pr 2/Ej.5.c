#include<stdio.h>
/*
 Se imprimen 3 valores de un arreglo a trav�s
 de aritm�tica de direcciones.
*/
int main () {
 short arr[5] = {91,28,73,46,55}; //Se declara un arreglo de cinco elementos y un apuntador que dirija al arreglo.
 short *apArr;
 apArr = arr; //Al apuntador se le asgina la direcci�n de memoria del primer elemento en arr. No requiere utilizar un operador unario ampersan.
 printf("*apArr = %i\n",*apArr);
 // Usando aritm�tica de apuntadores nos dirigimos a imprimir el contenido de la direcci�n 1 y la direcci�n 2.
 printf("*(apArr+1) = %i\n",*(apArr+1));
 printf("*(apArr+2) = %i\n",*(apArr+2));
 return 0;
}

#include <stdio.h>
/*
 Se recorre un arreglo unidimensional a trav�s de un apuntador
*/
int main(){
 short nums[] = {55,44,33,22,11}; //Declaraci�n del arreglo, un apuntador que apunte a la direcci�n 0 del arreglo y un contador para el ciclo for.
 short *ap, cont;
 ap = nums;
 for (cont = 0; cont < 5 ; cont++) //Usando el contador como variable de control, se recorre el arreglo usando aritm�tica de apuntadores. Imprime la direcci�n de cada espacio.
 printf("%x\n",(ap+cont));
 return 0;
}

#include <stdio.h>
/*
 Se recorre un arreglo unidimensional a través de un apuntador
*/
int main(){
 short nums[] = {55,44,33,22,11}; //Declaración del arreglo, un apuntador que apunte a la dirección 0 del arreglo y un contador para el ciclo for.
 short *ap, cont;
 ap = nums;
 for (cont = 0; cont < 5 ; cont++) //Usando el contador como variable de control, se recorre el arreglo usando aritmética de apuntadores. Imprime la dirección de cada espacio.
 printf("%x\n",(ap+cont));
 return 0;
}

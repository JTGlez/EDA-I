#include<stdio.h>
/*
 Se recorre un arreglo bidimensional a través de un apuntador
*/
int main(){
 int *ap, indice;
 int nums[3][3] = {{99,88,77}, //Declaración del arreglo matricial, un apuntador que apunta a la dirección 0,0 del arreglo y un contador.
 {66,55,44},
 {33,22,11}};
 ap = nums;
 for (indice = 0; indice < 9 ; indice++){ //Ciclo for con índice<(número de elementos en la matriz).
 if (indice%3==0) //Si el indice mod 3 produce un residuo 0...
 printf("\n");
 printf("%x\t",(ap+indice)); //Si se elimina el if, queda un listado de las direcciones de memoria...
 }
 return 0;
}


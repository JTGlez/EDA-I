#include <stdio.h>

#include "pila.h"

int main(void) {
  int pila[N];
  int tope=-1;
 
  int error=TODO_BIEN;


  error=push(pila, &tope, 5);

  

  if(error!=TODO_BIEN){
    imprimirError(error);
  }

  imprimirPila(pila,tope);

  int elementoSacadoDeLaPila;
  error=pop(pila, &tope, &elementoSacadoDeLaPila);

  imprimirPila(pila,tope);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define ERROR_PILA_LLENA -1000
#define TODO_BIEN 0

struct Nodo{
  int valor;
  struct Nodo *siguiente;
};
typedef struct Nodo Nodo;

Nodo* crearNodo (void){
  Nodo *n;
  n=(Nodo *)malloc(sizeof(Nodo));
  return n;
}

int push(Nodo** tope, Nodo* nodoAInsertar){
  if (nodoAInsertar==NULL)
  {
   return ERROR_PILA_LLENA;
  }else{
    if (*tope == NULL)
    {
      nodoAInsertar->siguiente=NULL;
      *tope=nodoAInsertar;
    }else{
      nodoAInsertar->siguiente=*tope;
      *tope=nodoAInsertar;
    }
  }
  return TODO_BIEN;
}


int main(void){
  Nodo *tope=NULL;

  Nodo *nodoAInsertar;
  nodoAInsertar= crearNodo();
  nodoAInsertar->valor=1;
  push(&tope, nodoAInsertar);

  nodoAInsertar= crearNodo();
  nodoAInsertar->valor=2;
  push(&tope, nodoAInsertar);

  nodoAInsertar= crearNodo();
  nodoAInsertar->valor=3;
  push(&tope, nodoAInsertar);


}

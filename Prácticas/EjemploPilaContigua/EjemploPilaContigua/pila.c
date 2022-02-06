#include "pila.h"


int push(int pila[], int* tope, int elementoAInsertar){
  if(*tope==(N-1)){
    return ERROR_PILA_LLENA;
  }
    *tope=*tope+1;
    pila[*tope]=elementoAInsertar;
    return TODO_BIEN;
}

int pop(int pila[],int *tope, int*elementoSacado){
  if(*tope==-1){
    return ERROR_PILA_VACIA;
  }

  *elementoSacado=pila[*tope];
  *tope=*tope-1;
  return TODO_BIEN;
}

//version de Pop que como valor devuelto
//da el entero que fue sacado de la pila
int pop2(int pila[], int *tope){
  if(*tope==-1){
    printf("La pila está vacía.");
    return INT_MIN;
  }

  int elementoSacado=pila[*tope];
  *tope=*tope-1;

  return elementoSacado;
}

void imprimirError(int error){
  switch(error){
    case ERROR_PILA_LLENA:
      printf("La pila está llena.\n");
      break;
    
    case ERROR_PILA_VACIA:
      printf("La pila está vacía.\n");
      break; 
  }
}

void imprimirPila(int pila[],int tope){

  int i;

  if(tope==-1){
    imprimirError(ERROR_PILA_VACIA);
  }

  for(i=tope;i>=0;i--){
    printf("pila[%d]: %d\n",i,pila[i]);
  }
}

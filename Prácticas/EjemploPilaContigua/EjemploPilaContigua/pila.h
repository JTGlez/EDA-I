#ifndef PILA_H
#define PILA_H

#include <stdio.h>
#include<limits.h>
#define N 10
#define TODO_BIEN 0
#define ERROR_PILA_LLENA -1000
#define ERROR_PILA_VACIA -1001

int push(int pila[], int* tope, int elementoAInsertar);
int pop(int pila[],int *tope, int*elementoSacado);
int pop2(int pila[], int *tope);
void imprimirError(int error);
void imprimirPila(int pila[],int tope);

#endif

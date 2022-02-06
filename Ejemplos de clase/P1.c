//
//  main.c
//  P1
//
//  Created by alumno on 8/12/19.
//  Copyright � 2019 alumno. All rights reserved.
//

#include <stdio.h>
/*
Llamada a la biblioteca principal para funciones como scanf o printf. El car�cter # indica al preprocesador incluir las funciones necesarias para el programa.
 */

/*
 Programa que realiza la implementaci�n de la escitala espartana
 Para cifrar y descifrar.
 */

void crearMensaje(void);
void descifrarMensaje(void); //La declaraci�n correcta incluye un par�metro void (Es decir, no va a recibir ning�n par�metro).

int main(){
    int opcion=0;
    while (1){ //Mientras la condici�n sea verdadera, se ejecutar� (y siempre lo har�).
        printf("\n\t*** ESC�TALA ESPARTANA ***\n");
        printf("�Qu� desea realizar?\n");
        printf("1) Crear mensaje cifrado.\n");
        printf("2) Descifrar mensaje.\n");  //Ciclo while que muestra las opciones principales del programa.
        printf("3) Salir.\n");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                crearMensaje();
                break;    //El c�digo original inclu�a un break mal colocado. Despu�s de las instrucciones en un case se coloca un break.
            case 2:
                descifrarMensaje();
                break;
            case 3:
                return 0; //Corta completamente la ejecuci�n del programa.
            default:
                printf("Opci�n no v�lida.\n");
        }
    }
    return 0;
}
void crearMensaje(){
    int ren, col, i, j, k=0;  //Definici�n de variables enteras a utilizar en el programa.
    printf("Ingresar el tama�o de la esc�tala:\n");
    printf("\nRenglones:");
    scanf("%i",&ren);    //Se pide la dimensi�n de la matriz a trabajar.
    printf("\nColumnas:");
    scanf("%i",&col);
    char escitala[ren][col];
    char texto[ren*col];   //Con base en la dimensi�n de la matriz, es decir, de los car�cteres almacenados.
    printf("Escriba el texto a cifrar:\n");
    scanf("%s", texto); //Dado que el arreglo guarda la direcci�n del primer elemento, el amperson resulta innecesario.
    for (i=0 ; i<ren ; i++) {
        for (j=0 ; j<col ; j++) {   //Ciclo for que permite iterar en la matriz, asignando lo que encuentre en el arreglo texto[k] en el indice (i,j), dependiendo la iteraci�n.
            //escitala[i][j]=texto[k++]
            escitala[i][j] = texto[k];
            k=k+1;
            } //K++ implica 2 instrucciones (k=k y k=k+1).
    }
    printf("El texto en la tira queda de la siguiente manera:\n");
    for (i=0 ; i<col ; i++)
        for (j=0 ; j<ren ; j++)
            printf("%c", escitala[j][i]);
    printf("\n");

}
void descifrarMensaje(){
    int ren, col, i, j, k=0;
    printf("Ingresar el tama�o de la esc�tala:\n");
    printf("\nRenglones:");
    scanf("%i",&ren);
    printf("\nColumnas:");
    scanf("%i",&col);
    char escitala[ren][col];
    char texto[ren*col];
    printf("Escriba el texto a descifrar:\n");
    scanf("%s", texto);
    for (i=0 ; i<col ; i++)
        for (j=0 ; j<ren ; j++)
            escitala[j][i] = texto[k++];
    printf("El texto descifrado es:\n");
    for (i=0 ; i<ren ; i++)
        for (j=0 ; j<col ; j++)
            printf("%c", escitala[i][j]);
}

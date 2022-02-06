/*
    Ejemplo 2 del Tema 1.2: Administraci�n de memoria en tiempo de ejecuci�n.

    Habiendo analizado el caso base para manipular las funciones de DMA, se ver�n otras utilidades en el siguiente ejemplo:

   1)Utilice la funcion malloc para reservar espacio para 10 doubles.
   2)Utilice un apuntador para guardar las primeras diez potencias negativas de 2 en los 10 doubles de ...1)
   3)Cree un arreglo de diez apuntadores a double.
   4)Apunte cada uno de los apuntadores creados en ...3) a los 10 doubles de ...1)
   5)Utilice el arreglo de 4) para modificar los doubles de ...1) y guardar las primeras 10 potencias positivas de 2.
   6)Imprimir los 10 doubles.

*/

    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <locale.h>

    int main(){

    setlocale(LC_CTYPE,"spanish");

    //1) El espacio para los diez doubles se almacenar� en un apuntador:

    double *elementosDouble=(double*)malloc(10*sizeof(double));

    //2) Se usar� un ciclo for para guardar potencias negativas de 2 en los 10 double solicitados:

    for(int i=0; i<10; i++){

        *(elementosDouble+i)=(1/pow(2, i+1));
        //Otra posibilidad para escribir la l�nea 30 es: elementosDouble[i]=(1/pow(2, i+1));

    }

    printf("Imprimiendo los n�meros actuales: \n");
    for (int i=0; i<10; i++) {
        printf("\n[%d] %f", i, elementosDouble[i]);
    }



    //3) Se declarar� el arreglo de 10 apuntadores a double:

    double *arregloDeApuntadores[10];

    //4) Ahora se har� que los apuntadores guarden la direcci�n de memoria de los 10 doubles:

    for(int i=0; i<10; i++){

        *(arregloDeApuntadores+i)= (elementosDouble+i);
        //Con notaci�n de arreglo la l�nea anterior resulta: arregloDeApuntadores[i]=&elementosDouble[i];

    }

    //5) Ahora se usar� el arreglo para modificar los doubles a los que apunta el arreglo:

    for(int i=0; i<10; i++){

        **(arregloDeApuntadores+i)=pow(2, i+1);

    }

    //6) Imprimiendo el resultado:

    printf("\nImprimiendo los n�meros resultantes: \n");
    for (int i=0; i<10; i++) {
        printf("\n[%d] %f", i, elementosDouble[i]);
      //printf("[%d] %f", i, *(elementos+i));
      //printf("[%d] %f", i, *arreglo[i]);
    }


    return 0;
    }

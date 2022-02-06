/*
    Ejemplo 2 del Tema 1.2: Administración de memoria en tiempo de ejecución.

    Habiendo analizado el caso base para manipular las funciones de DMA, se verán otras utilidades en el siguiente ejemplo:

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

    //1) El espacio para los diez doubles se almacenará en un apuntador:

    double *elementosDouble=(double*)malloc(10*sizeof(double));

    //2) Se usará un ciclo for para guardar potencias negativas de 2 en los 10 double solicitados:

    for(int i=0; i<10; i++){

        *(elementosDouble+i)=(1/pow(2, i+1));
        //Otra posibilidad para escribir la línea 30 es: elementosDouble[i]=(1/pow(2, i+1));

    }

    printf("Imprimiendo los números actuales: \n");
    for (int i=0; i<10; i++) {
        printf("\n[%d] %f", i, elementosDouble[i]);
    }



    //3) Se declarará el arreglo de 10 apuntadores a double:

    double *arregloDeApuntadores[10];

    //4) Ahora se hará que los apuntadores guarden la dirección de memoria de los 10 doubles:

    for(int i=0; i<10; i++){

        *(arregloDeApuntadores+i)= (elementosDouble+i);
        //Con notación de arreglo la línea anterior resulta: arregloDeApuntadores[i]=&elementosDouble[i];

    }

    //5) Ahora se usará el arreglo para modificar los doubles a los que apunta el arreglo:

    for(int i=0; i<10; i++){

        **(arregloDeApuntadores+i)=pow(2, i+1);

    }

    //6) Imprimiendo el resultado:

    printf("\nImprimiendo los números resultantes: \n");
    for (int i=0; i<10; i++) {
        printf("\n[%d] %f", i, elementosDouble[i]);
      //printf("[%d] %f", i, *(elementos+i));
      //printf("[%d] %f", i, *arreglo[i]);
    }


    return 0;
    }

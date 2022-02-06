/*
    Ejemplo 3 del Tema 1.2: Administración de memoria en tiempo de ejecución.

    En este ejemplo se explorará el uso de estas funciones para modelar y manipular vectores en R3.

    1)Reserve memoria para un numero de vectores en R3 pedidos por el usuario.
    2)Incializar las componentes de cada vector, pidiéndoselas al usuario.
    3)Imprimir la norma de los vectores dados.

*/

    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>

    typedef struct VectorR3{

    float i;
    float j;
    float k;

    }VectorR3;

    double normaVector (VectorR3 v) {
    return sqrt(v.i*v.i + v.j*v.j + v.k*v.k);
    }

    int main(){

    int numeroDeVectores=0;

    printf("Ingrese el número de vectores que desea ingresar: \t");
    scanf("%d", &numeroDeVectores);

    VectorR3 *vectoresIngresados=(VectorR3 *)malloc(numeroDeVectores*sizeof(VectorR3));


    for (int x=0; x<numeroDeVectores; x++) {
        printf("Ingrese las componentes del vector %d:\n", x+1);
        printf ("\ti:  ");
        scanf("%f", &vectoresIngresados[x].i);
        printf ("\tj:  ");
        scanf("%f", &vectoresIngresados[x].j);
        printf ("\tk:  ");
        scanf("%f", &vectoresIngresados[x].k);
    }

    for(int x=0; x<numeroDeVectores; x++){

    printf("Vector %d: (%f,%f,%f) \n", x+1, vectoresIngresados[x].i, vectoresIngresados[x].j, vectoresIngresados[x].k);


    }

    for (int i=0; i<numeroDeVectores; i++) {
        printf ("La norma del vector %d: es %f \n", i+1, normaVector(vectoresIngresados[i]));

    }


    return 0;
    }

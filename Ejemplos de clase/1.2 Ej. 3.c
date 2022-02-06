/* Ejemplo 3

   1)Reserve memoria para un numero de Vector3D pedido al usuario.
   2)Incializar las componentes de cada vector, pidiendoselas al usuario.
   3)Imprimir la norma de los vectores dados.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Vector3D {

    double x, y, z;


};

typedef struct Vector3D Vector3D;

double normaVector (Vector3D v) {
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
    }

int main () {

    int numeroDeVectores=0;
    printf ("Ingrese el numero de Vectores: \n");
    scanf ("%d", &numeroDeVectores);

    Vector3D *v= (Vector3D *)malloc(sizeof(Vector3D)*numeroDeVectores); //Lo que malloc devuelve va a parar a *v.
    calloc(numeroDeVectores, sizeof(Vector3D));

    for (int i=0; i<numeroDeVectores; i++) {
        printf("Ingrese las componentes del vector %d:\n", i+1);
        printf ("\tX:  ");
        scanf("%f", &v[i].x);
        printf ("\tY:  ");
        scanf("%f", &v[i].y);
        printf ("\tZ:  ");
        scanf("%f", &v[i].z);
    }

    for (int i=0; i<numeroDeVectores; i++) {
        printf ("La norma del vector %d: es %f \n", i+1, normaVector(v[i]));

    }



}



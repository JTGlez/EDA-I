/* Ejemplo Tema 1.1.2

   1)Utilice la funcion malloc para reservar espacio para 10 doubles.
   2)Utilice un apuntador para guardar las primeras diez potencias negativas de 2 en los 10 doubles de ...1)
   3)Cree un arreglo de diez apuntadores a double.
   4)Apunte cada uno de los apuntadores creados en ...3) a los 10 doubles de ...1)
   5)Utilice el arreglo de 4) para modificar los doubles de ...1) y guardar las primeras 10 potencias positivas de 2.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {

    int numeroDeDoubles=10;
    double nPotenciaDeDos=2.0;
    double *elementos=(double*)malloc(numeroDeDoubles*sizeof(double));

    // elementos[0]=1/2.0;
    //*elementos=1/2.0;
    //*(elementos + 0)=1/2.0;

    for (int i=0; i<numeroDeDoubles; i++) {
        elementos[i]=1/pow(2, i+1);
    //*(elementos + i)= Usando aritemetica de apuntadores.
    }

    double *arreglo[10];

    //arreglo[0]=elementos      //arreglo[0]=&elementos[0];
    //arreglo[1]=elementos+1;

    for (int i=0; i<numeroDeDoubles; i++) {
        arreglo[i]=elementos+i;
        //arreglo[i]=&elementos[i];
    }

    //*(arreglo[0])=2.0;


    for (int i=0; i<numeroDeDoubles; i++) {

        *arreglo[i]=pow(2, i+1);
        //Si el dos se define como variable, otra opcion es:
        //*arreglo[i]=nPotenciaDeDos; nPotenciaDeDos*=2;
    }

return 0;
}

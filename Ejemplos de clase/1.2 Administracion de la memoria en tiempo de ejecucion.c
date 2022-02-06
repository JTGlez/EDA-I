/*(1)Solicitar 5 enteros de 32 bits en tiempo de ejecucion.
  (2)Guardar los primeros cinco naturales en los enteros de ...1)
  (3)Liberar la memoria solicitada.
*/

 #include <stdio.h>
 #include <stdlib.h>

     int main () {
     //1) Comunmente se ocupaba para pedir memoria un arreglo con un tamaño fijo... pero si fuese una base de datos de alumnos?

     int*apt =(int*)calloc(5, sizeof(int)); //Se piden 5 enteros de 32 bits (4 bytes). Luego, void* se convierte a int*.

     /*Dicho de otro modo, se declaro una variable apuntadora apt que almacena la direccion.
       Como hay una diferencia en los tipo de dato, se realiza un cast a int*, que es el tipo de dato objetivo.
       Calloc devolvera la direccion del primer elemento de los 5 nuevos. Esa direccion sera asignada al apuntador apt. */

    //2)

       *apt=1;
       *(apt+1)=2;
       *(apt+2)=3;
       *(apt+3)=4;
       *(apt+4)=5;

    //Otras opciones son *apt=1 ; apt [0]=1 ; *(apt+0)=1;

    //Incluso, con un ciclo for.

    for (int i=0; i<5; i++) {

        *(apt+i)=(i+1);
        //apt[i]=i+1;
    }

    // 3) Liberar la memoria solicitada.

     free(apt);

     return 0;
     }

     //Cuando el programa termina la memoria es liberada.

/*

    Tema 1.2: Administraci�n de la memoria en tiempo de ejecuci�n (DMA).

    Cuando se declaran diversos entes o datos al momento de escribir un programa y ejecutarlo, estos se guardan en un espacio
    previamente reservado de la memoria para estar disponibles durante la ejecuci�n del mismo.

        Sin embargo, tambi�n existe la posibilidad de solicitar una mayor cantidad de memoria a la computadora para la
    creaci�n de nuevas variables o entes al momento de estar ejecutando un programa: A esto se le denomina Control Din�mica
    de la memoria.


    + Organizaci�n interna de la RAM:

    Dentro de la Memoria de Acceso Aleatorio (RAM) existen dos ubicaciones importantes donde se almacena y se manipula informaci�n
    de forma diferente:

        -Stack: Es una ubicaci�n est�tica de la memoria donde se almacenan todas las variables, arreglos o apuntadores declarados
        en las l�neas de c�digo de un programa.

        -Heap: Ubicaci�n din�mica para solicitar y almacenar datos hasta el tiempo de ejecuci�n.


    +Control Din�mica de la Memoria:

    Hace referencia a la solicitud para reservar o liberar memoria del mont�culo mediante peticiones al S.O.


    FUNCIONES EN LENGUAJE C PARA CONTROL DIN�MICO DE MEMORIA:

    La librer�a est�ndar <stdlib.h> posee diversas funciones definidas para hacer uso din�mico de la memoria del Heap (tambi�n
    denominado como "Mont�culo" en espa�ol). A continuaci�n se presentan las m�s importantes para este prop�sito.

    +Reservar Memoria:

        Funci�n malloc: Usada para reservar un bloque de N bytes contiguos en la memoria:

                            void* malloc (size_t numeroDeBytes);

            Donde:

                void*: Direcci�n de inicio del bloque asignado.
                size_t: Entero que representa el n�mero de bytes solicitados.

        Funci�n calloc: Usada para reservar X elemente de N bytes cada uno; inicializados en 0.

                            void* calloc (size_t numeroDeElementos, size_t bytesPorElemento);

        Funci�n realloc: Usada para reasignar un bloque previamente solicitado en tiempo de ejecuci�n a un nuevo bloque de
                         memoria de mayor tama�o.

                            void* realloc(void* bloquePrevio, size_t tama�oNuevaDireccion);


    +Liberar Memoria:

        Funci�n free: Devuelve o libera un bloque de memoria solicitada en tiempo de ejecuci�n.

                                void* free (void* bloqueALiberar);


    +Proceso Cast:

    Como se not� anteriormente, el tipo de dato void* representa la direcci�n de memoria de alg�n grupo de bytes solicitados.
    Cualquier variable de tipo void* debe ser convertida a un tipo de dato primitivo, apuntador o abstracto: A este proceso de
    conversi�n se le conoce con el nombre de Cast.

        En lenguaje C un cast se realiza escribiendo entre par�ntesis el tipo de dato destino, antecediendo a la variable convertida:

                            (tipoDeDatoDestino)variableAConvertir;


    CONSIDERACIONES:

        +Al t�rmino de un programa, el S.O. libera toda la memoria solicitada en tiempo de ejecuci�n.

        +Mientras el programa no termine es responsabilidad del programador liberar la memoria din�mica y mantener apuntadores a los
         bloques de memoria din�mica solicitados.

        +Existen situaciones donde el S.O. no logra asignar memoria exitosamente, entonces, es conveniente reviosar que la direcci�n
         devuelta a una petici�n de memoria sea diferente de 0.


    �Por qu� es importante la memoria din�mica?: Piense en la cl�sica forma de pedir memoria: Mediante un arreglo de tama�o fijo. �Qu� pasar�a si esto se hiciera para una
                                                 base de datos de muchas personas? La memoria din�mica permite un uso eficiente de los recursos de una computadora; los cuales
                                                 son finitos y limitados en todos los casos.


    Ejemplo 1: (1)Solicitar 5 enteros de 32 bits en tiempo de ejecucion.
               (2)Guardar los primeros cinco naturales en los enteros de ...1)
               (3)Liberar la memoria solicitada.


*/

    #include <stdio.h>
    #include <stdlib.h>

     int main () {

     //1) Solicitemos los cinco enteros de 32 bits solicitados usando la funci�n calloc; y guardaremos su direcci�n en un apuntador

     int *apuntadorAEnteros = (int*)calloc(5, sizeof(int));

     /*Note las operaciones involucradas: Se realiza directamente la asignaci�n de la direcci�n que almacenar� apuntadorAEnteros. Adem�s, como calloc devuelve un tipo de dato void*, el Cast
       correspondiente se realiza para que el tipo de dato coincida. As� mismo, se utiliza una funci�n denominada sizeof(size_t) que devuelve el tama�o de un tipo de dato primitivo o abstracto.

            La direcci�n devuelta es la del primero de los cinco enteros reservados en la memoria. Es relevante recordar que estos cinco enteros fueron asignados de manera contigua en la memoria
        por acci�n de calloc.

    */


    //2) Teniendo nuestra direcci�n del primer elemento, podemos usar aritm�tica de apuntadores para inicializar cada entero:

       *apuntadorAEnteros=1;
       *(apuntadorAEnteros+1)=2;
       *(apuntadorAEnteros+2)=3;
       *(apuntadorAEnteros+3)=4;
       *(apuntadorAEnteros+4)=5;

    //Otras opciones igualmente v�lidas son apuntadorAEnteros[0]=1 o *(apuntadorAEnteros+0)=1;

    //Incluso, cabe la posibilidad de realizarlo con un ciclo for:

    for (int i=0; i<5; i++) {

        *(apuntadorAEnteros+i)=(i+1);
        //apuntadorAEnteros[i]=i+1;
    }

    //3) Hecho lo anterior, es hora de liberar la memoria:

     free(apuntadorAEnteros);

     return 0;
     }

     //Cuando el programa termina la memoria es liberada.

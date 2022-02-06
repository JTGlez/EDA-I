/*

    Tema 1.2: Administración de la memoria en tiempo de ejecución (DMA).

    Cuando se declaran diversos entes o datos al momento de escribir un programa y ejecutarlo, estos se guardan en un espacio
    previamente reservado de la memoria para estar disponibles durante la ejecución del mismo.

        Sin embargo, también existe la posibilidad de solicitar una mayor cantidad de memoria a la computadora para la
    creación de nuevas variables o entes al momento de estar ejecutando un programa: A esto se le denomina Control Dinámica
    de la memoria.


    + Organización interna de la RAM:

    Dentro de la Memoria de Acceso Aleatorio (RAM) existen dos ubicaciones importantes donde se almacena y se manipula información
    de forma diferente:

        -Stack: Es una ubicación estática de la memoria donde se almacenan todas las variables, arreglos o apuntadores declarados
        en las líneas de código de un programa.

        -Heap: Ubicación dinámica para solicitar y almacenar datos hasta el tiempo de ejecución.


    +Control Dinámica de la Memoria:

    Hace referencia a la solicitud para reservar o liberar memoria del montículo mediante peticiones al S.O.


    FUNCIONES EN LENGUAJE C PARA CONTROL DINÁMICO DE MEMORIA:

    La librería estándar <stdlib.h> posee diversas funciones definidas para hacer uso dinámico de la memoria del Heap (también
    denominado como "Montículo" en español). A continuación se presentan las más importantes para este propósito.

    +Reservar Memoria:

        Función malloc: Usada para reservar un bloque de N bytes contiguos en la memoria:

                            void* malloc (size_t numeroDeBytes);

            Donde:

                void*: Dirección de inicio del bloque asignado.
                size_t: Entero que representa el número de bytes solicitados.

        Función calloc: Usada para reservar X elemente de N bytes cada uno; inicializados en 0.

                            void* calloc (size_t numeroDeElementos, size_t bytesPorElemento);

        Función realloc: Usada para reasignar un bloque previamente solicitado en tiempo de ejecución a un nuevo bloque de
                         memoria de mayor tamaño.

                            void* realloc(void* bloquePrevio, size_t tamañoNuevaDireccion);


    +Liberar Memoria:

        Función free: Devuelve o libera un bloque de memoria solicitada en tiempo de ejecución.

                                void* free (void* bloqueALiberar);


    +Proceso Cast:

    Como se notó anteriormente, el tipo de dato void* representa la dirección de memoria de algún grupo de bytes solicitados.
    Cualquier variable de tipo void* debe ser convertida a un tipo de dato primitivo, apuntador o abstracto: A este proceso de
    conversión se le conoce con el nombre de Cast.

        En lenguaje C un cast se realiza escribiendo entre paréntesis el tipo de dato destino, antecediendo a la variable convertida:

                            (tipoDeDatoDestino)variableAConvertir;


    CONSIDERACIONES:

        +Al término de un programa, el S.O. libera toda la memoria solicitada en tiempo de ejecución.

        +Mientras el programa no termine es responsabilidad del programador liberar la memoria dinámica y mantener apuntadores a los
         bloques de memoria dinámica solicitados.

        +Existen situaciones donde el S.O. no logra asignar memoria exitosamente, entonces, es conveniente reviosar que la dirección
         devuelta a una petición de memoria sea diferente de 0.


    ¿Por qué es importante la memoria dinámica?: Piense en la clásica forma de pedir memoria: Mediante un arreglo de tamaño fijo. ¿Qué pasaría si esto se hiciera para una
                                                 base de datos de muchas personas? La memoria dinámica permite un uso eficiente de los recursos de una computadora; los cuales
                                                 son finitos y limitados en todos los casos.


    Ejemplo 1: (1)Solicitar 5 enteros de 32 bits en tiempo de ejecucion.
               (2)Guardar los primeros cinco naturales en los enteros de ...1)
               (3)Liberar la memoria solicitada.


*/

    #include <stdio.h>
    #include <stdlib.h>

     int main () {

     //1) Solicitemos los cinco enteros de 32 bits solicitados usando la función calloc; y guardaremos su dirección en un apuntador

     int *apuntadorAEnteros = (int*)calloc(5, sizeof(int));

     /*Note las operaciones involucradas: Se realiza directamente la asignación de la dirección que almacenará apuntadorAEnteros. Además, como calloc devuelve un tipo de dato void*, el Cast
       correspondiente se realiza para que el tipo de dato coincida. Así mismo, se utiliza una función denominada sizeof(size_t) que devuelve el tamaño de un tipo de dato primitivo o abstracto.

            La dirección devuelta es la del primero de los cinco enteros reservados en la memoria. Es relevante recordar que estos cinco enteros fueron asignados de manera contigua en la memoria
        por acción de calloc.

    */


    //2) Teniendo nuestra dirección del primer elemento, podemos usar aritmética de apuntadores para inicializar cada entero:

       *apuntadorAEnteros=1;
       *(apuntadorAEnteros+1)=2;
       *(apuntadorAEnteros+2)=3;
       *(apuntadorAEnteros+3)=4;
       *(apuntadorAEnteros+4)=5;

    //Otras opciones igualmente válidas son apuntadorAEnteros[0]=1 o *(apuntadorAEnteros+0)=1;

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

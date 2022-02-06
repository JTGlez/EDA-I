/*
Tema 1.1: Representación de datos en memoria.

+Memoria: Se define como un conjunto ordenado y finito de celdas o espacios de 1 Byte con la capacidad de almacenar
          y obtener datos. Por tanto, es la base de ejecución de cualquier programa.

Tema 1.1.1: Tipos de datos primitivos

Cabe hacerse la siguiente pregunta desde un inicio... ¿Que es un tipo de dato?

+Tipo de dato: Etiqueta asignada a una variable que indica al compilador como utilizarla.

Existen diversos tipos de datos primitivos o elementales. Los más comunes son:

  ------Etiqueta char------

    +Este tipo de dato se utiliza principalmente para guardar en la memoria caracteres.
    +Ocupa 1 byte en la memoria.
    +Cada caracter posee un valor ASCII que lo identifica y que es usado para reconocerlo, por ello, el compilador sabrá
     que únicamente requiere una única celda de la memoria (1 Byte= 8 Bits con lugares 0 y 1).

    DECLARACIÓN:
     char nombreVariable = 'X';

  ------Etiqueta int------

    +Tipo de dato usado para números enteros, es decir, sin parte decimal.
    +Ocupan como máximo 4 Bytes en la memoria  y su máximo valor está dado por 2^(31)-1.
    +Internamente, el último espacio de los 32 Bits indica el signo del número. 0 para los (+) y 1 para los (-).

    DECLARACIÓN:
     int nombreVariable = N ; N pertenece a los enteros.

    +Es posible extender el tamaño de esta etiqueta asignando el prefijo long a la etiqueta:

     long nombreVariable = N ; N pertenece a los enteros.

  ------Etiqueta float------

    +Usado como representación aproximadas para los números reales.
    +Ocupan al igual que la etiqueta int 4 bytes de memoria.
    +La reglo del signo se sigue utilizando. Internamente utiliza la notación signo-base x10^(e).

    DECLARACIÓN:
     float nombreVariable = R ; R pertenece a los reales.

  ------Etiqueta double------

    +Extensión de la etiqueta float. También llamado "flotante de doble precisión".
    +Ocupa un total de 8 bytes en la memoria.

    DECLARACIÓN:
     float nombreVariable = R ; R pertenece a los reales.


*/


int main () {

//Declaremos tipos de datos primitivos:

    char letra = 'K'; //K tiene asociado un valor ASCII representado en 8 Bits/1 Byte.

    int entero = 1;

    long enteroLargo= 10;

    float realSimple = 3.14;

    double realDoble = 3.141592;

return 0;
}

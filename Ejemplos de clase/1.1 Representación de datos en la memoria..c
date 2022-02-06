/*
Tema 1.1: Representaci�n de datos en memoria.

+Memoria: Se define como un conjunto ordenado y finito de celdas o espacios de 1 Byte con la capacidad de almacenar
          y obtener datos. Por tanto, es la base de ejecuci�n de cualquier programa.

Tema 1.1.1: Tipos de datos primitivos

Cabe hacerse la siguiente pregunta desde un inicio... �Que es un tipo de dato?

+Tipo de dato: Etiqueta asignada a una variable que indica al compilador como utilizarla.

Existen diversos tipos de datos primitivos o elementales. Los m�s comunes son:

  ------Etiqueta char------

    +Este tipo de dato se utiliza principalmente para guardar en la memoria caracteres.
    +Ocupa 1 byte en la memoria.
    +Cada caracter posee un valor ASCII que lo identifica y que es usado para reconocerlo, por ello, el compilador sabr�
     que �nicamente requiere una �nica celda de la memoria (1 Byte= 8 Bits con lugares 0 y 1).

    DECLARACI�N:
     char nombreVariable = 'X';

  ------Etiqueta int------

    +Tipo de dato usado para n�meros enteros, es decir, sin parte decimal.
    +Ocupan como m�ximo 4 Bytes en la memoria  y su m�ximo valor est� dado por 2^(31)-1.
    +Internamente, el �ltimo espacio de los 32 Bits indica el signo del n�mero. 0 para los (+) y 1 para los (-).

    DECLARACI�N:
     int nombreVariable = N ; N pertenece a los enteros.

    +Es posible extender el tama�o de esta etiqueta asignando el prefijo long a la etiqueta:

     long nombreVariable = N ; N pertenece a los enteros.

  ------Etiqueta float------

    +Usado como representaci�n aproximadas para los n�meros reales.
    +Ocupan al igual que la etiqueta int 4 bytes de memoria.
    +La reglo del signo se sigue utilizando. Internamente utiliza la notaci�n signo-base x10^(e).

    DECLARACI�N:
     float nombreVariable = R ; R pertenece a los reales.

  ------Etiqueta double------

    +Extensi�n de la etiqueta float. Tambi�n llamado "flotante de doble precisi�n".
    +Ocupa un total de 8 bytes en la memoria.

    DECLARACI�N:
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

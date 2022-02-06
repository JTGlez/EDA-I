/*
    El almacenamiento ligado conecta nodos de informaci�n por medio de apuntadores, con el fin de que cada nodo conozca
    la ubicaci�n en la memoria del nodo que le sigue (permitiendo conocer la posici�n relativa del �ltimo elemento de
    una pila).

        Si no se usaran apuntadores para lo anterior, los nodos no conocer�an la posici�n en memoria de los otros nodos y,
    por lo tanto, la informaci�n cada nodo quedar�a perdida en la memoria y la pila dejar�a de tener sentido.

    Ejemplo: Defina un tipo de dato abstracto con las dos propiedades siguientes...

        -Un entero
        -Un apuntador a este tipo de dato abstracto.

        (Sugerencia: Nombre "Nodo" al tipo de dato).

    Ejemplo 2: Crear en tiempo de ejecucion una variable del tipo de dato definido en el ejemplo anterior.

    Ejemplo 3: Genere una funcion que se encargue de lo anterior.

    Ejemplo 4: Declare dos nodos (a y b) y realice lo siguiente:

                -Establecer como valor del nodo a, el entero 1 y como siguiente el valor NULL.

                -Establecer como valor del nodo b el entero 100, como siguiente el nodo a.

    Ejemplo 5: Implementar una pila de enteros con almacenamiento ligado.

*/

#include <stdio.h>
#include <stdlib.h>

    struct Nodo{

        int valor;
        struct Nodo *siguiente;

    };

    typedef struct Nodo Nodo;

    Nodo* crearNodo(void){ //Funci�n que retorna una direcci�n con memoria disponible para un programa.

        Nodo *n=(Nodo *)malloc(sizeof(Nodo)); //Ejemplo 2).
        //Nodo *n;
        //n=(Nodo *)malloc(sizeof(Nodo)); Otra posible forma de declarar la l�nea 44
        return n;

    }


    int main() {

    Nodo* a=crearNodo(); //Llamada a la funci�n del ejemplo 3).

    Nodo *b=crearNodo(); //En este punto ya se tienen dos nodos, el "a" y el "b".

    //Notese que realmente se est�n creando dos apuntadores que guardan la direcci�n de memoria de los nodos.
    //Internamente, esos bloques de memoria reservados poseen los atributos individuales que guarda cada nodo.

    a->valor=1;
    a->siguiente=NULL;

    b->valor=100;
    b->siguiente=a; //El atributo siguiente "b" guarda ahora la direcci�n de "a". Ejemplo 4) cumplido.


    return 0;
    }

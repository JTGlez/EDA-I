/*
    El almacenamiento ligado conecta nodos de información por medio de apuntadores, con el fin de que cada nodo conozca
    la ubicación en la memoria del nodo que le sigue (permitiendo conocer la posición relativa del último elemento de
    una pila).

        Si no se usaran apuntadores para lo anterior, los nodos no conocerían la posición en memoria de los otros nodos y,
    por lo tanto, la información cada nodo quedaría perdida en la memoria y la pila dejaría de tener sentido.

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

    Nodo* crearNodo(void){ //Función que retorna una dirección con memoria disponible para un programa.

        Nodo *n=(Nodo *)malloc(sizeof(Nodo)); //Ejemplo 2).
        //Nodo *n;
        //n=(Nodo *)malloc(sizeof(Nodo)); Otra posible forma de declarar la línea 44
        return n;

    }


    int main() {

    Nodo* a=crearNodo(); //Llamada a la función del ejemplo 3).

    Nodo *b=crearNodo(); //En este punto ya se tienen dos nodos, el "a" y el "b".

    //Notese que realmente se están creando dos apuntadores que guardan la dirección de memoria de los nodos.
    //Internamente, esos bloques de memoria reservados poseen los atributos individuales que guarda cada nodo.

    a->valor=1;
    a->siguiente=NULL;

    b->valor=100;
    b->siguiente=a; //El atributo siguiente "b" guarda ahora la dirección de "a". Ejemplo 4) cumplido.


    return 0;
    }

//Redefinir las funciones recibiendo apuntadors a struct pelicula.

#include <stdio.h>
#include <string.h>

struct pelicula{ //Declaración de los atributos del tipo de dato abstracto "pelicula".
    char *nombre;
    char *genero;
    short anio;
    short numDirectores;
    char *directores[10];
};
struct pelicula *p;
typedef struct pelicula pelicula;

void imprimirDatosPelicula(pelicula *p); //Prototipo de las funciones a utilizar.

void llenarDatosPelicula(pelicula *p,
                         char *,
                         char *,
                         short ,
                         short ,
                         char*[10]);



    int main() {
    char *directores[10]; //Arreglo de apuntadores.
    directores[0] = "Lana Wachowski"; //Se envía al arreglo en la posición 0 y 1 arreglos de caracteres.
    directores[1] = "Andy Wachowski";
    pelicula matrix;
    p=&matrix;
    llenarDatosPelicula(&matrix, "The matrix", "Cienciaficción", 1999, 2, directores);
    imprimirDatosPelicula(&matrix);
    return 0;
    }

    void llenarDatosPelicula(pelicula *p,
                             char *nombre,
                             char *genero,
                             short anio,
                             short numDirectores,
                             char *directores[10]){ //Variables dummy.

            strcpy(p->nombre, nombre);
            strcpy(p->genero, genero);
            p->anio=anio;
            p->numDirectores= numDirectores;
            int cont = 0;
            for ( ; cont < p->numDirectores ; cont++){
                strcpy(p->directores[cont], directores[cont]);
                                }

                                }

    void imprimirDatosPelicula(pelicula *p){
    printf("PELICULA: %s\n", p->nombre);
    printf("GENERO: %s\n", p->genero);      //únicamente se imprimen los atributos accediendo a ellos con el operador "."
    printf("ANIO: %d\n", p->anio);
    printf("DIRECTOR(ES):\n");
    int cont = 0;
    for ( ; cont < p->numDirectores ; cont++){
        printf("%s\n", p->directores[cont]);
    }

}

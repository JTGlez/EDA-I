#include <stdio.h>

struct pelicula{ //Declaración de los atributos del tipo de dato abstracto "pelicula".
    char *nombre;
    char *genero;
    short anio;
    short numDirectores;
    char *directores[10];
};
void imprimirDatosPelicula(struct pelicula); //Prototipo de las funciones a utilizar.

struct pelicula llenarDatosPelicula(char *, char *, short , short , char*[10]);



int main() {
char *directores[10]; //Arreglo de apuntadores.
directores[0] = "Lana Wachowski"; //Se envía al arreglo en la posición 0 y 1 arreglos de caracteres.
directores[1] = "Andy Wachowski";
struct pelicula matrix = llenarDatosPelicula("The matrix", "Cienciaficción", 1999, 2, directores); //  Se envian por valor los datos a la función y eso se almacenará en la variable abstracta "matrix".

    //Otra posible forma es llenarDatosPelicula(&matrix, "The Matrix", ...);
                                             imprimirDatosPelicula(matrix);
                                             return 0;
                                             }

                struct pelicula llenarDatosPelicula(char *nombre, char *genero, short anio, short numDirectores, char *directores[10]){ //Variables dummy.
                    struct pelicula movie; movie.nombre = nombre; movie.genero = genero;
                    movie.anio = anio;                         //Se asigna en los atributos de movie los datos recibidos por valor.
                    movie.numDirectores = numDirectores;
                    int cont = 0;
                    for ( ; cont < movie.numDirectores ; cont++){
                            movie.directores[cont] = directores[cont];
                                        }
                        return movie; //Los valores copiados irán a parar a la variable matrix y sus propiedades.
                            }

void imprimirDatosPelicula(struct pelicula movie){
    printf("PELICULA: %s\n", movie.nombre);
    printf("GENERO: %s\n", movie.genero);      //únicamente se imprimen los atributos accediendo a ellos con el operador "."
    printf("ANIO: %d\n", movie.anio);
    printf("DIRECTOR(ES):\n");
    int cont = 0;
    for ( ; cont < movie.numDirectores ; cont++){
        printf("%s\n", movie.directores[cont]);
    }

}

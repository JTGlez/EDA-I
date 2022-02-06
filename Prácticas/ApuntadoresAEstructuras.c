#include <stdio.h>
#include<string.h>

#define NUMERO_ACTORES 10

//Ejemplo
//Defina un tipo de dato abstracto que modele una película.
/*Algunas propiedades:
  -Duración
  -Género
  -Clasificación
  -Director
  -Actores
  -Nombre
  -Año
  -Calificación
*/
struct Pelicula{
  int duracion;
  char genero[50];
  char clasificacion[5];
  char director[50];
  char actores[NUMERO_ACTORES][50];
  char nombre[100];
  double calificacion;
};
typedef struct Pelicula Pelicula;

void imprimirPelicula(Pelicula *p){
  int numActores;
  printf("Nombre: %s",p->nombre);
  printf("Duracion: %d",p->duracion);
  for(numActores=0;numActores<NUMERO_ACTORES;numActores++){
    printf("El actor %d es: %s",numActores+1, p->actores[numActores]);
  }
}


int main(void) {
	Pelicula pelicula1;
  Pelicula *apuntadorAPeli;
  apuntadorAPeli=&pelicula1;

  (*apuntadorAPeli).calificacion=5.0;
  apuntadorAPeli->calificacion=5.0;
  pelicula1.calificacion=5.0;
	
  imprimirPelicula(apuntadorAPeli);
  imprimirPelicula(&pelicula1);

	return 0;

}
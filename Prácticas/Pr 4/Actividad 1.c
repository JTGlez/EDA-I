// P4: Actividad 1
// Reservar espacio para una varIable de un tipo de dato abstracto en tiempo de ejecución.
//
//
//
//
//

#include <stdio.h>
#include <stdlib.h>

struct Superheroe {

    char nombreDelSuperheroe[100]; //Inicializado explícitamente.
    char actorQueLoRepresenta[100];

};

typedef struct Superheroe Superheroe;

Superheroe* crearSuperheroe (void);
void pedirInformacionDeSuperheroe(Superheroe*);
void imprimirInformacionDeSuperheroe(Superheroe*);

int main(void) {

    Superheroe *superheroe; //Definir un apuntador y asignar a una dirección.

    superheroe=crearSuperheroe();
    pedirInformacionDeSuperheroe(superheroe);
    imprimirInformacionDeSuperheroe(superheroe);


    return 0;
}

Superheroe* crearSuperheroe (void) {

    Superheroe *ap=0;
    ap=(Superheroe*)malloc(sizeof(Superheroe));
    return ap;
}

void pedirInformacionDeSuperheroe(Superheroe *ap) {

    printf ("Ingrese el nombre del superheroe: \n");
    setbuf(stdin, NULL);
    fgets (ap->nombreDelSuperheroe,100,stdin); //Direccion y propiedad de lo contenido en la dirección.
    //scanf("%100[^\n]", ap->nombreDelSuperheroe);
    setbuf(stdin, NULL);
    printf ("Ingrese el nombre del actor: \n");
    fgets (ap->actorQueLoRepresenta,100,stdin);
}

void imprimirInformacionDeSuperheroe(Superheroe *ap) {

    printf ("El nombre del superheroe es: %s\n", ap->nombreDelSuperheroe);

    printf ("El nombre del actor es: %s\n", ap->actorQueLoRepresenta);

}




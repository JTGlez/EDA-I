#include<stdio.h>
/*
 Programa que realiza la implementación del cifrado César
*/
#define TAM_PALABRA 20
#define TAM_ABC 26

char abecedarioEnClaro[TAM_ABC] =
{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'
,'U','V','W','X','Y','Z'};                  //Declaración de los dos abecedarios.
char abecedarioCifrado[TAM_ABC] =
{'D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W'
,'X','Y','Z','A','B','C'};

void cifrar(char *textoEnClaro);
void descifrar(char *textoCifrado);   //Declaración de los prototipos de función.

int main(){
 short opcion = 0, contador; //Declaración de una variable de selección y otra de control.
 char palabra[TAM_PALABRA]; //Declaración del arreglo que contendrá caracteres escritos por el usuario.

 while (1){
    printf("\n\t*** CIFRADO CÉSAR ***\n");
    for (contador=0 ; contador<26; contador++)
        printf("%c", *(abecedarioEnClaro+contador));
    printf("\n");                                       //El código del while siempre se ejecuta. Imprime los abecedarios usando un for y aritmética de apuntadores.
    for (contador=0 ; contador<26; contador++)
    printf("%c", *(abecedarioCifrado+contador));

    printf("\nElegir una opción:\n");
    printf("1) Cifrar\n");
    printf("2) Descifrar.\n");
    printf("3) Salir.\n");
    scanf("%d", &opcion);

    switch(opcion){      //Switch de opciones.
    case 1:
        printf("Ingresar la palabra a cifrar (en mayúsculas): ");
        scanf("%s", palabra);
        cifrar(palabra);      //Envía por parámetro los caracteres escritos.
            break;
    case 2:
     printf("Ingresar la palabra a descifrar (en mayúsculas): ");
     scanf("%s", palabra);
     descifrar(palabra);      //Envía por parámetro los caracteres escritos.
     break;
     case 3:
     return 0;        //Termina el programa.
     default:
     printf("Opción no válida.");
         }
         }
    return 0;
    }

    //Funciones prototipo con su cuerpo de la función.


    void cifrar(char *textoEnClaro){              //Complicado de leer...
         printf("El texto %s cifrado es: ", textoEnClaro);
         int contadorAbcedario, contadorPalabra, indice = 0;
         for (contadorPalabra=0 ; contadorPalabra<textoEnClaro[contadorPalabra] ;contadorPalabra++)
         for (contadorAbcedario=0 ; contadorAbcedario<TAM_ABC ;contadorAbcedario++)

            if (abecedarioEnClaro[contadorAbcedario] == textoEnClaro[contadorPalabra]){
                printf("%c", abecedarioCifrado[contadorAbcedario]);
                contadorAbcedario = 26;
        }
        printf("\n");
        }

    void descifrar(char *textoCifrado){
        printf("El texto %s descifrado es: ", textoCifrado);
        int contadorAbcedario, contadorPalabra, indice = 0;
         for (contadorPalabra=0 ; contadorPalabra<textoCifrado[contadorPalabra] ;contadorPalabra++)
         for (contadorAbcedario=0 ; contadorAbcedario<TAM_ABC ; contadorAbcedario++)

            if (abecedarioCifrado[contadorAbcedario] == textoCifrado[contadorPalabra]){
            printf("%c", abecedarioEnClaro[contadorAbcedario]);
            contadorAbcedario = 26;
         }
         printf("\n");
    }


    /*Comentario adicional: En mi punto de vista completamente personal, el código es un poco complicado de leer
      debido a que el autor no utiliza llaves en diversos bucles; provocando un aspecto poco ordenado
      en el código.*/

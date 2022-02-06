/*
Tema 1.1.2: Arreglos

    ->Arreglos bidimensionales:

    Consiste en una matriz de variables de un mismo tipo de dato. Al igual que los arreglos comunes, las variables son
    contiguas en la memoria. A su vez, utilizan dos indices para denotar los renglones y las columnas.

    DECLARACIÓN:
     tipoDato nombreMatriz[renglón][columna]; //Nótese que inician en 0,0.

    Por ejemplo, si declarásemos un arreglo de la forma:

        int matriz[2][4]; //2 renglones y cuatro columnnas.

    Nuestra representación matricial sería:

       ---  ---  ---  ---
       0,0  0,1  0,2  0,3

       ---  ---  ---  ---
       1,0  1,1  1,2  1,3

    La declaración explícita también es aplicable a los arreglos bidimensionales:

        int matriz[2][4]={ {1,2,3,4},
                           {5,6,7,8}
                         };

    Lo anterior quedará representado como:

        1    2    3    4
       ---  ---  ---  ---
       0,0  0,1  0,2  0,3
                            //Los elementos de un renglón son contiguos en la memoria: 1
        5    6    7    8                                                               2
       ---  ---  ---  ---                                                              3...
       1,0  1,1  1,2  1,3


    NOTA: El mismo intervalo de restricción de [0, n-1] aplica de igual manera a los dos índices usados en un arreglo
          bidimensional.


*/

int main() {




  return 0;
    }

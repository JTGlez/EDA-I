#include  <stdio.h>

int main () {

    int ren, col, i, j, k=0;
    printf("Ingresar el tamaño de la escítala:\n");
    printf("\nRenglones:");
    scanf("%i",&ren);
    printf("\nColumnas:");
    scanf("%i",&col);
    char escitala[ren][col];
    char texto[ren*col];
    printf("Escriba el texto a descifrar:\n");
    scanf("%s", texto);
    for (i=0 ; i<col ; i++)
        for (j=0 ; j<ren ; j++)
            escitala[j][i] = texto[k++];
    printf("El texto descifrado es:\n");


    for (i=0 ; i<(col*i+j) ; i++)
            printf("%c", escitala[i]);

}

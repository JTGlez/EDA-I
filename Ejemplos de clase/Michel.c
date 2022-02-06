#include <stdio.h>

int main(){

int hora, minuto, segundo, totalS;

printf("\nIngrese las horas, minutos y segundos en formato 24hrs\n");

scanf("%d", &hora); scanf("%d", &minuto); scanf("%d", &segundo);

printf("\nConvirtiendo Hora: HH/MM/SS en segundos\n");

int horaS, minutoS;

horaS=hora*3600;
minutoS=minuto*60;

totalS=horaS+minutoS+segundo;

printf("\nSegundos convertidos: %d", totalS);




}

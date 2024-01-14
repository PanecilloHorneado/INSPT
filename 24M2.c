#include <stdio.h>
#include <stdlib.h>


//El formato sera 00:00:00 --> horas:minutos:segundos;
//si se sobrepasa min y seg de 99 hay error
int main(){
    int tiempo_N1 = 0;
    int tiempo_N2 = 0;
    int hora = 0;
    int min = 0;
    int seg = 0;
    int dia = 0;

    printf("Porfavor ingrese el tiempo numero 1 en el siguiente formato HH:MM:SS: "); // ej 01:01:01
    scanf("%d", &tiempo_N1);

    printf("Porfavor ingrese el tiempo numero 2 en el siguiente formato HH:MM:SS: "); // ej: 02/02/02
    scanf("%d", &tiempo_N2);

    seg = (tiempo_N1 % 100) + (tiempo_N2 % 100);
    min = ((tiempo_N2 % 10000) + (tiempo_N2 % 10000))/100;
    hora = ((tiempo_N2 / 10000) + (tiempo_N2 / 10000));

    printf("Hora: %d, min: %d, Seg: %d", hora, min, seg);


    return 0;
}

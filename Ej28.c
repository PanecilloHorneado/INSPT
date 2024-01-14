/*
28. Desarrolle una función que reciba una cadena por parámetro y devuelva la cantidad de vocales
que contiene. No puede usar funciones de cadenas en el desarrollo.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getCantidadDeVocales (char vec[]){

    int i,x=0;
    for (i=0;vec[i]!='\0';i++){
        switch(vec[i]){
            case 'A':
            case 'a':
                x++;
            break;

            case 'E':
            case 'e':
                x++;
            break;

            case 'I':
            case 'i':
                x++;
            break;

            case 'O':
            case 'o':
                x++;
            break;

            case 'U':
            case 'u':
                x++;
            break;
        }
    }
    return x;
}
int main2 (){
    char cadena[] = "hola mundO";
    printf("LA CADENA ' %s ' TIENE %i VOCALES\n",cadena,getCantidadDeVocales(cadena));
return 0;
}

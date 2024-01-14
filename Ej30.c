/*
30. Desarrolle una función que reciba una cadena por parámetro y un carácter, y que reemplace
todas las ocurrencias de ese carácter por X.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enroqueLetraPorX (char vec[],char c){

    int i;
    for(i=0;vec[i]!='\0';i++){
        if (vec[i]==c){
            vec[i]='x';
        }
    }
}

int main4 (){

    char letra = 'a' ,cadena[]="esto es una cadena";

    printf("REEMPLADO LA LETRA  '%c'  POR  'x'  EN LA SIGUIENTE FRASE: \n'%s'\n",letra,cadena);
    printf("RESULTADO\n");
    enroqueLetraPorX(cadena,letra);
    printf("'%s'",cadena);

return 0;
}

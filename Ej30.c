/*
30. Desarrolle una funci�n que reciba una cadena por par�metro y un car�cter, y que reemplace
todas las ocurrencias de ese car�cter por X.

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esSubCadena(char v1[], char v2[]){
    int i;

    for(i=0; v1[i]!='\0' && v2[i]!='\0'; i++){
        if(v1[i]==v2[i]){

        } else{
            return 0;
        }
    }
    return 1;
}

void main(){
    char v1[100];
    char v2[100];
    int condicion;

    printf("Porfavor ingrese la cadena numero 1: ");
    gets(v1);
    fflush(stdin);
    printf("Porfavor ingrese la cadena numero 2: ");
    gets(v2);

    condicion = esSubCadena(v1, v2);
    printf("%i", condicion);
}

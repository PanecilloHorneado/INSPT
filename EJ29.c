/*
29. Desarrolle una función que reciba una cadena por parámetro y devuelva la cantidad de
consonantes. No puede usar funciones de cadenas en el desarrollo

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getConsonantes(char vec[]){

    int i,x=0;
    for (i=0;vec[i]!='\0';i++){
        switch(vec[i]){
            case 'B':
            case 'b':
                x++;
            break;

            case 'C':
            case 'c':
                x++;
            break;

            case 'D':
            case 'd':
                x++;
            break;

            case 'F':
            case 'f':
                x++;
            break;

            case 'g':
            case 'G':
                x++;
            break;

            case 'H':
            case 'h':
                x++;
            break;

            case 'J':
            case 'j':
                x++;
            break;

            case 'K':
            case 'k':
                x++;
            break;

            case 'L':
            case 'l':
                x++;
            break;

            case 'M':
            case 'm':
                x++;
            break;

            case 'n':
            case 'N':
                x++;
            break;

            case 'p':
            case 'P':
                x++;
            break;

            case 'Q':
            case 'q':
                x++;
            break;

            case 'R':
            case 'r':
                x++;
            break;

            case 'S':
            case 's':
                x++;
            break;

            case 'T':
            case 't':
                x++;
            break;

            case 'V':
            case 'v':
                x++;
            break;


            case 'W':
            case 'w':
                x++;
            break;

            case 'X':
            case 'x':
                x++;
            break;

            case 'Y':
            case 'y':
                x++;
            break;

            case 'Z':
            case 'z':
                x++;
            break;
        }
    }
    return x;
}

int main3 (){

    char cadena[] = "esto es una cadena aleatoria";
    printf("LA CADENA ' %s ' TIENE %i CONSONANTES.\n",cadena,getConsonantes(cadena));

return 0;
}

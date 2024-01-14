#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
Realizar un programa que permita cargar un vector con 20 numero aleatorios. Una vez cargado el vector original, procesar este a manera de tener un vector
de numeros primos y un vector de numeros compuestos.
Mostrar el vector original y los otros dos vectores.
Ordenar el Vector original de mayor a menor.
**/

void cargarVectorAleatorio(int* vector, int longitud){
    int i;
    srand(time(NULL));

    for(i= 0;i<longitud;i++){
        vector[i] = rand()%200;
    }
}

int esPrimo(int valor){
    int i;
    int contador=0;

    for(i=2;i<valor;i++){
        if(valor%i==0){
            contador++;
        }
    }
    return contador;
    // 0 - es primo
    // =! 0 - es compuesto

}

void splitterVector(int* vPrimo, int* vComp, int* vector, int dimension){

    int pivote,i;
    int p=0,c=0;
    for(i=0;i<dimension;i++){
        if(esPrimo(vector[i])==0){
            vPrimo[p]=vector[i];
            p++;
        }else{

            vComp[c]=vector[i];
            c++;
        }
    }
}
    /**Burbujeo robado**/
void intercambiar(int* a, int* b){
    int temporal = *a;
    *a = *b;
    *b = temporal;
}

void burbuja(int arreglo[], int longitud) {
    for (int x = 0; x < longitud; x++) {
        for (int indiceActual = 0; indiceActual < longitud - 1;indiceActual++) {
            int indiceSiguienteElemento = indiceActual + 1;
            if (arreglo[indiceActual] < arreglo[indiceSiguienteElemento]) {
                intercambiar(&arreglo[indiceActual], &arreglo[indiceSiguienteElemento]);
      }
    }
  }
}
    /**/

void imprimir(int* vector,int longitud){
    int i;
    for(i= 0;i<longitud;i++){
        if(vector[i]!=0){
            printf("POSICION %d ES VALOR %d \n",i+1,vector[i]);
        }
    }
}
int main1(){
    int vector[20], vPrimo[20], vComp[20];
    int i;

    cargarVectorAleatorio(vector,20);
    printf("VECTOR CARGADO ALEATORIAMENTE: \n");
    imprimir(vector,20);
    printf("\n");

    for (i=0;i<20;i++){
        vPrimo[i]=0;
        vComp[i]=0;
    }

    splitterVector(vPrimo,vComp,vector,20);

    printf("VECTOR PRIMO: \n");
    imprimir(vPrimo,20);
    printf("\n");

    printf("VECTOR COMPUESTO: \n");
    imprimir(vComp,20);
    printf("\n");

    printf("VECTOR ORIGINAL ORDENADO: \n");
    burbuja(vector,20);
    imprimir(vector,20);

    return 0;
}

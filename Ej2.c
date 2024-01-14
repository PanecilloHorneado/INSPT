#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
Realizar la funcion mostrar
Ordenar el vector por nombre del rubro en forma alfabetica
Mostrar el vector ordenado
Mostrar el rubro con un aumento del 20% en el precio de mayor a menor
**/


typedef struct{
    int codrubro;
    char nomrubro[25];
    float precio;

}registro;

void mostrar(registro rubro[],int multiplicador){
    for(int i =0;i<5;i++){
        if(multiplicador>1){
            printf(" %d - %s ----> %.2f$ \n",rubro[i].codrubro,rubro[i].nomrubro,(rubro[i].precio*multiplicador/100)+(rubro[i].precio));
        }else{
            printf(" %d - %s ----> %.2f$ \n",rubro[i].codrubro,rubro[i].nomrubro,rubro[i].precio);
        }

    }
}

void burbujeoNomRubro(registro arreglo[], int longitud) {
    registro aux;
    for (int x = 0; x < longitud; x++) {
        for (int indiceActual = 0; indiceActual < longitud - 1;indiceActual++) {
            int indiceSiguienteElemento = indiceActual + 1;
            if (strcmp(arreglo[indiceActual].nomrubro,arreglo[indiceSiguienteElemento].nomrubro)>0) {
                aux=arreglo[indiceActual];
                arreglo[indiceActual]=arreglo[indiceSiguienteElemento];
                arreglo[indiceSiguienteElemento]=aux;
      }
    }
  }
}
void burbujeoPrecio(registro arreglo[],int longitud){
    registro aux;
    for (int x = 0; x < longitud; x++) {
        for (int indiceActual = 0; indiceActual < longitud - 1;indiceActual++) {
            int indiceSiguienteElemento = indiceActual + 1;
            if (arreglo[indiceActual].precio<arreglo[indiceSiguienteElemento].precio) {
                aux=arreglo[indiceActual];
                arreglo[indiceActual]=arreglo[indiceSiguienteElemento];
                arreglo[indiceSiguienteElemento]=aux;
      }
    }
  }

}

int main2(){
    registro rubro[5]={{1,"Automotores",15.25},{2,"Oficinas",12.46},{3,"Enseñanza",8.43},{4,"Servicios",10.54},{5,"Profesionales",14.80}};
    registro auxiliar[5];
    printf("STRUCTURA ORIGINAL: \n");
    mostrar(rubro,1);
    printf("\n");
    burbujeoNomRubro(rubro,5);
    printf("ORDENADO ALFABETICAMENTE POR RUBRO: \n");
    mostrar(rubro,1);
    printf("\n");
    burbujeoPrecio(rubro,5);
    printf("ORDENADO POR PRECIO Y AUMENTO 20% \n");
    mostrar(rubro,20);


    return 0;
}

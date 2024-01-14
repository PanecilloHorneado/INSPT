#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**Realice un programa que cargue 10 alumnos y ademas obtener:
        a). Una funcion que muestre solo los alumnos con promedio mayor a 7: nombre apellido promedio
        b). Una funcion que retorne cuantos alumnos tuvieron al menos 1 aplazo: (aplazos es 1,2,3) **/

typedef struct{
    char nombre[30];
    char apellido[30];
    int edad;
    float notas[5];
}alumno;


void mostrarAlumnosConPromedioMayorASiete(alumno misAlumnos[],int longuitud){

    float acumulador=0;

    for(int i =0;i<longuitud;i++){
        for(int j=0;j<5;j++){
            acumulador+=misAlumnos[i].notas[j];
        }
        if(acumulador/5>=7){
            printf("%s %s   %.2f \n",misAlumnos[i].nombre,misAlumnos[i].apellido,acumulador/5);
        }
        acumulador=0;
    }
}


int getCantidadDeAlumnosAplazados(alumno misAlumnos[],int longitud){

    /**0 SIN APLAZO
    1 CON APLAZO**/

    int flag=0;
    int cantidadDeAlumnosAplazados=0;

    for(int i = 0; i<longitud;i++){
        for(int j = 0;j<5;j++){
            if(flag==0 && misAlumnos[i].notas[j]<=3){
                flag = 1;
                cantidadDeAlumnosAplazados++;
            }
        }

        flag=0;
    }
    return cantidadDeAlumnosAplazados;

}



int main (){

    alumno arreglo[10] = { {"Jose","Perez",15,{10,7,8,5,9}},
                            {"Alberto","Rodriguez",16,{3,4,8,5,6}},
                            {"Juan","Lopez",17,{8,7,6,9,9}},
                            {"Martina","Fernandez",15,{6,7,9,8,9}},
                            {"Micaela","Lagorio",16,{1,5,4,2,1}},
                            {"Damian","Perez",18,{8,5,7,10,9}},
                            {"Mariana","Chalca",15,{6,10,8,9,9}},
                            {"Josefina","Guzman",16,{9,7,8,8,10}},
                            {"Rodolfo","Aguirre",15,{10,10,9,10,9}},
                            {"Martina","Chamorro",14,{6,9,8,6,7}}
                            };


    mostrarAlumnosConPromedioMayorASiete(arreglo,10);

    printf("CANTIDA DE ALUMNOS APLAZADOS %d \n",getCantidadDeAlumnosAplazados(arreglo,10));


return 0;
}

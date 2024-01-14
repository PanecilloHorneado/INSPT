#include <stdio.h>
#include <stdlib.h>

float funPromedioDeAsistenciaEstudiante(char genero, int asistencia, float totalDias, int *masculino, int *femenino){
    float PromedioAsistencia;

    switch(genero){
                case 'M':
                    (*masculino)+=1;
                    break;
                case 'F':
                    (*femenino)+=1;
                    break;
            }
    PromedioAsistencia = (asistencia/totalDias)*100;
    return PromedioAsistencia;
}

void procesarMaterias(int n, int *numeroAlumnos, int *claseMayor){
    int cantidadAlumnos, i, porcentaje=37; //variables de materia
    int j, diasAsistidos; //variables de estudiante
    float promAsistenciaEstudiante, contadorAsistencia, promAsistenciaFinal, cantidadDiasMateria;
    char genero;
    int contadorFemenino, contadorMasculino, promedioAsistencia;
    float promMayor = 0;

    for(i=1; i<=n; i++){
        contadorFemenino = 0;
        contadorMasculino = 0;
        contadorAsistencia = 0;
        printf("---------------------- Clase N%d ----------------------\n", i);
        printf("Porfavor ingrese el total de dias de la clase N%d: ", i);
        scanf("%f", &cantidadDiasMateria);
        printf("Porfavor ingrese la cantidad de alumnos de la clase N%d: ", i);
        scanf("%d", &cantidadAlumnos);

        (*numeroAlumnos) += cantidadAlumnos;

        for(j=1; j<=cantidadAlumnos;j++){
            printf("---------------------- Estudiante N%d ----------------------\n", j);
            fflush(stdin);
            printf("Genero estudiante N%d: ", j);
            scanf("%c", &genero);
            printf("Dias que asistio a clase: ");
            scanf("%d", &diasAsistidos);

            promAsistenciaEstudiante = funPromedioDeAsistenciaEstudiante(genero, diasAsistidos, cantidadDiasMateria, &contadorMasculino, &contadorFemenino);
            contadorAsistencia += promAsistenciaEstudiante;
        }
        printf("-------------------- Datos Clase N%d ----------------------\n", i);
        promAsistenciaFinal = (contadorAsistencia/cantidadAlumnos);
        printf("Promedio de asistencia de la materia N%d es: %2.f%c", i, promAsistenciaFinal, porcentaje);
        printf("\nGenero M: %d || Genero F: %d\n\n", contadorMasculino, contadorFemenino);

        if (promAsistenciaFinal>promMayor){
            promMayor = promAsistenciaFinal;
            (*claseMayor)=i;
        }
    }

}


void ma(){
    int numeroAlumnos = 0;
    int claseMayor;
    int cantidadMaterias = 2;
    procesarMaterias(cantidadMaterias, &numeroAlumnos, &claseMayor);

    printf("\n-------------------- Datos Finales --------------------\n");
    printf("Cantidad de alumnos: %d\n", numeroAlumnos);
    printf("La clase N: %d tiene la mayor asistencia", claseMayor);

}

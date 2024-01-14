#include <stdio.h>
#include <stdlib.h>

float fun_promedioAsistencia(char genero, float sumatoria, int diasDeClase, int *femenino, int *masculino){
    switch(genero){
        case 'M':
            (*masculino)+=1;
            break;
        case 'F':
            (*femenino)+=1;
            break;
    }
    return(sumatoria/diasDeClase)*100;
}

float def_procesarMaterias(int numMateria, int diasDeClase, int *totalAlumnos){
    int varControl=1, contadoMasculino=0, contadorFemenino=0;
    char genero;
    int opcion;
    int numEstudiantes=0;
    float asistenciaEstudiante, promAsistencia, promAsistenciaEstudiantes = 0;

    while(varControl!=0){
        printf("\n---------- Menu ----------");
        printf("\n1- Ingresar datos del estudiante");
        printf("\n0- Finalizar carga de estudiantes");

        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                (*totalAlumnos)+=1;
                numEstudiantes += 1;
                printf("\n----- Estudiante N%d -----", numEstudiantes);
                fflush(stdin);
                printf("\nGenero: ");
                scanf("%c",&genero);
                printf("Dias asistidos: ");
                scanf("%f", &asistenciaEstudiante);
                promAsistenciaEstudiantes = fun_promedioAsistencia(genero, asistenciaEstudiante, diasDeClase, &contadoMasculino, &contadorFemenino);
                promAsistencia += promAsistenciaEstudiantes;
                break;

            case 0:
                promAsistencia = promAsistencia/numEstudiantes;
                printf("\nPromedio: %2.f", promAsistencia);
                printf("\nGenero Femenino:%d || Masculino:%d\n\n", contadorFemenino, contadoMasculino);
                varControl=0;
                break;

            default:
                printf("ERROR: La opcion ingresada no es valida");
                break;
        }

    }
    return promAsistencia;
}

void main(){
    int totalAlumnos=0;
    float mayorAsistenciaPromedio = 0;
    float promAsistenciaMateria;
    int i, diasDeClase;
    int materiaMayorAsistencia;

    for(i=1; i<=1; i++){
        printf("---------- Materia N%d ----------", i);
        printf("\nIntroduzca el total de dias de clase: ");
        scanf("%d", &diasDeClase);
        promAsistenciaMateria=def_procesarMaterias(i, diasDeClase, &totalAlumnos);

        if(mayorAsistenciaPromedio<promAsistenciaMateria){
            mayorAsistenciaPromedio=promAsistenciaMateria;
            materiaMayorAsistencia = i;
        }
    }
    printf("\n---------- Datos Finales ----------");
    printf("\nTotal de alumnos procesados: %d", totalAlumnos);
    printf("\nLa materia con la mayor asistencia es la N: %d", materiaMayorAsistencia);

}

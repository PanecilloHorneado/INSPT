#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int presentes;
    int ausentes;
} Presentismo;

Presentismo inicializadorVector(int a, int m, int d, Presentismo vec[a][m][d]){
    int anho, mes, dia;
    for(anho=0; anho<4; anho++){
        for(mes=0; mes<12; mes++){
            for(dia=0; dia<31; dia++){
                vec[anho][mes][dia].ausentes = -1;
                vec[anho][mes][dia].presentes = -1;
            }
        }
    }
}

// Validacion de opciones del menu principal
int validaOpcion(){
    int opcion;
    while(1){
        printf("\nPorfavor ingrese una opcion:");
        scanf("%i", &opcion);
        fflush(stdin);
        if(opcion>=0 && opcion<=4){
            return opcion;
        } else{
            printf("Error: Opcion invalida");
        }
    }
}

int cargarPresentesAusentes(char* dato){
    int min = 0;
    int max = 200;
    int flag = 1;
    int cantidad;

    while(flag){
        printf("Porfavor ingrese los estudiantes %s: ", dato);
        scanf("%i", &cantidad);

        if(cantidad>=min && cantidad<=max){
            return cantidad;
        } else{
            printf("Error: El dato ingresado es invalido\n");
        }
    }
}

// Cantidad de dias en base al mes ingresado
int cantidadDeDias(int mes){
    int max;

    mes += 1;
    switch(mes){
        case 1:
            max = 31;
            break;
        case 2:
            max = 28;
            break;
        case 3:
            max = 31;
            break;
        case 4:
            max = 30;
            break;
        case 5:
            max = 31;
            break;
        case 6:
            max = 30;
            break;
        case 7:
            max = 31;
            break;
        case 8:
            max = 31;
            break;
        case 9:
            max = 30;
            break;
        case 10:
            max = 31;
            break;
        case 11:
            max = 30;
            break;
        case 12:
            max = 31;
            break;
        }
    return max;
}

// Carga datos para año, mes y dia ---> validados
int cargarDatos(int min, int max, char* dato, int mes){
    int datoIngreso;
    int flag = 1;
    if(mes == -1){
        while(flag){
        printf("Porfavor ingrese el %s: ", dato);
        scanf("%i", &datoIngreso);
        fflush(stdin);
        if(datoIngreso>0){
            if(datoIngreso>=min && datoIngreso<=max){
                return datoIngreso - 1;
            } else{
                printf("Error: El %s ingresado es invalido\n", dato);
                }
        } else{
            return -1;
        }
        }

    } else{  // Validacion de la carga de dias a partir del mes seleccionado
        max = cantidadDeDias(mes);
        }
        while(flag){
        printf("Porfavor ingrese el %s: ", dato);
        scanf("%i", &datoIngreso);
        fflush(stdin);
        if(datoIngreso==0){
            return -1;
        } else{
            if(datoIngreso>=min && datoIngreso<=max){
                return datoIngreso - 1;
            } else{
                printf("Error: El %s ingresado es invalido\n", dato);
            }
        }
        }
}

void cargarRegistros(int a, int m, int d, Presentismo listaPresentismo[a][m][d]){
    int ignite = 1;
    int ignite_2;
    int anho;
    int mes;
    int dia;
    int presentes;
    int ausentes;

    printf("\n### Para finalizar los registros en cualquier momento presione '0' ###\n");
    while(ignite){
        ignite_2 = 1;
        // Seleecion de fecha
        printf("\n--- Ingreso de datos ---\n");
        anho = cargarDatos(1, 4, "anho", 0);
        if(anho >= 0){
            mes = cargarDatos(1, 12, "mes", 0);
            if(mes >= 0){
                while(ignite_2){
                printf("\n--- Cargar dias ---\n");
                dia = cargarDatos(1, 0, "dia", mes);
                if(dia>=0){
                    // Carga de estudiantes presentes/ausentes en la fecha seleccionada
                    listaPresentismo[anho][mes][dia].presentes = cargarPresentesAusentes("Presentes");
                    listaPresentismo[anho][mes][dia].ausentes = cargarPresentesAusentes("Ausentes");
                } else{
                    ignite_2 = 0;
                }
                }
            } else{
                ignite = 0;
            }
        } else{
            ignite = 0;
        }
    }
}

// Busqueda del dia con mayor presentismo en un determinado año
void mayorPresentismo(int a, int m, int d, Presentismo listaPresentismo[a][m][d], int anho){
    int dia, mes;
    int diaMayorPresentismo;

    for(mes=0; mes<m; mes++){
        for(dia=1; dia<d; dia++){
            if(listaPresentismo[anho][mes][dia-1].presentes < listaPresentismo[anho][mes][dia].presentes){
                diaMayorPresentismo = dia;
            }
        }
    }
    printf("\nEl dia con mayor presentismo fue el dia: %i | mes: %i | anho: %i", diaMayorPresentismo+1, mes-1, anho+1);
}

// Busqueda del promedio de alumnos presentes en un determinado mes
void promAlumPresentes(int a, int m, int d, Presentismo listaPresentismo[a][m][d], int anho, int mes){
    int i;
    int dias;
    int diasTrabajados = 0;
    int signoPorcentaje = 37;
    float promedioDiario;
    float promedioAsistencia;
    dias = cantidadDeDias(mes);
    for(i=0; i<dias; i++){
        if(listaPresentismo[anho][mes][i].presentes!=-1 && listaPresentismo[anho][mes][i].ausentes!=-1){
            diasTrabajados += 1;
            promedioDiario += ((listaPresentismo[anho][mes][i].presentes*100)/(listaPresentismo[anho][mes][i].presentes + listaPresentismo[anho][mes][i].ausentes));
        }
    }
    if(diasTrabajados>0){
        promedioAsistencia = promedioDiario/diasTrabajados;
        printf("\nPromedio de alumnos que asistieron en el mes %i del anho %i: %.2f%c", mes+1, anho+1, promedioAsistencia, signoPorcentaje);
    } else{
        printf("\nNo hay ningun registro");
    }
}

void main(){
    int i;
    int anhoProm;
    int mesProm;
    int run = 1;
    int opcion;
    int anhos = 4;
    int anho;
    int meses = 12;
    int dias = 31;
    int promedioAlumnos;
    char iniciar;
    Presentismo listaPresentismo[anhos][meses][dias];
    inicializadorVector(anhos, meses, dias, listaPresentismo);


    printf("Desea iniciar la carga de los registros de presentismo (Y/N): ");
    scanf("%c", &iniciar);
    fflush(stdin);
    if(iniciar=='Y'||iniciar=='y'){
        while(run){
            printf("\n--- Menu ---");
            printf("\n1- Carga de datos");
            printf("\n2- Promedio de alumnos presentes en un mes");
            printf("\n3- Dia de mayor presentismo en un anho");
            printf("\n4- Extra");
            printf("\n0- Finalizar programa");
            opcion = validaOpcion();
            switch(opcion){
                case 1:
                    cargarRegistros(anhos, meses, dias, listaPresentismo);
                    break;
                case 2:
                    anhoProm = cargarDatos(1, 4, "anho", -1);
                    mesProm = cargarDatos(1, 12, "mes", -1);
                    promAlumPresentes(anhos, meses, dias, listaPresentismo, anhoProm, mesProm);
                    break;
                case 3:
                    anho = cargarDatos(1, 4, "anho", 0);
                    mayorPresentismo(anhos, meses, dias, listaPresentismo, anho);
                    break;
                case 4:
                    mesProm = 9;
                    for(i=1; i<=4; i++){
                        promAlumPresentes(anhos, meses, dias, listaPresentismo, i-1, mesProm-1);
                    }
                    for(i=1; i<=4; i++){
                        mayorPresentismo(anhos, meses, dias, listaPresentismo, i-1);
                    }

                    break;
                case 0:
                    printf("\nFin del programa");
                    run = 0;
                    break;
            }

        }
    } else{
        printf("\nFin del programa");
    }
}

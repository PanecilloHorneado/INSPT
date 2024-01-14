#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float temMax;
    float temMin;
    float sensacionTermica;
    int activo;
}   DatosMeteorologicos;

DatosMeteorologicos inicializarVector(int a, int m, int d, DatosMeteorologicos vec[a][m][d]){
    int anho, mes, dia;
    for(anho=0; anho<5; anho++){
        for(mes=0; mes<12; mes++){
            for(dia=0; dia<31; dia++){
                vec[anho][mes][dia].activo = 0;
            }
        }
    }
}

int cantidadDeDias(int mes){
    int dias;

    switch(mes){
        case 1:
            dias = 31;
            break;
        case 2:
            dias = 28;
            break;
        case 3:
            dias = 31;
            break;
        case 4:
            dias = 30;
            break;
        case 5:
            dias = 31;
            break;
        case 6:
            dias = 30;
            break;
        case 7:
            dias = 31;
            break;
        case 8:
            dias = 31;
            break;
        case 9:
            dias = 30;
            break;
        case 10:
            dias = 31;
            break;
        case 11:
            dias = 30;
            break;
        case 12:
            dias = 31;
            break;
        }
    return dias;
}

int validarDatos(int min, int max, char* opcion, int mes){
    int run = 1;
    int eleccion;
    while(run){
        printf("--> Porfavor ingrese el %s: ", opcion);
        scanf("%i", &eleccion);
        if(mes==0){
            if(eleccion>=min && eleccion<=max){
                return eleccion;
            } else{
                printf("## Error el dato ingresado es invalido ##\n");
            }
        } else{
            max = cantidadDeDias(mes);
            if(eleccion>=min && eleccion<=max){
                return eleccion;
            } else{
                printf("## Error el dato ingresado es invalido ##\n");
            }
        }
    }
}

void ingresoDeDatos(int a, int m, int d, DatosMeteorologicos vec[a][m][d]){
    int datoAnho;
    int datoMes;
    int datoDia;
    float temMax;
    float temMin;
    float sensacionTermica;
    int continuar;
    int run = 1;

    while(run){
        // La carga de datos es dato - 1 poque el vector inicia en la posicion 0   ---> mejorar la carga de datos (poco comoda)
        datoAnho = validarDatos(1, 5, "Anho", 0) - 1;
        datoMes = validarDatos(0, 12, "Mes", 0) - 1;
        datoDia = validarDatos(0, 0, "Dia", datoMes + 1) - 1;

        printf("\n--> Porfavor ingrese la temperatura Maxima: ");
        scanf("%f", &temMax);
        printf("--> Porfavor ingrese la temperatura Mimina: ");
        scanf("%f", &temMin);
        printf("--> Porfavor ingrese la Sensacion Termica: ");
        scanf("%f", &sensacionTermica);

        vec[datoAnho][datoMes][datoDia].temMax = temMax;
        vec[datoAnho][datoMes][datoDia].temMin = temMin;
        vec[datoAnho][datoMes][datoDia].sensacionTermica = sensacionTermica;
        vec[datoAnho][datoMes][datoDia].activo = 1;

        printf("--> Si desea continuar la carga datos presione 1 si no presione 0: ");
        scanf("%i", &continuar);
        printf("\n");
        fflush(stdin);
        if(continuar == 0){
            run = 0;
        }
    }
}

float diaDeMenorTemperatura(int a, int m, int d, DatosMeteorologicos vec[a][m][d], int anho){
    int i, j;
    int dia, mes;
    int dias = 31;
    int meses = 12;
    float diaMenorTemperatura;

    diaMenorTemperatura = 300;

    for(i=0; i<meses; i++){
        for(j=0; j<dias; j++){
            if(vec[anho][i][j].activo == 1){
                if(diaMenorTemperatura>vec[anho][i][j].temMin){
                    mes = i;
                    dia= j;
                    diaMenorTemperatura = vec[anho][i][j].temMin;
                }
            }
        }
    }

    if(diaMenorTemperatura == 300){
        printf("&&& No hay registros &&&");
    } else{
        printf("$$$ El dia %i del mes %i del anho %i tuvo la temperatura mas baja que fue de: %.2f", dia + 1, mes + 1, anho + 1, diaMenorTemperatura);
    }
}

void promedioSensacionTermica(int a, int m, int d, DatosMeteorologicos vec[a][m][d], int anho, int mes){
    float sumatoria = 0;
    float promedio;
    int totalDias = 0;
    int dias;
    int i;

    dias = cantidadDeDias(mes);
    for(i=0; i<dias; i++){
        if(vec[anho][mes][i].activo==1){
            totalDias += 1;
            sumatoria += vec[anho][mes][i].sensacionTermica;
        }
    }

    if(totalDias > 0){
        promedio = sumatoria/totalDias;
        printf("$$$ La sensacion termica promedio del anho %i y mes %i es de: %.2f", anho + 1, mes + 1, promedio);
    } else{
        printf("$$$ Datos insuficientes");
    }
}

void main(){
    int ignition = 1;
    int opcion;
    int anhos = 5;
    int meses = 12;
    int dias = 31;
    int datoAnho;
    int datoMes;
    int i;
    float diaDeMenorTemperaturaEnAnho;
    DatosMeteorologicos datosMeteorologicos[anhos][meses][dias];
    inicializarVector(anhos, meses, dias, datosMeteorologicos);

    while(ignition){
        printf("\n---> Menu <---\n");
        printf("1- Ingreso de datos\n");
        printf("2- Temperatura minima de un año\n");
        printf("3- Promedio de sensacion termica de un mes y un año dato\n");
        printf("4- Temperatura minima de todos los años y promedio de la sensacion termina del mes de Mayo\n");
        printf("5- Programa Total\n");
        printf("0- Fin del programa\n");

        printf("\nPorfavor ingrese una opcion: ");
        scanf("%i", &opcion);
        fflush(stdin);

        switch(opcion){
        case 1:
            ingresoDeDatos(anhos, meses, dias, datosMeteorologicos);
            break;
        case 2:
            printf("\n--- Temperatura minima de un año ---\n");
            datoAnho = validarDatos(1, 5, "Anho", 0) - 1;
            printf("\n");
            diaDeMenorTemperatura(anhos, meses, dias, datosMeteorologicos, datoAnho);
            printf("\n");
            break;
        case 3:
            printf("\n--- Promedio de sensacion termica de un mes y un año dato ---\n");
            datoAnho = validarDatos(1, 5, "Anho", 0) - 1;
            datoMes = validarDatos(1, 12, "Mes", 0) - 1;
            printf("\n");
            promedioSensacionTermica(anhos, meses, dias, datosMeteorologicos, datoAnho, datoMes);
            printf("\n");
            break;
        case 4:
            printf("\n--- Temperatura minima de todos los años y promedio de la sensacion termina del mes de Mayo ---\n");
            for(i=0; i<anhos; i++){
                printf("\n--- Informacion del anho %i ---", i);
                printf("\n");
                diaDeMenorTemperatura(anhos, meses, dias, datosMeteorologicos, i);
                printf("\n");
                promedioSensacionTermica(anhos, meses, dias, datosMeteorologicos, i, 4);
                printf("\n");
            }
            break;
        case 5:
            printf("\n--- Programa Total ---\n\n");
            ingresoDeDatos(anhos, meses, dias, datosMeteorologicos);

            // Ejecucion funcion 2
            printf("\n--- Temperatura minima de un año ---\n");
            datoAnho = validarDatos(1, 5, "Anho", 0) - 1;
            printf("\n");
            diaDeMenorTemperatura(anhos, meses, dias, datosMeteorologicos, datoAnho);
            printf("\n");

            // Ejecucion funcion 3
            printf("\n--- Promedio de sensacion termica de un mes y un año dato ---\n");
            datoAnho = validarDatos(1, 5, "Anho", 0) - 1;
            datoMes = validarDatos(1, 12, "Mes", 0) - 1;
            printf("\n");
            promedioSensacionTermica(anhos, meses, dias, datosMeteorologicos, datoAnho, datoMes);
            printf("\n");

            //Ejecucion funcion 4
            printf("\n--- Temperatura minima de todos los años y promedio de la sensacion termina del mes de Mayo ---\n");
            for(i=0; i<anhos; i++){
                printf("\n--- Informacion del anho %i ---", i);
                printf("\n");
                diaDeMenorTemperatura(anhos, meses, dias, datosMeteorologicos, i);
                printf("\n");
                promedioSensacionTermica(anhos, meses, dias, datosMeteorologicos, i, 4);
                printf("\n");
            }
            break;
        case 0:
            printf("\n--- Fin del programa ---");
            ignition = 0;
            break;
        default:
            printf("\nError: opcion invalida\n");
            break;
        }
    }
}

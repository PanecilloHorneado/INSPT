#include <stdio.h>
#include <stdlib.h>

/*
Una agencia de marketing necesita una aplicación para el proceso de sus clientes y publicidades. Para ello se reúne
con usted y define:
1- Construir una función que permita procesar una cantidad desconocida de ids de clientes que finaliza con el
número 0. Por cada cliente se ingresa su categoría (P-Platinum, G-Gold) y una cantidad desconocida de
publicidades. Cada publicidad tiene un importe y un rating. Por lo tanto, se debe ingresar:

    a. rating: B (bueno), R (regular), M (malo) -carácter -
    b. Importe: número decimal

Esta función debe emitir por cada cliente ingresado cuánto dinero se recaudó por cada rating, que se procesan
en la función 2. Ejemplo:
Total de publicidades del cliente 64: $10.000
Publicidades buenas: $2.000
Publicidades regulares: $3.000
Publicidades malas: $4.000

2- Construir una función que reciba al menos categoría e importe y devuelva (de alguna manera) a la función 1
todos los totales de las facturas procesadas por cada cliente.

3- En main el mensaje final que se emite debe mostrar:
a. Total de clientes procesados
b. Qué rating dejo más ganancias en total
c. Qué categoría de cliente fue la más lucrativa

*/


/*
    PAQUETE DE PRUEBA:
    IDCLIENTE: 00001,
        CATEGORIA: P,
        IMPORTE: 100 RATING B
        IMPORTE: 200 RATING R
        IMPORTE: 500 RATING M

        -1 SALIR CARGA IMPORTE

        IDCLIENTE: 00002
        CATEGORIA: G
        IMPORTE: 300 RATING B
        IMPORTE: 100 RATING M

      -1 SALIR CARGA IMPORTE

        IDCLIENTE: 00003
        CATEGORIA: P
        IMPORTE: 200 RATING B
        IMPORTE: 100 RATING R
        IMPORTE: 100 RATING M

        -1 SALIR CARGA IMPORTE

        0 SALIR DEL PROGRAMA.

*/



void procesarFacturas (char* rating, float* publicidadBuena, float* publicidadRegular, float* publicidadMala, float* importe){

    if (*rating == 'B'){
        *publicidadBuena = *publicidadBuena + *importe;
    }

    if (*rating == 'R'){
        *publicidadRegular = *publicidadRegular + *importe;
    }

    if (*rating == 'M'){
        *publicidadMala = *publicidadMala + *importe;
    }

}

void procesarCliente (int* contadorDeClientesProcesados, float* recaudacionRBueno, float* recaudacionRRegular, float* recaudacionRMalo,
                       float* categoriaPlatinum, float* categoriaGold){

    int idCliente;
    char categoria;
    float importe = 0, publicidadBuena = 0, publicidadRegular=0, publicidadMala=0;
    char rating;

    printf("INGRESE EL ID DEL CLIENTE. PRESS 0 TO EXIT \n");
    scanf("%d",&idCliente);

    do {
        printf("INGRESE LA CATEGORIA DEL CLIENTE. \n");
        fflush(stdin);
        scanf("%c",&categoria);
        while (categoria != 'P'&& categoria != 'G'){    // CONTROL CATEGORIA CORRECTA
            printf("INGRESE LA CATEGORIA DEL CLIENTE. \n");
            fflush(stdin);
            scanf("%c",&categoria);
        }

        printf("INGRESE EL IMPORTE. PRESS -1 TO EXIT \n");
        scanf("%f",&importe);
        do{
            printf("INGRESE EL RATING.\n");
            fflush(stdin);
            scanf("%c",&rating);
            while (rating != 'B' && rating != 'R' && rating != 'M'){
                printf("INGRESE EL RATING.\n");
                fflush(stdin);
                scanf("%c",&rating);
            }

            procesarFacturas(&rating,&publicidadBuena,&publicidadRegular,&publicidadMala,&importe);

            printf("INGRESE EL IMPORTE. PRESS -1 TO EXIT \n");
            scanf("%f",&importe);

        }while(importe>0);

        *contadorDeClientesProcesados = *contadorDeClientesProcesados + 1;
        printf("TOTAL DE PUBLICIDADES DEL CLIENTE %d : %2.f\n",idCliente,publicidadBuena+publicidadRegular+publicidadMala);
        printf ("PUBLICIDADES BUENAS %2.f \n",publicidadBuena);
        printf ("PUBLICIDADES REGULARES %2.f \n",publicidadRegular);
        printf ("PUBLICIDADES MALAS %2.f \n",publicidadMala);

        *recaudacionRBueno = *recaudacionRBueno + publicidadBuena;
        *recaudacionRRegular = *recaudacionRRegular + publicidadRegular;
        *recaudacionRMalo = *recaudacionRMalo + publicidadMala;


        if (categoria == 'P'){
            *categoriaPlatinum = *categoriaPlatinum + publicidadBuena + publicidadRegular + publicidadMala;
        }
        if(categoria == 'G'){
            *categoriaGold = *categoriaGold + publicidadBuena + publicidadRegular + publicidadMala;
        }
        publicidadBuena = 0;
        publicidadRegular= 0;
        publicidadMala =  0;

        printf("INGRESE EL ID DEL CLIENTE. PRESS 0 TO EXIT \n");
        scanf("%d",&idCliente);

    }while(idCliente!=0);

}

int main (){

    int contadorDeClientesProcesados = 0;
    float recaudacionRBueno= 0, recaudacionRRegular=0, recaudacionRMalo=0;
    float categoriaPlatinum = 0, categoriaGold=0;

    procesarCliente(&contadorDeClientesProcesados,&recaudacionRBueno,&recaudacionRRegular,&recaudacionRMalo,&categoriaPlatinum,&categoriaGold);

    printf("SE PROCESARON UN TOTAL DE %d CLIENTES\n",contadorDeClientesProcesados);

    if (recaudacionRBueno >= recaudacionRRegular && recaudacionRBueno >= recaudacionRMalo){
            printf("RATING BUENO CON MAYOR RECAUDACION %2.f \n",recaudacionRBueno);
    }
    if (recaudacionRRegular >= recaudacionRBueno && recaudacionRRegular>=recaudacionRMalo){
        printf ("RATING REGULAR CON MAYOR RECAUDACION %2.f \n",recaudacionRRegular);
    }
    if (recaudacionRMalo >= recaudacionRBueno && recaudacionRMalo >= recaudacionRRegular){
        printf("RATING MALO CON MAYOR RECAUDACION %2.f \n",recaudacionRMalo);
    }

    if (categoriaPlatinum >= categoriaGold){
        printf("CATEGORIA PLATINUM ES MAS LUCRATIVA CON %2.f \n",categoriaPlatinum);
    }else{
        printf("CATEGORIA GOLD ES MAS LUCRATIVA CON %2.f \n",categoriaGold);
    }

return 0;
}

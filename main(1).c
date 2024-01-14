#include <stdio.h>
#include <stdlib.h>
/*
float DevTotalesYPromAsist(char genero,int A,int a,float* TM,float* TF)
{
    float promedio;
    if(genero=='M')
    {
        (*TM)=(*TM)+A;
    }
    if(genero=='F')
    {
        (*TF)=(*TF)+A;
    }
    promedio=((*TM)+(*TF))*10/a;
    return promedio;
}
void ProcesaMaterias(int* TotalAlumnos,float* mejorpromedio,int*materia)
{
    int a,b,c,d,e,f,i,j,k,cant; char genero; int clase; float promedioA; float promedioB; float promedioC; float promedioD; float promedioE;
    int M=0;int F=0; float TMA=0; float TMB=0; float TMC=0; float TMD=0; float TME=0;
    float TFA=0; float TFB=0; float TFC=0; float TFD=0; float TFE=0;

    printf("\nIngrese totalidad de clases de materia 1: ");
    scanf("%d",&a);
    printf("\nIngrese totalidad de clases de materia 2: ");
    scanf("%d",&b);
    printf("\nIngrese totalidad de clases de materia 3: ");
    scanf("%d",&c);
    printf("\nIngrese totalidad de clases de materia 4: ");
    scanf("%d",&d);
    printf("\nIngrese totalidad de clases de materia 5: ");
    scanf("%d",&e);
    printf("\nIngrese cantidad de alumnos a ingresar: ");
    scanf("%d",&j); (*TotalAlumnos)=j;
    for(i=0;i<j;i++)
    {
        printf("\nIngrese genero (M o F) de alumno/a %d: ",i+1);
        fflush(stdin);
        scanf("%c",&genero);
        fflush(stdin);
        if(genero=='M')
            M++;
        if(genero=='F')
            F++;
        for(k=0;k<5;k++)
        {
            clase=k+1;
            switch(clase)
            {
            case 1:
                {
                    printf("\nIngrese asistencia a materia %d: ",clase);
                    scanf("%d",&cant);
                    promedioA=DevTotalesYPromAsist(genero,cant,j,&TMA,&TFA);
                    break;
                }
            case 2:
                {
                    printf("\nIngrese asistencia a materia %d: ",clase);
                    scanf("%d",&cant);
                    promedioB=DevTotalesYPromAsist(genero,cant,j,&TMB,&TFB);
                    break;
                }
            case 3:
                {
                    printf("\nIngrese asistencia a materia %d: ",clase);
                    scanf("%d",&cant);
                    promedioC=DevTotalesYPromAsist(genero,cant,j,&TMC,&TFC);
                    break;
                }
            case 4:
                {
                    printf("\nIngrese asistencia a materia %d: ",clase);
                    scanf("%d",&cant);
                    promedioD=DevTotalesYPromAsist(genero,cant,j,&TMD,&TFD);
                    break;
                }
            case 5:
                {
                    printf("\nIngrese asistencia a materia %d: ",clase);
                    scanf("%d",&cant);
                    promedioE=DevTotalesYPromAsist(genero,cant,j,&TME,&TFE);
                    break;
                }
            }
        }

    }
        printf("\nMateria #1:\nGenero M: %d   Genero F: %d\n Asistencia Promedio:  %1.2f",M,F,promedioA);
        printf("\nMateria #2:\nGenero M: %d   Genero F: %d\n Asistencia Promedio: %1.2f",M,F,promedioB);
        printf("\nMateria #3:\nGenero M: %d   Genero F: %d\n Asistencia Promedio: %1.2f",M,F,promedioC);
        printf("\nMateria #4:\nGenero M: %d   Genero F: %d\n Asistencia Promedio: %1.2f",M,F,promedioD);
        printf("\nMateria #5:\nGenero M: %d   Genero F: %d\n Asistencia Promedio: %1.2f",M,F,promedioE);
        (*mejorpromedio)=promedioA;
        (*materia)=1;
        if ((*mejorpromedio)<promedioB)
                {(*mejorpromedio)=promedioB;
                        (*materia)=2;
                }
        if((*mejorpromedio)<promedioC)
            {(*mejorpromedio)=promedioC;
                    (*materia)=3;
            }
        if((*mejorpromedio)<promedioD)
            {(*mejorpromedio)=promedioD;
                    (*materia)=4;
            }
        if((*mejorpromedio)<promedioE)
           {
               (*mejorpromedio)=promedioE;
               (*materia)=5;
           }

}
int main()
{
    int Total; float MayorAsistencia; int materia;
    ProcesaMaterias(&Total,&MayorAsistencia,&materia);
    printf("\nTotal de alumnos procesados: %d",Total);
    printf("\nMateria %d tiene mayor asistencia promedio: %1.2f",materia,MayorAsistencia);
    return 0;
}
*/
/*Una agencia de marketing necesita una aplicación para el proceso de sus clientesy publicidades.
Para ello se reúne con usted y define:
1-Construir una función que permita procesar una cantidad desconocidade ids de clientes
que finaliza con el número 0. Por cada clientese ingresasu categoría (P-Platinum, G-Gold)y una cantidad desconocida de
publicidades. Cada publicidad tiene unimporte y un rating. Por lo tanto, se debe ingresar:a.rating:
B (bueno), R (regular), M (malo) -carácter-b.Importe: número decimal
Esta función debe emitir por cada cliente ingresado
cuánto dinero se recaudó por cada rating,que se procesan en la función
2.Ejemplo:Total de publicidades del cliente 64:$10.000
Publicidades buenas: $2.000
Publicidades regulares: $3.000
Publicidades malas: $4.000
2-Construir una función que reciba al menos categoría e importe y devuelva (de alguna manera) a la función 1 todos
los totales de las facturas procesadas por cada cliente.
3-En main el mensaje final que se emite debe mostrar:
    a.Totalde clientes procesados
    b.Qué ratingdejo más gananciasen total
    c.Qué categoría de cliente fue la más lucrativa*/
float DevuelveTotal (char rating,float importe,float*facturaB,float*facturaR,float*facturaM,float*facturatotal)
{
    if(rating=='B')
    {
       (*facturaB)=(*facturaB)+importe;
    }
    if(rating=='R')
    {
        (*facturaR)=(*facturaR)+importe;
    }
    if(rating=='M')
    {
        (*facturaM)=(*facturaR)+importe;
    }
    (*facturatotal)=(*facturaB)+(*facturaR)+(*facturaM);

}
void EmiteValores (int*TotalClientes,float*RatGan,char*NomRat,float*CategLuc,char*NomCat)
{
    int i,j,k;char categ,rating; float importeB=15450.98; float importeR=10123.56; float importeM=6250.34; float facturatotal,facturaB,facturaM, facturaR;
    float Platinum=0; float Gold=0; float RatingB=0; float RatingR=0; float RatingM=0;
    (*TotalClientes)=0;
    printf("\nA continuacion ingresaremos los clientes.");
    printf("\nIngrese ID (0 para salir) de cliente: ");
    scanf("%d",&i);
    while(i!=0)
    {
        if(i<0)
           printf("\nCliente invalido. Intente con un ID mayor que cero...");
        if(i>0)
        {
            (*TotalClientes)=(*TotalClientes)+1;
            facturatotal=0; facturaB=0; facturaM=0; facturaR=0;
            printf("\nDigite inicial de categoria (P-Platinum, G-Gold): ");
            fflush(stdin);
            scanf("%c",&categ);
            fflush(stdin);
            if((categ!='P')&&(categ!='G'))
            {
                printf("\nDigito equivocado. Digite inicial de categoria (P-Platinum, G-Gold): ");
                fflush(stdin);
                scanf("%c",&categ);
                fflush(stdin);
            }
            switch (categ)
            {
                case 'P':
                {
                    printf("\nIngrese cantidad de publicidades que requiere el cliente (mayor que 0):");
                    scanf("%d",&k);
                    for(j=0;j<k;j++)
                    {
                        printf("\nIngrese caracter referente al rating de publicidad (B (bueno), R (regular), M (malo)): ");
                        fflush(stdin);
                        scanf("%c",&rating);
                        fflush(stdin);
                        if((rating!='B')&&(rating!='R')&(rating!='M'))
                            {
                                printf("\nRating equivocado. Ingrese caracter referente al rating de publicidad (B (bueno), R (regular), M (malo)): ");
                                fflush(stdin);
                                scanf("%c",&rating);
                                fflush(stdin);
                            }
                                switch(rating)
                                {
                                    case 'B':
                                        {
                                             printf("\nEl importe de este rating es de 15450.98 pesos");
                                             DevuelveTotal(rating,importeB,&facturaB,&facturaR,&facturaM,&facturatotal);
                                             break;
                                                                                          }
                                             case 'R':
                                                 {
                                                     printf("\nEl importe de este rating es de 10123.56 pesos");
                                                     DevuelveTotal(rating,importeR,&facturaB,&facturaR,&facturaM,&facturatotal);
                                                     break;

                                                     }
                                                     case 'M':
                                                         {
                                                             printf("\nEl importe de este rating es de 6250.34 pesos");
                                                             DevuelveTotal(rating,importeM,&facturaB,&facturaR,&facturaM,&facturatotal);
                                                             break;

                                                             }
                                }
                      }
                    RatingB=RatingB+facturaB;
                    RatingR=RatingR+facturaR;
                    RatingM=RatingM+facturaM;
                    printf("\nTotal de publicidades del cliente %d: $ %1.2f \nPublicidades buenas: $ %1.2f \nPublicidades regulares: $ %1.2f \nPublicidades malas: $ %1.2f",i,facturatotal,facturaB,facturaR,facturaM);
                    Platinum=Platinum+facturatotal;
                    break;
                }
                case 'G':
                {
                     printf("\nIngrese cantidad de publicidades que requiere el cliente (mayor que 0):");
                    scanf("%d",&k);
                    for(j=0;j<k;j++)
                    {
                        printf("\nIngrese caracter referente al rating de publicidad (B (bueno), R (regular), M (malo)): ");
                        fflush(stdin);
                        scanf("%c",&rating);
                        fflush(stdin);
                        if((rating!='B')&&(rating!='R')&(rating!='M'))
                            {
                                printf("\nRating equivocado. Ingrese caracter referente al rating de publicidad (B (bueno), R (regular), M (malo)): ");
                                fflush(stdin);
                                scanf("%c",&rating);
                                fflush(stdin);
                            }
                                switch(rating)
                                {
                                    case 'B':
                                        {
                                             printf("\nEl importe de este rating es de 15450.98 pesos");
                                             DevuelveTotal(rating,importeB,&facturaB,&facturaR,&facturaM,&facturatotal);
                                             break;
                                                                                          }
                                             case 'R':
                                                 {
                                                     printf("\nEl importe de este rating es de 10123.56 pesos");
                                                     DevuelveTotal(rating,importeR,&facturaB,&facturaR,&facturaM,&facturatotal);
                                                     break;

                                                     }
                                                     case 'M':
                                                         {
                                                             printf("\nEl importe de este rating es de 6250.34 pesos");
                                                             DevuelveTotal(rating,importeM,&facturaB,&facturaR,&facturaM,&facturatotal);
                                                             break;

                                                             }
                                }
                      }
                    RatingB=RatingB+facturaB;
                    RatingR=RatingR+facturaR;
                    RatingM=RatingM+facturaM;
                   printf("\nTotal de publicidades del cliente %d: $ %1.2f \nPublicidades buenas: $ %1.2f \nPublicidades regulares: $ %1.2f \nPublicidades malas: $ %1.2f",i,facturatotal,facturaB,facturaR,facturaM);
                   Gold=Gold+facturatotal;
                   break;
                }
                }
            }
            printf("\nIngrese ID (0 para salir) de cliente: ");
            scanf("%d",&i);
        }

        (*RatGan)=RatingB;
        (*NomRat)='B';
        if(RatingR>RatingB)
        {
        (*RatGan)=RatingR;
        (*NomRat)='R';
        if(RatingM>RatingR)
        {
        (*RatGan)=RatingM;
        (*NomRat)='M';
        }
        }
        else
        {
        if(RatingM>RatingB)
        {
        (*RatGan)=RatingM;
        (*NomRat)='M';
        }
        }
        (*CategLuc)=Platinum;
        (*NomCat)='P';
        if(Gold>Platinum)
        {
            (*CategLuc)=Gold;
            (*NomCat)='G';
        }
    }


int main()
{
    int TotalClientes; float RatingGan,CategLuc; char NomRat,NomCat;
    printf("Bienvenido/a al programa de clientes y publicidades");
    EmiteValores(&TotalClientes,&RatingGan,&NomRat,&CategLuc,&NomCat);
    printf("\nTotal de clientes procesados %d",TotalClientes);
    printf("\nEl rating %c fue el que mas ganancias tuvo con %1.2f pesos",NomRat,RatingGan);
    printf("\nLa categoria %c fue la mas lucrativa con %1.2f pesos",NomCat,CategLuc);
    printf("\nFin del programa.");
}

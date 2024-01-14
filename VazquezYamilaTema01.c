#define DIM 1000
#define DIM1 4

typedef struct
{
    int dia;
    int mes;
    int anio;
    int presentes;
    int ausentes;

}fecha;

int menu ()
{
    int opcion;
    printf("\n\n<<-----Programa Presentismo Profe musica Dewey Finn ---->>");
    printf("\n0) Salir del programa");
    printf("\n1) Ingreso de datos");
    printf("\n2) Visualizacion de datos de septiembre en pantalla");
    printf("\n Ingrese opcion deseada ");
    scanf("%d",&opcion);

    return opcion;
}

void IngresarDatos (fecha presentismo[1000], int* i)
{
    int a,m,d; int pres; int banda=1; int z;int curso=40;

    while(banda!=0)
    {
    printf("\nIngresar anioo> ");
    scanf("%d",&a);
    while(a<2019 || a>2022)
    {
    printf("\nIngreso un anio no valido recuerde que es del 2019 a 2022, por favor Reingrese anio: ");
    scanf("%d",&a);
    }
    printf("\nIngrese mes en formato numero > ");
    scanf("%d",&m);
    while(m<1|| m>12)
    {
    printf("\nIngreso un mes invalido por favor Reingrese mes en formato numero > ");
    scanf("%d",&m);
    }
    /*Meses que tienen 31 dias */
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
    {
        printf("\nIngrese dia> ");
        scanf("%d",&d);
        while(d<1 || d>31)
        {
        printf("\nIngrese dia> ");
        scanf("%d",&d);
        }
    }
    /*Meses que tienen 30 dias */
    if(m==4 || m==6 || m==9 || m==11)
    {
        printf("\nIngrese dia en formato numero> ");
        scanf("%d",&d);
        while(d<1 || d>30)
        {
        printf("\n Ingreso un dia invalido por favor reingrese dia en formato numero > ");
        scanf("%d",&d);
        }
    }

    /*Febrero especial y año bisciesto*/
    if(m==2)
    {
        if(a==2020)
        {
        printf("\nIngrese dia del dia hasta el 29: ");
        scanf("%d",&d);
        while(d<1|| d>29)
        {
        printf("\nIngrese dia del hasta el 29 dije: ");
        scanf("%d",&d);
        }
        }
        else
        {
        printf("\n Ingrese dia hasta el 28: ");
        scanf("%d",&d);
        while(d<1|| d>28)
        {
        printf("\nIngrese dia hasta el 28: ");
        scanf("%d",&d);
        }
        }
    }

    printf("\nLa fecha ingresada es %d / %d / %d",d,m,a);

    printf("\nIngrese cantidad de presentes en el dia que acaba de ingresar (cantidad maxima 40): ");
    scanf("%d",&pres);
    while(pres<0 || pres>curso)
    {
    printf("\nReIngrese cantidad de presentes en el dia que acaba de ingresar (cantidad maxima 40): ");
    scanf("%d",&pres);
    }

    (*i)=(*i)+1;
    z=(*i);
    presentismo[z].anio=a;
    presentismo[z].dia=d;
    presentismo[z].mes=m;
    presentismo[z].presentes=pres;
    presentismo[z].ausentes=curso-pres;

    printf("\nIngrese 0 para salir o 1 para continuar: ");
    scanf("%d",&banda);
    }

}

float ObtenerPromiedoMes (fecha presentismo[DIM], int i, int a, int m)
{
int y; int ingreso=0;int presente=0; float promedio=0;
for(y=1;y<i+1;y++)
{
    if(presentismo[y].anio==a)
    {
        if(presentismo[y].mes==m)
        {
            ingreso++;
            presente=presente+presentismo[y].presentes;
        }
    }
}
if(ingreso!=0)
promedio=presente/ingreso;
else
    {
        ingreso=1;
promedio=presente/ingreso;
}
return promedio;
}

void ObtenerDiaAnual (fecha presentismo[DIM], int i, int a, int* dia, int* mes, int* pres)
{
    int j; int mayor=0; int banda=0;
for(j=1;j<i+1;j++)
{
    if(presentismo[j].anio==a)
    {
      if(mayor<presentismo[j].presentes)
      {
          banda++;
          mayor=presentismo[j].presentes;
         (*dia)=presentismo[j].dia;
         (*mes)=presentismo[j].mes;
         (*pres)=presentismo[j].presentes;
      }
    }
    }
    if(banda==0)
    {
       (*dia)=0;
         (*mes)=0;
         (*pres)=0;
    }
}

void pantallaSeptiembre(fecha presentismo[DIM], int cant)
{
    int i,j; float anio,acum,ingr; int dia,mes,pres;
for(i=0;i<4;i++)
{
    switch(i)
    {
    case 0:
        {
             printf("\nEl promedio de sept del %d es de %.2f alumnos por clase.",2019+i,ObtenerPromiedoMes(presentismo,cant,2019,9));

            acum=0;
            ingr=0;
            for(j=1;j<13;j++)
            {

               acum=acum+ObtenerPromiedoMes(presentismo,cant,2019,j);
               if(ObtenerPromiedoMes(presentismo,cant,2019,j)!=0)
               ingr++;
            }
            if(ingr!=0)
            anio=acum/ingr;
            else
                anio=acum;
             printf("\nEl promedio anual del %d es de %.2f alumnos por clase.",2019+i,anio);

             ObtenerDiaAnual(presentismo,cant,2019,&dia,&mes,&pres);

             printf("\nEl dia %d / %d  del %d es el de mas presentismo con un total %d alumnos asistentes.",dia,mes,2019+i,pres);

        }
        break;
        case 1:
        {
             printf("\nEl promedio de sept del %d es de %.2f alumnos por clase.",2019+i,ObtenerPromiedoMes(presentismo,cant,2020,9));

            acum=0;
            ingr=0;
            for(j=1;j<13;j++)
            {

               acum=acum+ObtenerPromiedoMes(presentismo,cant,2020,j);
               if(ObtenerPromiedoMes(presentismo,cant,2020,j)!=0)
               ingr++;
            }
            if(ingr!=0)
            anio=acum/ingr;
            else
                anio=acum;
             printf("\nEl promedio anual del %d es de %.2f alumnos por clase.",2019+i,anio);

             ObtenerDiaAnual(presentismo,cant,2020,&dia,&mes,&pres);

             printf("\nEl dia %d / %d  del %d es el de mas presentismo con un total %d alumnos asistentes.",dia,mes,2019+i,pres);

        }
        break;
        case 2:
        {
             printf("\nEl promedio de sept del %d es de %.2f alumnos por clase.",2019+i,ObtenerPromiedoMes(presentismo,cant,2021,9));

            acum=0;
            ingr=0;
            for(j=1;j<13;j++)
            {

               acum=acum+ObtenerPromiedoMes(presentismo,cant,2021,j);
               if(ObtenerPromiedoMes(presentismo,cant,2021,j)!=0)
               ingr++;
            }
            if(ingr!=0)
            anio=acum/ingr;
            else
                anio=acum;
             printf("\nEl promedio anual del %d es de %.2f alumnos por clase.",2019+i,anio);

             ObtenerDiaAnual(presentismo,cant,2021,&dia,&mes,&pres);

             printf("\nEl dia %d / %d  del %d es el de mas presentismo con un total %d alumnos asistentes.",dia,mes,2019+i,pres);

        }
        break;
        case 3:
        {
             printf("\nEl promedio de sept del %d es de %.2f alumnos por clase.",2019+i,ObtenerPromiedoMes(presentismo,cant,2022,9));

           acum=0;
            ingr=0;
            for(j=1;j<13;j++)
            {

               acum=acum+ObtenerPromiedoMes(presentismo,cant,2022,j);
               if(ObtenerPromiedoMes(presentismo,cant,2022,j)!=0)
               ingr++;
            }
            if(ingr!=0)
            anio=acum/ingr;
            else
                anio=acum;
             printf("\nEl promedio anual del %d es de %.2f alumnos por clase.",2019+i,anio);

             ObtenerDiaAnual(presentismo,cant,2022,&dia,&mes,&pres);

             printf("\nEl dia %d / %d  del %d es el de mas presentismo con un total %d alumnos asistentes.",dia,mes,2019+i,pres);

        }
        break;

    }
}
}

int main ()
{
    int opcion; int i=0;
    fecha presentismo [DIM];

    opcion=menu();
    while(opcion!=0)
    {
        switch(opcion)
        {
        case 1:
            IngresarDatos(presentismo,&i);
            break;
        case 2:
            pantallaSeptiembre(presentismo,i);
            break;
        }

        opcion=menu();
    }
}


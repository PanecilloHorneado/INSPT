#include <stdio.h>
#include <stdlib.h>

void prodCategoria(char producto,float importe,float* acumCatO,float* acumCatS,float* acumCatU){
    switch(producto){
    case 'o':
    case 'O':
        (*acumCatO)+=importe;
        break;
    case 's':
    case 'S':
        (*acumCatS)+=importe;
        break;
    case 'u':
    case 'U':
        (*acumCatU)+=importe;
        break;
    }
}

char productoVendido(float acumCatOtotal,float acumCatStotal,float acumCatUtotal){
    if(acumCatOtotal>acumCatStotal && acumCatOtotal>acumCatUtotal)
        return 'O';
    else if(acumCatStotal>acumCatOtotal && acumCatStotal>acumCatUtotal)
        return 'S';
    else
        return 'U';
}

void procesarClientas(int* cantClientas,char* productoMasVendido, int*cantidadVentas){
    int dniCliente,i;
    char categoria, producto;
    float importe, acumCatO=0,acumCatS=0,acumCatU=0,acumCatOtotal=0,acumCatStotal=0,acumCatUtotal=0;

    printf("Ingrese su numero de DNI: , para finalizar ingrese -1 :)\n");
    scanf("%d",&dniCliente);
    printf("Ingresar la categoria C/E:\n");
            fflush(stdin);
            scanf("%c",&categoria);
    while(dniCliente!=-1){
        (*cantClientas)++;
        acumCatO=0;
        acumCatS=0;
        acumCatU=0;
        for(i=0;i<5;i++){
            printf("Ingresar producto O/S/U:\n");
            fflush(stdin);
            (*cantidadVentas)++;
            scanf("%c",&producto);
            printf("Ingrese el importe:\n");
            scanf("%f",&importe);
            prodCategoria(producto,importe,&acumCatO,&acumCatS,&acumCatU);
        }
        printf("Total clienta %d:\n",dniCliente);
        printf("Total ollas $%1.2f\n",acumCatO);
        printf("Total sartenes $%1.2f\n",acumCatS);
        printf("Total utensillos $%1.2f\n",acumCatU);

        acumCatOtotal+=acumCatO;
        acumCatStotal+=acumCatS;
        acumCatUtotal+=acumCatU;

        printf("Ingrese otro numero de DNI: para finalizar ingrese -1//\n :)");
        scanf("%d",&dniCliente);
    }
        (*productoMasVendido)=productoVendido(acumCatOtotal,acumCatStotal,acumCatUtotal);
}

int main(){
    int cantClientas=0, cantidadVentas=0;
    char productoMasVendido;

    procesarClientas(&cantClientas,&productoMasVendido,&cantidadVentas);

    printf("Cant clientas: %d\n",cantClientas);
    printf("Producto mas vendido: %c\n",productoMasVendido);
    printf("Ventas en total: %d\n",cantidadVentas);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    double DNI;
    char nombre[20];
    char apellido[20];
    char genero;
    int paresVendidos;
} Vendedor;

typedef struct{
    double idCalzado;
    char descripcion[20];
    int stock;
} Calzado;

Vendedor crearVendedor(double dni, int lenNomYApe, char nombre[lenNomYApe], char apellido[lenNomYApe], char genero, int paresV){
    Vendedor vendedor;
    vendedor.DNI = dni;
    printf("Estamos aca");
    strcpy(vendedor.nombre, nombre);
    printf("Estamos aca");
    strcpy(vendedor.apellido, apellido);
    vendedor.genero = genero;
    vendedor.paresVendidos = paresV;
    return vendedor;
}

void cargarVendedores(int n, Vendedor vec[n]){
    Vendedor vendedor;
    int i;
    double DNI;
    char nombre[20];
    char apellido[20];
    int lengNomApell = 20;
    char genero;
    int paresVendidos;
    for (i=0; i<n; i++){
        printf("--- Vendedor N%i ---\n", i+1);
        printf("DNI del vendedor: ");
        scanf("%d", &DNI);
        fflush(stdin);
        printf("Nombre del vendedor: ");
        gets(nombre);
        fflush(stdin);
        printf("Apellido del vendedor: ");
        gets(apellido);
        fflush(stdin);
        printf("Genero del vendedor (M/F): ");
        scanf("%c", &genero);
        fflush(stdin);
        printf("Pares vendidos por el vendedor: ");
        scanf("%i", &paresVendidos);
        fflush(stdin);
        vendedor = crearVendedor(DNI, lengNomApell, nombre, apellido, genero, paresVendidos);
        vec[i] = vendedor;
        vec[i] = vendedor;
    }
}

void cargarCalzados(int len, Calzado vec[len]){
    int i;
    double ID;
    char descipcion[20];
    int stock;
    Calzado calzado;
    for(i=0; i<len; i++){
        printf("\n\n--- Producto N%i ---\n", i+1);
        printf("ID del calzado: ");
        scanf("%d", &ID);
        fflush(stdin);
        printf("Descripcion del calzado: ");
        gets(descipcion);
        fflush(stdin);
        printf("Stock del calzado: ");
        scanf("%i", &stock);
        fflush(stdin);
        // Cargar calzado nuevo
        calzado.idCalzado = ID;
        strcpy(calzado.descripcion, descipcion);
        calzado.stock = stock;
        vec[i] = calzado;
    }
}

void main(){
    int cantidadVendedores = 1;
    int cantidadCalzados = 1;
    Vendedor listaVendedores[cantidadVendedores];
    Calzado listaCalzados[cantidadCalzados];

    cargarVendedores(cantidadVendedores, listaVendedores);
    cargarCalzados(cantidadCalzados, listaCalzados);

    printf("| %d | %s | %s | %c | %i |\n", listaVendedores[0].DNI, listaVendedores[0].nombre, listaVendedores[0].apellido, listaVendedores[0].genero, listaVendedores[0].paresVendidos);
    printf("| %d | %s | %i |", listaCalzados[0].idCalzado, listaCalzados[0].descripcion, listaCalzados[0].stock);
}

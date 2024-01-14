#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

///REALIZAR UN PROGRAMA QUE DADA LA CAPTURA DE LA CADENA, DETERMINAR LO SIGUIENTE:
///A) EL LARGO DE LA CADENA, REALIZANDO UNA FUNCION CUENTA CARACTERES
///B)LA CANTIDAD DE PALABRAS INGRESADAS, REALIZANDO UNA FUNCION CUENTA PAL
///C) LA CANTIDAD DE LETRAS Y NUMEROS QUE POSEE ESE TEXTO REALIZANDO UNA FUNCION LLAMADA CUENTA LETRAS
///D) CONVERTIR LA CADENA INGRESADA EN MAYUSCULA, MANTENIENDO LA ORIGINAL, REALIZANDO UNA FUNCION LLAMADA MAYU
///E) MOSTRAR LA CADENA INVERTIDA (RECURSIVIDAD)
///G)DADA UNA VOCAL DETERMINADA INDICAR LA TOTALIDAD DE APARICIONES EN EL TEXTO EN UNA FUNCION LLAMADA CANTIDADVOCAL

int CuentaCaracteres (char[]);
int CuentaPal (char[],int);
int CuentaLetras (char[],int);
void Mayu (char[],int);
void CadeInv (char[],int);
int CantidadVocal (char[],int,char,char);

int main()
{
    char frase[100];
    printf("Ingrese un texto: ");
    gets(frase);
    printf("\n%s",frase);
    printf("\n");
    printf("\nCantidad de caracteres:%d\n",CuentaCaracteres(frase));
    printf("\nCantidad de palabras:%d\n",CuentaPal(frase,CuentaCaracteres(frase)));
    printf("\nCantidad de letras y numeros:%d\n",CuentaLetras(frase,CuentaCaracteres(frase)));
    printf("\n");
    Mayu(frase,CuentaCaracteres(frase));
    printf("\n\n");
    CadeInv(frase,CuentaCaracteres(frase));
    printf("\n");
    printf("\nCantidad de repeticiones de vocal a: %d",CantidadVocal(frase,CuentaCaracteres(frase),'a','A'));
    printf("\nCantidad de repeticiones de vocal e: %d",CantidadVocal(frase,CuentaCaracteres(frase),'e','E'));
    printf("\nCantidad de repeticiones de vocal i: %d",CantidadVocal(frase,CuentaCaracteres(frase),'i','I'));
    printf("\nCantidad de repeticiones de vocal o: %d",CantidadVocal(frase,CuentaCaracteres(frase),'o','O'));
    printf("\nCantidad de repeticiones de vocal u: %d",CantidadVocal(frase,CuentaCaracteres(frase),'u','U'));

    return 0;
}

int CuentaCaracteres(char frase[])
{
    int final=0;
    while(frase[final]) ///MIENTRAS HAYA UN CARACTER ESCRITO VA A SER VERDADERO, LUEGO CORTA EL WHILE CUANDO NO HAY CARACTER
    {
        final++;
    }

return final;
    }

int CuentaPal(char frase[],int digitos)
{
    int final=0; int i;
    for(i=0;i<digitos;i++)
    {
        if(frase[i]==' ') ///CUANDO LE SIGUE UN ESPACIO A UNA PALABRA
            final++;
        if(frase[i]==' ' && frase[i]==' ') ///CUANDO LE SIGUEN DOS ESPACIOS A UNA PALABRA
            i++;
    }
if(final>1)
    final++;

return final;
    }

int CuentaLetras(char frase[],int digitos)
{
    int final=0; int i;
    for(i=0;i<digitos;i++)
    {
        if(frase[i]!=' ')///CUENTA LETRAS MIENTRAS NO SEAN ESPACIOS
            final++;

    }


return final;
    }

void Mayu (char frase[],int digitos)
{
    char textomayu [digitos]; int i;

    for(i=0;i<digitos;i++)
    {
        if(frase[i]!=' ')
            textomayu[i] = toupper(frase[i]); ///FUNCION QUE TRANSFORMA MINUSCULA EN MAYUSCULA
        else
            textomayu[i] = ' ';
    }

    for(i=0;i<digitos;i++)
    {
        printf("%c",textomayu[i]);
    }


}

void CadeInv (char frase[],int digitos)
{
    if(digitos<0)
    {

    }
    else
    {
        printf("%c",frase[digitos]);
        CadeInv(frase,digitos-1); ///FUNCION RECURSIVA (SE REPITE HASTA QUE LLEGA AL PRIMER CARACTER Y CORTA LUGO DE ESTE)
    }
}

int CantidadVocal (char frase[],int digitos,char minu,char mayu)
{
    int vocal=0;
    int i;

    for(i=0;i<digitos;i++)
    {
        if(frase[i]==minu || frase[i]==mayu) ///SI ENCUENTRA UNA VOCAL EN MAYU O EN MINU LAS CUENTA
        {
            vocal++;
        }
    }

    return vocal;
}

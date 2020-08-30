/*
 ============================================================================
 Name        : LemosPPPIG.c
 Author      : Lemos
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;

} sNotebook;

float aplicarDescuento (float precio);
int contarCaracteres (char cadena[], int len, char caracter);
void ordenarPorMarcayPrecio (sNotebook list[], int len);


int main(void)
{

    sNotebook lista[5] = { {1,"i5","intel",5000},{2,"a9","amd",8500},{3,"pwr","rayito",15.05},{4,"i7","intel",14890},{5,"a6","amd",4865.5} };
    char palabra[20] = "laboratorio";
    char letra = 'o';
    int repeticiones;
    float precio=100;

    printf("\nId   Procesador     Marca      Precio\n");
    for(int i=0; i<5; i++)
        printf("%d     %5s     %10s     %.2f\n", lista[i].id, lista[i].procesador, lista[i].marca, lista[i].precio);

    printf("\n----------------------------------------------\n");

    ordenarPorMarcayPrecio(lista, 5);

    printf("\nId   Procesador     Marca      Precio\n");
    for(int i=0; i<5; i++)
        printf("%d     %5s     %10s     %.2f\n", lista[i].id, lista[i].procesador, lista[i].marca, lista[i].precio);

    printf("\n*********************************************\n");

    repeticiones = contarCaracteres(palabra, 20, letra);

    printf("\nRepeticiones de %c en %s: %d\n", letra, palabra, repeticiones);

    printf("\n*********************************************\n");

    printf("\nPrecio del producto: %.2f\n", precio);
    printf("Precio final con 5 de descuento: %.2f\n", aplicarDescuento(precio));


    return 0;
}

/* 1. Crear una función llamada aplicarDescuento que reciba como parámetro el precio de un producto y
 * devuelva el valor del producto con un descuento del 5%. Realizar la llamada desde el main. *
 *
 * 2. Crear una función que se llame contarCaracteres que reciba una cadena de caracteres como primer
 * parámetro y un carácter como segundo y devuelva la cantidad de veces que ese carácter aparece en la cadena *
 *
 * 3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un
 * array de dicha estructura por marca. Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos
 * y mostrarlos desde el main. *
 *
 */

float aplicarDescuento (float precio)
{
    return precio*0.95;
}

int contarCaracteres (char cadena[], int len, char caracter)
{
    int acumulador=0;

    for(int i=0; cadena[i]!='\0'; i++)
    {
        if(cadena[i]==caracter)
            acumulador++;
    }

    return acumulador;
}

void ordenarPorMarcayPrecio (sNotebook list[], int len)
{
    sNotebook auxNotebook;

    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(strcmp(list[i].marca, list[j].marca)>0)
            {
                auxNotebook=list[i];
                list[i]=list[j];
                list[j]=auxNotebook;
            }
            else if(strcmp(list[i].marca, list[j].marca)==0 && list[i].precio>list[j].precio)
            {
                auxNotebook=list[i];
                list[i]=list[j];
                list[j]=auxNotebook;
            }
        }
    }
}

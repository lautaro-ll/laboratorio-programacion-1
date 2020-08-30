#include <stdio.h>
#include <stdlib.h>
#include "lemos.h"

int main()
{
    float A, B, suma, resta, division, multiplicacion;
    int factorialA, factorialB, entA, entB;
    int opcion, bOut=0, bA=0, bB=0;
    do
    {
        system("cls");
        if(bA==0)
            printf("1. Ingresar 1er operando (A=x) \n");
        else
            printf("1. Ingresar 1er operando (A=%.2f) \n", A);
        if(bB==0)
            printf("2. Ingresar 2do operando (B=y) \n");
        else
            printf("2. Ingresar 2do operando (B=%.2f) \n", B);
        printf("3. Calcular todas las operaciones \n");
        printf("4. Informar resultados \n");
        printf("5. Salir \n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("1. Ingrese 1er operando: ");
            scanf("%f", &A);
            bA=1;
            break;
        case 2:
            system("cls");
            printf("2. Ingrese 2do operando: ");
            scanf("%f", &B);
            bB=1;
            break;
        case 3:
            system("cls");
            if(bA==0 || bB==0)
            {
                printf("Debe ingresar los valores de A y B\n");
                system("pause");
                break;
            }
            suma = sumar(A,B);
            resta = restar(A,B);
            if (B!=0)
                division = dividir(A,B);
            multiplicacion = multiplicar(A,B);
            factorialA = factorial(A);
            factorialB = factorial(B);
            printf("Se realizaron todas las operaciones\n");
            system("pause");
            break;
        case 4:
            system("cls");
            if(bA==0 || bB==0)
            {
                printf("Debe ingresar los valores de A y B\n");
                system("pause");
                break;
            }
            printf("El resultado de A+B es: %.2f\n", suma);
            printf("El resultado de A-B es: %.2f\n", resta);
            if(B!=0)
                printf("El resultado de A/B es: %.2f\n", division);
            else
                printf("No es posible dividir por cero\n");
            printf("El resultado de A*B es: %.2f\n", multiplicacion);
            if(factorialA!=0)
            {
                printf("El factorial de A es: %d ", factorialA);
                entA = A;
                if(A-entA)
                    printf("(Se descartaron los decimales) ");
            }
            else
                printf("El factorial de A no se puede calcular por ser menor a 0 o mayor a 31 (excede el tamaño reservado) ");
            if(factorialB!=0)
            {
                printf("y el factorial de B es: %d ", factorialB);
                entB = B;
                if(B-entB)
                    printf("(Se descartaron los decimales)");
                printf("\n");
            }
            else
                printf("y el factorial de B no se puede calcular por ser menor a 0 o mayor a 31 (excede el tamanio reservado)\n");
            bA=0;
            bB=0;
            system("pause");
            break;
        case 5:
            bOut=1;
            break;
        default:
            printf("\nIngrese una opcion valida.\n");
        }
    }
    while(bOut==0);

    return 0;
}


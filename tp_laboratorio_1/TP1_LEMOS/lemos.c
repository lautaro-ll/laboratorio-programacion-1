#include <stdio.h>
#include <stdlib.h>
#include "lemos.h"

float sumar (float a, float b)
{
    return a+b;
}
float restar (float a, float b)
{
    return a-b;
}
float dividir (float a, float b)
{
    if(b!=0)
        return a/b;
    else
        return 0; //condicion de error por no poder dividir por 0
}
float multiplicar (float a, float b)
{
    return a*b;
}
int factorial (int a)
{
    int rta=1;
    if(a==0)
        return 1;
    if(a>0 && a<32)
    {
        for (int i=1; i<=a; i++)
            rta=rta*i;
        return rta;
    }
    else
        return 0; //condicion de error por ser menor a 0
}

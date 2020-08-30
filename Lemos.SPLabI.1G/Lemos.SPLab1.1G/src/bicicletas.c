/*
 * bicicletas.c
 *
 *  Created on: 29 Jun 2020
 *      Author: Lautaro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "utn_lemos.h"
#include "bicicletas.h"

/**
 * \brief Muestra un menu de opciones
 *
 * \param option opcion seleccionada
 * \return devuelve el numero entero valido ingresado
 */
int menu(int* option)
{
	int retorno=-1;
	int opcIngresada;
	if(utn_getNumeroInt(&opcIngresada,"\nMenu de opciones\n"
	    			 "1. Cargar archivo\n"
	    			 "2. Imprimir lista\n"
	    			 "3. Asignar tiempos\n"
	    			 "4. Filtrar por tipo\n"
	    			 "5. Mostrar posiciones\n"
	    			 "6. Guardar posiciones\n"
					 "7. Salir\n",
	    	     	 "Error, reingrese opcion (1 a 7)\n", 1, 7, 1)==0)
	{
		retorno=0;
		*option=opcIngresada;
	}
	return retorno;
}


eBicicleta* bike_find(LinkedList* pArrayList, int id)
{
    int tam = ll_len(pArrayList);
    eBicicleta* bicicleta;

    if(pArrayList!=NULL)
    {
        for(int i=0;i<tam;i++)
        {
        	bicicleta = (eBicicleta*)ll_get(pArrayList,i);
            if(bicicleta->id_bike == id)
                break;
            bicicleta=NULL;
        }
    }
    return bicicleta;
}

int mostrarBicicleta(eBicicleta* bicicleta)
{
    int retorno=-1;

    if(bicicleta!=NULL)
    {
        printf(" %d    %20s    %20s    %d\n", bicicleta->id_bike, bicicleta->nombre, bicicleta->tipo, bicicleta->tiempo);
        retorno=0;
    }
    return retorno;
}

eBicicleta* bike_new()
{
    eBicicleta* newBike;
    newBike = (eBicicleta*) malloc(sizeof(eBicicleta));

    if(newBike!=NULL)
    {
    		newBike->id_bike=0;
            strcpy(newBike->nombre, "");
            strcpy(newBike->tipo, "");
            newBike->tiempo=0;
    }

    return newBike;
}

eBicicleta* bike_newParametros(char* idStr,char* nombreStr,char* tipoStr, char* tiempoStr)
{
    int id;
    int tiempo;
    eBicicleta* newBike;
    newBike = bike_new();


    if(newBike!=NULL)
    {
        id = atoi(idStr);
        tiempo = atoi(tiempoStr);

        if(    bike_setId(newBike,id)
            || bike_setNombre(newBike, nombreStr)
            || bike_setTipo(newBike, tipoStr)
			|| bike_setTiempo(newBike, tiempo)
           )
        {
            free(newBike);
            newBike=NULL;
        }
    }
    return newBike;
}


int bike_delete(eBicicleta* bicicleta)
{
    int retorno=1;

    if(bicicleta!=NULL)
    {
        free(bicicleta);
        retorno=0;
    }

    return retorno;
}

int bike_setId(eBicicleta* this,int id)
{
    int retorno=1;

    if(this!=NULL && id>0 && id<1000)
    {
    	this->id_bike=id;
        retorno=0;
    }
    return retorno;
}
int bike_getId(eBicicleta* this,int* id)
{
    int retorno=1;

    if(this!=NULL && id!=NULL)
    {
        *id=this->id_bike;
        retorno=0;
    }
    return retorno;
}

int bike_setNombre(eBicicleta* this,char* nombre)
{
    int retorno=1;

    if(this!=NULL && strlen(nombre)>=3 && strlen(nombre)<=20)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}
int bike_getNombre(eBicicleta* this,char* nombre)
{
    int retorno=1;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int bike_setTipo(eBicicleta* this,char* tipo)
{
    int retorno=1;

    if(this!=NULL && strlen(tipo)>=1 && strlen(tipo)<=20)
    {
        strcpy(this->tipo,tipo);
        retorno=0;
    }
    return retorno;
}
int bike_getTipo(eBicicleta* this,char* tipo)
{
    int retorno=1;

    if(this!=NULL && tipo!=NULL)
    {
        strcpy(tipo,this->tipo);
        retorno=0;
    }
    return retorno;
}

int bike_setTiempo(eBicicleta* this,float tiempo)
{
    int retorno=1;

    if(this!=NULL && tiempo>=0 && tiempo<1000000)
    {
    	this->tiempo=tiempo;
        retorno=0;
    }
    return retorno;
}
int bike_getTiempo(eBicicleta* this,float* tiempo)
{
    int retorno=1;

    if(this!=NULL && tiempo!=NULL)
    {
        *tiempo=this->tiempo;
        retorno=0;
    }
    return retorno;
}

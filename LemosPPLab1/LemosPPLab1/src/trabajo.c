/*
 * trabajo.c
 *
 *  Created on: 15 may. 2020
 *      Author: Lemos
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_lemos.h"
#include "bicicleta.h"
#include "trabajo.h"

/**
 * \brief Muestra una lista de los Servicios
 *
 * \param servicio vector de tipo eServicio
 * \param tam tamaño de la lista
 */
void listarServicios (eServicio servicio[], int tam)
{
	printf("\n******* Lista de Servicios *******\n");
	printf("Id           Descripción    Precio\n\n");

	for(int i=0;i<tam;i++)
	{
		printf("%d          %10s         %.2f\n", servicio[i].id, servicio[i].descripcion, servicio[i].precio);
	}
}
/**
 * \brief Busca un indice libre de una lista eTrabajo
 *
 * \param vec vector a analizar
 * \param tam tamaño del vector
 * \return -1 si no hay espacio libre / numero de indice libre en caso contrario
 */
int buscarLibreT (eTrabajo vec[], int tam)
{
	int indice=-1;

	for(int i=0; i<tam; i++)
		if(vec[i].isEmpty)
		{
			indice=i;
			break;
		}
	return indice;
}
/**
 * \brief Busca un id de una lista eTrabajo
 *
 * \param idx id a buscar
 * \param vec vector a analizar
 * \param tam tamaño del vector
 * \return -1 si no hay espacio libre / numero de indice encontrado en caso contrario
 */
int buscarTrabajo (int idx, eTrabajo vec[], int tam)
{
	int indice=-1;

	for(int i=0;i<tam;i++)
		if(vec[i].id == idx && vec[i].isEmpty==0)
		{
			indice=i;
			break;
		}

	return indice;
}

void mostrarServicios (eServicio servicio[], int tam)
{
	printf("\n***** Listado de Servicios *****\n");
	printf("\n Id Descripcion Precio \n");

	for(int i=0;i<tam;i++)
	{
		printf(" %d    %10s    %5.2f\n", servicio[i].id, servicio[i].descripcion, servicio[i].precio);
	}
}
/**
 * \brief Inicializa un vector eTrabajo
 *
 * \param vec vector a inicializar
 * \param tam tamaño del vector
 */
void inicializarTrabajos(eTrabajo vec[], int tam)
{
	for(int i=0; i<tam; i++)
	{
		vec[i].isEmpty=1;
	}
}

int altaTrabajo (int id, eTrabajo trabajos[], int tam, eBicicleta bicicletas[], int tambic, eTipo tipo[], int tamtip, eColor color[], int tamcol, eServicio servicio[], int tamser)
{
	int retorno=0;
	int idBicicleta;
	int idServicio;
	eTrabajo auxTrabajo;
	int indice = buscarLibreT(trabajos,tam);
	if(indice==-1)
	{
		printf("Sistema Completo\n\n");

	}
	else
	{
		if(buscarTrabajo(id,trabajos,tam)==-1)
		{
				mostrarBicicletas(bicicletas,tambic,tipo,tamtip,color,tamcol);
				if(utn_getNumeroInt(&idBicicleta,"Ingrese id de bicicleta\n","ERROR (Rango->0,10000)\n",0,10000,2)==0 && buscarBicicleta(idBicicleta, bicicletas,tambic)!=-1)
				{
					mostrarServicios(servicio,tamser);
					if(utn_getNumeroInt(&idServicio,"Ingrese id servicio\n","ERROR (Rango->0,4)\n",0,4,2)==0)
					{
						if(
						utn_getNumeroInt(&auxTrabajo.fecha.dia,"Ingrese dia\n","ERROR (Rango->0,31)\n",0,31,2)==0 &&
						utn_getNumeroInt(&auxTrabajo.fecha.mes,"Ingrese mes\n","ERROR (Rango->0,12)\n",0,12,2)==0 &&
						utn_getNumeroInt(&auxTrabajo.fecha.anio,"Ingrese año\n","ERROR (Rango->1900,2020)\n",1900,2020,2)==0
						)
						{
									auxTrabajo.isEmpty=0;
									auxTrabajo.id=id;
									auxTrabajo.idServicio=idServicio;
									auxTrabajo.idBicicleta=idBicicleta;
									trabajos[indice]=auxTrabajo;
									retorno=1;
						}
					}
					else
						printf("No existe es id de comida\n");
				}
				else
					printf("No existe es id de Bicicleta\n");
		}
		else
		{
			printf("Ya existe un Trabajo registrado con ese id \n\n");
		}
	}
	return retorno;
}
/**
 * \brief Carga la marca de una Bicicleta indicada por un id
 *
 * \param marcaBicicleta variable donde se carga el dato
 * \param bicicletas vector de datos de eBicicleta
 * \param tam tamaño de la lista
 * \param idBicicleta id a buscar
 * \return 0- No se encontro el id / 1- Descripcion cargada
 */
int cargarBicicleta(char* marcaBicicleta,eBicicleta bicicletas[],int tam,int idBicicleta)
{
	int retorno=-1;
	int size;
	if(marcaBicicleta!=NULL)
	{
		retorno=0;
		for(int i=0;i<tam;i++)
		{
			if(bicicletas[i].id==idBicicleta)
			{
				size=sizeof(bicicletas[i].marca);
				strncpy(marcaBicicleta, bicicletas[i].marca, size);
				retorno=1;
			}
		}
	}
	return retorno;
}
/**
 * \brief Carga la descripcion de un Servicio indicado por un id
 *
 * \param descripcionServicio variable donde se carga el dato
 * \param servicios vector de datos de eServicio
 * \param tam tamaño de la lista
 * \param idServicio id a buscar
 * \return 0- No se encontro el id / 1- Descripcion cargada
 */
int cargarServicio(char* descripcionServicio,eServicio servicios[],int tam,int idServicio)
{
	int retorno=-1;
	int size;
	if(descripcionServicio!=NULL)
	{
		retorno=0;
		for(int i=0;i<tam;i++)
		{
			if(servicios[i].id==idServicio)
			{
				size=sizeof(servicios[i].descripcion);
				strncpy(descripcionServicio, servicios[i].descripcion, size);
				retorno=1;
			}
		}
	}
	return retorno;
}

void mostrarTrabajo(eTrabajo trabajo, eBicicleta bicicletas[], int tambic, eServicio servicios[], int tamser)
{
	char marcaBicicleta[20];
	char descripcionServicio[20];
	cargarBicicleta(marcaBicicleta, bicicletas, tambic, trabajo.idBicicleta);
	cargarServicio(descripcionServicio, servicios, tamser, trabajo.idServicio);

	printf(" %d          %d %10s  %10s     %d/%d/%d\n", trabajo.id, trabajo.idBicicleta, marcaBicicleta, descripcionServicio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
}

void mostrarTrabajos(eTrabajo trabajos[], int tamtra, eBicicleta bicicletas[], int tambic, eServicio servicios[], int tamser)
{
	int flag=0;
	printf("\n***** Listado de Trabajos *****\n");
	printf("\n IdTrabajo   IdBicicleta   Marca   Descripcion   Fecha \n");

	for(int i=0;i<tamtra;i++)
	{
		if(trabajos[i].isEmpty==0)
		{
			mostrarTrabajo(trabajos[i], bicicletas, tambic, servicios, tamser);
			flag=1;
		}
	}
	if(flag==0)
		printf("\nNo hay trabajos para mostrar\n");
}

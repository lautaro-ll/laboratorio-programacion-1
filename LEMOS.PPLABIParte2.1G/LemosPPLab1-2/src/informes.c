/*
 * informes.c
 *
 *  Created on: 22 may. 2020
 *      Author: Lau
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_lemos.h"
#include "bicicleta.h"
#include "trabajo.h"
#include "informes.h"


void informesTrabajos(eBicicleta lista[],int tam,eTrabajo trabajos[],int tamtra, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eServicio servicios[],int tamser)
{
	int opcion;
	do
	{
		if(utn_getNumeroInt(&opcion, "\n***** Menu de Informes *****\n\n"
				"1-	Mostrar bicicletas del color seleccionado por el usuario\n"
				"2-	Mostrar bicicletas de un tipo seleccionado\n"
				"3-	Informar la o las bicicletas de menor rodado\n"
				"4-	Mostrar un listado de las bicicletas separadas por tipo\n"
				"5-	Elegir un color y un tipo y contar cuantas bicicletas hay de ese color y ese tipo\n"
				"6-	Mostrar el o los colores más elegidos por los clientes\n"
				"7-	Pedir una bicicleta y mostrar todos los trabajos que se le hicieron a la misma\n"
				"8-	Pedir una bicicleta e informar la suma de los importes de los servicios que se le hicieron a la misma\n"
				"9-	Pedir un servicio y mostrar las bicicletas a las que se les realizo ese servicio y la fecha\n"
				"10-     Pedir una fecha y mostrar todos los servicios realizados en la misma\n"
				"11-     Salir\n",
				"\nReingrese Opcion ('1' a '11')\n",1,11,2)==0)
		{
			switch(opcion)
			{
				case 1:
					mostrarBicisPorColor(lista, tam, colores, tamcol, tipo, tamtip);
					break;
				case 2:
					mostrarBicisPorTipo(lista, tam, colores, tamcol, tipo, tamtip);
					break;
				case 3:
					informarBiciMenorRodado(lista, tam, colores, tamcol, tipo, tamtip);
					break;
				case 4:
					listarBicisPorTipo(lista, tam, colores, tamcol, tipo, tamtip);
					break;
				case 5:
					contarBicisPorColorYTipo(lista, tam, colores, tamcol, tipo, tamtip);
					break;
				case 6:
					mostrarColoresMasElegidos(lista, tam, colores, tamcol, tipo, tamtip);
					break;
				case 7:
					trabajosPorBici(lista, tam, colores, tamcol, tipo, tamtip, trabajos, tamtra, servicios, tamser);
					break;
				case 8:
					sumaDeImportesPorBici(lista, tam, colores, tamcol, tipo, tamtip, trabajos, tamtra, servicios, tamser);
					break;
				case 9:
					bicisPorServicio(lista, tam, colores, tamcol, tipo, tamtip, trabajos, tamtra, servicios, tamser);
					break;
				case 10:
					serviciosPorFecha(lista, tam, colores, tamcol, tipo, tamtip, trabajos, tamtra, servicios, tamser);
					break;
				case 11:
					break;
			}
		}

	}while(opcion!=11);
}

void mostrarBicisPorColor (eBicicleta vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip)
{
	int color;
	int vacio=0;
	listarColor(colores, tamcol);
	if(utn_getNumeroInt(&color,"Ingrese id del color \n","ERROR (Rango->1,5)",1,5,2)==0)
	{
		printf("\n******* Lista de Bicicletas *******\n");
		printf("Id          Marca     Tipo     Color      Rodado\n\n");

		for(int i=0;i<tam;i++)
		{
			if (vec[i].isEmpty==0 && vec[i].idColor==color)
			{
				mostrarBicicleta(vec[i],tipo, tamtip, colores, tamcol);
				vacio=1;
			}
		}
		if(!vacio)
			printf("\n******* No hay Bicicletas que listar *******\n\n");

	}
}

void mostrarBicisPorTipo (eBicicleta vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip)
{
	int tipoElegido;
	int vacio=0;
	listarTipos(tipo, tamtip);
	if(utn_getNumeroInt(&tipoElegido,"Ingrese id del tipo \n","ERROR (Rango->1,4)",1,4,2)==0)
	{
		printf("\n******* Lista de Bicicletas *******\n");
		printf("Id          Marca     Tipo     Color      Rodado\n\n");

		for(int i=0;i<tam;i++)
		{
			if (vec[i].isEmpty==0 && vec[i].idTipo==tipoElegido)
			{
				mostrarBicicleta(vec[i],tipo, tamtip, colores, tamcol);
				vacio=1;
			}
		}
		if(!vacio)
			printf("\n******* No hay Bicicletas que listar *******\n\n");

	}
}

void informarBiciMenorRodado  (eBicicleta vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip)
{
	int vacio=0;
	float menorRodado=9999;

	for(int e=0;e<tam;e++)
	{
		if (vec[e].isEmpty==0 && vec[e].rodado<menorRodado)
		{
			menorRodado=vec[e].rodado;
			vacio=1;
		}
	}
	if(!vacio)
		printf("\n******* No hay Bicicletas que listar *******\n\n");
	else
	{
		printf("******* Menor rodado *******\n");
		printf("Id          Marca     Tipo     Color      Rodado\n\n");
		for(int i=0;i<tam;i++)
		{
			if (vec[i].isEmpty==0 && menorRodado==vec[i].rodado)
			{
				mostrarBicicleta(vec[i],tipo, tamtip, colores, tamcol);
			}
		}
	}
}

void listarBicisPorTipo  (eBicicleta vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip)
{
	int vacio=0;
	char descripcionTipo[20];

	for(int e=1;e<=tamtip;e++)
	{
		cargarDescripcionTipo(descripcionTipo, e, tipo, tamtip);
		printf("\n******* Bicicletas de tipo %s *******\n", descripcionTipo);

		printf("Id          Marca     Tipo     Color      Rodado\n");

		for(int i=0;i<tam;i++)
		{
			if (vec[i].isEmpty==0 && vec[i].idTipo==e)
			{
				mostrarBicicleta(vec[i],tipo, tamtip, colores, tamcol);
				vacio=1;
			}
		}
		if(!vacio)
			printf("******* No hay Bicicletas que listar *******\n");
	}
}

void contarBicisPorColorYTipo (eBicicleta vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip)
{
	int vacio=0;
	int contador=0;
	int tipoElegido;
	int colorElegido;

	listarTipos(tipo, tamtip);
	if(utn_getNumeroInt(&tipoElegido,"Ingrese id del tipo \n","ERROR (Rango->1,4)",1,4,2)==0)
	{
		listarColor(colores,tamcol);
		if(utn_getNumeroInt(&colorElegido,"Ingrese id de color\n","ERROR (Rango->1,5)\n",1,5,2)==0)
		{
			for(int i=0;i<tam;i++)
			{
				if (vec[i].isEmpty==0 && vec[i].idColor==colorElegido && vec[i].idTipo==tipoElegido)
				{
					contador++;
					vacio=1;
				}
			}
			if(!vacio)
				printf("\n******* No hay Bicicletas que listar *******\n\n");
			else
				printf("\n******* Hay %d bicicleta/s de ese color y tipo *******\n\n", contador);

		}
	}
}

void mostrarColoresMasElegidos (eBicicleta vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip)
{
	int vacio=0;
	int contador[tamcol];
	int mayor=0;

	for(int e=0;e<tamcol;e++)
	{
		contador[e]=0;
	}
	for(int i=0;i<tam;i++)
	{
		if (vec[i].isEmpty==0)
		{
			contador[vec[i].idColor-1]++;
			if(contador[vec[i].idColor-1]>mayor)
				mayor=contador[vec[i].idColor-1];
			vacio=1;
		}
	}
	if(!vacio)
		printf("\n******* No hay Bicicletas que listar *******\n\n");
	else
	{
		printf("******* Colores mas elegidos *******\n");
		printf("Id          Marca     Tipo     Color      Rodado\n\n");
		for(int i=0;i<tam;i++)
		{
				if(vec[i].isEmpty==0 && mayor==contador[vec[i].idColor-1])
				{
					mostrarBicicleta(vec[i],tipo, tamtip, colores, tamcol);
					vacio=1;
				}
		}
	}
}


void trabajosPorBici (eBicicleta bicicletas[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eTrabajo trabajos[], int tamtra, eServicio servicios[],int tamser)
{
	int i;
	int id;
	char confirma='n';
	int flag=0;

	mostrarBicicletas(bicicletas,tam,tipo,tamtip,colores,tamcol);

	if(utn_getNumeroInt(&id,"Ingrese id\n","ERROR (Rango->0,10000)\n",0,10000,2)==0)
	{
		i = buscarBicicleta(id,bicicletas,tam);
		if(i==-1)
		{
			printf("No hay registro de un Bicicleta con el id: %d\n", id);
		}
		else
		{
			mostrarBicicleta(bicicletas[i],tipo,tamtip,colores,tamcol);

			if(utn_getCharacter(&confirma,"Confirma el Bicicleta seleccionado?\n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
			{
				printf("\n***** Listado de Trabajos *****\n");
				printf("\n IdTrabajo   IdBicicleta   Marca   Descripcion   Fecha \n");

				for(int i=0;i<tamtra;i++)
				{
					if(trabajos[i].isEmpty==0 && trabajos[i].idBicicleta==id)
					{
						mostrarTrabajo(trabajos[i], bicicletas, tam, servicios, tamser);
						flag=1;
					}
				}
				if(flag==0)
					printf("\nNo hay trabajos para mostrar\n");
			}
		}
	}

}


void sumaDeImportesPorBici (eBicicleta bicicletas[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eTrabajo trabajos[], int tamtra, eServicio servicios[],int tamser)
{
	int i;
	int id;
	char confirma='n';
	int suma=0;

	mostrarBicicletas(bicicletas,tam,tipo,tamtip,colores,tamcol);

	if(utn_getNumeroInt(&id,"Ingrese id\n","ERROR (Rango->0,10000)\n",0,10000,2)==0)
	{
		i = buscarBicicleta(id,bicicletas,tam);
		if(i==-1)
		{
			printf("No hay registro de un Bicicleta con el id: %d\n", id);
		}
		else
		{
			mostrarBicicleta(bicicletas[i],tipo,tamtip,colores,tamcol);

			if(utn_getCharacter(&confirma,"Confirma el Bicicleta seleccionado?\n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
			{

				for(int i=0;i<tamtra;i++)
					if(trabajos[i].isEmpty==0 && trabajos[i].idBicicleta==id)
						for(int e=0;e<tamser;e++)
							if(trabajos[i].idServicio==servicios[e].id)
								suma=suma+servicios[e].precio;
			}
			printf("La suma de importes de la misma es: %d\n", suma);

		}
	}

}

void bicisPorServicio (eBicicleta bicicletas[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eTrabajo trabajos[], int tamtra, eServicio servicios[],int tamser)
{
	int id;
	int vacio=0;

	listarServicios(servicios, tamser);
	if(utn_getNumeroInt(&id,"Ingrese id\n","ERROR (Rango->0,4)\n",0,4,2)==0)
	{
		printf("******* Bicicletas con ese servicio  *******\n");
		printf("Fecha        Id          Marca     Tipo     Color      Rodado\n");

		for(int e=0;e<tam;e++)
		{
					if (trabajos[e].idServicio==id && bicicletas[e].isEmpty==0)
					{
						printf("%d/%d/%d     ", trabajos[e].fecha.dia, trabajos[e].fecha.mes, trabajos[e].fecha.anio);
						mostrarBicicleta(bicicletas[e],tipo, tamtip, colores, tamcol);
						vacio=1;
					}
		}
		if(!vacio)
			printf("\n******* No hay Bicicletas que listar *******\n\n");
	}

}

void serviciosPorFecha (eBicicleta bicicletas[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eTrabajo trabajos[], int tamtra, eServicio servicios[],int tamser)
{
	eTrabajo auxTrabajo;
	int vacio=0;

	if( utn_getNumeroInt(&auxTrabajo.fecha.dia,"Ingrese dia\n","ERROR (Rango->0,31)\n",0,31,2)==0 &&
		utn_getNumeroInt(&auxTrabajo.fecha.mes,"Ingrese mes\n","ERROR (Rango->0,12)\n",0,12,2)==0 &&
		utn_getNumeroInt(&auxTrabajo.fecha.anio,"Ingrese año\n","ERROR (Rango->1900,2020)\n",1900,2020,2)==0)
		{
			printf("\n***** Listado de Servicios para esa fecha *****\n");
			printf("\n Id Descripcion Precio \n");
			for(int i=0;i<tamser;i++)
			{
				for(int e=0;e<tamtra;e++)
				{
					if(auxTrabajo.fecha.dia==trabajos[e].fecha.dia && auxTrabajo.fecha.mes==trabajos[e].fecha.mes && auxTrabajo.fecha.anio==trabajos[e].fecha.anio && trabajos[e].idServicio==servicios[i].id)
					{
						printf(" %d    %10s    %5.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
						vacio=1;
					}
				}
			}
		}
	if(!vacio)
		printf("\n******* No hay Bicicletas que listar *******\n\n");
}

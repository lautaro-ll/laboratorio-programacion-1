/*
 * bicicleta.c
 *
 *  Created on: 15 may. 2020
 *      Author: Lemos
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_lemos.h"
#include "datawarehouse.h"
#include "bicicleta.h"

/**
 * \brief Carga la descripcion de un Tipo indicada por un id
 *
 * \param descripcion variable donde se carga el dato
 * \param id id a buscar
 * \param tipo vector de datos de eTipo
 * \param tamtip tamaño de la lista
 * \return 0- No se encontro el id / 1- Descripcion cargada
 */
int cargarDescripcionTipo(char descripcion[], int id, eTipo tipo[], int tamtip)
{
	int retorno=0;
	int tamanio;
	for(int i=0;i<tamtip;i++)
	{
		if(tipo[i].id==id)
		{
			tamanio=sizeof(tipo[i].descripcion);
			strncpy(descripcion, tipo[i].descripcion, tamanio);
			retorno=1;
		}
	}
	return retorno;
}
/**
 * \brief Carga la descripcion de un Color indicada por un id
 *
 * \param descripcion variable donde se carga el dato
 * \param id id a buscar
 * \param color vector de datos de eColor
 * \param tamcol tamaño de la lista
 * \return 0- No se encontro el id / 1- Descripcion cargada
 */
int cargarDescripcionColor(char descripcion[], int id, eColor color[], int tamcol)
{
	int retorno=0;
	int tamanio;
	for(int i=0;i<tamcol;i++)
	{
		if(color[i].id==id)
		{
			tamanio=sizeof(color[i].descripcion);
			strncpy(descripcion, color[i].descripcion, tamanio);
			retorno=1;
		}
	}
	return retorno;
}


void mostrarBicicleta (eBicicleta bic, eTipo tipo[], int tamtip, eColor color[], int tamcol)
{
	char descripcionTipo[20];
	char descripcionColor[20];
	cargarDescripcionTipo(descripcionTipo, bic.idTipo, tipo, tamtip);
	cargarDescripcionColor(descripcionColor, bic.idColor, color, tamcol);

	printf("%d	%10s	%10s     %10s   %.2f     %10s\n", bic.id, bic.marca, descripcionTipo, descripcionColor, bic.rodado, descripcionColor);
}

void mostrarBicicletas (eBicicleta vec[], int tam, eTipo tipo[], int tamtip, eColor color[], int tamcol)
{
	int vacio=0;

	printf("\n******* Lista de Bicicletas *******\n");
	printf("Id          Marca     Tipo     Color      Rodado      Cliente\n\n");

	ordenarBicicletas(vec, tam);
	for(int i=0;i<tam;i++)
	{
		if (vec[i].isEmpty==0)
		{
			mostrarBicicleta(vec[i],tipo, tamtip, color, tamcol);
			vacio=1;
		}
	}
	if(!vacio)
		printf("\n******* No hay Bicicletas que listar *******\n\n");
}

void ordenarBicicletas(eBicicleta vec[], int tam)
{
	eBicicleta auxBicicleta;

	for(int i=0;i<tam-1;i++)
	{
		for(int j=i+1;j<tam;j++)
		{
			if(vec[i].idTipo > vec[j].idTipo)
			{
				auxBicicleta=vec[i];
				vec[i]=vec[j];
				vec[j]=auxBicicleta;
			}
			else if (vec[i].idTipo == vec[j].idTipo && vec[i].rodado > vec[j].rodado)
			{
				auxBicicleta=vec[i];
				vec[i]=vec[j];
				vec[j]=auxBicicleta;
			}
		}
	}

}
/**
 * \brief Inicializa un vector eBicicleta
 *
 * \param vec vector a inicializar
 * \param tam tamaño del vector
 */
void inicializarBicicletas(eBicicleta vec[], int tam)
{
	for(int i=0; i<tam; i++)
	{
		vec[i].isEmpty=1;
	}
}
/**
 * \brief Hardcodea variables de eBicicleta
 *
 * \param vec vector a cargar
 * \param cant cant de datos a cargar
 */
void hardCodearBicicletas(eBicicleta vec[], int cant)
{
	for(int i=0;i<cant;i++)
	{
		vec[i].id=hId[i];
		strncpy(vec[i].marca,hMarca[i],sizeof(vec[i]));
		vec[i].idTipo=hIdTipo[i];
		vec[i].idColor=hIdColor[i];
		vec[i].rodado=hRodado[i];
	}
}
/**
 * \brief Busca un indice libre de una lista eBicicleta
 *
 * \param vec vector a analizar
 * \param tam tamaño del vector
 * \return
 */
int buscarLibre (eBicicleta vec[], int tam)
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
 * \brief Busca un indice libre de una lista eBicicleta
 *
 * \param idx id a buscar
 * \param vec vector a analizar
 * \param tam tamaño del vector
 * \return
 */
int buscarBicicleta (int idx, eBicicleta vec[], int tam)
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
/**
 * \brief Muestra una lista de los Tipos
 *
 * \param tipo vector eTipo con los datos
 * \param tam tamaño de la lista
 */
void listarTipos (eTipo tipo[], int tam)
{
	printf("\n******* Lista de Tipos *******\n");
	printf("Id     Descripción \n\n");

	for(int i=0;i<tam;i++)
	{
		printf("%d          %10s\n", tipo[i].id, tipo[i].descripcion);
	}
}
/**
 * \brief Muestra una lista de los Colores
 *
 * \param color vector eColor con los datos
 * \param tam tamaño de la lista
 */
void listarColor (eColor color[], int tam)
{
	printf("\n******* Lista de Colores *******\n");
	printf("Id     Descripción \n\n");

	for(int i=0;i<tam;i++)
	{
		printf("%d          %10s\n", color[i].id, color[i].descripcion);
	}
}

int altaBicicleta (int idx, eBicicleta vec[], int tam, eTipo tipo[], int tamtip, eColor color[],int tamcol)
{
	int retorno=0;
	eBicicleta auxBicicleta;
	int indice = buscarLibre(vec,tam);
	if(indice==-1)
	{
		printf("Sistema Completo\n\n");

	}
	else
	{
		if(buscarBicicleta(idx,vec,tam)==-1)
		{
				if(utn_getString(auxBicicleta.marca,"Ingrese marca\n","ERROR (Rango->0,20)\n",0,20,2)==0 &&
				utn_getNumeroFloat(&auxBicicleta.rodado,"Ingrese rodado (Opciones: 20, 26, 27.5 y 29)\n","ERROR (Opciones: 20, 26, 27.5 y 29)\n",20,29,0)==0 &&
				(auxBicicleta.rodado==20 || auxBicicleta.rodado==26 || auxBicicleta.rodado==27.5 || auxBicicleta.rodado==29))
				{
					listarTipos(tipo,tamtip);
					if(utn_getNumeroInt(&auxBicicleta.idTipo,"Ingrese id de tipo\n","ERROR (Rango->1,4)\n",1,4,2)==0)
					{
						listarColor(color,tamcol);
						if(utn_getNumeroInt(&auxBicicleta.idColor,"Ingrese id de color\n","ERROR (Rango->1,5)\n",1,5,2)==0)
						{
							auxBicicleta.isEmpty=0;
							auxBicicleta.id=idx;
							vec[indice]=auxBicicleta;
							retorno=1;
						}
						else
							printf("No se ingresó el Bicicleta por errores en el ingreso de datos\n");
					}
					else
						printf("No se ingresó el Bicicleta por errores en el ingreso de datos\n");
				}
				else
					printf("No se ingresó el Bicicleta por errores en el ingreso de datos\n");
		}
		else
		{
			printf("Ya existe un Bicicleta registrado con ese id \n\n");
		}
	}
	return retorno;
}

void modificarBicicleta (eBicicleta vec[], int tam, eTipo tipo[], int tamtip, eColor color[],int tamcol)
{
	int id;
	int i;
	int opcion;
	char confirma;
	eBicicleta auxBicicleta;

	printf("\n******* Modificar Bicicleta *******\n");
	if(utn_getNumeroInt(&id,"Ingrese id\n","ERROR (Rango->0,10000)\n",0,10000,2)==0)
	{
		i = buscarBicicleta(id,vec,tam);
		if(i==-1)
		{
			printf("No hay registro de un Bicicleta con el id: %d\n", id);
		}
		else
		{
			mostrarBicicleta(vec[i],tipo,tamtip,color,tamcol);

			if(utn_getCharacter(&confirma,"Confirma el Bicicleta seleccionado?\n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
			{
				do
				{
					if(utn_getNumeroInt(&opcion,"\n Ingrese variable a modificar: 1-Tipo 2-Rodado 3-Salir\n", "ERROR (Rango 1->3)",1,3,2)==0)
					{
						switch(opcion)
						{
							case 1:
								listarTipos(tipo,tamtip);
								if(utn_getNumeroInt(&auxBicicleta.idTipo,"Ingrese id de tipo\n","ERROR (Rango->1,4)\n",1,4,2)==0)
								{
									vec[i].idTipo=auxBicicleta.idTipo;
									printf("Se realizó la modificación con éxito\n");
								}
								else
									printf("\nNo se modificaron datos\n");
								break;
							case 2:
								if(utn_getNumeroFloat(&auxBicicleta.rodado,"Ingrese rodado (Opciones: 20, 26, 27.5 y 29)\n","ERROR (Opciones: 20, 26, 27.5 y 29)\n",20,29,0)==0 &&
										(auxBicicleta.rodado==20 || auxBicicleta.rodado==26 || auxBicicleta.rodado==27.5 || auxBicicleta.rodado==29))
								{
									vec[i].rodado=auxBicicleta.rodado;
									printf("Se realizó la modificación con éxito\n");
								}
								else
									printf("\nNo se modificaron datos\n");
								break;
							case 3:
								break;
						}
					}
				}while(opcion!=3);
			}
			else
			{
				printf("Se canceló la operación\n");
			}
		}
	}
}

void bajaBicicleta (eBicicleta vec[], int tam,  eTipo tipo[], int tamtip, eColor color[],int tamcol)
{
	int id;
	int indice;
	char confirma;

	printf("\n******* Baja de Bicicleta *******\n");
	if(utn_getNumeroInt(&id,"Ingrese id\n","ERROR (Rango->0,10000)\n",0,10000,2)==0)
	{
		indice = buscarBicicleta(id,vec,tam);
		if(indice==-1)
		{
			printf("No hay registro de un Bicicleta con el id: %d\n", id);
		}
		else
		{
			mostrarBicicleta(vec[indice],tipo,tamtip,color,tamcol);

			if(utn_getCharacter(&confirma,"Confirma la baja?\n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
			{
				vec[indice].isEmpty=1;
				printf("Se realizó la baja con éxito\n");
			}
			else
			{
				printf("Se canceló la operación\n");
			}
		}
	}

}

/**
 * \brief Indica si la lista está vacía
 *
 * \param list Employee*
 * \param len int
 * \return -1 Error - 0 Vacia - 1 No vacía
 */
int checkEmpty(eBicicleta* list, int len)
{
	int retorno=-1;
	retorno=0;
	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty==0)
		{
			retorno=1;
			break;
		}
	}

	return retorno;
}

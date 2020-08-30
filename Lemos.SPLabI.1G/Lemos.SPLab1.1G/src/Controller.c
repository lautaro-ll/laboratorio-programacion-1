#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "bicicletas.h"
#include "parser.h"
#include "utn_lemos.h"

int controller_List(LinkedList* pArrayList)
{
	int retorno=-1;
	int tam=ll_len(pArrayList);
	eBicicleta* auxBike;
	if(pArrayList!=NULL)
	{
		if(ll_isEmpty(pArrayList)==0)
		{
			printf("ID             NOMBRE    		  TIPO         TIEMPO\n");
			for(int i=0;i<tam;i++)
			{
				auxBike = (eBicicleta*) ll_get(pArrayList,i);

				if( auxBike != NULL)
				{
					mostrarBicicleta (auxBike);
					retorno=1;
				}
			}
		}
		else
		{
			printf("No hay bicicletas que mostrar\n\n");
			retorno=0;
		}
	}
	return retorno;
}

int controller_load(char* path , LinkedList* pArrayList)
{
	int retorno=1;
	FILE* pFile;

	ll_clear(pArrayList);
	pFile = fopen(path, "r");

	if(path!=NULL && pArrayList!=NULL && pFile!=NULL)
	{
		if(!parser_FromText(pFile,pArrayList))
				retorno=0;
	}

	fclose(pFile);
    return retorno;
}

int controller_save(char* path , LinkedList* pArrayList)
{
	int retorno=1;
	int tam=ll_len(pArrayList);
	FILE* pFile;
	eBicicleta* aux;

	if(pArrayList!=NULL)
	{
		pFile = fopen(path,"w");

		if(pFile!=NULL)
		{
			fprintf(pFile,"id,nombre,tipo,tiempo\n");
			for(int i=0;i<tam;i++)
			{
				aux = (eBicicleta*) ll_get(pArrayList,i);
				fprintf(pFile,"%d,%s,%s,%d\n",aux->id_bike,aux->nombre,aux->tipo,aux->tiempo);
			}
		retorno=0;
		}
		fclose(pFile);
	}
	return retorno;
}


int lastId(LinkedList* pArrayList)
{
    int retorno=-1;
    int mayor=0;
    int flag=0;
    eBicicleta* aux;
    int tam=ll_len(pArrayList);

    if(pArrayList!=NULL)
    {
        for(int i=0;i<tam;i++)
        {
        	aux = (eBicicleta*) ll_get(pArrayList,i);
            if(aux!=NULL)
            {
                if(aux->id_bike > mayor || flag==0)
                {
                    mayor = aux->id_bike;
                    flag = 1;
                }
            }
        }
        retorno = mayor;
    }
    return retorno;
}


int compareTipo (void* datoA , void* datoB)
{
   int retorno=0;

   if(strcmp(((eBicicleta*) datoA)->tipo,((eBicicleta*) datoB)->tipo) > 0)
	   retorno=1;
   if(strcmp(((eBicicleta*) datoA)->tipo,((eBicicleta*) datoB)->tipo) < 0)
	   retorno=-1;

   return retorno;
}
int compareTiempo (void* datoA , void* datoB)
{
   int retorno=0;

   if(((eBicicleta*) datoA)->tiempo > ((eBicicleta*) datoB)->tiempo)
	   retorno=1;
   if(((eBicicleta*) datoA)->tiempo < ((eBicicleta*) datoB)->tiempo)
	   retorno=-1;

   return retorno;
}

int controller_sort(LinkedList* pArrayList)
{
    int retorno=1;
    LinkedList* auxLinkedList;
    auxLinkedList = ll_newLinkedList();

    if(pArrayList!=NULL && auxLinkedList!=NULL)
    {
    	auxLinkedList=ll_clone(pArrayList);
		printf("Ordenando. Aguarde un momento...\n");

		if(!ll_sort(auxLinkedList,compareTiempo,1))
		{
			if(!ll_sort(auxLinkedList,compareTipo,1))
			{
				controller_List(auxLinkedList);
				retorno=0;
			}
			else
				printf("Error. Operacion cancelada\n");
		}
    }
    return retorno;
}

int getRandom ()
{
	int aleatorio;
	aleatorio = rand()% 21 + 50; //aleatorio entre 50 y 70

	return aleatorio;
}

void* add_randomTime (void* bicicleta)
{
	((eBicicleta*) bicicleta)->tiempo = getRandom();
	return bicicleta;
}

int controller_asignTime (LinkedList* pArrayList)
{
	int retorno=1;

	if(pArrayList!=NULL)
	{
		pArrayList=ll_map(pArrayList, add_randomTime);
		retorno=0;
	}
	return retorno;
}

int filtrarTipoBMX (void* element)
{
	int retorno=0;
	eBicicleta* aux;

	aux = (eBicicleta*) element;
	if(strcmp(aux->tipo,"BMX")==0)
	{
		retorno=1;
	}

	return retorno;
}

int filtrarTipoPlayera (void* element)
{
	int retorno=0;
	eBicicleta* aux;

	aux = (eBicicleta*) element;
	if(strcmp(aux->tipo,"PLAYERA")==0)
	{
		retorno=1;
	}

	return retorno;
}

int filtrarTipoMTB (void* element)
{
	int retorno=0;
	eBicicleta* aux;

	aux = (eBicicleta*) element;
	if(strcmp(aux->tipo,"MTB")==0)
	{
		retorno=1;
	}

	return retorno;
}

int filtrarTipoPaseo (void* element)
{
	int retorno=0;
	eBicicleta* aux;

	aux = (eBicicleta*) element;
	if(strcmp(aux->tipo,"PASEO")==0)
	{
		retorno=1;
	}

	return retorno;
}

int controller_filterByType(LinkedList* pArrayList)
{
	int retorno=1;
	int opcion=0;
    LinkedList* auxLinkedList;
    auxLinkedList = ll_newLinkedList();

	if(pArrayList!=NULL && auxLinkedList!=NULL)
	{
		if(utn_getNumeroInt(&opcion, "Ingrese tipo: \n1.bmx\n2.playera\n3.mtb\n4.paseo\n", "Error", 1, 4, 2)==0)
		{
			switch(opcion)
			{
			case 1:
				auxLinkedList = ll_filter(pArrayList, filtrarTipoBMX);
				if(controller_save("bicicletasXtipo.csv",auxLinkedList))
					printf("Error al guardar el listado\n");
				else
					printf("Datos guardados\n");
				break;
			case 2:
				auxLinkedList = ll_filter(pArrayList, filtrarTipoPlayera);
				if(controller_save("bicicletasXtipo.csv",auxLinkedList))
					printf("Error al guardar el listado\n");
				else
					printf("Datos guardados\n");
				break;
			case 3:
				auxLinkedList = ll_filter(pArrayList, filtrarTipoMTB);
				if(controller_save("bicicletasXtipo.csv",auxLinkedList))
					printf("Error al guardar el listado\n");
				else
					printf("Datos guardados\n");
				break;
			case 4:
				auxLinkedList = ll_filter(pArrayList, filtrarTipoPaseo);
				if(controller_save("bicicletasXtipo.csv",auxLinkedList))
					printf("Error al guardar el listado\n");
				else
					printf("Datos guardados\n");
				break;
			}
		}
		else
			printf("Operación cancelada");
	}
	return retorno;
}

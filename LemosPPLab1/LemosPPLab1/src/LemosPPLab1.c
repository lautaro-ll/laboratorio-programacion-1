/*
 ============================================================================
 Name        : LemosPPLab1.c
 Author      : Lemos
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_lemos.h"
#include "bicicleta.h"
#include "trabajo.h"

#define CANTHARDCODE 5
#define TAM 15
#define TAMT 4
#define TAMC 5
#define TAMS 4
#define TAMTRABAJO 15

int main(void)
{
	setbuf(stdout, NULL);
	char opcion;
	char salida='n';
	int proximoId=1000;
	int proximoIdT=2000;
	eTipo tipo[TAMT] = {{1,"Rutera"}, {2,"Carrera"}, {3,"Mountain"}, {4,"BMX"}};
	eColor color[TAMC] = {{1,"Gris"}, {2,"Negro"}, {3,"Blanco"}, {4,"Azul"}, {5,"Rojo"}};
	eServicio servicio[TAMS] = {{1,"Limpieza", 250}, {2,"Parche", 300}, {3,"Centrado", 400}, {4,"Cadena", 350}};
	eBicicleta lista[TAM];
	eTrabajo trabajos[TAMTRABAJO];


	inicializarBicicletas(lista,TAM);
	inicializarTrabajos(trabajos,TAMTRABAJO);

	hardCodearBicicletas(lista, CANTHARDCODE);
	proximoIdT+=CANTHARDCODE+1;

	do
	{
		if(utn_getCharacter(&opcion, "\n***** Gestion de Bicicleteria *****\n\n"
				"A.	ALTA BICICLETA\n"
				"B.	MODIFICAR BICICLETA\n"
				"C.	BAJA BICICLETA\n"
				"D.	LISTAR BICICLETAS\n"
				"E.	LISTAR TIPOS \n"
				"F.	LISTAR COLORES\n"
				"G.	LISTAR SERVICIOS\n"
				"H.	ALTA TRABAJO\n"
				"I.	LISTAR TRABAJOS\n"
				"J.	SALIR\n",
				"\nReingrese Opcion (1 a 9)\n",'A','J',2)==0)
		{
			switch(opcion)
			{
				case 'A':
					if(altaBicicleta(proximoId,lista,TAM,tipo,TAMT,color,TAMC)==1)
					{
						proximoId+=1;
					}
					else
						printf("No se pudo dar de alta");
					break;
				case 'B':
					if(checkEmpty(lista, TAM)==1)
					{
						modificarBicicleta(lista,TAM,tipo,TAMT,color,TAMC);
					}
					else
						printf("\n******* No hay empleados que modificar *******\n\n");

					break;
				case 'C':
					if(checkEmpty(lista, TAM)==1)
					{
						bajaBicicleta(lista,TAM,tipo,TAMT,color,TAMC);
					}
					else
						printf("\n******* No hay empleados que dar de baja *******\n\n");

					break;
				case 'D':
					mostrarBicicletas(lista,TAM,tipo,TAMT,color,TAMC);
					break;
				case 'E':
					listarTipos(tipo,TAMT);
					break;
				case 'F':
					listarColor(color,TAMC);
					break;
				case 'G':
					listarServicios(servicio,TAMS);
					break;
				case 'H':
					if(altaTrabajo(proximoIdT,trabajos,TAMTRABAJO,lista,TAM,tipo,TAMT,color,TAMC,servicio,TAMS)==1)
					{
						proximoIdT+=1;
					}
					else
						printf("No se pudo dar de alta");
					break;
				case 'I':
					mostrarTrabajos(trabajos,TAMTRABAJO,lista,TAM,servicio,TAMS);
					break;
				case 'J':
					printf("¿Confirma Salida? (ingrese 's' para salir)\n");
					fflush(stdin);
					scanf("%c", &salida);
					break;
			}
		}
	}while(salida!='s');

	return 0;
}

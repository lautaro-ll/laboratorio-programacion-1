/*
 ============================================================================
 Name        : 1G.c
 Author      : Lemos
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "bicicletas.h"
#include "utn_lemos.h"

int main(void)
{
	setbuf(stdout, NULL);

	int option = 0;

	    LinkedList* lista = ll_newLinkedList();

	    do{
	    	if(!menu(&option))
	    	{
				switch(option)
				{
					case 1:
						if(controller_load("bicicletas.csv",lista))
							printf("Error al cargar los empleados\n");
						else
							printf("Carga de empleados exitosa\n");
						break;
					case 2:
						controller_List(lista);
						break;
					case 3:
						if(controller_asignTime(lista))
							printf("Ningún tiempo fue asignado\n");
						else
							printf("Tiempo asignado exitosamente\n");
						break;
					case 4:
						controller_filterByType(lista);
						break;
					case 5:
						controller_sort(lista);
						break;
					case 6:
						if(controller_save("bicicletas.csv",lista))
							printf("Error al guardar el listado\n");
						else
							printf("Datos guardados\n");
						break;
					case 7:
						ll_deleteLinkedList(lista);
						break;
				}
	    	}
	    }while(option != 7);

	return 0;
}

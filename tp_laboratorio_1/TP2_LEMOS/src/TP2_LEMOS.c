/*
 ============================================================================
 Name        : TP2_LEMOS.c
 Author      : Lemos Lautaro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_lemos.h"

#define TAM 1000
#define CANTHARDCODE 11

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int proximoId=100;
	char salida='n';
	Employee lista[TAM];
	Employee auxEmpleado;

	initEmployees(lista,TAM);


//	hardCodearEmpleados(lista, CANTHARDCODE);
//	proximoId+=CANTHARDCODE+1;


	do
	{
		if(menu(&opcion)==0)
		{
			switch(opcion)
			{
				case 1:
					printf("\n******* Alta de Empleados *******\n\n");
					if(	utn_getString(auxEmpleado.name,"Ingrese nombre\n","ERROR (Rango->0,20)\n",0,20,2)==0 &&
						utn_getString(auxEmpleado.lastName,"Ingrese apellido\n","ERROR (Rango->0,20)\n",0,20,2)==0 &&
						utn_getNumeroFloat(&auxEmpleado.salary,"Ingrese sueldo\n","ERROR (Rango->0,10000000)\n",0,10000000,2)==0 &&
						utn_getNumeroInt(&auxEmpleado.sector,"Ingrese sector (1 a 10)\n","ERROR (Rango->1,10)\n",1,10,2)==0
						)
					{
						if(addEmployee(lista, TAM, proximoId, auxEmpleado.name,auxEmpleado.lastName,auxEmpleado.salary,auxEmpleado.sector))
							proximoId+=1;
					}
					else
						printf("No se ingresó el empleado por errores en el ingreso de datos\n");
					break;
				case 2:
					if(checkEmpty(lista, TAM)==1)
					{
						if(utn_getNumeroInt(&auxEmpleado.id,"Ingrese id\n","ERROR (Rango->0,10000)\n",0,1000,2)==0)
							modifyEmployee(lista,TAM,auxEmpleado.id);
						else
							printf("No se ingresó el empleado por errores en el ingreso de datos\n");
					}
					else
						printf("\n******* No hay empleados que modificar *******\n\n");
					break;
				case 3:
					if(checkEmpty(lista, TAM)==1)
					{
						if(utn_getNumeroInt(&auxEmpleado.id,"Ingrese id\n","ERROR (Rango->0,10000)\n",0,1000,2)==0)
							removeEmployee(lista,TAM,auxEmpleado.id);
						else
							printf("No se ingresó el empleado por errores en el ingreso de datos\n");
					}
					else
						printf("\n******* No hay empleados que dar de baja *******\n\n");
					break;

				case 4:
					informarEmpleados(lista, TAM);
					break;
				case 5:
					utn_getCharacter(&salida, "¿Confirma Salida? (ingrese 's' para salir)\n", "",'a','z',0);
					break;
			}
		}


	}while(salida!='s');

	return 0;
}

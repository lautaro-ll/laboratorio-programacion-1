/*
 * ArrayEmployees.c
 *
 *  Created on: 10 may. 2020
 *      Author: Lemos
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_lemos.h"
#include "datawarehouse.h"
#include "ArrayEmployees.h"
/**
 * \brief Permite cargar un lote de empleados al inicializar
 *
 * \param vec Employee lista de empleados
 * \param cant int cantidad de empleados a cargar
 */
void hardCodearEmpleados(Employee vec[], int cant)
{
	for(int i=0;i<cant;i++)
	{
		vec[i].id=ids[i];
		strncpy(vec[i].name,nombres[i],sizeof(vec[i]));
		strncpy(vec[i].lastName,apellidos[i],sizeof(vec[i]));
		vec[i].salary=sueldos[i];
		vec[i].sector=idsSector[i];
	}
}
/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{
	int retorno=-1;
	if(list!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			list[i].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}
/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int printEmployees(Employee* list, int length)
{
	int retorno=-1;
	int vacio=0;
	if(list!=NULL)
	{
		printf("\n******* Lista de Empleados *******\n\n");
		printf(" Id          Nombre         Apellido     Sueldo        Sector\n\n");

		for(int i=0;i<length;i++)
		{
			if (list[i].isEmpty==0)
			{
				printf(" %d	%10s	%10s	%8.2f	%d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
				vacio=1;
			}
		}
		if(!vacio)
			printf("\n******* No hay empleados que listar *******\n\n");
		retorno=0;
	}
	return retorno;
}
/** \brief add in a existing list of employees the values received as parameters in the first empty position
*
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
**/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno=-1;
	int indice = findEmpty(list,len);

	if(list!=NULL)
	{
		if(indice==-1)
		{
			printf("Sistema Completo\n\n");
			retorno=0;
		}
		else
		{
			if(findEmployeeById(list,len,id)==-1)
			{
						list[indice].isEmpty=0;
						list[indice].id=id;
						strcpy(list[indice].name,name);
						strcpy(list[indice].lastName,lastName);
						list[indice].salary=salary;
						list[indice].sector=sector;
						printf("\nAlta de empleado exitosa\n");
						retorno=1;
			}
			else
			{
				printf("Ya existe un empleado registrado con ese id \n\n");
				retorno=0;
			}
		}

	}
	return retorno;
}
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
	int indice=-1;

		for(int i=0;i<len;i++)
			if(list[i].id == id && list[i].isEmpty==0)
			{
				indice=i;
				break;
			}

		return indice;
}
/**
 * \brief find an empty slot and returns the index position in array.
 *
 * \param vec Employee
 * \param tam int
 * \return Return empty index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 */
int findEmpty(Employee list[], int tam)
{
	int indice=-1;

	for(int i=0; i<tam; i++)
		if(list[i].isEmpty)
		{
			indice=i;
			break;
		}
	return indice;
}
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
	int i;
	char confirma;
	int retorno =-1;

	if(list!=NULL)
	{

		printf("\n******* Baja de Empleado *******\n");

			i = findEmployeeById(list,len,id);
			if(i==-1)
			{
				printf("No hay registro de un empleado con el id: %d\n", id);
			}
			else
			{
				printf("Id          Nombre         Apellido     Sueldo        Sector\n");
				printf(" %d	%10s	%10s	%.2f	%d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);

				if(utn_getCharacter(&confirma,"\nConfirma la baja? ('s' para confirmar)\n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
				{
					list[i].isEmpty=1;
					printf("Se realizó la baja con éxito\n");
				}
				else
				{
					printf("Se canceló la operación\n");
				}
			}
			retorno=0;
	}
	return retorno;
}
/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
	int retorno=-1;
	Employee auxEmpleado;

	if(list!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			for(int i=0;i<len-1;i++)
			{
				for(int j=i+1;j<len;j++)
				{
					if(strcmp(list[i].lastName, list[j].lastName)>0 && order==1)
					{
						auxEmpleado=list[i];
						list[i]=list[j];
						list[j]=auxEmpleado;
					}
					else if(strcmp(list[i].lastName, list[j].lastName)==0 && list[i].sector>list[j].sector && order==1)
					{
						auxEmpleado=list[i];
						list[i]=list[j];
						list[j]=auxEmpleado;
					}
					if(strcmp(list[i].lastName, list[j].lastName)<0 && order==0)
					{
						auxEmpleado=list[i];
						list[i]=list[j];
						list[j]=auxEmpleado;
					}
					else if(strcmp(list[i].lastName, list[j].lastName)==0 && list[i].sector<list[j].sector && order==0)
					{
						auxEmpleado=list[i];
						list[i]=list[j];
						list[j]=auxEmpleado;
					}
				}
			}
		}
		printf("\nOrdenamiento exitoso\n");
		retorno=0;
	}
	else
		printf("\nOperación cancelada\n");

	return retorno;
}
/**
 * \brief Permite modificar Nombre, Apellido, Sueldo o Sector de un empleado ingresado por id
 *
 * \param list Employee* lista de empleados
 * \param len int tamaño de la lista
 * \param id int id del empleado a modificar
 * \return
 */
int modifyEmployee (Employee* list, int len, int id)
{
	int i;
	int retorno=-1;
	int opcion;
	char confirma;
	Employee auxEmpleado;

	printf("\n******* Modificar Empleado *******\n\n");
	if(list!=NULL)
	{
		i = findEmployeeById(list,len,id);
		if(i==-1)
		{
			printf("No hay registro de un empleado con el id: %d\n", id);
		}
		else
		{
			printf(" Id          Nombre         Apellido     Sueldo        Sector\n");
			printf(" %d	%10s	%10s	%8.2f	%d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);

			if(utn_getCharacter(&confirma,"\n Confirma el empleado seleccionado? ('s' para confirmar)\n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
			{
				do
				{
					if(utn_getNumeroInt(&opcion,"\n Ingrese variable a modificar: 1-Nombre 2-Apellido 3-Salario 4-Sector 5-Salir\n", "ERROR (Rango 1->5)",1,5,2)==0)
					{
						switch(opcion)
						{
							case 1:
								if(utn_getString(auxEmpleado.name,"Ingrese nombre\n","ERROR (Rango->0,20)\n",0,20,2)==0)
								{
									strcpy(list[i].name,auxEmpleado.name);
									printf("Se realizó la modificación con éxito\n");
								}
								else
									printf("\nNo se modificaron datos\n");
								break;
							case 2:
								if(utn_getString(auxEmpleado.lastName,"Ingrese apellido\n","ERROR (Rango->0,20)\n",0,20,2)==0)
								{
									strcpy(list[i].lastName,auxEmpleado.lastName);
									printf("Se realizó la modificación con éxito\n");
								}
								else
									printf("\nNo se modificaron datos\n");
								break;
							case 3:
								if(utn_getNumeroFloat(&auxEmpleado.salary,"Ingrese nuevo sueldo\n","ERROR (Rango->0,10000000)\n",0,10000000,2)==0)
								{
									list[i].salary=auxEmpleado.salary;
									printf("Se realizó la modificación con éxito\n");
								}
								else
									printf("\nNo se modificaron datos\n");
								break;
							case 4:
								if(utn_getNumeroInt(&auxEmpleado.sector,"Ingrese nuevo sector\n","ERROR (Rango->1,10)\n",1,10,2)==0)
								{
									list[i].sector=auxEmpleado.sector;
									printf("Se realizó la modificación con éxito\n");
								}
								else
									printf("\nNo se modificaron datos\n");
								break;
							case 5:
								break;
						}
					}
				}while(opcion!=5);

			}
			else
			{
				printf("\nSe canceló la operación\n");
			}
		}
		retorno=0;
	}
	return retorno;

}
/**
 * \brief Indica si la lista está vacía
 *
 * \param list Employee*
 * \param len int
 * \return -1 Error - 0 Vacia - 1 No vacía
 */
int checkEmpty(Employee* list, int len)
{
	int retorno=-1;
	if(list!=NULL)
	{
		retorno=0;
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty==0)
			{
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Muestra el menu de informes de empleados
 *
 * \param list Employee* lista de empleados
 * \param len int tamaño de la lista
 */
void informarEmpleados(Employee* list, int len)
{
	int opcion;
	char salida;
	do
	{
		if(utn_getNumeroInt(&opcion, "\n***** Menu de Informes *****\n\n"
				"1. Listar Empleados por Apellido y Sector\n"
				"2. Total y promedio de los salarios, y cantidad de empleados que superan el promedio\n"
				"3. Salir\n","\nReingrese Opcion (1 a 3)\n",1,3,2)==0)
		{
			switch(opcion)
			{
				case 1:
					listarEmpleadosXApYSec(list,len);
					break;
				case 2:
					listarTotalyPromedioSalario(list,len);
					break;
				case 3:
					utn_getCharacter(&salida, "¿Confirma Salida? (ingrese 's' para salir)\n", "",'a','z',0);
					break;
			}
		}

	}while(salida!='s');

}
/**
 * \brief Muestra una lista de empleados ordenados por Apellido y Sector
 *
 * \param list Employee* lista de empleados
 * \param len int tamaño de la lista
 */
void listarEmpleadosXApYSec(Employee* list, int len)
{
	int orden;
	if(list!=NULL)
	{
		if(checkEmpty(list, len)==1)
		{
			if(utn_getNumeroInt(&orden,"Ingrese orden (1=ASC - 0=DESC)\n","ERROR ((1=ASC - 0=DESC))\n",0,1,2)==0)
			{
				sortEmployees(list,len,orden);
				printEmployees(list,len);
			}
			else
				printf("No se ordenó la lista por errores en el ingreso de datos\n");
		}
		else
			printf("\n******* No hay empleados que ordenar *******\n\n");
	}
}
/**
 * \brief Muestra el total de salarios, el promedio de los mismos y la cantidad de empleados que superan el promedio
 *
 * \param list Employee* lista de empleados
 * \param len int tamaño de la lista
 */
void listarTotalyPromedioSalario(Employee* list, int len)
{
	int total=0;
	int promedio;
	int supPromedio=0;
	int cantEmp=0;

	if(list!=NULL && checkEmpty(list, len)==1)
	{
		for(int i=0;i<len;i++)
		{
			if (list[i].isEmpty==0)
			{
				total+=list[i].salary;
				cantEmp++;
			}
		}
		promedio=total/cantEmp;
		for(int i=0;i<len;i++)
			if(list[i].isEmpty==0 && list[i].salary>promedio)
				supPromedio++;
		printf("\n******* Salario Total: %d\n", total);
		printf("\n******* Promedio de Salarios: %d\n", promedio);
		printf("\n******* Empleados que Superan el Promedio: %d\n", supPromedio);
	}
}
/**
 * \brief Muestra el menu de opciones
 *
 * \param op int
 * \return 0 si se ingresó correctamente, -1 si hay un error
 */
int menu (int* op)
{
	int retorno=-1;
	if(utn_getNumeroInt(op, "\n***** Gestion de Empleados *****\n\n"
			"1. Alta Empleado\n"
			"2. Modificar Empleado\n"
			"3. Baja Empleado\n"
			"4. Informar\n"
			"5. Salir\n",
			"\nReingrese Opcion (1 a 5)\n",1,5,2)==0)
	{
		retorno=0;
	}
	return retorno;
}

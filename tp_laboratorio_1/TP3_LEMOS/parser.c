#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=1;
	int cant;
	char buffer[4][128];
	Employee* auxEmp;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

		while(!feof(pFile))
		{
			cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
			if(cant==4)
			{
				auxEmp = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
				if(!ll_add(pArrayListEmployee, auxEmp))
				{
					retorno=0;
				}
			}
		}
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=1;
	int cant;
	Employee* auxEmp;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		while(!feof(pFile))
		{
			auxEmp = employee_new();
			cant = fread(auxEmp,sizeof(Employee),1,pFile);
			if(cant==1)
			{
				if(!ll_add(pArrayListEmployee, auxEmp))
					retorno=0;
			}
		}
	}

    return retorno;
}

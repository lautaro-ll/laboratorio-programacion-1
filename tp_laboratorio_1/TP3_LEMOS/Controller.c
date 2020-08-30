#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn_lemos.h"

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int -1=Error, 0=Lista vacia, 1=Se muestran datos
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int tam=ll_len(pArrayListEmployee);
	Employee* auxEmp;

	if(pArrayListEmployee!=NULL)
	{
		printf("ID             NOMBRE      HORAS         SUELDO\n");
		for(int i=0;i<tam;i++)
		{
			auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
			if( auxEmp != NULL)
			{
				mostrarEmpleado(auxEmp);
				retorno=1;
			}
		}
		if (retorno==-1)
		{
			printf("No hay empleados que mostrar\n\n");
			retorno=0;
		}
	}
	return retorno;
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=1;
	FILE* pFile;

	ll_clear(pArrayListEmployee);
	pFile = fopen(path, "r");

	if(path!=NULL && pArrayListEmployee!=NULL && pFile!=NULL)
	{
		if(!parser_EmployeeFromText(pFile,pArrayListEmployee))
				retorno=0;
	}

	fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=1;
	FILE* pFile;

	ll_clear(pArrayListEmployee);
	pFile = fopen(path, "rb");

	if(path!=NULL && pArrayListEmployee!=NULL && pFile!=NULL)
	{
		if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
				retorno=0;
	}

	fclose(pFile);
    return retorno;
}

/** \brief Encuentra el ultimo id asociado en la LinkedList
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int lastId(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int mayor=0;
    int flag=0;
    Employee* auxEmp;
    int tam=ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        for(int i=0;i<tam;i++)
        {
        	auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
            if(auxEmp!=NULL)
            {
                if(auxEmp->id > mayor || flag==0)
                {
                    mayor = auxEmp->id;
                    flag = 1;
                }
            }
        }
        retorno = mayor;
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=1;
    Employee* empleado;
    int idAux;
    int horasTrabajadasAux;
    int sueldoAux;
    char id[20];
	char nombre[128];
	char horasTrabajadas[20];
	char sueldo[20];
    char confirm='n';

    if(pArrayListEmployee!=NULL)
    {

    	if(	utn_getString(nombre,"Ingrese Nombre: ","Error (3 a 128 caracteres)\n",3,128,2)==0
        	&&  utn_getNumeroInt(&horasTrabajadasAux,"Ingrese Horas Trabajadas: ", "Error (Máximo 100000000hs.)\n",0,100000000,2)==0
			&&  utn_getNumeroInt(&sueldoAux,"Ingrese Sueldo: ", "Error (Máximo 1000000)\n",0,1000000,2)==0)
    	{

    		idAux = lastId(pArrayListEmployee)+1;
			sprintf(id,"%d",idAux);
			sprintf(horasTrabajadas,"%d",horasTrabajadasAux);
			sprintf(sueldo,"%d",sueldoAux);

			if(utn_getCharacter(&confirm,"¿Confirma los datos ingresados? ('s' para confirmar)\n","Proceso cancelado\n",'s','s',0)==0)
			{
				empleado = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
				if(!ll_add(pArrayListEmployee,empleado))
					retorno=0;
			}
		}
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=1;
    int id;
    Employee* empleado;
    char confirm;
    int opcion;
    char dato[128];
    int horasTrabajadasAux;
    int sueldoAux;

    if(controller_ListEmployee(pArrayListEmployee))
    {
        if(pArrayListEmployee!=NULL && utn_getNumeroInt(&id,"Ingrese el id del empleado a modificar: ","Error, reingrese un id valido", 0, 1000000,2)==0)
        {
            empleado = employee_find(pArrayListEmployee,id);

            if(empleado!=NULL)
            {
                printf("ID             NOMBRE      HORAS         SUELDO\n");
                printf("--------------------------------------------------\n");
                mostrarEmpleado(empleado);

                if(utn_getCharacter(&confirm,"¿Confirma el empleado seleccionado? ('s' para confirmar)\n","Proceso cancelado\n",'s','s',1)==0)
                {
                	do
                	{
						if(utn_getNumeroInt(&opcion,"¿Qué dato desea modificar?\n"
										 "1. Nombre\n"
										 "2. Horas Trabajadas\n"
										 "3. Sueldo\n"
										 "4. Salir\n",
										 "Error, reingrese opcion (1 a 4)\n", 1, 4, 1)==0)
						{
							switch(opcion)
							{
							case 1:
								if(utn_getString(dato,"Ingrese Nombre: ","Error (3 a 128 caracteres)\n",3,128,2)==0)
								{
									employee_setNombre(empleado,dato);
									printf("Nombre modificado\n");
									retorno=0;
								}
								else
									printf("Operacion cancelada\n");
								break;
							case 2:
								if(utn_getNumeroInt(&horasTrabajadasAux,"Ingrese Horas Trabajadas: ", "Error (Máximo 100000000hs.)\n",0,100000000,2)==0)
								{
									sprintf(dato,"%d",horasTrabajadasAux);
									employee_setNombre(empleado,dato);
									printf("Horas trabajadas modificadas\n");
									retorno=0;
								}
								else
									printf("Operacion cancelada\n");
								break;
							case 3:
								if(utn_getNumeroInt(&sueldoAux,"Ingrese Sueldo: ", "Error (Máximo 1000000)\n",0,1000000,2)==0)
								{
									sprintf(dato,"%d",sueldoAux);
									employee_setNombre(empleado,dato);
									printf("Sueldo modificado\n");
									retorno=0;
								}
								else
									printf("Operacion cancelada\n");
								break;
							case 4:
								break;
							}
						}
                    }while(opcion!=4);
                }

            }
            else
            	printf("No se encontró el empleado ingresado\n");
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=1;
    int id;
    Employee* empleado;
    int index;
    char confirm;

    if(pArrayListEmployee!=NULL && controller_ListEmployee(pArrayListEmployee)
    	&& utn_getNumeroInt(&id,"Ingrese el id del empleado a modificar: ","Error, reingrese un id valido", 0, 1000000,2)==0)
    {
            empleado = employee_find(pArrayListEmployee,id);

            if(empleado!=NULL)
            {
                printf("ID             NOMBRE      HORAS         SUELDO\n");
                printf("--------------------------------------------------\n");
                mostrarEmpleado(empleado);

                if(utn_getCharacter(&confirm,"¿Confirma el empleado seleccionado? ('s' para confirmar)\n","Proceso cancelado\n",'s','s',1)==0)
                {
                    index = ll_indexOf(pArrayListEmployee,empleado);
                    ll_remove(pArrayListEmployee,index);
                    retorno=0;
                }
            }
            else
            	printf("No se encontró el empleado ingresado\n");
    }
    return retorno;
}
/** \brief Compara dos id y devuelve cual es mayor
 *
 * \param void* datoA
 * \param void* datoB
 * \return int
 */
int compareId (void* datoA , void* datoB)
{
   int retorno=0;

   if(((Employee*) datoA)->id > ((Employee*) datoB)->id)
       retorno=1;
   if(((Employee*) datoA)->id < ((Employee*) datoB)->id)
       retorno=-1;

   return retorno;
}
/** \brief Compara dos nombres y devuelve cual es mayor
 *
 * \param void* datoA
 * \param void* datoB
 * \return int
 */
int compareNombre (void* datoA , void* datoB)
{
   int retorno=0;

   if(strcmp(((Employee*) datoA)->nombre,((Employee*) datoB)->nombre) > 0)
       retorno=1;
   if(strcmp(((Employee*) datoA)->nombre,((Employee*) datoB)->nombre) < 0)
       retorno=-1;

   return retorno;
}
/** \brief Compara dos cantidades de horas y devuelve cual es mayor
 *
 * \param void* datoA
 * \param void* datoB
 * \return int
 */
int compareHorasTrabajadas (void* datoA , void* datoB)
{
   int retorno=0;

   if(((Employee*) datoA)->horasTrabajadas > ((Employee*) datoB)->horasTrabajadas)
       retorno=1;
   if(((Employee*) datoA)->horasTrabajadas < ((Employee*) datoB)->horasTrabajadas)
       retorno=-1;

   return retorno;
}
/** \brief Compara dos sueldos y devuelve cual es mayor
 *
 * \param void* datoA
 * \param void* datoB
 * \return int
 */
int compareSueldo (void* datoA , void* datoB)
{
   int retorno=0;

   if(((Employee*) datoA)->sueldo > ((Employee*) datoB)->sueldo)
       retorno=1;
   if(((Employee*) datoA)->sueldo < ((Employee*) datoB)->sueldo)
       retorno=-1;

   return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=1;
    int opcion;
    int orden;
    char ordenIngresado;

    if(pArrayListEmployee!=NULL)
    {
    	if(utn_getNumeroInt(&opcion,"¿En base a que dato desea ordenar?\n"
    								"1. Id\n"
    								"2. Nombre\n"
    								"3. Horas Trabajadas\n"
								 	"4. Sueldo\n",
									"Error, reingrese opcion (1 a 4)\n", 1, 4, 1)==0
    		&& utn_getCharacter(&ordenIngresado,"Seleccione el tipo de ordenamiento\n"
    									"A: Ascendente\n"
    									"B: Descendente\n",
										"Error, reingrese opcion ('A' a 'B')\n", 'A', 'B', 1)==0)
		{
    		if(ordenIngresado=='A')
    		{
    			orden=1;
    		}
    		if(ordenIngresado=='B')
    		{
    			orden=0;
    		}

			switch(opcion)
			{
				case 1:
					printf("Ordenando. Aguarde un momento...\n");
					if(!ll_sort(pArrayListEmployee,compareId,orden))
					{
						printf("Lista ordenada por Id\n");
						retorno=0;
					}
					else
						printf("Error. Operacion cancelada\n");
					break;
				case 2:
					printf("Ordenando. Aguarde un momento...\n");
					if(!ll_sort(pArrayListEmployee,compareNombre,orden))
					{
						printf("Lista ordenada por Nombre\n");
						retorno=0;
					}
					else
						printf("Error. Operacion cancelada\n");
					break;
				case 3:
					printf("Ordenando. Aguarde un momento...\n");
					if(!ll_sort(pArrayListEmployee,compareHorasTrabajadas,orden))
					{
						printf("Lista ordenada por Horas Trabajadas\n");
						retorno=0;
					}
					else
						printf("Error. Operacion cancelada\n");
					break;
				case 4:
					printf("Ordenando. Aguarde un momento...\n");
					if(!ll_sort(pArrayListEmployee,compareSueldo,orden))
					{
						printf("Lista ordenada por Sueldo\n");
						retorno=0;
					}
					else
						printf("Error. Operacion cancelada\n");
					break;
			}
		}
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=1;
	int tam=ll_len(pArrayListEmployee);
	FILE* pFile;
	Employee* auxEmp;

	if(pArrayListEmployee!=NULL)
	{
		pFile = fopen(path,"w");

		if(pFile!=NULL)
		{
			fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
			for(int i=0;i<tam;i++)
			{
				auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
				fprintf(pFile,"%d,%s,%d,%d\n",auxEmp->id,auxEmp->nombre,auxEmp->horasTrabajadas,auxEmp->sueldo);
			}
		retorno=0;
		}
		fclose(pFile);
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=1;
	int tam=ll_len(pArrayListEmployee);
	FILE* pFile;
	Employee* auxEmp;

	if(pArrayListEmployee!=NULL)
	{
		pFile = fopen(path,"wb");

		if(pFile!=NULL)
		{
			for(int i=0;i<tam;i++)
			{
				auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
				fwrite(auxEmp,sizeof(Employee),1,pFile);
			}
		retorno=0;
		}
		fclose(pFile);
	}
	return retorno;
}


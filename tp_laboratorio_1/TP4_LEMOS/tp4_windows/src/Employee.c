#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_lemos.h"

int menu(int* option)
{
	int retorno=-1;
	int opcIngresada;
	if(utn_getNumeroInt(&opcIngresada,"\nMenu de opciones\n"
	    			 "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
	    			 "2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
	    			 "3. Alta de empleado\n"
	    			 "4. Modificar datos de empleado\n"
	    			 "5. Baja de empleado\n"
	    			 "6. Listar empleados\n"
	    			 "7. Ordenar empleados\n"
	    			 "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
	    			 "9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
	    			 "10. Salir\n"
					 "11. Modificar empleado\n"
					 "12. Duplicar lista\n"
					 "13. Listar empleados de lista duplicada\n"
					 "14. Mover empleado y reasignar id\n",
	    	     	 "Error, reingrese opcion (1 a 14)\n", 1, 14, 1)==0)
	{
		retorno=0;
		*option=opcIngresada;
	}
	return retorno;
}

Employee* employee_find(LinkedList* pArrayListEmployee, int id)
{
    int tam = ll_len(pArrayListEmployee);
    Employee* empleado;

    if(pArrayListEmployee!=NULL)
    {
        for(int i=0;i<tam;i++)
        {
        	empleado = (Employee*)ll_get(pArrayListEmployee,i);
            if(empleado->id == id)
                break;
            empleado=NULL;
        }
    }
    return empleado;
}

int mostrarEmpleado(Employee* empleado)
{
    int retorno=-1;

    if(empleado!=NULL)
    {
        printf(" %d    %20s    %d    %d\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
        retorno=0;
    }
    return retorno;
}

Employee* employee_new()
{
    Employee* newEmployee;
    newEmployee= (Employee*) malloc(sizeof(Employee));

    if(newEmployee!=NULL)
    {
            newEmployee->id =0;
            strcpy(newEmployee->nombre, "");
            newEmployee->horasTrabajadas=0;
            newEmployee->sueldo=0;
    }

    return newEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    int id;
    int horasTrabajadas;
    float sueldo;
    Employee* newEmployee;
    newEmployee = employee_new();


    if(newEmployee!=NULL)
    {
        id = atoi(idStr);
        horasTrabajadas = atoi(horasTrabajadasStr);
        sueldo = atof(sueldoStr);

        if(    employee_setId(newEmployee,id)
            || employee_setNombre(newEmployee, nombreStr)
            || employee_setHorasTrabajadas(newEmployee, horasTrabajadas)
			|| employee_setSueldo(newEmployee, sueldo)
           )
        {
            free(newEmployee);
            newEmployee=NULL;
        }
    }

    return newEmployee;
}

int employee_delete(Employee* emp)
{
    int retorno=1;

    if(emp!=NULL)
    {
        free(emp);
        retorno=0;
    }

    return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno=1;

    if(this!=NULL && id>0 && id<1000)
    {
    	this->id=id;
        retorno=0;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{
    int retorno=1;

    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=1;

    if(this!=NULL && strlen(nombre)>=3 && strlen(nombre)<=20)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=1;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=1;

    if(this!=NULL && horasTrabajadas>0)
    {
    	this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=1;

    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=1;

    if(this!=NULL && sueldo>0 && sueldo<1000000)
    {
    	this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=1;

    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}



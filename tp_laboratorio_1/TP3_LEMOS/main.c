#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_lemos.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    char confirm;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	if(!menu(&option))
    	{
			switch(option)
			{
				case 1:
					if(controller_loadFromText("data.csv",listaEmpleados))
						printf("Error al cargar los empleados\n");
					else
						printf("Carga de empleados exitosa\n");
					break;
				case 2:
					if(controller_loadFromBinary("data.bin",listaEmpleados))
						printf("Error al cargar los empleados\n");
					else
						printf("Carga de empleados exitosa\n");
					break;
				case 3:
					if(controller_addEmployee(listaEmpleados))
						printf("Ningún empleado fue agregado\n");
					else
						printf("Empleado agregado exitosamente\n");
					break;
				case 4:
					if(controller_editEmployee(listaEmpleados))
						printf("Ningún empleado fue modificado\n");
					else
						printf("Empleado modificado exitosamente\n");
					break;
				case 5:
					if(controller_removeEmployee(listaEmpleados))
						printf("Ningún empleado fue eliminado\n");
					else
						printf("Empleado eliminado exitosamente\n");
					break;
				case 6:
					controller_ListEmployee(listaEmpleados);
					break;
				case 7:
					controller_sortEmployee(listaEmpleados);
					break;
				case 8:
					if(controller_saveAsText("data.csv",listaEmpleados))
						printf("Error al guardar el listado\n");
					else
						printf("Datos guardados en data.csv\n");
					break;
				case 9:
					if(controller_saveAsBinary("data.bin",listaEmpleados))
						printf("Error al guardar el listado\n");
					else
						printf("Datos guardados en data.bin\n");
					break;
				case 10:
					if(!(utn_getCharacter(&confirm,"¿Desea salir del programa? ('s' para confirmar)\n","Proceso cancelado\n",'s','s',0)==0))
						option=0;
					else
						ll_deleteLinkedList(listaEmpleados);
					break;

			}
    	}
    }while(option != 10);

    return 0;
}

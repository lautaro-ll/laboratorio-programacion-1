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

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleados2 = ll_newLinkedList();

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
					ll_deleteLinkedList(listaEmpleados);
					break;
				case 11:
					if(controller_setEmployee(listaEmpleados))
						printf("Ningún empleado fue modificado\n");
					else
						printf("Empleado modificado exitosamente\n");
					break;
				case 12:
					listaEmpleados2 = ll_clone(listaEmpleados);
					if(ll_containsAll(listaEmpleados, listaEmpleados2)==1)
						printf("La lista fue duplicada\n");
					else
						printf("No se pudo duplicadar la lista\n");
					break;
				case 13:
					controller_ListEmployee(listaEmpleados2);
					break;
				case 14:
					if(controller_moveEmployee(listaEmpleados))
						printf("Ningún empleado fue reordenado\n");
					else
						printf("Empleado reordenado exitosamente\n");
					break;
			}
    	}
    }while(option != 10);

    return 0;
}

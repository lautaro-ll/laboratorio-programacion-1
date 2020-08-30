/*
 * ArrayEmployees.h
 *
 *  Created on: 10 may. 2020
 *      Author: Lemos
 */

#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_

struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;

}typedef Employee;

void hardCodearEmpleados(Employee vec[], int cant);

int initEmployees(Employee* list, int len);
int printEmployees(Employee* list, int length);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmpty (Employee vec[], int tam);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int modifyEmployee (Employee* list, int len, int id);
int checkEmpty(Employee* list, int len);
void informarEmpleados(Employee* list, int len);
void listarEmpleadosXApYSec(Employee* list, int len);
void listarTotalyPromedioSalario(Employee* list, int len);
int menu (int* op);

#endif /* EMPLEADOS_H_ */

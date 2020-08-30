/*
 * trabajo.h
 *
 *  Created on: 15 may. 2020
 *      Author: Lemos
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_
#include "bicicleta.h"

typedef struct {
	int dia;
	int mes;
	int anio;

} eFecha;

typedef struct {
	int id;
	char descripcion[20];
	float precio;

} eServicio;


typedef struct {
	int id;
	int idBicicleta;
	int idServicio;
	eFecha fecha;
	int isEmpty;

} eTrabajo;


void listarServicios (eServicio servicio[], int tam);
void inicializarTrabajos(eTrabajo vec[], int tam);
void mostrarServicios (eServicio servicio[], int tam);
int buscarTrabajo (int idx, eTrabajo vec[], int tam);
int buscarLibreT (eTrabajo vec[], int tam);
int cargarBicicleta(char* marcaBicicleta,eBicicleta bicicletas[],int tam,int idBicicleta);
int cargarServicio(char* descripcionServicio,eServicio servicios[],int tam,int idServicio);
void mostrarTrabajo(eTrabajo trabajo, eBicicleta bicicletas[], int tambic, eServicio servicios[], int tamser);
void mostrarTrabajos(eTrabajo trabajos[], int tamtra, eBicicleta bicicletas[], int tambic, eServicio servicios[], int tamser);
int altaTrabajo (int id, eTrabajo trabajos[], int tam, eBicicleta bicicletas[], int tambic, eTipo tipo[], int tamtip, eColor color[], int tamcol, eServicio servicio[], int tamser);


#endif /* TRABAJO_H_ */

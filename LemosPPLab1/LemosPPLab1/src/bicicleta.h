/*
 * bicicleta.h
 *
 *  Created on: 15 may. 2020
 *      Author: Lemos
 */

#ifndef BICICLETA_H_
#define BICICLETA_H_

typedef struct {
	int id;
	char descripcion[20];

} eTipo;

typedef struct {
	int id;
	char descripcion[20];

} eColor;

typedef struct {
	int id;
	char marca[20];
	float rodado;
	int idTipo;
	int idColor;
	int isEmpty;

} eBicicleta;

void mostrarBicicleta (eBicicleta bic, eTipo tipo[], int tamtip, eColor color[], int tamcol);
void mostrarBicicletas (eBicicleta vec[], int tam, eTipo tipo[], int tamtip, eColor color[], int tamcol);
int cargarDescripcionTipo(char descripcion[], int id, eTipo tipo[], int tamtip);
int cargarDescripcionColor(char descripcion[], int id, eColor color[], int tamcol);
void ordenarBicicletas(eBicicleta vec[], int tam);
void inicializarBicicletas(eBicicleta vec[], int tam);
void hardCodearBicicletas(eBicicleta vec[], int cant);
void listarTipos (eTipo tipo[], int tam);
void listarColor (eColor color[], int tam);
int altaBicicleta (int idx, eBicicleta vec[], int tam, eTipo tipo[], int tamtip, eColor color[],int tamcol);
void modificarBicicleta (eBicicleta vec[], int tam, eTipo tipo[], int tamtip, eColor color[],int tamcol);
void bajaBicicleta (eBicicleta vec[], int tam,  eTipo tipo[], int tamtip, eColor color[],int tamcol);
int buscarBicicleta (int idx, eBicicleta vec[], int tam);
int checkEmpty(eBicicleta* list, int len);


#endif /* BICICLETA_H_ */

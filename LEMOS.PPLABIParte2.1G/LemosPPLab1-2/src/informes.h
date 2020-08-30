/*
 * informes.h
 *
 *  Created on: 22 may. 2020
 *      Author: Lau
 */

#ifndef INFORMES_H_
#define INFORMES_H_


void informesTrabajos(eBicicleta lista[],int tam,eTrabajo trabajos[],int tamtra, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eServicio servicios[],int tamser);
void mostrarBicisPorColor (eBicicleta vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip);
void mostrarBicisPorTipo (eBicicleta vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip);
void informarBiciMenorRodado  (eBicicleta vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip);
void listarBicisPorTipo  (eBicicleta vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip);
void contarBicisPorColorYTipo (eBicicleta vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip);
void mostrarColoresMasElegidos (eBicicleta vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip);
void trabajosPorBici (eBicicleta bicicletas[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eTrabajo trabajos[], int tamt, eServicio servicios[],int tamser);
void sumaDeImportesPorBici (eBicicleta bicicletas[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eTrabajo trabajos[], int tamtra, eServicio servicios[],int tamser);
void bicisPorServicio (eBicicleta bicicletas[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eTrabajo trabajos[], int tamtra, eServicio servicios[],int tamser);
void serviciosPorFecha (eBicicleta bicicletas[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eTrabajo trabajos[], int tamtra, eServicio servicios[],int tamser);


#endif /* INFORMES_H_ */

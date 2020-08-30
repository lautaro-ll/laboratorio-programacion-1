/*
 * bicicletas.h
 *
 *  Created on: 29 Jun 2020
 *      Author: Lautaro
 */

#ifndef BICICLETAS_H_
#define BICICLETAS_H_

typedef struct
{
    int id_bike;
    char nombre[128];
    char tipo[128];
    int tiempo;
}eBicicleta;

int menu(int* option);
eBicicleta* bike_find(LinkedList* pArrayList, int id);
int mostrarBicicleta(eBicicleta* bicicleta);
eBicicleta* bike_new();
eBicicleta* bike_newParametros(char* idStr,char* nombreStr,char* tipoStr, char* tiempoStr);
int bike_delete(eBicicleta* bicicleta);
int bike_setId(eBicicleta* this,int id);
int bike_getId(eBicicleta* this,int* id);
int bike_setNombre(eBicicleta* this,char* nombre);
int bike_getNombre(eBicicleta* this,char* nombre);
int bike_setTipo(eBicicleta* this,char* tipo);
int bike_getTipo(eBicicleta* this,char* tipo);
int bike_setTiempo(eBicicleta* this,float tiempo);
int bike_getTiempo(eBicicleta* this,float* tiempo);


#endif /* BICICLETAS_H_ */

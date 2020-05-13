/*
 * eTrabajo.h
 *
 *  Created on: May 13, 2020
 *      Author: catalina
 */

#ifndef ETRABAJO_H_
#define ETRABAJO_H_
#include "eFecha.h"
#include "eServicio.h"

typedef struct{
	int id;
	int idNotebook;
	int idServicio;
	eFecha fecha;
	int isEmpty;

}eTrabajo;

int inicializarT(eTrabajo listaT[], int tamT);
int buscarLibreT(eTrabajo listaT[], int tamT);
int buscarTrabajoPorId(int id, eTrabajo listaT[], int tamT);
void mostrarTrabajo(eTrabajo trabajo, eServicio listaS[], int tamS);
void mostrarTrabajos(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);


#endif /* ETRABAJO_H_ */

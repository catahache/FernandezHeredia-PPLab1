/*
 * menus.h
 *
 *  Created on: May 13, 2020
 *      Author: catalina
 */

#ifndef MENUS_H_
#define MENUS_H_
#include "eTrabajo.h"
#include "eNotebook.h"
#include "eTipo.h"
#include "eMarca.h"
#include "eServicio.h"

int menu();
int menuAltas();
void alta(int* nextIdN, int* flagN, int* nextIdT, int* flagT, eTrabajo listaT[], int tamT, eNotebook listaN[], int tamN,  eTipo listaTipo[], int tamTipo, eMarca listaM[], int tamM, eServicio listaS[], int tamS);
void baja(int flagN, eNotebook listaN[], int tamN, eMarca listaM[], int tamM, eTipo listaTipos[], int tamTipos);
int modificacionNotebook(int flagN, eNotebook listaN[], int tamN, eTipo listaT[], int tamT, eMarca listaM[], int tamM);
int menuListas();
void listar(int flagN, int flagT, eNotebook listaN[], int tamN, eTipo listaTipo[], int tamTipo, eMarca listaM[], int tamM, eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);
int altaNotebook(int idX, eNotebook listaN[], int tamN, eTipo listaT[], int tamT, eMarca listaM[], int tamM);
int altaTrabajo(int idX, eTrabajo listaT[], int tamT, eNotebook listaN[], int tamN, eServicio listaS[], int tamS, eMarca listaM[], int tamM, eTipo tipos[], int tamTipos);
int bajaNotebook(int idN, int flagN, eNotebook listaN[], int tamN, eTipo listaTipos[], int tamTipos, eMarca listaM[], int tamM);

#endif /* MENUS_H_ */

/*
 * eTrabajo.c
 *
 *  Created on: May 13, 2020
 *      Author: catalina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "eTrabajo.h"
#include "eServicio.h"

//INICIALIZAR

int inicializarT(eTrabajo listaT[], int tamT)
{
	if(listaT != NULL)
	{
		for(int i = 0; i < tamT; i++)
		{
			listaT[i].isEmpty = 1;
		}
		return 0;
	}
	else
	{
		return -1;
	}
}

//--------------------------------------------------------------------------------------------------------------------------------------------------
//BUSCAR


int buscarLibreT(eTrabajo listaT[], int tamT)
{
	//-1 no consiguio lugar
	int indice = -1;//-1 no es una posicion en el vec
	for(int i = 0; i < tamT; i++)
	{
		if(listaT[i].isEmpty == 1)
		{
			indice = i; //devuelvo el valor que tiene el indice
			break;
		}
	}
	return indice;
}


int buscarTrabajoPorId(int id, eTrabajo listaT[], int tamT)
{
	int indice = -1;

	for(int i = 0; i < tamT; i++)
	{
		if(listaT[i].id == id && listaT[i].isEmpty == 0) //si el vec id existe ya, me devuelve donde esta
		{
			indice = i;
			break;
		}
	}

	return indice;
}


//--------------------------------------------------------------------------------------------------------------------------------------------------
//MOSTRAR


void mostrarTrabajo(eTrabajo trabajo, eServicio listaS[], int tamS)
{
	char descripS[20];
	cargarDescripServicio(descripS, trabajo.idServicio, listaS, tamS);

	printf("%d    %d      %10s     %d/%d/%d\n\n", trabajo.id, trabajo.idNotebook, descripS, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
}


void mostrarTrabajos(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS)
{
	printf("ID   ID notebook     Servicio      Fecha\n\n");
	for(int i = 0; i < tamS; i++)
	{
		if(listaT[i].isEmpty == 0)
		{
			mostrarTrabajo(listaT[i], listaS, tamS);
		}
	}
}




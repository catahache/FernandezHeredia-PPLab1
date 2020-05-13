/*
 * eNotebook.c
 *
 *  Created on: May 13, 2020
 *      Author: catalina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "eNotebook.h"
#include "eTipo.h"
#include "eMarca.h"

//INICIALIZAR


int inicializarN(eNotebook listaN[], int tamN)
{
	if(listaN != NULL)
	{
		for(int i = 0; i < tamN; i++)
		{
			listaN[i].isEmpty = 1;
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


int buscarLibreN(eNotebook listaN[], int tamN)
{
	//-1 no consiguio lugar
	int indice = -1;//-1 no es una posicion en el vec
	for(int i = 0; i < tamN; i++)
	{
		if(listaN[i].isEmpty == 1)
		{
			indice = i; //devuelvo el valor que tiene el indice
			break;
		}
	}
	return indice;
}


int buscarNotebookPorId(int id, eNotebook listaN[], int tamN)
{
	int indice = -1;

	for(int i = 0; i < tamN; i++)
	{
		if(listaN[i].id == id && listaN[i].isEmpty == 0) //si el vec id existe ya, me devuelve donde esta
		{
			indice = i;
			break;
		}
	}

	return indice;
}


//--------------------------------------------------------------------------------------------------------------------------------------------------
//MOSTRAR


void mostrarNotebook(eNotebook notebook, eTipo listaT[], int tamT, eMarca listaM[], int tamM)
{
	char descripTipo[20];
	char descripMarca[20];

	cargarDescripTipo(descripTipo, notebook.idTipo, listaT, tamT);
	cargarDescripMarca(descripMarca, notebook.idMarca, listaM, tamM);
	printf("%d    %10s      %10s     %10s      %.2f\n\n", notebook.id, notebook.modelo, descripMarca, descripTipo, notebook.precio);
}


void mostrarNotebooks(eNotebook listaN[], int tamN, eTipo listaT[], int tamT, eMarca listaM[], int tamM)
{
	printf("ID    Modelo    Marca    Tipo     Precio\n\n");
	for(int i = 0; i < tamN; i++)
	{
		if(listaN[i].isEmpty == 0)
		{
			mostrarNotebook(listaN[i], listaT, tamT, listaM, tamM);
		}
	}
}


//--------------------------------------------------------------------------------------------------------------------------------------------------
//ORDENAR

int ordenarNotebooks(eNotebook listaN[], int tamN, int orden)
{
	int isOk = -1;
	eNotebook auxN;

	if(listaN != NULL)
	{
		for(int i = 0; i < tamN -1; i++)
		{
			for(int j = i + 1; j < tamN; j ++)
			{
				if(listaN[i].isEmpty == 0 && listaN[j].isEmpty == 0) //solo hace el burbujeo si no estan vacias las posiciones
				{

					if(orden == 1)
					{
						if(listaN[i].idTipo > listaN[j].idTipo || (listaN[i].idTipo == listaN[j].idTipo && listaN[i].precio > listaN[j].precio)) //de menor a mayor sector (agrupa) y apellido (ordena)
						{
							auxN = listaN[i];
							listaN[i] = listaN[j];
							listaN[j] = auxN;
						}

					}
					else if(orden == 0)
					{
						if(listaN[i].idTipo < listaN[j].idTipo || (listaN[i].idTipo == listaN[j].idTipo && listaN[i].precio < listaN[j].precio)) //de mayor a menor sector (agrupa) y apellido (ordena)
						{
							auxN = listaN[i];
							listaN[i] = listaN[j];
							listaN[j] = auxN;
						}

					}//else if
				}//if isEmpty
			}//for
		}//for
		isOk = 0;
	}//if list != NULL
	return isOk;
}

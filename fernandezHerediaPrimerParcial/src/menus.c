/*
 * menus.c
 *
 *  Created on: May 13, 2020
 *      Author: catalina
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include "utn.h"

//MAIN:

int menu()
{
	int opcion;

	system("clear");
	printf("***** MENU *****\n\n");
	printf("1. ALTAS\n");
	printf("2. BAJAS\n");
	printf("3. MODIFICACIONES\n");
	printf("4. LISTAS\n");
	printf("5. SALIR\n\n");
	utn_getEntero(&opcion, 3, "Ingrese la opcion elegida: ", "Error, no es una opcion valida.\n", 1, 5);

	return opcion;

}

//ALTAS:

int menuAltas()
{
	int opcion;

	system("clear");
	printf("***** Altas *****\n");
	printf("1. Notebook\n");
	printf("2. Trabajos\n");
	printf("3. Salir\n\n");
	utn_getEntero(&opcion, 3, "Ingrese la opcion elegida: ", "Error, no es una opcion valida.\n", 1, 3);

	return opcion;

}

//esta es la funcion que llamo en main:
void alta(int* nextIdN, int* flagN, int* nextIdT, int* flagT, eTrabajo listaT[], int tamT, eNotebook listaN[], int tamN,  eTipo listaTipo[], int tamTipo, eMarca listaM[], int tamM, eServicio listaS[], int tamS)
{

	char continueS = 's';
	char confirm;

	int idN = *nextIdN;
	int idT = *nextIdT;

	if(nextIdN != NULL && flagN != NULL && listaN != NULL && nextIdT != NULL && flagT != NULL && listaTipo != NULL && listaM != NULL && listaS != NULL)
	{
		do
		{
			switch(menuAltas())
			{
				case 1:
					if(altaNotebook(idN, listaN, tamN, listaTipo, tamTipo, listaM, tamM) == 1)
					{
						*nextIdN = idN++;
						*flagN = 1;
					}
					break;
				case 2:
					if(altaTrabajo(idT, listaT, tamT, listaN, tamN, listaS, tamS, listaM, tamM, listaTipo, tamTipo)  == 1)
					{
						*nextIdT = idT++;
						*flagT = 1;
					}
					break;
				case 3:
					system("clear");
					printf("\n***** Salir *****\n\n ");
					printf("Confirma salida? s/n: ");
					fpurge(stdin);
					scanf("%c", &confirm);
					if(confirm == 's')
					{
						continueS = 'n';
					}
					break;
				default:
					printf("No es una opcion valida.\n");

			}
		}while(continueS == 's');
	}
}

//BAJAS:


//esta es la funcion que llamo en main para dar de baja:
void baja(int flagN, eNotebook listaN[], int tamN, eMarca listaM[], int tamM, eTipo listaTipos[], int tamTipos)
{
	char continueS = 's';
	char confirm;
	int idN;


	if(listaN != NULL && listaM != NULL && listaTipos != NULL)
	{
		do
		{

			if(flagN == 1)
			{
				mostrarNotebooks(listaN, tamN, listaTipos, tamTipos, listaM, tamM);
				utn_getEntero(&idN, 3, "Ingrese el id del generico a eliminar: ", "Error,id no valido.\n", 1000, 1020);
				if(bajaNotebook(idN, flagN, listaN, tamN, listaTipos, tamTipos, listaM, tamM)  == 1)
				{
					printf("Se ha eliminado la notebook con exito.\n\n");
				}
			}
			else
			{
				printf("Error. No hay notebooks cargadas.\n");
			}


			printf("Continuar dando de baja? s/n: ");
			fpurge(stdin);
			scanf("%c", &confirm);
			if(confirm == 'n')
			{
				continueS = 'n';
			}


		}while(continueS == 's');

	}//if null
}



//esta es la funcion que llamo en main para modificar:
int modificacionNotebook(int flagN, eNotebook listaN[], int tamN, eTipo listaT[], int tamT, eMarca listaM[], int tamM)
{
	int isOk = -1;
	int auxId;
	int opcion;
	char confirmar;
	char continuar;
	int indice;

	float nuevoPrecio;
	int nuevoTipo;

	system("clear");
	printf("***** Modificar *****\n\n");

	if(flagN == 1 && listaN != NULL && listaT != NULL && listaM != NULL)
	{
		mostrarNotebooks(listaN, tamN, listaT, tamT, listaM, tamM);

		if(listaN != NULL && tamN > 0 && utn_getEntero(&auxId, 3, "\nIngrese ID de la notebook a modificar: ", "Error. No es un ID.\n", 1000, 1020) == 0 )
		{
			indice = buscarNotebookPorId(auxId, listaN, tamN);

			if(indice == -1)
			{
				printf("No existe ese ID en el sistema.\n");
			}
			else
			{
				printf("El ID %d pertenece a la siguiente notebook:\n", auxId);
				printf("ID    Modelo    Marca    Tipo     Precio\n\n");
				mostrarNotebook(listaN[indice], listaT, tamT, listaM, tamM);
				printf("Desea modificarla? s/n: ");
				fpurge(stdin);
				scanf("%c", &confirmar);

				if(confirmar == 's')
				{
					do
					{
						system("clear");
						//OJO agregar o sacar las opciones (capos de la estruct) necesarias:
						printf("    1. Modificar precio\n");
						printf("    2. Modificar tipo\n");
						if(utn_getEntero(&opcion, 3, "Ingrese opcion a modificar: ", "Error, no es una opcion valida", 1, 2) == 0)
						{
							switch(opcion) //copio los nuevos valores
							{
								case 1:
									if(utn_getFlotante(&nuevoPrecio, 3, "Ingrese nuevo precio de 5000 a 100000: ", "Error, invalido.\n", 5000, 100000) == 0)
									{
										listaN[indice].precio = nuevoPrecio;
										isOk= 0;
									}
									break;
								case 2:
									mostrarTipos(listaT, tamT);
									if(utn_getEntero(&nuevoTipo, 3, "Ingrese id nuevo tipo: ", "Error, invalido\n", 5000, 5003) == 0)
									{
										listaN[indice].idTipo = nuevoTipo;
										isOk= 0;
									}
									break;
								default:
									printf("No es una opcion valida.\n\n");
							}
							if(isOk == 0)
							{
								printf("Se han modificado los datos correctamente. \n");
								printf("ID    Modelo    Marca    Tipo     Precio\n\n");
								mostrarNotebook(listaN[indice], listaT, tamT, listaM, tamM);
							}
							printf("Desea seguir modificando? s/n: ");
							fpurge(stdin);
							scanf("%c", &confirmar);
							if(confirmar == 's')
							{
								continuar = 'n';
							}
						}//if opcion a modificar == 0
					}while(continuar == 's');
				}//if confirma
				else if(confirmar == 'n')
				{
					printf("No se han registrado modificaciones.\n");
				}
			}//else
		}//if NULL
	}//if flagM == 1
	else
	{
		printf("No hay musicos que modificar.\n");

	}

	return isOk;
}


//LISTAS:
int menuListas()
{
	int opcion;

	system("clear");
	printf("***** Listar *****\n");
	printf("1. Notebooks\n");
	printf("2. Marcas\n");
	printf("3. Tipos\n");
	printf("4. Sevicios\n");
	printf("5. Trabajos\n");
	printf("6. Salir\n\n");
	utn_getEntero(&opcion, 3, "Ingrese la opcion elegida: ", "Error, no es una opcion valida.\n", 1, 6);

	return opcion;
}

//esta es la funcion que llamo en main para listar:
void listar(int flagN, int flagT, eNotebook listaN[], int tamN, eTipo listaTipo[], int tamTipo, eMarca listaM[], int tamM, eTrabajo listaT[], int tamT, eServicio listaS[], int tamS)
{
	int orden;
	char continuar = 's';
	char confirmar;

	do
	{
		switch(menuListas())
		{
			case 1:
				//notebooks
				if(flagN == 1)
				{
					//Ascendente o descendente? :
					utn_getEntero(&orden, 3, "Ascendente 1, Descendente 0: ", "Error, no es un criterio\n", 0, 1);
					ordenarNotebooks(listaN, tamN, orden);
					mostrarNotebooks(listaN, tamN, listaTipo, tamTipo, listaM, tamM);
				}
				else
				{
					printf("Error. No hay notebooks cargadas.\n");
				}
				break;
			case 2:
				//marca
				mostrarMarcas(listaM, tamM);
				break;
			case 3:
				//tipos
				mostrarTipos(listaTipo, tamTipo);
				break;
			case 4:
				//servicios
				mostrarServicios(listaS, tamS);
				break;
			case 5:
				//trabajos
				if(flagT == 1)
				{
					mostrarTrabajos(listaT, tamT, listaS, tamS);
				}
				else
				{
					printf("Error. No hay trabajos cargados.\n");
				}
				break;
			case 6:
				//salir
				system("clear");
				printf("\n***** Salir *****\n\n ");
				printf("Confirma salida? s/n: ");
				fpurge(stdin);
				scanf("%c", &confirmar);
				if(confirmar == 's')
				{
					continuar = 'n';
				}
				break;
			default:
				printf("No es una opcion valida.\n");

		}

	}while(continuar == 's');

}

int altaNotebook(int idX, eNotebook listaN[], int tamN, eTipo listaT[], int tamT, eMarca listaM[], int tamM)
{
	int todoOk = 0; //no pudo dar de alta
	int indice = buscarLibreN(listaN, tamN);

	if(listaN != NULL && listaT != NULL && tamN > 0 && tamT > 0 && listaM != NULL && tamM > 0)
	{
		system("clear");
		printf("***** Alta Notebook *****\n");
		if(indice < 0)
		{
			printf("Sistema completo.\n");
		}
		else
		{
			if(utn_getCadena(listaN[indice].modelo, 30, 3, "\nIngrese Modelo: ", "El modelo ingresado es invalido.\n") == 0)
			{
				mostrarMarcas(listaM, tamM);

				if(utn_getEntero(&listaN[indice].idMarca, 3, "Ingrese id marca: ", "El id ingresado no es valido.\n", 1000, 1003) == 0)
				{
					mostrarTipos(listaT, tamT);
					if(utn_getEntero(&listaN[indice].idTipo, 3, "Ingrese id tipo: ", "El id ingresado no es valido.\n", 5000, 5003) == 0 &&
						utn_getFlotante(&listaN[indice].precio, 3, "Ingrese precio de 5000 a 100000: ", "Error, el precio ingresado no es valido\n", 5000, 100000) == 0)
					{
						listaN[indice].id = idX;
						listaN[indice].isEmpty = 0; //lleno el lugar
						todoOk = 1; //exito
					}

				}
			}
		}//if indice
	}//if NULL

	return todoOk;
}


int altaTrabajo(int idX, eTrabajo listaT[], int tamT, eNotebook listaN[], int tamN, eServicio listaS[], int tamS, eMarca listaM[], int tamM, eTipo tipos[], int tamTipos)
{
	int todoOk = 0; //no pudo dar de alta
	int indice = buscarLibreT(listaT, tamT);
	int auxIdN;
	int auxIdS;

	if(listaT != NULL && listaN != NULL && tamN > 0 && tamT > 0 && listaS != NULL && tamS > 0 && listaM != NULL && tamM > 0)
	{
		system("clear");
		printf("***** Alta Trabajo *****\n");
		if(indice < 0)
		{
			printf("Sistema completo.\n");
		}
		else
		{
			printf("Ingrese fecha DD/MM/AAAA: ");
			scanf("%d/%d/%d", &listaT[indice].fecha.dia, &listaT[indice].fecha.mes, &listaT[indice].fecha.anio);
			mostrarNotebooks(listaN, tamN, tipos, tamTipos, listaM, tamT);
			if(utn_getEntero(&auxIdN, 3, "Ingrese id Notebook: ", "Error.", 1000, 1020) == 0)
			{
				if(buscarNotebookPorId(auxIdN, listaN, tamN) > -1)
				{
					listaT[indice].idNotebook = auxIdN;
					mostrarServicios(listaS, tamS);

					if(utn_getEntero(&auxIdS, 3, "Ingrese id Servicio: ", "El id ingresado no es valido.\n", 20000, 20003) == 0)
					{
						if(buscarServicioPorId(auxIdS, listaS, tamS) > -1)
						{

							listaT[indice].idServicio = auxIdS;
							listaT[indice].id = idX;
							listaT[indice].isEmpty = 0; //lleno el lugar
							todoOk = 1; //exito
						}
						else
						{
							printf("No existe ese servicio\n");
						}

					}

				}
				else
				{
					printf("No existe esa notebook\n");
				}
			}
		}//if indice
	}//if NULL
	return todoOk;
}


int bajaNotebook(int idN, int flagN, eNotebook listaN[], int tamN, eTipo listaTipos[], int tamTipos, eMarca listaM[], int tamM)
{
	int isOk = 0;
	char eliminarN;
	int indiceN;

	if(flagN == 1)
	{
		indiceN = buscarNotebookPorId(idN, listaN, tamN); //busca con el ID que conseguimos en la funcion baja y devuelve el indice donde esta o -1
		if(indiceN > -1)
		{
			mostrarNotebook(listaN[indiceN], listaTipos, tamTipos, listaM, tamM);//muestra la notebook a eliminar
			printf("Eliminar? s/n: ");
			scanf("%c", &eliminarN);
			if(eliminarN == 's')
			{
				listaN[indiceN].isEmpty = 1; //eliminar
				isOk = 1;
			}
			else
			{
				printf("No se han realizado cambios.\n");
			}
		}
		else
		{
			printf("No existe notebook con ese id.\n");
		}
	}
	else
	{
		printf("No hay notebooks cargadas\n");
	}
	return isOk;
}



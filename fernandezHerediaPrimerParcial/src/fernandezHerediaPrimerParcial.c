/*
 ============================================================================
 Name        : fernandezHerediaPrimerParcial.c
 Author      : Catalina Fernandez Heredia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "eMarca.h"
#include "eTipo.h"
#include "eServicio.h"
#include "eNotebook.h"
#include "eTrabajo.h"
#include "menus.h"

#define LENN 20
#define LENT 20
#define TAMTIPO 5
#define LENM 4
#define LENS 4

int main(void) {

	eMarca marcas[LENM] = { {1000, "Compaq"},
					  {1001, "Asus"},
					  {1002, "Acer"},
					  {1003, "HP"} };

	eTipo tipos[TAMTIPO] = { {5000, "Gamer"},
					{5001, "Disenio"},
					{5002, "Ultrabook"},
					{5003, "Normalita"} };

	eServicio servicios[LENS] = { {20000, "Bateria", 250},
							{20001, "Antivirus", 300},
							{20002, "Actualizacion", 400},
							{20003, "Fuente", 600} };
	eNotebook listaN[LENN];
	eTrabajo listaT[LENT];

	char continueS = 's';
	char confirm;

	//Ids
	//int nextIdN = 1000; //arranca en el 1000
	//int nextIdT = 1000;

	//Flags Alta:
	int flagN = 0;
	int flagT = 0;

	//Inicializar arrays:
	inicializarN(listaN, LENN);
	inicializarT(listaT, LENT);


	do
	{
		system("clear");
		switch(menu())
		{
			case 1:
				alta( &flagN,  &flagT, listaT, LENT, listaN, LENN, tipos, TAMTIPO, marcas, LENM, servicios, LENS);
				break;

			case 2:
				baja(flagN, listaN, LENN, marcas, LENM, tipos, TAMTIPO);
				break;

			case 3:
				modificacionNotebook(flagN, listaN, LENN, tipos, TAMTIPO, marcas, LENM);
				break;

			case 4:
				listar(flagN, flagT, listaN, LENN, tipos, TAMTIPO, marcas, LENM, listaT, LENT, servicios, LENS);
				break;

			case 5:
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
		pause();


	}while(continueS == 's');


	return EXIT_SUCCESS;
}

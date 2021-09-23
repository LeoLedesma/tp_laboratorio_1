/*
 * entradaDatos.c
 *
 *
 *      Author: Leonel
 */
#include <stdio.h>
#include <stdlib.h>

#include "entradaDatos.h"

#define TRUE 1
#define FALSE 0


float getFloatValidado (char mensaje[])
{

	int esNumero;
    float numeroIngresado;

		do
		{
			fflush(stdin);
			printf("%s", mensaje);
			esNumero=scanf("%f", &numeroIngresado);
			fflush(stdin);
		}while(!esNumero);


	return numeroIngresado;

}


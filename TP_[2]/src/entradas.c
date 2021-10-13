#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entradas.h"
#include "validaciones.h"

int menuOpciones()
{

    int opcion;
    fflush(stdin);
    printf("1) Alta de empleado\n");
    printf("2) Modificar empleado\n");
    printf("3) Baja de empleado\n");
    printf("4) Informar\n\n");
    printf("0) Salir\n");
    getInt("Por favor seleccione una opcion: ", "ERROR. seleccione una opcion (solo numeros): " , &opcion);
    fflush(stdin);
    return opcion;
}

int getString(char mensaje[], char mensajeError[], char entrada[], int tam)
{
	int todoOk = -1;
	char auxString[100];

	if(mensaje!=NULL && mensajeError!=NULL && entrada!=NULL && tam>0)
	{
		printf("%s", mensaje);
		fflush (stdin);
		gets(auxString);

		while(strlen(auxString)>tam-1 || !isString(auxString))
		{
			printf("%s", mensajeError);
			fflush (stdin);
			gets(auxString);
		}

		strcpy(entrada, auxString);
		todoOk=0;
	}

	return todoOk;
}

int getFloat(char mensaje[], char mensajeError[], float* entrada )
{
	int todoOk = -1;
	char auxString[100];

	if(mensaje!=NULL && mensajeError!=NULL && entrada!=NULL)
	{
		printf("%s", mensaje);
		fflush (stdin);
		gets(auxString);

		while(!isFloat(auxString))
		{
			printf("%s", mensajeError);
			fflush (stdin);
			gets(auxString);
		}

		*entrada = atof(auxString);

		todoOk=0;
	}

	return todoOk;
}

int getInt(char mensaje[], char mensajeError[], int* entrada )
{
	int todoOk = 0;
	char auxString[100];

	fflush(stdin);
	if(mensaje!=NULL && mensajeError!=NULL && entrada!=NULL)
	{
		printf("%s", mensaje);
		fflush (stdin);
		gets(auxString);

		while(!isInt(auxString))
		{
			printf("%s", mensajeError);
			fflush (stdin);
			gets(auxString);

		}

		*entrada = atoi(auxString);

		todoOk=1;
	}

	return todoOk;
}



/*
 * menuOpciones.c
 *
 *
 *      Author: Leonel Ledesma
 */
#include <stdio.h>
#include <stdlib.h>

#include "menuOpciones.h"

#define TRUE 1
#define FALSE 0


int desplegarMenuOpciones(int banderaPrimerOperando, int banderaSegundoOperando, float operandoUno, float operandoDos)

{
    int opcion;

    if(banderaPrimerOperando==TRUE)
    {
        printf("1. Cambiar 1er operando (A=%.2f)\n", operandoUno);
    }
    else
    {
        printf("1. Ingresar 1er operando.\n");
    }
    if(banderaSegundoOperando==TRUE)
    {
        printf("2. Cambiar 2do operando (B=%.2f)\n", operandoDos);
    }
    else
    {
        printf("2. Ingresar 2do operando.\n");
    }
    printf("3. Calcular todas las operaciones\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n");
    printf("Por favor seleccione una opcion: ");
    scanf("%d", &opcion);

    fflush(stdin);

    return opcion;
}

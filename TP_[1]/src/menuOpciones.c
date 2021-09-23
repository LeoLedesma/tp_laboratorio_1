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

void mostrarResultados(float operandoUno, float operandoDos, int factorialA, int factorialB, float resultadoSuma, float resultadoResta, float resultadoDivision, float resultadoMultiplicacion, unsigned long resultadoFactorialA, unsigned long resultadoFactorialB)
{
	printf("Los resultados calculados son: \n");
	printf("El resultado de %.2f + %.2f es: %.2f\n", operandoUno, operandoDos, resultadoSuma);
	printf("El resultado de %.2f - %.2f es: %.2f\n", operandoUno, operandoDos, resultadoResta);
	if (resultadoDivision!=0)
	{
		printf("El resultado de %.2f / %.2f es: %.2f\n", operandoUno, operandoDos, resultadoDivision);
	}
	else
	{
	printf("No se puede realizar una division si el segundo operando es '0'.\n");
	}
	printf("El resultado de %.2f * %.2f es: %.2f\n", operandoUno, operandoDos, resultadoMultiplicacion);
	if(factorialA>13 || factorialB>13)
	{
		printf("No se puede realizar factorial de numeros tan grandes. \n");
	}
	else
	{
		if(resultadoFactorialA!=0 && resultadoFactorialB!=0)
				{
					printf("El factorial de %d es: %lu y El factorial de %d es: %lu\n", factorialA, resultadoFactorialA, factorialB, resultadoFactorialB);
				}
				else
				{
				printf("No se puede realizar factorial de numeros negativos.");
				}
	}
	system("pause");
	system("cls");

}

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
    printf("a) El resultado de %.2f + %.2f es: %.2f\n", operandoUno, operandoDos, resultadoSuma);
    printf("b) El resultado de %.2f - %.2f es: %.2f\n", operandoUno, operandoDos, resultadoResta);
    if (operandoDos!=0)
    {
        printf("c) El resultado de %.3f / %.2f es: %.3f\n", operandoUno, operandoDos, resultadoDivision);
    }
    else
    {
        printf("c) No se puede realizar una division si el segundo operando es '0'.\n");
    }
    printf("d) El resultado de %.2f * %.2f es: %.2f\n", operandoUno, operandoDos, resultadoMultiplicacion);
    if(factorialA>=0 && factorialA<=12)
    {
        printf("e) El factorial de %d es: %lu ", factorialA, resultadoFactorialA);
    }
    else
    {
        printf("e) No se pudo calcular el factorial de %d ", factorialA);
    }

    if(factorialB>=0 && factorialB<=12)
    {
        printf("y el factorial de %d es: %lu.\n", factorialB, resultadoFactorialB);
    }
    else
    {
        printf("y no se pudo calcular el factorial de %d.\n", factorialB);
    }

    system("pause");
    system("cls");

}


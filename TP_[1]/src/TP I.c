/*
 ============================================================================
 Name        : TP I.c
 Author      : Leonel Ledesma
 Version     :
 Copyright   : Your copyright notice
 Description : Es una calculadora
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "entradaDatos.h"
#include "funcionesAritmeticas.h"
#include "menuOpciones.h"


#define TRUE 1
#define FALSE 0

int main(void)
{

    setbuf(stdout, NULL);

    int salir=FALSE;

    float operandoUno=0;
    float operandoDos=0;
    int factorialA;
    int factorialB;

    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    unsigned long resultadoFactorialA;
    unsigned long resultadoFactorialB;

    int banderaPrimerOperando=FALSE;
    int banderaSegundoOperando=FALSE;
    int banderaCalcular=FALSE;

    printf("Bienvenidos a la calculadora\n");
    printf("----------------------------\n");

    do
    {
        printf("\tMenu principal\n");

        switch(desplegarMenuOpciones(banderaPrimerOperando, banderaSegundoOperando, operandoUno, operandoDos))
        {
        case 1:
            operandoUno = getFloatValidado("Por favor ingrese el primer operando: ");
            banderaPrimerOperando=TRUE;
            if(banderaPrimerOperando==TRUE && banderaCalcular==TRUE)
            {
                banderaCalcular=FALSE;
            }
            factorialA = redondearFloat(operandoUno);
            system("cls");

            break;
        case 2:
            operandoDos = getFloatValidado("Por favor ingrese el segundo operando: ");
            banderaSegundoOperando=TRUE;
            if(banderaSegundoOperando==TRUE && banderaCalcular==TRUE)
            {
                banderaCalcular=FALSE;
            }
            factorialB = redondearFloat(operandoDos);
            system("cls");

            break;
        case 3:
            system("cls");
            if(banderaPrimerOperando==TRUE && banderaSegundoOperando==TRUE)
            {
                banderaCalcular=TRUE;
                resultadoSuma = sumarFloats(operandoUno, operandoDos);
                resultadoResta = restarFloats(operandoUno, operandoDos);
                resultadoDivision = dividirFloats(operandoUno, operandoDos);
                resultadoMultiplicacion = multiplicarFloats(operandoUno, operandoDos);
                resultadoFactorialA = factorizar(factorialA);
                resultadoFactorialB = factorizar(factorialB);
                printf("Se han realizado los calculos.\n");
            }
            else
            {
                printf("Primero debe cargar todos los operandos.\n");

            }

            break;
        case 4:
            system("cls");
            if(banderaCalcular==TRUE)
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
            else
            {
                printf("Para informar los resultados, primero debe calcularlos (opcion 3).\n");

            }


            break;
        case 5:
            salir=TRUE;
            printf("Hasta luego");
            break;
        default:
            system("cls");
            printf("ERROR. Seleccione una opcion correcta\n");

            break;
        }
    }
    while(salir==FALSE );



    return EXIT_SUCCESS;
}

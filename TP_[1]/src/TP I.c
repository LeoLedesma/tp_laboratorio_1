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

                if(operandoUno<0&&operandoDos==0)
                {
                	resultadoMultiplicacion=resultadoMultiplicacion*-1;
                }
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

                mostrarResultados(operandoUno, operandoDos, factorialA, factorialB, resultadoSuma, resultadoResta, resultadoDivision, resultadoMultiplicacion, resultadoFactorialA, resultadoFactorialB);
            }
            else
            {
                printf("Para informar los resultados, primero debe calcularlos.\n");

            }


            break;
        case 5:
            salir=TRUE;
            printf("Hasta luego");
            break;
        default:
            salir=FALSE;
            system("cls");
            printf("ERROR. Seleccione una opcion correcta\n");

            break;
        }
    }
    while(salir==FALSE );



    return EXIT_SUCCESS;
}

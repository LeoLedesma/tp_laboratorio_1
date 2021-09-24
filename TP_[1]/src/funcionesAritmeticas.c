/*
 * funcionesAritmeticas.c
 *
 *
 *      Author: Leonel Ledesma
 */

#include "funcionesAritmeticas.h"

float sumarFloats(float primerNumero, float segundoNumero)
{
    float resultado;
    resultado = primerNumero+segundoNumero;
    return resultado;
}


float restarFloats(float primerNumero, float segundoNumero)
{
    float resultado;
    resultado = primerNumero-segundoNumero;
    return resultado;
}

float dividirFloats(float primerNumero, float segundoNumero)
{
    float resultado= 0;
    if(segundoNumero!=0){
    resultado = primerNumero/segundoNumero;
    }
    return resultado;
}

float multiplicarFloats(float primerNumero, float segundoNumero)
{
    float resultado;
    resultado = primerNumero*segundoNumero;

    if(primerNumero<0&&segundoNumero==0)
                   {
                   	resultado=resultado*-1;
                   }
    return resultado;
}

unsigned long factorizar (int numero)
{
    unsigned long resultado = 0;

    if(numero >= 0)
    {
        resultado = 1;

        for(int i = 1; i<=numero; i++)
        {
            resultado*=i;
        }

    }
    return resultado;
}

int redondearFloat(float numero)
{
    int numeroRedondeado;

    numeroRedondeado = numero;

    if((numero-numeroRedondeado)>=0.50)
    {
        numeroRedondeado++;
    }

    return numeroRedondeado;
}

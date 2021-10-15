#ifndef ENTRADAS_H_
#define ENTRADAS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0



#endif /* ENTRADAS_H_ */



//--------------PEDIDO DE DATOS------------------

int getString(char mensaje[], char mensajeError[], char entrada[], int tam);

int getFloat(char mensaje[], char mensajeError[], float* entrada );

int getInt(char mensaje[], char mensajeError[], int* entrada);

char getConfirmation (char mensaje[], char mensajeError[]);


//------------------VALIDACIONES-------------------

int isString (char string[]);

int isFloat(char entrada[]);

int isInt(char entrada[]);

//-----------------MODIFICACION DE ENTRADAS

int toUpperFirstLetterPhrase(char string [], int len);

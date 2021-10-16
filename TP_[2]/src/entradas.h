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

/// \fn int getString(char[], char[], char[], int)
/// \brief Pide al usuario la entrada de una cadena de texto, exclusiva de caracteres alfabeticos.
///  Mostrando mensaje de error si se ingreso algo diferente a letras.
///
/// \param mensaje Mensaje de pedido de ingreso.
/// \param mensajeError Mensaje de error de pedido.
/// \param entrada Puntero a la direccion donde se requiere guardar la entrada.
/// \param tam tamaño maximo de la entrada.
/// \return retorna (-1) si hubo un error o (0) si esta ok.
int getString(char mensaje[], char mensajeError[], char entrada[], int tam);

/// \fn int getFloat(char[], char[], float*)
/// \brief Pide al usuario la entrada de un numero con punto flotante, validando que se ingrese correctamente.
///
/// \param mensaje Mensaje de pedido de ingreso.
/// \param mensajeError Mensaje de error de ingreso.
/// \param entrada Puntero a la direccion donde se requiere guardar la entrada.
/// \return Retorna (-1) si hubo un error o (0) si esta ok.
int getFloat(char mensaje[], char mensajeError[], float* entrada );

/// \fn int getInt(char[], char[], int*)
/// \brief Pide al usuario la entrada de un numero entero, validando que se ingrese correctamente.
///
/// \param mensaje Mensaje de pedido de ingreso.
/// \param mensajeError Mensaje de error de ingreso.
/// \param entrada Puntero a la direccion donde se requiere guardar la entrada.
/// \return Retorna (-1) si hubo un error o (0) si esta ok.
int getInt(char mensaje[], char mensajeError[], int* entrada);

/// \fn char getConfirmation(char[], char[])
/// \brief Pide al usuario la entrada de un caracter de confirmacion( s=si, y=yes, n=no), admitiendo el ingreso de mayusculas o minisculas.
///
/// \param mensaje Mensaje de pedido de ingreso.
/// \param mensajeError Mensaje de error de ingreso.
/// \return Retorna la opcion que haya ingresado correctamente el usuario.
char getConfirmation (char mensaje[], char mensajeError[]);


//------------------VALIDACIONES-------------------

/// \fn int isString(char[])
/// \brief Valida si string es un string sin numeros.
///
/// \param string Cadena a validar
/// \return Retorna (0) si no es string sin numeros, (1) si es string sin numeros.
int isString (char string[]);

/// \fn int isFloat(char[])
/// \brief Valida si entrada es un numero con punto flotante valido.
///
/// \param entrada Cadena a validar
/// \return Retorna (0) si no es string sin numeros, (1) si es string sin numeros.
int isFloat(char entrada[]);

/// \fn int isInt(char[])
/// \brief Valida si entrada es un numero entero valido.
///
/// \param entrada Cadena a validar.
/// \return
int isInt(char entrada[]);

//-----------------MODIFICACION DE ENTRADAS

/// \fn int toUpperFirstLetterPhrase(char[], int)
/// \brief Deja o cambia todas la primer letra de cada palabras de string a mayusculas.
///
/// \param string Cadena a modificar
/// \param len Largo de cadena a modificar.
/// \return Retorna (0) si hubo un error, (1) si todo ok.
int toUpperFirstLetterPhrase(char string [], int len);

/*
 * funcionesAritmeticas.h
 *
 *
 *      Author: Leonel Ledesma
 */

#ifndef FUNCIONESARITMETICAS_H_
#define FUNCIONESARITMETICAS_H_




/// \fn float sumaraFloats(float, float)
/// \brief
///
/// \param primerNumero
/// \param segundoNumero
/// \return
float sumaraFloats(float primerNumero, float segundoNumero);

#endif /* FUNCIONESARITMETICAS_H_ */

/** \brief Suma dos flotantes y devuelve el resultado.
 *
 * \param primerNumero float Primer sumando.
 * \param segundoNumero float Segundo sumando.
 * \return float Retorna el resultado (suma).
 *
 */
float sumarFloats(float primerNumero, float segundoNumero);


/** \brief Resta dos flotantes y devuelve el resultado
 *
 * \param primerNumero float Minuendo
 * \param segundoNumero float Sustraendo
 * \return float Retorna el resultado (Diferencia).
 *
 */
float restarFloats(float primerNumero, float segundoNumero);


/** \brief Divide dos flotantes y devuelve el resultado.
 *
 * \param primerNumero float Dividendo.
 * \param segundoNumero float Divisor.
 * \return float Retorna el resultado (Cociente).
 *
 */
float dividirFloats(float primerNumero, float segundoNumero);


/** \brief Multiplica dos flotantes y devuelve el resultado.
 *
 * \param primerNumero float Primer factor
 * \param segundoNumero float Segundo factor
 * \return float Retorna el resultado (Producto).
 *
 */
float multiplicarFloats(float primerNumero, float segundoNumero);


/** \brief Redondea un flotante y lo devuelve.
 *
 * \param numero float Numero a ser redondeado
 * \return int Retorna el numero redondeado.
 *
 */
int redondearFloat(float numero);


/** \brief Realiza la factorizacion de un numero.
 *
 * \param numero int Numero a ser factorizado.
 * \return unsigned long Resultado de la factorizacion.
 *
 */
unsigned long factorizar(int numero);

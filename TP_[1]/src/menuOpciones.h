/*
 * menuOpciones.h
 *
 *
 *      Author: Leonel
 */

#ifndef MENUOPCIONES_H_
#define MENUOPCIONES_H_

/** \brief Despliega un menu de opciones numericas para una calculadora, solicita la eleccion de la misma y devuelve el resultado.
 *
 * \param banderaPrimerOperando int Si es TRUE permite que se muestre el operandoUno.
 * \param banderaSegundoOperando int Si es TRUE permite que se muestre el operandoDos.
 * \param operandoUno float Se muestra el valor una vez haya sido cargado.
 * \param operandoDos float Se muestra el valor una vez haya sido cargado.
 * \return int Devuelve la opcion elegida por el usuario.
 *
 */
int desplegarMenuOpciones(int banderaPrimerOperando, int banderaSegundoOperando, float operandoUno, float operandoDos);

#endif /* MENUOPCIONES_H_ */

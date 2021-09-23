/*
 * menuOpciones.h
 *
 *
 *      Author: Leonel
 */


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

/** \brief
 *
 * \param operandoUno float Muestra su valor dentro de los mensajes.
 * \param operandoDos float Muestra su valor dentro de los mensajes.
 * \param factorialA int Muestra su valor dentro de los mensajes. Debe ser el operandoUno redondeado.
 * \param factorialB int Muestra su valor dentro de los mensajes. Debe ser el operandoDos redondeado.
 * \param resultadoSuma float Resultado de la suma entre operandoUno y operandoDos.
 * \param resultadoResta float Resultado de la resta entre operandoUno y operandoDos.
 * \param resultadoDivision float Resultado de la division entre operandoUno y operandoDos.
 * \param resultadoMultiplicacion float Resultado de la multiplicacion entre operandoUno y operandoDos.
 * \param resultadoFactorialA unsigned long Resultado del factorial del operandoUno.
 * \param resultadoFactorialB unsigned long Resultado del factorial del operandoDos.
 * \return void
 *
 */
void mostrarResultados(float operandoUno, float operandoDos, int factorialA, int factorialB, float resultadoSuma, float resultadoResta, float resultadoDivision, float resultadoMultiplicacion, unsigned long resultadoFactorialA, unsigned long resultadoFactorialB);
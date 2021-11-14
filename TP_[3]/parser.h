#ifndef PARSER_H_
#define PARSER_H_

#include "LinkedList.h"
#include "Employee.h"

#endif /* PARSER_H_ */

/// @fn int parser_EmployeeFromText(FILE*, LinkedList*)
/// @brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
///
/// @param pFile Archivo
/// @param pArrayListEmployee Lista de empleados
/// @return Retorna (1) si logro cargar al menos un empleado, (0) si no.
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);


/// @fn int parser_EmployeeFromBinary(FILE*, LinkedList*)
/// @brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
///
/// @param pFile Archivo
/// @param pArrayListEmployee Lista de empleados
/// @return Retorna (1) si logro cargar al menos un empleado, (0) si no.
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

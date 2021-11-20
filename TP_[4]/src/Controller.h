#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "../inc/LinkedList.h"
#include "Employee.h"
#include "menu.h"
#include "parser.h"

#endif /* CONTROLLER_H_ */


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


int controller_findEmployeeById(LinkedList* pArrayListEmployee, int id);
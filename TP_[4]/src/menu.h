#ifndef MENU_H_
#define MENU_H_

#include "entradas.h"
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "entradas.h"

int menuOpciones();
int menuPrincipal(LinkedList* listaEmpleados);

void mostrarGraficoEmpleado();

int menuOrdenamiento();
int menuCriterioOrdenamiento();
int menuModificaciones();




#endif /* MENU_H_ */

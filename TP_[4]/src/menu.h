#ifndef MENU_H_
#define MENU_H_

#include "entradas.h"
#include "../inc/LinkedList.h"
#include "../testing/inc/main_test.h"
#include "Controller.h"
#include "Employee.h"
#include "entradas.h"


int menuOpciones();
int menuPrincipal(LinkedList* listaEmpleados);

void mostrarGraficoEmpleado();

int menuOrdenamiento();
int menuCriterioOrdenamiento();
int menuModificaciones();
int funcionesLinkedlist(LinkedList *listaEmpleados);
int menuOpcionesLinkedlist();




#endif /* MENU_H_ */

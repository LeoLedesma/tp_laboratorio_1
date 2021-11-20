#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "entradas.h"
#include "../inc/LinkedList.h"

typedef struct
{
    int id;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
int employee_delete(Employee* eEmployee);

int employee_setId(Employee* eEmployee,int id);
int employee_getId(Employee* eEmployee,int* id);

int employee_setNombre(Employee* eEmployee,char* nombre);
int employee_getNombre(Employee* eEmployee,char* nombre);

int employee_setHorasTrabajadas(Employee* eEmployee,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* eEmployee,int* horasTrabajadas);

int employee_setSueldo(Employee* eEmployee,int sueldo);
int employee_getSueldo(Employee* eEmployee,int* sueldo);

void employee_mostrarEmpleado(Employee* employee);
int employee_getMaxId(LinkedList* pArrayListEmployee);


int employee_compareById(void* employee1, void* employee2);
int employee_compareByName(void* employee1, void* employee2);
int employee_compareByHours(void* employee1, void* employee2);
int employee_compareBySalary(void* employee1, void* employee2);


#endif // employee_H_INCLUDED

#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#include "entradas.h"

#define SIZE_LIST 1000
#define SIZE_STRING 51

struct{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;

}typedef Employee;


#endif // ARRAYEMPLOYEES_H_INCLUDED


int menuEmployees();

int menuPrintEmployees(Employee* list, int len);

int getDataEmployee(Employee* list, int len, int nextId);

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

int printEmploye(Employee list);

float totalSalaryEmployees(Employee* list, int len);

float getMedianSalaryEmployees(Employee* list, int len);

int getEmployeesUpMedianSalary(Employee* list, int len);

int findEmpty(Employee* lista, int tam);

//------------------PEDIDO DE DATOS DE EMPLEADOS


int getIdEmployee(Employee* list, int len);

//------------------MODIFICACIONES DE EMPLEADOS

int modifyEmployee(Employee* list, int len, int lenName);

int offEmployee(Employee* list, int len);

int modifyName(Employee* list, int index, char newName[]);

int modifyLastname(Employee* list, int index, char newLastname[]);

int modifySalary(Employee* list,int index, float newSalary);

int modifySector(Employee* list,int index, int newSector);


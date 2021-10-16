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

/// \fn int findEmpty(Employee*, int)
/// \brief  Busca si hay lugar libre en la lista.
///
/// \param lista Puntero a array de empleados
/// \param tam Largo del array
/// \return Retorna (-1) si no hay libre o hubo un error o retorna el primer indice libre.
int findEmpty(Employee* lista, int tam);

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

/// \fn int getDataEmployee(Employee*, int, int)
/// \brief Pide los datos para agregar un nuevo empleado.
///
/// \param list Puntero a array de empleados
/// \param len Largo del array
/// \param nextId ID a cargar en el empleado
/// \return Devuelve (-1) si hubo un error y (0) si pudo cargar el empleado.
int getDataEmployee(Employee* list, int len, int nextId);

/// \fn int getEmployeesUpMedianSalary(Employee*, int)
/// \brief Calcula los empleados que superan el salario minimo.
///
/// \param list Puntero a array de empleados
/// \param len Largo del array
/// \return Retorna la cantidad de empleados que superan el salario promedio.
int getEmployeesUpMedianSalary(Employee* list, int len);

/// \fn int getIdEmployee(Employee*, int)
/// \brief Pide al usuario un id y verifica que este cargado.
///
/// \param list
/// \param len
/// \return Retorna (-1) si hubo error o el ID esta vacio, si esta cargado devuelve el id que ingreso el usuario.
int getIdEmployee(Employee* list, int len);

/// \fn float getMedianSalaryEmployees(Employee*, int)
/// \brief Calcula el salario medio/promedio de los empleados.
///
/// \param list Puntero a array de empleados
/// \param len Largo del array
/// \return Retorna (-1) si ocurrio un error, 0 si no hay ningun empleado dado de alta o el salario promedio.
float getMedianSalaryEmployees(Employee* list, int len);

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);

/// \fn int menuEmployees()
/// \brief Abre un menu de opciones de alta, baja modificacion, e informes y pide elegir una opcion.
///
/// \return Devuelve la opcion elegida
int menuEmployees();

/// \fn int menuPrintEmployees(Employee*, int)
/// \brief Abre un menu de opciones para informar lista de empleados,
///
/// \param list Puntero a array de empleados
/// \param len largo del array
/// \return Devuelve (-1) si hubo un error y (0) si esta bien.
int menuPrintEmployees(Employee* list, int len);

/// \fn int modifyEmployee(Employee*, int, int)
/// \brief
///
/// \param list
/// \param len
/// \param lenName
/// \return
int modifyEmployee(Employee* list, int len, int lenName);

/// \fn int modifyName(Employee*, int, char[])
/// \brief Modifica el nombre del empleado, cambiandolo por newName.
///
/// \param list Puntero a array de empleados
/// \param index Indice en el array del empleado a modificar
/// \param newName Nuevo nombre del empleado.
/// \return Retorna (0) si hubo error, (1) si realizo el cambio de nombre.
int modifyName(Employee* list, int index, char newName[]);

/// \fn int modifyLastname(Employee*, int, char[])
/// \brief Modifica el nombre del empleado, cambiandolo por newLastname.
///
/// \param list Puntero a array de empleados
/// \param index Indice en el array del empleado a modificar
/// \param newLastname Nuevo apellido del empleado.
/// \return Retorna (0) si hubo error, (1) si realizo el cambio de nombre.
int modifyLastname(Employee* list, int index, char newLastname[]);

/// \fn int modifySalary(Employee*, int, float)
/// \brief Modifica el salario del empleado, cambiandolo por newSalary.
///
/// \param list Puntero a array de empleados
/// \param index Indice en el array del empleado a modificar
/// \param newSalary Nuevo salario del empleado.
/// \return Retorna (0) si hubo error, (1) si realizo el cambio de salario.
int modifySalary(Employee* list, int index, float newSalary);

/// \fn int modifySector(Employee*, int, int)
/// \brief Modifica el sector del empleado, cambiandolo por newSector
///
/// \param list Puntero a array de empleados
/// \param index Indice en el array del empleado a modificar
/// \param newSector Nuevo sector del empleado.
/// \return Retorna (0) si hubo error, (1) si realizo el cambio de salario.
int modifySector(Employee* list, int index, int newSector);

/// \fn int offEmployee(Employee*, int)
/// \brief Llama al menu para dar de baja baja al empleado.
/// \param list Puntero a array de empleados
/// \param len Largo del array
/// \return Retorna (-1) si hubo error, (0) si no se concreta la baja y (1) si se dio de baja.
int offEmployee(Employee* list, int len);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length);

/// \fn int printEmploye(Employee)
/// \brief Imprime individualmente el empleado enviado.
///
/// \param list Datos del empleado a mostrar.
/// \return Retorna (1) si puedo mostrar el empleado y (0) si no.
int printEmploye(Employee list);

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

/// \fn float totalSalaryEmployees(Employee*, int)
/// \brief Calcula la suma de todos los salarios de los empleados.
///
/// \param list Puntero a array de empleados
/// \param len Largo del array
/// \return Retorna la suma de salarios.
float totalSalaryEmployees(Employee* list, int len);
